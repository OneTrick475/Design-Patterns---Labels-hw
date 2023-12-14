#pragma once
#include "TransformText.h"

class Replace : public TransformText {
	std::string from;
	std::string to;

public:
	Replace(std::string from, std::string to);

	std::string transform(const std::string& text) const;

	bool equals(TransformText* other) const;
};