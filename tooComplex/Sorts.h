//@author Hans Brown
//@file Sorts.h
//@date 10-23-2015
//@brief: Sorts is a static object (one composed of only static methods) that can be called to perform sorting operations on given methods of undisclosed types. Also includes a clocking method to track efficiency of array sorting methods

#ifndef SRT_H
#define SRT_H
#include <iostream>
#include <random>
#include <ctime>
#include <chrono>
#include <cassert>
#include <functional>


template <typename T>
class Sorts //object inherits from object<templated>
{
    public:

//methods

    //@pre given array pointer and size beyond pointer to look
    //@post array given is sorted using given method
    //@return null
    static void bubbleSort(T arr[], int size); //start from far left, shifting right, comparing two adjacent elements and swapping
    
    //@pre given array pointer and size beyond pointer to look
    //@post array given is sorted using given method
    //@return null
    static void bogoSort(T arr[], int size); //uses randomization to sort array
    //rearrange all terms based on random number generator, then check if sorted
    
    //@pre given array pointer and size beyond pointer to look
    //@post array given is sorted using given method
    //@return null
    static void insertionSort(T arr[], int size); //take given element and keep shifting it left until it can't be shifted more
    //do this for all elements
    
    //@pre given array pointer and size beyond pointer to look
    //@post array given is sorted using given method
    //@return null
    static void selectionSort(T arr[], int size); //takes a position, and looks for element that goes at position
    
    //@pre given array pointer and size beyond pointer to look
    //@post returns true if array is sorted in ascending order, else returns false
    //@return bool
    static bool isSorted(T arr[], int size); //returns true if array is in ascending order
    
    //@pre given array pointer and size beyond pointer to look and a random number generator
    //@post reorders array using random number generator
    //@return null
    static void shuffle(T arr[], int size, std::default_random_engine& generator); //for each array element, swaps with another random element
    
    //@pre given perameters: size, min, and max values
    //@post builds an array given specified parameters (no less than min, no greater than max, size elements)
    //@return int array pointer
    static int* createTestArray(int size, int min, int max); //creates new array with specified size, and contains random values that fall within range specified by min and max (including those values)
    
    //@pre given a method to run, and parameters to pass into it (an array and a size) -- this method is assumed to be some sort of array sort method that takes an array (location and size) and runs its sorting method, tracking program time
    //@post array is sorted, return the time it took to perform operation
    //@return double
    static double sortTimer(std::function<void(T[],int)> sort, T arr[], int size); //attempts to sort the array, then returns the time it took to sort array
};

#include "Sorts.hpp"
#endif
