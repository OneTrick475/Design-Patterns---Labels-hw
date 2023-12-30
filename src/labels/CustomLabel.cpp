#include "CustomLabel.h"

CustomLabel::CustomLabel(const std::string& text, int time, std::istream& is) : text(text), time(time), is(is) {}

std::string CustomLabel::getText() const {
	return std::string();
}

Label* CustomLabel::clone() const
{
	return nullptr;
}
