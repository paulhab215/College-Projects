/*******************************************************************************
 *
 * Project3.cpp - Data Structures
 * Created on: Mar 31, 2014
 * Author: Paul Habjanetz - ph1106 - A00579084
 *
 *******************************************************************************
 *******************************************************************************
 *
 * Description - Using Object Oriented Class Defintion for Stack -
 * Program evaluates postfix expression - up to ten times.
 *
 *******************************************************************************
 *******************************************************************************
 */



#include <iostream>				// necessary header
#include <string>				// for string
#include <sstream>				// for string


using namespace std;				// will not comment same as first assignment

class mystack{
   int stackarray[20];
   int tos;
   
 public :
   mystack()
   {
      tos = -1;
   }
   
   void push(int c)
   {
       if(tos == 20)
         cout << "stack is full" << endl;
       else
         stackarray[++tos] = c;
   }
   
   int pop()
   {
      int c;
      if (tos == -1)
        cout << "stack is empty" << endl; 
      else
        c = stackarray[tos--];
            
      return c; 
   }
   
   int topOfStack()
   {
       return  stackarray[tos];
   }
   
   void showStack()
   {
      if (tos == -1)
        cout << "stack is empty" << endl; 
      else
        for(int i=0;i<=tos;i++)
          cout << stackarray[i] << " "; 
      cout << endl;
   }
   
   
   
   int isStackEmpty()
   {
      if (tos == -1)
       return 1;
      else
       return 0;   
   } 
   
   int isStackFull()
   {
      if (tos == 20)
       return 1;
      else
       return 0;   
   }       
};

int calculate(int operand1 , int operand2, char c)		
{				// used to calculate operands
   int num = 0;
   switch(c)
   {
       case '+' : num = operand2 + operand1;	//add
                   break;
                   
       case '-' : num = operand2 - operand1;	// subtract
                   break;
                   
       case '*' : num = operand2 * operand1;	// multiply
                   break;
                   
       case '/' : num = operand2 / operand1;	// divide
                   break;
                   
       case '%' : num = operand2 % operand1;	// modulus 
                   break;
                   
       deafult  : cout << "cant calculate"<<endl;
   }
    
   return num; 				// return number
}

void postfix_evaluation(string s)	// used to evaluate
{
    mystack stk;			// mystack object
    int operand1, operand2, num;
    int i = 0;
    char chr;
    stringstream str;
    
    while( i<s.length())
    {
       if( isdigit(s[i]) )
       {
         chr = s[i];
         num = chr - '0';  		// converting single char to integer;
         stk.push(num);
       }
       else
       {
          operand1 = stk.pop();		//  pop first op
          operand2 = stk.pop();		// pop second op
          stk.push( calculate(operand1, operand2, s[i]) ); 
         
       } 
       i++;    				// increment counter
    }
    
  while( !stk.isStackEmpty() )		// pop stack until nothing is left
  {
     num = stk.pop();
     cout << "##############" << endl;
     cout << num;     			// output number
  } 
  cout << endl;                     
}


int main()				// main function driver
{
  string s;				
  for(int i =0; i<10; i++)		
  {
    cout << endl << "Enter the postfix expression : ";
    cin >> s;
    postfix_evaluation(s);
  }
   
    
  return 0;  				// exit
}
