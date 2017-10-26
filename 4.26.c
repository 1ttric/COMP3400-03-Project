//
//  main.c
//  4.26
//
//  Created by Devin Nguyen on 10/24/17.
//  Copyright © 2017 Devin Nguyen. All rights reserved.
//

#include<stdio.h>
#include<pthread.h>
//initialize data shared by threads
int arr[1000],uInput;

//setup for call child thread that will run fibonacci algorithm
void * call_child(void *ptr){
    int n=0;
    arr[0]=0;
    arr[1]=1;
    for(n=2;n<uInput;n++){
        arr[n] = arr[n-1]+ arr[n-2];
    }
    return uInput;
}

//main function
int main(){
    int n;
    
    //thread identifier
    pthread_t p_thread;
    
    //capture uInput
    printf("Enter amount of fibonacci numbers user wishes to generate:\n");
    scanf("%d",&uInput);
    
    //create thread to run fibonacci algorithm
    pthread_create(&p_thread, NULL, call_child, NULL);
    
    //wait for thread to exit
    pthread_join(p_thread,NULL);
    
    //output number stored in parent thread
    printf("\nPrinting fibonacci numbers in parent\n");
    for(n=0;n<uInput;n++){
        printf("%d\n",arr[n]);
    }
      printf("\n");
    
    //end program
    return 0;
}