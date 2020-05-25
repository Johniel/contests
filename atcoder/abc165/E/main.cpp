// atcoder/abc165/E/main.cpp
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
  static bool prime[N];
  fill(prime, prime + N, true);
  prime[0] = prime[1] = false;
  for (int i = 2; i * i < N; ++i) {
    for (int j = 2; i * j < N; ++j) {
      prime[i * j] = false;
    }
  }
  vector<int> p;
  for (int i = 0; i < N; ++i) {
    if (prime[i]) p.push_back(i);
  }
  p.push_back(1);
  sort(p.begin(), p.end());

  int n, m;
  while (cin >> n >> m) {
    vec<int> v;
    each (i, p) {
      if (i < n) v.push_back(i);
      else break;
    }

    vec<pair<lli, lli>> u;
    set<int> vis;
    for (int i = 0, j = 0; u.size() < m; ++i) {
      lli a = i;
      lli b = n - i - 1;
      if (vis.count(a)) continue;
      if (vis.count(b)) continue;
      unless (a < b) swap(a, b);
      if (a != b) {
        ++j;
        u.push_back(make_pair(a, b));
        vis.insert(a);
        vis.insert(b);
      }
    }
    each (i, u) cout << i.first+1 << ' ' << i.second+1 << endl;

    {
      set<pair<lli, lli>> vis;
      for (int i = 0; i < n; ++i) {
        each (j, u) {
          pair<lli, lli> p = j;
          (p.first += i) %= n;
          (p.second += i) %= n;
          unless (p.first < p.second) swap(p.first, p.second);
          cout << i << ' ' << make_pair(p.first+1, p.second+1) << endl;
          assert(vis.count(p) == 0);
          vis.insert(p);
        }
      }
    }
  }

  return 0;
}
