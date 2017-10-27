#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>

void main(int argc, char *argv[])
{
    if (argc != 2)
    {
        printf("Input must be a positive integer\n");
        exit(0);
    }
    
    int n;
    n = atoi(argv[1]);
    if (n < 1) {
        printf("Input must be a positive integer\n");
        exit(0);
    }

    if (fork() == 0)
    {
        while (n != 1)
        {
            printf("%d ", n);
            if (n % 2 == 0)
            {
                // If even
                n = n / 2;
            }
            else
            {
                // If odd
                n = 3 * n + 1;
            }
        }
        printf("%d", n);
    }
    else
    {
        wait(NULL);
    }
}