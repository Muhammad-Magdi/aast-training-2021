#include <bits/stdc++.h>

using namespace std;

const int N = 1e6+6;

typedef long long ll;

ll fact(ll n) { // O(n)
  if (n == 1 || n == 0) return 1;
  return n * fact(n-1);
}

ll fib(ll n) {  // O(2^n)
  if (n == 1 || n == 2) return 1;
  return fib(n-1) + fib(n-2);
}

ll power(ll a, ll b) { // O(b)
  if (b == 0) return 1;
  return a * power(a, b-1);
}

// Fast Power, Fast Exponentiation
ll fPower(ll a, ll b) {  // O(log(b))
  if (b == 0) return 1;
  ll p = fPower(a, b>>1);
  return (b&1) ? p*p*a : p*p;
}

// Euclidean Algorithm
ll GCD(ll a, ll b) {  // O(log(n))
  if (b == 0) return a;
  return GCD(b, a%b);
}

// GCD * LCM = a * b
ll LCM(ll a, ll b){
  return a * (b / GCD(a, b));
}

int C[N];
// Assuming that A, B are consecutive => endA = beginB
void merge(int* beginA, int* beginB, int* endB) { // O(n)
  int szA = beginB - beginA;
  int szB = endB - beginB;
  int idxA = 0, idxB = 0, idxC = 0;
  while (idxA < szA && idxB < szB) {
    if (beginA[idxA] < beginB[idxB])  C[idxC++] = beginA[idxA++];
    else C[idxC++] = beginB[idxB++];
  }

  while (idxA < szA) C[idxC++] = beginA[idxA++];
  while (idxB < szB) C[idxC++] = beginB[idxB++];

  copy(C, C+idxC, beginA);
}

// Sorts [begin, end[
void mergeSort(int* begin, int* end) {  // O(n*log(n))
  int n = end - begin;
  if (n == 1) return;
  mergeSort(begin, begin + n/2);
  mergeSort(begin + n/2, end);
  merge(begin, begin + n/2, end);
}

int n;
int A[N];
int main() {
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> A[i];
  }
  mergeSort(A, A+n);
  for (int i = 0; i < n; i++) {
    cout <<  A[i] << " \n"[i+1==n];
  }
  return 0;
}