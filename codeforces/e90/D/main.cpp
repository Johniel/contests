// codeforces/e90/D/main.cpp
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

  int n;
  while (cin >> n) {
    vec<lli> a(n);
    cin >> a;
    // cout << "a: " << a << endl;

    lli mx = 0;
    for (int i = 0; i < a.size(); i+=2) {
      mx += a[i];
    }

    vec<lli> o = a;
    vec<lli> e = a;

    for (int i = 0; i < a.size(); ++i) {
      if (i % 2) e[i] = 0;
      else o[i] = 0;
    }
    // cout << e << endl;
    // cout << o << endl;

    vec<lli> x({0});
    vec<lli> y({0});
    for (int i = 0; i < a.size(); ++i) {
      x.push_back(x.back() + e[i]);
      y.push_back(y.back() + o[i]);
    }

    // cout << x << endl;
    // cout << y << endl;

    priority_queue<vec<lli>> O;
    priority_queue<vec<lli>> E;
    for (int i = 0; i <= a.size(); ++i) {
      if (1 < i) {
        int j = i;
        int k = i;
        auto v = (i % 2 ? O.top() : E.top());
        // cout << v << endl;
        lli s = (x.back() - x[j]) + v[1];
        lli t = y[k] - v[2];
        setmax(mx, s + t);
        // cout << "(("<<x.back() <<"-"<<x[j]<< ")+" << v[1] << ")+(" << y[k] <<"-"<< v[2] << ")=" << s+t << endl;
      }
      // if (i) q.push({x[i-1] - y[i-1], x[i-1], y[i-1]});
      if (i%2) O.push({x[i] - y[i], x[i], y[i]});
      else E.push({x[i] - y[i], x[i], y[i]});
    }

    cout << mx << endl;
    // cout << endl;
  }

  return 0;
}
