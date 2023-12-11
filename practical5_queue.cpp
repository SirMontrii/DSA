#include<iostream>
using namespace std;

class Queue {
    int* arr;
    int qfront;
    int rear; 
    int size;
    
public:
    Queue() {
        size = 100001;
        arr = new int[size];
        qfront = 0;
        rear = 0;
    }

    bool isEmpty() {
        return (qfront == rear);
    }

    void enqueue(int data) {
        if (rear == size)
            cout << "Queue is Full" << endl;
        else {
            arr[rear] = data;
            rear++;
        }
    }

    int dequeue() {
        if (qfront == rear) {
            return -1;
        }
        else {
            int ans = arr[qfront];
            arr[qfront] = -1;
            qfront++;
            if (qfront == rear) {
                qfront = 0;
                rear = 0;
            }
            return ans;
        }
    }

    int front() {
        if (qfront == rear) {
            return -1;
        }
        else {
            return arr[qfront];
        }
    }

    void display() {
        if (isEmpty()) {
            cout << "Queue is empty\n";
        }
        else {
            cout << "Queue elements: ";
            for (int i = qfront; i < rear; ++i) {
                cout << arr[i] << " ";
            }
            cout << endl;
        }
    }
};

int main() {
    Queue q;
    int choice;

    do {
        cout << "\nMenu"<<endl;
        cout << "1. Enqueue"<<endl;
        cout << "2. Dequeue"<<endl;
        cout << "3. Front"<<endl;
        cout << "4. Check if the queue is empty"<<endl;
        cout << "5. Display "<<endl;
        cout << "6. Exit"<<endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                int data;
                cout << "Enter data to enqueue: ";
                cin >> data;
                q.enqueue(data);
                break;
            }
            case 2: {
                int dequeued = q.dequeue();
                if (dequeued == -1)
                    cout << "Queue is empty"<<endl;
                else
                    cout << "Dequeued element: " << dequeued << endl;
                break;
            }
            case 3: {
                int frontElement = q.front();
                if (frontElement == -1)
                    cout << "Queue is empty"<<endl;
                else
                    cout << "Front element: " << frontElement << endl;
                break;
            }
            case 4: {
                if (q.isEmpty())
                    cout << "Queue is empty"<<endl;
                else
                    cout << "Queue is not empty"<<endl;
                break;
            }
            case 5: {
                q.display();
                break;
            }
            case 6: {
                cout << "Exiting the program"<<endl;
                break;
            }
            default:
                cout << "Invalid choice, please try again"<<endl;
        }

    } while (choice != 6);

    return 0;
}
