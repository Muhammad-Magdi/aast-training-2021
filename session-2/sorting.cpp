#include <iostream>
#include <algorithm>

using namespace std;

const int N = 1e6 + 2;

int n;
int A[N];

// 1 sec ~= 10^8 Operations
// 10^4 sec ~= 10^12 Operations

void merge(int* A, int szA, int* B, int szB) {  // O(szA + szB)
  int* C = new int[szA + szB];  // Dynamic Allocation - Runtime
  // int C[szA + szB];
  int idxA = 0, idxB = 0, idxC = 0;
  while (idxA < szA && idxB < szB) {
    C[idxC++] = (A[idxA] < B[idxB] ? A[idxA++] : B[idxB++]);
  }
  while (idxA < szA) {
    C[idxC++] = A[idxA++];
  }
  while (idxB < szB) {
    C[idxC++] = B[idxB++];
  }

  for (int i = 0; i < szA+szB; i++) {
    // cout << C[i] << endl;
    A[i] = C[i];
  }

  delete [] C;
}

void mergeSort(int* A, int sz) {
  if (sz < 2) {
    return;
  }
  int half = sz/2;
  mergeSort(A, half);  // Sorts first half
  mergeSort(A+half, sz - half); // Sorts second half
  merge(A, half, A+half, sz - half);  // Combine the two sorted arrays into one
}

int main() {
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> A[i];
  }

  // for (int i = 0; i < n; i++) {
  //   for (int j = i; j < n; j++) {
  //     if (A[j] < A[i]) {
  //       int tmp = A[i];
  //       A[i] = A[j];
  //       A[j] = tmp;
  //     }
  //   }
  // }

  // mergeSort(A, n);

  sort(A, A+n); // O(n*log(n)) - Intro Sort - hybrid Algorithm

  for (int i = 0; i < n; i++) {
    cout << A[i] << " \n"[i==n-1];
  }
  return 0;
}