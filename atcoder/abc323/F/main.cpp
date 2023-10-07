// github.com/Johniel/contests
// atcoder/abc323/F/main.cpp

#include <bits/stdc++.h>

#define each(i, c) for (auto& i : c)
#define each_with_index(i, e, c) for (const auto i: views::iota(0, (int)c.size())) if (auto& e = c.at(i); true)
#define each_pair(p, c) for (const auto _i: views::iota(0, (int)c.size())) if (std::pair<const int, decltype((c.at(_i)))> p = {_i, c[_i]}; true)
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

constexpr array<int, 8> di({0, 1, -1, 0, 1, -1, 1, -1});
constexpr array<int, 8> dj({1, 0, 0, -1, 1, -1, -1, 1});
// constexpr lli mod = 1e9 + 7;
constexpr lli mod = 998244353;


template<typename T> pair<T, T> rot90(T x, T y)
{
  T a = x * 0 - y * 1;
  T b = x * 1 + y * 0;
  return make_pair(a, b);
}

tuple<pair<lli, lli>, pair<lli, lli>, lli> fn1(pair<lli, lli> src, pair<lli, lli> bag, pair<lli, lli> dst)
{
  bool f = false;;
    unless (src.second <= dst.second) {
      f = true;
      src.second *= -1;
      bag.second *= -1;
      dst.second *= -1;
    }

  // 横に押す
    // cout << "fn1:" << src << bag << dst << endl;
  assert(src.second <= dst.second);

  if (bag.second == dst.second) return make_tuple(src, bag, 0);

  if (bag.second < src.second) {
    lli z = 0;
    // 回り込む
    if (bag.first == src.first) {
      ++z;
      ++src.first;
    }
    // <
    z += abs(bag.second - src.second) + 1;
    // v
    z += abs(bag.first - src.first);
    // >
    z += abs(bag.second - dst.second);

    bag.second = dst.second;
    src = make_pair(bag.first, bag.second - 1);

    if (f) {
      src.second *= -1;
      bag.second *= -1;
    }
    return make_tuple(src, bag, z);
  }

  if (src.second == bag.second) {
    lli z = 0;
    // <
    ++z;
    --src.second;
    // v
    z += abs(bag.first - src.first);
    // >
    z += abs(bag.second - dst.second);
    bag.second = dst.second;
    src = make_pair(bag.first, bag.second - 1);
    if (f) {
      src.second *= -1;
      bag.second *= -1;
    }
    return make_tuple(src, bag, z);
  }

  if (src.second < bag.second && bag.second < dst.second) {
    lli z = 0;
    // >
    z += abs((bag.second - 1) - src.second);
    // v
    z += abs(bag.first - src.first);
    // >
    z += abs(dst.second - bag.second);

    bag.second = dst.second;
    src = make_pair(bag.first, bag.second - 1);
    if (f) {
      src.second *= -1;
      bag.second *= -1;
    }
    return make_tuple(src, bag, z);
  }

  if (dst.second < bag.second) {
    lli z = 0;
    if (src.first == bag.first) {
      // 回り込む
      ++src.first;
      ++z;
    }
    // >
    z += abs(src.second - bag.second);
    // >
    ++z;
    src.second = bag.second + 1;
    // v
    z += abs(src.first - bag.first);
    // <
    z += abs(dst.second - bag.second);

    bag.second = dst.second;
    src = make_pair(bag.first, bag.second + 1);
    if (f) {
      src.second *= -1;
      bag.second *= -1;
    }
    return make_tuple(src, bag, z);
  }

  assert(false);
}

tuple<pair<lli, lli>, pair<lli, lli>, lli> fn2(pair<lli, lli> src, pair<lli, lli> bag, pair<lli, lli> dst)
{
  src = rot90(src.first, src.second);
  bag = rot90(bag.first, bag.second);
  dst = rot90(dst.first, dst.second);

  auto [p, b, c] = fn1(src, bag, dst);

  for (int _ = 0; _ < 3; ++_) {
    p = rot90(p.first, p.second);
    b = rot90(b.first, b.second);
  }
  return make_tuple(p, b, c);
}

int main(int argc, char *argv[])
{
  pair<lli, lli> src, bag, dst;
  while (cin >> src >> bag >> dst) {
    // cout << src << bag << dst << endl;

    lli mn = 1LL << 62;
    if (1) {
      auto [p, b, x] = fn1(src, bag, dst);
      auto [q, c, y] = fn2(p, b, dst);
      // cout << "(x,y):" << make_pair(x, y) << endl;
      setmin(mn, x + y);
    }
    if (1) {
      auto [p, b, x] = fn2(src, bag, dst);
      auto [q, c, y] = fn1(p, b, dst);
      setmin(mn, x + y);
    }
    cout << mn << endl;
  }
  return 0;
}
