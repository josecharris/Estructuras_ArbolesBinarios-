/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Account.cpp
 * Author: Usuario
 * 
 * Created on 17 de noviembre de 2017, 03:42 PM
 */

#include <sstream>
#include <iosfwd>
#include <string>
#include <iostream>
#include "Account.hpp"

Account::Account() {
}
Account::Account(std::string number,std::string headLine,double residue,bool state,double residueMin) {
    setNumber(number);
    setHeadLine(headLine);
    setResidue(residue);
    setState(state);
    setresidueMin(residueMin);
}

std::string Account::getNumber() {
    return number;
}

void Account::setNumber(std::string number) {
    this->number=number;
}
std::string Account::getHeadLine() {
    return headLine;
}
void Account::setHeadLine(std::string headLine) {
    this->headLine=headLine;
}
double Account::getResidue() {
    return residue;
}
void Account::setResidue(double residue) {
    this->residue=residue;
}
bool Account::getState() {
    return state;
}
void Account::setState(bool state) {
    this->state=state;
}
double Account::getResidueMin() {
    return residueMin;
}
void Account::setresidueMin(double residueMin) {
    this->residueMin=residueMin;
}
Account::~Account() {
}

