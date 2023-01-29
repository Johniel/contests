// github.com/Johniel/contests
// codeforces/TypeDBForces2023/B/main.cpp

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

  lli n;
  while (cin >> n) {
    map<lli, int> m;
    for (lli i = 2; i * i <= n; ++i) {
      while (n % i == 0) {
        ++m[i];
        n /= i;
      }
    }
    if (n != 1) ++m[n];
    vec<pair<int, lli>> v;
    each (i, m) {
      v.push_back(make_pair(i.second, i.first));
    }
    sort(v.begin(), v.end());
    lli x = 1;
    each (i, v) x *= i.second;
    lli z = 0;
    lli y = 0;
    // cout << m << endl;
    each (i, v) {
      i.first -= y;
      if (i.first == 0) {
        x /= i.second;
        continue;
      }
      z += x * i.first;
      y += i.first;
      i.first = 0;
      x /= i.second;
      // cout << v << '+' <<  i.first << '*' << x << endl;
    }
    cout << z << endl;
  }

  return 0;
}
