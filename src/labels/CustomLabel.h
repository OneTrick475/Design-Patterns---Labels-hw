#pragma once 

#include "Label.h"
#include <iostream>

class CustomLabel : public Label {
	mutable std::string text;
	mutable int timeout = 0;
	int time = 0;

	std::istream& is;

public:
	CustomLabel(int time = 0, std::istream& is = std::cin);

	virtual std::string getText() const override;

	virtual Label* clone() const override;
};