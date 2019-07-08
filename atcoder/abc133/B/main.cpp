// atcoder/abc133/B/main.cpp
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

  int n, d;
  while (cin >> n >> d) {
    vector<vector<int>> v;
    for (int i = 0; i < n; ++i) {
      vector<int> u(d);
      cin >> u;
      v.push_back(u);
    }

    auto fn = [] (int n) {
      for (int i = 0; i * i <= n; ++i) {
        if (i * i == n) {
          return true;
        }
      }
      return false;
    };

    int cnt = 0;
    for (int i = 0; i < v.size(); ++i) {
      for (int j = i + 1; j < v.size(); ++j) {
        int x = 0;
        for (int k = 0; k < v[i].size(); ++k) {
          int a = v[i][k] - v[j][k];
          x += a * a;
        }
        assert(0 <= x);
        cnt += fn(x);
      }
    }
    cout << cnt << endl;
  }

  return 0;
}
