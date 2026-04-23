#pragma once

#include <string>

namespace SimTextInput {

void setCaptureEnabled(bool enabled);
bool isCaptureEnabled();

void pushText(const char* text);
void pushBackspace();
void pushNewline();

bool readAvailable(std::string& out);

}  // namespace SimTextInput
