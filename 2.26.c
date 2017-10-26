//
//  226.c
//  test
//
//  Created by Devin Nguyen on 10/20/17.
//  Copyright © 2017 Devin Nguyen. All rights reserved.
//
//Create two documents for reading and writing before running
#include <stdio.h>
#include <stdlib.h>


int main(){
    //initialize variables
    FILE *file1, *file2;
    char fileStorage[100], contentStorage;
    //scan for file source
    printf("Enter source file \n");
    scanf("%s", fileStorage);
    
    //read file
    file1=fopen(fileStorage, "r");
    
     //if file source isn't found
    if(file1==NULL){
        printf("can't open file, check working directory %s \n", fileStorage);
        exit(0);
    }
    
    //scan for file write
    printf("enter destination file for writing \n");
    scanf("%s",fileStorage);
    
    //write file
    file2=fopen(fileStorage,"w");
    
    //if file write isn't found
    if (file2 == NULL){
        printf("Cannot open file, check working directory %s \n", fileStorage);
        exit(0);
    }
    //store contents of file 1 into content storage
    contentStorage = fgetc(file1);
    
    //copy contents to file 2
    while(contentStorage != EOF){
        fputc(contentStorage, file2);
        contentStorage = fgetc(file1);
    }
    
    //notify user that contents are copied
    printf("\nContent copied to %s \n", fileStorage);
    
    //close both documents
    fclose(file1);
    fclose(file2);
    
    //end program
    return 0;
}


