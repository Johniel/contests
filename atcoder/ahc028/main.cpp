// github.com/Johniel/contests
// atcoder/ahc028/main.cpp

#include <bits/stdc++.h>

#define each(i, c) for (auto& i : c)
#define each_with_index(i, e, c) for (const auto i: views::iota(0, (int)c.size())) if (auto& e = c.at(i); true)
#define each_pair(p, c) for (const auto _i: views::iota(0, (int)c.size())) if (std::pair<const int, decltype((c.at(_i)))> p = {_i, c[_i]}; true)
#define unless(cond) if (!(cond))
// #define endl "\n"

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

__attribute__((constructor)) static void ___initio(void) { ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.setf(ios_base::fixed); cout.precision(15); return ; }

using lli = long long int;
using ull = unsigned long long;
using str = string;
template<typename T> using vec = vector<T>;

constexpr array<int, 8> di({0, 1, -1, 0, 1, -1, 1, -1});
constexpr array<int, 8> dj({1, 0, 0, -1, 1, -1, -1, 1});
constexpr lli mod = 998244353;

template<typename T>
T manhattan_distance(pair<T, T> a, pair<T, T> b) {
  return abs(a.first - b.first) + abs(a.second - b.second);
}

// (x,y) => (x-y,x+y)
// manhattan_rot45 ignores 1/sqrt(2)
// マンハッタン距離の45度回転後はチェビシェフ距離
template<typename T>
pair<T, T> manhattan_rot45(pair<T, T> p) {
  return make_pair(p.first - p.second, p.first + p.second);
}

template<typename T>
T chebyshev_distance(pair<T, T> a, pair<T, T> b) {
  return max(abs(a.first - b.first), abs(a.second - b.second));
}

template<typename T>
T chebyshev_distance(vector<T> a, vector<T> b) {
  assert(a.size() == b.size());
  T mx = std::numeric_limits<T>::min();
  for (int i = 0; i < a.size(); ++i) {
    mx = max(mx, abs(a[i] - b[i]));
  }
  return mx;
}

const int WORD_SIZE = 5;
const int N = 15;
const int M = 200;
char keybord[N][N];
map<char, vec<pair<int, int>>> positions;
vec<str> words(M);

const int inf32 = 1 << 29;
const lli inf64 = 1LL << 61;

int overwrapped(str a, str b)
{
  // clog << "overwrapped: " << a << "," << b << endl;
  assert(a.size() >= b.size());
  for (int i = a.size() - b.size(); i < a.size(); ++i) {
    bool f = true;
    for (int j = 0; j < b.size() && i + j < a.size(); ++j) {
      f = f && (a[i + j] == b[j]);
    }
    if (f) {
      return a.size() - i;
    }
  }
  return 0;
}

str compress(str a, str b)
{
  assert(a.size() >= b.size());
  int rm = overwrapped(a, b);
  while (rm--) a.pop_back();
  return a + b;
}

vec<str> compress_words(void)
{
  static int g[M][M];
  fill(&g[0][0], &g[M - 1][M - 1] + 1, -inf32);
  for (int i = 0; i < words.size(); ++i) {
    for (int j = 0; j < words.size(); ++j) {
      g[i][j] = overwrapped(words[i], words[j]);
    }
  }

  random_device seed_gen;
  mt19937 engine(seed_gen());

  vec<int> numbering(M);
  iota(numbering.begin(), numbering.end(), 0);

  set<vec<int>> inq;
  priority_queue<pair<int, vec<int>>> q;

  for (int _ = 0; _ < 130; ++_) {
    for (int src = 0; src < M; ++src) {
      static bool vis[M];
      fill(vis, vis + M, false);
      vis[src] = true;
      vec<int> u;
      int x = 0;
      u.push_back(src);
      for (int curr = src; ; ) {
        int best = -1;
        int mx = -inf32;
        each (next, numbering) {
          if (!vis[next] && mx < g[curr][next]) {
            best = next;
            mx = g[curr][next];
          }
        }
        if (best == -1) break;
        u.push_back(best);
        vis[best] = true;
        curr = best;
        x += mx;
      }
      if (!inq.count(u)) {
        q.push(make_pair(-x, u));
        inq.insert(q.top().second);
      }
    }
    while (12 < q.size()) {
      inq.erase(q.top().second);
      q.pop();
    }
    shuffle(numbering.begin(), numbering.end(), engine);
  }

  vec<str> texts;
  while (q.size()) {
    vec<int> v = q.top().second;
    // clog << q.top() << endl;
    q.pop();
    str s = words[v[0]];
    for (int i = 1; i < v.size(); ++i) {
      s = compress(s, words[v[i]]);
    }
    texts.push_back(s);
  }
  return texts;
}

