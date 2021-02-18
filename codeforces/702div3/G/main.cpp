// codeforces/702div3/G/main.cpp
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

  int _;
  cin >> _;

  int n, m;
  int cnt = 0;
  while (cin >> n >> m) {
    vec<lli> a(n);
    cin >> a;
    vec<lli> v(m);
    cin >> v;
    lli sum = 0;
    vec<lli> u;
    each (i, a) {
      sum += i;
      u.push_back(sum);
    }
    for (int i = 1; i < u.size(); ++i) {
      setmax(u[i], u[i - 1]);
    }

    function<lli(lli, lli)> fn = [&] (lli x, lli y) {
      lli z = x - (sum * y);
      return lower_bound(u.begin(), u.end(), z) - u.begin();
    };

    vec<lli> r;
    each (i, v) {
      lli small = 0;
      lli large = (sum <= 0 ? 1 : (i + sum - 1) / sum);
      while (small + 1 < large) {
        lli mid = (small + large) / 2;
        if (fn(i, mid) < u.size()) large = mid;
        else small = mid;
      }
      if (0) ;
      else if (fn(i, small) < u.size()) r.push_back(small * n + fn(i, small));
      else if (fn(i, large) < u.size()) r.push_back(large * n + fn(i, large));
      else r.push_back(-1);
    }
    each (i, r) cout << i << ' '; cout << endl;
  }

  return 0;
}
