#include <stdio.h>
#include <stdarg.h>

void PrintFloats(int n, ...) {
    int i;
    double val;
    printf("printing floats:");
    va_list vl;
    va_start(vl, n);
    for (int i = 0; i < n; ++i) {
        val = va_arg(vl, double);
        printf(" [%.2f]", val);
    }
    va_end(vl);
    printf("\n");
}
int main() {
    PrintFloats(10, 3.1, 2.71828, 1.41421);
}