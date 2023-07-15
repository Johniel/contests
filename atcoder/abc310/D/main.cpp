// github.com/Johniel/contests
// atcoder/abc310/D/main.cpp

#include <bits/stdc++.h>

#define each(i, c) for (auto& i : c)
#define unless(cond) if (!(cond))
// #define endl "\n"

using namespace std;

template<typename P, typename Q> ostream& operator << (ostream& os, pair<P, Q> p) { os << "(" << p.first << "," << p.second << ")"; return os; }
template<typename P, typename Q> istream& operator >> (istream& is, pair<P, Q>& p) { is >> p.first >> p.second; return is; }
template<typename T> ostream& operator << (ostream& os, vector<T> v) { os << "("; for (auto& i: v) os << i << ","; os << ")"; return os; }
template<typename T> istream& operator >> (istream& is, vector<T>& v) { for (auto& i: v) is >> i; return is; }
template<typename T> ostream& operator << (ostream& os, set<T> s) { os << "#{"; for (auto& i: s) os << i << ","; os << "}"; return os; }
template<typename K, typename V> ostream& operator << (ostream& os, map<K, V> m) { os << "{"; for (auto& i: m) os << i << ","; os << "}"; return os; }
template<typename E, size_t N> istream& operator >> (istream& is, array<E, N>& a) { for (auto& i: a) is >> i; return is; }
template<typename E, size_t N> ostream& operator << (ostream& os, array<E, N>& a) { os << "[" << N << "]{"; for (auto& i: a) os << i << ","; os << "}"; return os; }

template<typename T> inline T setmax(T& a, T b) { return a = std::max(a, b); }
template<typename T> inline T setmin(T& a, T b) { return a = std::min(a, b); }

__attribute__((constructor)) static void ___initio(void) { ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.setf(ios_base::fixed); cout.precision(15); return ; }

using lli = long long int;
using ull = unsigned long long;
using str = string;
template<typename T> using vec = vector<T>;

constexpr array<int, 8> di({0, 1, -1, 0, 1, -1, 1, -1});
constexpr array<int, 8> dj({1, 0, 0, -1, 1, -1, -1, 1});
constexpr lli mod = 1e9 + 7;
// constexpr lli mod = 998244353;

set<pair<int, int>> taboo;
vec<int> v[10];
int n, T, m;
lli bt(int i)
{
  if (i == n) {
    bool f = true;
    for (int k = 0; k < T; ++k) {
      f = f && v[k].size();
    }
    return f;
  }

  // int e = 0; for (int k = 0; k < T; ++k) e += v[k].empty(); if (n - i < e) return 0;

  lli z = 0;
  for (int k = 0; k < T; ++k) {
    bool f = false;
    each (j, v[k]) {
      f = f || taboo.count(make_pair(i, j));
    }
    unless (f) {
      v[k].push_back(i);
      z += bt(i + 1);
      v[k].pop_back();
    }
    if (v[k].empty()) break;
  }

  return z;
}

int main(int argc, char *argv[])
{
  while (cin >> n >> T >> m) {
    fill(v, v + 10, vec<int>());
    taboo.clear();
    for (int i = 0; i < m; ++i) {
      int a, b;
      cin >> a >> b;
      --a;
      --b;
      taboo.insert(make_pair(min(a, b), max(a, b)));
      taboo.insert(make_pair(max(a, b), min(a, b)));
    }
    lli d = 1;
    for (int i = 0; i < T; ++i) {
      d *= (i + 1);
    }
    lli z = bt(0);
    cout << bt(0) << endl;
    // break;
  }
  return 0;
}
