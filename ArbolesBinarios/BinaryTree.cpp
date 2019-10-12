/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   BinaryTree.cpp
 * Author: Usuario
 * 
 * Created on 12 de noviembre de 2017, 03:07 PM
 */

#include "BinaryTree.hpp"
#include "TreeNode.hpp"
#include "LinkedList.hpp"
#include <vector>
#include <string>
#include <cstdlib>

template < class T >
BinaryTree< T >::BinaryTree( ) {
    root = NULL;
}

template < class T >
bool BinaryTree< T >::isEmpty( ){
    return root == NULL;
}

template < class T >
void BinaryTree< T >::addNode( T info ){
    if ( isEmpty( ) ){
        root = new TreeNode< T >( info );
    }
    else{
        TreeNode< T >* newNode = new TreeNode< T >( info );
        TreeNode< T >* actually = root;
        TreeNode< T >* last = NULL;
        while ( actually != NULL ){
            last = actually;
            actually = info.getIdTeam().compare( actually->info.getIdTeam()) > 0 ? actually->right : actually->left;
        }
        if (info.getIdTeam().compare(last->info.getIdTeam()) < 0 ){
            last->left = newNode;
        }
        else{
            last->right = newNode;
        }
    }
}

template < class T >
TreeNode<T>* BinaryTree< T >::findNode( std::string serial ){
    TreeNode< T >* aux = root;
    while( aux != NULL ){
        if ( aux->info.getIdTeam().compare( serial ) == 0 ){
            return aux;
        }
        aux = serial.compare( aux->info.getIdTeam( ) ) > 0 ? aux->right : aux->left;
    }
    
    return NULL;
}

template<class T>
T BinaryTree<T>::showNode(TreeNode<T>* node){
    return node->info;
}

template < class T >
T* BinaryTree< T >::findObject( std::string serial ){
    TreeNode< T >* aux = root;
    while( aux != NULL ){
        if ( aux->info.getIdTeam( ).compare( serial ) == 0 ){
            return &aux->info;
        }
        aux = serial.compare( aux->info.getIdTeam( ) ) > 0 ? aux->right : aux->left;
    }
    
    return NULL;
}

template<class T>
void BinaryTree<T>::preorden( TreeNode<T>* aux ) {
    if ( aux != NULL ){
        output.push_back( aux->info );
        preorden( aux->left );
        preorden( aux->right );
    }
}

template<class T>
std::vector<T> BinaryTree<T>::listPreorden() {
    output.clear( );
    preorden( root );
    return output;
}

template<class T>
void BinaryTree<T>::inorden( TreeNode<T>* aux ) {
    if ( aux != NULL ){
        inorden( aux->left );
        output.push_back( aux->info );
        inorden( aux->right );
    }
}

template<class T>
std::vector<T> BinaryTree<T>::listInorden( ) {
    output.clear( );
    inorden( root );
    return output;
}

template<class T>
std::vector<T> BinaryTree<T>::listPosorden( ) {
    output.clear( );
    posorden( root );
    return output;
}

template<class T>
void BinaryTree<T>::posorden( TreeNode<T>* aux ) {
     if ( aux != NULL ){
        posorden( aux->left );
        posorden( aux->right );
        output.push_back( aux->info );
    }
}

template< class T >
std::vector< T > BinaryTree<T>::listAmplitudeDown( ) {
    LinkedList< T > tailAux;
    LinkedList< T > tailPrint;
    
    tailAux.addLast( root );
    while ( !tailAux.isEmpty( ) ){
        TreeNode< T >* nodeAux = tailAux.pop( );
        if ( nodeAux->left != NULL ){
            tailAux.addLast( nodeAux->left );
        }
        if ( nodeAux->right != NULL ){
            tailAux.addLast( nodeAux->right );
        }
        
        tailPrint.addLast( nodeAux );
    }
    
    return tailPrint.getList( );
}

template<class T>
std::vector<T> BinaryTree<T>::listAmplitudeTop( ) {
    LinkedList< T > tailAux;
    LinkedList< T > tailPrint;
    
    tailAux.addLast( root );
    while ( !tailAux.isEmpty( ) ){
        TreeNode< T >* nodeAux = tailAux.pop( );
        if ( nodeAux->left != NULL ){
            tailAux.addLast( nodeAux->left );
        }
        if ( nodeAux->right != NULL ){
            tailAux.addLast( nodeAux->right );
        }
        
        tailPrint.addBegin( nodeAux );
    }
    
    return tailPrint.getList( );
}


