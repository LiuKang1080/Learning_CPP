// Data / Data Structures

/*
Data Structures:
    - ALL programs work with / deal with data.
    - The 3 biggest components we deal with is: 1) CPU, 2) RAM, and 3) Storage
    - Applications are brought into RAM by the CPU when a user clicks on files or programs. The CPU then follows algorithms to
        perfom the instructions given by the data / executable / program.
    - The organization of data / the arrangement of data is what is known as a Data Structure.
    - Data Structures are formed in memory during the execution of a program.
    - We've worked with data structures before: arrays, vectors, maps, dequeue, queue...(generally all of the containers in C++
        could be considered as data structures.)

Databases:
    - When we're dealing with very large amounts of data / commerical data, we need to organize that data in an efficent way.
    - Generally we store that large amounts of data within a database. The data is organized into related data tables within the
        database.
    - If we have very large amounts of data particularly old data, generally we store that unused data within a Data Warehouse.
        We access that Data Warehouse only when we need to look up old records, or access particular data that we do not use
        frequently.

Physical Data Structures:
    - Generally Arrays and Linked Lists are considered "physical data structures", they define how the memory is allocated, and
        how the data within them are set. Generally Physical Data Structures are meant to hold the data.
    
    - Arrays: A data strucutre that has a fixed size of elements in contiguous memory. Can be created on the stack or on the
        heap. We use the array when we're sure about the maximum size of the data we're dealing with.
    
    - Linked Lists: A dynamic data structure, a collection of nodes in which it contains a value, and a pointer that points to
        the next nodes. Linked Lists are always created on the Heap. The Head pointer may be on the stack, but the rest of the
        linked list is on the heap.

Logical Data Structures:
    - Generally Stack, Queues, Trees, Graphs, and Hash Tables are considered as "logical data structures". Generally Physical
        Data Structures are meant to hold the data.
    - Generally we will perform operations on the physical data structures, HOW we will perform those actions are defined by the
        logical data structures.
    
    - Stacks and Queues: Are considered Linear Data Structures.
    - Trees and Graphs: Are considered Non-Linear Data Structures.
    - Hash Tables: Maybe considered Linear, but generally considered a Tabular Data Structure.

    - To implement the Logical Data Structures we choose either Physical Data Structure. The logical data structure is IMPLEMENTED
        by using one of the physical data structure: either Array, Linked List, or a combination of both.

Abstract Data Types (ADTs):
    - There are 2 parts of a Data Type: 1) The Representation of data, and 2) The Operations performed on the data.
    - The Representation means the behaviour of the data itself. How much memory does it take up? How "big" is it? 
        int / float / double ...
    - The Operations on the data means: What can we do do the data. Ex) We have an int: +, -. *, /, ++, --, <, >, <=, >=, !=, ==.
*/


#include <iostream>


int main() {

    return 0;
}
