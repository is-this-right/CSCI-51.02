#include <cstdlib>
#include <iostream>
#include <string>
using namespace std;

int main(){
    string sample = "no";
    int num = 10;
    char character = '!';
    sample.append(num, character);
    cout << sample;
}