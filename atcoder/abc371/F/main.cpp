// github.com/Johniel/contests
// atcoder/abc371/F/main.cpp

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

// N人が数直線上に並んでいる。左からi番目の人iはXiの位置に立っている。
// クエリごとに人iをYの位置にまで移動させる。移動の際、同じ座標に複数人が立つことが出来ない。
// そのため人iを移動させるために玉突きで移動が発生する。クエリ毎に、移動の結果として立つ位置を替えた全員分の移動距離を返す。
template<std::integral T=long long int>
struct NarrowRoadOrderedSet {
  // https://atcoder.jp/contests/abc371/editorial/10942
  NarrowRoadOrderedSet(vec<T> x) : n(x.size()) {
    assert(is_sorted(x.begin(), x.end()));
    for (int i = 0; i < x.size(); ++i) {
      x[i] -= i;
      if (i == 0 || x[i - 1] != x[i]) m[i] = x[i];
    }
  }
  T operator () (int i, T y) { return query(i, y); }
  T query(int i, T y) {
    y -= i;
    auto itr = --m.lower_bound(i + 1);
    const T x = itr->second;
    if (y == x) return 0;
    T cost = 0;
    pair<int, T> p = make_pair(i, itr->second);
    if (x < y) {
      if (itr->first != i) {
        m[i] = p.second;
        ++itr;
      }
      while (itr != m.end()) {
        itr = m.erase(itr);
        if (itr == m.end() || y < itr->second) break;
        cost += abs(itr->first - p.first) * abs(p.second - itr->second);
        p.second = itr->second;
      }
      if (itr != m.end()) {
        cost += abs(itr->first - p.first) * abs(p.second - y);
      } else {
        cost += abs(n - p.first) * abs(p.second - y);
      }
      p.second = y;
    } else {
      if (!m.contains(i + 1)) m[i + 1] = itr->second;
      p = *itr;
      int right;
      while (true) {
        itr = m.erase(itr);
        right = (itr == m.end() ? n : itr->first);
        if (itr == m.begin()) break;
        --itr;
        if (itr->second < y) break;
        cost += abs(right - p.first) * abs(p.second - itr->second);
        p = *itr;
      }
      if (itr->second < y) {
        cost += abs(right - p.first) * abs(p.second - y);
      } else {
        cost += right * abs(p.second - y);
      }
      p.second = y;
    }
    m[p.first] = p.second;
    return cost;
  }
  map<int, T> m; // {同じ位置に立つ人たちの最小添字,位置}
  const int n;
};

int main(int argc, char *argv[])
{
  int n;
  while (cin >> n) {
    vec<lli> xs(n);
    cin >> xs;
    NarrowRoadOrderedSet<lli> s(xs);

    int q;
    cin >> q;
    lli z = 0;
    while (q--) {
      int t;
      lli g;
      cin >> t >> g;
      --t;
      z += s(t, g);
    }
    cout << z << endl;
  }
  return 0;
}
