#ifndef QNODE_H_
#define QNODE_H_

#include <cstddef>


template <class T>
class QNode{
    public:
        QNode();
        void setNext(QNode<T> *);
        void clearNext();
        QNode<T> * getNext();
        void setPrev(QNode<T> *);
        void clearPrev();
        QNode<T> * getPrev();
        void setData(T *);
        T * getData();
    private:
        T * data;
        QNode<T> * next;
        QNode<T> * prev;
};


template<class T>
QNode<T>::QNode(){
    data = NULL;
    next = NULL;
    prev = NULL;
}

template<class T>
void QNode<T>::clearNext(){
    next = NULL;
}

template<class T>
void QNode<T>::clearPrev(){
    prev = NULL;
}

template<class T>
void QNode<T>::setNext(QNode<T> * n){
    next = n;
}

template<class T>
void QNode<T>::setPrev(QNode<T> * p){
    prev = p;
}

template<class T>
QNode<T> * QNode<T>::getNext(){
    return next;
}

template<class T>
QNode<T> * QNode<T>::getPrev(){
    return prev;
}

template<class T>
void QNode<T>::setData(T * d){
    data = d;
}

template<class T>
T * QNode<T>::getData(){
    return data;
}

#endif
