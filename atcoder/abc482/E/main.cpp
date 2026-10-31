// github.com/Johniel/contests
// atcoder/abc482/E/main.cpp

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

vec<int> g[N];
vec<int> color;

int main(int argc, char *argv[])
{
  int n;
  while (cin >> n) {
    fill(g, g + n, vec<int>());
    for (int i = 0; i < n - 1; ++i) {
      int a, b;
      cin >> a >> b;
      --a;
      --b;
      g[a].push_back(b);
      g[b].push_back(a);
    }
    color.resize(n);
    cin >> color;

    vec<int> path(n, -1);
    function<pair<int, int>(int, int)> rec = [&] (int curr, int prev) {
      path[curr] = prev;
      pair<int, int> mx = make_pair(0, curr);
      each (next, g[curr]) {
        if (next == prev) continue;
        pair<int, int> p = rec(next, curr);
        ++p.first;
        setmax(mx, p);
      }
      return mx;
    };
    auto p1 = rec(0, 0);
    auto p2 = rec(p1.second, p1.second);

    // cout << p2 << endl;

    if (p2.first % 2) {
      int x = p2.second;
      for (int i = 0; i < p2.first / 2; ++i) {
        x = path[x];
      }
      int y = path[x];
      {
        auto itr = std::remove(g[x].begin(), g[x].end(), y);
        g[x].erase(itr, g[x].end());
      }
      {
        auto itr = std::remove(g[y].begin(), g[y].end(), x);
        g[y].erase(itr, g[y].end());
      }
      ++n;
      g[x].push_back(n - 1);
      g[y].push_back(n - 1);
      g[n - 1].push_back(x);
      g[n - 1].push_back(y);
      p1 = rec(0, 0);
      p2 = rec(p1.second, p1.second);

      // cout << make_pair(x, n - 1) << ' ' << make_pair(y, n - 1) << endl;
    }
    assert(p2.first % 2 == 0);
    int c = p2.second;
    for (int i = 0; i < p2.first / 2; ++i) {
      c = path[c];
    }

    // cout << p2 << endl;

    vec<int> v;
    function<void(int, int, int)> rec2 = [&] (int curr, int prev, int depth) {
      if (g[curr].size() == 1) {
        if (depth == p2.first / 2) v.push_back(curr);
        return ;
      }
      each (next, g[curr]) {
        if (next == prev) continue;
        rec2(next, curr, depth + 1);
      }
      return ;
    };
    lli z = 0;
    {
      vec<int> w(N, 0);
      int i = c;
      each (j, g[i]) {
        v.clear();
        rec2(j, i, 1);
        // cout << make_pair(i, j) << ' ' << v << endl;
        each (k, v) z += w[color[k]];
        each (k, v) ++w[color[k]];
      }
    }
    cout << z << endl;
  }
  return 0;
}
