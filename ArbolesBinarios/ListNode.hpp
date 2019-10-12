/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   ListNode.hpp
 * Author: Usuario
 *
 * Created on 12 de noviembre de 2017, 03:11 PM
 */

#ifndef LISTNODE_HPP
#define LISTNODE_HPP

#include <cstdlib>
#include "TreeNode.hpp";

template < class T > class LinkedList;

template < class T >
class ListNode {
    
    friend class LinkedList< T >;
    
public:
    ListNode( TreeNode< T >* );
    virtual ~ListNode();
    
private:
    TreeNode< T >* info;
    ListNode< T >* next;
};

template < class T >
ListNode< T >::ListNode( TreeNode< T >* info ){
    this->info = info;
    next = NULL;
}

template < class T >
ListNode< T >::~ListNode(  ){

}

#endif /* LISTNODE_HPP */
