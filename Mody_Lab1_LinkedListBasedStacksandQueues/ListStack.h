/*
 * Name:Kevin Mody
 * Date Submitted: 01/21/2021
 * Lab Section: 004
 * Assignment Name: Lab1 Linked List Based Stacks and Queues
 */

#pragma once
#include "List.h"
//This class represents a Stack implemented via Linked List
//Do not modify anything in the class interface
template <class T>
class ListStack{

 private:
  List<T> stack;

 public:
  ListStack();
  ~ListStack();
  int size();
  bool empty();
  void push(T);
  T pop();
  //Print the name and this ListStack's size and values to stdout
  //This function is already implemented (no need to change it)
  void print(string name){
    stack.print(name);
  }

}; //end of class interface (you may modify the code below)

//Implement all of the functions below

//Construct an empty ListStack by initializing this ListStack's instance variables
template <class T>
ListStack<T>::ListStack(){
   // List<T> * temp = new List<T>();
    //stack = *temp;
    
}

//Destroy all nodes in this ListStack to prevent memory leaks
template <class T>
ListStack<T>::~ListStack(){
   // stack.~List();
}

//Return the size of this ListStack
template <class T>
int ListStack<T>::size(){
    return stack.size();
}

//Return true if this ListStack is empty
//Otherwise, return false
template <class T>
bool ListStack<T>::empty(){
    if(stack.size()==0){
        return stack.empty();
    }
    else{
        return false;
    }
}

//Create a node with value <value> and push it onto the stack
template <class T>
void ListStack<T>::push(T value){
    stack.insertStart(value);
}

//Pop a node from the Stack.
//Note that here that includes both removing the node from the stack
//AND returning its value.
template <class T>
T ListStack<T>::pop(){
    T temp = stack.getFirst();
    stack.removeStart();
    return temp;
}
