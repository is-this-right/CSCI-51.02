struct IntStack{
    #include "IntNode.hpp"
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

    int peek(){
        if (!is_empty()){
            return (*head).getData();
        } else {
            return -1;
        }
    }

    int getSize(){
        return size;
    }

    void push(int i){
        IntNode* node = new IntNode(i);
        if (!is_empty()){
            (*node).setNext(head);
        }
        head = node;
        delete node;
        node = nullptr;
        size++;
    }


    void push(IntNode n){
        IntNode* node = new IntNode(n);
        if (!is_empty()){
            (*node).setNext(head);
        }
        head = node;
        delete node;
        node = nullptr;
        size++;
    }

    int pop(){
        if (!is_empty()){
            IntNode* node = head;
            head = (*head).getNext();
            (*node).deleteNext();
            delete node;
            node = nullptr;
            size--;
            return (*node).getData();
        } 
        // else{
        //     return 1;
        // }
        else {
            throw std::out_of_range("Index out of range :/");
        }
    }
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