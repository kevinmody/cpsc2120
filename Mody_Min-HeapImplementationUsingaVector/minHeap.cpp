/*
 * Name: Kevin Mody
 * Date Submitted: 04/01/2021
 * Lab Section: 004 
 * Assignment Name: Min-Heap Implementation Using a Vector
 */
#include <iostream>
#include "minHeap.h"
using namespace std;

void minHeap::siftUp(int pos)
{
    // parent
    int parent = (pos-1)/2;
    // child
    int child = pos;
    // keep comparing with parents
    while(child!=0 && heap[parent] > heap[child])
    {
        //swapping child with parent
        int temp = heap[parent];
        heap[parent] = heap[child];
        heap[child] = temp;
        // make current parent as child
        child = parent;
        // make new parent
        parent = (parent-1)/2;
    }
}

void minHeap::siftDown(int pos)
{
    int parent = pos;
    int child1 = 2*parent + 1;   //left child
    int child2 = 2*parent + 2;    //right child
    int swap = -1;
    // check left 
    if(child1 < (int)heap.size() && heap[child1] < heap[parent])
    {
        swap=child1;
    }
    // check right 
    if(child2 < (int)heap.size() && heap[child2] < heap[parent])
    {
        if (swap == -1) swap = child2;
        else
        {
            if (heap[child2] < heap[child1]) swap=child2;
        }
    }
    if(swap == -1) return;
    int temp=heap[parent];
    heap[parent]= heap[swap];
    heap[swap] = temp;
    siftDown(swap);
}
minHeap::minHeap(vector<int> data)
{
    //clearing heap
    heap.resize(0);
    for(int i = 0;i<(int)data.size();i++) heap.push_back(data[i]);
    for(int i=heap.size()-1;i>=0;i--) siftDown(i);
}
void minHeap::insert(int value)
{
    //insert at the end of the heap array
    heap.push_back(value);
    int position = heap.size()-1;
    siftUp(position);
}
int minHeap::removeMin()
{
    if(heap.size()== 0) return -1;
    int temp = heap[0];
    heap[0] = heap[heap.size()-1];
    heap[heap.size()-1] = temp;
    heap.pop_back();
    siftDown(0);
    return temp;
}
int main(){
    return 0;
}