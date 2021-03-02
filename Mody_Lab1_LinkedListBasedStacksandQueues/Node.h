/*
 * Name:Kevin Mody
 * Date Submitted: 01/21/2021
 * Lab Section: 004
 * Assignment Name: Lab1 Linked List Based Stacks and Queues
 */
#pragma once

template <class T>
class List;

//This class represents a node in a linked list
//Do not modify anything in this file
template <class T>
class Node{

 friend class List<T>;

 private:
  T value; //value stored by this node
  Node * next; //pointer to the next node in list

public:
 Node(T v){
   value = v;
   next = nullptr;
 }

};
