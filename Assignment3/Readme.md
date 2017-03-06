# Program Description

Part 1:
(i)  I had to define the functions insert_after , insert_before, delete_after, and delete_before for a simple doubly linked list class. The simply doubly linked list class helps us understand how the nodes work and how to insert them into a list. 
(ii)For Double Linked List class I had to define the copy constructor, overload the assignment operator(=) and the output operator (<<). This helped me iterate through the Doubly Linked List class using header and trailer. 
(iii) In TemplateDoublyLinkedList class I had to create a template for more generic programming. Later I realized that we are going to create DoublyLinkedList of Records.
Part 2:
 I used the above defined classes to implement a phone book of students which stores the last name, first name, 9-digit UIN, and phone number of each student. The phonebook had to be read in from a text file and sorted orderly alphabetically. Also, a search function is created for the user search for a student’s records.
Purpose of the Assignment
The purpose of this programming assignment is to learn about data structures and algorithms. Implementing these functions provided a deeper understanding of templates and the functionality of double linked lists. I learned how double linked lists works with its nodes through the help of the header and the trailer. 

# Data Structures Description 
The main data structure in this assignment is the double linked list. 
For Part 1:A double linked list contains a header which helps us identify the front and a trailer for the back of the list. Every element in the list contains an object and two pointers, previous and next, that point to the previous element and next element respectively. To add or remove the objects of the list we could do it using the pointers as the elements in the list could not be accessed using an index.
For Part 2: I created a class called Records which stored a student’s last name, first name, UIN, and phone number. Then I created a vector of 26 Lists having the nodes as Record that saved the Names Alphabetically.

# Algorithm Description
where n is the size of the list.
1. insert_before(d) – inserts d before this node -  Big O(1)
A new node is created with a "previous" pointer to the previous node, and a "next pointer to the current node. the previous node's "next" pointer is assigned to the created node and the current node's "previous" pointer is assigned to the created node.
2. insert_after(d) – inserts d after this node -  Big O(1)
A new node is created with a "previous" pointer to the current node, and a "next pointer to the next node. the current node's "next" pointer is assigned to the created node and the next node's "previous" pointer is assigned to the created node.
3. delete_before() – deletes the node before this node -  Big O(1)
The function first checks if a previous node exists. The second previous node's "next" pointer is assigned to the current node, the previous node is deleted, and the current node's "previous" pointer is assigned to the previous node's "previous" pointer
4.delete_after()– deletes the node after this node -  Big O(1)
The function first checks if a next node exists. The second next node's "previous" pointer is assigned to the current node, the next node is deleted, and the current node's "next" pointer is assigned to the next node's "next" pointer.
5. copy constructor – copies the doubly linked list – Big O(n)
Creates a pointer to iterate through the argument that use "insertlast" to add them to the newly constructed DLL.
6. assignment operator – assigns the same values as the doubly linked list – Big O(n)
Creates a pointer to iterate through the argument that use "insertlast" to add them to the newly constructed DLL.
7. output operator – prints the list to the screen – Big O(n)
Checks to see if the DLL is empty, if it isn't it creates a pointer to iterate through the DLL, outputting each element as it does so.
8.less-than operator – compares two Records and is true if the Record on the left is smaller alphabetically – Big O(1)
9.insertOrderly – inserts an object to the correct position if the linked list is sorted– Big O(n)

# Program Organization and Description of Classes
I used a Template Doubly Linked List class and it is a friend class of the DListNode class. 
I created a Record class which stored student info. In the main function, I used a Doubly Linked List of Records.
Instructions to Compile and Run your Program
Compile the Simple Doubly Linked List with make and run it with ./SimpleDoublyLinkedList
Compile the Doubly Linked List with make and run it with ./Main
Compile the Template Doubly Linked List with make and run it with ./TemplateMain
Compile the phonebook with g++ -std=c++11 -o Main *.cpp and run it with ./Main
To run them use: ./a.out
Input and Output Specifications  Text files with the format as the give text file are required. Record tabs the first name and uses each element on a new line. When the last name is inputed and it matches, all the details are displayed. If not then first name and if not then the uin are inputed into the program, and simply the details are displayed.

# Logical Exceptions
When I display the phonebook I was not able to get the blanked lists to disappear which instead printed blank lines.
C++ object oriented or generic programming features 
The Doubly Linked List Class is a friend class to the DListNode class which means Doubly Linked List can access the private and protected members of DListNode. I made a Generic Doubly Linked List using Template so that it can store any desired type into the list.
Tests

# How the Program runs:

Enter the name of the textfile you want to read.
PhoneBook.txt
Raw File:
The phoneBook has the following contents:
Last name - First Name: Andrews-Edna
UIN:528320876
ph_no:4352514822

Last name - First Name: Arenas-Edward
UIN:239924731
ph_no:2525976612
