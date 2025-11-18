// github.com/Johniel/contests
// atcoder/ahc056/main.cpp

#include <bits/stdc++.h>

#define each(i, c) for (auto& i : c)
#define unless(cond) if (!(cond))
#define __builtin_popcount(x) __builtin_popcountll(x)

using namespace std;

template<typename P, typename Q> ostream& operator << (ostream& os, pair<P, Q> p);
template<typename P, typename Q> istream& operator >> (istream& is, pair<P, Q>& p);
template<typename... Ts> ostream& operator << (ostream& os, const tuple<Ts...>& t) { os << "("; if constexpr (sizeof...(Ts) > 0) { apply([&](const Ts&... args) { ((os << args << ','), ...); }, t); } os << ")"; return os; }
template<typename... Ts> istream& operator >> (istream& is, tuple<Ts...>& t) { apply([&](Ts&... args) { ((is >> args), ...); }, t); return is; }
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

inline double rand01(void)
{
  return (xorshift() >> 11) * (1.0 / (1ULL << 53));
}

const int N = 20;
const int K = N * N;
int n, k, t;
vec<pair<int, int>> destinations;

int wall[N][N][N][N];

constexpr array<int, 8> di({0, 1, -1, 0, 1, -1, 1, -1});
constexpr array<int, 8> dj({1, 0, 0, -1, 1, -1, -1, 1});
const str D = "RDUL";
map<char, int> dir_chars({{'R', 0}, {'D', 1}, {'U', 2}, {'L', 3}});

vec<pair<int, int>> sssp(pair<int, int> src, pair<int, int> dst)
{
  static map<pair<pair<int, int>, pair<int, int>>, vec<pair<int, int>>> memo;
  const auto key = make_pair(src, dst);
  if (memo.contains(key)) return memo[key];

  const pair<int, int> nilpath = make_pair(-1, -1);
  static pair<int, int> path[N][N];
  for (int i = 0; i < n; ++i) for (int j = 0; j < n; ++j) path[i][j] = nilpath;
  path[src.first][src.second] = src;
  queue<tuple<int, int, int>> q;
  for (q.push(make_tuple(src.first, src.second, 0)); q.size() && path[dst.first][dst.second] == nilpath; q.pop()) {
    const auto [i, j, pd] = q.front();
    vec<int> dirs({pd, 0, 1, 2, 3});
    each (d, dirs) {
      const int ni = i + di[d];
      const int nj = j + dj[d];
      unless (0 <= ni && ni < n) continue;
      unless (0 <= nj && nj < n) continue;
      if (wall[i][j][ni][nj]) continue;
      if (path[ni][nj] != nilpath) continue;
      path[ni][nj] = make_pair(i, j);
      q.push(make_tuple(ni, nj, d));
    }
  }
  assert(path[dst.first][dst.second] != nilpath);
  vec<pair<int, int>> v;
  v.push_back(dst);
  while (true) {
    auto [i, j] = v.back();
    if (path[i][j] == v.back()) break;
    v.push_back(path[i][j]);
  }
  reverse(v.begin(), v.end());
  return memo[key] = v;
}

int get_dir(pair<int, int> src, pair<int, int> dst)
{
  for (int d = 0; d < 4; ++d) {
    const auto [i, j] = src;
    const int ni = i + di[d];
    const int nj = j + dj[d];
    if (dst == make_pair(ni, nj)) return d;
  }
  assert(false);
  return -1;
}

struct Solution {
  int color_count;
  int state_count;
  int color[N][N];
  vec<tuple<int, int, int, int, char>> fn; // ci, si, next_color, next_state, dir

  int score(void) const { return color_count + state_count; }

