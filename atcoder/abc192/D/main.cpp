// atcoder/abc192/D/main.cpp
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

#include<boost/multiprecision/cpp_int.hpp>
#include<iostream>

using namespace std;
using namespace boost::multiprecision;

using bigint = boost::multiprecision::cpp_int;

int main(int argc, char *argv[])
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.setf(ios_base::fixed);
  cout.precision(15);

  str s;
  lli m;
  while (cin >> s >> m) {
    vec<int> v;
    each (c, s) v.push_back(c - '0');
    reverse(v.begin(), v.end());

    function<bool(bigint)> fn = [&] (bigint b) {
      vec<bigint> w;
      w.push_back(bigint("1"));
      for (int i = 0; w.size() < v.size(); ++i) {
        w.push_back(w.back() * b);
        if (m < w.back()) return false;
      }

      bigint sum = 0;
      for (int i = 0; i < v.size(); ++i) {
        sum += w[i] * v[i];
        if (m < sum) return false;
      }
      return true;
    };

    bigint small = *max_element(s.begin(), s.end()) - '0' + 1;
    if (!fn(small)) {
      cout << 0 << endl;
      continue;
    }
    if (s.size() == 1) {
      cout << 1 << endl;
      continue;
    }

    bigint large("90000000000000000000");
    while (small + 1 < large) {
      auto mid = (small + large) / 2;
      if (fn(mid)) small = mid;
      else large = mid;
    }

    bigint z = *max_element(s.begin(), s.end()) - '0' + 1;
    cout << small - z + 1 << endl;
  }

  return 0;
}
