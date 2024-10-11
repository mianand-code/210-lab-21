// COMSC-210 | Lab 21 | Mira Anand
// Module 7, Lesson: Doubly-Linked Lists & Class Destructors, Assignment: Goat Herd Manager 3000
// IDE used: Visual Studio Code for Mac

// Removing insert_after() and delete_node() functions from the DoublyLinkedClass since they do not apply to assignment instructions
// The purpose of this assignment is to exercise the Goat class in conjunction with the DoublyLinkedList class
// We do this by adding Goat objects to a linked list, which requires the use of the push_back() function that is a part of the DoublyLinkedList class
// Our main() function exercises the default constructor of the Goat class in conjunction with the push_back(), print(), and print_reverse() functions of the DoublyLinkedList class
// We could also exercise our full parameter constructor and setters/getters from the Goat class in main() as well
// - Including these in our Goat class is beneficial because it makes our class fully functional and able to stand on its own

#include <cstdlib> // needed to generate a random number
#include <ctime> // needed to generate a random number
#include <iostream>
#include <string>
using namespace std;

// declaration and initialization of const int variables
// range of Goat objects to be created should be within between 5 - 20
// range of age to be assigned to a Goat object should be between 1 - 20
const int SIZE = 15; // represents array size (names, colors)
const int MIN_OBJECT = 5; // represents the minimum # of Goat objects to be created, will be used to generate a random # in main()
const int MAX_OBJECT = 20; // represents the maximum # of Goat objects to be created, will be used to generate a random # in main()
const int AGE_MAX = 20; // represents the maximum age to be assigned to a Goat object, will be used to generate a random #

// creation of Goat Class
class Goat {
// private member variables
private:
    int age; // to hold goat's age
    string name; // to hold goat's name
    string color; // to hold color of goat

    // creation and initialization of a 15-element string array that holds a list of names, names were randomly generated
    string names[SIZE] = {"Billy", "Nanny", "Daisy", "Ginger", "Coco", 
                        "Luna", "Misty", "Shadow", "Pepper", "Max", 
                        "Fluffy", "Snowy", "Bella", "Rocky", "Duke"};
    // creation and initialization of a 15-element string array that holds a list of colors, colors were randomly generated
    string colors[SIZE] = {"Black", "White", "Brown", "Gray", "Gold", 
                        "Red", "Blue", "Yellow", "Pink", "Purple", 
                        "Green", "Mauve", "Teal", "Orange", "Tan"};

// public member functions
public:
    // creation of a default constructor, Goat()
    // DESCRIPTION: initializes age, name, and color to random values/selections
    // name and color of goat will be randomly selected from "names" and "colors" arrays
    // ARGUMENTS: no arguments/parameters
    // RETURNS: no return type
    Goat()
    {
        age = rand() % AGE_MAX + 1; // random assignment of a age between 1 - 20
        // random selection of a name within the "names" array and assignment to "name"
        // rand() % SIZE will pick an element from the array within the range 0 - 14
        // this is accurate because arrays start at index 0
        name = names[rand() % SIZE]; 
        color = colors[rand() % SIZE]; // random selection of a color within the "colors" array and assignment to "color"
    }

    // creation of a full parameter constructor, Goat(int a, string n, string c)
    // inline because it is 1 line only
    // DESCRIPTION: initializes age, name, and color all by parameter
    // ARGUMENTS: int a, represents the goat's age
    // - string n, represents the goat's name
    // - string c, represents the color of the goat
    // RETURNS: no return type
    Goat(int a, string n, string c)     { age = a; name = n; color = c; }

    // creating all setters together, to keep it organized
    // void setAge(int a), void setName(string n), void setColor(string c) function header
    // DESCRIPTION: these functions will "set" the age, name, and color for each Goat object
    // ARGUMENTS: int a, represents the goat's age
    // - string n, represents the goat's name
    // - string c, represents the color of the goat
    // RETURNS: nothing, void functions
    void setAge(int a)                  { age = a; }
    void setName(string n)              { name = n; }
    void setColor(string c)             { color = c; }

    // creating all getters together, to keep it organized
    // int getAge() const, string getName() const, string getColor() const function header
    // DESCRIPTION: these functions will "get" the age, name, and color values for each Goat object
    // ARGUMENTS: no arguments/parameters
    // RETURNS: the int value for age
    // - the string value for name
    // - the string value for color
    // adding a trailing const to each, since getters do not change an object's data
    int getAge() const                  { return age; }
    string getName() const              { return name; }
    string getColor() const             { return color; }

    // creating a member print() method to print the object's data
    // void print() function header
    // DESCRIPTION: this function outputs the age, name, and color for each Goat object
    // ARGUMENTS: no arguments/parameters
    // RETURNS: nothing, void function
    void print()
    {
        cout << "GOAT:" << endl;
        cout << "Age: " << age << ", ";
        cout << "Name: " << name << ", ";
        cout << "Color: " << color << endl;
        cout << endl;
    }
};

// creation of DoublyLinkedList class
class DoublyLinkedList {
// private member variables
private:
    struct Node 
    {
        Goat data; // modifying from int to "Goat" object
        Node* prev;
        Node* next;
        Node(Goat info, Node* p = nullptr, Node* n = nullptr) // modifying constructor from int parameter to "Goat" object parameter
        {
            data = info;
            prev = p;
            next = n;
        }
    };
    
    Node* head;
    Node* tail;

public:
    // constructor
    DoublyLinkedList() { head = nullptr; tail = nullptr; }

    void push_back(Goat info) // modifying from int parameter to "Goat" object parameter
    {
        Node* newNode = new Node(info);
        if (!tail) // if there's no tail, the list is empty
            head = tail = newNode;
        else 
        {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
    }

    void push_front(Goat info) // modifying from int parameter to "Goat" object parameter
    {
        Node* newNode = new Node(info);
        if (!head) // if there's no head, the list is empty
            head = tail = newNode;
        else 
        {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
    }

    void print() 
    {
        Node* current = head;
        if (!current) // modifying to display "List is empty" if current is equal to nullptr
        {
            cout << "List is empty." << endl;
            return; // exit function
        }

        while (current) 
        {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }

    void print_reverse() 
    {
        Node* current = tail;
        if (!current) // modifying to display "List is empty" if current is equal to nullptr
        {
            cout << "List is empty." << endl;
            return; // exit function
        }

        while (current) 
        {
            cout << current->data << " ";
            current = current->prev;
        }
        cout << endl;
    }

    ~DoublyLinkedList() 
    {
        while (head) 
        {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
    }
};

// Driver program
int main() 
{
    srand(time(0)); // needed as the first line in main() to generate random numbers
    
    DoublyLinkedList list; // creation of a DoublyLinkedList object

    // declaration and initialization of a int variable "size", that will generate a random # between 5 - 20
    // this random value will be the number of Goat objects created
    int size = rand() % (MAX_OBJECT-MIN_OBJECT+1) + MIN_OBJECT; 

    for (int i = 0; i < size; ++i)
        list.push_back(rand() % (MAX_NR-MIN_NR+1) + MIN_NR);
    
    cout << "List forward: ";
    list.print();

    cout << "List backward: ";
    list.print_reverse();

    cout << "Deleting list, then trying to print.\n";
    list.~DoublyLinkedList();
    cout << "List forward: ";
    list.print();

    return 0;
}