#pragma once

#include <memory>
#include "Label.h"

class LabelWithHelp : public Label {
	std::shared_ptr<Label> label;
	std::string help;

public:
	LabelWithHelp(const std::shared_ptr<Label>& label, const std::string& help);

	std::string getText() const override;

	std::string getHelpText() const;

	Label* clone() const override;
};