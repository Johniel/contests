// codeforces/e93/D/main.cpp
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

vec<lli> r, g, b;
const int N = 200 + 2;
lli memo[N][N][N];
lli rec(int i, int j, int k)
{
  lli& ret = memo[i][j][k];
  if (ret != -1) return ret;

  lli mx = 0;

  if (i < r.size()) setmax(mx, rec(i + 1, j, k));
  if (j < g.size()) setmax(mx, rec(i, j + 1, k));
  if (k < b.size()) setmax(mx, rec(i, j, k + 1));

  if (i < r.size() && j < g.size()) setmax(mx, rec(i + 1, j + 1, k) + r[i] * g[j]);
  if (j < g.size() && k < b.size()) setmax(mx, rec(i, j + 1, k + 1) + g[j] * b[k]);
  if (i < r.size() && k < b.size()) setmax(mx, rec(i + 1, j, k + 1) + r[i] * b[k]);

  return ret = mx;
}

int main(int argc, char *argv[])
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.setf(ios_base::fixed);
  cout.precision(15);

  int R, G, B;
  while (cin >> R >> G >> B) {
    r.resize(R);
    g.resize(G);
    b.resize(B);
    cin >> r >> g >> b;

    sort(r.begin(), r.end());
    sort(g.begin(), g.end());
    sort(b.begin(), b.end());

    reverse(r.begin(), r.end());
    reverse(g.begin(), g.end());
    reverse(b.begin(), b.end());

    fill(&memo[0][0][0], &memo[N - 1][N - 1][N - 1] + 1, -1);
    cout << rec(0, 0, 0) << endl;
  }

  return 0;
}
