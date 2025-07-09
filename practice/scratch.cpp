#include <iostream>
#include <string>
using namespace std;
int main( void )
{
     string s_1;
    cout << "Input a string: ";
    getline( cin, s_1 );
    cout << "You typed: " << s_1 << endl;
    
    string s;
    cout << "Input a string: ";
    cin >> s;
    cout << "You typed: " << s << endl;

   return 0;
}