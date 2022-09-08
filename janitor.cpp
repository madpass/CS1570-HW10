//Programmer: Madison Passolano   ID: 12560375
//File: janitor.cpp               Date: 04-16-2020
//Purpose: the janitor functions file  

#include "lunch.h"
#include "school.h"
#include "janitor.h"
#include "drink.h"
#include "head.h"

using std::cout; 
using std::cin; 

/*---------------------------JANITOR---------------------------------------*/

Janitor::Janitor()
{
  set_name("name"); 
  set_dead(false);
  set_sober(true); 
  set_caught_lunch(false); 
  set_bac(0.05); 
  set_bruises(0); 
  set_row(-1); 
  set_col(-1); 
}

Janitor::Janitor(const string name)
{
  set_name(name); 
  set_dead(false);
  set_sober(true); 
  set_caught_lunch(false);  
  set_bac(0.05);
  set_bruises(0);
  set_row(-1);
  set_col(-1);
}

void Janitor::place_me(School& s)
{
  //initialize placeholders 
  int val, j;
  
  //this finds the middle point of the arracol (it should)
  val = s.get_size()/2;  

  //set the new location in janitor within janitor 
  set_row(val); 
  set_col(val); 

  //gets the 'J' value for the janitor to put into the arracol
  j = get_piece();

  //this sends it to the School object that was used as the parameter 
  s.set_position(val, val, j); 

  return; 
}

