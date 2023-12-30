#include "CustomLabel.h"

CustomLabel::CustomLabel(int time, std::istream& is) : time(time), is(is) {}

std::string CustomLabel::getText() const {
	if (timeout == 0) {
		std::string temp;
		is >> temp;
		text = temp;
		timeout = time;
	}

	timeout--;
	return text;
}

Label* CustomLabel::clone() const {
	return new CustomLabel(*this);
}
