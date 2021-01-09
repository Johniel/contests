// codeforces/695div2/B/main.cpp
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
    vec<int> a(n);
    cin >> a;

    int x = 0;
    for (int i = 1; i + 1 < a.size(); ++i) {
      if (a[i - 1] < a[i] && a[i] > a[i + 1]) ++x;
      if (a[i - 1] > a[i] && a[i] < a[i + 1]) ++x;
    }

    int mn = x;

    for (int i = 1; i + 1 < a.size(); ++i) {
      const int tmp = a[i];

      int p = 0;
      for (int j = i - 1; j <= i + 1; ++j) {
        if (0 <= j - 1 && j + 1 < n) {
          if (a[j - 1] < a[j] && a[j] > a[j + 1]) ++p;
          if (a[j - 1] > a[j] && a[j] < a[j + 1]) ++p;
        }
      }

      int y = 0;
      a[i] = a[i - 1];
      for (int j = max(i - 1, 0); j <= i + 1; ++j) {
        if (0 <= j - 1 && j + 1 < n) {
          if (a[j - 1] < a[j] && a[j] > a[j + 1]) ++y;
          if (a[j - 1] > a[j] && a[j] < a[j + 1]) ++y;
        }
      }

      int z = 0;
      a[i] = a[i + 1];
      for (int j = i - 1; j <= i + 1; ++j) {
        if (0 <= j - 1 && j + 1 < n) {
          if (a[j - 1] < a[j] && a[j] > a[j + 1]) ++z;
          if (a[j - 1] > a[j] && a[j] < a[j + 1]) ++z;
        }
      }

      // cout << x << ' ' << p << ' ' << y << ' ' << z << endl;
      setmin(mn, min(x - p + y, x - p + z));
      a[i] = tmp;
    }


    cout << mn << endl;
  }

  return 0;
}
