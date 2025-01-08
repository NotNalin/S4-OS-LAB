#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>

void main() {
    struct stat buf;
    stat("./nine.c", &buf);
    printf("\n Size of file is %ld", buf.st_size);
    printf("\n Type of file is %o", buf.st_mode);
}
