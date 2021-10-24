// atcoder/abc224/E/main.cpp
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

int main(int argc, char *argv[])
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.setf(ios_base::fixed);
  cout.precision(15);

  int h, w, n;
  while (cin >> h >> w >> n) {
    vec<vec<int>> v(n, vec<int>(3, -1));
    cin >> v;
    const auto u = v;
    sort(v.begin(), v.end(), [] (auto a, auto b) { return a.back() < b.back(); });
    reverse(v.begin(), v.end());
    map<int, int> mxh, mxw;
    each (i, v) {
      mxh[i[0]] = -1;
      mxw[i[1]] = -1;
    }
    map<vec<int>, int> m;
    for (int i = 1; i < v.size(); ++i) {
      if (v[i].back() != v[i - 1].back()) {
        map<int, int> a, b;
        for (int j = i - 1; 0 <= j && v[i - 1].back() == v[j].back(); --j) {
          int z = -mod;
          if (mxh.count(v[j][0])) setmax(z, mxh[v[j][0]] + 1);
          if (mxw.count(v[j][1])) setmax(z, mxw[v[j][1]] + 1);
          setmax(a[v[j][0]], z);
          setmax(b[v[j][1]], z);
        }
        each (i, a) setmax(mxh[i.first], i.second);
        each (i, b) setmax(mxw[i.first], i.second);
      }
      m[v[i]] = max(mxh[v[i][0]], mxw[v[i][1]]) + 1;
    }
    each (i, u) cout << max(0, m[i]) << endl;
  }

  return 0;
}
