// atcoder/abc236/D/main.cpp
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

const int N = 16;
lli g[N][N];
int n;
vec<lli> v;
lli mx = 0;
void rec(int bit)
{
  if (v.size() == n / 2) {
    lli z = 0;
    each (i, v) z ^= i;
    setmax(mx, z);
    return ;
  }
  for (int i = 0; i < n; ++i) {
    if (bit & (1 << i)) continue;
    for (int j = i + 1; j < n; ++j) {
      if (bit & (1 << j)) continue;
      v.push_back(g[i][j]);
      rec(bit | (1 << i) | (1 << j));
      v.pop_back();
    }
    break;
  }
  return ;
}

int main(int argc, char *argv[])
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.setf(ios_base::fixed);
  cout.precision(15);

  while (cin >> n) {
    n *= 2;
    for (int i = 0; i < n; ++i) {
      for (int j = i + 1; j < n; ++j) {
        cin >> g[i][j];
        g[j][i] = g[i][j];
      }
    }
    v.clear();
    mx = 0;
    rec(0);
    cout << mx << endl;
  }

  return 0;
}
