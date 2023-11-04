// atcoder/abc025/C/main.cpp
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
template<typename P, typename Q> inline pair<Q, P> reverse(pair<P, Q> p) { return make_pair(p.second, p.first); }

using lli = long long int;
using ull = unsigned long long;
using point = complex<double>;
using str = string;
template<typename T> using vec = vector<T>;

constexpr lli mod = 1e9 + 7;

int b[2][3];
int c[3][2];

const int N = (1 << 9) + 5;
map<string, pair<int, int>> memo;
pair<int, int> rec(string s)
{
  if (memo.count(s)) return memo[s];

  char g[3][3];
  int k = 0;
  for (int i = 0; i < 3; ++i) {
    for (int j = 0; j < 3; ++j) {
      g[i][j] = s[k++];
    }
  }

  if (count(s.begin(), s.end(), '-') == 0) {
    int x = 0;
    int y = 0;
    for (int i = 0; i < 2; ++i) {
      for (int j = 0; j < 3; ++j) {
        if (g[i][j] == g[i + 1][j]) {
          x += b[i][j];
        } else {
          y += b[i][j];
        }
      }
    }
    for (int i = 0; i < 3; ++i) {
      for (int j = 0; j < 2; ++j) {
        if (g[i][j] == g[i][j + 1]) {
          x += c[i][j];
        } else {
          y += c[i][j];
        }
      }
    }
    return make_pair(y, x);
  }

  pair<int, int> opt = make_pair(-1, -1);

  int p = count(s.begin(), s.end(), 'x');
  int q = count(s.begin(), s.end(), 'o');
  char c = (p < q) ? 'x' : 'o';

  k = 0;
  for (int i = 0; i < 3; ++i) {
    for (int j = 0; j < 3; ++j) {
      if (g[i][j] == '-') {
        s[k] = c;
        pair<int, int> z = rec(s);
        swap(z.first, z.second);
        setmax(opt, z);
        s[k] = '-';
      }
      ++k;
    }
  }

  return memo[s] = opt;
}

int main(int argc, char *argv[])
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  while (true) {
    bool f = true;
    for (int i = 0; i < 2; ++i) {
      for (int j = 0; j < 3; ++j) {
        f = f && (cin >> b[i][j]);
      }
    }
    for (int i = 0; i < 3; ++i) {
      for (int j = 0; j < 2; ++j) {
        f = f && (cin >> c[i][j]);
      }
    }

    if (!f) break;
    memo.clear();
    auto p = rec("---------");
    cout << p.first << endl;
    cout << p.second << endl;
  }

  return 0;
}
