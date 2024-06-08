#include<iostream>
#include<cmath>
#include<cstring>
using namespace std;
int stacks[1000];
int top=-1;
int size=0;
int temp_stack[100];
int top2=-1;

void push_arr(int item)
  {
     if(top==999)
      cout<<"the stack is full"<<endl;
     else
       {
      top++;
      stacks[top]=item;
       }       
  }
void pop()  
    {   
        if(top == -1)   
            cout<<"the stack is empty "<<endl;
        else  
          top--;  
    }  
  //the function to check weather the stack is empty or not
bool isempty()
  {
     if(top==-1)
       return true;
     else
       return false;
   }  
   //the function to check weather the stack which take the bits after the point is empty or not
   bool temp_isempty()
  {
     if(top2==-1)
       return true;
     else
       return false;
   }  
   //the function which delete the respective bits in the temp_stack
   void temp_pop()  
    {   
        if(top2 == -1)   
            cout<<"the stack is empty "<<endl;
        else  
          top2--;  
    } 
void decimal_to_binary(float num) 
{
    // Split the float into its integer and fractional parts
    float nembr=num;
	if(num<0)
     num=-(num);

    int intPart = (int)num;
    float fracPart = num - intPart;
    // Convert the integer part to binary
    while (intPart > 0) {
         push_arr(intPart % 2);
        intPart /= 2;
    }
    if(nembr<0)
    push_arr(1);
    else
    push_arr(0);
     while (!isempty())
    {
        cout << stacks[top];
        pop();
    }
  
    if(fracPart!=0)
    {
     cout << ".";
     for (int i = 0; i < 10; i++) {
        fracPart *= 2;
        if (fracPart >= 1)
        { 
            push_arr(1); //because the number is negative
             if(fracPart==1)
              break;
             else 
             fracPart -= 1;
        } 
        else
          push_arr(0); //because the number is positive
      }
      //take the bits in the stacks to temp_stack      
      while(top!=-1)
      {
         top2++;
        temp_stack[top2]=stacks[top];
        pop();
      }
      //display the nubers after the decimal point
     while (!temp_isempty()) 
       {
        cout <<temp_stack[top2];
        temp_pop();
       }
    }
}

	string modify_binary(string binary) 
  {	
    bool hasDot = false;

    for (int i = 0; i < binary.length(); i++) {
        if (binary[i] == '.')
           {
            hasDot = true;
            break;
           }
      }
    if (hasDot==false) 
        binary+=".";

    return binary;
  }

void binary_to_decimal(string binary)
  { 
        int decimal=0;
        float fract=0;
  	 int dot=binary.find('.');
  	 string before=binary.substr(0,dot); //take the number before the decimal point
  	 string after=binary.substr(dot+1);  ////take the number after the decimal point
  	 int frac_len=after.length();
     //push the integer bits in to the stack
  	 while(top<dot-1)
  	   {
  	   	 top++;
  	   	 stacks[top]=before[top];
		 }
    int i=0;
    //converting the binary to decimal
  while(top!=-1)
     {
     if(stacks[top]=='1')
      decimal+=pow(2,i);
      i++;
      pop();
	   }
  //push the bits after the floating point
  while(top<frac_len-1)
  	   {
  	   top++;
  	   stacks[top]=after[top];
	     }	
  i=frac_len;
  //converting the binary after the floating point to decimal
  while(top!=-1)
    {
     if(stacks[top]=='1')
	   fract=fract+pow(2,-i); 
	   pop();
	   i--;
    }
  cout<<decimal+fract<<endl;  
  }

bool validate_decimal(string dec)
  {  int n=dec.length();
     bool check=true;
    
    for(int i=0;i<n;i++)
       {
       if(!(dec[i]<='9'&&dec[i]>='0'||dec[0]=='-'||dec[i]=='.'))
          check=false;
       }
     return check;
  }
bool validate_binary(string bin)
 {
    int n=bin.length();
    bool check=true;

    for(int i=0;i<n;i++)
        {
         if(!(bin[i]=='0'||bin[i]=='1'||bin[i]=='.'||bin[0]=='-'))
           check=false;
        }
    return check;
 }

int main()
{
  cout<<"\n\tNAME: ASMAMAW KASSAHUN   ID: 1404416\n\n";
  cout<<"\t\t~~~DIRECTION~~~\n";
 
   cout<<"***********************************************************************************\n";  
   cout<<"||This c++ program converts any decimal numbers to the equivalent binary number  ||\n||and vice versal. This include:                                                 ||\n||           ->converting negative and positive integer to binary                ||\n||           ->converting negative and positive floating points to binary        ||\n||           ->converting integer and floating point binary to decimal.          ||\n||When we convert negative decimals to the equivalent binary we can use different||\n||methods. From these methods I have used signed representation. The left most   ||\n||bit of the converted binary represent the sign i.e. if the bit is 1 that number||\n||is negative and if that bit is 0 the number is positive. That means the left   ||\n||most bit doesn't represent the magnetude.                                      ||\n";
   cout<<"***********************************************************************************\n\n";
   system("color 9");
   char ch;
   do {
  cout<<"\nPress y to continue ...\n";
  cin>>ch;
  if(ch == 'y'||ch == 'Y')
  {
  system("cls");
  int choice;
  back:
  cout<<"enter\t1. to convert decimal to binary\n\t2. to convert binary to decimal\n";
  cin>>choice;

  switch(choice)
  {
     case 1:
     {
      string num;
      prev:
      cout<<"enter the decimal number\n";
      cin>>num;
      if(!validate_decimal(num))
         {
          cout<<"please insert the correct floating point\n";
          goto prev;
         }
      float flot=atof(num.c_str());
      cout<<"the binary equivalent in signed representation of "<<flot<<"  = ";
      decimal_to_binary(flot);
     }
    break;
    case 2:
    {
      string binary;
    above:
    cout<<"enter a binary number\n";
    cin>>binary;
     binary=	modify_binary(binary);
    if(!validate_binary(binary)){
        cout<<"please insert the correct binary number interms of 0 and 1\n";
        goto above;
          }
    cout<<"the decimal equivalent of "<<binary<<" = ";
    binary_to_decimal(binary);
    }
    break;
   default:
   cout<<"you inserted wrong number please insert the correct number \n ";
   goto back;
  }
  }
 }
  while(ch=='y'||ch=='Y');

  return 0;
}