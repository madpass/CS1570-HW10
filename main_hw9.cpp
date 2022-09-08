m //Programmer: Madison Passolano  ID: 12560375
//File: main_hw9.cpp             Date: 04-16-2020
//Purpose: what controls the whole program 

#include "lunch.h"
#include "school.h"
#include "janitor.h"
#include "drink.h"
#include "head.h"
#include <fstream>

char Janitor::m_jan_piece = 'J'; 
char Lunch::m_lun_piece = 'L';
char Drink::m_drink_piece = 'D';
char Lunch::m_trap_piece = 'T';
//using static member variables so you have to declare them in main 

int main()
{
  srand(time(NULL)); 
  //seeds the time 
  ifstream in;
  ofstream out;

  int days;
  int grid_size;
  int num_drinks;
  int num_traps;
  int window_frequency;
  int wind_count = 0, caught_lunch_count = 0;  

  in.open("config.dat");
    {
      in >> days;
      in >> grid_size;
      in >> num_drinks;
      in >> num_traps;
      in >> window_frequency;
      in.close();
    }

  for(int i=0; i<days; i++)
  {
    simulation(i, grid_size, num_drinks, num_traps, window_frequency); 
    /*
    if(jan.get_out_window() == true)
    {
      wind_count++;
    }
    if(jan.get_caught_lunch() == true)
    {
      caught_lunch_count++; 
    }
    */
  } 

  cout<<"Out Window: "<<(wind_count/days)*100<<endl; 
  cout<<"Caught Lunch: "<<(caught_lunch_count/days)*100<<endl; 

  return 0; 
}





