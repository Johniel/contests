// github.com/Johniel/contests
// atcoder/abc404/G/main.cpp

#include <bits/stdc++.h>

#define each(i, c) for (auto& i : c)
#define unless(cond) if (!(cond))
#define __builtin_popcount(x) __builtin_popcountll(x)

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

constexpr lli mod = 998244353; // 1e9 + 7;

// N個の変数d[i]
// M個の差分制約式d[j]-d[i]<=c[k]
// 2つの変数からなる式d[t]-d[s]を最大化する線形計画問題
template<std::integral T>
struct CowGame {
  vector<tuple<int, int, T>> es;
  const size_t n;
  CowGame(size_t n_) : n(n_) {}
  // d[j]-d[i]<=c[k]を追加。
  void add_edge(int i, int j, T c) {
    assert(0 <= i && i < size());
    assert(0 <= j && j < size());
    // d[j]-d[i]<=c[k]を式変形してd[j]<=d[i]+c[k]するとグラフっぽくなる。
    es.push_back(make_tuple(i, j, c));
  }
  // d[t]-d[s]の最大値
  pair<bool, T> run(int s, int t) {
    assert(0 <= s && s < size());
    assert(0 <= t && t < size());
    vector<T> cost(size(), numeric_limits<T>::max() / 2 - 1);
    cost[s] = 0;
    // bellman-ford
    for (size_t k = 1; k < size(); ++k) {
      for (const auto& e: es) {
        const auto [i, j, c] = e;
        cost[j] = min(cost[j], cost[i] + c);
      }
    }
    for (const auto& e: es) {
      const auto [i, j, c] = e;
      if (cost[j] > cost[i] + c) return make_pair(false, T(0));
    }
    return make_pair(true, cost[t]);
  }
  size_t size(void) const { return n; }
};

int main(int argc, char *argv[])
{
  int n, m;
  while (cin >> n >> m) {
    // Σ(L[i],R[i])=S[i]
    // Σ(0,R[i])-Σ(0,L[i]-1)=S[i]
    // sum(0,j)をB[j]とおく※半開区間の総和だと駄目。

    CowGame<lli> cg(n+1);
    // A[i]は正整数なのでB[j+1]-B[j]=>1
    // -1倍してB[j]-B[j+1]<=-1
    for (int j = 0; j + 1 <= n; ++j) {
      cg.add_edge(j + 1, j, -1);
    }
    for (int i = 0; i < m; ++i) {
      int a, b, c;
      cin >> a >> b >> c;
      // sum(a,b)=cなので、sum(0,b)-sum(0,a)=c
      // B[b]-B[a]=c
      // これを２つの不等式に変えて、
      // B[b]-B[a]<=c
      // B[b]-B[a]>=c これは B[a]-B[b]<=-c
      --a;
      cg.add_edge(a, b, +c);
      cg.add_edge(b, a, -c);
    }
    // この問題はB[n]の最小化をしたい
    // d[t]-d[s]の最大化が牛
    auto p = cg.run(n, 0);
    unless (p.first) {
      cout << -1 << endl;
    } else {
      cout << -p.second << endl;
    }
  }
  return 0;
}
