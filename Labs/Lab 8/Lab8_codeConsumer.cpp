#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/sem.h>
#include <sys/shm.h>
#include <fstream>
#include <unistd.h>

using namespace std;

int main(int argc, char* argv[]){
    // Instantiation
    char* copy;
    int shm_size = atoi(argv[2]);
    key_t key = 1234;
    struct sembuf sema;
    sema.sem_num = 0;
    ofstream output;
    output.open(argv[1], ios::out);
    output.close();
    output.open(argv[1], ios::out | ios::app );
    cout << "instantiation" << endl;
    sleep(1);

    // Find Semaphore
    int sem_id = semget(key, 1, IPC_CREAT | 0666);
    cout << "semaphore find" << endl;
    sleep(1);

    // Wait Semaphore
    sema.sem_op  = 0;
    int op_result = semop( sem_id, &sema, 1);
    if(op_result==1){        
        cout << "semaphore could not wait" << endl;
        return 1;
    }    
    cout << "semaphore wait" << endl;

    // Access Semaphore
    sema.sem_op  = 1;    
    op_result = semop( sem_id, &sema, 1);
    if(op_result==1){
        cout << "semaphore could not access" << endl;
        return 1;
    }
    cout << "semaphore access" << endl;
    
        // Find SharedMemory
        int shm_id = shmget(key, shm_size, IPC_CREAT | 0666);
        if(shm_id == -1){
            sema.sem_op  = -1;
            op_result = semop( sem_id, &sema, 1);
            cout << "sharedmem could not find" << endl;
            return 1;
        }
        cout << "sharedmem find" << endl;

        // Access SharedMemory
        char* shm_ptr = (char*)shmat(shm_id, NULL, 0);
        if(shm_ptr==(char*)(-1)){
            sema.sem_op  = -1;
            op_result = semop( sem_id, &sema, 1);
            cout << "sharedmem could not access" << endl;
            return 1;
        }
        cout << "sharedmem access" << endl;

            // Check SharedMemory if not full
            char buffer[shm_size];
            strcpy(buffer, shm_ptr);
            if(strlen(buffer)!=shm_size){
                cout << "sharedmem not full" << endl;
                sema.sem_op  = -1;
                op_result = semop( sem_id, &sema, 1);
                return 1;
            }else{

            // Read SharedMemory into copy
                strcpy(copy, shm_ptr);
                output << copy;
                cout << "sharedmem read : " << copy << endl;

            // Remove SharedMemory
                shmctl(shm_id, IPC_RMID, NULL);
                cout << "sharedmem removed" << endl;
            }
            output.close();
            

    // Release Semaphore
    sema.sem_op  = -1;
    op_result = semop( sem_id, &sema, 1);
    if(op_result==1){
        cout << "semaphore could not release" << endl;
        return 1;
    }
    cout << "semaphore release" << endl;
    
    return 0;
}