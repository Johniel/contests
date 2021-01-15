// codeforces/e102/E/main.cpp
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

  int n, m;
  while (cin >> n >> m) {
    vec<pair<int, int>> g[n];
    for (int i = 0; i < m; ++i) {
      int a, b, c;
      cin >> a >> b >> c;
      --a;
      --b;
      g[a].push_back(make_pair(b, c));
      g[b].push_back(make_pair(a, c));
    }

    const int N = 2 * 1e5 + 5;
    static lli w[N][4];
    const lli inf = 1LL << 60;
    fill(&w[0][0], &w[N - 1][3 - 1] + 1, inf);
    w[0][0] = 0;

    priority_queue<vec<lli>> q;
    q.push({0, 0, 0});
    while (q.size()) {
      auto v = q.top();
      q.pop();
      const int curr = v[2];
      const lli c = abs(v[0]);
      const int s = v[1];
      if (w[curr][s] != c) continue;
      each (e, g[curr]) {
        const int next = e.first;
        const lli cost = e.second;
        {
          auto p = c + cost;
          int ns = s;
          if (w[next][ns] > p) {
            w[next][ns] = p;
            q.push({-w[next][ns], ns, next});
          }
        }
        {
          auto p = c + cost + cost;
          int ns = s | (1 << 0);
          if (!(s & (1 << 0)) && w[next][ns] > p) {
            w[next][ns] = p;
            q.push({-w[next][ns], ns, next});
          }
        }
        {
          auto p = c;
          int ns = s | (1 << 1);
          if (!(s & (1 << 1)) && w[next][ns] > p) {
            w[next][ns] = p;
            q.push({-w[next][ns], ns, next});
          }
        }
      }
    }
    for (int i = 1; i < n; ++i) {
      cout << min(w[i][0], w[i][3]) << ' ';
    }
    cout << endl;
  }

  return 0;
}
