// atcoder/aising2020/D/main.cpp
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

const int N = 2 * 1e5 + 5;

int memo[N];
int rec(int x)
{
  if (x == 0) return 0;
  int& ret = memo[x];
  if (ret != -1) return ret;
  return ret = rec(x % __builtin_popcount(x)) + 1;
}

int main(int argc, char *argv[])
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.setf(ios_base::fixed);
  cout.precision(15);

  int n;
  str s;
  while (cin >> n >> s) {
    fill(memo, memo + N, -1);

    const int _1 = count(s.begin(), s.end(), '1');
    const int a = _1 + 1;
    const int b = _1 - 1;

    static int w0[N];
    static int w1[N];
    w0[0] = 1;
    w1[0] = 1;
    for (int i = 1; i < N; ++i) {
      if (a) w0[i] = (w0[i - 1] * 2) % a;
      if (b) w1[i] = (w1[i - 1] * 2) % b;
    }

    int sum0 = 0;
    int sum1 = 0;
    for (int i = 0; i < s.size(); ++i) {
      if (s[i] == '1') {
        sum0 += w0[n - i - 1];
        sum1 += w1[n - i - 1];
        if (a) sum0 %= a;
        if (b) sum1 %= b;
      }
    }

    for (int i = 0; i < s.size(); ++i) {
      if (s[i] == '0') {
        int x = (sum0 + w0[n - i - 1]) % a;
        cout << rec(x)+1 << endl;
      }
      if (s[i] == '1') {
        if (b) {
          int x = (sum1 - w1[s.size() - i - 1] + b) % b;
          cout << rec(x)+1 << endl;
        } else {
          cout << 0 << endl;
        }
      }
    }
  }

  return 0;
}
