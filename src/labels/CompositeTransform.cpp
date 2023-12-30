#include "CompositeTransform.h"

CompositeTransform::CompositeTransform(const std::vector<std::shared_ptr<TransformText>>& transforms) : transforms(transforms) {}

std::string CompositeTransform::transform(const std::string& text) const {
	std::string str = text;

	for (auto transform : transforms) {
		str = transform->transform(str);
	}

	return str;
}

bool CompositeTransform::equals(TransformText* other) const {
	if (auto ptr = dynamic_cast<CompositeTransform*>(other)) {
		if (ptr->transforms.size() != transforms.size())
			return false;

		for (int i = 0; i < transforms.size(); ++i) {
			if (!transforms[i]->equals(ptr->transforms[i].get())) {
				return false;
			}
		}
		return true;
	}
	return false;
}
