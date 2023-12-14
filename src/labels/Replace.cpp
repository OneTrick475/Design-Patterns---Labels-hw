#include "Replace.h"

Replace::Replace(std::string from, std::string to) : from(from), to(to) {}

std::string Replace::transform(const std::string& text) const {
    std::string str = text;
    size_t index = 0;
    while (true) {
        /* Locate the substring to replace. */
        index = str.find(from, index);
        if (index == std::string::npos) break;

        /* Make the replacement. */
        str.replace(index, 3, to);

        /* Advance index forward so the next iteration doesn't pick it up as well. */
        index += to.size();
    }
    return str;
}

bool Replace::equals(TransformText* other) const {
	if (auto ptr = dynamic_cast<Replace*>(other)) {
		return from == ptr->from && to == ptr->to;
	}
	return false;
}
