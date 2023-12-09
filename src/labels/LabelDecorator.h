#pragma once
#include "Label.h"
#include <memory>
#include "TransformText.h"

class LabelDecorator : public Label {
	std::unique_ptr<Label> label;
	std::unique_ptr<TransformText> transform;

public:
	LabelDecorator(std::unique_ptr<Label>&& label, std::unique_ptr<TransformText> transform);

	std::string getText() const override;

	virtual ~LabelDecorator() = default;
};