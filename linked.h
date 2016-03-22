#ifndef LINKED_H_
#define LINKED_H_

#include "qnode.h"
#include <cstddef>
#include <iostream>

using namespace std;

template <class T>
class Linked{
    public:
        Linked();
        ~Linked();
        T * get();
        void advance();
        void add(T *);
        T * remove();
        bool isEmpty();
        int getSize();
        void moveToHead();
        void moveToTail();
    private:
        QNode<T> * head;
        QNode<T> * tail;
        QNode<T> * current;
        int size;
};

template<class T> Linked<T>::Linked(){
    head = NULL;
    tail = NULL;
    current = NULL;
    size = 0;
}

template<class T> Linked<T>::~Linked(){
    while (size > 0){
        current = head;
        remove();
    }
}

template<class T> T * Linked<T>::get(){
    return current->getData();
}

template<class T> void Linked<T>::advance(){
    if (size > 1){
        if (current->getNext() == NULL)
            current = head;
        else
            current = current->getNext();
    }
}

template<class T> void Linked<T>::add(T * data){
    QNode<T> * n = new QNode<T>();
    n->setData(data);
    if (size >= 1){
        tail->setNext(n);
        n->setPrev(tail);
        tail = n;
    }
    else{
        head = n;
        tail = n;
        current = n;
    }
    size ++;
}

template<class T> void Linked<T>::moveToHead(){
    current = head;
}

template<class T> void Linked<T>::moveToTail(){
    current = tail;
}

template<class T> int Linked<T>::getSize(){
    return size;
}

template<class T> bool Linked<T>::isEmpty(){
    if (size > 0)
        return false;
    return true;
}

template<class T> T * Linked<T>::remove(){
    QNode<T> * n = current;
    if (size == 1){
        head = NULL;
        tail = NULL;
        current = NULL;
        size --;
    }
    else{
        QNode<T> * pre = n->getPrev();
        QNode<T> * nex = n->getNext();
        bool isTail, isHead;
        if (pre == NULL)
            isHead = true;
        if (nex == NULL)
            isTail = false;
        if (isHead){
            head = nex;
            head->setPrev(NULL);
            current = head;
        }
        else if (isTail){
            tail = pre;
            tail->setNext(NULL);
            current = tail;
        }
        else{
            pre->setNext(nex);
            nex->setPrev(pre);
            current = pre;
        }
    }
    size --;
    return n->getData();
}

#endif
