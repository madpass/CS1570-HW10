//Programmer: Madison Passolano   ID: 12560375
//File: lunch.cpp                 Date: 04-16-2020
//Purpose: the lunch functions file 

#include "lunch.h"
#include "school.h"
#include "janitor.h"
#include "drink.h"
#include "head.h"

using std::cout; 
using std::cin; 

Lunch::Lunch()
{
  set_row(-1); 
  set_col(-1);
  m_trapped = false;   //not trapped 
}

void Lunch::place_me(School& s)
{
  int size, min, max, row, col;
  char val; 
  bool done = false;  

  size = s.get_size(); //gets size of the school 
  min = 1;             //minimum value 
  max = size -1;       //max value without hitting boarders 

  do
  {
    row = min + rand() % ((max + 1) - min);
    col = min + rand() % ((max + 1) - min);
    //random place in grid 

    val = s.get_value(row, col); 
    if(val == ' ')
    {
      s.set_position(row, col, get_piece());
      done = true; 
    }

  }while(done == false);

  set_row(row); 
  set_col(col); 
  return; 
}

void Lunch::place_trap(School& s, const int amt)
{
  int size, min, max, row, col;
  char val; 
  bool done = false;  

  size = s.get_size(); //gets size of the school 
  min = 1;             //minimum value 
  max = size -1;       //max value without hitting boarders 

  for(int i=0; i<amt; i++)
  {
    done = false; 
    do
    {
      row = min + rand() % ((max + 1) - min);
      col = min + rand() % ((max + 1) - min);
      //random place in grid 

      val = s.get_value(row, col); 
      if(val == ' ')
      {
        s.set_position(row, col, get_trap_piece());
        done = true; 
      }

    }while(done == false);
  } 
  return;  
}

void Lunch::rand_walk(School& s)
{
  //look at the janitor one for reference 
  int dir, row, col; 
  char val;
  bool done = false;  
  row = get_row(); //get his location from janitor
  col = get_col(); 

  dir = rand() % 4;  

  if(dir == 0)
  { 
    row++; 
    val = s.get_value(row, col); 
    if(val == ' ')
    {
      set_row(row); 
      s.clear_piece(get_piece()); 
    }
    else if(val == 'T')
    {
      m_trapped = true;            //OK SO what i was going for is where it only calls the move lunch if this is false
      s.clear_piece(get_trap_piece()); 
    }
    else
    {
      row--; 
    }
  }

  else if(dir==1)
  {
    col++; 
    val = s.get_value(row, col); 
    if(val == ' ')
    {
      set_col(col); 
      s.clear_piece(get_piece()); 
    }
    else if(val == 'T')
    {
      m_trapped = true; 
      s.clear_piece(get_trap_piece());
    }
    else
    {
      col--; 
    }
  }
  
  else if(dir==2)
  {
    row--; 
    val = s.get_value(row, col); 
    if(val == ' ')
    {
      set_row(row); 
      s.clear_piece(get_piece());  
    }
    else if(val == 'T')
    {
      m_trapped = true; 
      s.clear_piece(get_trap_piece());
    }
    else
    {
      row++; 
    }
  }
  else if(dir==3)
  {
    col--; 
    val = s.get_value(row, col); 
    if(val == ' ')
    {
      set_col(col); 
      s.clear_piece(get_piece());  
    }
    else if(val == 'T')
    {
      m_trapped = true; 
      s.clear_piece(get_trap_piece()); 
    }
    else
    {
      col++; 
    }
  }

  s.set_position(row, col, get_piece());
  //cout<<"done with lunch"<<endl; 
}












