/*
 * Name: Kevin Mody
 * Date Submitted: 02/16/2021
 * Lab Section: 004
 * Assignment Name: Searching and Sorting
 */

#pragma once

#include <vector>
#include <iostream> 
using namespace std;

template <class T>
int linearSearch(std::vector<T> data, T target){
    for(int i = 0; i < data.size();i++){
        std::cout<<data[i] << std:: endl;
        if(data[i]==target)
            return i;
    }
    return -1;
}

template <class T>
int binaryHelper(std::vector<T> data, T target, int startpoint, int endpoint){
    int midpoiint = (startpoint+endpoint)/2;
    if(data[midpoiint]==target){
        return midpoiint;
    } else if(startpoint == endpoint){
        return -1;
    } else {
        if (data[midpoiint]>target){
            return binaryHelper(data, target, startpoint, (midpoiint - 1));
        } else{
            return binaryHelper(data, target, (midpoiint+1), endpoint);
        }
    }
}
template <class T>
int binarySearch(std::vector<T> data, T target){
    int endpoint = data.size();
    return binaryHelper(data, target, 0, endpoint);
}
