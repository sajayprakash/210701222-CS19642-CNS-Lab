#include <stdio.h>
#include <math.h>

int gcd(int e, int z)
{
    if (e == 0)
        return z;
    else
        return gcd(z % e, e);
}

int findE(int z)
{
    for (int e = 2; e < z; e++)
    {
        if (gcd(e, z) == 1)
        {
            return e;
        }
    }
    return 0;
}

int findD(int e, int z)
{
    for (int i = 0; i <= 9; i++)
    {
        int x = 1 + (i * z);
        if (x % e == 0)
        {
            return x / e;
        }
    }
    return 0;
}

int main()
{
    int p, q, msg, n, z, e, d;
    printf("Enter the value of p (a prime number): ");
    scanf("%d", &p);
    printf("Enter the value of q (a prime number): ");
    scanf("%d", &q);
    printf("Enter the message to be encrypted: ");
    scanf("%d", &msg);

    n = p * q;
    z = (p - 1) * (q - 1);
    printf("the value of z = %d\n", z);

    e = findE(z);
    printf("the value of e = %d\n", e);

    d = findD(e, z);
    printf("the value of d = %d\n", d);

    double c = fmod(pow(msg, e), n);
    printf("Encrypted message is : %.0f\n", c);

    long long N = n;
    long long C = (long long)c;
    long long msgback = fmod(pow(C, d), N);
    printf("Decrypted message is : %lld\n", msgback);

    return 0;
}
