#include "RandomLabelDecorator.h"

RandomLabelDecorator::RandomLabelDecorator(std::unique_ptr<Label>&& label, std::vector<std::unique_ptr<TransformText>>&& transforms, 
	std::unique_ptr<IRandomGenerator>&& random)
	: label(std::move(label)), transforms(std::move(transforms)), random(std::move(random)) {}

std::string RandomLabelDecorator::getText() const {
	return transforms[random->getInRange(0, transforms.size())]->transform(label->getText());
}