  bool is_valid(void) {
    assert(color_count <= n * n * n * n);
    assert(state_count <= n * n * n * n);
    unless (fn.size() < t) return false;
    assert(0 < color_count);
    assert(0 < state_count);
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j) {
        assert(0 <= color[i][j] && color[i][j] < color_count);
      }
    }
    static int current_color[N][N];
    for (int i = 0; i < N; ++i) {
      for (int j = 0; j < N; ++j) {
        current_color[i][j] = color[i][j];
      }
    }
    map<pair<int, int>, int> fnC;
    map<pair<int, int>, int> fnS;
    map<pair<int, int>, int> fnDir;
    for (int i = 0; i < fn.size(); ++i) {
      auto [c, s, nc, ns, d] = fn[i];
      assert(0 <= s && s < state_count);
      assert(0 <= ns && ns < state_count);
      assert(0 <= c && c < color_count);
      assert(0 <= nc && nc < color_count);
      assert(dir_chars.contains(d));
      pair<int, int> key = make_pair(c, s);
      assert(!fnC.contains(key));
      assert(!fnS.contains(key));
      assert(!fnDir.contains(key));
      fnC[key] = nc;
      fnS[key] = ns;
      fnDir[key] = dir_chars[d];
    }
    int idx = 1;
    int turn = 0;
    pair<int, int> pos = destinations[0];
    int current_state = 0;
    set<pair<int, int>> vis;
    for (; turn < t && idx < destinations.size(); ++turn) {
      const auto [i, j] = pos;
      const pair<int, int> key = make_pair(current_color[i][j], current_state);
      vis.insert(key);
      // cerr << pos << idx << endl;
      unless (fnC.contains(key)) {
        cerr << "failed#1: " << key << "," << pos << "," << destinations[idx] << endl;
      }
      assert(fnC.contains(key));
      assert(fnS.contains(key));
      assert(fnDir.contains(key));
      current_color[i][j] = fnC[key];
      current_state = fnS[key];
      const int dir = fnDir[key];
      const int ni = i + di[dir];
      const int nj = j + dj[dir];
      if ((0 <= ni && ni < n) && (0 <= nj && nj < n) && !wall[i][j][ni][nj]) {
        pos = make_pair(ni, nj);
      }
      if (destinations[idx] == pos) ++idx;
    }
    // cerr << turn << "<=" << t << "&&" << idx << "==" << destinations.size() << endl;
    return turn <= t && idx == destinations.size() && fn.size() <= t;
  }
};

vec<pair<int, int>> build_simple_path(const vec<int>& ord)
{
  vec<pair<int, int>> path;
  for (int k = 0; k + 1 < ord.size(); ++k) {
    int i = ord[k];
    int j = ord[k + 1];
    auto v = sssp(destinations[i], destinations[j]);
    if (path.size()) path.pop_back();
    path.insert(path.end(), v.begin(), v.end());
  }
  return path;
}

vec<pair<int, int>> build_cyclic_path(const vec<int>& ord)
{
  vec<pair<int, int>> path = build_simple_path(ord);
  auto v = sssp(destinations[ord.back()], destinations[ord.front()]);
  path.pop_back();
  path.insert(path.end(), v.begin(), v.end());
  return path;
}

