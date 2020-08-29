// atcoder/abc177/E/main.cpp
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

bool setwise(const vec<lli>& v)
{
  lli x = v.front();
  each (i, v) x = __gcd(x, i);
  return x == 1;
}

int main(int argc, char *argv[])
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.setf(ios_base::fixed);
  cout.precision(15);

  const int N = 1e3 + 5;
  bool prime[N];
  fill(prime, prime + N, true);
  prime[0] = prime[1] = false;
  for (int i = 2; i * i < N; ++i) {
    for (int j = 2; i * j < N; ++j) {
      prime[i * j] = false;
    }
  }

  vec<lli> p;
  for (int i = 0; i < N; ++i) {
    if (prime[i]) p.push_back(i);
  }

  // cout << p.size() << endl;

  int n;
  while (cin >> n) {
    vec<lli> a(n);
    cin >> a;

    if (count(a.begin(), a.end(), 1) == a.size()) {
      cout << "pairwise coprime" << endl;
      continue;
    }

    map<int, int> m;

    each (i, a) {
      lli x = i;
      each (j, p) {
        if (x % j == 0) {
          ++m[j];
          while (x % j == 0) x /= j;
        }
      }
      if (x != 1) ++m[x];
    }

    int mx = 0;
    each (i, m) setmax(mx, i.second);

    if (mx == 1) cout << "pairwise coprime" << endl;
    else if (setwise(a)) cout << "setwise coprime" << endl;
    else cout << "not coprime" << endl;
  }

  return 0;
}
