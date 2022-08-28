#include "kernel/types.h"
#include "kernel/stat.h"
#include "user/user.h"

#define STDIN 0
#define STDOUT 1
#define STDERR 2


int main(int argc, char **argv) {
    argc--;
    argv++;

    if (argc != 1) {
        fprintf(STDERR, "input arg error\n");
    } else {
        // for 2nd char array, every *argv is a string, every **argv is a char
        fprintf(STDOUT, "sleep for %s\n", *argv);
        sleep(atoi(*argv));
    }
    exit(0);
}