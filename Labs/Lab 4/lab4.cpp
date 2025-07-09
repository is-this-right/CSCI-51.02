#include <iostream>
using namespace std;

int dummy(int x, int y){
    int ret = x << y;
    return ret;
}

int main(void){
    cout << dummy(5, 5);
}