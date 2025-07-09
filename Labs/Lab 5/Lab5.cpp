#include <iostream>
#include <cstdlib>
using namespace std;

struct Point3D {
    int x;
    int y;
    int z;
};

void manhatdistance(Point3D p, Point3D q){
    cout << " - p.x: " << p.x;
    cout << " - p.y: " << p.y;
    cout << " - p.z: " << p.z;
    cout << " - q.x: " << q.x;
    cout << " - q.y: " << q.y;
    cout << " - q.z: " << q.z << endl;
    cout << "manhat : " << abs(p.x - q.x) + abs(p.y - q.y) + abs(p.z - q.z) << endl;
}

int main(){
    int T, N;
    cin >> T;

    for(int t = 0; t<T; t++){
        string N_holder;
        cin >> N_holder;
        try{
            N=stoi(N_holder);
        }
        catch(std::invalid_argument e){
            cout << "Invalid input. Check N or T";
            return 0;
        }
        Point3D p;
        
        for(int n = 0; n<N; n++){
            string x, y, z;
            Point3D q;
            cin >> x >> y >> z;
            
            if (x.empty() || y.empty() || z.empty()){
                cout << "Error: Incomplete input";
                break;
            }

            q.x = stoi(x);
            q.y = stoi(y);         
            q.z = stoi(z);
    
                    
            if(n>0){
                manhatdistance(p, q);              
            }
            p = q;
        }
        cout << endl;
    }
    return 0;
}