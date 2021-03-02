/*
 * Name: Kevin Mody
 * Date Submitted: 02/16/2021
 * Lab Section: 004
 * Assignment Name: Searching and Sorting
 */

#pragma once
#include <iostream>
#include <vector>
using namespace std;

template <class T>
void change(std::vector<T> &lst, int a, int b){
    T temp = lst[a];
    lst[a]= lst[b];
    lst[b]=temp;
}
template <class T>
int preChange(std::vector<T> &lst, int head, int tail){
    int pDex = ((tail-head)/2)+head;
    T pval = lst[pDex];
    int begin = head;
    int end = tail;
    
    while(begin <= end){
        while(lst[begin]<pval){
            begin++;
        }
        while(lst[end]>pval){
            end --;
    
        }
        if(begin <= end){
            change(lst, begin,end);
            begin++;
            end--;
        }
    }
    return begin;
}



template <class T>
void quickSortHelper(std::vector <T> &lst, int head , int tail){
    if(head<tail){
        int sortVal = preChange(lst, head, tail);
        quickSortHelper(lst, head, sortVal-1);
        quickSortHelper(lst, sortVal, tail);
    }
}

template <class T>
std::vector<T> quickSort(std::vector<T> lst){
    quickSortHelper(lst, 0, lst.size()-1);
    return lst;
}





template <class T>
std::vector <T> mergeSortHelper(std::vector <T> lst){
    std::vector<T> postVector;
    int start = 0;
    int finish = lst.size()/2;
    for(int i = 0; i < lst.size(); i++){
        if(start<lst.size()/2 && finish < lst.size()){
            if(lst[start]<=lst[finish]){
                postVector.push_back(lst[start]);
                start++;
            }
            else{
                postVector.push_back(lst[finish]);
                finish++;
            }
        }
        else if(start>=lst.size()/2){
            postVector.push_back(lst[finish]);
            finish++;
        }
        else if (finish>=lst.size()/2){
            postVector.push_back(lst[start]);
            start++;
        }
    }
    return postVector;
}


template <class T>
std::vector<T> mergeSort(std::vector<T> lst){
    quickSortHelper(lst,0,(lst.size()/2)-1);
    quickSortHelper(lst, lst.size()/2, lst.size()-1);
    return mergeSortHelper(lst);
    
}
