// atcoder/agc022/B/main.cpp
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
    if (n == 3) {
      cout << "2 5 63" << endl;
      continue;
    }
    if (n == 4) {
      cout << "2 5 20 63" << endl;
      continue;
    }
    const int N = 30000;
    vec<int> v;
    v.push_back(2);
    v.push_back(3);
    for (int i = 4; i <= N && v.size() + 1 < n; ++i) {
      if (i % 2 == 0 || i % 3 == 0) v.push_back(i);
    }
    lli sum = accumulate(v.begin(), v.end(), 0LL);
    if (sum % 6 == 5) {
      sum -= v.back(); v.pop_back();
    } else if (sum % 6 == 1) {
      sum -= v.back(); v.pop_back();
      sum -= v.back(); v.pop_back();
    }

    if (sum % 6 == 0) {
      for (int i = v.back() + 1; i <= N && v.size() < n; ++i) {
        if (i % 6 == 0) {
          v.push_back(i);
        }
      }
    } else if (sum % 6 == 2) {
      for (int i = v.back() + 1; i <= N && v.size() < n; ++i) {
        if (i % 2 == 0) {
          v.push_back(i);
        }
      }
    } else if (sum % 6 == 4) {
      for (int i = v.back() + 1; i <= N && v.size() < n; ++i) {
        if (i % 2 == 0) {
          v.push_back(i);
        }
      }
    } else if (sum % 6 == 3) {
      for (int i = v.back() + 1; i <= N && v.size() < n; ++i) {
        if (i % 6 == 3) {
          v.push_back(i);
          break;
        }
      }
      for (int i = v.back() + 1; i <= N && v.size() < n; ++i) {
        if (i % 6 == 0) {
          v.push_back(i);
        }
      }
    }
    each (i, v) cout << i << ' '; cout << endl;
    sum = accumulate(v.begin(), v.end(), 0LL);
    each (i, v) assert(__gcd((lli)i, sum) != 1);
    lli g = v.front();
    each (i, v) g = __gcd(g, (lli)i);
    assert(g == 1);
    assert(v.size() == n);
  }

  return 0;
}
