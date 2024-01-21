#include <cstdlib>
#include <iostream>
#include <string>
using namespace std;

void censor(string str){
    cout << str[0];
    for (int i = 1; i < str.length(); i++){
        cout << "#";
    }
}

string hashtaginator(string in){
    string out;
    if (in.length() > 0){
        
        out += in[0];
        int reps = in.length() - 1;
        if (reps > 0){
            char character = '#';
            out.append(reps, character);
        }
    }
    return out;
}

void caesar_cypher(char* name){
    if ( ((*name >= 97 ) && (*name < 122)) || ( (*name >= 65) && (*name < 90) ) ){
        *name += 1;
    } else if (*name == 90){
        *name = 65;
    } else if (*name == 122){
        *name = 97;
    }
}

int main(void) {
    string user_name;
    cout << "1.";
    cin >> user_name;
    cout << "2." << user_name << endl;
    cout << "3.";
    cout << hashtaginator(user_name) << endl;
    // censor(user_name) << endl;
    for (int i = 0; i < user_name.length(); i++)
    {
        caesar_cypher(&user_name[i]);
    }
    cout << "4." << user_name;
}