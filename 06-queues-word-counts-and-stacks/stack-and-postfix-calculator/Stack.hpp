#ifndef STACK_HPP
#define STACK_HPP

// constructor initializes stack with default capacity
template <typename T>
Stack<T>::Stack(int n) {
    stack_size = 0;
    array_capacity = n;
    array = new T[array_capacity];
}

// destructor frees allocated memory
template <typename T>
Stack<T>::~Stack() {
    delete[] array;
}

// copy constructor creates deep copy
template <typename T>
Stack<T>::Stack(const Stack<T>& other) {
    stack_size = other.stack_size;
    array_capacity = other.array_capacity;
    array = new T[array_capacity];

    for (int i = 0; i < stack_size; i++) {
        array[i] = other.array[i];
    }
}

// assignment operator handles deep copy
template <typename T>
Stack<T>& Stack<T>::operator=(const Stack<T>& other) {
    if (this != &other) {
        delete[] array;

        stack_size = other.stack_size;
        array_capacity = other.array_capacity;
        array = new T[array_capacity];

        for (int i = 0; i < stack_size; i++) {
            array[i] = other.array[i];
        }
    }
    return *this;
}

// returns true if no elements
template <typename T>
bool Stack<T>::empty() const {
    return stack_size == 0;
}

// returns top element without removing it
template <typename T>
T Stack<T>::top() const {
    return array[stack_size - 1];
}

// adds new item to top of stack
template <typename T>
void Stack<T>::push(const T& item) {
    if (stack_size == array_capacity) {
        resize(); // grow array if full
    }
    array[stack_size] = item;
    stack_size++;
}

// removes and returns top element
template <typename T>
T Stack<T>::pop() {
    stack_size--;
    return array[stack_size];
}

// doubles capacity and copies elements
template <typename T>
void Stack<T>::resize() {
    array_capacity *= 2;
    T* newArray = new T[array_capacity];

    for (int i = 0; i < stack_size; i++) {
        newArray[i] = array[i];
    }

    delete[] array;
    array = newArray;
}

#endif