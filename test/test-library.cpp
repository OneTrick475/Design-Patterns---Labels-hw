#include "catch2/catch_all.hpp"
#include "library.h"

#include <chrono>
#include <labels/SimpleLabel.h>
#include <labels/LabelDecorator.h>
#include <labels/CapitalizeText.h>



TEST_CASE("Test capitalize")
{
	LabelDecorator dec(std::make_shared<SimpleLabel>(SimpleLabel("idk")), std::make_shared<CapitalizeText>(CapitalizeText()));

	REQUIRE(dec.getText() == "IDK");
}

TEST_CASE("Test remove capitalize")
{
	auto dec = std::make_shared<LabelDecorator>(LabelDecorator(std::make_shared<SimpleLabel>(SimpleLabel("idk")), std::make_shared<CapitalizeText>(CapitalizeText())));

	auto rem = LabelDecorator::removeDecorator(dec, std::make_shared<CapitalizeText>(CapitalizeText()));

	REQUIRE(rem->getText() == "idk");
}