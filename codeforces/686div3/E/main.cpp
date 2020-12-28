// codeforces/686div3/E/main.cpp
// author: @___Johniel
// github: https://github.com/johniel/

#include <bits/stdc++.h>

#define each(i, c) for (auto& i : c)
#define unless(cond) if (!(cond))

using namespace std;

template<typename P, typename Q> ostream& operator << (ostream& os, pair<P, Q> p) { os << "(" << p.first << "," << p.second << ")"; return os; }
template<typename P, typename Q> istream& operator >> (istream& is, pair<P, Q>& p) { is >> p.first >> p.second; return is; }
template<typename T> ostream& operator << (ostream& os, vector<T> v) { os << "("; for (auto& i: v) os << i << ","; os << ")"; return os; }
template<typename T> istream& operator >> (istream& is, vector<T>& v) { for (auto& i: v) is >> i; return is; }
template<typename T> ostream& operator << (ostream& os, set<T> s) { os << "#{"; for (auto& i: s) os << i << ","; os << "}"; return os; }
template<typename K, typename V> ostream& operator << (ostream& os, map<K, V> m) { os << "{"; for (auto& i: m) os << i << ","; os << "}"; return os; }

template<typename T> inline T setmax(T& a, T b) { return a = std::max(a, b); }
template<typename T> inline T setmin(T& a, T b) { return a = std::min(a, b); }

using lli = long long int;
using ull = unsigned long long;
using point = complex<double>;
using str = string;
template<typename T> using vec = vector<T>;

constexpr array<int, 8> di({0, 1, -1, 0, 1, -1, 1, -1});
constexpr array<int, 8> dj({1, 0, 0, -1, 1, -1, -1, 1});
constexpr lli mod = 1e9 + 7;

const int N = 2 * 1e5 + 5;
set<int> g[N];

int main(int argc, char *argv[])
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.setf(ios_base::fixed);
  cout.precision(15);

  int _;
  cin >> _;

  int n;
  while (cin >> n) {
    fill(g, g + n, set<int>());
    for (int i = 0; i < n; ++i) {
      int a, b;
      cin >> a >> b;
      --a;
      --b;
      g[a].insert(b);
      g[b].insert(a);
    }

    vec<int> v;
    for (int i = 0; i < n; ++i) {
      if (g[i].size() == 1) v.push_back(i);
    }

    vec<lli> u(n, 1);
    while (!v.empty()) {
      int x = v.back();
      v.pop_back();
      int y = *g[x].begin();
      u[y] += u[x];
      u[x] = 0;
      g[y].erase(x);
      if (g[y].size() == 1) {
        v.push_back(y);
      }
    }

    lli z = 0;
    for (int i = 0; i < n; ++i) {
      z += u[i] * (n - u[i]);
      z += u[i] * (u[i] - 1) / 2;
    }
    cout << z << endl;
  }

  return 0;
}
