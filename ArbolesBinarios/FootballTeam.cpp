/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   FootballTeam.cpp
 * Author: Usuario
 * 
 * Created on 17 de noviembre de 2017, 06:00 AM
 */

#include <sstream>
#include "FootballTeam.hpp"
using namespace std;

FootballTeam::FootballTeam() {
}

FootballTeam::FootballTeam(string idTeam, string name, int age, double value) {
    this->idTeam = idTeam;
    this->name = name;
    this->age = age;
    this->value = value;
}

string FootballTeam::getIdTeam(){
    return idTeam;
}

string FootballTeam::getName(){
    return name;
}

int FootballTeam::getAge(){
    return age;
}

double FootballTeam::getValue(){
    return value;
}

void FootballTeam::setAge(int age){
    this->age = age;
}

void FootballTeam::setValue(double value){
    this->value = value;
}

void FootballTeam::setIdTeam(std::string idTeam){
    this->idTeam = idTeam;
}

void FootballTeam::setName(std::string name){
    this->name = name;
}

void FootballTeam::convertString(std::string& chain,  int val){
    ostringstream output;
    output<<val;
    chain = output.str();
}

void FootballTeam::convertString(std::string& chain,  double val){
    ostringstream output;
    output<<val;
    chain = output.str();
}

string FootballTeam::toString(){
    string output = "";
    string ageAux; 
    string valueAux;
    convertString(ageAux, getAge());
    convertString(valueAux, getValue());
    output = "FootballTeam[idTeam = "+getIdTeam()+", Name = "+getName()+", Age = "+ageAux+", Value = "+valueAux
            +"]";
    return output;
}

FootballTeam::~FootballTeam() {
}