pair<int, vec<pair<int, int>>> type(const str& text, const pair<int, int>& src)
{
  const int TEXT_LEN = WORD_SIZE * M + 3;
  static int dp[TEXT_LEN][N][N]; // [何文字目][いまどこi][いまどこj]
  fill(&dp[0][0][0], &dp[TEXT_LEN - 1][N - 1][N - 1] + 1, inf32);
  dp[0][src.first][src.second] = 0;
  static pair<int, int> path[TEXT_LEN][N][N];
  for (int k = 0; k < text.size(); ++k) {
    for (int i = 0; i < N; ++i) {
      for (int j = 0; j < N; ++j) {
        if (dp[k][i][j] == inf32) continue;
        each (p, positions[text[k]]) {
          int dist = manhattan_distance(make_pair(i, j), p);
          if (dp[k + 1][p.first][p.second] > dp[k][i][j] + dist) {
            dp[k + 1][p.first][p.second] = dp[k][i][j] + dist;
            path[k + 1][p.first][p.second] = make_pair(i, j);
          }
        }
      }
    }
  }

  int mn = inf32;
  int a, b;
  for (int i = 0; i < N; ++i) {
    for (int j = 0; j < N; ++j) {
      if (mn > dp[text.size()][i][j]) {
        mn = dp[text.size()][i][j];
        a = i;
        b = j;
      }
    }
  }
  int md = 0;
  vec<pair<int, int>> v;
  for (int k = text.size(); k; --k) {
    v.push_back(make_pair(a, b));
    auto [na, nb] = path[k][a][b];
    md += manhattan_distance(make_pair(a, b), make_pair(na, nb));
    a = na;
    b = nb;
  }
  reverse(v.begin(), v.end());
  return make_pair(md, v);
}

int main(int argc, char *argv[])
{
  assert(overwrapped("xyz", "abc") == 0);
  assert(overwrapped("xyz", "yzw") == 2);
  assert(overwrapped("xyz", "xyz") == 3);
  assert(overwrapped("abcxyz", "xyz") == 3);

  assert(compress("xyz", "yzw") == "xyzw");
  assert(compress("xyz", "abc") == "xyzabc");

  { int _; cin >> _ >> _; }
  pair<int, int> src;
  cin >> src;

  for (int i = 0; i < N; ++i) {
    for (int j = 0; j < N; ++j) {
      cin >> keybord[i][j];
      positions[keybord[i][j]].push_back(make_pair(i, j));
    }
  }

  cin >> words;
  each (w, words) assert(w.size() == 5);
  // str text = compress_words_rm1();
  vec<str> texts = compress_words();
  int mn = inf32;
  str text;
  vec<pair<int, int>> v;
  each (t, texts) {
    auto [cost, u] = type(t, src);
    if (mn > cost) {
      text = t;
      mn = cost;
      v = u;
    }
  }
  each (i, v) cout << i.first << ' ' << i.second << endl;

  {
    // clog << words.size() * 5 << " >= " << text.size() << endl; clog << mn << endl;
    str t;
    each (i, v) t += keybord[i.first][i.second];
    each (w, words) assert(text.find(w) != str::npos);
    assert(text == t);
  }

  return 0;
}