bool Janitor::rand_walk(Drink array[], School& s, int num_drinks)
{
  int dir, row, col, temp;         //place holder for the direction value, and the row and col coord
  char val;              //hold the value returned from the school arracol 
  bool done = false;     //determines whether the do while loop is done 
  row = get_row();           //get his location from janitor
  col = get_col(); 

  
  do
  {  
    dir = rand() % 3; 
    //random number 0-3 to find the direction 
    //go down
    if(dir == 0)
    {       
      row++;                          //go in new direction                                        
      val = s.get_value(row, col);    //get the char at the new point                  
      if(val == ' ')                  //if the spot is open 
      {    
        set_row(row);                  //set the janitor row to the new row 
        s.clear_piece(get_piece());    //clear the board of the old J (before you put the new J in )
        done = true;                   //set done to true so the loop in this ends              
      }
      else if(val == 'D')         //if he hits a drink            
      { 
        s.clear_piece(get_piece());                 //clear the old j off of the screen, the D gets written over 
        m_bac += array[num_drinks-1].get_effect();  //increase the bac according to the value from the array of Drinks 
        num_drinks--;                               //decrease the number of drinks so that the next drink val in the array is used 
        set_row(row);                               //set the new point 
        if(m_bac < 0.08)
        {
          set_sober(true); 
        }
        else if(m_bac >= 0.25)   //if the bac is higher than the max
        { 
          set_dead(true);   //they are deemed dead 
          return true;      //this function returns true, meaning the simulation loop ends 
        }
        done = true;        //the loop ended                         
      }
      else if(val == 'L')
      { 
        s.clear_piece(get_piece()); 
        //FIX
        return true; 
      }
      else if(val == '#')  //if the next value would be a wall 
      {
        //hits a wall and gets a bruise 
        m_bruises++;   //inc number of bruises 
        row--;         //go back to the old position value and try again 
      }
      else if(val == '%')   //jumped out of the window 
      { 
        m_out_window = true; 
        s.clear_piece(get_piece());
        return true; 
      }
      else                                          
      {
        row--;        //if it doesnt hit any of those, go back to the old position                            
      }
    }
    //shift right 
    else if(dir==1)
    {
      col++;
      val = s.get_value(row, col);
      if(val == ' ')
      {  
        set_col(col);
        s.clear_piece(get_piece());
        done = true; 
      }
      else if(val == 'D')
      {
        s.clear_piece(get_piece()); 
        m_bac += array[num_drinks-1].get_effect();  
        num_drinks--; 
        set_col(col);
        if(m_bac < 0.08)
        {
          set_sober(true); 
        } 
        else if(m_bac >= 0.25)
        { 
          set_dead(true); 
          return true;  
        }
        done = true; 
      }
      else if(val == 'L')
      { 
        s.clear_piece(get_piece()); 
        m_caught_lunch = true; 
        return true; 
      }
      else if(val == '#')
      {
        m_bruises++; 
        col--; 
      }
      else if(val == '%')  
      { 
        m_out_window = true; 
        s.clear_piece(get_piece());
        return true; 
      }
      else 
      {
        col--;
      } 
    }
    //shift left 
    else if(dir==2)
    {
      row--;
      val = s.get_value(row, col);                     
      if(val == ' ')                                  
      {    
        set_row(row);
        s.clear_piece(get_piece());
        done = true;                              
      }
      else if(val == 'D')                    
      {
        s.clear_piece(get_piece()); 
        m_bac += array[num_drinks-1].get_effect();  
        num_drinks--; 
        set_row(row); 
        if(m_bac < 0.08)
        {
          set_sober(true); 
        }
        else if(m_bac >= 0.25)
        { 
          set_dead(true); 
          return true;  
        }
        done = true;                                 
      }
      else if(val == 'L')
      { 
        s.clear_piece(get_piece()); 
        m_caught_lunch = true; 
        return true; 
      }
      else if(val == '#')
      {
        //hits a wall and gets a bruise 
        m_bruises++; 
        row++; 
      }
      else if(val == '%') 
      { 
        m_out_window = true; 
        s.clear_piece(get_piece());
        return true; 
      }
      else
      {
        row++;
      }
    }
    //shift up 
    else if(dir==3)
    {
      col--; 
      val = s.get_value(row, col);
      if(val == ' ')
      {  
        set_col(col);
        s.clear_piece(get_piece());
        done = true; 
      }
      else if(val == 'D')
      {
        s.clear_piece(get_piece());
        m_bac += array[num_drinks-1].get_effect();  
        num_drinks--; 
        set_col(col); 
        if(m_bac < 0.08)
        {
          set_sober(true); 
        }
        else if(m_bac >= 0.25)
        { 
          set_dead(true); 
          return true;  
        }
        done = true; 
      }
      else if(val == 'L')
      { 
        s.clear_piece(get_piece()); 
        m_caught_lunch = true; 
        return true; 
      }
      else if(val == '#')
      {
        //hits a wall and gets a bruise 
        m_bruises++; 
        col++; 
      }
      else if(val == '%') //jumped out of the window 
      { 
        m_out_window = true; 
        s.clear_piece(get_piece());
        return true; 
      }
      else
      {
        col++;
      }

    }
  }while(done == false);
 
  s.set_position(row, col, get_piece());
  //cout<<"done w janitor"<<endl; 
  //sends the new row and col coord and character representation of janitor back to school 
  return false; //if he is still alive 
}

/*------------------sober------------------------------------------------------------------------*/


