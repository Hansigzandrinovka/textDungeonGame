//@author Hans Brown
//@file Sorts.hpp
//@date 10-23-2015
//@brief: Sorts is a static object (one composed of only static methods) that can be called to perform sorting operations on given methods of undisclosed types. Also includes a clocking method to track efficiency of array sorting methods
#include <iostream>
#include <random>
#include <ctime>
#include <chrono>
#include <cassert>
#include <functional>

using namespace std;

//bubble: start at front, working to back, testing adjacent terms and swapping
//after each revision, last element will be lowest, so ignore it


template <typename T>
void Sorts<T>::bubbleSort(T arr[], int size)
{


    for(int i = 0; i < size; i++) //for each last term in list
        //iterate from 0 to size-1, increasing
    {
        //std::cout << "iteration: " << i << "\n";
        for(int j = 1; j < (size - i); j ++) //shift everything before and including term once
            //iterate from 1 to size - 1 - i, increasing
        {
            //std::cout << "        " << arr[j] << " position " << j << "\n";
            if(arr[j-1] >= arr[j]) //if a bigger value is in left term than right term, swap them
            {
                //std::cout << "swapping: " << arr[j-1] << " with " << arr[j] << "\n";
                int storedSwap = 0;
                storedSwap = arr[j];
                arr[j] = arr[j-1];
                arr[j-1] = storedSwap;
            }
            //else, we don't swap characters
        }
        //after one run of for-loop, largest value is on rightmost term we worked with,
        //so ignore that term in next run
    }

    assert( Sorts<T>::isSorted(arr, size));

    //std::cout <<"herpaderp";
}

//selection: take current as minimum element
//compare and replace through array
//swap first element with min,
//repeat for num of elements, bumping up "first" element to next

//insertion: 2 halves of array, sorted and unsorted
//take element from unsorted half, and find its location in sorted half, and place there
//repeat until sorted half is empty

//bogo: use shuffle method


template <typename T>
void Sorts<T>::selectionSort(T arr[], int size)
{
    for(int i = 0; i < size; i++) //for each position in array, starting at first (lowest term) position
    {
        int minPos = i;
        for(int j = (i + 1); j < size; j++) //goes through array, testing each element with a running min term : we don't worry about terms before i, because they have already been sorted
        {
            if(arr[minPos] > arr[j]) //if found term less than running min, it is now running min (so we eventually get lowest term in list)
            {
                minPos = j;
            }
        }
        //now, we know for certain where min val is at,
        //so swap it with i'th term - the position where current min term goes
        int placeHolder = arr[i];
        arr[i] = arr[minPos];
        arr[minPos] = placeHolder;
    } //each successivel loop ignores the i'th term from previous loop, so it sorts more efficiently

    assert( Sorts<T>::isSorted(arr, size));
}

template <typename T>
void Sorts<T>::bogoSort(T arr[], int size)
{
    std::default_random_engine generator(time(nullptr));
    while(!isSorted(arr, size))
    {
        shuffle(arr, size, generator);
    }

    assert( Sorts<T>::isSorted(arr, size));
}

template <typename T>
void Sorts<T>::insertionSort(T arr[], int size) //takes a value, and keeps shifting it right until it can't go further
{
    for(int unsortedPos = 1; unsortedPos < size; unsortedPos++) //for all elements in array, excluding first, because it is assumed to be already sorted
    {
        int comparedTerm = arr[unsortedPos]; //the term we will be trying to shift as far left as possible
        int compareToLocation = unsortedPos - 1; //the initial value to compare to
        while((compareToLocation >= 0) && (comparedTerm < arr[compareToLocation])) //if we can shift the watched term further left, and there are more terms left to compare to,
        {
            compareToLocation --;
        }
        //after this loop, we are watching either a nonexistent term (because we need to place unsortedPos behind last term) or a term smaller than the watched term, so we need to insert it to the right of that term
        //so, we need to insert comparedTerm at the current location, and shift everything to the right of it 1 unit further right
        //int placeHolder = arr[compareToLocation + 1];
        for(int i = unsortedPos; i > compareToLocation + 1; i--) //starting at unsorted Term, replace current term with term to left, until we get to the term right before hit term, then replace it
        {
            arr[i] = arr[i-1];
        }
        //now, the [compareToLocation+1] term should become the removed term
        arr[compareToLocation+1] = comparedTerm;
    } //after 1 execution, we know terms 0 through unsortedPos are sorted

    assert( Sorts<T>::isSorted(arr, size));
}

template <typename T>
bool Sorts<T>::isSorted(T arr[], int size) //adds a new UniNode on top of stack, then moves m_top to new element
{
    for(int i = 0; i < size - 1; i++) //if any term in array is greater than the term to the right of it, array is not sorted
    {
        if(arr[i] > arr[i+1])
        {
            //std::cout << "element: " << i << ": "<<arr[i]<< " is greater than "<<i+1<<": "<< arr[i+1] <<"\n";
            return false;
        }
    }
    //if method reaches this point, there are no cases where a higher value comes before a lower value, so return true
    return true;
}

template <typename T>
void Sorts<T>::shuffle(T arr[], int size, std::default_random_engine& generator) //when given an array, a size, and a random engine, scrambles the array using engine to decide what elements to swap
//for each array element, swaps with another element in a random position in array
{
    //generator already declared as a parameter into method
    std::uniform_int_distribution<int> distribution(0,(size - 1)); //creates a distribution for rng to follow (every value from rng will be between 0 and size -1
    for(int i = 0; i < size; i++) //for every element in the array,
    {
        int placeHolder = arr[i];
        int swapPos = distribution(generator);
        arr[i] = arr[swapPos];
        arr[swapPos] = placeHolder;
        //swaps current element with a random element inside array
    }
}



/*
 * MAKE SURE YOU DELETE THE ARRAY AFTER CALLING THIS METHOD!!!!!!!!
 *
 */

template <typename T>
int* Sorts<T>::createTestArray(int size, int min, int max) //the user passes in a max value, min value, and size for a desired array, and the method returns a "randomly" generated array with criteria
{
    int* intArray = new int[size]; //initialize the array to fill with "random" values
    std::default_random_engine generator(time(nullptr)); //initialize the generator to pull from
    std::uniform_int_distribution<int> distribution(min, max); //initialize the distribution to interpret from
    //int buffer = distribution(generator); //this causes the distribution to ignore the first element, which appears to be fixed with every initialization of the generator and distribution
    //buffer = 5;
    for(int i = 0; i < size; i++) //for each element in array
    {
        //buffer = distribution(generator);
        //int derf = distribution(generator);
        intArray[i] = distribution(generator);
        //intArray[i] = derf*;
    }
    //now array is full of random elements, so return
    return intArray;
}

template <typename T>
double Sorts<T>::sortTimer(std::function<void(T[],int)> sort, T arr[], int size)
{
    std::chrono::system_clock::time_point start; //the presumed start point
    std::chrono::system_clock::time_point end; //the presumed end point
    std::chrono::duration<double> elapsed; //the presumed duration or length of time elapsed

    //start point
    //std::cout << "Beginning timing: \n";
    start = std::chrono::system_clock::now();
    //std::cout << "Starting at " << start.count() << " seconds\n";

    sort(arr,size);

    end = std::chrono::system_clock::now();
    //std::cout << "Ending at " << end.count() << " seconds \n";
    elapsed = (end-start);
    //std::cout << "What you did completed in " << elapsed.count() << " seconds\n";
    return elapsed.count();
}
