#include "CapitalizeText.h"
#include <algorithm>
#include <string>
#include <cstring>

std::string CapitalizeText::transform(const std::string& text) const {
	std::string temp = text;

	std::transform(temp.begin(), temp.end(), temp.begin(), std::toupper);

	return temp;
}

bool CapitalizeText::equals(TransformText* other) const {
	return dynamic_cast<CapitalizeText*>(other);
}
