#include <stdio.h>
#include <math.h>
long int ext_euclidean(long int m, long int b);
long int power(long int a, long int j, long int c);
int main()
{
    long int p, q, g, x, hm, k, y, r, s, s1, w, u1, u2, v, v1, v2, v3;
    printf("Enter the value of p: ");
    scanf("%ld", &p);
    printf("Enter the value of q: ");
    scanf("%ld", &q);
    printf("Enter the value of g: ");
    scanf("%ld", &g);
    printf("Enter the value of x: ");
    scanf("%ld", &x);
    printf("Enter the value of hm: ");
    scanf("%ld", &hm);
    printf("Enter the value of k: ");
    scanf("%ld", &k);
    y = power(g, x, p);
    printf("\nValue of y: %ld\n", y);
    r = power(g, k, p) % q;
    printf("Value of r: %ld\n", r);
    s1 = (hm + (x * r)) % q;
    w = ext_euclidean(q, k);
    s = (w * s1) % q;
    printf("Value of s: %ld\n", s);
    u1 = (hm * w) % q;
    u2 = (r * w) % q;
    v1 = power(g, u1, p);
    v2 = power(y, u2, p);
    v = ((v1 * v2) % p) % q;
    printf("Value of w: %ld\n", w);
    printf("Value of u1: %ld\n", u1);
    printf("Value of u2: %ld\n", u2);
    printf("Signature (r,s): %ld %ld\n", r, s);
    printf("Value of v: %ld\n", v);
    if (v == r)
    {
        printf("\nSignature valid v==r");
    }
    return 0;
}
long int ext_euclidean(long int m, long int b)
{
    long int a1 = 1, a2 = 0, a3 = m, b1 = 0, b2 = 1, b3 = b, q, t1, t2, t3;
    while (1)
    {
        if (b3 == 0)
        {
            return 0;
        }
        if (b3 == 1)
        {
            if (b2 < 0)
                b2 += m;
            return b2;
        }
        q = a3 / b3;
        t1 = a1 - (q * b1);
        t2 = a2 - (q * b2);
        t3 = a3 - (q * b3);
        a1 = b1;
        a2 = b2;
        a3 = b3;
        b1 = t1;
        b2 = t2;
        b3 = t3;
    }
}
long int power(long int a, long int j, long int c)
{
    long int f = 1, i;
    for (i = 1; i <= j; i++)
    {
        f = (f * a) % c;
    }
    return f;
}
