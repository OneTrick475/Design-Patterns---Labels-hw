#include "LabelDecorator.h"

LabelDecorator::LabelDecorator(std::shared_ptr<Label>&& label, std::shared_ptr<TransformText>&& transform) : label(std::move(label)), transform(std::move(transform)) {}

std::string LabelDecorator::getText() const {
	return transform->transform(label->getText());
}

Label* LabelDecorator::clone() const {
	return new LabelDecorator(*this);
}

std::shared_ptr<Label> LabelDecorator::removeDecorator(const std::shared_ptr<TransformText>& transform) {
	if (transform->equals(this->transform.get())) {
		return label;
	}
	else if (LabelDecorator* ptr = dynamic_cast<LabelDecorator*>(label.get())) {
		label = ptr->removeDecorator(transform);

		return std::shared_ptr<Label>(this->clone());
	}
	else {
		return std::shared_ptr<Label>(this->clone());
	}
}

std::shared_ptr<Label> LabelDecorator::removeDecorator(std::shared_ptr<LabelDecorator>& label, const std::shared_ptr<TransformText>& transform) {
	if (label == nullptr) {
		return nullptr;
	}

	if (LabelDecorator* ptr = dynamic_cast<LabelDecorator*>(label.get()) ) {
		return ptr->removeDecorator(transform);
	}

	else {
		return label;
	}
}


