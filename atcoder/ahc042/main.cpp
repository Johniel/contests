// github.com/Johniel/contests
// atcoder/ahc042/main.cpp

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

template<typename T>
struct PrefixSum2D {
  vector<vector<T>> sum;
  PrefixSum2D() {}
  PrefixSum2D(vector<vector<T>> v) {
    const int H = v.size() + 1;
    const int W = v[0].size() + 1;
    sum.resize(H);
    fill(sum.begin(), sum.end(), vector<T>(W, 0));
    for (int i = 0; i < v.size(); ++i) {
      for (int j = 0; j < v[i].size(); ++j) {
        sum[i + 1][j + 1] = v[i][j];
      }
    }
    for (int i = 1; i < H; ++i) {
      for (int j = 0; j < W; ++j) {
        sum[i][j] += sum[i - 1][j];
      }
    }
    for (int i = 0; i < H; ++i) {
      for (int j = 1; j < W; ++j) {
        sum[i][j] += sum[i][j - 1];
      }
    }
  }
  T operator () (int ai, int aj, int bi, int bj) const { return this->query(ai, aj, bi, bj); }
  T query(int ai, int aj, int bi, int bj) const {
    // assert(0 <= ai && ai < sum.size());
    // assert(0 <= bi && bi < sum.size());
    // assert(0 <= aj && aj < sum[0].size());
    // assert(0 <= bj && bj < sum[0].size());
    // assert(ai <= bi && aj <= bj);
    return sum[bi][bj] + sum[ai][aj] - sum[ai][bj] - sum[bi][aj];
  }
  pair<size_t, size_t> size(void) const { return make_pair(sum.size() - 1, sum[0].size() - 1); }
};

const int N = 20;
const int M = 2 * N;

bool bounded(char g[N][N])
{
  vec<pair<int, int>> u;
  vec<vec<int>> v(N, vec<int>(N, 0));
  for (int i = 0; i < N; ++i) {
    for (int j = 0; j < N; ++j) {
      if (g[i][j] == 'o') ++v[i][j];
      if (g[i][j] == 'x') u.push_back(make_pair(i, j));
    }
  }
  if (u.empty()) return false;
  PrefixSum2D<int> sum(v);
  each (k, u) {
    auto [i, j] = k;
    if (sum(i, j, i + 1, N) == 0) continue;
    if (sum(i, j, N, j + 1) == 0) continue;
    if (sum(0, j, i + 1, j + 1) == 0) continue;
    if (sum(i, 0, i + 1, j + 1) == 0) continue;
    return true;
  }
  return false;
}

vec<pair<char, int>> curr;
int soto;

void moveR(char g[N][N], int i) {
  // assert(g[i][N - 1] != 'o');
  soto += (g[i][N - 1] == 'x');
  for (int j = N - 1; 0 <= j - 1; --j) {
    g[i][j] = g[i][j - 1];
  }
  g[i][0] = '.';
  curr.push_back(make_pair('R', i));
}
void moveR_n(char g[N][N], int i, int n) { while (n--) moveR(g, i); }

void moveL(char g[N][N], int i) {
  // assert(g[i][0] != 'o');
  soto += (g[i][0] == 'x');
  for (int j = 0; j + 1 < N; ++j) {
    g[i][j] = g[i][j + 1];
  }
  g[i][N - 1] = '.';
  curr.push_back(make_pair('L', i));
}
void moveL_n(char g[N][N], int i, int n) { while (n--) moveL(g, i); }

void moveU(char g[N][N], int j) {
  // assert(g[0][j] != 'o');
  soto += (g[0][j] == 'x');
  for (int i = 0; i + 1 < N; ++i) {
    g[i][j] = g[i + 1][j];
  }
  g[N - 1][j] = '.';
  curr.push_back(make_pair('U', j));
}
void moveU_n(char g[N][N], int j, int n) { while (n--) moveU(g, j); }

void moveD(char g[N][N], int j) {
  // assert(g[N - 1][j] != 'o');
  soto += (g[N - 1][j] == 'x');
  for (int i = N - 1; 0 <= i - 1; --i) {
    g[i][j] = g[i - 1][j];
  }
  g[0][j] = '.';
  curr.push_back(make_pair('D', j));
}
void moveD_n(char g[N][N], int j, int n) { while (n--) moveD(g, j); }

int main(int argc, char *argv[])
{
  { int n; cin >> n; }

  static char g[N][N];
  static char g0[N][N];
  for (int i = 0; i < N; ++i) {
    for (int j = 0; j < N; ++j) {
      cin >> g[i][j];
      g0[i][j] = g[i][j];
    }
  }

  vec<tuple<char, int, bool>> v;
  const int dir_h = 'h';
  const int dir_w = 'w';
  assert(dir_h != dir_w);
  for (int k = 0; k < N; ++k) {
    v.push_back(make_tuple(dir_h, k, false));
    v.push_back(make_tuple(dir_h, k, true));
    v.push_back(make_tuple(dir_w, k, false));
    v.push_back(make_tuple(dir_w, k, true));
  }

  vec<pair<char, int>> best(4 * N * N + 1);

  random_device seed_gen;
  mt19937 engine(seed_gen());
  for (int loop = 26000; --loop; ) {
    for (int i = 0; i < N; ++i) {
      for (int j = 0; j < N; ++j) {
        g[i][j] = g0[i][j];
      }
    }

    curr.clear();
    soto = 0;

    bool tail = true;
    for (int _k = 0; ; ++_k) {
      {
        const bool fin = (soto == M);
        if (fin) {
          if (best.size() > curr.size()) best = curr;
          break;
        }
      }
      const int k = _k % v.size();
      if (best.size() < curr.size() + (M - soto)) break;

      tail = false;
      auto [dir, idx, rev] = v[k];

      if (dir == dir_h) {
        const int j = idx;
        unless (rev) {
          int last_d = -1;
          for (int i = 0; i < N; ++i) {
            if (g[i][j] == 'x') last_d = i;
            if (g[i][j] == 'o') break;
          }
          if (last_d != -1) {
            moveU_n(g, j, last_d + 1);
            while (bounded(g)) moveD(g, j);
          }
        } else {
          int last_d = -1;
          for (int i = N - 1; 0 <= i; --i) {
            if (g[i][j] == 'x') last_d = i;
            if (g[i][j] == 'o') break;
          }
          if (last_d != -1) {
            moveD_n(g, j, N - last_d);
            while (bounded(g)) moveU(g, j);
          }
        }
      }

      if (dir == dir_w) {
        const int i = idx;
        unless (rev) {
          int last_d = -1;
          for (int j = 0; j < N; ++j) {
            if (g[i][j] == 'x') last_d = j;
            if (g[i][j] == 'o') break;
          }
          if (last_d != -1) {
            moveL_n(g, i, last_d + 1);
            while (bounded(g)) moveR(g, i);
          }
        } else {
          int last_d = -1;
          for (int j = N - 1; 0 <= j; --j) {
            if (g[i][j] == 'x') last_d = j;
            if (g[i][j] == 'o') break;
          }
          if (last_d != -1) {
            moveR_n(g, i, N - last_d);
            while (bounded(g)) moveL(g, i);
          }
        }
      }
    }
    shuffle(v.begin(), v.end(), engine);
  }

  each (k, best) cout << k.first << ' ' << k.second << endl;

  return 0;
}
