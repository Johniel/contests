// github.com/Johniel/contests
// codeforces/893div2/B/main.cpp

#include <bits/stdc++.h>

#define each(i, c) for (auto& i : c)
#define unless(cond) if (!(cond))
// #define endl "\n"

using namespace std;

template<typename P, typename Q> ostream& operator << (ostream& os, pair<P, Q> p) { os << "(" << p.first << "," << p.second << ")"; return os; }
template<typename P, typename Q> istream& operator >> (istream& is, pair<P, Q>& p) { is >> p.first >> p.second; return is; }
template<typename T> ostream& operator << (ostream& os, vector<T> v) { os << "("; for (auto& i: v) os << i << ","; os << ")"; return os; }
template<typename T> istream& operator >> (istream& is, vector<T>& v) { for (auto& i: v) is >> i; return is; }
template<typename T> ostream& operator << (ostream& os, set<T> s) { os << "#{"; for (auto& i: s) os << i << ","; os << "}"; return os; }
template<typename K, typename V> ostream& operator << (ostream& os, map<K, V> m) { os << "{"; for (auto& i: m) os << i << ","; os << "}"; return os; }
template<typename E, size_t N> istream& operator >> (istream& is, array<E, N>& a) { for (auto& i: a) is >> i; return is; }
template<typename E, size_t N> ostream& operator << (ostream& os, array<E, N>& a) { os << "[" << N << "]{"; for (auto& i: a) os << i << ","; os << "}"; return os; }

template<typename T> inline T setmax(T& a, T b) { return a = std::max(a, b); }
template<typename T> inline T setmin(T& a, T b) { return a = std::min(a, b); }

__attribute__((constructor)) static void ___initio(void) { ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.setf(ios_base::fixed); cout.precision(15); return ; }

using lli = long long int;
using ull = unsigned long long;
using str = string;
template<typename T> using vec = vector<T>;

constexpr array<int, 8> di({0, 1, -1, 0, 1, -1, 1, -1});
constexpr array<int, 8> dj({1, 0, 0, -1, 1, -1, -1, 1});
// constexpr lli mod = 1e9 + 7;
constexpr lli mod = 998244353;

int main(int argc, char *argv[])
{
  int _;
  cin >> _;

  int m;
  lli n, d;
  while (cin >> n >> m >> d) {
    vec<lli> v(m);
    cin >> v;
    each (i, v) --i;
    int idx = 0;
    lli mx = -1;
    int cnt = 0;
    for (int i = 0; i < v.size(); ++i) {
      lli x = 0;
      lli y = 0;

      {
        int prev = i ? v[i - 1] : 0;
        int curr = v[i];
        x += ((curr - 1) - prev) / d + 1;
        if (i + 1 < v.size()) {
          int next = v[i + 1];
          x += ((next - 1) - curr) / d + 1;
        } else {
          int next = n;
          x += ((next - 1) - curr) / d + 1;
        }
      }
      {
        int prev = i ? v[i - 1] : 0;
        if (i + 1 < v.size()) {
          int next = v[i + 1];
          y = ((next - 1) - prev) / d + 1;
        } else {
          // cout << (n-1) << '-' << prev << "/" << d << endl;
          y = ((n - 1) - prev) / d + 1;
        }
      }

      lli diff = x - y;

      if (v[i] == 0) diff = 0;

      // cout << v[i] << ':' << x << "->" << y << ' ' << diff << endl;
      cnt += (mx == diff);
      if (mx < diff) {
        mx = diff;
        idx = i;
        cnt = 1;
      }
    }
    v.erase(v.begin() + idx);
    // cout << v << endl;
    lli z = 1;
    lli prev = 0;
    for (int i = 0; i < v.size(); ++i) {
      if (v[i] == 0) continue;
      z += ((v[i] - 1) - prev) / d + 1;
      // cout << "+= (" << ((v[i] - 1) - prev) / d << ")+" << 1 << endl;
      prev = v[i];
    }
    if (v.back() != (n - 1)) {
      z += ((n - 1) - v.back()) / d;
      // cout << "+= " << '(' << n << '-' << v.back() << ')' << '/' << d << ", " << (n - v.back()) / d << endl;
    }
    cout << z << ' ' << cnt << endl;
    // break;
  }
  return 0;
}

// 66778899
// 20000000
// 3

// (- 837653445 66778899 1) ; 770874545
// 770874545
// 20000000
// 38

// (- 1000000000 837653445)
// 162346555
// 20000000
// 8

// (/ 66778899 20000000) ; 3
// (/ (- 837653445 66778899 1) 20000000) ; 38
// (/ (- 1000000000 837653445 1) 20000000) ; 8