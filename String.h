#ifndef STRING_H
#define STRING_H

#include <iostream>
#include "UniquePtr.h"
#include <cstring>
#include "Algorithm.h"

class String {
private:
    UniquePtr<char[]> _arr;
    size_t _size;

public:
    String(const char* arr = "");
    ~String();
    
    String(const String& other);
    String(String&& other) noexcept;
    
    String& operator=(const String& other);
    String& operator=(String&& other) noexcept;
    bool operator==(const String& other) const;
    bool operator!=(const String& other) const;
    String operator+(const String& other) const;
    char& operator[](size_t index);
    const char& operator[](size_t index) const;
    
    bool empty() const;
    size_t length() const;
    const char* c_str() const;
    
    friend std::ostream& operator<<(std::ostream& os, const String& other);

    char* begin();
    char* end();
    const char* begin() const;
    const char* end() const;
};

namespace MyStd{
    template<>
    struct Hash<String>{
        size_t operator()(const String& key) const{
            const size_t FNV_prime = 1099511628211u;
            const size_t offset_basis = 14695981039346656037u;

            size_t hash = offset_basis;
            
            for (char c : key) {
                hash ^= static_cast<size_t>(c); 
                hash *= FNV_prime;              
            }
            
            return hash;
        }
    };
};

#endif 