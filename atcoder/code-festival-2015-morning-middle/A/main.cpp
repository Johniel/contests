// atcoder/code-festival-2015-morning-middle/A/main.cpp
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
  lli m, r;
  while (cin >> n >> k >> m >> r) {
    vec<lli> v(n-1);
    cin >> v;
    sort(v.begin(), v.end());

    auto fn = [&] (lli x, vec<lli> v) {
      v.push_back(x);
      sort(v.begin(), v.end());
      reverse(v.begin(), v.end());
      lli sum = 0;
      for (int i = 0; i < k; ++i) {
        sum += v[i];
      }
      return r * k <= sum;
    };

    lli small = 0;
    lli large = m;
    while (small + 1 < large) {
      lli mid = (small + large) / 2;
      if (!fn(mid, v)) small = mid;
      else large = mid;
    }

    if (fn(0, v)) cout << 0 << endl;
    else if (fn(large, v)) cout << large << endl;
    else cout << -1 << endl;
  }

  return 0;
}
