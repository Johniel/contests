// atcoder/m-solutions2020/F/main.cpp
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

const lli inf = 1LL << 55;
struct S {
  lli i, j;
  char d;
};

lli fn1(vec<S>& v)
{
  map<lli, vec<pair<lli, char>>> m;
  each (k, v) {
    if (k.d == 'L' || k.d == 'R') m[k.j].push_back(make_pair(k.i, k.d));
  }

  lli mn = inf;
  each (w, m) {
    vec<pair<lli, char>> u;
    each (k, w.second) u.push_back(k);
    sort(u.begin(), u.end());
    int last_r = -1;
    for (int i = 0; i < u.size(); ++i) {
      if (u[i].second == 'L' && last_r != -1) {
        setmin(mn, u[i].first - u[last_r].first);
      }
      if (u[i].second == 'R') {
        last_r = i;
      }
    }
  }

  return mn * 5;
}

lli fn2(vec<S>& v)
{
  map<lli, vec<S>> m;
  each (k, v) {
    m[k.i + k.j].push_back(k);
  }

  lli mn = inf;
  each (k, m) {
    priority_queue<lli, vec<lli>, greater<lli>> r, u;
    each (w, k.second) {
      if (w.d == 'R') r.push(w.i);
      if (w.d == 'U') u.push(w.i);
    }
    while (r.size() && u.size()) {
      if (r.top() < u.top()) setmin(mn, u.top() - r.top());
      if (r.top() < u.top()) r.pop();
      else u.pop();
    }
  }
  return mn * 10;
}

int main(int argc, char *argv[])
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.setf(ios_base::fixed);
  cout.precision(15);

  int n;
  while (cin >> n) {
    vec<S> v;
    for (int i = 0; i < n; ++i) {
      int a, b;
      char c;
      cin >> a >> b >> c;
      v.push_back(S{a, b, c});
    }

    map<char, char> rot90;
    rot90['R'] = 'U';
    rot90['U'] = 'L';
    rot90['L'] = 'D';
    rot90['D'] = 'R';

    lli mn = inf;
    for (int _ = 0; _ < 4; ++_) {
      each (k, v) {
        lli ni = -k.j;
        lli nj = k.i;
        k.i = ni;
        k.j = nj;
        k.d = rot90[k.d];
      }
      setmin(mn, fn1(v));
      setmin(mn, fn2(v));
    }
    if (mn == inf) cout << "SAFE" << endl;
    else cout << mn << endl;
  }

  return 0;
}
