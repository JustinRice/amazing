#include <cstddef>


template <class T>
class QNode{
    public:
        QNode();
        void setNext(T *);
        void clearNext();
        T * getNext();
        void setPrev(T *);
        void clearPrev();
        T * getPrev();
        void setData(T *);
        T * getData();
    private:
        T * data;
        T * next;
        T * prev;
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
void QNode<T>::setNext(T * n){
    next = n;
}

template<class T>
void QNode<T>::setPrev(T * p){
    prev = p;
}

template<class T>
T * QNode<T>::getNext(){
    return next;
}

template<class T>
T * QNode<T>::getPrev(){
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
