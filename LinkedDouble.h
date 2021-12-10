//
// Created by USUARIO on 9/12/2021.
//

#ifndef TALLERINDIVIDUALLISTASDOBLES_LINKEDDOUBLE_H
#define TALLERINDIVIDUALLISTASDOBLES_LINKEDDOUBLE_H
#include "NodeDouble.h"
#include<vector>
#include <string>
using namespace std;


template <class T>
class LinkedDouble {
public:
    LinkedDouble();

    bool isEmpty();

    void addNodeFirst( T );

    void addNodeLast( T );

    void addNodeSorted( T );

    NodeDouble<T>* findNode( string );

    T* findInfo( string );

    void addNodeBeforeTo( NodeDouble<T>*, T);

    void addNodeAfterTo( NodeDouble<T>*, T);

    std::vector<T> getList(bool);

    int getSize();

    T* getObject(int);

    T deleteNode(NodeDouble<T>* node){
        T out = node->info;
        if(node == head){
            head = head->next;
        }else{
            NodeDouble<T>*aux =head;
            while(aux->next!=node){
                aux=aux->next;
            }
            aux->next = node->next;
        }
        delete(node);
        return out;
    }

    virtual ~LinkedDouble();

private:
    NodeDouble<T>* head;
    NodeDouble<T>* last;

};



#endif //TALLERINDIVIDUALLISTASDOBLES_LINKEDDOUBLE_H
