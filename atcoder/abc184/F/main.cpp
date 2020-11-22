// atcoder/abc184/F/main.cpp
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

  int n, t;
  while (cin >> n >> t) {
    vec<lli> a(n / 2);
    vec<lli> b(n - (n / 2));
    cin >> a >> b;

    // cout << a << endl;
    // cout << b << endl;

    vec<lli> p, q;

    lli z1[50];
    lli z2[50];
    const lli inf = 1LL << 60;
    fill(z1, z1 + 50, inf);
    fill(z2, z2 + 50, inf);
    z1[0] = z2[0] = 0;

    for (int bit = 0; bit < (1 << a.size()); ++bit) {
      lli sum = 0;
      for (int i = 0; i < a.size(); ++i) {
        if (bit & (1 << i)) sum += a[i];
      }
      int T = __builtin_popcount(bit);
      p.push_back(sum);
      if (sum <= t) setmin(z1[T], sum);
    }

    for (int bit = 0; bit < (1 << b.size()); ++bit) {
      lli sum = 0;
      for (int i = 0; i < b.size(); ++i) {
        if (bit & (1 << i)) sum += b[i];
      }
      int T = __builtin_popcount(bit);
      if (sum <= t) setmin(z2[T], sum);
      q.push_back(sum);
    }

    sort(p.begin(), p.end());
    sort(q.begin(), q.end());

    lli mx = 0;
    each (i, p) {
      auto itr = lower_bound(q.begin(), q.end(), t - i + 1);
      if (itr != q.begin()) {
        --itr;
        setmax(mx, i + *itr);
      }
    }
    cout << mx << endl;

    // cout << "z1" << endl;
    // for (int i = 0; i < a.size(); ++i) {
    //   cout << z1[i] << endl;
    // }
    // cout << "z2" << endl;
    // for (int i = 0; i < b.size(); ++i) {
    //   cout << z2[i] << endl;
    // }

    // lli mx = 0;
    // lli p = inf;
    // for (int i = 0; i < 50; ++i) {
    //   for (int j = 0; j < 50; ++j) {
    //     unless (z1[i] + z2[j] < inf) continue;
    //     setmax(mx, z1[i] + z2[j]);
    //     // if (z1[i] + z2[j] <= t) {
    //     //   mx = i + j;

    //     // }
    //     // if (i + j == mx) {
    //     //   setmin(p, z1[i] + z2[j]);
    //     // }
    //   }
    // }
    // cout << p << endl;
    // cout << make_pair(p, mx) << endl;
  }

  return 0;
}