template<class T>
TreeNode<T>* BinaryTree<T>::findFather( TreeNode<T>* node ) {
    if ( node == root ){
        return NULL;
    }
    TreeNode< T >* aux = root;
    while( aux->left != node && aux->right != node ){
        aux = aux->info.getIdTeam( ).compare( node->info.getIdTeam( ) ) > 0 ? aux->left : aux->right;
    }
    
    return aux;
}
template<class T>
int BinaryTree<T>::calculateWeightTree() {
    return weightTree( root );
}

template<class T>
short int BinaryTree<T>::weightTree( TreeNode<T>* node ) {
    if ( node != NULL ){
        return weightTree( node->left ) + weightTree( node->right ) + 1;
    }
    
    return 0;
}

template<class T>
short int BinaryTree<T>::calculateGradeNode( TreeNode<T>* node ) {
    if ( node->left == NULL && node->right == NULL ){
        return 0;
    }
    return node->left != NULL && node->right != NULL ? 2 : 1;
}

template<class T>
short int BinaryTree<T>::calculateHeightTree( ) {
    height = 0;
    heightTree( root, 1 );
    return height;
}

template<class T>
short int BinaryTree<T>::heightTree( TreeNode<T>* node, int level ) {
    if ( node != NULL ){
        heightTree( node->left, level + 1 );
        if ( level > height ){
            height = level;
        }
        heightTree( node->right, level + 1 );
    }
    
    return 0;
}

template<class T>
short int BinaryTree<T>::calculateHeightNode( TreeNode<T>* node ) {
    height = 0;
    heightTree( node, 1 );
    return height;
}

template< class T >
short int BinaryTree< T >::calculateLevelNode( TreeNode< T >* node ) {
    if ( node == root ){
        return 0;
    }
    else{
        short int level = 1;
        TreeNode< T >* aux = root;
        while ( aux->left != node && aux->right != node ){
            level++;
            aux = aux->info.getIdTeam( ).compare( node->info.getIdTeam( ) ) > 0 ? aux->left : aux->right;
        }
    
        return level;
    }
}

template< class T >
short int BinaryTree< T >::calculateLevelNodeClass(std::string id) {
    TreeNode< T >* node = findNode(id);
    if ( node == root ){
        return 0;
    }
    else{
        short int level = 1;
        TreeNode< T >* aux = root;
        while ( aux->left != node && aux->right != node ){
            level++;
            aux = aux->info.getIdTeam( ).compare( node->info.getIdTeam( ) ) > 0 ? aux->left : aux->right;
        }
    
        return level;
    }
}


template<class T>
T BinaryTree<T>::deleteNode( TreeNode< T >* node ) {
    T output = node->info;
    
    switch( calculateGradeNode( node ) ){
        case 0 : deleteSheet( node );
        break;
        
        case 1 : deleteWithSon( node );
        break;
        
        default : deleteWithChildren( node );
    }
    
    delete( node );
    
    return output;
}

template< class T >
void BinaryTree< T >::deleteSheet( TreeNode< T >* node ) {
    TreeNode< T >* father = findFather( node );
    if ( father == NULL ){
        root = NULL;
    }
    else{
        if ( father->left == node ){
            father->left = NULL;
        }
        else{
            father->right = NULL;
        }
    }
}

template< class T >
void BinaryTree< T >::deleteWithChildren( TreeNode< T >* node ) {
    TreeNode< T >* sustitute = node->right;
    TreeNode< T >* fatherSustitute = NULL;
    while ( sustitute->left != NULL ){
        fatherSustitute = sustitute;
        sustitute = sustitute->left;
    }
    if ( fatherSustitute != NULL ){
        fatherSustitute->left = sustitute->right;
        sustitute->right = node->right;
    }
    sustitute->left = node->left;
    TreeNode< T >* father = findFather( node );
    if ( father == NULL ){
        root = sustitute;
    }
    else{
        if ( father->left == node ){
            father->left = sustitute;
        }
        else{
            father->right = sustitute;
        }
    }
}

template< class T >
void BinaryTree< T >::deleteWithSon( TreeNode< T >* node ) {
    TreeNode< T >* father = findFather( node );
    if ( father == root ){
        root = father->left == node ? father->left : father->right;
    }
    else{
        if ( father->left == node ){
            father->left = node->left != NULL ? node->left : node->right;
        }
        else{
            father->right = node->left != NULL ? node->left : node->right;
        }
    }
}



template < class T >
BinaryTree< T >::~BinaryTree( ) {
    
}