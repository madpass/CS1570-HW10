//Programmer: Madison Passolano   ID: 12560375
//File: janitor.h                 Date: 04-16-2020
//Purpose: the janitor class file 

#ifndef JANITOR_H 
#define JANITOR_H

#include <iostream>
#include <string.h>
#include <cstdlib>
#include <time.h>
#include "drink.h"


using namespace std; 

/*--------------------Documentation----------------------------*/
//Desc: Janitor() is the default constructor
//Pre: none 
//Post: the member variables are filled with default values 

//Desc: Janitor() is the specified constructor
//Pre: string name has to be passed in 
//Post: member variables are filled in with defaults except for name 

//Desc: all set functions take in a value and set the private member variable to that value 
//Pre: a value must be passed in 
//Post: the member variable is now assigned the new value 

//Desc: get functions return a private member variable's value 
//Pre: none 
//Post: returned a private member variable value 

//Desc: place_me() places the J in the middle of the grid 
//Pre: pass by reference the school the janitor should be in with a created school array
//Post: the janitor is placed in the grid array in the school 

//Desc: rand_walk() finds a direction and places the J in a new cell one over 
//Pre: pass by reference the school the janitor should be in with a created school array 
//Post: the janitor is placed in a new spot in the grid array of the school 

//Desc: print() prints out the stats of the janitor 
//Pre: the stats have to be declared through the creation of the janitor 
//Post: the stats are outputted to the sceen


/*--------------------Class------------------------------------*/
class Janitor
{
  public: 
    //constructors
    Janitor(); 
    Janitor(const string name);
    //set functions 
    void set_bac(const double bac){m_bac = bac;}
    void set_bruises(const int bruise){m_bruises = bruise;}
    void set_row(const int x){m_row = x;}
    void set_col(const int y){m_col = y;}
    void set_name(const string name){m_name = name;} 
    void set_dead(const bool state){m_dead = state;}
    void set_sober(const bool state){m_sober = state;}
    void set_caught_lunch(const bool state){m_caught_lunch = state;}
    void set_out_window(const bool out){m_out_window = out;}
    //get functions
    char get_piece(){return m_jan_piece;}
    int get_col(){return m_col;}
    int get_row(){return m_row;}
    double get_bac(){return m_bac;}
    bool get_sober(){return m_sober;}
    bool get_out_window(){return m_out_window;}
    bool get_caught_lunch(){return m_caught_lunch;}
    //other 
    void place_me(School& s);   //places the J 
    bool rand_walk(Drink array[], School& s, int num_drinks);  //drunnk 
    bool sober_walk(Drink array[], School& s, Lunch& l, int num_drinks);  //sober 

    //print 
    void print();

  private: 
    //private
    double m_bac;               //the blood alcohol content 
    int m_bruises;              //the number of bruises 
    int m_row;                //the x coordinate 
    int m_col;                //the y coordinate 
    string m_name;              //the name of the janitor 
    bool m_out_window; 
    bool m_dead;             //alive, sober, drunk, or dead
    bool m_sober; 
    bool m_caught_lunch; 
    static char m_jan_piece;    //the character used to represent the janitor ('J')
};


#endif
