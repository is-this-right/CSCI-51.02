#include <iostream>
#include <string>
using namespace std;

int main(){
    // access strings
    string name = "Jamie Oliver";
    cout << name[0] << endl;
    name[0] = 'C';
    cout << name << endl;

    // string length & using special characters
    // NOTE: to use quotations (or any special juju), use a back-slash (\)
    cout << "Camie Oliver\'s name (including whitespace) has " << name.length() << " characters" << endl;

    // String concatenation
    string first_name = "Junel";
    string last_name = "Quintos";
    cout << first_name + last_name << endl;

    //getting a long string input with whitespace
    /*
    Problem: cin only accepts the first word.
    White-space = new variable/input
    Solution: use getline() function
    */
    cout << "What's a quote you believe in?" << endl;
    string quote;
    getline(cin, quote);
    cout << "Did you say: \"" << quote << "\"";
}