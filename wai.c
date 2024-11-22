// C program to demonstrate working of wait()
// #include <stdio.h>
// #include <sys/wait.h>
// #include <unistd.h>

// int	main(void)
// {
// 	if (fork() == 0)
// 		printf ("HC: hello from child\n");
// 	else
// 	{
// 		printf("HP: hello from parent\n");
// 		wait();
// 		printf("CT: child has terminated\n");
// 	}
// 	printf("Bye\n");
// 	return (0);
// }

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    int pipefd[2]; // Array to store pipe ends
    pid_t child1, child2;

    if (pipe(pipefd) == -1) { // Create the pipe
        perror("pipe");
        exit(EXIT_FAILURE);
    }

    // First child process
    if ((child1 = fork()) == 0) {
        close(pipefd[0]); // Close unused read end
        dup2(pipefd[1], STDOUT_FILENO); // Redirect stdout to pipe write end
        close(pipefd[1]); // Close original write end

        // Child 1 task (e.g., producing data)
        execlp("ls", "ls", "-l", NULL); // Example command
        perror("execlp");
        exit(EXIT_FAILURE);
    } 

    // Second child process
    if ((child2 = fork()) == 0) {
        close(pipefd[1]); // Close unused write end
        dup2(pipefd[0], STDIN_FILENO); // Redirect stdin to pipe read end
        close(pipefd[0]); // Close original read end

        // Child 2 task (e.g., consuming data)
        execlp("wc", "wc", "-l", NULL); // Example command
        perror("execlp");
        exit(EXIT_FAILURE);
    }

    // Parent process
    close(pipefd[0]); // Close both pipe ends in parent
    close(pipefd[1]);

    int status;
    // Wait for both child processes
    waitpid(child1, &status, 0);
    if (WIFEXITED(status)) {
        printf("Child 1 exited with status %d\n", WEXITSTATUS(status));
    }

    waitpid(child2, &status, 0);
    if (WIFEXITED(status)) {
        printf("Child 2 exited with status %d\n", WEXITSTATUS(status));
    }

    return 0;
}
