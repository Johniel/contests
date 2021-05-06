// atcoder/ahc002/main.cpp
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
using str = string;
template<typename T> using vec = vector<T>;

constexpr array<int, 8> di({0, 1,  0, -1});
constexpr array<int, 8> dj({1, 0, -1, 0});
constexpr lli mod = 1e9 + 7;

const int H = 50;
const int W = 50;
int tile[H][W];
int point[H][W];

const str DIR = "RDLU";
const lli inf = 1LL << 60;

pair<lli, str> solve(int si, int sj, str fixed, int ini_d = 0)
{
  lli sum = 0;
  str path;

  map<char, int> idx;
  for (int i = 0; i < DIR.size(); ++i) {
    idx[DIR[i]] = i;
  }

  set<int> vis;
  int d = ini_d;
  function<void(int, int, int)> rec = [&] (int i, int j, int step) {
    vis.insert(tile[i][j]);
    int dir = -1;
    int best = -1;
    for (int _ = 0; _ < 4 && d < 4; d = (d + 1) % 4, ++_) {
      if (step < fixed.size()) {
        if (idx[fixed[step]] != d) continue;
      }
      int ni = i + di[d];
      int nj = j + dj[d];
      unless (0 <= ni && ni < H) continue;
      unless (0 <= nj && nj < W) continue;
      if (vis.count(tile[ni][nj])) continue;
      if (best < point[ni][nj]) {
        best = point[ni][nj];
        dir = d;
        break;
      }
    }
    if (dir == -1) return ;
    int ni = i + di[dir];
    int nj = j + dj[dir];
    path += DIR[dir];
    sum += point[ni][nj];
    vis.insert(tile[ni][nj]);
    return rec(ni, nj, step + 1);
  };
  rec(si, sj, 0);

  return make_pair(sum, path);
}

pair<lli, str> solve2(int si, int sj, str fixed)
{
  lli sum = 0;
  str path;

  map<char, int> idx;
  for (int i = 0; i < DIR.size(); ++i) {
    idx[DIR[i]] = i;
  }

  set<int> vis;
  function<void(int, int, int)> rec = [&] (int i, int j, int step) {
    // cout << fixed << ' ' << make_pair(i, j)<< ' ' << sum << ' ' << vis << endl;
    vis.insert(tile[i][j]);
    int dir = -1;
    int best = -1;
    for (int d = 0; d < 4; ++d) {
      if (step < fixed.size()) {
        if (idx[fixed[step]] != d) continue;
      }
      int ni = i + di[d];
      int nj = j + dj[d];
      unless (0 <= ni && ni < H) continue;
      unless (0 <= nj && nj < W) continue;
      if (vis.count(tile[ni][nj])) continue;
      if (best < point[ni][nj]) {
        best = point[ni][nj];
        dir = d;
      }
    }
    if (dir == -1) return ;
    int ni = i + di[dir];
    int nj = j + dj[dir];
    path += DIR[dir];
    sum += point[ni][nj];
    vis.insert(tile[ni][nj]);
    return rec(ni, nj, step + 1);
  };
  rec(si, sj, 0);

  return make_pair(sum, path);
}

pair<lli, str> solve3(int si, int sj)
{
  map<char, int> idx;
  for (int i = 0; i < DIR.size(); ++i) {
    idx[DIR[i]] = i;
  }

  static lli sum[H][W];
  fill(&sum[0][0], &sum[H - 1][W - 1] + 1, -1);

  queue<pair<int, int>> q;
  static str path[H][W];
  fill(&path[0][0], &path[H - 1][W - 1] + 1, str(""));

  set<int> vis;

  q.push(make_pair(si, sj));
  sum[si][sj] = point[si][sj];
  vis.insert(tile[si][sj]);

  for (q.push(make_pair(si, sj)); q.size(); q.pop()) {
    int i = q.front().first;
    int j = q.front().second;
    for (int d = 0; d < 4; ++d) {
      int ni = i + di[d];
      int nj = j + dj[d];
      unless (0 <= ni && ni < H) continue;
      unless (0 <= nj && nj < W) continue;
      if (vis.count(tile[ni][nj])) continue;
      if (sum[ni][nj] != -1) continue;
      vis.insert(tile[ni][nj]);
      path[ni][nj] = path[i][j] + DIR[d];
      sum[ni][nj] = sum[i][j] + point[ni][nj];
      q.push(make_pair(ni, nj));
    }
  };

  pair<lli, str> mx = make_pair(-1, str(""));
  for (int i = 0; i < H; ++i) {
    for (int j = 0; j < W; ++j) {
      // setmax(mx, make_pair(sum[i][j], path[i][j]));
      if (mx.second.size() < path[i][j].size()) {
        mx = make_pair(sum[i][j], path[i][j]);
      }
    }
  }
  return mx;
}


int rand(void)
{
  static int _seed = 1e9 + 7;
  (_seed += 3571) %= mod;
  return _seed;
}

int main(int argc, char *argv[])
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.setf(ios_base::fixed);
  cout.precision(15);

  int si, sj;
  cin >> si >> sj;

  for (int i = 0; i < H; ++i) {
    for (int j = 0; j < W; ++j) {
      cin >> tile[i][j];
    }
  }
  for (int i = 0; i < H; ++i) {
    for (int j = 0; j < W; ++j) {
      cin >> point[i][j];
    }
  }

  pair<lli, str> best = solve3(si, sj);
  {
    each (c1, DIR) each (c2, DIR) each (c3, DIR) each (c4, DIR) each (c5, DIR) {
      str s = str("") + c1 + c2 + c3 + c4 + c5;
      setmax(best, solve(si, sj, s));
    }
  }

  for (int _ = 1; _ < 2000; ++_) {
    int len = _ % best.second.size() + 1;

    str s = best.second.substr(0, len);
    auto p = solve2(si, sj, s);
    setmax(best, p);

    for (int d = 0; d < 4; ++d) {
      str t = s.substr(0, len);
      auto p = solve(si, sj, t, d);
      setmax(best, p);
    }
  }

  cout << best.second << endl;

  return 0;
}
