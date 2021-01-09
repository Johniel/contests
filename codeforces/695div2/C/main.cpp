// codeforces/695div2/C/main.cpp
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

  int n1, n2, n3;
  while (cin >> n1 >> n2 >> n3) {
    const int N = 3;
    vec<lli> v[N];
    v[0] = vec<lli>(n1);
    v[1] = vec<lli>(n2);
    v[2] = vec<lli>(n3);
    cin >> v[0] >> v[1] >> v[2];

    for (int i = 0; i < N; ++i) {
      sort(v[i].begin(), v[i].end());
    }

    lli sum[N];
    for (int i = 0; i < N; ++i) {
      sum[i] = accumulate(v[i].begin(), v[i].end(), 0LL);
    }

    lli mx = -(1LL << 60);
    for (int i = 0; i < N; ++i) {
      for (int j = 0; j < N; ++j) {
        for (int k = 0; k < N; ++k) {
          if (i == j || i == k || j == k) continue;
          lli a = v[i].back();
          lli b = v[j].front();
          lli c = v[k].front();

          {
            lli x = sum[i] - a;
            lli y = c - (sum[j] - b);
            lli z = b - (sum[k] - c);
            // cout << a << ' ' << b << ' ' << c << ":" << x << ' ' << y << ' ' << z << endl;

            // cout << a << "-((" << y << "-" << x << ")-" << z << ")" <<

            setmax(mx, a - y - (z - x));
            setmax(mx, a - (y - (z - x)));
            setmax(mx, a - ((z - x) - y));

            setmax(mx, a - (y - x) - z);
            setmax(mx, a - ((y - x) - z));
            setmax(mx, a - (z - (y - x)));
          }
        }
      }
    }
    cout << mx << endl;
  }


  return 0;
}
