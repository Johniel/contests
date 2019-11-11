// atcoder/abc035/C/main.cpp
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

  int n, q;
  while (cin >> n >> q) {
    const int N = 200000 * 2 + 5;
    int v[N];
    fill(v, v + N, 0);
    for (int i = 0; i < q; ++i) {
      int a, b;
      cin >> a >> b;
      a *= 2;
      b *= 2;
      ++v[a];
      --v[b + 1];
    }
    int sum = 0;
    for (int i = 1; i <= n*2; ++i) {
      sum += v[i];
      if (i % 2 == 0) {
        cout << sum%2;
      }
    }
    cout << endl;
  }

  return 0;
}
