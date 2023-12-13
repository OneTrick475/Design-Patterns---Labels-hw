#pragma once
#include "TransformText.h"

class CapitalizeText : public TransformText {
public:
	std::string transform(const std::string& text) const;

	bool equals(TransformText* other) const;
};