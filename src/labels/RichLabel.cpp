#include "RichLabel.h"

RichLabel::RichLabel(const std::string& value, const std::string& color = "black", const std::string& font = "somefont", int size = 20) : value(value),	color(color), font(font), size(size) {}

std::string RichLabel::getText() const {
	return value;
}