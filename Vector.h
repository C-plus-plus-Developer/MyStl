#ifndef VECTOR_H
#define VECTOR_H

#include <iostream>
#include "UniquePtr.h"
#include "Algorithm.h"
template<class T>
class Vector{
private:
    size_t _size;
    size_t _capacity;
    UniquePtr<T[]> _arr;
    
public:
    Vector() : _size(0), _capacity(4), _arr(MakeUnique<T[]>(_capacity)){}
    
    size_t size() const {return _size;}
    size_t capacity() const {return _capacity;}
    bool empty() const {return _size == 0;}

    T &operator[](size_t index){
        if (index >= _size) {
        throw std::out_of_range("Error: index >= size - 1");
        }
        return _arr[index];
    }

    const T &operator[](size_t index) const{
        if (index >= _size) {
        throw std::out_of_range("Error: index >= size - 1");
        }
        return _arr[index];
    }

    Vector(std::initializer_list<T> init) : _size(init.size()), _capacity(init.size()){
        if(_capacity < 4) _capacity = 4;
        _arr = MakeUnique<T[]>(_capacity);
        size_t i = 0;
        for(const T& el : init){
            _arr[i] = el;
            i++;
        }
    }

    void push_back(const T& type){
        if(_size == _capacity){
            _capacity *= 2;
            UniquePtr<T[]> newArr = MakeUnique<T[]>(_capacity);
            for(size_t i = 0; i < _size; ++i){
                newArr[i] = _arr[i]; 
            }
            newArr[_size] = type;
            _arr = MyStd::move(newArr);
        }
        else{
            _arr[_size] = type;
        }
        _size++;
    }

    T& back(){
        return _arr[_size - 1];
    }

    void pop_back() {
    if (_size > 0) _size--;
    }

    void resize(size_t newSize){
        if(newSize < _size){
            _size = newSize;
            return;
        }
        if(newSize > _size){
            size_t newCapacity = (newSize > _capacity * 2) ? newSize : _capacity * 2;
            UniquePtr newArr = MakeUnique<T[]>(newCapacity);
            for(int i = 0; i < _size; ++i){
                newArr[i] = MyStd::move(_arr[i]);
            }
            _arr = MyStd::move(newArr);
            _capacity = newCapacity;
        }
        for (size_t i = _size; i < newSize; ++i) {
            _arr[i] = T(); 
        }
        _size = newSize;
    }

    void push_front(const T& value){
        if(_size == _capacity){
            _capacity *= 2;
            UniquePtr<T[]> newArr = MakeUnique<T[]>(_capacity);
            newArr[0] = value;
            for(size_t i = 0; i < _size; ++i){
                newArr[i+1] = _arr[i]; 
            }
            _arr = MyStd::move(newArr);
        }
        else{
            for(size_t i = _size; i > 0; --i){
                _arr[i] = _arr[i - 1];
            }
            _arr[0] = value;
        }
        _size++;
    }

    T* begin(){return _arr.get();}
    T* end(){return _arr.get() + _size;}

    const T* begin() const {return _arr.get();}
    const T* end() const {return _arr.get() + _size;}
};


#endif 