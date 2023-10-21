// github.com/Johniel/contests
// atcoder/abc325/E/main.cpp

#include <bits/stdc++.h>

#define each(i, c) for (auto& i : c)
#define each_with_index(i, e, c) for (const auto i: views::iota(0, (int)c.size())) if (auto& e = c.at(i); true)
#define each_pair(p, c) for (const auto _i: views::iota(0, (int)c.size())) if (std::pair<const int, decltype((c.at(_i)))> p = {_i, c[_i]}; true)
#define unless(cond) if (!(cond))
// #define endl "\n"

using namespace std;

template<typename P, typename Q> ostream& operator << (ostream& os, pair<P, Q> p) { os << "(" << p.first << "," << p.second << ")"; return os; }
template<typename P, typename Q> istream& operator >> (istream& is, pair<P, Q>& p) { is >> p.first >> p.second; return is; }
template<typename T> ostream& operator << (ostream& os, vector<T> v) { os << "("; for (auto& i: v) os << i << ","; os << ")"; return os; }
template<typename T> istream& operator >> (istream& is, vector<T>& v) { for (auto& i: v) is >> i; return is; }
template<typename T> ostream& operator << (ostream& os, set<T> s) { os << "#{"; for (auto& i: s) os << i << ","; os << "}"; return os; }
template<typename K, typename V> ostream& operator << (ostream& os, map<K, V> m) { os << "{"; for (auto& i: m) os << i << ","; os << "}"; return os; }
template<typename E, size_t N> istream& operator >> (istream& is, array<E, N>& a) { for (auto& i: a) is >> i; return is; }
template<typename E, size_t N> ostream& operator << (ostream& os, array<E, N>& a) { os << "[" << N << "]{"; for (auto& i: a) os << i << ","; os << "}"; return os; }

template<typename T> inline T setmax(T& a, T b) { return a = std::max(a, b); }
template<typename T> inline T setmin(T& a, T b) { return a = std::min(a, b); }

__attribute__((constructor)) static void ___initio(void) { ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.setf(ios_base::fixed); cout.precision(15); return ; }

using lli = long long int;
using ull = unsigned long long;
using str = string;
template<typename T> using vec = vector<T>;

constexpr array<int, 8> di({0, 1, -1, 0, 1, -1, 1, -1});
constexpr array<int, 8> dj({1, 0, 0, -1, 1, -1, -1, 1});
// constexpr lli mod = 1e9 + 7;
constexpr lli mod = 998244353;

int main(int argc, char *argv[])
{
  int n;
  lli a, b, c;
  while (cin >> n >> a >> b >> c) {
    // 車
    // 電車
    // 車->電車
    const int N = 1000 + 3;
    static int d[N][N];
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j) {
        cin >> d[i][j];
      }
    }
    const int M = 2;
    static lli dist[N][M];
    const lli inf = 1LL << 61;
    fill(&dist[0][0], &dist[N - 1][M - 1] + 1, inf);
    const int C = 0;
    const int T = 1;
    priority_queue<pair<lli, pair<int, int>>> q;
    dist[0][C] = dist[0][T] = 0;
    q.push(make_pair(0, make_pair(0, C)));
    q.push(make_pair(0, make_pair(0, T)));
    while (q.size()) {
      auto p = q.top();
      q.pop();
      lli cost = abs(p.first);
      int curr = p.second.first;
      int type = p.second.second;
      if (dist[curr][type] != cost) continue;
      for (int next = 0; next < n; ++next) {
        lli w = inf;
        if (0) ;
        else if (type == C) w = d[curr][next] * a;
        else if (type == T) w = d[curr][next] * b + c;
        else assert(0);
        if (dist[next][type] > dist[curr][type] + w) {
          dist[next][type] = dist[curr][type] + w;
          q.push(make_pair(-dist[next][type], make_pair(next, type)));
        }
      }
      if (dist[curr][T] > dist[curr][C]) {
        dist[curr][T] = dist[curr][C];
        q.push(make_pair(-dist[curr][T], make_pair(curr, T)));
      }
    }
    cout << min(dist[n - 1][C], dist[n - 1][T]) << endl;
  }
  return 0;
}
