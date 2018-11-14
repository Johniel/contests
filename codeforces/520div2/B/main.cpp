#include <bits/stdc++.h>

#define each(i, c) for (auto& i : c)
#define unless(cond) if (!(cond))

using namespace std;

typedef long long int lli;
typedef unsigned long long ull;
typedef complex<double> point;

template<typename P, typename Q> ostream& operator << (ostream& os, pair<P, Q> p) { os << "(" << p.first << "," << p.second << ")"; return os; }
template<typename P, typename Q> istream& operator >> (istream& is, pair<P, Q>& p) { is >> p.first >> p.second; return is; }
template<typename T> ostream& operator << (ostream& os, vector<T> v) { os << "("; each (i, v) os << i << ","; os << ")"; return os; }
template<typename T> istream& operator >> (istream& is, vector<T>& v) { each (i, v) is >> i; return is; }

template<typename T> inline T setmax(T& a, T b) { return a = std::max(a, b); }
template<typename T> inline T setmin(T& a, T b) { return a = std::min(a, b); }

int main(int argc, char *argv[])
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  const int N = 1e6 + 10;
  bool prime[N];
  fill(prime, prime + N, true);
  prime[0] = prime[1] = false;
  for (lli i = 2; i * i < N; ++i) {
    for (lli j = 2; i * j < N; ++j) {
      prime[i * j] = false;
    }
  }
  vector<int> p;
  for (int i = 0; i < N; ++i) {
    if (prime[i]) p.push_back(i);
  }
  
  int n;
  while (cin >> n) {
    if (n == 1) {
      cout << 1 << ' ' << 0 << endl;
      continue;
    }
    map<int, int> cnt;
    each (i, p) {
      while (n % i == 0) {
        ++cnt[i];
        n /= i;
      }
    }
    if (n != 1) ++cnt[n];

    int mx = 0;
    each (i, cnt) {
      for (int j = 0; j < 30; ++j) {
        if (i.second <= (1 << j)) {
          setmax(mx, j);
          break;
        }
      }
    }

    int diff = 0;
    each (i, cnt) {
      diff += (i.second != (1 << mx));
    }

    int x = 1;
    each (i, cnt) x *= i.first;
    cout << x << ' ' << mx + (bool)diff << endl;
  }
  
  return 0;
}
