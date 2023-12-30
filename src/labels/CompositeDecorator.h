// did this first cuz i misunderstood the task, will leave it here but its not part of the task

#pragma once
#include "Label.h"
#include <memory>
#include "TransformText.h"
#include <vector>

class CompositeDecorator : public Label {
	std::shared_ptr<Label> label;
	std::vector<std::shared_ptr<TransformText>> transforms;

public:
	CompositeDecorator(const std::shared_ptr<Label>& label, const std::vector<std::shared_ptr<TransformText>>& transforms);

	std::string getText() const override;

	virtual Label* clone() const;

	virtual ~CompositeDecorator() = default;
};