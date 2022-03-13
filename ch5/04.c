#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int
main()
{
    printf("hello world (pid:%d)\n", (int) getpid());

    int rc = fork();
    if (rc < 0) {
        // fork failed; exit
        fprintf(stderr, "fork failed\n");
        exit(1);
    } else if (rc == 0) {
        // child (new process)
        printf("hello, I am child (pid:%d) \n", (int) getpid());
        execl("/bin/ls", "-lF", "/tmp/", NULL);
    } else {
        // parent goes down this path (original process)
        printf("hello, I am parent of %d (pid:%d)\n",
	       rc, (int) getpid());
        execlp("ls", "-lF", "/tmp/", NULL);
    }
    return 0;
}


/*
To give callers control over the environment that the new process is executing in.
 */
