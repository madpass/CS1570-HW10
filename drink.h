//Programmer: Madison Passolano   ID: 12560375
//File: drink.h                   Date: 04-28-2020
//Purpose: the drink header file 


#ifndef DRINK_H 
#define DRINK_H

#include <iostream>
#include <string.h>
#include <cstdlib>
#include <time.h>

using namespace std; 

/*-----------Documentation---------------------------------------------------*/



class Drink
{
  public: 
    Drink(); 
    void place_me(School& s); 
    void set_desc(const string x){m_description = x;}
    void set_effect(const float x){m_effect = x;}
    string get_desc(){return m_description;}
    float get_effect(){return m_effect;}
    char get_piece(){return m_drink_piece;}

  private: 
    string m_description; 
    static char m_drink_piece; 
    float m_effect; 
};

#endif