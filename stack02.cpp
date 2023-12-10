#include<iostream>
using namespace std;
//program of stack using synamic array
class Stack{
    private:
        int top;
        int* arr;
        int capacity; 
    public:
        Stack(int size = 5){
            top = -1;
            capacity = size;
            arr = new int[capacity];
            for(int i=0; i<capacity ; i++){
                arr[i]=0;
            }
        }
        bool isEmpty(){
            if(top==-1)
                return true;
            else
                return false;
        }
        bool isFull(){
            if (top == capacity - 1)
                return true;
            else
                return false;
        }
        void push(int val){ //Place an item onto the stack. If there is no place for new item, stack is in overflow state.
            if (isFull()){
                cout<<"Stack Overflow"<<endl;
            }
            else{
                top++;
                arr[top]=val;
            }
        }
        int pop(){ 
            //Return the item at the top of the stack and then remove it. If stack is empty, it is in an underflow state.
            if(isEmpty()){
                cout<<"Underflow condition"<<endl;
                return 0;
            }
            else{
                int popValue = arr[top];
                arr[top]=0;
                top--;
                return popValue;
            }
        }
        int count(){
            // Get the number of items in the stack.
            return (top+1);
        }
        int peek(int pos){
                // Access the item at the i position
            if (isEmpty()){
                cout<<"Underflow"<<endl;
            }
            else{
                return arr[pos];
            }
        }
        void change(int pos,int val){
            // Change the item at the i position
            arr[pos]=val;
            cout<<"value changed at the position:"<<pos<<endl;
        }
        void display(){
            cout<<"all values of stack are: "<<endl;
            for(int i = 4; i>=0 ; i--){
                cout<<arr[i]<<endl;
            }
        }
};
int main(){
    Stack s1;
    int option, position, value;

    do{
        cout<<"what operations do you want to perform? Select the option. Exit by hitting 0. "<<endl;
        cout<<"1.Push()"<<endl;
        cout<<"2.Pop()"<<endl;
        cout<<"3.isEmpty()"<<endl;
        cout<<"4.isFull()"<<endl;
        cout<<"5.peek()"<<endl;
        cout<<"6.count()"<<endl;
        cout<<"7.change()"<<endl;
        cout<<"8.display()"<<endl;
        cout<<"9.Clear Screen"<<endl;

        cin>>option;
        switch(option){
            case 0:
                break;
            case 1:
                cout<<"Enter the number you want to push: "<<endl;
                cin>>value;
                s1.push(value);
                break;
            case 2:
                cout<<"The popped value was: "<<s1.pop()<<endl;
                break;
            case 3:
                if(s1.isEmpty()){
                    cout<<"Stack is empty"<<endl;
                }
                else{
                    cout<<"Stack isnt empty"<<endl;
                }
                break;
            case 4:
                if(s1.isFull()){
                    cout<<"Stack is Full";
                }
                else{
                    cout<<"Stack isnt full"<<endl;
                }
                break;
            case 5: 
                cout<<"Enter the postion you want to peek: "<<endl;
                cin>>position;
                cout<<"Value at position "<<position<<" is "<<s1.peek(position)<<endl;
                break;
            case 6:
                cout<<"Count function called - No. of items in stack are "<<s1.count()<<endl;
                break;

            case 7:
                cout<<"Enter the postion where you want to change the value: "<<endl;
                cin>>position;
                cout<<"Enter the value: "<<endl;
                cin>>value;
                s1.change(position,value);
                break;
            case 8:
                cout<<"Display Fucntion called - "<<endl;
                s1.display();
                break;
            case 9:
                system("cls");
                break;
            default:
                cout<<"Please enter proper value"<<endl;
        }
    }while(option!=0);

    return 0;
}