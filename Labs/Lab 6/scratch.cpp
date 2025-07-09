#include <iostream>
#include <ctime>

using namespace std;

int main() {
    // current date/time based on current system
    time_t now = time(0);

    // convert now to string form
    tm *ltm = localtime(&now);

    cout << "Format:" << endl;
    cout << "[yyyy-mm-dd] hh:mm:ss." << endl;
    cout << "[" << 1900 + ltm->tm_year << "-";
    if(ltm->tm_mon < 10){
        cout << "0";
    }
    cout << 1 + ltm->tm_mon << "-";
    if (ltm->tm_mday < 10){
        cout << "0";
    }
    cout << ltm->tm_mday << "] "
    << ltm->tm_hour << ":"
    << ltm->tm_min << ":"
    << ltm->tm_sec << endl;
}