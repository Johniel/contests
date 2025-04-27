// github.com/Johniel/contests
// atcoder/ahc046/main.cpp

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

const int N = 20;
const int M = 40;

constexpr array<int, 8> di({0, 1, -1, 0, 1, -1, 1, -1});
constexpr array<int, 8> dj({1, 0, 0, -1, 1, -1, -1, 1});
const str D = "RDUL";
pair<int, int> path[N][N];
char pathD[N][N];
char pathC[N][N];

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

inline bool isA (const char c) {
  return c == 'A' || c == '_';
}

const int inf = (N * N * N * N);
vec<pair<int, int>> pos;
const int K = 5;
const int T = 35;
int g[N][N];
struct State {
  int score = 0;
  vec<int> sol;
  vec<pair<char, char>> cmd;
  vec<int> ss;

  int block[N][N];

  State() {
    fill(&block[0][0], &block[N - 1][N - 1] + 1, 0);
  }

  static State random_initial(void) {
    while (true) {
      State st;
      for (int i = 0; i < M; ++i) {
        st.sol.push_back(K);
      }
      st.sol.back() = K;
      st.calc_score();
      st.score = accumulate(st.ss.begin(), st.ss.end(), 0);
      if (st.score < inf) return st;
      // clog << "retry" << endl;
    }
  }

  bool calc_score(const int start = 0) {
    if (start) {
      assert(cmd.size() == ss.size());
      int A = M - 1;
      while (start < A) {
        assert(cmd.size());
        assert(ss.size());
        A -= isA(cmd.back().first);
        cmd.pop_back();
        ss.pop_back();
      }
    } else {
      cmd.clear();
      ss.clear();
    }
    for (int i = 0; i < N; ++i) {
      for (int j = 0; j < N; ++j) {
        if (start + 1 <= block[i][j]) block[i][j] = 0;
      }
    }
    if (0) {
      cerr << "start:" << start << endl;
      for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
          cerr << block[i][j] << ' ';
        }
        cerr << endl;
      }
    }

    for (int dst = start + 1; dst < M; ++dst) {
      const int curr = dst - 1;
      if (const int k = sol[curr]; k < 4) {
        const auto [i, j] = pos[curr];
        const int ni = i + di[k];
        const int nj = j + dj[k];
        if (0 <= ni && ni < N && 0 <= nj && nj < N && g[ni][nj] <= curr && curr < T) {
          if (block[ni][nj]) {
            ss.push_back(0);
            cmd.push_back(make_pair('_', '_'));
          } else {
            block[ni][nj] = dst;
            ss.push_back(1);
            cmd.push_back(make_pair('A', D[k]));
          }
        } else {
          ss.push_back(0);
          cmd.push_back(make_pair('_', '_'));
        }
      } else {
        ss.push_back(0);
        cmd.push_back(make_pair('_', '_'));
      }
      if (inf < ss.size()) return false;
      int cost[N][N];
      fill(&cost[0][0], &cost[N - 1][N - 1] + 1, inf);
      cost[pos[curr].first][pos[curr].second] = 0;
      path[pos[curr].first][pos[curr].second] = pos[curr];
      priority_queue<pair<int, pair<int, int>>> q;
      for (q.push(make_pair(0, pos[curr])); q.size(); ) {
        auto p = q.top();
        q.pop();
        const auto [i, j] = p.second;
        assert(block[i][j] == 0);
        const int c = abs(p.first);
        if (cost[i][j] != c) continue;
        if (p.second == pos[dst]) break;
        for (int d = 0; d < 4; ++d) {
          int last = -1;
          for (int len = 1; len < N; ++len) {
            const int ni = i + di[d] * len;
            const int nj = j + dj[d] * len;
            unless (0 <= ni && ni < N) break;
            unless (0 <= nj && nj < N) break;
            if (block[ni][nj]) break;
            if (cost[ni][nj] > cost[i][j] + len) {
              cost[ni][nj] = cost[i][j] + len;
              {
                const int mi = i + di[d] * (len - 1);
                const int mj = j + dj[d] * (len - 1);
                path[ni][nj] = make_pair(mi, mj);
                pathD[ni][nj] = D[d];
                pathC[ni][nj] = 'M';
                assert(path[ni][nj] != make_pair(ni, nj));
              }
              q.push(make_pair(-cost[ni][nj], make_pair(ni, nj)));
            }
            last = len;
          }
          if (1 < last) {
            const int ni = i + di[d] * last;
            const int nj = j + dj[d] * last;
            if (cost[ni][nj] > cost[i][j] + 1) {
              cost[ni][nj] = cost[i][j] + 1;
              {
                path[ni][nj] = make_pair(i, j);
                pathD[ni][nj] = D[d];
                pathC[ni][nj] = 'S';
                assert(path[ni][nj] != make_pair(ni, nj));
              }
              q.push(make_pair(-cost[ni][nj], make_pair(ni, nj)));
            }
          }
        }
      }
      if (inf <= cost[pos[dst].first][pos[dst].second]) {
        cerr << ">>retry" << curr << endl;
        return false;
      }
      {
        pair<int, int> p = pos[dst];
        vec<pair<char, char>> v;
        while (p != pos[curr]) {
          const auto [i, j] = p;
          v.push_back(make_pair(pathC[i][j], pathD[i][j]));
          p = path[i][j];
          ss.push_back(1);
          if (inf < ss.size()) return false;
        }
        reverse(v.begin(), v.end());
        each (i, v) cmd.push_back(i);
      }
    }

    return true;
  }

  /* ------------ 近傍遷移 ------------ */
  // 適当な方法で 1 回の変更を施し、差分更新して返す
  State neighbor() const {
    while (true) {
      State next = *this;
      int idx = xorshift() % T;
      next.sol[idx] = xorshift() % K;
      // ここではスコアをフル再計算しているが差分高速化できるなら差分更新に置き換える
      // next.calc_score(idx);
      bool f = next.calc_score(idx);
      next.score = accumulate(next.ss.begin(), next.ss.end(), 0);
      if (f) return next;
      if (0) {
        cerr << next.sol << ' ' << idx << endl;
        for (int i = 0; i < N; ++i) {
          for (int j = 0; j < N; ++j) {
            cerr << next.block[i][j] << ' ';
          }
          cerr << endl;
        }
        // exit(1);
      }
    }
  }
};

