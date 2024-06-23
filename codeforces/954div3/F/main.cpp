// github.com/Johniel/contests
// codeforces/954div3/F/main.cpp

#include <bits/stdc++.h>

#define each(i, c) for (auto& i : c)
#define unless(cond) if (!(cond))

using namespace std;

template<typename P, typename Q> ostream& operator << (ostream& os, pair<P, Q> p);
template<typename P, typename Q> istream& operator >> (istream& is, pair<P, Q>& p);
template<typename P, typename Q, typename R> ostream& operator << (ostream& os, tuple<P, Q, R> t) { os << "(" << get<0>(t) << "," << get<1>(t) << "," << get<2>(t) << ")"; return os; }
template<typename P, typename Q, typename R> istream& operator >> (istream& is, tuple<P, Q, R>& t) { is >> get<0>(t) >> get<1>(t) >> get<2>(t); return is; }
template<typename T> ostream& operator << (ostream& os, vector<T> v) { os << "("; for (auto& i: v) os << i << ","; os << ")"; return os; }
template<typename T> istream& operator >> (istream& is, vector<T>& v) { for (auto& i: v) is >> i; return is; }
template<typename T> ostream& operator << (ostream& os, set<T> s) { os << "set{"; for (auto& i: s) os << i << ","; os << "}"; return os; }
template<typename K, typename V> ostream& operator << (ostream& os, map<K, V> m) { os << "map{"; for (auto& i: m) os << i << ","; os << "}"; return os; }
template<typename E, size_t N> istream& operator >> (istream& is, array<E, N>& a) { for (auto& i: a) is >> i; return is; }
template<typename E, size_t N> ostream& operator << (ostream& os, array<E, N>& a) { os << "[" << N << "]{"; for (auto& i: a) os << i << ","; os << "}"; return os; }
template<typename T> ostream& operator << (ostream& os, stack<T> s) { os << "stack{"; while (s.size()) { os << s.top() << ","; s.pop(); } os << "}"; return os; }
template<typename T> ostream& operator << (ostream& os, queue<T> q) { os << "queue{"; while (q.size()) { os << q.front() << ","; q.pop(); } os << "}"; return os; }
template<typename T> ostream& operator << (ostream& os, deque<T> q) { os << "deque{"; for (int i = 0; i < q.size(); ++i) os << q[i] << ","; os << "}"; return os; }
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

// constexpr lli mod = 1e9 + 7;
constexpr lli mod = 998244353;

struct LowLink {
  // 橋: ABC266F
  // 関節点: ARC045D
  using graph = vector<vector<int>>;
  vector<bool> vis;
  vector<int> ord, low;
  vector<pair<int, int>> bs; // bridges
  vector<int> as; // articulation points
  graph g;
  void run(const graph& g_)
  {
    g = g_;
    const int n = g.size();
    vis.resize(n, false);
    ord.resize(n, 0);
    low.resize(n, 0);
    int k = 0;
    for (int i = 0; i < n; ++i) {
      if (!vis[i]) k = rec(i, k, -1);
    }
    sort(as.begin(), as.end());
    sort(bs.begin(), bs.end());
  }
  int rec(int curr, int k, int prev)
  {
    vis[curr] = true;
    ord[curr] = k++;
    low[curr] = ord[curr];
    bool f = false;
    int cnt = 0;
    for (auto &next: g[curr]) {
      if (next == prev) continue;
      if (vis[next]) { // 後退辺
        low[curr] = min(low[curr], ord[next]);
      } else {
        ++cnt;
        k = rec(next, k, curr);
        low[curr] = min(low[curr], low[next]);
        f = f || (prev != -1 && ord[curr] <= low[next]);
        if (ord[curr] < low[next]) {
          bs.push_back({min(curr, next), max(curr, next)});
        }
      }
    }
    if (prev == -1 && 2 <= cnt) f = true;
    if (f) as.push_back(curr);
    return k;
  }
};

int main(int argc, char *argv[])
{
  { int _; cin >> _; }
  int n, m;
  while (cin >> n >> m) {
    LowLink::graph g(n);
    for (int i = 0; i < m; ++i) {
      int a, b;
      cin >> a >> b;
      --a;
      --b;
      g[a].push_back(b);
      g[b].push_back(a);
    }

    LowLink ll;
    ll.run(g);

    if (ll.bs.empty()) {
      lli x = n;
      cout << x * (x - 1) / 2 << endl;
      continue;
    }

    sort(ll.bs.begin(), ll.bs.end());

    set<int> vis;
    function<pair<lli, int>(int, int)> rec = [&] (int curr, int prev) {
      vis.insert(curr);
      lli z = 1LL << 60;
      int size = 1;
      each (next, g[curr]) {
        if (next == prev) continue;
        if (vis.count(next)) continue;
        auto p = rec(next, curr);
        size += p.second;
        setmin(z, p.first);

        pair<int, int> e = make_pair(min(curr, next), max(curr, next));
        if (binary_search(ll.bs.begin(), ll.bs.end(), e)) {
          lli x = p.second;
          lli y = n - x;
          setmin(z, x * (x - 1) / 2 + y * (y - 1) / 2);
        }
      }
      return make_pair(z, size);
    };
    cout << rec(0, 0).first << endl;
  }
  return 0;
}
