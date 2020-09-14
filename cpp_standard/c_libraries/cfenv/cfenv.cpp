#include <stdio.h>
#include <math.h>
#include <fenv.h>
#pragma STDC FENV_ACCESS on

double fn(double x) {
    if (x == 0.0) feraiseexcept(FE_INVALID);
    return x;
}

int main() {
    feclearexcept(FE_ALL_EXCEPT);
    fn(0.0);
    if(fetestexcept(FE_INVALID)) printf("FE_INVALID raised\n");
    return 0;
}