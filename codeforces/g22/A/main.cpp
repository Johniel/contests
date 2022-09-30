// github.com/Johniel/contests
// codeforces/g22/A/main.cpp

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
template<typename E, size_t N> ostream& operator << (ostream& os, array<E, N>& a) { os << "[]{"; for (auto& i: a) os << i << ","; os << "}"; return os; }

template<typename T> inline T setmax(T& a, T b) { return a = std::max(a, b); }
template<typename T> inline T setmin(T& a, T b) { return a = std::min(a, b); }

using lli = long long int;
using ull = unsigned long long;
using str = string;
template<typename T> using vec = vector<T>;

constexpr array<int, 8> di({0, 1, -1, 0, 1, -1, 1, -1});
constexpr array<int, 8> dj({1, 0, 0, -1, 1, -1, -1, 1});
constexpr lli mod = 1e9 + 7;
// constexpr lli mod = 998244353;

lli fn(vec<lli> a, vec<lli> b)
{
  lli z = 0;
  while (a.size() && b.size()) {
    if (a.size() && b.size()) {
      z += a.back() * 2;
      a.pop_back();
    }
    if (a.size() && b.size()) {
      z += b.back() * 2;
      b.pop_back();
    }
  }
  return z + accumulate(a.begin(), a.end(), 0LL) + accumulate(b.begin(), b.end(), 0LL);
}

int main(int argc, char *argv[])
{
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.setf(ios_base::fixed);
  cout.precision(15);

  int _;
  cin >> _;

  int n;
  while (cin >> n) {
    vec<int> t(n);
    vec<lli> d(n);
    cin >> t >> d;

    vec<lli> a, b;
    for (int i = 0; i < n; ++i) {
      if (t[i] == 0) a.push_back(d[i]);
      else b.push_back(d[i]);
    }
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    cout << max(fn(a, b), fn(b, a)) << endl;
  }

  return 0;
}
