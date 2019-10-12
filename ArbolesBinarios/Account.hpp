/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Account.hpp
 * Author: Usuario
 *
 * Created on 17 de noviembre de 2017, 03:42 PM
 */

#ifndef ACCOUNT_HPP
#define ACCOUNT_HPP

class Account {
public:
    Account();
    Account(std::string,std::string,double,bool,double);
    void setNumber(std::string );
    void setHeadLine(std::string );
    void setResidue(double);
    void setresidueMin(double);
    void setState(bool);
    
    std::string getNumber();
    std::string getHeadLine();   
    double getResidueMin();
    double getResidue();
    bool getState();
    ~Account();
private:
    std::string number;
    std::string headLine;
    double residue;
    bool state;
    double residueMin;
};

#endif /* ACCOUNT_HPP */

