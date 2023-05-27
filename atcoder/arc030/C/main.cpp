// github.com/Johniel/contests
// atcoder/arc030/C/main.cpp

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

namespace SCC {
  // https://atcoder.jp/contests/typical90/tasks/typical90_u

  const int N = 300 + 4;
  bool vis[N];

  void rec(vec<int> graph[N], int curr, int ord[], int &cnt)
  {
    vis[curr] = true;
    for (auto& next : graph[curr]) {
      unless (vis[next]) rec(graph, next, ord, cnt);
    }
    ord[--cnt] = curr;
    return ;
  }

  vector<int> g[N];
  vector<int> h[N];
  void init(const int size)
  {
    fill(g, g + size, vector<int>());
  }

  int ord[N];
  int scc[N];
  vector<vector<int>> detect_scc(const int size)
  {
    int cnt, prev = size - 1;
    vector<vector<int>> ret;
    fill(ord, ord + size, -1);
    fill(scc, scc + size, -1);
    fill(h, h + size, vector<int>());
    for (int curr = 0; curr < size; ++curr) {
      for (const auto& next : g[curr]) {
        h[next].push_back(curr);
      }
    }
    cnt = size;
    fill(vis, vis + size, false);
    for (int i = 0; i < size; ++i) {
      unless (vis[i]) rec(g, i, ord, cnt);
    }
    cnt = size;
    fill(vis, vis + size, false);
    for (int i = 0; i < size; ++i) {
      unless (vis[ord[i]]) {
        rec(h, ord[i], scc, cnt);
        int j = prev;
        vector<int> T;
        for (j = prev; 0 <= j && scc[j] != -1; --j) T.push_back(scc[j]);
        prev = j;
        ret.push_back(T);
      }
    }
    return ret;
  }
};

const int N = 300 + 3;
vec<int> g[N];
vec<int> h[N];

int main(int argc, char *argv[])
{
  int n, m, K;
  while (cin >> n >> m >> K) {
    vec<char> symbols(n);
    cin >> symbols;
    fill(g, g + N, vec<int>());
    SCC::init(n);
    for (int i = 0; i < m; ++i) {
      int a, b;
      cin >> a >> b;
      --a;
      --b;
      g[a].push_back(b);
      SCC::g[a].push_back(b);
    }
    vec<vec<int>> scc = SCC::detect_scc(n);

    map<int, int> rename;
    {
      for (int i = 0; i < scc.size(); ++i) {
        each (j, scc[i]) rename[j] = i;
      }
      fill(h, h + N, vec<int>());
      set<pair<int, int>> vis;
      for (int i = 0; i < n; ++i) {
        each (j, g[i]) {
          int a = rename[i];
          int b = rename[j];
          if (a != b && !vis.count(make_pair(a, b))) h[a].push_back(b);
          vis.insert(make_pair(a, b));
        }
      }
    }

    vec<str> v(scc.size()+1);
    {
      for (int i = 0; i < scc.size(); ++i) {
        each (j, scc[i]) v[i] += symbols[j];
        sort(v[i].begin(), v[i].end());
      }
    }

    static bool r[N][N];
    {
      fill(&r[0][0], &r[N - 1][N - 1] + 1, false);
      for (int i = 0; i < scc.size(); ++i) {
        r[i][i] = true;
      }
      for (int i = 0; i < scc.size(); ++i) {
        each (j, h[i]) r[i][j] = true;
      }
      for (int k = 0; k < scc.size(); ++k) {
        for (int i = 0; i < scc.size(); ++i) {
          for (int j = 0; j < scc.size(); ++j) {
            r[i][j] = r[i][j] || (r[i][k] && r[k][j]);
          }
        }
      }
    }

    static str dp[N][N]; // [何文字目][今どこ]
    const str infstr = str(1, max('z', 'Z') + 1);
    fill(&dp[0][0], &dp[N - 1][N - 1], infstr);
    const int src = scc.size();
    dp[0][src] = "";
    for (int i = 0; i < scc.size(); ++i) {
      r[src][i] = true;
    }
    for (int len = 0; len < K; ++len) {
      for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
          if (i == j || !r[i][j]) continue;
          str t;
          for (int k = 0; k < v[j].size(); ++k) {
            t += v[j][k];
            if (len + t.size() < N) {
              setmin(dp[len + t.size()][j], dp[len][i] + t);
            }
          }
        }
      }
    }
    str mn = infstr;
    for (int i = 0; i < scc.size(); ++i) {
      setmin(mn, dp[K][i]);
    }
    if (mn == infstr) mn = "-1";
    cout << mn << endl;
  }
  return 0;
}
