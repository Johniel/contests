// github.com/Johniel/contests
// atcoder/awc0060/E/main.cpp

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

lli mod = 998244353; // 1e9 + 7;

// Acc: 要約の型（long long, pair, struct...）
// Merge: Acc operator()(Acc left, Acc right) で「leftの後にright」を結合
template<class Acc, class Merge>
struct Doubling {
  int n;
  int LOG;
  vector<vector<int>> up;
  vector<vector<Acc>> acc;
  Merge merge;
  Acc id; // 単位元（空区間の要約）

  Doubling(int n_, long long max_t, Merge merge_, Acc id_) : n(n_), merge(merge_), id(id_) {
    LOG = 0;
    while ((1LL << LOG) <= max_t) LOG++;
    up.assign(LOG, vector<int>(n, 0));
    acc.assign(LOG, vector<Acc>(n, id));
  }

  void build(const vector<int>& nxt, const vector<Acc>& base) {
    for (int v = 0; v < n; v++) {
      up[0][v] = nxt[v];
      acc[0][v] = base[v];
    }
    for (int k = 1; k < LOG; k++) {
      for (int v = 0; v < n; v++) {
        int mid = up[k - 1][v];
        up[k][v] = up[k - 1][mid];
        acc[k][v] = merge(acc[k - 1][v], acc[k - 1][mid]);
      }
    }
  }

  pair<int, Acc> jump(int v, long long t) const {
    int cur = v;
    Acc res = id;
    for (int k = 0; k < LOG; k++) {
      if (t & (1LL << k)) {
        res = merge(res, acc[k][cur]);
        cur = up[k][cur];
      }
    }
    return {cur, res};
  }
};

int main(int argc, char *argv[])
{
  int n, q;
  while (cin >> n >> q >> mod) {
    vec<lli> d(n);
    vec<int> p(n);
    for (int i = 0; i < n; ++i) {
      cin >> d[i] >> p[i];
      --p[i];
    }

    // Acc = (値 mod M, 10^長さ mod M), 「leftの後にright」: left * 10^len(right) + right
    using Acc = pair<lli, lli>;
    auto merge = [&] (Acc a, Acc b) -> Acc {
      return { (a.first * b.second + b.first) % mod, (a.second * b.second) % mod };
    };
    Acc id = { 0 % mod, 1 % mod };

    Doubling<Acc, decltype(merge)> db(n, (lli)1e18 + 10, merge, id);

    vec<Acc> base(n);
    for (int i = 0; i < n; ++i) {
      base[i] = { d[i] % mod, 10 % mod };
    }
    db.build(p, base);

    while (q--) {
      int s;
      lli k;
      cin >> s >> k;
      --s;
      auto [_, res] = db.jump(s, k);
      cout << res.first << "\n";
    }
  }
  return 0;
}
