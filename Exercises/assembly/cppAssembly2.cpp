//cppAssembly2.cpp
int dummy(int a, int b){
    int x = a + b;
    int x = a - b;
    int x = a * b;
    int x = a / b;
    int x = a % b;
    return 0;
}

// still in cppAssembly2.cpp, after dummy( )
int main(void){
    int temp = dummy(19,3);
    return 0;
}