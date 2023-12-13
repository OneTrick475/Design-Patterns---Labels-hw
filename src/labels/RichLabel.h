#pragma once
#include "Label.h"

class RichLabel : public Label {
	std::string value;
	std::string color;
	std::string font;
	int size;
public:
	RichLabel(const std::string& value, const std::string& color = "black", const std::string& font = "somefont", int size = 20);

	Label* clone() const override;

	std::string getText() const override;
};
