#ifndef UNIQUE_PTR_H
#define UNIQUE_PTR_H

#include <utility>
#include <iostream>
#include <type_traits>

template<typename T>
class UniquePtr{
private:
    T* _ptr;
public:
    explicit UniquePtr(T* ptr = nullptr) : _ptr(ptr){}
    ~UniquePtr(){delete _ptr;}
    UniquePtr(const UniquePtr& other) = delete;
    UniquePtr& operator=(const UniquePtr& other) = delete;
    UniquePtr(UniquePtr&& other) noexcept : _ptr(other._ptr){
        other._ptr = nullptr;
    }
    UniquePtr& operator=(UniquePtr&& other) noexcept{
        if(this == other) return *this;
        delete _ptr;
        _ptr = other._ptr;
        other._ptr = nullptr;
        return *this;
    }
    T* get() const{return _ptr;}
    T& operator*() const {return *_ptr;}
    T* operator->() const {return _ptr;}
    T* release(){
        T* temp = _ptr;
        _ptr = nullptr;
        return temp;
    }
    void reset(T* ptr){
        delete _ptr;
        _ptr = ptr;
    }
};

template<typename T>
class UniquePtr<T[]>{
private:
    T* _arr;
public:
    explicit UniquePtr(T* arr = nullptr) : _arr(arr){}
    ~UniquePtr(){delete[] _arr;}
    UniquePtr (const UniquePtr&) = delete;
    UniquePtr &operator=(const UniquePtr&) = delete;
    UniquePtr(UniquePtr&& other) noexcept : _arr(other._arr){
        other._arr = nullptr;
    } 
    UniquePtr& operator=(UniquePtr&& other) noexcept {
        if (this != &other) {
            delete[] _arr;
            _arr = other._arr;
            other._arr = nullptr;
        }
        return *this;
    }

    T& operator[](size_t index) const {
        return _arr[index];
    }

    T* get() const { return _arr; }
};

//template<typename T>
//UniquePtr<T> MakeUnique(size_t size) {
  //  return UniquePtr<T>(new T[size]); 
//}

template<typename T, typename... Args>
UniquePtr<T> MakeUnique(Args&&... args) {
    return UniquePtr<T>(new T(std::forward<Args>(args)...));
}

template<typename T>
UniquePtr<T> MakeUnique(size_t size) {
    using ClearType = typename std::remove_extent<T>::type;
    return UniquePtr<T>(new ClearType[size]);
}

#endif