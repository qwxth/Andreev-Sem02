#ifndef CONTAINER_FUNCTIONS_H
#define CONTAINER_FUNCTIONS_H

#include "../MyVector/MyStack.h"
#include "PrintedEdition.h"

void print(const MyStack<PrintedEdition*>& stack);

void remove(MyStack<PrintedEdition*>& stack, int index);

void clear(MyStack<PrintedEdition*>& stack);

#endif // CONTAINER_FUNCTIONS_H
