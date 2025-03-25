#include "MyStack.h"
#include <stdexcept>

template<class INF, class FRIEND>
ListNode<INF, FRIEND>::ListNode() : next(nullptr) {
}

template<class INF, class FRIEND>
ListNode<INF, FRIEND>::ListNode(const INF& value) : data(value), next(nullptr) {
}

template<class INF, class FRIEND>
ListNode<INF, FRIEND>::ListNode(const ListNode& other) : data(other.data), next(nullptr) {
}

template<class INF, class FRIEND>
ListNode<INF, FRIEND>& ListNode<INF, FRIEND>::operator=(const ListNode& other) {
    if (this != &other) {
        data = other.data;
    }
    return *this;
}

template<class INF>
MyStack<INF>::MyStack() : top(nullptr) {
}

template<class INF>
MyStack<INF>::MyStack(const MyStack& other) : top(nullptr) {
    if (other.top) {
        Node* srcCurrent = other.top;
        Node* destCurrent = new Node(*srcCurrent);
        top = destCurrent;

        while (srcCurrent->next) {
            srcCurrent = srcCurrent->next;
            destCurrent->next = new Node(*srcCurrent);
            destCurrent = destCurrent->next;
        }
    }
}

template<class INF>
MyStack<INF>::~MyStack() {
    while (!empty()) {
        pop();
    }
}

template<class INF>
MyStack<INF>& MyStack<INF>::operator=(const MyStack& other) {
    if (this != &other) {
        while (!empty()) {
            pop();
        }

        if (other.top) {
            Node* srcCurrent = other.top;
            Node* destCurrent = new Node(*srcCurrent);
            top = destCurrent;

            while (srcCurrent->next) {
                srcCurrent = srcCurrent->next;
                destCurrent->next = new Node(*srcCurrent);
                destCurrent = destCurrent->next;
            }
        }
    }
    return *this;
}

template<class INF>
bool MyStack<INF>::empty(void) {
    return top == nullptr;
}

template<class INF>
void MyStack<INF>::push(const INF& value) {
    Node* newNode = new Node(value);
    newNode->next = top;
    top = newNode;
}

template<class INF>
void MyStack<INF>::pop(void) {
    if (!empty()) {
        Node* temp = top;
        top = top->next;
        delete temp;
    }
}

template<class INF>
INF MyStack<INF>::peek(void) {
    if (empty()) {
        throw std::out_of_range("Стек пуст");
    }
    return top->data;
}

template<class DATA>
void Multipliers(int n, MyStack<DATA>& stack) {
    while (!stack.empty()) {
        stack.pop();
    }

    if (n <= 1) {
        stack.push(n);
        return;
    }

    MyStack<DATA> tempStack;

    int remaining = n;
    int factor = 2;

    while (remaining > 1) {
        if (remaining % factor == 0) {
            tempStack.push(factor);
            remaining /= factor;
        } else {
            factor++;
        }
    }

    while (!tempStack.empty()) {
        stack.push(tempStack.peek());
        tempStack.pop();
    }
}

template class MyStack<int>;
template void Multipliers<int>(int n, MyStack<int>& stack);
