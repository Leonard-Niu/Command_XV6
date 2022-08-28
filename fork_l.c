#include "kernel/types.h"
#include "kernel/stat.h"
#include "user/user.h"

#define STDIN 0
#define STDOUT 1
#define STDERR 2

int main(int argc, char **argv) {
    // classic format
    argc--;
    argv++;

    int pid_flag = -1;
    int status = -1;
    pid_flag = fork();
    if (pid_flag == -1) {
        fprintf(STDERR, "fork error!\n");
        exit(1);
    } else {
        if (pid_flag == 0) { // child
            fprintf(STDOUT, "child proc, pid:%d\n", getpid());
            exit(0);
        } else { // parent
            fprintf(STDOUT, "parent proc, pid:%d\n", getpid());
            wait(&status);
            exit(0);
        }
    }
    exit(0);
}