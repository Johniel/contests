// atcoder/abc128/C/main.cpp
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

  int n, m;
  while (cin >> n >> m) {
    vector<int> v(m, 0);
    for (int i = 0; i < m; ++i) {
      int k;
      cin >> k;
      for (int j = 0; j < k; ++j) {
        int x;
        cin >> x;
        --x;
        v[i] |= (1 << x);
      }
    }
    vector<int> p(m);
    cin >> p;

    int cnt = 0;
    for (int bit = 0; bit < (1 << n); ++bit) {
      bool f = true;
      for (int i = 0; i < v.size(); ++i) {
        int x = __builtin_popcount(bit & v[i]);
        f = f && (x % 2 == p[i]);
      }
      cnt += f;
    }
    cout << cnt << endl;
  }

  return 0;
}
