/*
 * Name: Kevin Mody
 * Date Submitted: 04/01/2021
 * Lab Section: 004 
 * Assignment Name: Min-Heap Implementation Using a Vector

 */
#pragma once

#include <vector>

using namespace std;

//This class defines a heap where each node has a
//less or equal value than all child nodes (min-heap)
//Implemented using a vector of integers representing the
//values at each node of a complete binary tree
//Do not modify anything in the class definition

class minHeap
{
    private:
        vector<int> heap;
        //Implement the following functions that maintain the heap property
        void siftUp(int pos);
        void siftDown(int pos);
    public:
        minHeap() {} //Default constructor, heap is initiallay an empty vector
        vector<int> getHeap() {return heap;} //Returns heap data for test cases
        //Implement all the following functions
        minHeap(vector<int> data); //Should build the heap from bottom-up
        void insert(int value); //Insert value into heap
        int removeMin(); //Removes minimum value
};