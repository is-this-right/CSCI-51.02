#include <iostream>
#include <cstdlib>
#include <unistd.h>
using namespace std;

int main(int argc, char* argv[]) {

// just use execv to run ANY program

// if(execv( "/Users/je/Desktop/school/3rd Year/2nd Sem/CSCI 51.02/Labs/Lab 6/forktest", argv ) == -1) {
if(execl("/Users/je/Desktop/school/3rd Year/2nd Sem/CSCI 51.02/Labs/Lab 6/forktest", "REALLY NOT GEDIT", NULL) == -1){
// error

    cout << "Error. Booooo!" << endl;

}

cout << "Will this line still be printed?" << endl;

}