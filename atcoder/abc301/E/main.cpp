// github.com/Johniel/contests
// atcoder/abc301/E/main.cpp

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
constexpr lli mod = 1e9 + 7;
// constexpr lli mod = 998244353;

const int H = 300 + 2;
const int W = 300 + 2;
char g[H][W];
int h, w;
vec<pair<int, int>> pos;

const int M = 21;
int adj[M][M];
const int inf = 1 << 29;
void fn(const int src)
{
  static int cost[H][W];
  fill(&cost[0][0], &cost[H -1][W - 1] + 1, inf);

  cost[pos[src].first][pos[src].second] = 0;
  adj[src][src] = 0;

  queue<pair<int, int>> q;
  for (q.push(pos[src]); q.size(); q.pop()) {
    pair<int, int> curr = q.front();
    const int di[] = {0, 0, -1, +1};
    const int dj[] = {-1, +1, 0, 0};
    for (int dir = 0; dir < 4; ++dir) {
      const int ni = curr.first + di[dir];
      const int nj = curr.second + dj[dir];
      unless (0 <= ni && ni < h) continue;
      unless (0 <= nj && nj < w) continue;
      if (g[ni][nj] == '#') continue;
      if (cost[ni][nj] != inf) continue;
      q.push(make_pair(ni, nj));
      cost[ni][nj] = cost[curr.first][curr.second] + 1;
    }
  }

  for (int i = 0; i < pos.size(); ++i) {
    adj[src][i] = cost[pos[i].first][pos[i].second];
  }
  return ;
}

int main(int argc, char *argv[])
{
  int k;
  while (cin >> h >> w >> k) {
    pos.clear();
    pair<int, int> s, t;
    for (int i = 0; i < h; ++i) {
      for (int j = 0; j < w; ++j) {
        cin >> g[i][j];
        if (g[i][j] == 'o') pos.push_back(make_pair(i, j));
        if (g[i][j] == 'S') s = make_pair(i, j);
        if (g[i][j] == 'G') t = make_pair(i, j);
      }
    }
    pos.insert(pos.begin(), s);
    pos.push_back(t);

    fill(&adj[0][0], &adj[M - 1][M - 1] + 1, inf);
    for (int i = 0; i < pos.size(); ++i) {
      fn(i);
    }

    const int src = 0;
    const int dst = pos.size() - 1;
    const int B = (1 << M);
    static lli dp[B][M];
    fill(&dp[0][0], &dp[B - 1][M - 1] + 1, inf);
    dp[1 << src][src] = 0;
    for (int bit = 0; bit < (1 << pos.size()); ++bit) {
      for (int curr = 0; curr < pos.size(); ++curr) {
        unless (bit & (1 << curr)) continue;
        for (int next = 0; next < pos.size(); ++next) {
          if (bit & (1 << next)) continue;
          if (adj[curr][next] != inf) {
            setmin(dp[bit | (1 << next)][next], dp[bit][curr] + adj[curr][next]);
          }
        }
      }
    }

    int z = -1;
    for (int bit = 0; bit < (1 << pos.size()); ++bit) {
      unless (bit & (1 << dst)) continue;
      unless (bit & (1 << src)) continue;
      if (dp[bit][dst] <= k) {
        setmax(z, __builtin_popcount(bit) - 2);
      }
    }
    cout << z << endl;
  }
  return 0;
}
