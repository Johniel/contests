// github.com/Johniel/contests
// atcoder/abc313/C/main.cpp

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

constexpr array<int, 8> di({0, 1, -1, 0, 1, -1, 1, -1});
constexpr array<int, 8> dj({1, 0, 0, -1, 1, -1, -1, 1});
constexpr lli mod = 1e9 + 7;
// constexpr lli mod = 998244353;

// 上に凸な関数の極値を求める。
lli trinaly_search(lli small, lli large, function<lli(lli)>fn)
{
  for (int i = 0; i < 100; ++i) {
    lli left = (large - small) / 3 + small;
    lli right = (large - small) * 2 / 3 + small;
    if (fn(right) < fn(left)) large = right;
    else small = left;
  }

  lli mx = small;
  for (lli i = small; i <= large; ++i) {
    if (fn(mx) < fn(i)) mx = i;
  }
  return mx;
}

int main(int argc, char *argv[])
{
  int n;
  while (cin >> n) {
    vec<lli> a(n);
    cin >> a;
    sort(a.begin(), a.end());

    if (a.front() == a.back() || a.front() + 1 == a.back()) {
      cout << 0 << endl;
      continue;
    }

    function<lli(lli)> fn = [&] (const lli x) {
      lli add = 0;
      lli sub = 0;
      lli nop = 0;
      each (i, a) {
        if (i < x) add += (x - i);
        else if (i == x || i == x + 1) ++nop;
        else if (x + 1 < i) sub += (i - (x + 1));
      }
      // if (x == 6) cout << "fn(6):" << add << ' '<< sub << endl;
      if (add == 0 && sub == 0) return 0LL;
      if (add == 0 || sub == 0) return -(1LL << 60);
      lli z = min(add, sub) + max(add, sub) - min(add, sub);
      return -z;
    };

    lli small = *min_element(a.begin(), a.end());
    lli large = *max_element(a.begin(), a.end());
    lli x = trinaly_search(small, large, fn);
    // cout << x << ' ' << -fn(x) << endl;
    cout << -fn(x) << endl;
  }
  return 0;
}
