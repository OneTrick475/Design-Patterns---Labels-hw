#include "LabelDecorator.h"

LabelDecorator::LabelDecorator(std::unique_ptr<Label>&& label, std::unique_ptr<TransformText> transform) : label(std::move(label)), transform(std::move(transform)) {}

std::string LabelDecorator::getText() const {
	return transform->transform(label->getText());
}


