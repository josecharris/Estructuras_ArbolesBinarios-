/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   BinaryTree.hpp
 * Author: Usuario
 *
 * Created on 12 de noviembre de 2017, 03:07 PM
 */

#ifndef BINARYTREE_HPP
#define BINARYTREE_HPP

#include "TreeNode.hpp"
#include <iostream>
#include <sstream>
#include <vector>

#include "TreeNode.hpp"
#include <string>
#include <vector>

template < class T >
class BinaryTree {
public:
    BinaryTree( );
    bool isEmpty( );
    void addNode( T );
    TreeNode< T >* findNode( std::string );
    TreeNode< T >* findFather(  TreeNode< T >* );
    T* findObject( std::string );
    std::vector< T > listPreorden( );
    std::vector< T > listInorden( );
    std::vector< T > listPosorden( );
    std::vector< T > listAmplitudeDown( );
    std::vector< T > listAmplitudeTop( );
    int calculateWeightTree( );
    short int calculateGradeNode(TreeNode<T>*);
    short int calculateHeightTree( );
    short int calculateHeightNode( TreeNode<T>* );
    short int calculateLevelNode( TreeNode<T>* );
    short int calculateLevelNodeClass(std::string);
    T deleteNode( TreeNode< T >* );
    virtual ~BinaryTree();
    T showNode(TreeNode< T >*);
private:
    TreeNode< T >* root;
    std::vector<T> output;
    short int height;
    
    void preorden( TreeNode<T>* );
    void inorden( TreeNode<T>* );
    void posorden( TreeNode<T>* );
    short int weightTree( TreeNode<T>* );
    short int heightTree( TreeNode<T>*, int );
    void deleteSheet( TreeNode<T>* );
    void deleteWithSon( TreeNode<T>* );
    void deleteWithChildren( TreeNode<T>* );
    
};

#endif /* BINARYTREE_HPP */