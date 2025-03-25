#include <cstring>
#include <iostream>
#include "MyStack.h"

void demo() {
    MyStack<int> stack;
    int n = 3960;

    Multipliers(n, stack);

    std::cout << n << "=";
    MyStack<int> tempStack;

    bool first = true;
    while (!stack.empty()) {
        int factor = stack.peek();
        tempStack.push(factor);
        stack.pop();

        if (!first) {
            std::cout << " * ";
        }
        std::cout << factor;
        first = false;
    }
    std::cout << std::endl;

    std::cout << n << "=";
    first = true;
    while (!tempStack.empty()) {
        int factor = tempStack.peek();
        tempStack.pop();

        if (!first) {
            std::cout << " * ";
        }
        std::cout << factor;
        first = false;
    }
    std::cout << std::endl;
}

void interactive() {
    MyStack<int> stack;

    MyStack<char> stackChar;

    stackChar.push('a');
    stackChar.push('b');
    stackChar.push('c');

    MyStack<char> stackChar2;
    MyStack.copy



    int n = 0;
    std::cout << "ведите число" << std::endl;
    std::cin >> n;

    Multipliers(n, stack);

    std::cout << n << "=";
    MyStack<int> tempStack;

    bool first = true;
    while (!stack.empty()) {
        int factor = stack.peek();
        tempStack.push(factor);
        stack.pop();

        if (!first) {
            std::cout << " * ";
        }
        std::cout << factor;
        first = false;
    }
    std::cout << std::endl;

    std::cout << n << "=";
    first = true;
    while (!tempStack.empty()) {
        int factor = tempStack.peek();
        tempStack.pop();

        if (!first) {
            std::cout << " * ";
        }
        std::cout << factor;
        first = false;
    }
    std::cout << std::endl;
}

int main(int argc, char* argv[]) {
    bool isInteractive = false;

    if ((argc == 2) && strcmp(argv[1], "i") == 0) {
        isInteractive = true;
    }

    if (isInteractive) {
        interactive();

    } else {
        demo();
    }
}
