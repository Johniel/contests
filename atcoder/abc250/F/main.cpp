// atcoder/abc250/F/main.cpp
// author: @___Johniel
// github: https://github.com/johniel/

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
// constexpr lli mod = 998244353;

lli cross(pair<lli, lli> a, pair<lli, lli> b)
{
  return (a.first * b.second - a.second * b.first);
}

lli area(pair<lli, lli> a, pair<lli, lli> b, pair<lli, lli> c)
{
  return abs(cross(a, b) + cross(b, c) + cross(c, a));
}

lli area(vec<pair<lli, lli>> v)
{
  lli sum = cross(v.back(), v.front());
  for (int i = 0; i + 1 < v.size(); ++i) {
    sum += cross(v[i], v[i + 1]);
  }
  return abs(sum);
}


int main(int argc, char *argv[])
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.setf(ios_base::fixed);
  cout.precision(15);

  // cout << area({-1, 3}, {-3, 1}, {-1, -1}) << endl;

  int n;
  while (cin >> n) {
    vec<pair<lli, lli>> v(n);
    cin >> v;

    const lli A = area(v);
    // cout << "A: " << A << endl;

    const lli inf = 1LL << 62;
    lli mn = inf;
    deque<pair<lli, lli>> q;
    lli a = 0;
    for (int _i = 0; _i < v.size() * 2; ++_i) {
      int i = _i % v.size();
      if (q.size() < 2) {
        q.push_back(v[i]);
      } else {
        a += area(q.front(), q.back(), v[i]);
        q.push_back(v[i]);
      }
      const lli X = 4;
      setmin(mn, abs(A - a * X));
      // cout << q.front() << ' ' << q.back() << ' ' << A << "-" << a << "*" << X << endl;
      while (a * X > A && q.size()) {
        pair<lli, lli> p = q.front();
        q.pop_front();
        a -= area(q.front(), q.back(), p);
        setmin(mn, abs(A - a * X));
      }
      setmin(mn, abs(A - a * X));
    }
    cout << mn << endl;
  }

  return 0;
}
