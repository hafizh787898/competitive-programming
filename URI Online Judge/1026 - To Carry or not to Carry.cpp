#include <bits/stdc++.h>
using namespace std;

int main()
{
    long long n, m;
    while (scanf("%lld %lld", &n, &m) != EOF) {
        printf("%lld\n", n ^ m);
    }
}