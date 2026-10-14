#include <stdio.h>

int main() {
    int a1 = 3, a2 = 8, b1, b2, b3;
    a2 -= a1; // a2=8-3=5
    b1 = a1 + 2 * a2 * a2; // b1=3+2*25=3+50=53
    b2 = !a1; // b2=!3 ? 0
    printf("b2=%d\n", b2);
    b3 = b2++; // b3=0, b2=0+1=1
    printf("a1=%d a2=%d b1=%d b2=%d b3=%d\n", a1, a2, b1, b2, b3);

    float f1 = 1.5, f2 = 1.5, r1, r2;
    r1 = f1 * f1 + 2 * f2; // r1=2.25+3=5.25
    r2 = (f1 != f2) ? f1 - 0.3 : f2 + 0.4; // r2=(1.5!=1.5)? ні 1.5+0.4=1.9
    printf("r1=%5.2f r2=%5.2f\n", r1, r2);

    return 0;
}