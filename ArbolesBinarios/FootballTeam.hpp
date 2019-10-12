/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   FootballTeam.hpp
 * Author: Usuario
 *
 * Created on 17 de noviembre de 2017, 06:00 AM
 */

#ifndef FOOTBALLTEAM_HPP
#define FOOTBALLTEAM_HPP

class FootballTeam {
public:
    FootballTeam();
    FootballTeam(std::string,std::string,int,double);
    std::string getIdTeam();
    std::string getName();
    int getAge();
    double getValue();
    void setIdTeam(std::string);
    void setName(std::string);
    void setAge(int);
    void setValue(double);
    std::string toString();
    void convertString(std::string&, int);
    void convertString(std::string&, double);
    virtual ~FootballTeam();
private:
    std::string idTeam;
    std::string name;
    int age;
    double value;

};

#endif /* FOOTBALLTEAM_HPP */

