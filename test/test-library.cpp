#include "catch2/catch_all.hpp"
#include "library.h"

#include <chrono>
#include <labels/SimpleLabel.h>
#include <labels/LabelDecorator.h>
#include <labels/CapitalizeText.h>
#include <labels/Replace.h>


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

	auto rem = LabelDecorator::removeDecorator(dec, std::make_shared<CapitalizeText>(CapitalizeText()));

	REQUIRE(rem->getText() == "idk");
}

TEST_CASE("Test remove replace")
{
	std::shared_ptr<Label> dec = std::make_shared<LabelDecorator>(LabelDecorator(std::make_shared<SimpleLabel>(SimpleLabel("abc_def")), std::make_shared<Replace>(Replace("abc", "def"))));

	dec = std::make_shared<LabelDecorator>(dec, std::make_shared<CapitalizeText>(CapitalizeText()));

	auto rem = LabelDecorator::removeDecorator(dec, std::make_shared<Replace>(Replace("abc", "def")));

	REQUIRE(dec->getText() == "ABC_DEF");
}