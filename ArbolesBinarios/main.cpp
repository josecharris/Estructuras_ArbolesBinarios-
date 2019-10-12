/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Usuario
 *
 * Created on 12 de noviembre de 2017, 03:02 PM
 */

#include <cstdlib>
#include <iostream>
#include <sstream>
#include <vector>
#include <string>
#include "FootballTeam.hpp"
#include "BinaryTree.hpp"
#include "BinaryTree.cpp"
#include "TreeNode.hpp"
#include "ListNode.hpp"
#include "LinkedList.hpp"
#include "LinkedList.cpp"

using namespace std;

/*
 * 
 */
void listMt(vector<FootballTeam> mt , string t){
    for(int i=0; i<mt.size(); i++){
        cout<<mt.at(i).toString()<<endl;
       
    }
    cout<<endl;
}
    
std::string IdBuscar;
BinaryTree<FootballTeam> listTeams;
TreeNode<FootballTeam>* aux;
TreeNode<FootballTeam>* aux2;
std::string id;
std::string name;
int credits;
double varDouble;
int auxLevel;
int opc;
void addTeams();
void listPreSort();
void listPosSort();
void listInOrden();
void findNodo();
void findFather();
void calculateHeightTree();
void calculateWeightTree();
void calculateHeightNode();
void listAmplitudTop();
void listAmplitudDown();
void deleteNode();
void calculateGradeNode();
void showLevel(int);
void showSheets();


int main(int argc, char** argv) {
    

    listTeams.addNode(FootballTeam("50","Manchester United",4,3.4));
    listTeams.addNode(FootballTeam("25","Real Madrid",3,4.5));
    listTeams.addNode(FootballTeam("15","Ajax",4,1));
    listTeams.addNode(FootballTeam("37","Chelsea FC",3,4));
    listTeams.addNode(FootballTeam("10","cester",3,7));
    listTeams.addNode(FootballTeam("30","sea FC",3,4));
    listTeams.addNode(FootballTeam("45","Lei",3,7));    
    listTeams.addNode(FootballTeam("75","Liverpool",3,6.7));   
    listTeams.addNode(FootballTeam("65","Leicester",3,7));
    listTeams.addNode(FootballTeam("87","CheFC",3,4));
    listTeams.addNode(FootballTeam("82","cester",3,7));
    listTeams.addNode(FootballTeam("95","sea FC",3,4));
    listTeams.addNode(FootballTeam("80","Lei",3,7));
    
    
    
    
    
    
    do{
        cout<<"Bienvenidos al Menu\n"
                "1.Agregar \n"
                "2.Listar Preorden\n"
                "3.Listar PosOrden\n"
                "4.Listar InOrden\n"
                "5.Listar Amplitud Ariiba\n"
                "6.Listar Amplitud Abajo\n"
                "7.Buscar Nodo\n"
                "8.Buscar Padre\n"
                "9.Eliminar Nodo\n"
                "10.Calcular Altura del Arbol\n"
                "11.Calcular peso del Arbol\n"
                "12.Calcular Altura Nodo\n"
                "13.El Numero de Hijos de un Nodo\n"
                "14.Salir"
                "\n15.Mostrar Nivel"
                "16.Nodos hoja\n"
                "\n"
                "Digite una Opcion ....."<<endl;
        cin>>opc;
                switch(opc){
                    
                    case 1:addTeams();
                        break;
                    case 2:listPreSort();
                        break;
                    case 3:listPosSort();
                        break;
                    case 4:listInOrden();
                        break;
                    case 5:listAmplitudTop();
                        break;
                    case 6:listAmplitudDown();
                        break;
                    case 7:findNodo();
                        break;
                    case 8:findFather();
                        break;
                    case 9:deleteNode();
                        break;
                    case 10:calculateHeightTree();
                        break;
                    case 11:calculateWeightTree();
                        break;
                    case 12:calculateHeightNode();
                        break;
                    case 13:calculateGradeNode();
                        break;
                    case 14:  cout<<"Gracias Hasta luego, saliendo.."<<endl;
                        opc=14;
                        break;
                    case 15:
                        cout<<"Digite el nivel : "<<endl;
                        cin>>auxLevel;
                        showLevel(auxLevel-1);
                        break;
                    case 16:
                        showSheets();                       
                        break;
                        
                }
                
    }while(opc!=14);

    return 0;
}

