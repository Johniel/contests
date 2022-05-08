// atcoder/abc244/G/main.cpp
// author: @___Johniel
// github: https://github.com/johniel/

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
// constexpr lli mod = 998244353;

int main(int argc, char *argv[])
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.setf(ios_base::fixed);
  cout.precision(15);

  int n, m;
  string s;
  while (cin >> n >> m) {
    const int N = 2 * 1e5 + 3;
    vec<int> g[N];
    for (int i = 0; i < m; ++i) {
      int a, b;
      cin >> a >> b;
      --a;
      --b;
      g[a].push_back(b);
      g[b].push_back(a);
    }
    cin >> s;
    int cnt[N];
    fill(cnt, cnt + N, 0);
    vec<int> v;
    function<void(int, int)> rec = [&] (int curr, int prev) {
      ++cnt[curr];
      v.push_back(curr);
      each (next, g[curr]) {
        if (next == prev || cnt[next]) continue;
        rec(next, curr);
        v.push_back(curr);
        ++cnt[curr];
        if ((s[next] - '0') % 2 != cnt[next] % 2) {
          v.push_back(next);
          ++cnt[next];
          v.push_back(curr);
          ++cnt[curr];
        }
      }
      return ;
    };
    rec(0, 0);
    if ((s[0] - '0') % 2 != cnt[0] % 2) {
      --cnt[v.back()];
      v.pop_back();
    }

    cout << v.size() << endl;
    each (i, v) cout << i + 1 << ' '; cout << endl;

    for (int i = 0; i < n; ++i) {
      assert((s[i] - '0') % 2 == cnt[i] % 2);
    }
  }

  return 0;
}
