// codeforces/620div2/D/main.cpp
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
template<typename P, typename Q> inline pair<Q, P> reverse(pair<P, Q> p) { return make_pair(p.second, p.first); }

using lli = long long int;
using ull = unsigned long long;
using point = complex<double>;
using str = string;
template<typename T> using vec = vector<T>;

constexpr lli mod = 1e9 + 7;

vector<int> fn1(const string s)
{
  const int n = s.size() + 1;
  vector<int> u(n, 0);

  int x = n;
  for (int i = 0; i < n; ++i) {
    if (i == n - 1 || s[i] == '>') {
      for (int j = i; 0 <= j && !u[j]; --j) {
        u[j] = x--;
      }
    }
  }

  return u;
}

vector<int> fn2(const string s)
{
  const int n = s.size() + 1;
  vector<int> u(n, 0);

  int x = 1;
  for (int i = 0; i < n; ++i) {
    if (i == n - 1 || s[i] == '<') {
      for (int j = i; 0 <= j && !u[j]; --j) {
        u[j] = x++;
      }
    }
  }

  return u;
}

bool test(string s, vector<int> v)
{
  set<int> vis;
  each (i, v) {
    assert(vis.count(i) == 0);
    vis.insert(i);
  }
  assert(*vis.begin() == 1);

  assert(s.size() + 1 == v.size());
  for (int i = 0; i < s.size(); ++i) {
    if (s[i] == '<') assert(v[i] < v[i + 1]);
    if (s[i] == '>') assert(v[i] > v[i + 1]);
  }
  return true;
}

int main(int argc, char *argv[])
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int _;
  cin >> _;

  string s;
  while (cin >> _ >> s) {
    vector<int> a = fn1(s);
    vector<int> b = fn2(s);

    // cout << s << endl;
    each (i, a) cout << i << ' ' ; cout << endl;
    each (i, b) cout << i << ' ' ; cout << endl;

    test(s, a);
    test(s, b);

    // cout << endl;
  }

  return 0;
}
