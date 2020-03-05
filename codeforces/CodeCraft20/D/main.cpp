// codeforces/CodeCraft20/D/main.cpp
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

int di[] = {0, 1, 0, -1, 1, -1, 1, -1};
int dj[] = {1, 0, -1, 0, 1, -1, -1, 1};
constexpr lli mod = 1e9 + 7;

const int N = 1e3 + 5;
pair<int, int> g[N][N];

char h[N][N];
int n;

static str D = "RDLU";

void rec(int i, int j)
{
  for (int d = 0; d < 4; ++d) {
    int ni = i + di[d];
    int nj = j + dj[d];
    unless (0 <= ni && ni < n) continue;
    unless (0 <= nj && nj < n) continue;
    if (g[ni][nj] == g[i][j] && h[ni][nj] == '@') {
      h[ni][nj] = D[(d + 2) % 4];
      rec(ni, nj);
    }
  }
  return ;
}

void show_h()
{
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      cout << h[i][j];
    }
    cout << endl;
  }
  return ;
}

int main(int argc, char *argv[])
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  while (cin >> n) {
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j) {
        cin >> g[i][j];
        if (g[i][j].first != -1) {
          --g[i][j].first;
          --g[i][j].second;
        }
      }
    }

    fill(&h[0][0], &h[N - 1][N - 1] + 1, '@');

    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j) {
        if (g[i][j] == make_pair(i, j)) {
          h[i][j] = 'X';
          rec(i, j);
        }
      }
    }

    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j) {
        for (int d = 0; d < 4; ++d) {
          int ni = i + di[d];
          int nj = j + dj[d];
          unless (0 <= ni && ni < n) continue;
          unless (0 <= nj && nj < n) continue;
          auto p = make_pair(-1, -1);
          if (g[i][j] == p && g[ni][nj] == p) {
            h[i][j] = D[d];
            h[ni][nj] = D[(d + 2) % 4];
            rec(i, j);
            rec(ni, nj);
          }
        }
      }
    }

    bool f = true;
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j) {
        f = f && (h[i][j] != '@');
      }
    }
    if (f) {
      cout << "VALID" << endl;
      show_h();
    } else {
      cout << "INVALID" << endl;
    }
  }

  return 0;
}
