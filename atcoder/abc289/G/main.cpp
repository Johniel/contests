// github.com/Johniel/contests
// atcoder/abc289/G/main.cpp

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
template<typename T> using heap = priority_queue<T>;

constexpr array<int, 8> di({0, 1, -1, 0, 1, -1, 1, -1});
constexpr array<int, 8> dj({1, 0, 0, -1, 1, -1, -1, 1});
constexpr lli mod = 1e9 + 7;
// constexpr lli mod = 998244353;

template<typename T>
struct ConvexHullTrick {
  deque<pair<T, T>> q;
  ConvexHullTrick() {}
  void append(T a, T b) // DESC a, aX+b
  {
    if (q.size()) {
      assert(q.back().first >= a);
    }
    q.push_back({a, b});
    while (3 <= q.size() && check()) {
      q[q.size() - 2] = q[q.size() - 1];
      q.pop_back();
    }
    return ;
  }
  bool check(void)
  {
    pair<T, T> a = q[q.size() - 3];
    pair<T, T> b = q[q.size() - 2];
    pair<T, T> c = q[q.size() - 1];
    assert(a.first >= b.first);
    assert(b.first >= c.first);
    return (b.first - a.first) * (c.second - b.second) >= (b.second - a.second) * (c.first - b.first);
  }
  T eval(T x, pair<T, T> p)
  {
    return p.first * x + p.second;
  }
  T query(T x) // ASC x
  {
    while (2 <= q.size() && eval(x, q[0]) >= eval(x, q[1])) {
      q.pop_front();
    }
    return eval(x, q.front());
  }
};

int main(int argc, char *argv[])
{
  int n, m;
  while (cin >> n >> m) {
    vec<lli> b(n), c(m);
    cin >> b >> c;
    // 客n人
    // 購買意欲bi
    // 商品m個
    // 価格pjを決める。
    // bi+cj>=pjなら購入。
    // 各商品jについて売上を最大化しようと思うとpjはいくら？
    // n<=2*1e5
    // m<=2*1e5

    // 両辺にjがあると面倒そうなので移行
    // bi>=pj-cj
    // biは固定値。cjも固定値。

    // 売上を最大化しようとする場合は(bi+cj)を下げる必要性は無いのでpjのうちどれかとなるので、
    // 商品iの売上はx人が購入するとしてx(bi+cj)となる。
    // bi順でソートしたとき、`x人が購入する`を`客iまでが購入する`に言い換えられて、i(bi+cj)になる。天才か。
    // yj=i(bi+cj)の最大化。
    // ibiは固定値。cjも固定値。
    // つまりyj=icj+ibiで、y=ax+cの形。

    sort(b.begin(), b.end());
    reverse(b.begin(), b.end());

    ConvexHullTrick<lli> cht;
    // for (lli i = idx.size() - 1; 0 <= i; --i) cht.append((i + 1), (i + 1) * b.at(i));
    for (int i = 0; i < b.size(); ++i) cht.append(-(i + 1), -(i + 1) * b.at(i));
    vec<pair<lli, int>> v;
    for (int j = 0; j < c.size(); ++j) {
      v.push_back(make_pair(c[j], j));
    }
    sort(v.begin(), v.end());
    vec<lli> u(c.size());
    each (i, v) u[i.second] = cht.query(i.first);
    each (i, u) cout << abs(i) << ' ';
    cout << endl;
  }
  return 0;
}
