#include "Chess.h"

#include <cstring>
#include <iostream>

void demo() {

}

void interactive() {

}

int main(int argc, char* argv[]) {
    bool isInteractive = false;

    if ((argc == 2) && strcmp(argv[1], "i") == 0) {
        isInteractive = true;
    }

    if (isInteractive) {
        StartApp();

    } else {
        demo();
    }
    return 0;
}
