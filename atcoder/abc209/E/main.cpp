// atcoder/abc209/E/main.cpp
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
vec<int> g[N];
int deg[N];

int main(int argc, char *argv[])
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.setf(ios_base::fixed);
  cout.precision(15);

  int n;
  while (cin >> n) {
    fill(g, g + N, vec<int>());
    fill(deg, deg + N, 0);

    vec<str> v(n);
    cin >> v;

    map<str, int> m;
    each (s, v) {
      str a = s.substr(0, 3);
      str b = s.substr(s.size() - 3);
      if (m.count(a) == 0) m[a] = m.size();
      if (m.count(b) == 0) m[b] = m.size();

      g[m[b]].push_back(m[a]);
      ++deg[m[a]];
    }

    const int W = 0;
    const int L = 1;
    const int D = -1;
    vec<int> r(m.size(), D);

    queue<int> q;
    for (int i = 0; i < m.size(); ++i) {
      if (deg[i] == 0) {
        q.push(i);
        r[i] = L;
      }
    }

    for (; q.size(); q.pop()) {
      const int curr = q.front();
      if (r[curr] == L) {
        each (next, g[curr]) {
          unless (r[next] == D) continue;
          r[next] = W;
          q.push(next);
        }
      } else {
        each (next, g[curr]) {
          unless (r[next] == D) continue;
          if (--deg[next] == 0) {
            r[next] = L;
            q.push(next);
          }
        }
      }
    }

    each (s, v) {
      str b = s.substr(s.size() - 3);
      int k = r[m[b]];
      if (k == L) cout << "Takahashi" << endl;
      else if (k == W) cout << "Aoki" << endl;
      else cout << "Draw" << endl;
    }
  }

  return 0;
}