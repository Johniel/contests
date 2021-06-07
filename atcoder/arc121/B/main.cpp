// atcoder/arc121/B/main.cpp
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
  while (cin >> n) {
    n *= 2;
    vec<pair<lli, char>> v(n);
    cin >> v;

    vec<lli> r, g, b;
    each (i, v) {
      if (i.second == 'R') r.push_back(i.first);
      if (i.second == 'G') g.push_back(i.first);
      if (i.second == 'B') b.push_back(i.first);
    }
    sort(r.begin(), r.end());
    sort(g.begin(), g.end());
    sort(b.begin(), b.end());

    lli mn = 1LL << 60;

    if (r.size() % 2 == 0 && g.size() % 2 == 0 && b.size() % 2 == 0) {
      mn = 0;
    }
    if (0) ;
    else if (r.size() % 2 == 0) ;
    else if (g.size() % 2 == 0) swap(r, g);
    else if (b.size() % 2 == 0) swap(r, b);

    each (i, g) {
      auto itr = lower_bound(b.begin(), b.end(), i);
      if (itr != b.end()) setmin(mn, abs(i - *itr));
      if (itr != b.begin()) {
        --itr;
        setmin(mn, abs(i - *itr));
      }
    }

    lli x = 1LL << 60;
    lli y = 1LL << 60;
    each (i, r) {
      auto itr = lower_bound(b.begin(), b.end(), i);
      if (itr != b.end()) setmin(x, abs(i - *itr));
      if (itr != b.begin()) {
        --itr;
        setmin(x, abs(i - *itr));
      }
    }
    each (i, r) {
      auto itr = lower_bound(g.begin(), g.end(), i);
      if (itr != g.end()) setmin(y, abs(i - *itr));
      if (itr != g.begin()) {
        --itr;
        setmin(y, abs(i - *itr));
      }
    }
    setmin(mn, x + y);
    cout << mn << endl;
  }

  return 0;
}
