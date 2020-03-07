// atcoder/abc158/E/main.cpp
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

int di[] = {0, 1, -1, 0, 1, -1, 1, -1};
int dj[] = {1, 0, 0, -1, 1, -1, -1, 1};
constexpr lli mod = 1e9 + 7;

int main(int argc, char *argv[])
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n, p;
  str s;
  while (cin >> n >> p >> s) {
    if (p == 2 || p == 5) {
      lli sum = 0;
      for (int i = 0; i < s.size(); ++i) {
        if ((s[i] - '0') % p == 0) {
          sum += i + 1;
        }
      }
      cout << sum << endl;
      continue;
    }

    reverse(s.begin(), s.end());

    const int N = 2 * 1e5 + 5;
    static lli u[N];
    fill(u, u + N, -1);
    u[0] = (s[0] - '0') % p;

    lli w = 1;
    for (int i = 1; i < s.size(); ++i) {
      (w *= 10) %= p;
      u[i] = ((s[i] - '0') * w + u[i - 1]) % p;
    }

    lli sum = count(u, u + N, 0);
    map<lli, lli> m;
    for (int i = 0; i < s.size(); ++i) {
      sum += m[u[i]];
      ++m[u[i]];
    }
    cout << sum << endl;
  }

  return 0;
}
