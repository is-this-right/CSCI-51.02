#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <math.h>

// struct to hold data
typedef struct data{
    int i; // index
    int N; // number of threads
    long double X; // value to sine
} data;

// factorial(c) = c!
long double fact(long double c){
    long double fact = c;
    for(long double i=2; i<c; i++){
        fact *= i;
    }
    return fact;
}

// global variable sum
long double sum=0;

// thread function
void* run(void* arg){
    // instantiate variables
    data *d = (data*) arg;
    int i=d->i, N=d->N, c;
    long double X=d->X, addend=1;

    while(addend>pow(10, -16)){
        c = (2*i)+1;
        addend = (pow(X, c))/(fact(c));
        if(i%2==0){
            sum += addend;
        }else{
            sum -= addend;
        }
        i += N;
    }

    pthread_exit(0);
}

int main(int argc, char **argv){
    if(argc!=3){
        printf("Error: Invalid number of arguments.\n");
        return 1;
    }else if(atoi(argv[1])<=0){
        printf("Error: Invalid input.\n");
        return 1;
    }

    // instantiate variables
    data d;
    d.N = atoi(argv[1]);
    d.X = strtold(argv[2], NULL);    
    pthread_t t; 
    
    // threads
    for(int i=0; i<d.N; i++){
        d.i = i;
        pthread_create(&t, NULL, run, &d);
        pthread_join(t, NULL);
    }

    // print sum
    printf("Lab sin(x): %Lf\n", sum);
    long double test = sinl(d.X);
    printf("sinl(x): %LF", test);
    return 0;
}




