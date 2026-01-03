#ifndef STACK_H
#define STACK_H

#include "Vector.h"

template<typename T>
class Stack {
private:
    Vector<T> _container; 
public:

    void push(const T& value) {
        _container.push_back(value);
    }

    void pop() {
        _container.pop_back();
    }

    T& top() {
        return _container.back();
    }
    
    const T& top() const {
        return _container.back();
    }

    bool empty() const {
        return _container.size() == 0;
    }

    size_t size() const {
        return _container.size();
    }
};

#endif