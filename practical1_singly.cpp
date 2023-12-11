#include <iostream>
using namespace std;
class Node
{
public:
    int data;
    Node *next;
    Node(int val)
    {
        this->data = val;
        this->next = nullptr;
    }
};
class LinkedList
{
private:
    Node *head;
    Node *tail;

public:
    LinkedList()
    {
        this->head = nullptr;
        this->tail = nullptr;
    }
    ~LinkedList()
    {
        Node *current = head;
        Node *nextNode;

        while (current != nullptr)
        {
            nextNode = current->next;
            delete current;
            current = nextNode;
        }

        head = nullptr;
        tail = nullptr;
    }
    void insert_head(int d)
    {
        Node *temp = new Node(d);
        if (head == nullptr)
        {
            head = temp;
            tail = temp;
            return;
        }
        else
        {
            temp->next = head;
            head = temp;
        }
    }
    void insert_tail(int d)
    {
        Node *temp = new Node(d);
        if (tail == nullptr)
        {
            head = temp;
            tail = temp;
            return;
        }
        else
        {
            tail->next = temp;
            tail = temp;
        }
    }
    void insert_position(int d, int pos)
    {
        if (pos == 1)
        {
            insert_head(d);
            return;
        }
        Node *temp = head;
        int count = 1;
        while (count < pos - 1)
        {
            temp = temp->next;
            count++;
        }
        Node *newnode = new Node(d);
        newnode->next = temp->next;
        temp->next = newnode;
        if (temp->next == nullptr)
        {
            insert_tail(d);
            return;
        }
    }
    void deletion_by_position(int pos)
    {
        if (pos == 1)
        {
            Node *temp = head;
            head = head->next;
            temp->next = nullptr;
            delete temp;
        }
        else
        {
            Node *current = head;
            Node *prev = nullptr;
            int count = 1;
            while (count < pos)
            {
                prev = current;
                current = current->next;
                count++;
            }
            prev->next = current->next;
            current->next = nullptr;
            delete current;
        }
    }
    void delete_beginning()
    {
        if (head == nullptr)
        {
            cout << "List is empty. Cannot remove from beginning.\n";
            return;
        }
        Node *temp = head;
        head = head->next;
        delete temp;
    }
    Node *search(int d)
    {
        Node *current = head;
        while (current != nullptr)
        {
            if (current->data == d)
            {
                return current;
            }
            current = current->next;
        }
        return nullptr;
    }
    void print()
    {
        if (head == nullptr)
        {
            cout << "List is empty" << endl;
            return;
        }
        Node *temp = head;
        while (temp != nullptr)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};
int main()
{
    LinkedList list;
    int choice, value, position;
    Node* searchResult = nullptr;

    do
    {
        cout << "\n------ Menu ------" << endl;
        cout << "1. Insert at beignning" << endl;
        cout << "2. Insert at ith Position" << endl;
        cout << "3. Delete element from beginning" << endl;
        cout << "4. Delete from  ith position" << endl;
        cout << "5. Search element in element: " << endl;
        cout << "6. Print List" << endl;
        cout << "7. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            cout << "Enter value to insert at the head: ";
            cin >> value;
            list.insert_head(value);
            break;

        case 2:
            cout << "Enter value to insert: ";
            cin >> value;
            cout << "Enter ith position to insert: ";
            cin >> position;
            list.insert_position(value, position);
            break;

        case 3:
            list.delete_beginning();
            break;

        case 4:
            cout << "Enter the ith position to delete: ";
            cin >> position;
            list.deletion_by_position(position);
            break;
        case 5:
        cout << "Enter value to search: ";
        cin >> value;
        searchResult = list.search(value);
        if (searchResult != nullptr) {
            cout << "Value " << value << " found in the list at address: " << searchResult << endl;
        } else {
            cout << "Value " << value << " not found in the list." << endl;
        }
        break;
        case 6:
            cout << "Linked List: ";
            list.print();
            break;
        case 7:
            cout << "Exiting the program." << endl;
            break;
        default:
            cout << "Invalid choice. Please enter a valid option." << endl;
        }

    } while (choice != 7);

    return 0;
}