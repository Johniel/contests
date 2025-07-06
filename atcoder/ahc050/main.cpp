// github.com/Johniel/contests
// atcoder/ahc050/main.cpp

#include <bits/stdc++.h>

#define each(i, c) for (auto& i : c)
#define unless(cond) if (!(cond))
#define __builtin_popcount(x) __builtin_popcountll(x)

using namespace std;

template<typename P, typename Q> ostream& operator << (ostream& os, pair<P, Q> p) { os << "(" << p.first << "," << p.second << ")"; return os; }
template<typename P, typename Q> istream& operator >> (istream& is, pair<P, Q>& p) { is >> p.first >> p.second; return is; }
template<std::ranges::input_range R> requires (!std::same_as<R, std::string>) std::ostream& operator<<(std::ostream& os, const R& r) { os << '{'; for (const auto& e : r) os << e << ','; return os << '}'; }
template<std::ranges::input_range R> requires (!std::same_as<R, std::string>) && std::ranges::sized_range<R> && requires(R& r) { r.begin(); r.end(); } std::istream& operator>>(std::istream& is, R& r) { for (auto& x : r) is >> x; return is; }

template<typename T> inline T setmax(T& a, T b) { return a = std::max(a, b); }
template<typename T> inline T setmin(T& a, T b) { return a = std::min(a, b); }

__attribute__((constructor)) static void _____(void) { ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.setf(ios_base::fixed); cout.precision(6); cerr.setf(ios_base::fixed); cerr.precision(5); return ; }

using lli = long long int;
using ull = unsigned long long;
using str = string;
template<typename T> using vec = vector<T>;

constexpr lli mod = 998244353; // 1e9 + 7;

uint32_t xorshift(void)
{
  // https://shindannin.hatenadiary.com/entry/2021/03/06/115415
  static uint32_t x = 123456789;
  static uint32_t y = 362436069;
  static uint32_t z = 521288629;
  static uint32_t w = 88675123;
  uint32_t t;

  t = x ^ (x << 11);
  x = y; y = z; z = w;
  return w = (w ^ (w >> 19)) ^ (t ^ (t >> 8));
}

const int N = 40;
constexpr double TIME_LIMIT   = 1.80;    // 実行時間（提出 TL − α）
constexpr double SA_T0    = 3.0;     // 焼き鈍し初期温度
constexpr double SA_T1    = 1e-3;    // 焼き鈍し最終温度

const int DIR_U = 0;
const int DIR_D = 1;
const int DIR_R = 2;
const int DIR_L = 3;

struct State {
  vec<set<int>> row; // >
  vec<set<int>> col; // v

  State() {
    row.resize(N);
    col.resize(N);
    for (int i = 0; i < N; ++i) {
      row[i].insert(-1);
      row[i].insert(N);
      col[i].insert(-1);
      col[i].insert(N);
    }
  }

  void add_rock(int i, int j) {
    row[i].insert(j);
    col[j].insert(i);
    return ;
  }

  void add_rock(pair<int, int> p) {
    return add_rock(p.first, p.second);
  }

