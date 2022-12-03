#include <iostream>
#include <math.h>

using namespace std;

int main(void)
{
        double A, B, R1, P1, R2, P2;

        cin >> R1 >> P1 >> R2 >> P2;

        A = (R1 * cos(P1)) * (R2 * cos(P2)) - (R1 * sin(P1)) * (R2 * sin(P2));
        B = R1 * sin(P1) * R2 * cos(P2) + R2 * sin(P2) * R1 * cos(P1);

        if(B == 0) {
                printf("%.2lf", A);
        }
        else {
                printf("%s%.2f%s%.2fi",
                A >= -0.001 ? "" : "-",abs(A),
		B >= -0.001 ? "+" : "-", abs(B));
        }


        return 0;
}
