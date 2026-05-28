// ----------- Q1 -------------
#include <iostream>
using namespace std;

class Node
{
private:
    string Data;
    int Priority_No;

public:
    Node(string Data = "ABC", int Priority_No = 1)
    {
        this->Data = Data;
        this->Priority_No = Priority_No;
    }
    int get_Priority_No() const { return Priority_No; }
    string get_data() const { return Data; }
    void set_data(string data) { Data = data; }
    void set_priority(int priority) { Priority_No = priority; }
};

class Priority_Queue
{
private:
    int size;
    Node *queue;   // Pointer to store address of Node type array
    int count = 0; // it counts the number of nodes that are added in queue

public:
    Priority_Queue()
    {
        cout << "Enter size of queue:\n> ";
        cin >> size;
        queue = new Node[size];
    }
    ~Priority_Queue()
    {
        delete[] queue;
    }
    void Enqueue(const Node &node)
    {

        if (count >= size)
        {
            cout << "Queue is already full." << endl;
            return;
        }

        int index = 0;

        // Find correct position based on priority
        // (Assuming smaller number = higher priority)
        while (index < count && queue[index].get_Priority_No() <= node.get_Priority_No())
        {
            index++;
        }

        // Shift elements to the right to make space
        for (int i = count - 1; i >= index; i--)
        {
            queue[i + 1] = queue[i];
        }

        // Insert the new node
        queue[index] = node;
        count++;
        cout << node.get_data() << " is added at " << node.get_Priority_No() << " position in queue." << endl;
    }
    void Dequeue()
    {
        if (count == 0)
        {
            cout << "Queue is empty." << endl;
            return;
        }
        else
        {
            string remove = queue[0].get_data();
            for (int i = 1; i < count; i++)
            {
                queue[i - 1] = queue[i];
            }
            count--;
            cout << remove << " is removed from queue." << endl;
        }
    }
    int get_size() { return size; }
    void Display()
    {
        cout << "--- Queue ---" << endl;
        for (int i = 0; i < count; i++)
        {
            cout << i + 1 << ") " << queue[i].get_data() << endl;
        }
    }
};

int main()
{
    Priority_Queue Queue;

    cout << "Give information about queue elements." << endl;
    string data;
    int priority;
    for (int i = 0; i < Queue.get_size(); i++)
    {
        cout << "Enter data (or -1 to exit): ";
        cin >> data;

        if (data == "-1")
            break;

        cout << "Enter priority: ";
        cin >> priority;

        Node temp(data, priority);
        Queue.Enqueue(temp);
    }

    Queue.Display();

    cout << "\n--- Testing Dequeue ---" << endl;
    Queue.Dequeue(); // Remove first element
    Queue.Display(); // Show remaining queue


}

/*
Output:

Enter size of queue:
> 5
Give information about queue elements.
Enter data (or -1 to exit): CS-129
Enter priority: 1
CS-129 is added at 1 position in queue.
Enter data (or -1 to exit): CS-130
Enter priority: 2
CS-130 is added at 2 position in queue.
Enter data (or -1 to exit): CS-131
Enter priority: 3
CS-131 is added at 3 position in queue.
Enter data (or -1 to exit): -1
--- Queue ---
1) CS-129
2) CS-130
3) CS-131

--- Testing Dequeue ---
CS-129 is removed from queue.
--- Queue ---
1) CS-130
2) CS-131

*/
