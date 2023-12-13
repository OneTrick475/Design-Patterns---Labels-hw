#include "RichLabel.h"

RichLabel::RichLabel(const std::string& value, const std::string& color , const std::string& font , int size) : value(value),	color(color), font(font), size(size) {}

Label* RichLabel::clone() const {
	return new RichLabel(*this);
}

std::string RichLabel::getText() const {
	return value;
}