#ifndef ALGORITHM_H
#define ALGORITHM_H

namespace MyStd {
    
    template<typename T>
    struct remove_reference {
        using type = T;
    };

    template<typename T>
    struct remove_reference<T&> {
        using type = T;
    };

    template<typename T>
    struct remove_reference<T&&> {
        using type = T;
    };

    template<typename T>
    typename remove_reference<T>::type&& move(T&& t) noexcept {
        return static_cast<typename remove_reference<T>::type&&>(t);
    }

    template<typename T>
    struct Hash;

    template<>
    struct Hash<int>{
        size_t operator()(int key) const{
            return static_cast<size_t>(key);
        }
    };

    template<>
    struct Hash<char>{
        size_t operator()(char key) const{
            return static_cast<size_t>(key); 
        }
    };

    template<typename T>
    void swap(T& a, T& b) {
        T temp = MyStd::move(a); 
        a = MyStd::move(b);      
        b = MyStd::move(temp);   
    }

} 

#endif