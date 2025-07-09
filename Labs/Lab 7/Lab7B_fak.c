#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <math.h>

// struct to hold data
typedef struct data{
    int i; // index
    int N; // number of threads
    long double X; // value to sine
    long double* thread_sum;
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
long double sum = 0;
long double *thread_sum;
pthread_mutex_t mutex1 = PTHREAD_MUTEX_INITIALIZER;


// thread function
void* run(void* arg){
    pthread_mutex_lock( &mutex1 );
    // instantiate variables
    data *d = (data*) arg;
    int i=d->i, N=d->N, c;
    int id=d->i;
    long double X=d->X, addend=1;

    while(addend>pow(10, -16)){
        c = (2*i)+1;
        addend = (pow(X, c))/(fact(c));
        if(i%2==0){
            thread_sum[id] += addend;
        }else{
            thread_sum[id] -= addend;
        }
        printf("id: %d\n", id);
        i += N;
    }
    printf("Thread %d sum: %Lf\n", id, thread_sum[id]);
    pthread_mutex_unlock( &mutex1 );

    pthread_exit(0);
}

int main(int argc, char **argv){
    if(argc!=3){
        printf("Error: Invalid number of arguments.\n");
        return 1;
    }else if(atoi(argv[1])<=0 || (fabsl(strtold(argv[2], NULL))>=3.15)){
        printf("Error: Invalid input.\n");
        return 1;
    }

    // instantiate variables
    int N = atoi(argv[1]);
    int X = strtold(argv[2], NULL);
    thread_sum = malloc(sizeof(long double) * N); // N = number of thread
    pthread_t* t = malloc(sizeof(pthread_t) * N);; 
    
    // threads
    for(int i=0; i<N; i++){
        data d;
        d.N = atoi(argv[1]);
        d.X = strtold(argv[2], NULL);    
        d.i = i;
        printf("Created Thread %d\n", d.i);
        pthread_create(&t[i], NULL, &run, &d);

        printf("Thread %d running\n", i);
        pthread_join(t[i], NULL);
    }

    for (int i = 0; i < N; i++){
        sum += thread_sum[i];
    }

    // print sum
    printf("Total sum: %Lf\n", sum);
    long double test = sinl(X);
    printf("sinl(x): %LF", test);
    return 0;
}




