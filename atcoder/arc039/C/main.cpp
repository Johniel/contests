// atcoder/arc039/C/main.cpp
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

const int di[] = {1, 0, -1, 0};
const int dj[] = {0, -1, 0, 1};
constexpr lli mod = 1e9 + 7;

map<pair<int, int>, pair<int, int>> m[4];
pair<int, int> fn(pair<int, int> curr, const int dir)
{
  for (int d = 0; d < 4; ++d) {
    if (!m[d].count(curr)) {
      m[d][curr] = make_pair(curr.first + di[d], curr.second + dj[d]);
    }
  }


  for (int d = 0; d < 4; ++d) {
    int e = (d + 2) % 4;
    pair<int, int> q = m[d][curr];
    m[e][q] = m[e][curr];
  }

  return m[dir][curr];
}

int main(int argc, char *argv[])
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.setf(ios_base::fixed);
  cout.precision(15);

  int k;
  str s;
  while (cin >> k >> s) {
    fill(m, m + 4, map<pair<int, int>, pair<int, int>>());
    pair<int, int> curr = {0, 0};
    map<char, int> dir;
    dir['R'] = 0;
    dir['D'] = 1;
    dir['L'] = 2;
    dir['U'] = 3;
    each (c, s) curr = fn(curr, dir[c]);
    cout << curr.first << ' ' << curr.second << endl;
  }

  return 0;
}
