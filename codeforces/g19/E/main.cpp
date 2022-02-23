// codeforces/g19/E/main.cpp
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

  int _;
  cin >> _;

  int n, m;
  while (cin >> n >> m) {
    vec<lli> a(n);
    // cin >> a;
    // sort(a.begin(), a.end());
    map<lli, lli> cnt;
    // each (i, a) ++cnt[i];
    each (i, a) {
      cin >> i;
      ++cnt[i];
    }

    vec<pair<lli, lli>> taboo;
    for (int i = 0; i < m; ++i) {
      int a, b;
      cin >> a >> b;
      taboo.emplace_back(make_pair(a, b));
      taboo.emplace_back(make_pair(b, a));
      // taboo.push_back({a, b});
      // taboo.push_back({b, a});
    }
    sort(taboo.begin(), taboo.end());

    vector<lli> occ[n+1];
    each (i, cnt) {
      occ[i.first].push_back(i.second);
    }
    for (int i = 0; i <= n; ++i) {
      reverse(occ[i].begin(), occ[i].end());
    }

    lli z = 0;
    for (int cntx = 0; cntx <= n; ++cntx) {
      each (x, occ[cntx]) {
        for (int cnty = 0; cnty <= cntx; ++cnty) {
          each (y, occ[cnty]) {
            if (x != y && !binary_search(taboo.begin(), taboo.end(), make_pair(x, y))) {
              setmax(z, (x + y) * (cntx + cnty));
              break;
            }
          }
        }
      }
    }
    cout << z << "\n";
  }

  return 0;
}
