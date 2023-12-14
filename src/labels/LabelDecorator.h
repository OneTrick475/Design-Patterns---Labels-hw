#pragma once
#include "Label.h"
#include <memory>
#include "TransformText.h"

class LabelDecorator : public Label {
	std::shared_ptr<Label> label;
	std::shared_ptr<TransformText> transform;

public:
	LabelDecorator(const std::shared_ptr<Label>& label, const std::shared_ptr<TransformText>& transform);

	std::string getText() const override;

	virtual Label* clone() const;

	std::shared_ptr<Label> removeDecorator(const std::shared_ptr<TransformText>& transform);

	static std::shared_ptr<Label> removeDecorator(std::shared_ptr<Label>& label, const std::shared_ptr<TransformText>& transform);

	virtual ~LabelDecorator() = default;
};