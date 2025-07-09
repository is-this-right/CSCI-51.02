#include <iostream>
#include <cstdlib>
#include <unistd.h>
using namespace std;

int main( int argc, char* argv[] ) {

int var = 4;

var += 2;

if( fork() == 0 ) {

    var += 8;

    cout << "Child ID: " << getpid();

    cout << ", var = " << var << "\n";

}

else {

    var -= 8;

    cout << "Parent ID: " << getpid();

    cout << ", var = " << var << "\n";

}

}