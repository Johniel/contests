// github.com/Johniel/contests
// atcoder/abc271/F/main.cpp

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


const int M = 1024 + 3;
const int p = 1 << 10;

const int N = 20 + 3;
int g[N][N];

int n;

map<int, lli> m1[N][N];
void rec1(int i, int j, int k)
{
  if (i + j == n - 1) {
    ++m1[i][j][k];
    return ;
  }
  if (i + 1 < n) rec1(i + 1, j, k ^ g[i + 1][j]);
  if (j + 1 < n) rec1(i, j + 1, k ^ g[i][j + 1]);
  return ;
}

map<int, lli> m2[N][N];
void rec2(int i, int j, int k)
{
  if (i + j == n - 1) {
    ++m2[i][j][k];
    return ;
  }
  if (0 <= i - 1) rec2(i - 1, j, k ^ g[i - 1][j]);
  if (0 <= j - 1) rec2(i, j - 1, k ^ g[i][j - 1]);
  return ;
}

int main(int argc, char *argv[])
{
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.setf(ios_base::fixed);
  cout.precision(15);

  while (cin >> n) {
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j) {
        cin >> g[i][j];
      }
    }
    for (int i = 0; i < N; ++i) {
      for (int j = 0; j < N; ++j) {
        m1[i][j] = m2[i][j] = map<int, lli>();
      }
    }
    rec1(0, 0, g[0][0]);
    rec2(n - 1, n - 1, g[n - 1][n - 1]);

    lli z = 0;
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j) {
        each (k, m1[i][j]) {
          int x = k.first ^ g[i][j];
          if (m2[i][j].count(x)) {
            z += k.second * m2[i][j][x];
          }
        }
      }
    }
    cout << z << endl;
  }

  return 0;
}
