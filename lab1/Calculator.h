#pragma once

namespace Calculator {
enum class ModeType {
  DemoMode = 'd',
  InteractiveMode = 'i',
};
int demoMode();

int interactiveMode();

void StartApp();

void SelectMode(ModeType mode);
} // namespace Calculator
