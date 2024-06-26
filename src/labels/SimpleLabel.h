#pragma once
#include "Label.h"

class SimpleLabel : public Label {
	std::string value;

public:
	SimpleLabel(const std::string& value);

	Label* clone() const override;

	std::string getText() const override ;
};