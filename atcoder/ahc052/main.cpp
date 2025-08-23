// github.com/Johniel/contests
// atcoder/ahc052/main.cpp

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

// https://shindannin.hatenadiary.com/entry/2021/03/06/115415
uint32_t xorshift(void)
{
  static uint32_t x = 123456789;
  static uint32_t y = 362436069;
  static uint32_t z = 521288629;
  static uint32_t w = 88675123;
  uint32_t t;

  t = x ^ (x << 11);
  x = y; y = z; z = w;
  return w = (w ^ (w >> 19)) ^ (t ^ (t >> 8));
}

constexpr int N = 30;
constexpr int H = N;
constexpr int W = N;
constexpr int M = 10; // robot
constexpr int K = 10; // button

vec<pair<int, int>> initial_positions(M);
vec<vec<int>> wall_R(N, vec<int>(N - 1));
vec<vec<int>> wall_D(N - 1, vec<int>(N));
constexpr array<int, 4> di({0, 1, -1, 0});
constexpr array<int, 4> dj({1, 0, 0, -1});
constexpr str dir_str = "RDUL";
constexpr int dir_R = 0;
constexpr int dir_D = 1;
constexpr int dir_U = 2;
constexpr int dir_L = 3;
constexpr int DIR = 4;
constexpr int dir_S = 4;
vec<vec<array<bool, 4>>> wall;
int label[N][N];
vec<pair<int, int>> positions;

int rev_dir(int dir) {
  if (dir == dir_R) return dir_L;
  if (dir == dir_L) return dir_R;
  if (dir == dir_D) return dir_U;
  if (dir == dir_U) return dir_D;
  return dir_S;
}

int get_dir(pair<int, int> src, pair<int, int> dst)
{
  const int md = abs(src.first - dst.first) + abs(src.second - dst.second);
  if (md == 0) return dir_S;
  assert(md == 1);
  if (src.first != dst.first) {
    if (src.first < dst.first) return dir_D;
    return dir_U;
  }
  if (src.second != dst.second) {
    if (src.second < dst.second) return dir_R;
    return dir_L;
  }
  assert(false);
}

int get_dir(int si, int sj, int di, int dj)
{
  return get_dir(make_pair(si, sj), make_pair(di, dj));
}

pair<int, int> move(pair<int, int> p, int dir) {
  auto [i, j] = p;
  const int ni = i + di[dir];
  const int nj = j + dj[dir];
  unless (0 <= ni && ni < H) return p;
  unless (0 <= nj && nj < W) return p;
  if (wall[i][j][dir]) return p;
  return make_pair(ni, nj);
}

const int inf = (1 << 29);

struct State {
  vec<vec<int>> buttons;
  array<vec<int>, 4> dir2button;
  int score;
  vec<int> ord;
  int target;

  State(vec<int> o, int t) : State(t) {
    ord = o;
  }

  State(int t) : target(t) {
    score = inf;
    vec<int> ds({dir_R, dir_D, dir_U, dir_L});
    each (d, ds) {
      for (int _ = 0; _ < 2; ++_) {
        vec<int> b(M);
        b[t] = d;
        for (int i = 0; i < b.size(); ++i) {
          if (i == t) continue;
          if (i % 2) b[i] = d;
          else b[i] = rev_dir(d);
        }
        buttons.push_back(b);
      }
    }
    buttons.push_back(buttons[0]);
    buttons.push_back(buttons[1]);
    for (int i = 0; i < buttons.size(); ++i) {
      dir2button[buttons[i][t]].push_back(i);
    }
    assert(buttons.size() == K);

    for (int i = 0; i < N; ++i) {
      for (int j = 0; j < N; ++j) {
        if (make_pair(i, j) != initial_positions[t]) ord.push_back(label[i][j]);
      }
    }
  }

  vec<int> pushed_count;
  int button_index_from_dir(int dir) {
    int bidx = dir2button.at(dir).at(pushed_count.at(dir));
    (pushed_count[dir] += 1) %= dir2button[dir].size();
    return bidx;
  }

  vec<int> sssp(const int src, const int dst) {
    static bool vis[N][N];
    static pair<int,int> path[N][N];
    fill(&vis[0][0], &vis[N - 1][N - 1] + 1, false);
    queue<pair<int, int>> q;

    auto [si, sj] = positions[src];
    path[si][sj] = positions[src];
    vis[si][sj] = true;

    for (q.push(positions[src]); q.size(); q.pop()) {
      auto [i, j] = q.front();
      for (int d = 0; d < 4; ++d) {
        const int ni = i + di[d];
        const int nj = j + dj[d];
        unless (0 <= ni && ni < H) continue;
        unless (0 <= nj && nj < W) continue;
        if (wall[i][j][d]) continue;
        if (vis[ni][nj]) continue;
        vis[ni][nj] = true;
        path[ni][nj] = make_pair(i, j);
        q.push(make_pair(ni, nj));
      }
      auto [di, dj] = positions[dst];
      if (vis[di][dj]) break;
    }
    vec<int> v;
    auto [i, j] = positions[dst];
    assert(vis[i][j]);
    while (make_pair(i, j) != positions[src]) {
      auto [pi, pj] = path[i][j];
      v.push_back(get_dir(pi, pj, i, j));
      i = pi;
      j = pj;
    }
    reverse(v.begin(), v.end());
    return v;
  }

