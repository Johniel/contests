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

// 木の各頂点から最も遠い点までの距離を求める。
struct TreeEccentricity {
  vector<vector<int>> g;
  vector<int> eccentricity;

  TreeEccentricity() : TreeEccentricity(0) {}
  TreeEccentricity(const int n) {
    g.resize(n, vector<int>());
  }

  void add_edge(int a, int b) {
    g[a].push_back(b);
    g[b].push_back(a);
  }

  void rec(int curr, int prev, vector<int>& dist) {
    if (curr != prev) dist[curr] = dist[prev] + 1;
    for (const auto next: g[curr]) {
      if (next != prev) rec(next, curr, dist);
    }
  }

  pair<int, pair<int, int>> build(void) {
    vector<int> v_(g.size(), 0);
    vector<int> va(g.size(), 0);
    vector<int> vb(g.size(), 0);
    rec(0, 0, v_);
    int a = max_element(v_.begin(), v_.end()) - v_.begin();
    rec(a, a, va);
    int b = max_element(va.begin(), va.end()) - va.begin();
    rec(b, b, vb);
    for (int i = 0; i < g.size(); ++i) {
      eccentricity.push_back(max(va[i], vb[i]));
    }
    const int diameter = *max_element(eccentricity.begin(), eccentricity.end());
    assert(diameter == eccentricity[a]);
    return make_pair(diameter, make_pair(a, b));
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
  T operator () (size_t end) const { return (*this)(0, end); }
  size_t size(void) const { return (int)sum.size() - 1; }
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  lli n1;
  while (cin >> n1) {
    TreeEccentricity A(n1);

    for (int i = 0; i < n1 - 1; ++i) {
      int u, v;
      cin >> u >> v;
      --u;
      --v;
      A.add_edge(u, v);
    }

    lli n2;
    cin >> n2;
    TreeEccentricity B(n2);
    for (int i = 0; i < n2 - 1; ++i) {
      int u, v;
      cin >> u >> v;
      --u;
      --v;
      B.add_edge(u, v);
    }

    A.build();
    B.build();

    lli z = 0;

    const int mx1 = *max_element(A.eccentricity.begin(), A.eccentricity.end());
    const int mx2 = *max_element(B.eccentricity.begin(), B.eccentricity.end());

    vec<lli> a, b;
    each (i, A.eccentricity) a.push_back(i);
    each (i, B.eccentricity) b.push_back(i);
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    PrefixSum<lli> sum1(a);
    PrefixSum<lli> sum2(b);

    lli p = 0;
    for (int i = 0; i < n1; ++i) {
      const lli mx = max(mx1, mx2);
      auto itr = lower_bound(b.begin(), b.end(), mx - (A.eccentricity[i] + 1));
      lli w = (b.end() - itr) * (lli)(A.eccentricity[i] + 1);
      p += (b.end() - itr);
      z += w;
      z += sum2(itr - b.begin(), sum2.size());
    }
    z += ((n1 * n2) - p) * max<lli>(mx1, mx2);
    cout << z << endl;
  }

  return 0;
}
