// atcoder/abc175/D/main.cpp
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

const int N = 5000 + 5;
const lli inf = 1LL << 60;

int p[N];
lli c[N];

int n;
lli k;

lli vis[N];
lli cycle_size[N];
lli cycle_score[N];

void rec1(int curr, int depth, lli& S, lli& C)
{
  if (vis[curr] != -1) {
    C = depth - vis[curr];
    return ;
  }
  vis[curr] = depth;
  S += c[p[curr]];
  rec1(p[curr], depth + 1, S, C);
  cycle_size[curr] = C;
  cycle_score[curr] = S;
  return ;
}

lli rec2(int curr, int depth, lli S)
{
  if (k < depth) return -inf;
  if (vis[curr]) {
    return -inf;
  }
  vis[curr] = true;

  S += c[curr];
  lli mx = -inf;
  lli z = ((k - depth) / cycle_size[curr]) * cycle_score[curr];

  // cout << curr+1 << ' ' << S << ' ' << z << endl;

  setmax(mx, S);
  setmax(mx, S + z);
  setmax(mx, rec2(p[curr], depth + 1, S));

  vis[curr] = false;
  return mx;
}

int main(int argc, char *argv[])
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.setf(ios_base::fixed);
  cout.precision(15);

  while (cin >> n >> k) {
    for (int i = 0; i < n; ++i) {
      cin >> p[i];
      --p[i];
    }
    for (int i = 0; i < n; ++i) {
      cin >> c[i];
    }

    fill(vis, vis + N, -1);
    fill(cycle_size, cycle_size + N, -1);
    for (int i = 0; i < n; ++i) {
      if (cycle_size[i] == -1) {
        lli S = 0;
        lli C = 0;
        rec1(i, 0, S, C);
      }
    }

    lli mx = *max_element(c, c + n);
    fill(vis, vis + N, false);
    for (int i = 0; i < n; ++i) {
      setmax(mx, rec2(p[i], 1, 0));
    }
    cout << mx << endl;
  }

  return 0;
}
