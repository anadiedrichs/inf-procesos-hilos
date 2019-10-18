// compilar usando gcc 1-pthread-basic.c -lpthread
#include <stdio.h> 
#include <stdlib.h> 
#include <unistd.h> //Header file for sleep(). man 3 sleep for details. 
#include <pthread.h> 

// A normal C function that is executed as a thread 
// when its name is specified in pthread_create() 
void *myThreadFun(void *vargp) 
{ 
	sleep(1); 
	printf("Mostrando el hola mundo de los hilos - thread \n"); 
	return NULL; 
} 

int main() 
{ 
	pthread_t thread_id; 
	printf("Before Thread - antes del hilo \n"); 
	pthread_create(&thread_id, NULL, myThreadFun, NULL); 
	pthread_join(thread_id, NULL); 
	printf("After Thread - despues del hilo \n"); 
	exit(0); 
}

