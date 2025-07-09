#include <iostream>
#include <cstdlib>
#include <unistd.h>
using namespace std;

int main( void ){
    if( fork() == 0 ){
        if( fork() == 0 ){
            if( fork() == 0 ){
                if( fork() == 0 ){
                    if( fork() == 0 ){
                        if( fork() == 0 ){
                            cout << "I'm a kid process!\nMy ID is " << getpid() << ".\n";
                        }
                    }
                }
            }
        }
    }
    return 0;
    }