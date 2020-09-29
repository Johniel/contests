// atcoder/arc025/B/main.cpp
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

struct Acc2D {
  vector<vector<lli>> sum;
  Acc2D(vector<vector<lli>> v) {
    const int N = v.size() + 1;
    sum.resize(N);
    fill(sum.begin(), sum.end(), vector<lli>(N, 0));
    for (int i = 0; i < v.size(); ++i) {
      for (int j = 0; j < v.size(); ++j) {
        sum[i + 1][j + 1] = v[i][j];
      }
    }
    for (int i = 1; i < N; ++i) {
      for (int j = 0; j < N; ++j) {
        sum[i][j] += sum[i - 1][j];
      }
    }
    for (int i = 0; i < N; ++i) {
      for (int j = 1; j < N; ++j) {
        sum[i][j] += sum[i][j - 1];
      }
    }
  }
  lli query(int ai, int aj, int bi, int bj) {
    return sum[bi][bj] + sum[ai][aj] - sum[ai][bj] - sum[bi][aj];
  }
};

int main(int argc, char *argv[])
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.setf(ios_base::fixed);
  cout.precision(15);

  int h, w;
  while (cin >> h >> w) {
    const int N = 100 + 1;
    vec<vec<lli>> g(N, vec<lli>(N, (1 << 20)));
    for (int i = 0; i < h; ++i) {
      for (int j = 0; j < w; ++j) {
        cin >> g[i][j];
        if (i % 2 == j % 2) g[i][j] *= -1;
      }
    }
    Acc2D sum(g);
    int mx = 0;
    for (int i = 0; i < h; ++i) {
      for (int j = 0; j < w; ++j) {
        for (int a = i+1; a <= h; ++a) {
          for (int b = j+1; b <= w; ++b) {
            if (sum.query(i, j, a, b) == 0) {
              // cout << make_pair(i, j) << ' ' << make_pair(a, b) << ' ' << (a-i) * (b-j) << endl;
              setmax(mx, (a-i) * (b-j));
            }
          }
        }
      }
    }
    cout << mx << endl;
  }

  return 0;
}
