// github.com/Johniel/contests
// atcoder/abc306/G/main.cpp

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

  const int N = 2 * 1e5 + 3;
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

int ord[SCC::N];
set<int> same;
set<int> vis;
vec<lli> r;
void rec(int curr, int depth)
{
  vis.insert(curr);
  ord[curr] = depth++;
  each (next, SCC::g[curr]) {
    unless (same.count(next)) continue;
    if (vis.count(next)) {
      r.push_back(abs(ord[next] - (depth + 1)));
    } else {
      rec(next, depth + 1);
    }
  }
  return ;
}

int main(int argc, char *argv[])
{
  // SCCをDFSした深さの差を見るとサイクルの長さを列挙できる。ABC306G
  int _;
  cin >> _;

  int n, m;
  while (cin >> n >> m) {
    SCC::init(n);
    for (int i = 0; i < m; ++i) {
      int a, b;
      cin >> a >> b;
      --a;
      --b;
      SCC::g[a].push_back(b);
    }
    vec<vec<int>> scc = SCC::detect_scc(n);
    same.clear();
    each (v, scc) {
      if (count(v.begin(), v.end(), 0)) {
        // cout << v << endl;
        each (i, v) same.insert(i);
        break;
      }
    }
    vis.clear();
    r.clear();
    rec(0, 0);
    if(r.empty()) {
      cout << "No" << endl;
      continue;
    }
    // cout << r << endl;
    lli g = r.front();
    each (i, r) g = __gcd(i, g);
    while (g % 2 == 0) g /= 2;
    while (g % 5 == 0) g /= 5;
    // cout << g << endl;
    if (g == 1) cout << "Yes" << endl;
    else cout << "No" << endl;
  }
  return 0;
}
