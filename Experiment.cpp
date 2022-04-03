/*In the situation where are multiple users on a network system, you probably share a printer with other users... When you request to print a file, your,
request is added to the print queue. When your request reaches to the front of the print queue, your file is printed... This ensures that only one person
at a time has access to the printer and given on a first-come, first-serve basis... Design an algorithm for this scenario and Implement it in any 
language...*/
#include <iostream>
using namespace std;
class Node                  // Node class for creating the Node data type for Queue Data Structure
{
    public:       // Data Members created
    int data;
    Node* next;
    public:
    Node (int value)     // Parametrized Constructor
    {
        data = value; next = NULL;
    }
};
class Queues     // Queue class for Implementing Queue Data Structure in printing Operations
{
    public:
    Node* front;     // Front pointer reference created
    Node* back;      // Back pointer reference created
    public:
    Queues ()     // Default Constructor
    {
        front = NULL;
        back = NULL;
    }
    public:
    void Enqueue(int value)    // Enqueuing the Node in the Queue, done by the back pointer
    {
        Node* n = new Node(value);    // New Node creation
        cout << "Request Added in the Queue, You will be dealt shortly !!" << endl;
        if(front == NULL)    // If the Queue is empty
        {
            front = back = n;    // Front and Back pointers will point to the same Node
            return;
        }
        back -> next = n;   // The next of Back pointer is appended
        back = n;           // The New Node becomes the back of thw Queue
    }
    public:
    void Dequeue()    // Dequeuing the Node from the Queue, done by the Front pointer
    {
        Node* temp = front;   // Temporary Node pointer created
        if(front == NULL)
        {        // If Queue is empty then nothing can be Dequeued from the Queue
            cout << "Queue Underflow !!" << endl;
            return;
        }
        cout << "The first request is processed, it will be removed from the Queue !!" << endl;
        front = temp -> next;   // Front moves to the net succeeding Node
        delete temp;
    }
    public:
    void DisplayQueue()    // Displaying the Queue by means of Traversal
    {
        Node* temp = front;
        cout << " (Front) ";
        for(;temp != NULL; temp = temp -> next)   // While Traversing
        {
            if(temp -> next == NULL)
                cout << temp -> data;
            else
                cout << temp -> data << " ---> ";
        }
        cout << " (Back) " << endl;
    }
};
int main()    // main method begins
{
    Queues queue;        // Object creation of Queue class
    string str = "";
    string st1 = "";
    int i = 1;
    do             // do-while loop
    {
        cout << "Do you want to print ?? (Y/N) : ";
        cin >> st1;
        if(st1 == "Y" || st1 == "y")
        {
            queue.Enqueue(i);   // Calling Enqueue function
            i++;
            queue.DisplayQueue();
        }
        cout << "Is your work done ?? You will be Dequeued (Y/N) : ";
        cin >> st1;
        if(st1 == "Y" || st1 == "y")
        {
            queue.Dequeue();          // Calling Dequeue function
            queue.DisplayQueue();
        }
        cout << " ======================================================== "<< endl;
        cout << "Do you want to shut down the Printer ?? (Y/N) : ";
        cout << " ======================================================== " << endl;
        cin >> str;
    }while(str == "No" || str == "NO" || str == "N" || str == "n" || str == "no");   // Termination condition
    return 0;    // End of the Program
}