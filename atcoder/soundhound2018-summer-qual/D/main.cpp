// atcoder/soundhound2018-summer-qual/D/main.cpp
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

const int N = 1e5 + 5;
vec<pair<int, pair<int, int>>> g[N];

int main(int argc, char *argv[])
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.setf(ios_base::fixed);
  cout.precision(15);

  int n, m, s, t;
  while (cin >> n >> m >> s >> t) {
    --s;
    --t;
    for (int i = 0; i < N; ++i) {
      g[i].clear();
    }
    for (int i = 0; i < m; ++i) {
      int a, b, c, d;
      cin >> a >> b >> c >> d;
      --a;
      --b;
      g[a].push_back(make_pair(b, make_pair(c, d)));
      g[b].push_back(make_pair(a, make_pair(c, d)));
    }

    static lli cost1[N];
    static lli cost2[N];
    const lli inf = 1LL << 60;
    fill(cost1, cost1 + N, inf);
    fill(cost2, cost2 + N, inf);

    {
      priority_queue<pair<lli, int>> q;
      q.push(make_pair(0, s));
      cost1[s] = 0;
      while (q.size()) {
        auto p = q.top();
        q.pop();
        int curr = p.second;
        auto c = -1 * p.first;
        if (cost1[curr] != c) continue;
        each (i, g[curr]) {
          auto d = cost1[curr] + i.second.first;
          if (cost1[i.first] > d) {
            cost1[i.first] = d;
            q.push(make_pair(-d, i.first));
          }
        }
      }
    }

    {
      priority_queue<pair<lli, int>> q;
      q.push(make_pair(0, t));
      cost2[t] = 0;
      while (q.size()) {
        auto p = q.top();
        q.pop();
        int curr = p.second;
        auto c = -1 * p.first;
        if (cost2[curr] != c) continue;
        each (i, g[curr]) {
          auto d = cost2[curr] + i.second.second;
          if (cost2[i.first] > d) {
            cost2[i.first] = d;
            q.push(make_pair(-d, i.first));
          }
        }
      }
    }

    vec<lli> v;
    for (int i = 0; i < n; ++i) {
      v.push_back(cost1[i] + cost2[i]);
    }
    for (int i = n - 2; 0 <= i; --i) {
      setmin(v[i], v[i + 1]);
    }
    const lli x = 1000000000000000LL;
    each (i, v) cout << x - i << endl;
  }

  return 0;
}
