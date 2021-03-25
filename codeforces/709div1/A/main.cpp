// codeforces/709div1/A/main.cpp
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
    const int N = 1e5 + 3;
    const int M = 1e5 + 3;
    static vec<int> deg[M];
    fill(deg, deg + m, vec<int>());
    for (int i = 0; i < m; ++i) {
      int k;
      cin >> k;
      for (int j = 0; j < k; ++j) {
        int f;
        cin >> f;
        deg[i].push_back(f - 1);
      }
    }
    vec<int> w;
    for (int i = 0; i < m; ++i) {
      w.push_back(i);
    }
    sort(w.begin(), w.end(), [&] (auto i, auto j) { return deg[i].size() < deg[j].size(); });
    int cnt[n];
    fill(cnt, cnt + n, 0);
    bool f = true;
    vec<int> r(m, -1);
    each (i, w) {
      while (true) {
        if (deg[i].empty()) {
          f = false;
          break;
        }
        int j = deg[i].back();
        deg[i].pop_back();
        if ((m+1) / 2 <= cnt[j]) continue;
        r[i] = j;
        ++cnt[j];
        break;
      }
    }
    if (f) {
      cout << "YES" << endl;
      each (i, r) cout << i+1 << ' '; cout << endl;
    } else {
      cout << "NO" << endl;
    }
  }

  return 0;
}
