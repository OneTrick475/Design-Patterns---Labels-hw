#include "CompositeDecorator.h"

CompositeDecorator::CompositeDecorator(const std::shared_ptr<Label>& label, const std::vector<std::shared_ptr<TransformText>>& transforms) : label(label), transforms(transforms) {}

std::string CompositeDecorator::getText() const {
	std::string str = label->getText();

	for (auto transform : transforms) {
		str = transform->transform(str);
	}

	return str;
}

Label* CompositeDecorator::clone() const {
	return new CompositeDecorator(*this);
}