bool Janitor::sober_walk(Drink array[], School& s, Lunch& l, int num_drinks)
{
  int dir; 
  char val;
  bool done = false;  
  int l_row = l.get_row();   //row of the target 
  int l_col = l.get_col();   //column of the target
  int j_row = get_row();     //row of the janitor
  int j_col = get_col();     //col of the janitor 

  do
  {
    dir = rand() % 4; 

    if(dir == 0)
    {
      if(l_row > j_row)  //if lunch is lower than jan 
      {
        j_row++; 
        val = s.get_value(j_row, j_col); 
        if(val == ' ')   //if it is empty                  
        {    
          set_row(j_row);   //set the J in the new spot 
          s.clear_piece(get_piece());   //erase old J                            
        }
        else if(val == 'D')   //if you land on a drink          
        {
          set_row(j_row);    //move to that piece 
          s.clear_piece(get_piece());     //clear old piece 
          m_bac += array[num_drinks-1].get_effect();    //change the bac depending on the number of drinks 
          num_drinks--;   //i pass in the num_drinks not as a copy so it is manipulated each time 
          if(m_bac >= 0.08)  //if he is considered drunk 
          {
            set_sober(false);  //he is not sober, this will cause the rand walk to be called instead of sober 
          }
        }
        else if(val == 'L')  //if catch lunch 
        { 
          s.clear_piece(get_piece());   //clear the old piece 
          set_caught_lunch(true);   //set to true 
          return true;    // return true so the simulation do while loop can end 
        }
        else if(val == 'T')   //if willie steps on a trap, he gets a bruise 
        {
          m_bruises += 5;   //inc number of bruises 
          s.clear_piece(get_piece()); //clear old J, new J will be set at the bottom  
        }
      }
    }

    else if(dir == 1)
    {
      if(l_row < j_row)    
      {
        j_row--; 
        val = s.get_value(j_row, j_col); 
        if(val == ' ')
        {
          set_row(j_row); 
          s.clear_piece(get_piece()); 
          done = true; 
        }
        else if(val == 'D')
        {
          s.clear_piece(get_piece()); 
          m_bac += array[num_drinks-1].get_effect();  
          num_drinks--; 
          set_row(j_row); 
          if(m_bac >= 0.08)
          {
            set_sober(false); 
          } 
          done = true; 
        }
        else if(val == 'L')
        { 
          s.clear_piece(get_piece()); 
          set_caught_lunch(true);
          done = true; 
          return true; 
        }
        else if(val == 'T')   //if willie steps on a trap, he gets a bruise 
        {
          m_bruises += 5; 
          s.clear_piece(get_piece()); 
          done = true; 
        }
      }
    }

    else if(dir == 2)
    {
      if(l_col > j_col)    
      {
        j_col++; 
        val = s.get_value(j_row, j_col); 
        if(val == ' ')
        {
          set_col(j_col); 
          s.clear_piece(get_piece()); 
          done = true; 
        }
        else if(val == 'D')
        {
          s.clear_piece(get_piece()); 
          m_bac += array[num_drinks-1].get_effect();  
          num_drinks--; 
          set_col(j_col); 
          if(m_bac >= 0.08)
          {
            set_sober(false); 
          } 
          done = true; 
        }
        else if(val == 'L')
        { 
          s.clear_piece(get_piece()); 
          set_caught_lunch(true);
          done = true; 
          return true; 
        }
        else if(val == 'T')   //if willie steps on a trap, he gets a bruise 
        {
          m_bruises += 5; 
          s.clear_piece(get_piece()); 
          done = true; 
        }
      }
    }

    else if(dir == 3)
    {
      if(l_col < j_col)
      {
        j_col--; 
        val = s.get_value(j_row, j_col); 
        if(val == ' ')
        {
          set_col(j_col); 
          s.clear_piece(get_piece()); 
          done = true; 
        }
        else if(val == 'D')
        {
          s.clear_piece(get_piece()); 
          m_bac += array[num_drinks-1].get_effect();  
          num_drinks--; 
          set_col(j_col); 
          if(m_bac >= 0.08)
          {
            set_sober(false); 
          } 
          done = true; 
        }
        else if(val == 'L')
        { 
          s.clear_piece(get_piece()); 
          set_caught_lunch(true); 
          done = true; 
          return true; 
        }
        else if(val == 'T')   //if willie steps on a trap, he gets a bruise 
        {
          m_bruises += 5; 
          s.clear_piece(get_piece());
          done = true; 
        }
      }
    }

  }while(done == false);
  s.set_position(j_row, j_col, get_piece()); //this sets the final J 
  return false;  //returns false if willie didnt catch the lunch 
}


void Janitor::print()
{
  cout<<"\nJanitor Name: "<<m_name<<endl;
  cout<<"Blood alcohol Content: "<<m_bac<<endl;
  cout<<"Number of bruises: "<<m_bruises<<endl;
  if(m_dead == true)
  {
    cout<<"Janitor has died."<<endl; 
  }
  else
  {
    cout<<"Janitor is alive."<<endl; 
  }
}














