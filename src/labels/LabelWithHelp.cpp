#include "LabelWithHelp.h"

LabelWithHelp::LabelWithHelp(const std::shared_ptr<Label>& label, const std::string& help) : label(label), help(help) {}

std::string LabelWithHelp::getText() const {
	return label->getText();
}

std::string LabelWithHelp::getHelpText() const {
	return help;
}

Label* LabelWithHelp::clone() const {
	return new LabelWithHelp(*this);
}
