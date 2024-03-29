// atcoder/abc216/E/main.cpp
// author: @___Johniel
// github: https://github.com/johniel/

#include <bits/stdc++.h>

#define each(i, c) for (auto& i : c)
#define unless(cond) if (!(cond))

using namespace std;

template<typename P, typename Q> ostream& operator << (ostream& os, pair<P, Q> p) { os << "(" << p.first << "," << p.second << ")"; return os; }
template<typename P, typename Q> istream& operator >> (istream& is, pair<P, Q>& p) { is >> p.first >> p.second; return is; }
template<typename T> ostream& operator << (ostream& os, vector<T> v) { os << "("; for (auto& i: v) os << i << ","; os << ")"; return os; }
template<typename T> istream& operator >> (istream& is, vector<T>& v) { for (auto& i: v) is >> i; return is; }
template<typename T> ostream& operator << (ostream& os, set<T> s) { os << "#{"; for (auto& i: s) os << i << ","; os << "}"; return os; }
template<typename K, typename V> ostream& operator << (ostream& os, map<K, V> m) { os << "{"; for (auto& i: m) os << i << ","; os << "}"; return os; }

template<typename T> inline T setmax(T& a, T b) { return a = std::max(a, b); }
template<typename T> inline T setmin(T& a, T b) { return a = std::min(a, b); }

using lli = long long int;
using ull = unsigned long long;
using point = complex<double>;
using str = string;
template<typename T> using vec = vector<T>;

constexpr array<int, 8> di({0, 1, -1, 0, 1, -1, 1, -1});
constexpr array<int, 8> dj({1, 0, 0, -1, 1, -1, -1, 1});
constexpr lli mod = 1e9 + 7;

int main(int argc, char *argv[])
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.setf(ios_base::fixed);
  cout.precision(15);

  int n;
  lli k;
  while (cin >> n >> k) {
    vec<lli> a(n);
    cin >> a;
    sort(a.begin(), a.end());
    reverse(a.begin(), a.end());

    auto fn = [&] (lli x) {
      lli z = 0;
      each (i, a) {
        z += max(0LL, i - x + 1);
      }
      return z;
    };

    lli small = 0;
    lli large = 1LL << 60;
    while (small + 1 < large) {
      lli mid = (small + large) / 2;
      if (fn(mid) <= k) large = mid;
      else small = mid;
    }

    // cout << small << ' ' << fn(small) << endl;
    // cout << large << ' ' << fn(large) << endl;

    lli z = 0;
    const lli y = fn(large);
    each (i, a) {
      if (large <= i) {
        lli d = (i - large + 1);
        z += i * d - (d * (d - 1) / 2);
        k -= d;
        i = large - 1;
      }
    }
    // cout << a << endl;
    sort(a.begin(), a.end());
    reverse(a.begin(), a.end());
    each (i, a) {
      if (k == 0) break;
      --k;
      z += i;
    }
    cout << z << endl;
  }

  return 0;
}
