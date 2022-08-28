#include "common.h"

// #include <string.h>

static int p2c[2];
static int c2p[2];

int main(int argc, char **argv) {
    argc--;
    argv++;

    pipe(p2c);
    pipe(c2p);


    int status = -1;
    int pid_flag = fork();
    if (pid_flag == -1) {
        fprintf(STDERR, "fork error!\n");
        exit(1);
    } else if (pid_flag == 0) { // chlid
        char readBuf[BUFFER_SIZE];
        // memset(readBuf, 0, sizeof(readBuf));
        char writeBuf[BUFFER_SIZE] = "child->parent\n";
        // memset(writeBuf, 0, sizeof(writeBuf));

        // read from, write to
        close(p2c[WR]);
        close(c2p[RD]);
        // write after read, avoid lock wait
        // strcpy(writeBuf, "child->parent\n");
        write(c2p[WR], writeBuf, sizeof(writeBuf));
        close(c2p[WR]);
        read(p2c[RD], readBuf, sizeof(readBuf));
        close(p2c[RD]);

        fprintf(STDOUT, "%s", readBuf);
        exit(0);
    } else { // parent
        char readBuf[BUFFER_SIZE];
        // memset(readBuf, 0, sizeof(readBuf));
        char writeBuf[BUFFER_SIZE] = "parent->child\n";
        // memset(writeBuf, 0, sizeof(writeBuf));

                // read from, write to
        close(p2c[RD]);
        close(c2p[WR]);
        // write after read, avoid lock wait
        // strcpy(writeBuf, "parent->child\n");
        write(p2c[WR], writeBuf, sizeof(writeBuf));
        close(p2c[WR]);
        read(c2p[RD], readBuf, sizeof(readBuf));
        close(c2p[RD]);

        sleep(2);
        fprintf(STDOUT, "%s", readBuf);

        wait(&status);
        exit(0);
    }
}