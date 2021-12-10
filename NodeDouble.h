//
// Created by USUARIO on 8/12/2021.
//


#ifndef TALLERINDIVIDUALLISTASDOBLES_NODEDOUBLE_H
#define TALLERINDIVIDUALLISTASDOBLES_NODEDOUBLE_H
#include <cstdlib>

template <class T> class LinkedDouble;

template <class T>
class NodeDouble {

    friend class LinkedDouble<T>;
public:
    NodeDouble(T info) : info(info) {
        next = previous = NULL;
    }

private:
    T info;
    NodeDouble<T>* next;
    NodeDouble<T>* previous;
};


#endif //TALLERINDIVIDUALLISTASDOBLES_NODEDOUBLE_H
