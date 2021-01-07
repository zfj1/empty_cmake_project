#include "example.h"

int DoExampleCalculation(int A, int B) {
    if (A > B)
        return 2 * A - B;
    else {
        if (B == A) return 0;
        A = B * B / A;
        return (A - B + 2 * A) / (A * B) + B * A * A / 3;
    }
};
