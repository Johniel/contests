// atcoder/donuts-2015/B/main.cpp
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

const int M = 55;
vec<pair<int, int>> w;
set<int> v;
vec<lli> a;

lli rec(int idx, lli sum)
{
  if (v.size() == 9) {
    int bit = 0;
    each (i, v) bit += (1 << i);
    each (i, w) {
      if (3 <= __builtin_popcount(i.second & bit)) {
        sum += i.first;
      }
    }
    return sum;
  }
  if (16 <= v.size()) return 0;

  lli mx = 0;
  for (int i = idx; i < a.size(); ++i) {
    v.insert(i);
    setmax(mx, rec(i + 1, sum + a[i]));
    v.erase(i);
  }

  return mx;
}

int main(int argc, char *argv[])
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.setf(ios_base::fixed);
  cout.precision(15);

  int n, m;
  while (cin >> n >> m) {
    w.clear();
    v.clear();
    a.resize(n);
    cin >> a;
    for (int i = 0; i < m; ++i) {
      int x, y;
      cin >> x >> y;
      w.push_back({x, 0});
      for (int j = 0; j < y; ++j) {
        cin >> x;
        w[i].second += (1 << (x - 1));
      }
    }
    v.clear();
    cout << rec(0, 0) << endl;
  }

  return 0;
}
