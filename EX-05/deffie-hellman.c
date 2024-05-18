#include <stdio.h>
#include <math.h>

long power(long a, long b, long p)
{
    if (b == 1)
        return a;
    else
        return ((long)pow(a, b)) % p;
}

int main()
{
    long P, G, a, b, x, y, ka, kb;

    printf("Enter the prime number (P): ");
    scanf("%ld", &P);
    printf("Enter the primitive root (G): ");
    scanf("%ld", &G);
    printf("Enter the private key for person A (a): ");
    scanf("%ld", &a);

    x = power(G, a, P);

    printf("Enter the private key for person B (b): ");
    scanf("%ld", &b);

    y = power(G, b, P);

    ka = power(y, a, P);
    kb = power(x, b, P);

    printf("Secret key for person A: %ld\n", ka);
    printf("Secret key for person B: %ld\n", kb);

    return 0;
}
