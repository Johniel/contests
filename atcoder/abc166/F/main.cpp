// atcoder/abc166/F/main.cpp
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

const int N = 1e5 + 5;
const int M = 3;
char path[N][M][M][M];
int memo[N][M][M][M];
str s[N];
int p, q, r;
char t[N];
int rec(int nth, int a, int b, int c)
{
  if (min({a, b, c}) < 0) return false;
  if (s[nth] == "@") {
    p = a;
    q = b;
    r = c;
    return true;
  }
  int& ret = memo[nth][a][b][c];
  if (ret != -1) return ret;

  if (s[nth] == "AB") {
    if (a) {
      path[nth][a - 1][b + 1][c] = 'B';
      if (rec(nth + 1, a - 1, b + 1, c)) {
        t[nth] = 'B';
        return ret = true;
      }
    }
    if (b) {
      path[nth][a + 1][b - 1][c] = 'A';
      if (rec(nth + 1, a + 1, b - 1, c)) {
        t[nth] = 'A';
        return ret = true;
      }
    }
  }

  if (s[nth] == "AC") {
    if (a) {
      path[nth][a - 1][b][c + 1] = 'C';
      if (rec(nth + 1, a - 1, b, c + 1)) {
        t[nth] = 'C';
        return ret = true;
      }
    }
    if (c) {
      path[nth][a + 1][b][c - 1] = 'A';
      if (rec(nth + 1, a + 1, b, c - 1)) {
        t[nth] = 'A';
        return ret = true;
      }
    }
  }

  if (s[nth] == "BC") {
    if (b) {
      path[nth][a][b - 1][c + 1] = 'C';
      if (rec(nth + 1, a, b - 1, c + 1)) {
        t[nth] = 'C';
        return ret = true;
      }
    }
    if (c) {
      path[nth][a][b + 1][c - 1] = 'B';
      if (rec(nth + 1, a, b + 1, c - 1)) {
        t[nth] = 'B';
        return ret = true;
      }
    }
  }

  return ret = false;
}

int main(int argc, char *argv[])
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.setf(ios_base::fixed);
  cout.precision(15);

  int n, a, b, c;
  while (cin >> n >> a >> b >> c) {
    fill(&memo[0][0][0][0], &memo[N - 1][2][2][2] + 1, -1);
    for (int i = 0; i < n; ++i) {
      cin >> s[i];
    }
    s[n] = "@";
    int x =rec(0, min(a, M - 1), min(b, M - 1), min(c, M - 1));
    if (!x) {
      cout << "No" << endl;
    } else {
      cout << "Yes" << endl;
      for (int i = 0; i < n; ++i) {
        cout << t[i] << endl;
      }
    }
  }

  return 0;
}
