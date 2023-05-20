// github.com/Johniel/contests
// atcoder/abc302/F/main.cpp

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

const int N = 2 * 1e5 + 10;
const int M = 2 * 1e5 + 10;

const int K = N + M;
vec<int> g[K];

int main(int argc, char *argv[])
{
  int n, m;
  while (cin >> n >> m) {
    fill(g, g + K, vec<int>());

    for (int i = 0; i < n; ++i) {
      int a;
      cin >> a;
      int y = i + N;
      for (int j = 0; j < a; ++j) {
        int x;
        cin >> x;
        --x;
        g[x].push_back(y);
        g[y].push_back(x);
        // cout << make_pair(x+1, char('A'+(y-N))) << endl;
      }
    }

    queue<int> q;
    static int cost[K];
    const int inf = 1 << 29;
    fill(cost, cost + K, inf);
    cost[0] = 0;
    for (q.push(0); q.size(); q.pop()) {
      int curr = q.front();
      each (next, g[curr]) {
        if (cost[next] == inf) {
          cost[next] = cost[curr] + 1;
          q.push(next);
        }
      }
    }
    if (cost[m - 1] == inf) cout << -1 << endl;
    else {
      if (cost[m - 1] == 0) cout << 0 << endl;
      else {
        cout << (cost[m - 1] - 1) / 2 << endl;
      }
    }
  }
  return 0;
}
