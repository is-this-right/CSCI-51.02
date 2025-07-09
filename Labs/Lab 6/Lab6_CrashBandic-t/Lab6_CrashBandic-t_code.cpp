#include <iostream>
#include <cstdlib>
#include <unistd.h>
#include <ctime>
using namespace std;

void current_datetime(){
    // reference: https://www.tutorialspoint.com/cplusplus/cpp_date_time.htm
    time_t now = time(0);
    tm *ltm = localtime(&now);
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
    << ltm->tm_min << ":";
    if (ltm->tm_sec < 10){
        cout << "0";
    }
    cout << ltm->tm_sec << endl;
}

int main(int argc, char* argv[]){
    int id = fork();
    if(id < 0){
        return 1;
    }
    if(id > 0){
        int counter = 0;
        while(true){
            current_datetime();
            if(counter%3==2){
                cout << "“This program has gone on for far too long. Type Ctrl+C to abort this timer application.”" << endl;
            }
            sleep(10);
            counter += 1;
        }
    }
    if(id == 0){  
        // reference: https://command-not-found.com/xclock
        // reference: https://access.redhat.com/solutions/409033  
        while(true){
            execl("/opt/X11/bin/xclock", "myXclock", NULL);
        }
    }
    return 0;
}
