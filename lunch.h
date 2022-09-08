//Programmer: Madison Passolano   ID: 12560375
//File: lunch.h                   Date: 04-16-2020
//Purpose: the lunch class file


#ifndef LUNCH_H
#define LUNCH_H

#include <iostream>
#include <string.h>
#include <cstdlib>
#include <time.h>
#include "school.h"


using namespace std;

/*--------------------Documentation----------------------------*/
//Desc: Lunch() is the default constructor
//Pre: none 
//Post: the member variables are filled with default values 

//Desc: all set functions take in a value and set the private member variable to that value 
//Pre: a value must be passed in 
//Post: the member variable is now assigned the new value 

//Desc: get functions return a private member variable's value 
//Pre: none 
//Post: returned a private member variable value 

//Desc: place_me() places the L in a random spot in the grid 
//Pre: pass by reference the school the lunch should be in with a created school array
//Post: the lunch is placed in the grid array in the school 

//Desc: rand_walk() finds a direction and places the L in a new cell one over 
//Pre: pass by reference the school the lunch should be in with a created school array 
//Post: the lunch is placed in a new spot in the grid array of the school 

/*--------------------Class------------------------------------*/

class Lunch
{
  public: 
    Lunch(); 
    //set 
    void set_row(const int x){m_row = x;}
    void set_col(const int y){m_col = y;}
    //get
    int get_row(){return m_row;}
    int get_col(){return m_col;}
    char get_piece(){return m_lun_piece;}
    char get_trap_piece(){return m_trap_piece;}
    bool is_trapped(){return m_trapped;}
    //functions 
    void place_me(School& s);
    void place_trap(School& s, const int amt); 
    void rand_walk(School& s); 

  private: 
    static char m_lun_piece;   //const char with value 'C' 
    static char m_trap_piece; 
    bool m_trapped; 
    int m_row;         //row
    int m_col;         //column
};

#endif



