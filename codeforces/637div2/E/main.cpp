// codeforces/637div2/E/main.cpp
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
    const int N = 1e4 + 5;
    const int M = 1000 + 5;
    int g, r;
    vec<int> v(m);
    cin >> v >> g >> r;
    sort(v.begin(), v.end());

    const lli inf = 1LL << 60;
    static lli cost[N][M];
    fill(&cost[0][0], &cost[N - 1][M - 1] + 1, inf);

    lli x = -1;

    priority_queue<pair<lli, pair<int, int>>> q;

    q.push(make_pair(0, make_pair(0, 0)));
    cost[0][0] = 0;

    while (q.size()) {
      auto p = q.top();
      q.pop();
      lli c = -1 * p.first;
      int a = p.second.first;
      int b = p.second.second;
      if (cost[a][b] != c) continue;
      if (a == m - 1) {
        x = c;
        break;
      }
      if (b == g) {
        if (cost[a][0] > cost[a][b] + r) {
          cost[a][0] = cost[a][b] + r;
          q.push(make_pair(-cost[a][0], make_pair(a, 0)));
        }
        continue;
      }
      for (int d = -1; d <= +1; ++d) {
        const int na = a + d;
        unless (0 <= na && na < n) continue;
        const int y = abs(v[a] - v[na]);
        if (b + y <= g && cost[na][b + y] > cost[a][b] + y) {
          cost[na][b + y] = cost[a][b] + y;
          q.push(make_pair(-cost[na][b + y], make_pair(na, b + y)));
        }
      }
    }

    cout << x << endl;
  }

  return 0;
}
