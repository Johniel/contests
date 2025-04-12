// github.com/Johniel/contests
// atcoder/abc401/F/main.cpp

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

const int MAXN = 2 * 1e5 + 5;
namespace A {
  // const int MAXN = 2e5 + 5;
  vector<int> G[MAXN];
  int dp[MAXN];       // 子から受け取った部分木最大長
  int res[MAXN];

// 1回目のDFS：部分木の最大深さを求める
  void dfs1(int v, int p) {
    dp[v] = 0;
    for (int u : G[v]) {
      if (u == p) continue;
      dfs1(u, v);
      dp[v] = max(dp[v], dp[u] + 1);
    }
  }

// 2回目のDFS：rerooting によって res を更新していく
  void dfs2(int v, int p, int from_parent) {
    // 各子に渡す値を準備する
    vector<int> prefix, suffix;
    for (int u : G[v]) {
      if (u == p) continue;
      prefix.push_back(dp[u] + 1);
      suffix.push_back(dp[u] + 1);
    }

    int sz = prefix.size();
    for (int i = 1; i < sz; ++i) prefix[i] = max(prefix[i], prefix[i - 1]);
    for (int i = sz - 2; i >= 0; --i) suffix[i] = max(suffix[i], suffix[i + 1]);

    int child_index = 0;
    for (int u : G[v]) {
      if (u == p) continue;

      // 最大値を親から持ってきた `from_parent` または兄弟部分木から選ぶ
      int use = from_parent;
      if (child_index > 0) use = max(use, prefix[child_index - 1]);
      if (child_index + 1 < sz) use = max(use, suffix[child_index + 1]);

      dfs2(u, v, use + 1);
      child_index++;
    }

    res[v] = max(dp[v], from_parent);
  }
};
namespace B {
  vector<int> G[MAXN];
  int dp[MAXN];       // 子から受け取った部分木最大長
  int res[MAXN];      // 各頂点を根にしたときの最大距離

// 1回目のDFS：部分木の最大深さを求める
  void dfs1(int v, int p) {
    dp[v] = 0;
    for (int u : G[v]) {
      if (u == p) continue;
      dfs1(u, v);
      dp[v] = max(dp[v], dp[u] + 1);
    }
  }

// 2回目のDFS：rerooting によって res を更新していく
  void dfs2(int v, int p, int from_parent) {
    // 各子に渡す値を準備する
    vector<int> prefix, suffix;
    for (int u : G[v]) {
      if (u == p) continue;
      prefix.push_back(dp[u] + 1);
      suffix.push_back(dp[u] + 1);
    }

    int sz = prefix.size();
    for (int i = 1; i < sz; ++i) prefix[i] = max(prefix[i], prefix[i - 1]);
    for (int i = sz - 2; i >= 0; --i) suffix[i] = max(suffix[i], suffix[i + 1]);

    int child_index = 0;
    for (int u : G[v]) {
      if (u == p) continue;

      // 最大値を親から持ってきた `from_parent` または兄弟部分木から選ぶ
      int use = from_parent;
      if (child_index > 0) use = max(use, prefix[child_index - 1]);
      if (child_index + 1 < sz) use = max(use, suffix[child_index + 1]);

      dfs2(u, v, use + 1);
      child_index++;
    }

    res[v] = max(dp[v], from_parent);
  }
};

template<typename T>
struct PrefixSum {
  vector<T> sum;
  PrefixSum(vector<T> v) {
    sum.push_back(0);
    for (int i = 0; i < v.size(); ++i) {
      sum.push_back(sum.back() + v[i]);
    }
  }
  T operator () (size_t begin, size_t end) const {
    assert(begin <= end);
    return sum[end] - sum[begin];
  }
  T operator () (size_t end) const {
    return (*this)(0, end);
  }
  int lower_bound(T x) const {
    return std::lower_bound(sum.begin(), sum.end(), x) - sum.begin();
  }
  int upper_bound(T x) const {
    return std::upper_bound(sum.begin(), sum.end(), x) - sum.begin();
  }
  size_t size(void) const { return (int)sum.size() - 1; }
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n1;
  while (cin >> n1) {
    fill(A::G, A::G + MAXN, vec<int>());
    fill(B::G, B::G + MAXN, vec<int>());
    for (int i = 0; i < n1 - 1; ++i) {
      int u, v;
      cin >> u >> v;
      --u; --v;
      A::G[u].push_back(v);
      A::G[v].push_back(u);
    }
    A::dfs1(0, -1);         // 木DP
    A::dfs2(0, -1, 0);      // rerooting
    int n2;
    cin >> n2;
    for (int i = 0; i < n2 - 1; ++i) {
      int u, v;
      cin >> u >> v;
      --u; --v;
      B::G[u].push_back(v);
      B::G[v].push_back(u);
    }
    B::dfs1(0, -1);         // 木DP
    B::dfs2(0, -1, 0);      // rerooting

    lli z = 0;

    int mx1 = 0;
    int mx2 = 0;
    for (int i = 0; i < n1; ++i) setmax(mx1, A::res[i]);
    for (int i = 0; i < n2; ++i) setmax(mx2, B::res[i]);

    vec<lli> a, b;
    for (int i = 0; i < n1; ++i) a.push_back(A::res[i]);
    for (int i = 0; i < n2; ++i) b.push_back(B::res[i]);
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    PrefixSum<lli> sum1(a);
    PrefixSum<lli> sum2(b);

    lli p = 0;
    for (int i = 0; i < n1; ++i) {
      const lli mx = max(mx1, mx2);
      auto itr = lower_bound(b.begin(), b.end(), mx - (A::res[i] + 1));
      lli w = (b.end() - itr) * (lli)(A::res[i] + 1);
      p += (b.end() - itr);
      z += w;
      z += sum2(itr - b.begin(), sum2.size());
    }
    z += (lli)((n1 * (lli)n2) - p) * max<lli>(mx1, mx2);
    cout << z << endl;

  }

  return 0;
}
