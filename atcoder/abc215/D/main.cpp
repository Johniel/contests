// atcoder/abc215/D/main.cpp
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

  const int N = 1e5 + 5;
  int n, m;
  while (cin >> n >> m) {
    vec<lli> a(n);
    cin >> a;

    sort(a.begin(), a.end());
    a.erase(unique(a.begin(), a.end()), a.end());

    static bool vis[N];
    fill(vis, vis + N, true);
    each (i, a) vis[i] = false;

    static bool f[N];
    fill(f, f + N, true);
    for (int i = 2; i < N; ++i) {
      vec<int> b;
      bool g = true;
      for (int j = i; j < N; j += i) {
        b.push_back(j);
        g = g && vis[j];
      }
      if (!g) each (j, b) f[j] = false;
    }

    vec<int> v;
    for (int i = 1; i <= m; ++i) {
      if (f[i]) v.push_back(i);
    }
    cout << v.size() << endl;
    each (i, v) cout << i << endl;
  }

  return 0;
}
