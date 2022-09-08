//Programmer: Madison Passolano   Date: 05/05/2020
//file: functions.cpp             ID: 12560375
//purpose: where the simulation function is held 


//this holds all of the main funcitons 

#include "lunch.h"
#include "school.h"
#include "janitor.h"
#include "drink.h"
#include "head.h"

using namespace std; 
//              i                  15         6           4           4
void simulation(const int day, const int grid_size, const int num_drinks, const int num_traps, const int window_frequency)
{
  bool done = false;       //whether or not were done looping through one simulation 
               //only when willie falls, he catches the lunch, or dies of alcohol poisoning 
  School sch1(grid_size); 
  Janitor jan("Willie"); 
  Lunch lun; 

  const int MAX_DRINKS = 20; 
  Drink drink_arr[MAX_DRINKS]; //array of drinks that uses the default constructor upon creation 

  sch1.build_arr(); 

  jan.place_me(sch1);         //passes in the school and places the janitor within it
  lun.place_me(sch1);         //same but lunch 
  for(int i=0; i<num_drinks; i++)
  {
    drink_arr[i].place_me(sch1);  //takes in num drinks and school and places all of the drinks
  }
  lun.place_trap(sch1, num_traps); //places the traps 
  
  do
  { 
    if(jan.get_sober() == false)   //if he is not sober 
    {
      done = jan.rand_walk(drink_arr, sch1, num_drinks); //jan walk 
      if(num_drinks != 6)
      {
        cout<<num_drinks<<endl; 
      }
    }
    else  //if he is sober 
    {
      done = jan.sober_walk(drink_arr, sch1, lun, num_drinks);
      if(num_drinks != 6)
      {
        cout<<num_drinks<<endl; 
      }
    }

    if(lun.is_trapped() == false)
    {
      lun.rand_walk(sch1);   //lunch walk 
    }
    if(day < 1)
    {
      cout<<sch1<<endl; 
      usleep(200000);
    } 
  

    //cout<<count<<endl;    <-- ignore 
  }while(done == false); //move janitor while alive 

  //jan.print(); //printing janitor stats 



}














