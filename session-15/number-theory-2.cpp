#include <bits/stdc++.h>
#include <vector>
#include <cmath>

using namespace std;

const int N = 1e6 + 6;

typedef long long ll;

// !(0 <=) a%b < b 
// 0 <= fixMod(a, b) < b
ll fixMod(ll a, ll b) {
  return (a % b + b) % b;
}

// vector<int> getDivisors(int n) {    // O(n)
//     vector<int> ret;
//     for (int i = 1; i <= n/2; i++) {
//         if (n%i == 0) {
//             ret.push_back(i);
//         }
//     }
//     return ret;
// }

vector<int> getDivisors(int n) {    // O(sqrt(n))
  vector<int> ret;
  int i = 1;
  for (i = 1; i * i < n; i++) {
    if (n % i == 0) {
      ret.push_back(i);
      ret.push_back(n / i);
    }
  }

  if (i * i == n) {
    ret.push_back(i);
  }
  return ret;
}

vector<int> getMultiples(int x, int n) {    // O(n/x)
  vector<int> ret;
  for (int m = x; m <= n; m += x) {
    ret.push_back(m);
  }
  return ret;
}

bool isPrime(int n) {   // O(sqrt(n))
  for (int i = 2; i * i <= n; i++) {
    if (n % i == 0) {
      return false;
    }
  }
  return true;
}

bool is_prime[N];
void sieve() {  // O(N) ~= O(N*log(log(N)))
  fill(is_prime, is_prime + N, true);
  is_prime[0] = is_prime[1] = false;

  for (int p = 2; p * p < N; p++) {
    if (is_prime[p]) {
      for (int m = p * p; m < N; m += p) {
        is_prime[m] = false;
      }
    }
  }
}

vector<pair<int, int> > getPrimeFactors(ll n) { // O(sqrt(n))
  vector<pair<int, int> > ret;
  for (int p = 2; p * p <= n; p++) {
    int e = 0;
    while (n % p == 0) {
      n /= p;
      e++;
    }
    if (e > 0) {
      ret.push_back({ p, e });
    }
  }
  if (n > 1) {
    ret.push_back({ n, 1 });
  }
  return ret;
}

// LCM * GCD = a * b
ll LCM(ll a, ll b) {
  // return (a*b)/__gcd(a, b);
  return a * (b / __gcd(a, b));
}

/*
    Modular Arithmetic
    (a + b) % m = (a % m + b % m) % m
    (a - b) % m = (a % m - b % m) % m
    (a * b) % m = ((a % m) * (b % m)) % m
*/

void printVector(vector<int> v) {
  for (int i = 0; i < v.size(); i++) {
    printf("%d%c", v[i], " \n"[i + 1 == v.size()]);
  }
}

int main() {
  printf("%d\n", __gcd(24, 36));
  return 0;
}