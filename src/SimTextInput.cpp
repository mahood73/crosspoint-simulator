#include "SimTextInput.h"

#include <SDL2/SDL.h>

#include <deque>

namespace SimTextInput {

static bool captureEnabled = false;
static std::deque<std::string> queuedInput;

void setCaptureEnabled(bool enabled) {
  captureEnabled = enabled;
  if (captureEnabled) {
    SDL_StartTextInput();
  } else {
    SDL_StopTextInput();
    queuedInput.clear();
  }
}

bool isCaptureEnabled() { return captureEnabled; }

void pushText(const char* text) {
  if (!captureEnabled || !text || !text[0]) return;
  queuedInput.emplace_back(text);
}

void pushBackspace() {
  if (!captureEnabled) return;
  queuedInput.emplace_back("\b");
}

void pushNewline() {
  if (!captureEnabled) return;
  queuedInput.emplace_back("\n");
}

bool readAvailable(std::string& out) {
  out.clear();

  while (!queuedInput.empty()) {
    out += queuedInput.front();
    queuedInput.pop_front();
  }

  return !out.empty();
}

}  // namespace SimTextInput
