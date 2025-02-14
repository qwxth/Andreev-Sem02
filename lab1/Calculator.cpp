#include "Calculator.h"
#include "mymath/mymath.h"
#include "myproduct/myproduct.h"
#include <iostream>

namespace Calculator {
int demoMode() {
  std::cout << "я умею суммировать! зацени 10 + 32 = ";
  std::cout << mymath::sum(10, 32) << std::endl;

  std::cout << "я умею умножать! зацени 10 * 32 = ";
  std::cout << myproduct::product(10, 32) << std::endl;

  return 0;
}

int interactiveMode() {
  int a = 0;
  int b = 0;

  std::cout << "vvedite dva chisla";
  std::cin >> a, b;

  std::cout << "я умею суммировать! зацени" << a << " + " << b << " = ";
  std::cout << mymath::sum(a, b) << std::endl;

  std::cout << "я умею умножать! зацени" << a << " * " << b << " = ";
  std::cout << myproduct::product(a, b) << std::endl;

  return 0;
}

void StartApp() {
  char mode;

  std::cout << "vvedite mode" << std::endl;
  std::cin >> mode;

  SelectMode(static_cast<ModeType>(mode));
}

void SelectMode(ModeType mode) {
  switch (static_cast<ModeType>(mode)) {
  case ModeType::DemoMode:
    demoMode();
    break;
  case ModeType::InteractiveMode:
    interactiveMode();
    break;
  default:
    std::cout << "введены недопустимые данные" << std::endl;
    break;
  }
}
} // namespace Calculator
