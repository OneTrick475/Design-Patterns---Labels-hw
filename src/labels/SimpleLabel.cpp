#include "SimpleLabel.h"

SimpleLabel::SimpleLabel(const std::string& value) : value(value) {}

std::string SimpleLabel::SimpleLabel::getText() const{
	return value;
}