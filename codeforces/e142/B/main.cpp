// github.com/Johniel/contests
// codeforces/e142/B/main.cpp

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
template<typename T> using heap = priority_queue<T>;

constexpr array<int, 8> di({0, 1, -1, 0, 1, -1, 1, -1});
constexpr array<int, 8> dj({1, 0, 0, -1, 1, -1, -1, 1});
constexpr lli mod = 1e9 + 7;
// constexpr lli mod = 998244353;

int main(int argc, char *argv[])
{
  int _;
  cin >> _;

  vec<lli> v(4);
  while (cin >> v) {
    lli a = 0;
    lli b = 0;
    lli z = 0;

    lli s = accumulate(v.begin(), v.end(), 0LL);
    if (s == 0) {
      cout << 0 << endl;
      continue;
    }
    if (v[0] == 0) {
      cout << 1 << endl;
      continue;
    }

    a += v[0];
    b += v[0];
    z += v[0];
    v[0] = 0;

    lli mn = max(0LL, min(v[1], v[2]) - 1);
    z += mn * 2;
    v[1] -= mn;
    v[2] -= mn;

    if (0) {
    } else if (v[1] == v[2] && a && b) {
      z += v[1];
      z += v[2];
      v[1] = v[2] = 0;
    } else if (v[1] && v[2] && v[1] < v[2] && b) {
      ++a;
      --b;
      --v[1];
      ++z;
    } else if (v[1] && v[2] && v[1] > v[2] && b) {
      ++b;
      --a;
      --v[2];
      ++z;
    }

    mn = min(v[1], b);
    a += mn;
    b -= mn;
    v[1] -= mn;
    z += mn;

    mn = min(v[2], a);
    a -= mn;
    b += mn;
    v[2] -= mn;
    z += mn;

    mn = min(v[1], b);
    a += mn;
    b -= mn;
    v[1] -= mn;
    z += mn;

    mn = min({v[3], a, b});
    a -= mn;
    b -= mn;
    v[3] -= mn;
    z += mn;

    if (v[1] || v[2] || v[3]) ++z;

    cout << z << endl;
  }
  return 0;
}
