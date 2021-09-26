// atcoder/abc220/F/main.cpp
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

const int N = 2 * 1e5 + 3;
vec<int> g[N];

pair<int, lli> memo1[N];
pair<int, lli> memo2[N];

// 頂点数,距離の総和
pair<int, lli> rec1(int curr, int prev)
{
  pair<int, lli> p = make_pair(1, 0);
  each (next, g[curr]) {
    if (next == prev) continue;
    auto q = rec1(next, curr);
    p.first += q.first;
    p.second += q.second + q.first;
  }
  return memo1[curr] = p;
}

void rec2(int curr, int prev, pair<int, lli> z)
{
  if (curr) {
    pair<int, lli> p = z;
    p.second += p.first;
    each (next, g[curr]) {
      if (next == prev) continue;
      auto q = memo1[next];
      p.first += q.first;
      p.second += q.second + q.first;
    }
    memo2[curr] = p;
  } else {
    memo2[curr] = memo1[curr];
  }

  each (next, g[curr]) {
    if (next == prev) continue;
    pair<int, lli> p = memo2[curr];
    p.first;
    p.first = memo1[0].first - memo1[next].first;
    p.second -= memo1[next].first + memo1[next].second;
    rec2(next, curr, p);
  }

  return ;
}

int main(int argc, char *argv[])
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.setf(ios_base::fixed);
  cout.precision(15);

  int n;
  while (cin >> n) {
    fill(g, g + N, vec<int>());
    for (int i = 0; i < n - 1; ++i) {
      int a, b;
      cin >> a >> b;
      --a;
      --b;
      g[a].push_back(b);
      g[b].push_back(a);
    }

    rec1(0, -1);
    rec2(0, -1, make_pair(0, 0));
    for (int i = 0; i < n; ++i) {
      cout << memo2[i].second << endl;
    }
  }

  return 0;
}
