#include <stdio.h>
#include <unistd.h>
#include <string.h>

#define P1_READ P1[0]
#define P1_WRITE P1[1]
#define P2_READ P2[0]
#define P2_WRITE P2[1]

void flipCase(char *str)
{
    for (int i = 0; str[i] != '\0'; i++)
    {
        if (str[i] >= 'A' && str[i] <= 'Z')
        {
            str[i] += 32;
        }
        else if (str[i] >= 'a' && str[i] <= 'z')
        {
            str[i] -= 32;
        }
    }
}

/*
 * Parent -> P1 -> Child
 * Child -> P2 -> Parent
 * 
*/
int main(int argc, char *argv[])
{

    char parentReadBuffer[strlen(argv[1])];
    char childReadBuffer[strlen(argv[1])];

    // Create pipes
    int P1[2];
    int P2[2];
    pipe(P1);
    pipe(P2);

    // Fork!
    pid_t pid;
    pid = fork();

    // Store the length of the string plus the zero terminator
    int len = strlen(argv[1]) + 1;

    if (pid == 0)
    {
        // Read the string from the first pipe
        read(P1_READ, childReadBuffer, len);
        printf("[Child]: Received %d: '%s'\n", (int)strlen(childReadBuffer), childReadBuffer);

        flipCase(childReadBuffer);

        // Write the modeified string to the second pipe
        printf("[Child]: Sending %d: '%s'\n", (int)strlen(childReadBuffer), childReadBuffer);
        write(P2_WRITE, &childReadBuffer, strlen(childReadBuffer)+1);
    }
    else
    {
        // Write the string to the first pipe
        printf("[Parent]: Sending %d: '%s'\n", (int)strlen(argv[1]), argv[1]);
        write(P1_WRITE, argv[1], len);

        // Read the modified string from the second pipe
        char parentReadBuffer[len];
        read(P2_READ, &parentReadBuffer, len);
        printf("[Parent] Received %d: '%s'\n", (int)strlen(parentReadBuffer), parentReadBuffer);
    }
}