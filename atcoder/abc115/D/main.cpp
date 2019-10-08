// atcoder/abc115/D/main.cpp
// author: @___Johniel
// github: https://github.com/johniel/

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

  const int N = 100;
  ull P[N];
  ull PB[N];

  PB[0] = 1;
  P[0] = 1;
  for (int i = 1; i < N; ++i) {
    P[i] = P[i - 1] + 1 + P[i - 1];
    PB[i] = 1 + PB[i - 1] + 1 + PB[i - 1] + 1;
  }

  int n;
  ull x;
  while (cin >> n >> x) {
    ull sum = 0;
    while (true) {
      if (n == 0) {
        ++sum;
        break;
      }

      if (x == 1) {
        break;
      } else if (x <= 1 + PB[n - 1]) {
        --x;
        --n;
      } else if (x <= 1 + PB[n - 1] + 1) {
        sum += P[n - 1] + 1;
        break;
      } else if (x <= 1 + PB[n - 1] + 1 + PB[n - 1]) {
        sum += P[n - 1] + 1;
        x -= 1 + PB[n - 1] + 1;
        --n;
      } else {
        sum += P[n - 1] + 1 + P[n - 1];
        break;
      }
    }
    cout << sum << endl;
  }

  return 0;
}
