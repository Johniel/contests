// github.com/Johniel/contests
// atcoder/abc472/E/main.cpp

#include <bits/stdc++.h>

#define each(i, c) for (auto& i : c)
#define unless(cond) if (!(cond))
#define __builtin_popcount(x) __builtin_popcountll(x)

using namespace std;

template<typename P, typename Q> ostream& operator << (ostream& os, pair<P, Q> p);
template<typename P, typename Q> istream& operator >> (istream& is, pair<P, Q>& p);
template<typename... Ts> ostream& operator << (ostream& os, const tuple<Ts...>& t) { os << "("; if constexpr (sizeof...(Ts) > 0) { apply([&](const Ts&... args) { ((os << args << ','), ...); }, t); } os << ")"; return os; }
template<typename... Ts> istream& operator >> (istream& is, tuple<Ts...>& t) { apply([&](Ts&... args) { ((is >> args), ...); }, t); return is; }
template<typename T> ostream& operator << (ostream& os, const vector<T>& v) { os << "("; for (const auto& i: v) os << i << ","; os << ")"; return os; }
template<typename T> istream& operator >> (istream& is, vector<T>& v) { for (auto& i: v) is >> i; return is; }
template<typename T> ostream& operator << (ostream& os, const set<T>& s) { os << "set{"; for (const auto& i: s) os << i << ","; os << "}"; return os; }
template<typename K, typename V> ostream& operator << (ostream& os, const map<K, V>& m) { os << "map{"; for (const auto& i: m) os << i << ","; os << "}"; return os; }
template<typename E, size_t N> istream& operator >> (istream& is, array<E, N>& a) { for (auto& i: a) is >> i; return is; }
template<typename E, size_t N> ostream& operator << (ostream& os, array<E, N>& a) { os << "[" << N << "]{"; for (const auto& i: a) os << i << ","; os << "}"; return os; }
template<typename T> ostream& operator << (ostream& os, stack<T> s) { os << "stack{"; while (s.size()) { os << s.top() << ","; s.pop(); } os << "}"; return os; }
template<typename T> ostream& operator << (ostream& os, queue<T> q) { os << "queue{"; while (q.size()) { os << q.front() << ","; q.pop(); } os << "}"; return os; }
template<typename T> ostream& operator << (ostream& os, const deque<T>& q) { os << "deque{"; for (int i = 0; i < q.size(); ++i) os << q[i] << ","; os << "}"; return os; }
template<typename T> ostream& operator << (ostream& os, priority_queue<T> q) { os << "heap{"; while (q.size()) { os << q.top() << ","; q.pop(); } os << "}"; return os; }
template<typename P, typename Q> ostream& operator << (ostream& os, pair<P, Q> p) { os << "(" << p.first << "," << p.second << ")"; return os; }
template<typename P, typename Q> istream& operator >> (istream& is, pair<P, Q>& p) { is >> p.first >> p.second; return is; }

template<typename T> inline T setmax(T& a, T b) { return a = std::max(a, b); }
template<typename T> inline T setmin(T& a, T b) { return a = std::min(a, b); }

__attribute__((constructor)) static void _____(void) { ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.setf(ios_base::fixed); cout.precision(15); return ; }

using lli = long long int;
using ull = unsigned long long;
using str = string;
template<typename T> using vec = vector<T>;

constexpr lli mod = 998244353; // 1e9 + 7;

const int N = 2 * 1e5 + 3;

vec<pair<int, int>> g[N][2];
int vis[N][2];

vec<int> path;
vec<int> inv;

void rec(int curr, int color, int prev)
{
  path.push_back(curr);
  vis[curr][color] = path.size();
  // cout << make_pair(curr+1, color) << endl;
  each (e, g[curr][color]) {
    auto [next, _] = e;
    assert(_ == color ^ 1);
    if (next == prev) continue;
    if (vis[next][color] != -1) {
      vec<int> v;
      while (path.back() != next) {
        assert(path.size());
        v.push_back(path.back());
        path.pop_back();
      }
      v.push_back(next);
      cout << v.size() << endl;
      each (i, v) cout << i + 1 << ' ';
      cout << endl;
      throw "";
    }
    if (vis[next][color ^ 1] != -1) continue;
    rec(next, color ^ 1, curr);
  }

  path.pop_back();
  return ;
}

int main(int argc, char *argv[])
{
  { int _; cin >> _; }
  int n, m;
  while (cin >> n >> m) {
    for (int i = 0; i < n; ++i) {
      g[i][0] = g[i][1] = vec<pair<int, int>>();
      vis[i][0] = vis[i][1] = -1;
    }
    for (int i = 0; i < m; ++i) {
      int a, b;
      cin >> a >> b;
      --a;
      --b;
      g[a][0].push_back(make_pair(b, 1));
      g[b][0].push_back(make_pair(a, 1));
      g[a][1].push_back(make_pair(b, 0));
      g[b][1].push_back(make_pair(a, 0));
    }
    try {
      path.clear();
      rec(0, 0, -1);
      cout << -1 << endl;
    } catch (const char* e) {
    }
  }
  return 0;
}
