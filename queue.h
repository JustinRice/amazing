
#ifndef QUEUE_H_
#define QUEUE_H_

#include "qnode.h"
#include <cstddef>

template <class T>
class Queue{
    public:
        Queue();
        ~Queue();
        void enqueue(T);
        T dequeue();
        int getSize();
        bool isEmpty();
    private:
        QNode<T> * head;
        QNode<T> * tail;
        int size;
};

template<class T> Queue<T>::Queue(){
    head = NULL;
    tail = NULL;
    size = 0;
}

template<class T> Queue<T>::~Queue(){
    while (size > 0)
        dequeue();
}

template<class T> void Queue<T>::enqueue(T data){
    QNode<T> * n = new QNode<T>();
    *n.setData(* data);
    if (tail != NULL){
        *tail.setNext(n);
        *n.setPrev(tail);
        tail = n;
    }
    else{
        head = n;
        tail = n;
    }
    size ++;
}

template<class T> T Queue<T>::dequeue(){
    if (size == 0)
        return NULL;
    T * tmp = head;
    head = *tmp.getNext();
    *head.setNext(NULL);
    size --;
    return *tmp.getData();
}

template<class T> int Queue<T>::getSize(){
    return size;
}

template<class T> bool Queue<T>::isEmpty(){
    if (size > 0)
        return false;
    return true;
}



#endif
