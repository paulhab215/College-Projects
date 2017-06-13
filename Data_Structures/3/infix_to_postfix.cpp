#include <iostream>
#include <string>


using namespace std;

class mystack{
   char stackarray[20];
   int tos;
   
 public :
   mystack()
   {
      tos = -1;
   }
   
   void push(char c)
   {
       if(tos == 20)
         cout<<"stack is full"<<endl;
       else
         stackarray[++tos] = c;
   }
   
   char pop()
   {
      char c;
      if (tos == -1)
        cout<<"stack is empty"<<endl; 
      else
        c = stackarray[tos--];
            
      return c; 
   }
   
   char topOfStack()
   {
       return  stackarray[tos];
   }
   
   void showStack()
   {
      if (tos == -1)
        cout<<"stack is empty"<<endl; 
      else
        for(int i=0;i<=tos;i++)
          cout<<stackarray[i]<<" "; 
      cout<<endl;
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

int priority(char x)
{
   if(x == '(')
     return(0);
   if(x == '+' || x == '-')
     return(1);
   if(x == '*' || x == '/' || x == '%')
     return(2);
   return(3);
}

void convert_infix_to_postfix(string s)
{
  // cout<<"###   Length of string : "<<s<<"is"<<s.length()<<endl; 
  // cout<<s[2]<<endl;
  mystack stk;
  int i=0;
  char c;
  
  while( i<s.length())
  {
     if ( isalnum(s[i]) )
       cout<<s[i];
     else
     {
       if( s[i] == '(' )
          stk.push(s[i]);
          
       else if( s[i] == ')' )
         while( (c=stk.pop()) != '(' )
            cout<<c;
            
       else
        {
          while( ( priority(s[i]) < priority(stk.topOfStack()) ) && !stk.isStackEmpty()  )
            {
                c = stk.pop();
                cout<<c; 
            }
          stk.push(s[i]);
        }
     }
     
     i++;  
  }
  
  while( !stk.isStackEmpty() )
  {
     c = stk.pop();
     cout<<c;     
  }
  cout<<endl;
  
}

int main()
{
  string s;
  for(int i =0; i<5; i++)
  {
    cout<<"Enter the infix expression : ";
    cin>>s;
    convert_infix_to_postfix(s);
  }
   
  
  return 0;  
}
