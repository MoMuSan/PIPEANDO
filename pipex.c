#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>



int main(int argc, char *argv[], char *envp[])
{
    int i = 0;
    /*char *env = getenv("PATH");
    printf("ENV %s\n", env);*/

    while (envp[i] != NULL)
    {
        printf(" %s\n", envp[i]);
        char *var = envp[i];
        
        i++;
    }
    printf("------VAR %s %d\n",var, i);


    return (0);
}