// github.com/Johniel/contests
// atcoder/arc158/A/main.cpp

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

  vec<int> v(3);
  while (cin >> v) {
    // 3,5,7
    // 0,2,4
    if (abs(v[0] - v[1]) % 2 || abs(v[1] - v[2]) % 2) {
      cout << -1 << endl;
      continue;
    }
    // 0,0,0
    // 0,2,4
    // 0,6,6

    // 0,0,0
    // 4,2,0
    // 8,2,2

    sort(v.begin(), v.end());
    lli a = (v[1] - v[0]) / 2;
    lli b = (v[2] - v[0]) / 4;
    lli c = (v[2] - v[1]) / 2;
    v[0] += min({a, b, c}) * 4;
    v[1] += min({a, b, c}) * 2;
    sort(v.begin(), v.end());
    if (0) {
    } else if (v[2] == v[1] && (v[1] - v[0]) % 6 == 0) {
      cout << min({a, b, c}) + (v[1] - v[0]) / 3 << endl;
    } else if (v[0] == v[1] && (v[2] - v[1]) % 6 == 0) {
      cout << min({a, b, c}) + (v[2] - v[1]) / 3 << endl;
    } else {
      cout << -1 << endl;
    }
  }
  return 0;
}
