/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   LinkedList.cpp
 * Author: Usuario
 * 
 * Created on 12 de noviembre de 2017, 03:09 PM
 */

#include "LinkedList.hpp"

template < class T >
LinkedList< T >::LinkedList( ) {
    head = NULL;
}

template< class T >
bool LinkedList< T >::isEmpty( ) {
    return head == NULL;
}

template< class T >
void LinkedList< T >::addBegin( TreeNode< T >* node ) {
    if ( isEmpty( ) ){
        head = new ListNode< T >( node );
    }
    else{
        ListNode< T >* newNode = new ListNode< T >( node );
        newNode->next = head;
        head = newNode;
    }
}

template< class T >
TreeNode< T >* LinkedList< T >::pop( ) {
    ListNode< T >* aux = head;
    TreeNode< T >* output = head->info;
    head = head->next;
    delete( aux );
    
    return output;
}


template< class T >
void LinkedList<T>::addLast( TreeNode<T>* node ) {
    if ( isEmpty( ) ){
        head = new ListNode< T >( node );
    }
    else{
        ListNode< T >* aux = head;
        while( aux->next != NULL ){
            aux = aux->next;
        }
        aux->next = new ListNode< T >( node );
    }
}

template< class T >
std::vector< T > LinkedList< T >::getList( ) {
    std::vector< T > output;
    ListNode< T >* aux = head;
    while( aux != NULL ){
        output.push_back( aux->info->getInfo());
        aux = aux->next;
    }
    
    return output;
}

template < class T >
LinkedList< T >::~LinkedList() {
    
}