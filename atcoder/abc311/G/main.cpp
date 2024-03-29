// github.com/Johniel/contests
// atcoder/abc311/G/main.cpp

#include <bits/stdc++.h>

#define each(i, c) for (auto& i : c)
#define unless(cond) if (!(cond))
// #define endl "\n"

using namespace std;

template<typename P, typename Q> ostream& operator << (ostream& os, pair<P, Q> p) { os << "(" << p.first << "," << p.second << ")"; return os; }
template<typename P, typename Q> istream& operator >> (istream& is, pair<P, Q>& p) { is >> p.first >> p.second; return is; }
template<typename T> ostream& operator << (ostream& os, vector<T> v) { os << "("; for (auto& i: v) os << i << ","; os << ")"; return os; }
template<typename T> istream& operator >> (istream& is, vector<T>& v) { for (auto& i: v) is >> i; return is; }
template<typename T> ostream& operator << (ostream& os, set<T> s) { os << "#{"; for (auto& i: s) os << i << ","; os << "}"; return os; }
template<typename K, typename V> ostream& operator << (ostream& os, map<K, V> m) { os << "{"; for (auto& i: m) os << i << ","; os << "}"; return os; }
template<typename E, size_t N> istream& operator >> (istream& is, array<E, N>& a) { for (auto& i: a) is >> i; return is; }
template<typename E, size_t N> ostream& operator << (ostream& os, array<E, N>& a) { os << "[" << N << "]{"; for (auto& i: a) os << i << ","; os << "}"; return os; }

template<typename T> inline T setmax(T& a, T b) { return a = std::max(a, b); }
template<typename T> inline T setmin(T& a, T b) { return a = std::min(a, b); }

__attribute__((constructor)) static void ___initio(void) { ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.setf(ios_base::fixed); cout.precision(15); return ; }

using lli = long long int;
using ull = unsigned long long;
using str = string;
template<typename T> using vec = vector<T>;

constexpr array<int, 8> di({0, 1, -1, 0, 1, -1, 1, -1});
constexpr array<int, 8> dj({1, 0, 0, -1, 1, -1, -1, 1});

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
    assert(0 <= ai && ai < sum.size());
    assert(0 <= bi && bi < sum.size());
    assert(0 <= aj && aj < sum[0].size());
    assert(0 <= bj && bj < sum[0].size());
    assert(ai <= bi && aj <= bj);
    return sum[bi][bj] + sum[ai][aj] - sum[ai][bj] - sum[bi][aj];
  }
};

template<typename T>
struct CartesianTree {
  // abc311G
  vector<int> parent;
  CartesianTree() {}
  CartesianTree(const vector<T>& a) : parent(a.size(), -1) {
    vector<int> st;
    for (int i = 0; i < a.size(); ++i) {
      int prev = -1;
      while (st.size() && a[i] < a[st.back()]) {
        prev = st.back();
        st.pop_back();
      }
      if (prev != -1) parent[prev] = i;
      if (st.size()) parent[i] = st.back();
      st.push_back(i);
    }
  }
};

const int H = 300 + 2;
const int W = 300 + 2;
vec<vec<int>> g;
tuple<int, int, int> rect[H][W];
void fn(const int h, const int w)
{
  static int dp[H][W];
  for (int i = 0; i < h; ++i) {
    for (int j = 0; j < w; ++j) {
      dp[i][j] = (g[i][j] != -1);
    }
  }

  for (int i = 1; i < h; ++i) {
    for (int j = 0; j < w; ++j) {
      if (dp[i][j]) dp[i][j] = dp[i - 1][j] + 1;
    }
  }

  const int N = H;
  static vec<int> tree[N];
  vec<pair<int, int>> u;
  function<void(int, int, int)> fn = [&] (int curr, int begin, int end) {
    u[curr] = make_pair(begin, end);
    each (next, tree[curr]) {
      if (curr < next) {
        fn(next, curr + 1, end);
      } else {
        fn(next, begin, curr);
      }
    }
    return ;
  };

  const int inf = 1 << 29;
  for (int i = 0; i < h; ++i) {
    vec<int> v;
    for (int j = 0; j < w; ++j) {
      v.push_back(dp[i][j] ? dp[i][j] : -inf);
    }
    CartesianTree<int> ct(v);
    // cout << "v:" << v << endl;
    // cout << "ct.parent" << ct.parent << endl;
    fill(tree, tree + H, vec<int>());
    int root;
    for (int i = 0; i < ct.parent.size(); ++i) {
      if (ct.parent[i] != -1) tree[ct.parent[i]].push_back(i);
      else root = i;
    }
    u.resize(N);
    fn(root, 0, v.size());
    for (int j = 0; j < w; ++j) {
      rect[i][j] = make_tuple(v[j], u[j].first, u[j].second);
    }
  }
  return ;
}

int main(int argc, char *argv[])
{
  int h, w;
  while (cin >> h >> w) {
    g.resize(H, vec<int>(W));
    for (int i = 0; i < h; ++i) {
      for (int j = 0; j < w; ++j) {
        cin >> g[i][j];
      }
    }
    map<int, vec<pair<int, int>>> m;
    for (int i = 0; i < h; ++i) {
      for (int j = 0; j < w; ++j) {
        m[g[i][j]].push_back(make_pair(i, j));
      }
    }

    PrefixSum2D<int> sum(g);

    lli mx = 0;
    each (k, m) {
      // cout << k.first << endl;
      fn(h, w);
      for (int i = 0; i < h; ++i) {
        for (int j = 0; j < w; ++j) {
          if (g[i][j] != -1) {
            auto [a, wbegin, wend] = rect[i][j];
            lli z = sum(i - (a - 1), wbegin, i + 1, wend);
            if (k.first == 3) {
              // cout << make_pair(i - (a - 1), i + 1) << ' ' << wbegin <<' ' << wend << endl;
              // cout << make_pair(i - (a - 1), wbegin) << ' ' << make_pair(i + 1, wend)<< endl;
            }
            setmax(mx, z * k.first);
          }
        }
      }
      each (p, k.second) g[p.first][p.second] = -1;
    }
    cout << mx << endl;
    // break;
  }
  return 0;
}
