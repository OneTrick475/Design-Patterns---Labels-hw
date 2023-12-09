#pragma once
#include <string>

class TransformText {
public:
	virtual std::string transform(const std::string& text) const = 0;

	virtual ~TransformText() = default;
};