struct SA_Param {
  const double T0       = 1e3;   // 初期温度
  const double T_end    = 1e-3;  // 終了温度
  const double time_lim = 1.95;  // 制限時間（秒）
};

static std::mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());

inline double randR() {
  static std::uniform_real_distribution<double> dist(0.0, 1.0);
  return dist(rng);
}


int main(int argc, char *argv[])
{
  xorshift();
  int n, m;
  while (cin >> n >> m) {
    pos.resize(M);
    cin >> pos;
    for (int i = 0; i < pos.size(); ++i) {
      g[pos[i].first][pos[i].second] = i;
    }

    SA_Param P;
    const auto t_start = chrono::steady_clock::now();
    const auto time_limit = P.time_lim;

    State cur = State::random_initial();
    State best = cur;

    lli iter = 0;
    while (true) {
      ++iter;

      /* --- 経過時間チェック --- */
      double elapsed = chrono::duration<double>(chrono::steady_clock::now() - t_start).count();
      if (elapsed >= time_limit) break;

      /* --- 温度計算 (線形スケジュール) --- */
      double progress = elapsed / time_limit;
      double T = P.T0 + (P.T_end - P.T0) * progress; // linear
      // double T = P.T0 * pow(P.T_end / P.T0, progress); // exponential

      /* --- 近傍生成 --- */
      State nxt = cur.neighbor();
      const lli diff = nxt.score - cur.score;

      /* --- 受理判定 --- */
      if (diff >= 0 || randR() < exp(diff / T)) {
        cur = move(nxt);
        if (cur.score < best.score) best = cur;
      }
    }

    /* ---- 出力 ---- */
    // best.sol / best.score を問題に合わせて整形
    clog << "Iter = " << iter << "  BestScore = " << best.score << '\n';
    int parity = 0;
    for (int i = 0; i < best.cmd.size(); ++i) {
      if (best.cmd[i].first != '_') {
        cout << best.cmd[i].first << ' ' << best.cmd[i].second << endl;
        ++parity;
      }
    }
    cout << endl;
    // clog << best.score << ' ' << best.cmd.size() << endl;
    assert(best.score == parity);
  }
  return 0;
}
