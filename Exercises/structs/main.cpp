#include "Point3D.hpp"
#include "allVar.hpp"
#include <iostream>
using namespace std;

int main(void){
    allVar structure;
    cout << structure._bool << endl;
    cout << structure._char << endl;
    cout << structure._double << endl;
    cout << structure._float << endl;
    cout << structure._int << endl;
    cout << structure._string << endl;


    structure._bool = false;
    structure._char = 'a';
    structure._double = 1.012345678901234567890123456789012345678901234567890;
    structure._float = 1.012345678901234567890123456789012345678901234567890;
    structure._int = structure._float;
    structure._string = "This is a string. I can write as much as I want here. Yup. No problemo. I can even write numbers. Watch. 1234567890!";

    cout << structure._bool << endl;
    cout << structure._char << endl;
    cout << structure._double << endl;
    cout << structure._float << endl;
    cout << structure._int << endl;
    cout << structure._string << endl;

    // Point3D point = {1, 2, 3};
    // cout << point.x << " " << point.y;
    // cout << " " << point.z << endl << endl;
    // Point3D orig;
    // cout << "orig: " << endl;
    // cout << orig.x << " " << orig.y;
    // cout << " " << orig.z << endl;
}