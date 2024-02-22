#include <iostream>
using namespace std;

struct IntNode{
    int data;
    int* node;
    IntNode* next;

    IntNode(int i){
        data = i;
        node = new int(data);
        next = nullptr;
    }

    IntNode(){
        node = nullptr;
        next = nullptr;
    }

    void setData(int i){
        data = i;
    }

    int getData(){
        return *node;
    }

    void deleteData(){
        delete node;
        node = nullptr;
    }

    void setNext(IntNode* node){
        next = node;
    }

    IntNode* getNext(){
        return next;
    }

    void deleteNext(){
        delete next;
        next = nullptr;
    }

    ~IntNode(){
        delete node;
        delete next;
    }
};

struct IntStack{
    IntNode* head;
    int size;
    IntStack(int i){
        size = 1;
        head = new IntNode(i);
    }

    IntStack(){
        size = 0;
        head = nullptr;
    }

    bool is_empty(){
        return head == nullptr;
    }

    void peek(){
        cout << "Peek-a-boo: ";
        if (!is_empty()){
            cout << (*head).getData();
        } else {
            cout << "empty b";
        }
    }

    int getSize(){
        cout << "Size me up: ";
        return size;
    }

    void push(int i){
        IntNode node = IntNode(i);
        cout << "Push me to the edge: " << node.data << endl;
        if (!is_empty()){
            (node).setNext(head);
        }
        head = &node;
        cout << "node->data: " << node.data << endl;
        cout << "(*head).getData(): " << (*head).getData() << endl;
        size++;
    }


    int pop(){
        cout << "Popping Off: ";
        if (!is_empty()){
            IntNode* node = head;
            head = (*head).getNext();
            (*node).deleteNext();
            delete node;
            node = nullptr;
            size--;
            return (*node).getData();
        } else {
            throw out_of_range("Index out of range.");
        }
    }
    
    // void push(IntNode n){
    //     cout << "Push me off the ledge: ";
    //     IntNode* node = new IntNode(n);
    //     if (!is_empty()){
    //         (*node).setNext(head);
    //     }
    //     head = node;
    //     delete node;
    //     node = nullptr;
    //     size++;
    // }
    // #include <string>
    // string print_stack(){
    //     string str = "";
    //     IntNode* node = head;
    //     while(node != nullptr){
    //         str += (*node).getData() + " ";
    //         node = (*node).getNext();
    //     }
    //     return str
    // }

    // void swap(){

    // }
    ~IntStack(){
        while(!is_empty()){
            pop();
        }
        size = 0;
        head = nullptr;
    }
};

int main(void){
    IntStack stack = IntStack(1);
    stack.peek();
    cout << stack.pop() << endl;
}