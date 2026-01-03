#ifndef LIST_H
#define LIST_H

#include <iostream>
#include "Algorithm.h"

template<typename T>
class List{
private:
    struct Node{
        T data;
        Node* prev;
        Node* next;
        Node(const T& val) : data(val), prev(nullptr), next(nullptr) {}
    };
    Node* _head;
    Node* _end;
    size_t _size;
public:
    List() : _head(nullptr), _end(nullptr), _size(0) {}
    ~List(){ clear();}

    List(const List& other) : _head(nullptr), _end(nullptr){
        Node* current = other._head;
        while(current!=nullptr){
            push_back(current->data);
            current = current->next;
        }
    }

    List(List&& other) noexcept : _head(other._head), _end(other._end), _size(other._size){
        other._head = nullptr;
        other._end = nullptr;
        other._size = 0;
    }

    List& operator=(const List& other){
        if(this == &other) return *this; 
        List temp(other);
        MyStd::swap(_head, temp._head);
        MyStd::swap(_end, temp._end);
        MyStd::swap(_size, temp._size);
        return *this;
    }

    List& operator=(List&& other) noexcept {
        if(this!=&other){
        clear();

        _head = other._head;
        _end = other._end;
        _size = other._size;

        other._head = nullptr;
        other._end = nullptr;
        other._size = 0;
        }
        return *this;
    }

    void clear(){
        Node* current = _head;
        while(current != nullptr){
            Node* nextNode = current->next;
            delete current;
            current = nextNode;
        }
        _head = nullptr;
        _end = nullptr;
        _size = 0;
    }

    void pop_front(){
        if(_head == nullptr) return;
        Node* oldHead = _head;
        _head = _head->next;
        if(_head!=nullptr){
            _head->prev = nullptr;
        }
        else{
            _end = nullptr;
        }
        delete oldHead;
        _size--;
    }

    void push_back(const T& val){
        Node* newNode = new Node(val);
        if(_end == nullptr){
            _head = newNode;
            _end = newNode;
        }
        else{
            _end->next = newNode;
            newNode->prev = _end;
            _end = newNode;
        }
        _size++;
    }

    void remove(const T& value) {
        if(_head == nullptr) return;
        Node* current = _head;
        while(current != nullptr){
            if(current->data == value){
                if(current->prev == nullptr){
                    _head = current->next;
                }
                else{
                    current->prev->next = current->next;
                }
                if(current->next == nullptr){
                    _end = current->prev;
                }
                else{
                    current->next->prev = current->prev;
                }
                delete current;
                _size--;
                return;
            }
            current = current->next;
        }
    }

    size_t size() const{return _size;}
    bool emty() const{return _size==0;}

    struct Iterator{
        Node* ptr;
        Iterator& operator++(){ptr = ptr->next; return *this;}
        T& operator*()const{return ptr->data;}
        bool operator!=(const Iterator& other){return ptr != other.ptr;}
    };
    Iterator begin() const{return Iterator{_head};}
    Iterator end() const{return Iterator{nullptr};}
    T& back(){
        if(_end == nullptr) throw std::runtime_error("List empty");
        return _end->data;
    }
};

#endif 