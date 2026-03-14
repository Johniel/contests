// github.com/Johniel/contests
// atcoder/abc449/E/main.cpp

#include <bits/stdc++.h>

#define each(i, c) for (auto& i : c)
#define unless(cond) if (!(cond))
#define __builtin_popcount(x) __builtin_popcountll(x)

using namespace std;

template<typename P, typename Q> ostream& operator << (ostream& os, pair<P, Q> p);
template<typename P, typename Q> istream& operator >> (istream& is, pair<P, Q>& p);
template<typename... Ts> ostream& operator << (ostream& os, const tuple<Ts...>& t) { os << "("; if constexpr (sizeof...(Ts) > 0) { apply([&](const Ts&... args) { ((os << args << ','), ...); }, t); } os << ")"; return os; }
template<typename... Ts> istream& operator >> (istream& is, tuple<Ts...>& t) { apply([&](Ts&... args) { ((is >> args), ...); }, t); return is; }
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

template<typename T = long long int>
struct BIT {
  vector<T> v;
  const int n;

  BIT(int n_ = 0) : n(n_), v(n_ + 1, 0) {}

  T operator () (int i) const {
    T s = 0;
    while (i > 0) {
      s += v.at(i);
      i -= i & -i;
    }
    return s;
  }

  T query(int begin, int end) const {
    assert(begin <= end);
    return (*this)(end) - (*this)(begin);
  }

  T operator () (int begin, int end) const {
    return query(begin, end);
  }

  void add(int i, T x) {
    ++i;
    while (i <= n) {
      v.at(i) += x;
      i += i & -i;
    }
    return ;
  }

  size_t lower_bound(const T query) const {
    int small = 0;
    int large = v.size();
    while (small + 1 < large) {
      auto mid = (small + large) / 2;
      if ((*this)(mid) <= query) small = mid;
      else large = mid;
    }
    if (query <= (*this)(small)) return small;
    if (query <= (*this)(large)) return large;
    return size();
  }

  size_t size(void) const { return n; }
};

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;

template<typename T>
class ordered_set : public tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update> {};
// find_by_order(k),order_of_key(k)
template<typename T> ostream& operator << (ostream& os, ordered_set<T>& s) { os << "&{"; for (int i = 0; i < s.size(); ++i) { os << *s.find_by_order(i) << ","; } os << "}"; return os; }

int main(int argc, char *argv[])
{
  int n, m;
  while (cin >> n >> m) {
    vec<int> a(n);
    cin >> a;
    map<int, int> freq;

    for (int i = 1; i <= m; ++i) freq[i] = 0;

    each (i, a) ++freq[i];
    vec<pair<int, int>> v;
    each (k, freq) v.push_back(make_pair(k.second, k.first));
    sort(v.begin(), v.end());
    vec<int> u;
    each (k, freq) u.push_back(k.second);
    sort(u.begin(), u.end());
    u.erase(unique(u.begin(), u.end()), u.end());

    const int N = 5 * 1e5 + 3;
    const int M = 5 * 1e5 + 3;
    static vec<int> w[M];
    fill(w, w + N, vec<int>());
    each (k, freq) w[k.second].push_back(k.first);

    BIT<lli> sum(M);
    for (int i = 0; i < M; ++i) {
      sum.add(i, w[i].size());
    }

    int q;
    cin >> q;

    vec<int> res(q, -999);

    vec<pair<lli, int>> b;
    for (int i = 0; i < q; ++i) {
      lli x;
      cin >> x;
      if (x <= n) res[i] = a[x - 1];
      else b.push_back(make_pair(x - n, i));
    }
    sort(b.begin(), b.end());
    reverse(b.begin(), b.end());

    ordered_set<int> vis;
    vec<lli> req(n + 2, 0);
    lli s = 0;
    for (int i = 0; i <= n; ++i) {
      s += i * 1LL * w[i].size();
      req[i] = sum.query(0, i + 1) * i - s;
      while (i && b.size() && req[i - 1] < b.back().first && b.back().first <= req[i]) {
        lli y = b.back().first - req[i - 1] -1;
        res[b.back().second] = *vis.find_by_order(y % vis.size());
        b.pop_back();
      }
      each (k, w[i]) vis.insert(k);
    }
    while (b.size()) {
      lli y = b.back().first - req[n] -1;
      res[b.back().second] = (y % m) + 1;
      b.pop_back();
    }
    each (i, res) cout << i << endl;
  }
  return 0;
}
