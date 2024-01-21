#include <iostream>
using namespace std;

int addTwoV1(int x) {
    x += 2;
    return x;
}

 

int addTwoV2(int* x) {
    *x += 2;
    return *x;
}

int main(void){
    int x = 5;
    int* pointer;
    pointer = &x;
    cout << "V1 = " << addTwoV1(x) << endl;
    cout << "pointer = " << pointer << endl;
    cout << "V2 = " << addTwoV2(pointer) << endl;
    return 0;
}