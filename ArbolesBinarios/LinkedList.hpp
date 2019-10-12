/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   LinkedList.hpp
 * Author: Usuario
 *
 * Created on 12 de noviembre de 2017, 03:09 PM
 */


#ifndef LINKEDLIST_HPP
#define LINKEDLIST_HPP

#include <vector>
#include "ListNode.hpp"

template < class T >
class LinkedList {
public:
    LinkedList( );
    bool isEmpty( );
    void addBegin( TreeNode< T >* );
    void addLast( TreeNode< T >* );
    TreeNode< T >* pop( );
    std::vector< T > getList( );
    virtual ~LinkedList();
    
private:
    ListNode< T >* head;
};

#endif /* LINKEDLIST_HPP */
