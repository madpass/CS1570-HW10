//Programmer: Madison Passolano   ID: 12560375
//File: school.h                  Date: 04-16-2020
//Purpose: the school class file 

#ifndef SCHOOL_H
#define SCHOOL_H

#include <iostream>


using namespace std; 

/*--------------------Documentation----------------------------*/
//Desc: School() is the default constructor
//Pre: none 
//Post: the member variables are filled with default values 

//Desc: School() is the specified constructor
//Pre: passes in a positive grid size (only one value since its a square)
//Post: member variable name is filled in with a user defined value 

//Desc: all set functions take in a value and set the private member variable to that value 
//Pre: a value must be passed in 
//Post: the member variable is now assigned the new value 

//Desc: get functions return a private member variable's value 
//Pre: pass in an x and y coord within the size of the array  
//Post: returned a the char at that spot 

//Desc: print_whole() prints out the entire grid with the right formatting 
//Pre: none 
//Post: the grid is printed 

//Desc: build_arr() creates the bare grid without all of the lines and dashes, it doesnt include the J and C
//Pre: none 
//Post: the array is filled with the basic grid 



//CHANGE!!!!!!!//Desc: set_jan() changes the value of the array where the janitor is to be placed   
//Pre: find an x and y coord that is open and pass in the character to represent the janitor 
//Post: 'J' is placed in the array where the x and y specify 

//Desc: set_lunch() chnages the value of the array where the lunch is to be placed   
//Pre: find an x and y coord that is open and pass the character to represent the lunch 
//Post: 'J' is placed in the array where the x and y specify 



/*--------------------Class------------------------------------*/

class School 
{
  public: 
    //constructors
    School(const int input_size); 
    School(); 
    //set 
    void set_size(const int input_size){m_act_size = input_size;} 
    int get_size(){return m_act_size;}
    //egt
    char get_value(const int x, const int y){return m_school_arr[x][y];} 
    //build
    void build_arr(); 
    //set jan and lunch 
    void set_position(const int x, const int y, const char z);
    //array for drinks 
    //Drinks drinks_arr[20]; 
        //this is already filled with declared Drinks because it will call the default constructor to fill all 20 spots
        //the only spots we are abt are the first 4 bc thats how many drinks are on the grid and available for willie to 
        //drink. 
    void clear_piece(const char val);
    friend ostream& operator<<(ostream& out, const School& s); 
  private: 
    //member variables 
    char m_school_arr[25][25]; //declare the array with set size 
    int m_act_size;            //actual size of the school, what blocks will be filled or used
    //private functions 
     //should clear all of the values in school 
    //since this is a member function, i do not need to pass any of the member variables to use them in the function 
};



#endif