void addTeams(){
    cout<<"Digite el codigo del equipo\n";
    cin>>id;
    cout<<"Ingrese nombre del equipo\n";
    cin>>name;
    cout<<"Ingrese la edad del equipo\n";
    cin>>credits;
    cout<<"Ingrese el valor\n";
    cin>>varDouble;
    listTeams.addNode(FootballTeam(id,name,credits,varDouble));
}

void listPreSort(){
    listMt(listTeams.listPreorden(), "PreOrden");
}

void listPosSort(){
    listMt(listTeams.listPosorden(), "PosOrden");
}

void listInOrden(){
    listMt(listTeams.listInorden(), "InOrden");
}


void findNodo(){
    cout<<"Ingrese ID a Buscar\n";
    cin>>IdBuscar;
    TreeNode<FootballTeam>*father = listTeams.findNode( IdBuscar);
     if(father){
        cout<<"Existe "<<listTeams.showNode (father).toString()<<endl;
    }else{
        cout<<"No existe";
    }
}

void findFather(){
    cout<<"Ingrese ID  \n";
    cin>>IdBuscar;
    TreeNode<FootballTeam>*father = listTeams.findNode( IdBuscar );
     if(father){
         TreeNode<FootballTeam>*papa = listTeams.findFather( father );
        cout<<"Existe "<<listTeams.showNode( papa ).toString()<<endl;
    }else{
        cout<<"No existe";
    }

}

void calculateHeightTree(){
    cout<<"ALTURA "<<listTeams.calculateHeightTree()<<"\n"<<endl;
}

void calculateWeightTree(){
    cout<<"PESO "<<listTeams.calculateWeightTree()<<"\n"<<endl;
}
  
void calculateHeightNode(){
    if(!(listTeams.isEmpty())){
    cout<<"Ingrese ID \n";
    cin>>IdBuscar;
    TreeNode<FootballTeam>*  node = listTeams.findNode(IdBuscar);
    if(node!=NULL){
        cout<<"Altura : "<<listTeams.calculateHeightNode(node)<<endl;
    }else{
        cout<<"No existe";
    }
    }
}

void listAmplitudTop(){
    listMt(listTeams.listAmplitudeTop(),"Amplitud hacia arriba\n");
}
    
void listAmplitudDown(){
    listMt(listTeams.listAmplitudeDown(),"Amplitud hacia abajo\n");
}

void calculateGradeNode(){
    if(!(listTeams.isEmpty())){
    cout<<"Ingrese ID \n";
    cin>>IdBuscar;
    TreeNode<FootballTeam>*  node = listTeams.findNode(IdBuscar);
    if(node!=NULL){
        cout<<"Grado es de : "<<listTeams.calculateGradeNode(node)<<endl;
    }else{
        cout<<"No existe";
    }
    }
}

void deleteNode(){
    cout<<"Ingrese ID a eliminar"<<endl;
    cin>>IdBuscar;
    TreeNode<FootballTeam>*father=listTeams.findNode(IdBuscar);
    if(father!= NULL){
        cout<<"Se elimino: "<<listTeams.deleteNode(father).toString()<<endl;
    }
}

void showLevel(int level){
    for(int i=0; i<listTeams.listInorden().size(); i++){
        if(listTeams.calculateLevelNodeClass(listTeams.listInorden()[i].getIdTeam()) == level){
             cout<<listTeams.listInorden().at(i).toString()<<endl;
        } 
       
    }
}

void showSheets(){
    for(int i=0; i<listTeams.listInorden().size(); i++){
        if(listTeams.calculateGradeNode(listTeams.findNode(listTeams.listInorden()[i].getIdTeam()))==0){
            cout<<listTeams.listInorden()[i].toString()<<endl;
        }
    }
}

