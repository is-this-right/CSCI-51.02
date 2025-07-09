#include <iostream>
#include <list>
using namespace std;

int dummy(int x, int y, list<int>* l){
    int len = l->size();
    if(y<=1){
        int ret = x;  
        cout << endl << "calculating: " << ret << endl;
        list<int>::iterator i = l->begin();
        while(*i<=1){
            if(*i == 1){
                ret *= 2;
                cout << "shifted: " << ret << endl;
            }else if(*i == 0){
                ret += x;
                cout << "added: " << ret << endl;
            }else{
                break;
            }
            advance(i, 1);
        }
        cout << "done!" << endl;
        while(!l->empty()){
            l->pop_front();
        }
        return ret;
    }else if(y<-17 || y>25){
        cout << endl << "too easy" << endl;
        return x*y;
    }else if(y%2==0){
        l->push_front(1);
        return dummy(x, y/2, l);
    }else{
        l->push_front(0);
        return dummy(x, y-1, l);
    }
}

int main(){
    list<int>* l = new list<int>;
    // cout << "1 * 3"   << dummy(1, 3, l)  << endl << endl;
    // cout << "2 * 5"   << dummy(2, 5, l)  << endl << endl;
    // cout << "3 * 4"   << dummy(3, 4, l)  << endl << endl;
    // cout << "5 * 7"   << dummy(5, 7, l)  << endl << endl;
    // cout << "21 * 99" << dummy(21, 99, l) << endl << endl;
    cout << "25 * -1" << dummy(25,-1, l) <<endl<<endl;
}

