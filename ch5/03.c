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
        printf("hello \n");
        exit(1);
    } else {
        sleep(1);
        printf("goodbye \n");
    }
    printf("time to be done\n");
    return 0;
}

/*
Yes:
~/ostep/ch5 [2022-03-12 16:36:13]
markcurtiss@Marks-iMac [107]>make && ./03
gcc -o 03 03.c -Wall -Wextra -Werror -O2 -std=c99 -pedantic
hello world (pid:36789)
hello
goodbye
time to be done
*/
