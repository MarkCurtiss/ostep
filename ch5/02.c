#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int
main()
{
    printf("hello world (pid:%d)\n", (int) getpid());

    FILE *fp = fopen("/tmp/test-file", "w");
    int rc = fork();
    if (rc < 0) {
        // fork failed; exit
        fprintf(stderr, "fork failed\n");
        exit(1);
    } else if (rc == 0) {
        // child (new process)
        printf("hello, I am child (pid:%d) \n", (int) getpid());
        fprintf(fp, "Child process\n");
    } else {
        // parent goes down this path (original process)
        printf("hello, I am parent of %d (pid:%d)\n",
	       rc, (int) getpid());
        fprintf(fp, "Parent process\n");
    }
    fclose(fp);
    return 0;
}

/*
They both write to it:

markcurtiss@Marks-iMac [88]>./02
hello world (pid:36451)
hello, I am parent of 36452 (pid:36451)
hello, I am child (pid:36452)
~/ostep/ch5 [2022-03-12 16:26:44]
markcurtiss@Marks-iMac [89]>cat /tmp/test-file
Parent process
Child process
*/
