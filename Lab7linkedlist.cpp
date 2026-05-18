/*
Name: <Christina Barefoot> NetID: <ceb1003>
Date: <4/1/25> Due Date: <4/7/25>
Description: <Double Linked Lists>
*/


#include "linkedlist.h"
using namespace std;

LinkedList::LinkedList()
{
    head = nullptr;
    tail = nullptr;
    size = 0;
}

LinkedList::~LinkedList()
{
    if(size > 0)
    {
        Node *temp; 
        while(head != nullptr)
        {
            // grabs the node after the head
            temp = head->next;

            // deletes the head
            delete head;

            // reassigns the head
            head = temp;
        }
    }
}

// given to students
void LinkedList::display()
{
    // error check:
    // checks if the current size is zero
    if(size == 0)
    {
        cout << "List was empty -- display failed!" << endl;
    }

    // starts temporary Node at the beginning (head)
    Node *temp = head;

    for(int i = 0; i < size; i++)
    {
        // displays information
        cout << i << ": " << temp->number << endl;

        // moves the temp node to the next node in the sequence
        temp = temp->next;
    }
}

void LinkedList::reverseDisplay()
{
    // error check:
    // checks if the current size is zero
    if(size == 0)
    {
        cout << "List was empty -- display failed!" << endl;
    }

    // starts temporary Node at the end (tail)
    Node *temp = tail;

    for(int i = (size - 1); i >= 0; i--)
    {
        // displays information
        cout << i << ": " << temp->number << endl;

        // moves the temp node to the previous node in the sequence
        temp = temp->prev;
    }
}

void LinkedList::append(int number)
{
    // if the list is currently empty
    if(size == 0)
    {
        // create a new node at the head
        // with the information brought in
        head = new Node(number);

        // assigns tail to the head
        tail = head;
    }

    // otherwise, if it's not empty
    else
    {
        // creates a new node
        // with the information brought in
        // points the prev pointer to the tail
        Node *temp = new Node(number, tail, nullptr);

        // point current tail to new node
        tail->next = temp;

        // make new node the new tail
        tail = temp;
    }

    size++;
}

void LinkedList::pop()
{
    // error check:
    // checks if the current size is zero
    if(size == 0)
    {
        cout << "List was empty -- pop failed!" << endl;
        return;
    }

    // if removing a node will empty the list
    if(size == 1)
    {
        // store current head
        Node *temp = head;

        // sanity check clear head and tail
        head = nullptr;
        tail = nullptr;

        // delete node
        delete temp;
    }

    // otherwise, if it won't empty the list...
    else
    {
        // grab the node before the tail
        Node *temp = tail->prev;

        // delete the current tail
        delete tail;

        // sanity check clear the next pointer
        // and assign the new tail
        tail = temp;
        tail->next = nullptr;
    }

    size--;
}

// **********************************************************************
// you must create

void LinkedList::insert(int number, int position)
{
    
    if (position < 0 || position > size)  // making sure the position is in the list and is not bigger or smaller than size
    {

        cout << "Not a valid insert -- out of range!";
        return;

    }
    else
    {
        Node* temp = new Node(number); // creating new node to add number 
        if (position == 0) // 0 position is head so inserting to the head
        {
            temp->next = head; // sets pointer temp to next node and making that the head
            if (size == 0) // checking if it is the tail
            {
                tail = temp; //setting tail to node
            }
            else
            {
                head->prev = temp; // og head's previous pointer to new node         
                
            }
            head = temp; // new node as head
        }
        else
        {
            Node* current = head; // for middle & end of list
            for (int i = 1; i < position; i++) // iterates through the list to find correct position
            {
                current = current->next; // setting current to next node after current
            }
            temp->next = current->next;  // Linking the node to the next node
            temp->prev = current;   // Linking the before node to the newest node

            if (current->next)
            {
                current->next->prev = temp;// next node's previous pointer is assigned
            }

            current->next = temp;// links the nodes

            if (temp->next == nullptr) 
            {
                tail = temp; // update tail
            }

        }
        size++;
    }

}

void LinkedList::remove(int position)
{

    if (position < 0 || position > size)   // making sure the position is in the list and is not bigger or smaller than size
    {

        cout << "Not a valid insert -- out of range!";
        return;
    }

    Node* removeN; // the node that will be removed/deleted

    if (position == 0)
    {
        removeN = head; // this will remove the node's head
        head = head->next;  // move the head pointer to the next node

        if (head)
        {
            head->prev = nullptr; // makes sure the head has no previous node
        }
        if (removeN == tail)
        {
            tail = nullptr; // fixes tail if it was only 1 deleted node in the list
        }
    }
    else
    {
        Node* current = head; // for middle or end of list

        for (int i = 1; i < position; i++)  // iterating through the list
        {
            current = current->next; // setting current to next node after current
        }

        removeN = current->next; // removing the node that needs to be removed
        current->next = removeN->next; // skipping to next next node
        if (removeN->next) 
        {
            removeN->next->prev = current; //update next node prev pointer
        }
        if (removeN == tail)
        {
            tail = current; // fixes tail
        }
    }
    delete removeN; // deallocated / deletes node
    size--;
}

void LinkedList::removeValue(int number)
{
    int count = 0; // creating count variable to check if the value is even in the list and how many times it is
    Node* current = head;  // start at the head

    
    while (current) // check if the head node even has a value
    {
        if (current->number == number) // check if the value is the picked value
        {
            Node* deleteN = current; // save the abt to be deleted node
            current = current->next; // moves to the next lab

            if (deleteN == head)
            {
                head = deleteN->next; // updates the head

                if (head)
                {
                    head->prev = nullptr; // set new head nullpointer

                }
            }
            
            if (deleteN == tail)
            {
                tail = deleteN->prev; // updates the tail

                if (tail)
                {
                    tail->next = nullptr; //  set new tail nullpointer
                }
            }

            if (deleteN->prev)
            {
                deleteN->prev->next = deleteN->next; // fixes previous pointer
            }

            if (deleteN->next)
            {
                deleteN->next->prev = deleteN->prev; // fixes previous pointer
            }
            
            delete deleteN;  // deletes the node
            size--;  // decrease size
            count++;  // add to the count
        }
        else
        {
            current = current->next;  // move to the next node
        }
    }

    if (count == 0)
    {
        cout << "The value is not present in this list" << endl; 
    }
}

// **********************************************************************