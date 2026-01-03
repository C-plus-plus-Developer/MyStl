#include "String.h"
#include <stdexcept>

String::String(const char* arr) {
    if (!arr) {
        _size = 1;
        _arr = MakeUnique<char[]>(_size);
        _arr[0] = '\0';
    } else {
        _size = std::strlen(arr) + 1;
        _arr = MakeUnique<char[]>(_size);
        for(size_t i = 0; i < _size; ++i) {
            _arr[i] = arr[i];
        }
    }
}

String::~String() = default;

String::String(const String& other) {
    std::cout << "String COPY constructor called!" << std::endl;
    _size = other._size;
    if (other._arr.get()) {
        _arr = MakeUnique<char[]>(_size);
        for(size_t i = 0; i < _size; ++i) {
            _arr[i] = other._arr[i];
        }
    } else {
        _size = 1;
        _arr = MakeUnique<char[]>(_size);
        _arr[0] = '\0';
    }
    std::cout << "String COPY constructor finished!" << std::endl;
}

String& String::operator=(const String& other) {
    if (this == &other) {
        return *this;
    }
    
    _size = other._size;
    if (other._arr.get()) {
        _arr = MakeUnique<char[]>(_size);
        for(size_t i = 0; i < _size; ++i) {
            _arr[i] = other._arr[i];
        }
    } else {
        _size = 1;
        _arr = MakeUnique<char[]>(_size);
        _arr[0] = '\0';
    }
    
    return *this;
}

String::String(String&& other) noexcept 
    : _arr(MyStd::move(other._arr)), _size(other._size) {
    other._size = 0;
}

String& String::operator=(String&& other) noexcept {
    if (this == &other) {
        return *this;
    }
    
    _arr = MyStd::move(other._arr);
    _size = other._size;
    other._size = 0;
    
    return *this;
}

String String::operator+(const String& other) const {
    size_t newSize = _size + other._size - 1;
    auto newArr = MakeUnique<char[]>(newSize);
    
    for(size_t i = 0; i < _size - 1; ++i) {
        newArr[i] = _arr[i];
    }

    for(size_t i = 0; i < other._size; ++i) {
        newArr[_size - 1 + i] = other._arr[i];
    }
    
    return String(newArr.get());
}

char& String::operator[](size_t index) {
    if (index >= _size - 1) {
        throw std::out_of_range("Error: index >= size - 1");
    }
    return _arr[index];
}

const char& String::operator[](size_t index) const {
    if (index >= _size - 1) {
        throw std::out_of_range("Error: index >= size - 1");
    }
    return _arr[index];
}

bool String::empty() const {
    return _size <= 1;
}

size_t String::length() const {
    return _size > 0 ? _size - 1 : 0;
}

const char* String::c_str() const {
    return _arr.get();
}

std::ostream& operator<<(std::ostream& os, const String& other) {
    os << other._arr.get();
    return os;
}

bool String::operator==(const String& other) const {
    if(_size != other._size) return false;
    for(size_t i = 0; i < _size; ++i){
        if(_arr[i] != other._arr[i]) return false;
    }
    return true;
}

bool String::operator!=(const String& other) const{
    return !(*this==other);
}
    
char* String::begin(){return _arr.get();}
char* String::end(){return _arr.get() + _size - 1;}

const char* String::begin() const{return _arr.get();}
const char* String::end() const{return _arr.get() + _size - 1;}
