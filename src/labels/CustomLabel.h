#pragma once 

#include "Label.h"

class CustomLabel : public Label {
	std::string text;
	int timeout = 0;
	int time = 0;

	std::istream& is;

public:
	CustomLabel(const std::string& text, int time = 0, std::istream& is);

	virtual std::string getText() const override;

	virtual Label* clone() const override;
};