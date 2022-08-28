#include "common.h"

const int MAX_TIME = 5;

int max(int v, int d) {
    if (v < d) {
        return v;
    } else {
        return d;
    }
}

void core(int *input, int curTime) {
    fprintf(STDOUT, "input:%d\n", *input);
    if (curTime > MAX_TIME) {
        exit(0);
    }
    int p2c[2];
    pipe(p2c);

    int status = -1;
    int pid_flag = fork();
    if (pid_flag == -1) {
        fprintf(STDERR, "fork error! %d\n", curTime);
        exit(1);
    } else if (pid_flag == 0) { // child
        char readBuf[BUFFER_SIZE];
        read(p2c[RD], readBuf, sizeof(readBuf));
        close(p2c[RD]);
        fprintf(STDOUT, "read num is:%s\n", readBuf);

        *input = atoi(readBuf) + 1;
        fprintf(STDOUT, "cur num is:%d\n", *input);
        core(input, curTime + 1);
        exit(0);

    } else { // parent
        // char input[BUFFER_SIZE] = itoa(input);
        char i = '0' + *input;
        write(p2c[WR], &i, sizeof(char));
        close(p2c[WR]);
        
        wait(&status);
        // exit(0);
    }
}

int main(int argc, char **argv) {
    argc--;
    argv++;

    // int max_time = max(atoi(*argvs), MAX_TIME);
    int init = 1;

    core(&init, 1);
    wait(0);

    // not in the same process(diff user space addr), the value is not changed!
    fprintf(STDOUT, "final:%d\n", init);
    exit(0);

}