#include <cstdio>
#include <vector>
#include <cmath>

using namespace std;

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
    for (i = 1; i*i < n; i++) {
        if (n%i == 0) {
            ret.push_back(i);
            ret.push_back(n/i);
        }
    }

    if (i*i == n) {
        ret.push_back(i);
    }
    return ret;
}

vector<int> getMultiples(int x, int n) {    // O(n/x)
    vector<int> ret;
    for (int m = x; m <= n; m+=x) {
        ret.push_back(m);
    }
    return ret;
}

bool isPrime(int n) {   // O(sqrt(n))
    for (int i = 2; i*i <= n; i++) {
        if (n % i == 0) {
            return false;
        }
    }
    return true;
}

void printVector(vector<int> v) {
    for(int i = 0; i < v.size(); i++) {
        printf("%d%c", v[i], " \n"[i+1 == v.size()]);
    }
}

int main() {
    printf("%d\n", isPrime(37));
    printf("%d\n", getDivisors(37).size() == 2);
    return 0;
}