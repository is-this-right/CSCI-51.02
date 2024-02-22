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