  pair<int, int> move(pair<int, int> p, int dir) {
    if (dir == DIR_U) {
      auto itr = col[p.second].lower_bound(p.first);
      --itr;
      int nr = (*itr) + 1;
      p.first = nr;
      return p;
    }

    if (dir == DIR_D) {
      auto itr = col[p.second].lower_bound(p.first);
      int nr = (*itr) - 1;
      p.first = nr;
      return p;
    }

    if (dir == DIR_L) {
      auto itr = row[p.first].lower_bound(p.second);
      --itr;
      int nc = (*itr) + 1;
      p.second = nc;
      return p;
    }

    if (dir == DIR_R) {
      auto itr = row[p.first].lower_bound(p.second);
      int nc = (*itr) - 1;
      p.second = nc;
      return p;
    }

    assert(false);
  }
};
int M;
char g[N][N];
char tmp_g[N][N];
pair<double, vec<pair<int, int>>> eval(vec<pair<int,int>> pos, State state)
{
  double E = 0;
  for (int i = 0; i < N; ++i) for (int j = 0; j < N; ++j) g[i][j] = tmp_g[i][j];

  static double curr[N][N];
  static double next[N][N];
  for (int i = 0; i < N; ++i) {
    for (int j = 0; j < N; ++j) {
      curr[i][j] = (g[i][j] == '.') / (double)(N * N - M);
      next[i][j] = 0;
    }
  }

  vec<pair<int, int>> u;
  int rem = N * N - M;
  while (rem) {
    each (P, pos) {
      auto [i, j] = P;
      if (g[i][j] == '#') continue;
      for (int dir = 0; dir < 4; ++dir) {
        auto p = state.move(P, dir);
        next[p.first][p.second] += curr[i][j] / 4.0;
      }
    }

    pair<int, int> p;
    double mn = 1e128;
    int idx = 0;
    int cnt = 0;
    each (P, pos) {
      auto [i, j] = P;
      if (g[i][j] == '.' && mn > next[i][j]) {
        mn = next[i][j];
        p = P;
        idx = cnt;
      }
      ++cnt;
    }
    pos.erase(pos.begin() + idx);
    u.push_back(p);
    g[p.first][p.second] = '#';
    state.add_rock(p);
    E += next[p.first][p.second];
    for (int i = 0; i < N; ++i) {
      for (int j = 0; j < N; ++j) {
        if (g[i][j] == '.') {
          curr[i][j] = next[i][j];
          next[i][j] = 0;
        }
      }
    }
    --rem;
  }

  return make_pair(-E, u);
}

double cooling(double progress) {
  constexpr double START_TEMP   = 1e3;          // 初期温度
  constexpr double END_TEMP     = 1e-3;         // 最終温度
  // progress ∈ [0,1]、指数スケジュール
  return START_TEMP * pow(END_TEMP / START_TEMP, progress);
}

inline double rand01(void)
{
  return (xorshift() >> 11) * (1.0 / (1ULL << 53));
}


int main(int argc, char *argv[])
{
  { int _; cin >> _ >> M; }
  vec<pair<int, int>> rocks;

  for (int i = 0; i < N; ++i) {
    for (int j = 0; j < N; ++j) {
      cin >> g[i][j];
      tmp_g[i][j] = g[i][j];
      if (g[i][j] == '#') rocks.push_back(make_pair(i, j));
    }
  }

  State initial_state;
  each (i, rocks) initial_state.add_rock(i);

  vec<pair<int, int>> v;
  {
    static double curr[N][N];
    static double next[N][N];
    for (int i = 0; i < N; ++i) {
      for (int j = 0; j < N; ++j) {
        if (g[i][j] == '.') {
          curr[i][j] =  1.0 / (double)(N * N - M);
          v.push_back(make_pair(i, j));
        }
      }
    }

    vec<pair<int, int>> u;
    int rem = N * N - M;
    fill(&next[0][0], &next[N - 1][N - 1] + 1, 0);
    for (int i = 0; i < N; ++i) {
      for (int j = 0; j < N; ++j) {
        if (g[i][j] == '#') continue;
        for (int dir = 0; dir < 4; ++dir) {
          auto p = initial_state.move(make_pair(i, j), dir);
          next[i][j] += curr[i][j] / 4.0;
        }
      }
    }
    sort(v.begin(), v.end(), [&] (auto a, auto b) {
      return next[a.first][a.second] < next[b.first][b.second];
    });
  }

  auto [best, ops] = eval(v, initial_state);

  const auto time_start = chrono::steady_clock::now();

  for (int loop = 0; ; ++loop) {

    double t = chrono::duration<double>(chrono::steady_clock::now() - time_start).count();
    if (t >= TIME_LIMIT) break;
    double progress = t / TIME_LIMIT;
    double temp = cooling(progress);

    int i = xorshift() % v.size();
    int j = i;
    while (i == j) j = xorshift() % v.size();
    swap(v[i], v[j]);

    auto [curr, o] = eval(v, initial_state);

    lli diff = curr - best;
    bool accept = diff >= 0;
    unless (accept) {
      double prob = exp(diff / temp);
      accept = (rand01() < prob);
    }

    if (accept) {
      if (diff > 0) {
        best = curr;
        ops = o;
      }
    } else {
      swap(v[i], v[j]);
    }
    cerr << loop << ' ' << best << endl;
  }
  each (k, ops) cout << k.first << ' ' << k.second << endl;

  return 0;
}
