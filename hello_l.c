#include "kernel/types.h"
#include "kernel/stat.h"
#include "user/user.h"

int main(int argc, char **argv) {
    fprintf(1, "hello world!\n");
    fprintf(1, "welcome to OS world\n");
    exit(0);
}