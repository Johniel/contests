// codeforces/770div2/D/main.cpp
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

vec<int> fn(vec<int> v)
{
  vec<pair<int, int>> u;
  int mx = -1;
  for (int i = 0; i < v.size(); ++i) {
    cout << "?";
    for (int j = 0; j < v.size(); ++j) {
      if (i != j) {
        cout << ' ' << v[j]+1;
      }
    }
    cout << endl;
    int z;
    cin >> z;
    setmax(mx, z);
    u.push_back({z, v[i]});
  }
  vec<int> z;
  each (i, u) {
    if (i.first != mx) z.push_back(i.second);
  }
  return z;
}

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
    vec<int> v;
    for (int i = 0; i < n; ++i) {
      v.push_back(i);
    }
    while (3 <= v.size()) {
      vec<int> u;
      u.push_back(v.back()); v.pop_back();
      u.push_back(v.back()); v.pop_back();
      u.push_back(v.back()); v.pop_back();
      if (v.empty()) {
        for (int i = 0; i < n; ++i) {
          if (count(u.begin(), u.end(), i) == 0) {
            u.push_back(i);
            break;
          }
        }
      } else {
        u.push_back(v.back());
        v.pop_back();
      }
      u = fn(u);
      each (i, u) v.push_back(i);
    }
    if (v.size() == 1) v.push_back(0 + (v[0] == 0));
    cout << "! " << v[0]+1 << ' ' << v[1]+1 << endl;
  }

  return 0;
}
