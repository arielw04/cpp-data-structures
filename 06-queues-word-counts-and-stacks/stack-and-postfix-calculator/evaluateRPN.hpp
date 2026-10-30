#ifndef EVALUATERPN_HPP
#define EVALUATERPN_HPP

#include <sstream>
#include <string>
#include "Stack.h"

// evaluates RPN using stack
template <typename T>
T evaluateRPN(const std::string& expr) {
    Stack<T> s;                  // stack to store values
    std::stringstream ss(expr); // split input string
    std::string token;

    // process each token
    while (ss >> token) {
        // if operator, pop two values and compute
        if (token == "+" || token == "-" || token == "*" || token == "/") {
            T right = s.pop();
            T left = s.pop();

            if (token == "+") s.push(left + right);
            else if (token == "-") s.push(left - right);
            else if (token == "*") s.push(left * right);
            else if (token == "/") s.push(left / right);
        }
        else {
            // convert number and push to stack
            std::stringstream convert(token);
            T value;
            convert >> value;
            s.push(value);
        }
    }

    // final result is last value in stack
    return s.pop();
}

#endif