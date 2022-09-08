//Programmer: Madison Passolano  ID: 12560375
//File: school.cpp               Date: 04-16-2020
//Purpose: where all of the school function definitions are kept 

#include "lunch.h"
#include "school.h"
#include "janitor.h"
#include "drink.h"
#include "head.h"


using std::cout; 
using std::cin; 


/*-----------SCHOOL------------------------------------------*/
School::School(const int input_size)
{
  set_size(input_size);  
  //set_numDrinks(drinks); 
  //clear();
  build_arr(); 
}

School::School()
{
  set_size(25); 
  //set_numDrinks()
  //clear();
  build_arr();
}

void School::clear_piece(const char val)
{
  for(int i=0; i<25; i++)
  {
    for(int j=0; j<25; j++)
    {
      if(m_school_arr[j][i] == val)
      {
        m_school_arr[j][i] = ' '; 
      }
    }
  }
  return; 
}

ostream& operator<<(ostream& out, const School& s)
{
  const int size = 25; 
  
  for(int i=0; i<(s.m_act_size*2)+1; i++)
    {
      out<<"-";
    }
    out<<endl;
    for(int i=0; i<s.m_act_size; i++)
    {
        out<<"|";
        for(int j=0; j<s.m_act_size; j++)
        {
            out<<s.m_school_arr[i][j]<<"|";
        }
        cout<<endl;
        for(int i=0; i<(s.m_act_size*2)+1; i++)
        {
           out<<"-";
        }
        out<<endl;
    }
    return out; 
}

void School::build_arr()
{
  //top of school is set to #
  for(int i=0; i<m_act_size; i++)
    {
       m_school_arr[0][i] = '#';
    }
    //bottom of school is set to #
    for(int i=1; i<m_act_size-1; i++)
    {
       m_school_arr[i][m_act_size-1] = '#';
    }
    for(int i=1; i<m_act_size-1; i++)
    {
       m_school_arr[i][0] = '#';
       m_school_arr[i][m_act_size] = '#';
    }
    for(int i=0; i<m_act_size; i++)
    {
       m_school_arr[m_act_size-1][i] = '#';
    }
    for(int i=1; i<m_act_size-1; i++)
    {
        for(int j=1; j<m_act_size-1; j++)
        {
            m_school_arr[i][j] = ' ';
        }
    } 
    for(int i=1; i<m_act_size-1; i=i+4)
    {
       m_school_arr[i][m_act_size-1] = '%';
       m_school_arr[i][0] = '%';
    }
    
    for(int i=1; i<m_act_size-1; i=i+4)
    {
       m_school_arr[m_act_size-1][i] = '%';
       m_school_arr[0][i] = '%';
    }
}

void School::set_position(const int x, const int y, const char z)
{
  //takes in the values calculated and then does this
  m_school_arr[x][y] = z; 
}



































