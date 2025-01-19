#include <stdio.h>
#include <limits.h>
#include <unistd.h>

int main() {
    printf("OPEN_MAX: %ld\n", sysconf(_SC_OPEN_MAX));
    return 0;
}
valgrind --leak-check=full ./a.out 














