#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>


int
main()
{
    printf("hello world (pid:%d)\n", (int) getpid());

    int child1 = fork();
    if (child1 == 0) {
        // child (new process)
        printf("hello, I am child (pid:%d) \n", (int) getpid());
        sleep(2);
    } else {
        // parent goes down this path (original process)
        printf("hello, I am parent of %d (pid:%d)\n",
	       child1, (int) getpid());

        int child2 = fork();
        if (child2 == 0) {
            printf("hello, I am child (pid:%d) \n", (int) getpid());
            sleep(2);
        } else {
          int pids[2] = {child1, child2};
          pipe(pids);
        }

        int status;
        if (waitpid(0, &status, 0) >= 0) {
            printf("child processes exited with status %d\n", status);
        };
    }
    return 0;
}

/*
The child doesn't print anything.
*/