Solution solve0(void)
{
  vec<int> ord(destinations.size());
  iota(ord.begin(), ord.end(), 0);
  const vec<pair<int, int>>& path = build_simple_path(ord);

  const int total_moves = path.size() - 1;
  const int required_colors = floor(sqrt(total_moves));
  const int cycle = (total_moves + required_colors - 1) / required_colors;

  static int initial_color[N][N];
  static int color[N][N];

  vec<tuple<int, int, int, int, char>> fn;

  queue<int> steps[N][N];
  for (int k = 0; k < path.size() - 1; ++k) {
    steps[path[k].first][path[k].second].push(k);
  }

  fill(&initial_color[0][0], &initial_color[N - 1][N - 1] + 1, -1);
  fill(&color[0][0], &color[N - 1][N - 1] + 1, -1);
  for (int k = 0; k + 1 < path.size(); ++k) {
    auto [i, j] = path[k];
    if (color[i][j] == -1) {
      initial_color[i][j] = color[i][j] = (k / cycle);
    }
  }
  replace(&initial_color[0][0], &initial_color[N - 1][N - 1] + 1, -1, 0);
  replace(&color[0][0], &color[N - 1][N - 1] + 1, -1, 0);

  str path_str;
  int state = 0;
  for (int k = 0; k + 1 < path.size(); ++k) {
    const auto [i, j] = path[k];
    assert(steps[i][j].size());
    steps[i][j].pop();

    const int next_color = steps[i][j].size() ? (steps[i][j].front() / cycle) : initial_color[i][j];
    const int next_state = (state + 1) % cycle;
    const int dir = get_dir(path[k], path[k + 1]);
    path_str += D[dir];
    fn.push_back(make_tuple(color[i][j], state, next_color, next_state, D[dir]));
    state = next_state;
    color[i][j] = next_color;
  }

  Solution s;
  s.color_count = required_colors;
  s.state_count = cycle;
  s.fn = fn;
  for (int i = 0; i < N; ++i) {
    for (int j = 0; j < N; ++j) {
      s.color[i][j] = initial_color[i][j];
    }
  }
  return s;
}

void show(Solution s)
{
  cout << s.color_count << ' ' << s.state_count << ' ' << s.fn.size() << endl;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      cout << s.color[i][j] << ' ';
    }
    cout << endl;
  }
  each (k, s.fn) {
    auto [c, s, nc, ns, d] = k;
    cout << c << ' ' << s << ' ' << nc << ' ' << ns << ' ' << d << endl;
  }
  return ;
}

constexpr double TIME_LIMIT   = 1.80;    // 実行時間（提出 TL − α）
constexpr double SA_T0    = 3.0;     // 焼き鈍し初期温度
constexpr double SA_T1    = 1e-3;    // 焼き鈍し最終温度

double cooling(double progress)
{
  // progress ∈ [0,1]、指数スケジュール
  return SA_T0 * pow(SA_T1 / SA_T0, progress);
}

Solution solve1(const vec<int>& ord)
{
  const vec<pair<int, int>>& path = build_cyclic_path(ord);

  const int total_moves = path.size() - 1;
  const int required_colors = floor(sqrt(total_moves));
  const int cycle = (total_moves + required_colors - 1) / required_colors;

  static int initial_color[N][N];
  static int color[N][N];

  vec<tuple<int, int, int, int, char>> fn;

  queue<int> steps[N][N];
  for (int k = 0; k < path.size() - 1; ++k) {
    steps[path[k].first][path[k].second].push(k);
  }

  fill(&initial_color[0][0], &initial_color[N - 1][N - 1] + 1, -1);
  fill(&color[0][0], &color[N - 1][N - 1] + 1, -1);
  for (int k = 0; k + 1 < path.size(); ++k) {
    auto [i, j] = path[k];
    if (color[i][j] == -1) {
      initial_color[i][j] = color[i][j] = (k / cycle);
    }
  }
  replace(&initial_color[0][0], &initial_color[N - 1][N - 1] + 1, -1, 0);
  replace(&color[0][0], &color[N - 1][N - 1] + 1, -1, 0);

  str path_str;
  int state = 0;
  for (int k = 0; k + 1 < path.size(); ++k) {
    const auto [i, j] = path[k];
    assert(steps[i][j].size());
    steps[i][j].pop();

    const int next_color = steps[i][j].size() ? (steps[i][j].front() / cycle) : initial_color[i][j];
    const int next_state = (state + 1) % cycle;
    const int dir = get_dir(path[k], path[k + 1]);
    path_str += D[dir];
    fn.push_back(make_tuple(color[i][j], state, next_color, next_state, D[dir]));
    state = next_state;
    color[i][j] = next_color;
  }
  {
    auto [c, s, nc, ns, d] = fn.back();
    fn.pop_back();
    fn.push_back(make_tuple(c, s, nc, 0, d));
  }

  Solution s;
  s.color_count = required_colors;
  s.state_count = cycle;
  s.fn = fn;
  for (int i = 0; i < N; ++i) {
    for (int j = 0; j < N; ++j) {
      s.color[i][j] = initial_color[i][j];
    }
  }
  return s;
}

