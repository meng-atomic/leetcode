#include <stdlib.h>
#include <string.h>

int main(int argc, char** argv) {
    void* buffer = malloc(10);
    memset(buffer, 0, 10);
    return 0;
}