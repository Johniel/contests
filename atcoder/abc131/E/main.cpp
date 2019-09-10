// atcoder/abc131/E/main.cpp
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

  int n, k;
  while (cin >> n >> k) {
    vector<pair<int, int>> v;
    for (int i = 1; i < n; ++i) {
      v.push_back({0, i});
    }
    vector<pair<int, int>> u;
    for (int i = 1; i < n; ++i) {
      for (int j = i + 1; j < n; ++j) {
        u.push_back({i, j});
      }
    }
    int x = (n - 1) * (n - 2) / 2;
    while (k < x && u.size()) {
      v.push_back(u.back());
      u.pop_back();
      --x;
    }
    if (x != k) cout << -1 << endl;
    else {
      cout << v.size() << endl;
      each (i, v) cout << i.first + 1 << ' ' << i.second + 1 << endl;
    }
  }

  return 0;
}