  vec<int> simulate(void) {
    pushed_count.clear();
    pushed_count.resize(4, 0);

    static int visited_at[N][N];
    fill(&visited_at[0][0], &visited_at[N - 1][N - 1] + 1, -1);

    int t = 0;
    int rem = N * N;
    vec<pair<int, int>> pos = initial_positions;

    each (p, pos) {
      visited_at[p.first][p.second] = t;
      --rem;
    }

    vec<int> button_indexes;
    auto push_button = [&] (const int button_index) {
      for (int k = 0; k < pos.size(); ++k) {
        pos[k] = move(pos[k], buttons[button_index][k]);
        auto [i, j] = pos[k];
        if (visited_at[i][j] == -1) {
          visited_at[i][j] = t;
          --rem;
        }
      }
      button_indexes.push_back(button_index);
      return ;
    };

    const auto [root_i, root_j] = initial_positions[target];
    const int root_label = label[root_i][root_j];

    int curr = root_label;
    each (o, ord) {
      auto [dst_i, dst_j] = positions[o];
      while (visited_at[dst_i][dst_j] == -1) {
        vec<int> dirs = sssp(curr, o);
        int b_index = button_index_from_dir(dirs[0]);
        push_button(b_index);
        curr = label[pos[target].first][pos[target].second];
      }
      if (rem <= 0) break;
    }

    score = button_indexes.size();
    return button_indexes;
  }
};

vec<vec<int>> spanning_tree;
vec<int> tree_parent;

vec<int> build_spanning_tree(const int robot_index, vec<int> ds)
{
  static bool vis[N][N];
  static pair<int, int> path[N][N];
  fill(&vis[0][0], &vis[N - 1][N - 1] + 1, false);
  {
    auto [i, j] = initial_positions[robot_index];
    vis[i][j] = true;
    path[i][j] = make_pair(-1, -1);
  }

  vec<int> ord;
  function<void(int, int)> rec = [&] (int i, int j) {
    ord.push_back(label[i][j]);
    each (d, ds) {
      const int ni = i + di[d];
      const int nj = j + dj[d];
      unless (0 <= ni && ni < H) continue;
      unless (0 <= nj && nj < W) continue;
      if (vis[ni][nj]) continue;
      if (wall[i][j][d]) continue;
      vis[ni][nj] = true;
      rec(ni, nj);
    }
    return ;
  };
  auto [ri, rj] = initial_positions[robot_index];
  rec(ri, rj);
  ord.erase(ord.begin());
  return ord;
}

void show(State& s)
{
  for (int i = 0; i < K; ++i) {
    for (int j = 0; j < M; ++j) {
      cout << dir_str[s.buttons.at(i).at(j)] << ' ';
    }
    cout << "\n";
  }
  vec<int> b = s.simulate();
  each (i, b) cout << i << "\n";
  return ;
}

int main(int argc, char *argv[])
{
  const auto time_start = chrono::steady_clock::now();

  positions.clear();
  for (int i = 0; i < N; ++i) {
    for (int j = 0; j < N; ++j) {
      label[i][j] = positions.size();
      positions.push_back(make_pair(i, j));
    }
  }
  {
    int n, m, k;
    cin >> n >> m >> k;
  }
  assert(cin >> initial_positions);

  for (int i = 0; i < wall_R.size(); ++i) {
    for (int j = 0; j < wall_R[i].size(); ++j) {
      char c;
      cin >> c;
      wall_R[i][j] = (c - '0');
    }
  }
  for (int i = 0; i < wall_D.size(); ++i) {
    for (int j = 0; j < wall_D[i].size(); ++j) {
      char c;
      cin >> c;
      wall_D[i][j] = (c - '0');
    }
  }

  wall.resize(N, vec<array<bool, 4>>(N));

  for (int i = 0; i < H; ++i) {
    for (int j = 0; j < W - 1; ++j) {
      wall[i][j][dir_R] = wall_R[i][j];
    }
  }
  for (int i = 0; i < H - 1; ++i) {
    for (int j = 0; j < W; ++j) {
      wall[i][j][dir_D] = wall_D[i][j];
    }
  }
  for (int i = 1; i < H; ++i) {
    for (int j = 0; j < W; ++j) {
      wall[i][j][dir_U] = wall[i - 1][j][dir_D];
    }
  }
  for (int i = 0; i < H; ++i) {
    for (int j = 1; j < W; ++j) {
      wall[i][j][dir_L] = wall[i][j - 1][dir_R];
    }
  }

  State best(build_spanning_tree(0, {0,1,2,3}), 0);
  best.simulate();

  for (int i = 1; i < M; ++i) {
    vec<int> ds({0, 1, 2, 3});
    sort(ds.begin(), ds.end());
    do {
      State s(build_spanning_tree(i, ds), i);
      s.simulate();
      cerr << i << ds << s.score << endl;
      if (best.score > s.score) best = s;
    } while (next_permutation(ds.begin(), ds.end()));
  }

  cerr << best.score << ' ' << best.target << endl;
  show(best);

  return 0;
}
