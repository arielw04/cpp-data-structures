#ifndef STACK_H
#define STACK_H

// Template Stack class using dynamic array
template <typename T>
class Stack {
private:
    int stack_size;        // number of elements currently in stack
    int array_capacity;    // total allocated size
    T* array;              // pointer to dynamic array

    void resize();         // doubles capacity when full

public:
    Stack(int n = 10);                     // constructor
    ~Stack();                              // destructor
    Stack(const Stack<T>& other);          // copy constructor
    Stack<T>& operator=(const Stack<T>& other); // assignment operator

    bool empty() const;    // check if stack is empty
    T top() const;         // return top element
    void push(const T& item); // add element to stack
    T pop();               // remove and return top element
};

// include implementation for templates
#include "Stack.hpp"

#endif