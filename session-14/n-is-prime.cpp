#include <cstdio>
#include <vector>
#include <cmath>

using namespace std;

typedef long long ll;

const int N = 1e6+6;

bool isPrime[N];

void sieve() {
    fill(isPrime, isPrime+N, true);
    isPrime[0] = isPrime[1] = false;

    for (int i = 2; i*i < N; i++) {
        if (isPrime[i]) {
            for (int m = 2*i; m < N; m += i) {
                isPrime[m] = false;
            }
        }
    }
}


int t, n;

int main() {
    // scanf("%d", &t);
    sieve();
    for (int i = 1; i <= 100; i++) {
        printf("%d %s\n", i, (isPrime[i] ? "PRIME" : "NOT"));
    }
    while (t--) {   // O(t)
        scanf("%d", &n);
        puts(isPrime[n] ? "YES" : "NO");
    }    
    return 0;
}