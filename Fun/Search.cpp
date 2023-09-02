#include "Search.h"

int main() {
    myVector<string> nameList;

    nameList.push_back("Alice");
    nameList.push_back("Bob");
    nameList.push_back("Charlie");

    // Bubble Sortting
    cout << "Before Bubble Sort: ";
    for (const auto& name : nameList)
    {
        cout << name << " ";
    }
    cout << endl;

    nameList.bubbleSort();
    cout << "After Bubble Sort: ";
    for (const auto& name : nameList)
    {
        cout << name << ", ";
    }
    cout << endl;

    //Search method
    int foundIndex = nameList.binarySearch("Bob");
    cout << "Binary Search for Bob: " << foundIndex << endl;


    cout << "Sorted Vector: ";
    for (const auto& name : nameList)
    {
        cout << name << ", ";
    }
    cout << endl;

    myVector<int> numList;

    numList.push_back(2);
    numList.push_back(1);
    numList.push_back(6);

    // Test the STL sort method
    sort(numList.begin(), numList.end());

    // Binary search
    if (binary_search(numList.begin(), numList.end(), 3)) 
    {
        std::cout << "Yes, 3 exists\n";
    }
    else
    {
        std::cout << "No, 3 doesn't exist\n";
    }

    //Sequence searching
    int sequenceFind = nameList.seqSearch("Bob");
    if (sequenceFind != -1) 
    {
        cout << "Bob found at " << sequenceFind << endl;
    }
    else
    {
        cout << "Bob not found" << endl;
    }

    // Print the resulting vector(s) using an iterator
    cout << "Sorted Numbers: ";
    for (auto it = numList.begin(); it != numList.end(); ++it)
    {
        cout << *it << " ";
    }

    return 0;
}