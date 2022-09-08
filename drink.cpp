//Programmer: Madison Passolano   ID: 12560375
//File: drink.cpp                 Date: 04-28-2020
//Purpose: the drink functions file  

#include "lunch.h"
#include "school.h"
#include "janitor.h"
#include "drink.h"
#include "head.h"

using std::cout; 
using std::cin; 

Drink::Drink()
{
  //constructor 
  int val, holder;  
  val = rand()%1; 
  if(val == 0)
  {
    //negative so coffee, lowers the bac 
    holder = 001 + (rand() % 010);
    m_effect = holder/ -100.0;
    m_description = "coffee";
  }
  else if(val == 1)
  {
    //positive so whiskey, increases the bac 
    holder = 05 + (rand() % 10);
    m_effect = holder/100.0;
    m_description = "whiskey";
  }

}

//puts all the drinks on the grid 
void Drink::place_me(School& s)
{
  int size, min, max, x, y;
  char val; 
  bool done = false;  

  size = s.get_size(); //gets size of the school 
  min = 1;             //minimum value 
  max = size -1;       //max value without hitting boarders 

  do
  {
  x = min + rand() % ((max + 1) - min);
  y = min + rand() % ((max + 1) - min);

  val = s.get_value(x, y); //finds location 
  if(val == ' ') //if its open 
    {
      s.set_position(x, y, get_piece()); //puts 'D' on the grid at that location 
      done = true; //ends the do while loop 
    }

  }while(done == false); 

  return; 
}








