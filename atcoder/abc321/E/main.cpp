// github.com/Johniel/contests
// atcoder/abc321/E/main.cpp

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

// const lli N = 1000000000000000000LL;

pair<ull, ull> nil = make_pair(1, 0);

pair<ull, ull> fn(ull n, ull x, ull k)
{
  // cout << n << ' ' << x << ' ' << k << endl;
  if (x == 0) return nil;
  unless (0 <= k) return nil;
  int sh = 0;
  for (int _ = 0; _ < k; ++_) {
    if (__int128(x) * 2 <= __int128(n)) {
      x *= 2;
      ++sh;
    } else {
      return nil;
    }
  }
  return make_pair(x, min(x + (ull(1) << sh) - 1, n));
}

void show(ull x)
{
  str s;
  while (x) {
    s += '0' + (x & 1);
    x /= 2;
  }
  reverse(s.begin(), s.end());
  cout << s << endl;
}

int main(int argc, char *argv[])
{
  int _;
  while (cin >> _) {
    while (_--) {
      lli n, x, k;
      cin >> n >> x >> k;
      vec<pair<ull, ull>> v;
      v.push_back(fn(n, x, k));
      {
        ull y = x;
        for (int _ = 0; _ < k && y; ++_) {
          y /= 2;
        }
        if (y) v.push_back(make_pair(y,  y));
      }
      for (int up = 1; up < 65 && 0 <= k - up - 1; ++up) {
        if ((__int128(x) >> up) == (__int128(x) >> (up - 1))) break;
        ull y;

        if ((__int128(x) >> (up - 1)) & 1) {
          y = (x >> up) * 2;
        } else{
          y = (x >> up) * 2 + 1;
        }
        auto tmp = fn(n, y, k - up - 1);
        v.push_back(tmp);
      }
      sort(v.begin(), v.end());
      erase(v, nil);
      // cout << v << endl;
      {
        vec<pair<ull, ull>> u;
        each (i, v) {
          if (u.empty()) u.push_back(i);
          else {
            if (u.back().first <= i.first && i.first <= u.back().second) setmax(u.back().second, i.second);
            else u.push_back(i);
          }
        }
        v = u;
      }
      // cout << v << endl;
      lli z = 0;
      each (i, v) z += i.second - i.first + 1;
      cout << z << endl;
    }
    // break;
  }
  return 0;
}
