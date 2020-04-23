// codeforces/637div2/D/main.cpp
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

const int N = 2000 + 5;
int memo[N][N];
int path[N][N];

int cost[N][10];
vec<str> v;
int rec(int n, int k)
{
  if (k < 0) return false;
  if (n == v.size()) return k == 0;
  int& ret = memo[n][k];
  if (ret != -1) return ret;

  for (int i = 9; 0 <= i; --i) {
  // for (int i = 0; i < 9; ++i) {
    if (cost[n][i] == -1) continue;
    int x = rec(n + 1, k - cost[n][i]);
    if (x) {
      path[n][k] = i;
      return ret = 1;
    }
  }
  return ret = 0;
}

int main(int argc, char *argv[])
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.setf(ios_base::fixed);
  cout.precision(15);

  int n, k;
  while (cin >> n >> k) {
    fill(&memo[0][0], &memo[N - 1][N - 1] + 1, -1);
    v.resize(n);
    cin >> v;

    str D[10] = {"1110111", "0010010", "1011101", "1011011", "0111010", "1101011", "1101111", "1010010", "1111111", "1111011"};

    fill(&cost[0][0], &cost[N - 1][10 - 1] + 1, -1);
    for (int i = 0; i < v.size(); ++i) {
      for (int j = 0; j < 10; ++j) {
        int cnt = 0;
        for (int k = 0; k < 7; ++k) {
          if (v[i][k] ==  D[j][k]) continue;
          if (v[i][k] == '0' && D[j][k] == '1') {
            ++cnt;
          }
          if (v[i][k] == '1' && D[j][k] == '0') {
            cnt = -1;
            break;
          }
        }
        cost[i][j] = cnt;
      }
    }

    if (rec(0, k)) {
      for (int i = 0; i < n; ++i) {
        cout << path[i][k];
        k -= cost[i][path[i][k]];
      }
      cout << endl;
    } else {
      cout << -1 << endl;
    }
  }

  return 0;
}
