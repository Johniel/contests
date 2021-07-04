// codeforces/729div2/B/main.cpp
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

  lli n, a, b;
  while (cin >> n >> a >> b ) {
    vec<lli> v;
    {
      lli x = 1;
      for (int i = 0; i < 40; ++i) {
        x *= a;
        if (n < x) break;
        v.push_back(x);
      }
      v.push_back(1);
      sort(v.begin(), v.end());
      v.erase(unique(v.begin(), v.end()), v.end());
    }

    bool f = ((n - 1) % b == 0);
    for (int i = 0; i < v.size(); ++i) {
      lli y = n - v[i];
      if (y < 0) break;
      for (int j = 0; j < i; ++j) {
        lli z = y / (v[j] * b);
        y -= z * (v[j] * b);
      }
      if (y == 0) f = true;
    }

    cout << (f ? "Yes" : "No") << endl;
  }


  return 0;
}
