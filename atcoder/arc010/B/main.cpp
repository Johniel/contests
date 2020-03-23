// atcoder/arc010/B/main.cpp
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
  std::ios_base::sync_with_stdio(0);
  std::cin.tie(0);
  std::cout.setf(std::ios_base::fixed);
  std::cout.precision(15);

  int n;
  while (cin >> n) {
    set<pair<int, int>> h;
    for (int i = 0; i < n; ++i) {
      int m, d;
      char c;
      cin >> m >> c >> d;
      h.insert(make_pair(m, d));
    }

    map<int, int> lim;
    lim[2] = 29;
    lim[4] = lim[6] = lim[9] = lim[11] = 30;
    lim[1] = lim[3] = lim[5] = lim[7] = lim[8] = lim[10] = lim[12] = 31;
    assert(lim.size() == 12);

    int mx = 0;
    int D = 6;
    int c = 0;
    int cnt = 0;

    int m = 1;
    int d = 1;
    for (int i = 0; i <= 365; ++i) {
      // cout << m << "/" << d << ", " << D << endl;
      if (D == 5 || D == 6) {
        if (h.count(make_pair(m, d))) ++c;
        // cout << "1." << m << "/" << d << ", " << D << endl;
        ++cnt;
      } else if (h.count(make_pair(m, d))) {
        // cout << "2." << m << "/" << d << ", " << D << endl;
        ++cnt;
      } else if (c) {
        // cout << "3." << m << "/" << d << endl;
        ++cnt;
        --c;
      } else {
        cnt = 0;
      }

      setmax(mx, cnt);
      D = (D + 1) % 7;
      if (lim[m] == d) {
        ++m;
        d = 1;
      } else {
        ++d;
      }
    }
    cout << mx << endl;
  }

  return 0;
}
