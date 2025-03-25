#ifndef MYSTACK_H
#define MYSTACK_H

#include <stdexcept>

template<class INF>
class MyStack;

template<class INF, class FRIEND>
class ListNode {
 private:
    INF data;
    ListNode* next;

    ListNode();
    ListNode(const INF& value);
    ListNode(const ListNode& other);

    ListNode& operator=(const ListNode& other);

    friend FRIEND;
};

template<class INF>
class MyStack {
 private:
    typedef ListNode<INF, MyStack<INF>> Node;
    Node* top;

 public:
    MyStack();
    MyStack(const MyStack& other);
    ~MyStack();

    MyStack& operator=(const MyStack& other);
    bool empty(void);
    void push(const INF& value);
    void pop(void);
    INF peek(void);
};

template<class DATA>
void Multipliers(int n, MyStack<DATA>& stack);

#endif  // MYSTACK_H
