#pragma once

#include "TransformText.h"
#include <vector>
#include <memory>

class CompositeTransform : public TransformText {
	std::vector<std::shared_ptr<TransformText>> transforms;

public:
	CompositeTransform(const std::vector<std::shared_ptr<TransformText>>& transforms);

	virtual std::string transform(const std::string& text) const override;

	bool equals(TransformText* other) const override;
};

