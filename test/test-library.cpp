#include "catch2/catch_all.hpp"
#include "library.h"

#include <chrono>
#include <labels/SimpleLabel.h>
#include <labels/LabelDecorator.h>
#include <labels/CapitalizeText.h>
#include <labels/Replace.h>
#include <labels/CompositeDecorator.h>


TEST_CASE("Test capitalize")
{
	LabelDecorator dec(std::make_shared<SimpleLabel>(SimpleLabel("idk")), std::make_shared<CapitalizeText>(CapitalizeText()));

	REQUIRE(dec.getText() == "IDK");
}

TEST_CASE("Test replace")
{
	LabelDecorator dec(std::make_shared<SimpleLabel>(SimpleLabel("abc_def")), std::make_shared<Replace>(Replace("abc", "def")));

	REQUIRE(dec.getText() == "def_def");
}

TEST_CASE("Test replace and capitalize stack")
{
	auto dec = std::make_shared<LabelDecorator>(LabelDecorator(std::make_shared<SimpleLabel>(SimpleLabel("abc_def")), std::make_shared<Replace>(Replace("abc", "def"))));

	dec = std::make_shared<LabelDecorator>(dec, std::make_shared<CapitalizeText>(CapitalizeText()));

	REQUIRE(dec->getText() == "DEF_DEF");
}

TEST_CASE("Test remove capitalize")
{
	std::shared_ptr<Label> dec = std::make_shared<LabelDecorator>(LabelDecorator(std::make_shared<SimpleLabel>(SimpleLabel("idk")), std::make_shared<CapitalizeText>(CapitalizeText())));

	dec = LabelDecorator::removeDecorator(dec, std::make_shared<CapitalizeText>(CapitalizeText()));

	REQUIRE(dec->getText() == "idk");
}

TEST_CASE("Test remove replace")
{
	std::shared_ptr<Label> dec = std::make_shared<LabelDecorator>(LabelDecorator(std::make_shared<SimpleLabel>(SimpleLabel("abc_def")), std::make_shared<Replace>(Replace("abc", "def"))));

	dec = std::make_shared<LabelDecorator>(dec, std::make_shared<CapitalizeText>(CapitalizeText()));

	dec = LabelDecorator::removeDecorator(dec, std::make_shared<Replace>(Replace("abc", "def")));

	REQUIRE(dec->getText() == "ABC_DEF");
}

TEST_CASE("Test remove all")
{
	std::shared_ptr<Label> dec = std::make_shared<LabelDecorator>(LabelDecorator(std::make_shared<SimpleLabel>(SimpleLabel("abc_def")), std::make_shared<Replace>(Replace("abc", "def"))));

	dec = std::make_shared<LabelDecorator>(dec, std::make_shared<CapitalizeText>(CapitalizeText()));

	dec = LabelDecorator::removeDecorator(dec, std::make_shared<CapitalizeText>(CapitalizeText()));

	dec = LabelDecorator::removeDecorator(dec, std::make_shared<Replace>(Replace("abc", "def"))) ;

	REQUIRE(dec->getText() == "abc_def");
}

TEST_CASE("Test composite")
{
	std::vector<std::shared_ptr<TransformText>> transforms;
	transforms.push_back(std::make_shared<Replace>(Replace("abc", "def")));
	transforms.push_back(std::make_shared<CapitalizeText>(CapitalizeText()));
	std::shared_ptr<Label> dec = std::make_shared<CompositeDecorator>(CompositeDecorator(std::make_shared<SimpleLabel>(SimpleLabel("abc_def") ), transforms));

	REQUIRE(dec->getText() == "DEF_DEF");
}

TEST_CASE("Test stack composite with other")
{
	std::vector<std::shared_ptr<TransformText>> transforms;
	transforms.push_back(std::make_shared<Replace>(Replace("abc", "def")));
	transforms.push_back(std::make_shared<CapitalizeText>(CapitalizeText()));
	std::shared_ptr<Label> dec = std::make_shared<CompositeDecorator>(CompositeDecorator(std::make_shared<SimpleLabel>(SimpleLabel("abc_def")), transforms));
	dec = std::make_shared<LabelDecorator>(dec, std::make_shared<Replace>(Replace("DEF", "idk")));
	dec = std::make_shared<LabelDecorator>(dec, std::make_shared<CapitalizeText>(CapitalizeText()));

	REQUIRE(dec->getText() == "IDK_IDK");
}