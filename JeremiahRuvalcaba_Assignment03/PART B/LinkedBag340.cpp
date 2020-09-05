//	LinkedBag340.cpp
//	Created by: CSC340
#include <cstddef>
#include "LinkedBag.h"
#include <cstdlib>	
/*
===>					<===
===>  PLEASE ADD CODE	<===
===>					<===
*/

template<typename ItemType>
bool LinkedBag<ItemType>::removeSecondNode340()
{
    Node<ItemType>* removeSecondNode340Ptr = headPtr;
    removeSecondNode340Ptr = headPtr->getNext();
    remove(removeSecondNode340Ptr->getItem());
    return true;
}

template<typename ItemType>
bool LinkedBag<ItemType>::addEnd340(const ItemType& newNode)
{
    Node<ItemType>* ptr = headPtr;
    while (ptr->getNext() != nullptr) {
        ptr = ptr->getNext();
    }

    Node<ItemType>* nextNodePtr = new Node<ItemType>();
    nextNodePtr->setItem(newNode);
    ptr->setNext(nextNodePtr);
    itemCount++;
    return true;
}

template<typename ItemType>
int LinkedBag<ItemType>::getCurrentSize340Iterative() const
{
    Node<ItemType>* ptr = headPtr;
    while (ptr != nullptr)
    {
        ptr = ptr->getNext();
    }
    return getCurrentSize();
}
    
template<typename ItemType>
int LinkedBag<ItemType>::getCurrentSize340Recursive() const
{
    static Node<ItemType>* ptr = headPtr;
 
    while (ptr != nullptr)
    {
        ptr = ptr->getNext();
    }

    return (getCurrentSize340RecursiveHelper(ptr)); 

    }

template<typename ItemType>
int LinkedBag<ItemType>::getCurrentSize340RecursiveHelper(Node<ItemType>*) const
    {
        return itemCount; 
    }



template<typename ItemType>
int LinkedBag<ItemType>::getCurrentSize340RecursiveNoHelper() const
{
    static Node<ItemType>* ptr = headPtr;
    int counter = 0;
    if (ptr == nullptr) {
        return counter;
    } else {
        ptr = ptr->getNext();
        counter++;
    }
    return  counter + getCurrentSize340RecursiveNoHelper();
    
}
   

template<typename ItemType>
int LinkedBag<ItemType>::getFrequencyOf340Recursive(const ItemType& anEntry) const
{
    static Node<ItemType>* ptr = headPtr;
    while (ptr != nullptr)
    {
        ptr = ptr->getNext();
    }
    return getFrequencyOf340RecursiveHelper(ptr, anEntry);
}

template<typename ItemType>
int LinkedBag<ItemType>::getFrequencyOf340RecursiveHelper(Node<ItemType>* ptr, const ItemType& anEntry) const
{
    return getFrequencyOf(anEntry);
}


template<typename ItemType>
int LinkedBag<ItemType>::getFrequencyOf340RecursiveNoHelper(const ItemType& anEntry) const
{
    static Node<ItemType>* ptr = headPtr;

    if (ptr->getNext() == nullptr) {
        ptr = headPtr;
        return 1;

    }
    else if (ptr->getItem() == anEntry) {
        ptr = ptr->getNext();
        return 1 + getFrequencyOf340RecursiveNoHelper(anEntry);
    }
    else {
        ptr = ptr->getNext();
        return 0 + getFrequencyOf340RecursiveNoHelper(anEntry);
    }

}
    
    
    
template<typename ItemType>
ItemType LinkedBag<ItemType>::removeRandom340()
{
    ItemType removeRandom{};
    Node<ItemType>* ptr = headPtr;

    int random = rand() % getCurrentSize() + 1;

    for (int i = 0; i < random; i++) {
        ptr = ptr->getNext();
    }
   
    remove(ptr->getItem());
    return removeRandom;

} // end removeRandom340()

