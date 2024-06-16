// github.com/Johniel/contests
// atcoder/ahc034/main.cpp

#include <bits/stdc++.h>

#define each(i, c) for (auto& i : c)
#define unless(cond) if (!(cond))

using namespace std;

template<typename P, typename Q> ostream& operator << (ostream& os, pair<P, Q> p);
template<typename P, typename Q> istream& operator >> (istream& is, pair<P, Q>& p);
template<typename P, typename Q, typename R> ostream& operator << (ostream& os, tuple<P, Q, R> t) { os << "(" << get<0>(t) << "," << get<1>(t) << "," << get<2>(t) << ")"; return os; }
template<typename P, typename Q, typename R> istream& operator >> (istream& is, tuple<P, Q, R>& t) { is >> get<0>(t) >> get<1>(t) >> get<2>(t); return is; }
template<typename T> ostream& operator << (ostream& os, vector<T> v) { os << "("; for (auto& i: v) os << i << ","; os << ")"; return os; }
template<typename T> istream& operator >> (istream& is, vector<T>& v) { for (auto& i: v) is >> i; return is; }
template<typename T> ostream& operator << (ostream& os, set<T> s) { os << "set{"; for (auto& i: s) os << i << ","; os << "}"; return os; }
template<typename K, typename V> ostream& operator << (ostream& os, map<K, V> m) { os << "map{"; for (auto& i: m) os << i << ","; os << "}"; return os; }
template<typename E, size_t N> istream& operator >> (istream& is, array<E, N>& a) { for (auto& i: a) is >> i; return is; }
template<typename E, size_t N> ostream& operator << (ostream& os, array<E, N>& a) { os << "[" << N << "]{"; for (auto& i: a) os << i << ","; os << "}"; return os; }
template<typename T> ostream& operator << (ostream& os, stack<T> s) { os << "stack{"; while (s.size()) { os << s.top() << ","; s.pop(); } os << "}"; return os; }
template<typename T> ostream& operator << (ostream& os, queue<T> q) { os << "queue{"; while (q.size()) { os << q.front() << ","; q.pop(); } os << "}"; return os; }
template<typename T> ostream& operator << (ostream& os, deque<T> q) { os << "deque{"; for (int i = 0; i < q.size(); ++i) os << q[i] << ","; os << "}"; return os; }
template<typename T> ostream& operator << (ostream& os, priority_queue<T> q) { os << "heap{"; while (q.size()) { os << q.top() << ","; q.pop(); } os << "}"; return os; }
template<typename P, typename Q> ostream& operator << (ostream& os, pair<P, Q> p) { os << "(" << p.first << "," << p.second << ")"; return os; }
template<typename P, typename Q> istream& operator >> (istream& is, pair<P, Q>& p) { is >> p.first >> p.second; return is; }

template<typename T> inline T setmax(T& a, T b) { return a = std::max(a, b); }
template<typename T> inline T setmin(T& a, T b) { return a = std::min(a, b); }

__attribute__((constructor)) static void _____(void) { ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.setf(ios_base::fixed); cout.precision(15); return ; }

using lli = long long int;
using ull = unsigned long long;
using str = string;
template<typename T> using vec = vector<T>;

// constexpr lli mod = 1e9 + 7;
constexpr lli mod = 998244353;

const int h = 20;
const int w = 20;
static int g[h][w];
int n;

void show(pair<int, int> p = make_pair(-1, -1))
{
  for (int i = 0; i < h; ++i) {
    for (int j = 0; j < w; ++j) {
      if (make_pair(i, j) != p) clog << g[i][j] << "  " ;
      else clog << g[i][j] << "@ ";
    }
    clog << endl;
  }
  return ;
}

void rot90(void)
{
  clog << "> rot90" << endl;
  show();

  int tmp[h][w];
  for (int _ = 0; _ < 3; ++_) {
    for (int i = 0; i < h; ++i) {
      for (int j = 0; j < w; ++j) {
        tmp[i][j] = g[i][j];
      }
    }
    for (int i = 0; i < h; ++i) {
      for (int j = 0; j < w; ++j) {
        g[j][i] = tmp[i][j];
      }
    }
  }

  clog << "< rot90" << endl;
  show();

  return ;
}

