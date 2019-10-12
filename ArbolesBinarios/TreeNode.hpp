/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   TreeNode.hpp
 * Author: Usuario
 *
 * Created on 12 de noviembre de 2017, 03:05 PM
 */

#ifndef TREENODE_HPP
#define TREENODE_HPP
#include <cstdlib>

template < class T > class BinaryTree;
        
template < class T >
class TreeNode {
    friend class BinaryTree< T >;
public:
    TreeNode( T );
    T getInfo( );
    virtual ~TreeNode( );

private:
    T info;
    TreeNode< T >* left;
    TreeNode< T >* right;
};

template < class T >
TreeNode< T >::TreeNode( T info ){
    this->info = info;
    left = NULL;
    right = NULL;
}

template < class T >
T TreeNode< T >::getInfo( ){
    return info;
}

template < class T >
TreeNode< T >::~TreeNode( ){

}

#endif /* TREENODE_HPP */