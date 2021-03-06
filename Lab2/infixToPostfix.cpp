/*
 * Name: Kevin Mody 
 * Date Submitted: 01/27/2021   
 * Lab Section: 004
 * Assignment Name: Lab 2: Infix to Postfix Conversion
 */

#include <string>
#include <stack>
#include <iostream>
using namespace std;

//Converts an infix arithmetic expression into postfix
//The function takes 3 parameters
//First parameter: array of strings for infix expression
//    each string is either an integer number or operator symbol
//Second parameter: number of strings in infix expression
//Third parameter: array of strings for postfix expression
//    generated by function, same format as first parameter
//    assumes that postfix is at least the size of postfix
//Return value: int, number of strings in postfix expression
//    Returns 0 if an error is encountered when converting expression
//    An error occurs with a mismatched parenthesis, e.g. ( ( ) or ( ) ) etc.
//Operator symbols:
// ( : left parenthesis, all operations between this and ")" take place first
// ) : right parenthesis, all op.s back to previous "(" take place first
// * : multiplication, higher precedence - takes place before "+" and "-"
// / : division, higher precedence - takes place before "+" and "-"
// % : remainder, higher precedence - takes place before "+" and "-"
// + : addition, lower precedence - takes place after "*" , "/" , "%"
// - : subtraction, lower precedence - takes place after "*" , "/" , "%"
//The function is not specified to work with any other operator symbols
//Any string in infix may be assumed to be an integer operand if none
// of the above symbols
int checkOrder(char check)
{
    // checks precedence of operators
    if (check == '/' || check == '*' || check == '%')
    {
        return 2;
    }
    else if (check == '+' || check == '-')
    {
        return 1;
    }
    else
    {
        return -1;
    }
}
int infixToPostfix(string infix[], int length, string postfix[])
{
    int count = 0;
    int index = 0;
    int value = length;
    int countOpen = 0;
    int countClose = 0;
   
    // creates stack called fixStack
    stack<string> fixStack;
    // used to check if it is empty
    fixStack.push("X");
   
    // for loop to check if the '(' and ')' allign
     for (int i = 0; i < length -1; i++)
     {
         if(infix[i][0] != '(' && infix[i][0] == infix[ i + 1] [0] && infix[i][0] != ')')
         {
             value = 0;
         }
     }
     // for loop to scan the array
   /* for(int i = 0; i < 1; i++)
    {
        if((infix[i] == 1) || (infix[i] == 2) || (infix[i] == 3) || (infix[i] == 4)
        || (infix[i] == 5) || (infix[i] == 6) || (infix[i] == 7) || (infix[i] == 8))
    } */

  for( int i = 0; i < length; i++)
  {
    // checks numbers into stack
    if(isdigit(infix[i][0]))
    {
       /* string hold = fixStack.top();
        postfix[count++] = hold;
        count++; */
        postfix[index++] = infix[i];
    }
    else if (infix[i][0] == '(')
    {
        // adds to stack and increases count
        fixStack.push(infix[i]);
        count = count + 1;
        countOpen = countOpen + 1;
    }
     else if (infix[i][0] == ')')
    {
        while(fixStack.top()[0] != 'X' && fixStack.top()[0] != '(')
        {
            // adds to stack and removes
            string hold = fixStack.top();
            fixStack.pop();
            postfix[index++] = hold;
           // count++;
        }
           // increases count
           count = count + 1;
           countClose = countClose + 1;
           
         // checks stack and removes
        if(fixStack.top()[0] == '(')
        {
            fixStack.pop();
        }
    }
   /* else if( infix[i][0] == '/' || infix[i][0] == '*' || infix[i][0] == '%')
    {
        while(!fixStick.empty() && fixStick.top()!= '+' && fixStack.top() != '-' && fixStack.top()!= '(')
        {
            postfix[index] = fixStack.top();
            fixStack.pop();
           
        }
       
    }*/
   
   else
    {   // while loop to compare/precedence
        while(fixStack.top()[0] != 'X' && checkOrder(infix[i][0]) <= checkOrder(fixStack.top()[0]))
        {
            string hold = fixStack.top();
            fixStack.pop();
            postfix[index++] = hold;
        }
        fixStack.push(infix[i]);
    }
  }
    value = value - count;
   
   // empties the stack
   if (countClose != countOpen)
   {
       value = 0;
   }
   else
   {
      for(index = index; index < value; index++)
      {
          postfix[index] = fixStack.top();
          fixStack.pop();
      }
   }
   // returns int
   return value;
}

int main()
{
    string infixExp[] = {"2", "+", "3", "*", "4", "+", "(",
                         "5", "-", "6", "+", "7", ")", "*",
                         "8"};
    string postfixExp[15];
    int postfixLength;

    cout << "Infix expression: ";
    for (int i=0; i<15; i++)
    {
        cout << infixExp[i] << " ";
    }
    cout << endl;
    cout << "Length: 15" << endl << endl;

    postfixLength = infixToPostfix(infixExp, 15, postfixExp);

    cout << "Postfix expression: ";
    for (int i=0; i<postfixLength; i++)
    {
        cout << postfixExp[i] << " ";
    }
    cout << endl;
    cout << "Length: " << postfixLength << endl;
    
    return 0;
}