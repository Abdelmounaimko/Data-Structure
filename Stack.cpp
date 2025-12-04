#include<iostream> 
using namespace std;

typedef struct Stacks {
	int data;
	struct Stacks *Next;
}Stacks;

Stacks* Top = NULL;

void push(int data) {
    Stacks * Element = new Stacks;
    Element -> data = data;
    Element->Next = Top;
    Top = Element;
}

int pop(){
    Stacks * temp;
    int value;
    if(Top == NULL){
        cout << "Stack is underflow." << endl;
        return -1;
    }
    temp = Top ;
    value = temp->data ;
    Top = Top->Next;
    delete temp;
    return value;
} 

int peek(){
    if(Top == NULL){
        cout << "Stack is underflow." << endl;
        return -1 ;
    }
    return Top->data ;
}

void display(){
    Stacks * Show = Top;
    if(Top == NULL){
        cout << "Stack is underflow." << endl;
    }
    while (Show != NULL){
        cout << Show->data <<endl;
        Show = Show->Next;
    }
}

int main() {
    int choice;
    int push_value ;
    do{
        cout << "------Choose one of these options------" <<endl; 
        cout << "-------------1: Push-------------------" <<endl;
        cout << "--------------2: Pop-------------------" <<endl;
        cout << "--------------3:Peek-------------------" <<endl;
        cout << "-------------4: Display----------------" <<endl;
        cout << "-------5: For exit this program--------" <<endl;

        cin >> choice;

        switch(choice)
        {
        case 1: cout << "enter value of push: " ;
                cin >> push_value;
                push(push_value);
            break;
        case 2: pop();
           break;
        case 3: cout << "Top element: " << peek() << endl;
            break;
        case 4: cout << "Elements in your stack :"<< endl; display();
            break;
        case 5: exit(0);
        default: cout << "enter correct value" << endl;
            break;
        }
    }while(choice != 5 );

}
