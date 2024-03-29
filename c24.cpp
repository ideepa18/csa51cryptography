#include <stdio.h>

int gcd(int a, int b) {
    if (b == 0) {
        return a;
    }
    return gcd(b, a % b);
}

int mod_inverse(int e, int phi) {
    int r1 = phi, r2 = e;
    int t1 = 0, t2 = 1;
    int q, r, t;

    while (r2 > 0) {
        q = r1 / r2;
        r = r1 - q * r2;
        r1 = r2;
        r2 = r;

        t = t1 - q * t2;
        t1 = t2;
        t2 = t;
    }

    if (t1 < 0) {
        t1 += phi;
    }

    return t1;
}

int main() {
    int e = 31;
    int n = 3599;

    int p, q;
    for (int i = 2; i < n; i++) {
        if (n % i == 0) {
            p = i;
            q = n / i;
            break;
        }
    }

    int phi = (p - 1) * (q - 1);
    int d = mod_inverse(e, phi);

    printf("Private Key (d): %d\n", d);

    return 0;
}
