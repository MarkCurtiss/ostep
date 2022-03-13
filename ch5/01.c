#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int
main()
{
    printf("hello world (pid:%d)\n", (int) getpid());

    int sharedvariable = 88;

    int rc = fork();
    if (rc < 0) {
        // fork failed; exit
        fprintf(stderr, "fork failed\n");
        exit(1);
    } else if (rc == 0) {
        // child (new process)
      printf("hello, I am child (pid:%d) and the sharedvariable is %d \n", (int) getpid(), sharedvariable);
      sharedvariable = 44;
    } else {
        // parent goes down this path (original process)
        printf("hello, I am parent of %d (pid:%d)\n",
	       rc, (int) getpid());
    }
    printf("hello, I am the parent and the sharedvariable is now %d\n", sharedvariable);
    return 0;
}


/*
The change the child makes is reflected in the parent:
~/ostep/ch5 [2022-03-12 16:18:16]
markcurtiss@Marks-iMac [83]>./01
hello world (pid:36151)
hello, I am parent of 36152 (pid:36151)
hello, I am the parent and the sharedvariable is now 88
hello, I am child (pid:36152) and the sharedvariable is 88
hello, I am the parent and the sharedvariable is now 44
 */
