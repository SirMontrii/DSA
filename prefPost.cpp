#include <iostream>
#include <cstring>  
using namespace std;

class Stack {
private:
    int* data;
    int capacity;
    int top;

public:
    Stack(int size) {
        capacity = size;
        data = new int[capacity];
        top = -1;
    }

    ~Stack() {
        delete[] data;
    }

    void push(int value) {
        if (top == capacity - 1) {
            cout << "Stack Overflow" << endl;
        } else {
            top++;
            data[top] = value;
        }
    }

    int pop() {
        if (top == -1) {
            cout << "Stack Underflow" << endl;
            return -1;
        } else {
            int value = data[top];
            top--;
            return value;
        }
    }

    int peek() {
        if (top == -1) {
            cout << "Stack is Empty" << endl;
            return -1;
        } else {
            return data[top];
        }
    }

    bool isEmpty() {
        return top == -1;
    }

    bool isFull() {
        return top == capacity - 1;
    }
};

int eval_prefix(const char* exp) {
    Stack stack(strlen(exp));
    int len = strlen(exp);

    for (int i = len - 1; i >= 0; i--) {
        if (isdigit(exp[i])) {
            stack.push(exp[i] - '0');
        } else {
            int oprnd1 = stack.pop();
            int oprnd2 = stack.pop();
            switch (exp[i]) {
                case '+':
                    stack.push(oprnd1 + oprnd2);
                    break;
                case '-':
                    stack.push(oprnd1 - oprnd2);
                    break;
                case '*':
                    stack.push(oprnd1 * oprnd2);
                    break;
                case '/':
                    stack.push(oprnd1 / oprnd2);
                    break;
            }
        }
    }

    return stack.pop();
}

int eval_postfix(const char* exp) {
    Stack stack(strlen(exp));
    int len = strlen(exp);

    for (int i = 0; i < len; i++) {
        if (isdigit(exp[i])) {
            stack.push(exp[i] - '0');
        } else {
            int oprnd2 = stack.pop();
            int oprnd1 = stack.pop();
            switch (exp[i]) {
                case '+':
                    stack.push(oprnd1 + oprnd2);
                    break;
                case '-':
                    stack.push(oprnd1 - oprnd2);
                    break;
                case '*':
                    stack.push(oprnd1 * oprnd2);
                    break;
                case '/':
                    stack.push(oprnd1 / oprnd2);
                    break;
            }
        }
    }

    return stack.pop();
}

int main() {
    const char* prefixExp = "-/56*89";
    const char* postfixExp = "56/89*-" ;

    cout << "Prefix Expression Result: " << eval_prefix(prefixExp) << endl;
    cout << "Postfix Expression Result: " << eval_postfix(postfixExp) << endl;

    return 0;
}