pair<lli, vec<str>> solve(void)
{
  static int G[h][w];
  auto save = [&] () {
    for (int i = 0; i < h; ++i) {
      for (int j = 0; j < w; ++j) {
        G[i][j] = g[i][j];
      }
    }
    return ;
  };
  auto restore = [&] () {
    for (int i = 0; i < h; ++i) {
      for (int j = 0; j < w; ++j) {
        g[i][j] = G[i][j];
      }
    }
    return ;
  };


  save();
  vec<str> cmd;
  lli cost = 0;
  int z = 0;
  auto take = [&] (int i, int j) {
    assert(0 <= i && i < h);
    assert(0 <= j && j < w);
    assert(0 <= z);
    if (0 < g[i][j]) {
      cmd.push_back("+" + to_string(g[i][j]));
      cost += g[i][j];
      z += g[i][j];
      g[i][j] = 0;
    }
    assert(0 <= z);
    return ;
  };
  auto drop = [&] (int i, int j) {
    assert(0 <= i && i < h);
    assert(0 <= j && j < w);
    assert(0 <= z);
    if (0 <= g[i][j]) return ;
    int mn = min(z, -g[i][j]);
    if (mn) {
      cost += mn;
      cmd.push_back("-" + to_string(mn));
    }
    z -= mn;
    g[i][j] += mn;
    assert(0 <= z);
    return ;
  };

  auto finished = [&] () {
    for (int i = 0; i < h; ++i) {
      for (int j = 0; j < w; ++j) {
        if (g[i][j]) return false;
      }
    }
    return true;
  };

  int i = 0;
  int j = 0;
  auto move = [&] (str d) {
    if (d == "U") --i;
    if (d == "D") ++i;
    if (d == "R") ++j;
    if (d == "L") --j;
    cost += z;
    cmd.push_back(d);
    return ;
  };

  const int inf = 1 << 28;

  const int dj[] = {-1, +1};
  int dir = 1;
  str djs = "LR";

  while (i < n) {
    assert(0 <= i && i < h);
    assert(0 <= j && j < w);
    take(i, j);
    drop(i, j);

    if (finished()) break;

    if (i && g[i - 1][j] < 0 && abs(g[i - 1][j]) <= z) {
      cmd.push_back("U"); cost += z;
      drop(i - 1, j);
      cmd.push_back("D"); cost += z;
    }

    bool f = true;
    {
      vec<int> v;
      for (int k = 1; k <= w; ++k) {
        int nj = j + (dj[dir] * k);
        if (0 <= nj && nj < w) v.push_back(nj);
      }
      int e = 0;
      if (i + 1) {
        each (k, v) e += (0 < g[i + 1][k]) + (0 < g[i][k]);
      } else {
        each (k, v) e += (0 < g[i][k]);
      }
      if (z == 0 && i != h - 1 && e == 0) f = false;
    }

    int nj = j + dj[dir];
    if (0 <= nj && nj < w && f) {
      cmd.push_back(str("") + djs[dir]); cost += z;
      j = nj;
    } else {
      if (i + 1 == h) break;
      cmd.push_back("D"); cost += z;
      ++i;
      dir ^= 1;
    }
  }

  clog << make_pair(i, j) << endl;

  if (j == 0) dir = 1;
  else dir = 0;

  while (0 <= i) {
    assert(0 <= i && i < h);
    assert(0 <= j && j < w);
    take(i, j);
    drop(i, j);

    if (finished()) break;

    // clog << endl; show(make_pair(i, j));

    bool f = true;
    {
      vec<int> v;
      for (int k = 1; k <= w; ++k) {
        int nj = j + (dj[dir] * k);
        if (0 <= nj && nj < w) v.push_back(nj);
      }
      int e = 0;
      if (i) {
        each (k, v) e += !!g[i - 1][k] + !!g[i][k];
      } else {
        each (k, v) e += !!g[i][k];
      }
      if (e == 0) f = false;
    }

    int nj = j + dj[dir];
    if (0 <= nj && nj < w && f) {
      cmd.push_back(str("") + djs[dir]); cost += z;
      j = nj;
    } else {
      if (i == 0) break;
      unless (0 <= i - 1) break;
      cmd.push_back("U"); cost += z;
      --i;
      dir ^= 1;
    }
  }

  unless (z == 0) {
    show();
  }
  assert(z == 0);

  unless (finished()) show();
  assert(finished());
  restore();
  return make_pair(cost, cmd);
}

int main(int argc, char *argv[])
{
  while (cin >> n) {
    for (int i = 0; i < h; ++i) {
      for (int j = 0; j < w; ++j) {
        cin >> g[i][j];
      }
    }

    clog << "A" << endl;
    auto a = solve();
    rot90();
    clog << "B" << endl;
    auto b = solve();

    clog << "A" << a.first << endl;
    clog << "B" << b.first << endl;

    if (a.first < b.first) {
      each (k, a.second) cout << k << endl;
    } else {
      each (k, b.second) {
        if (k == "U") k = "L";
        else if (k == "D") k = "R";
        else if (k == "L") k = "U";
        else if (k == "R") k = "D";
      }
      each (k, b.second) cout << k << endl;
    }

  }
  return 0;
}