int main(int argc, char *argv[])
{
  const auto time_start = chrono::steady_clock::now();
  cin >> n >> k >> t;
  fill(&wall[0][0][0][0], &wall[N -  1][N - 1][N - 1][N - 1] + 1, 0);

  for (int i = 0; i < n; ++i) {
    for (int j = 0; j + 1 < n; ++j) {
      char c;
      cin >> c;
      wall[i][j][i][j + 1] = wall[i][j + 1][i][j] = (c == '1');
    }
  }
  for (int i = 0; i + 1 < n; ++i) {
    for (int j = 0; j < n; ++j) {
      char c;
      cin >> c;
      wall[i][j][i + 1][j] = wall[i + 1][j][i][j] = (c == '1');
    }
  }

  destinations.resize(k);
  assert(cin >> destinations);

  Solution best = solve0();
  assert(best.is_valid());

  vec<int> origin(destinations.size());
  iota(origin.begin(), origin.end(), 0);
  for (int i = n - 2; 1 < i; --i) {
    vec<int> ord = origin;
    int x = ord.back();
    ord.pop_back();
    ord.insert(ord.begin() + i, x);
    Solution curr = solve1(ord);
    if (curr.is_valid() && curr.score() <= best.score()) {
      if (curr.score() < best.score()) cerr << "updated: " << best.score() << "->" << curr.score() << endl;
      best = curr;
      origin = ord;
    }
  }

  {
    static int g[K][K];
    for (int i = 0; i < destinations.size(); ++i) {
      for (int j = i + 1; j < destinations.size(); ++j) {
        g[i][j] = g[j][i] = sssp(destinations[i], destinations[j]).size();
      }
    }
    auto fn = [&] (const vec<int>& v) {
      set<int> vis;
      for (int i = 0; i < v.size(); ++i) {
        vis.insert(i);
      }
      int sum = 0;
      // for (int k = 0; vis.size(); ++k) {
      for (int k = 0; k < v.size(); ++k) {
        int i = k % v.size();
        if (*vis.begin() == v[i]) vis.erase(vis.begin());
        int j = (i + 1) % v.size();
        sum += g[v[i]][v[j]];
      }
      return sum;
    };

    vec<int> opt(destinations.size());
    iota(opt.begin(), opt.end(), 0);
    int opt_score = fn(opt);
    vec<int> curr = opt;
    int curr_score = opt_score;

    for (int loop = 0; ; ++loop) {
      double t = chrono::duration<double>(chrono::steady_clock::now() - time_start).count();
      if (TIME_LIMIT < t) break;
      double progress = t / TIME_LIMIT;
      double temp = cooling(progress);
      vec<int> next = curr;
      {
        int idx = 1 + xorshift() % (next.size() - 2);
        swap(next[idx], next[idx + 1]);
      }
      int next_score = fn(next);
      int diff = abs(next_score - curr_score);
      bool accept = next_score < curr_score;
      unless (accept) {
        double prob = exp(diff / temp);
        accept = (rand01() < prob);
      }
      // cerr << make_pair(curr_score, next_score) << endl;
      // cerr << curr << curr_score << endl;
      // cerr << next << next_score << endl;
      if (accept) {
        curr = next;
        curr_score = next_score;
        if (opt_score > next_score) {
          opt = next;
          opt_score = next_score;

          Solution s = solve1(opt);
          if (s.is_valid() && s.score() < best.score()) {
            cerr << "updated(1): " << best.score() << "->" << s.score() << endl;
            best = s;
          }
        }
      }
    }
  }

  assert(best.is_valid());
  cerr << best.color_count + best.state_count << endl;
  show(best);

  return 0;
}
