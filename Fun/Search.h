#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std; 

template <class T>
class myVector : public vector<T>
{
    private:
        static bool isSorted;

    public:
        int seqSearch(T searchItem);
        int binarySearch(T searchItem);
        void bubbleSort();
        void insertionSort();
};

template <class T>
bool myVector<T>::isSorted = false;

template <class T>
int myVector<T>::seqSearch(T searchItem) 
{
    for (int i = 0; i < this->size(); ++i) 
    {
        if (this->at(i) == searchItem)
        {
            return i;
        }
    }
    return -1;
}

template <class T>
void myVector<T>::bubbleSort() 
{
    for (int i = 0; i < this->size() - 1; ++i) 
    {
        for (int j = 0; j < this->size() - i - 1; ++j) 
        {
            if (this->at(j) > this->at(j + 1))
            {
                swap(this->at(j), this->at(j + 1));
            }
        }
    }
    isSorted = true;
}

template <class T>
void myVector<T>::insertionSort() 
{
    for (int currentIndex = 1; currentIndex < this->size(); ++currentIndex) 
    {
        T key = this->at(currentIndex);
        int previousIndex = currentIndex - 1;
        while (previousIndex >= 0 && this->at(previousIndex) > key) 
        {
            this->at(previousIndex + 1) = this->at(previousIndex);
            previousIndex--;
        }
        this->at(previousIndex + 1) = key;
    }
    isSorted = true;
}

template <class T>
int myVector<T>::binarySearch(T searchItem) 
{
    if (!isSorted) 
    {
        bubbleSort();
    }
    int leftIndex = 0, rightIndex = this->size() - 1;
    while (leftIndex <= rightIndex) 
    {
        int middleIndex = leftIndex + (rightIndex - leftIndex) / 2;
        if (this->at(middleIndex) == searchItem)
        {
            return middleIndex;
        }
        if (this->at(middleIndex) < searchItem)
        {
            leftIndex = middleIndex + 1;
        }
        else
        {
            rightIndex = middleIndex - 1;
        }
    }
    return -1;
}



