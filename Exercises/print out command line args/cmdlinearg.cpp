#include <iostream>
using namespace std;

string reverse_string(string variable){
    string reversed = "";
    for (int i = variable.length(); i >= 0; i--){
        reversed = reversed + variable[i];
    }
    return reversed;
}

int main(int argc, char* argv[])
{
    // assuming change the order they are printed
    for(int i = argc - 1; i >= 0; i--)
    {
        cout << "arg" << i << ": " << argv[i];
        cout << endl; // cout << "\n";
        cout << reverse_string(argv[i]) << endl;
        // printf("%c\n", argv[i][0]);
        // printf("%s\n", argv[i]+1);
    }
    return 0; // non-zero means an error
}