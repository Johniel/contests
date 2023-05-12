// github.com/Johniel/contests
// atcoder/abc282/G/main.cpp

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

lli mod;

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
    // cout << make_pair(ai, aj) << ' ' << make_pair(bi, bj) << endl;
    assert(0 <= ai && ai < sum.size());
    assert(0 <= bi && bi < sum.size());
    assert(0 <= aj && aj < sum[0].size());
    assert(0 <= bj && bj < sum[0].size());
    assert(ai <= bi && aj <= bj);
    return sum[bi][bj] + sum[ai][aj] - sum[ai][bj] - sum[bi][aj];
  }
};

const int N = 100 + 3;
// lli dp[N][N][N][N];
// dp[今何番目][類似度][最後がa][最後がb][aより大きいものの残り][bより大きいものの残り]
// dp[今何番目][類似度][直前より大きいものの残り][直前より大きいものの残り]:=パターン数 ※(n-i)個からどれを選ぶかでO(N^2)

// lli f()
// {
//   for (int i = 0; i < N; ++i) {
//     for (int sim = 0; sim < N; ++sim) {
//       for (int la = 0; la < N; ++la) {
//         for (int lb = 0; lb < N; ++lb) {
//           const int sa = (n - i) - la;
//           const int sb = (n - i) - lb;
//           for (int x = 0; x < n - i; ++x) {
//             for (int y = 0; y < n - i; ++y) {
//               // 配る
//               (dp[i + 1][sim + (x < sa) * (y < sb)][(n - i) - x][(n - i) - y] += dp[i][sim][a][b]) %= mod;
//               // 貰う
//               dp[i][sim][x][y] += dp[i - 1][sim - (x < sa) * (y < sb)][a - ((n - i) - x)][b - ((n - i) - y)];
//             }
//           }
//         }
//       }
//     }
//   }
// }

int main(int argc, char *argv[])
{
  int n, k;
  while (cin >> n >> k >> mod) {
    const int N = 100 + 2;
    PrefixSum2D<lli> sum[N][N];
    static lli dp[N][N][N][N];
    fill(&dp[0][0][0][0], &dp[N - 1][N - 1][N - 1][N - 1] + 1, 0);
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j) {
        dp[0][0][i][j] = 1;
      }
    }
    for (int i = 1; i < n; ++i) {
      for (int sim = 0; sim < n; ++sim) {
        if (0 <= i - 2) sum[i - 2][sim].sum.clear();
      }
      for (int sim = 0; sim < n; ++sim) {
        if (0 <= sim - 2) sum[i][sim - 2].sum.clear();

        if (sim) {
          vec<vec<lli>> v(n+1, vec<lli>(n+1, 0));
          for (int a = 0; a <= n; ++a) {
            for (int b = 0; b <= n; ++b) {
              v[a][b] = dp[i - 1][sim - 1][a][b];
            }
          }
          sum[i - 1][sim - 1] = PrefixSum2D<lli>(v);
        }
        {
          vec<vec<lli>> v(n+1, vec<lli>(n+1, 0));
          for (int a = 0; a <= n; ++a) {
            for (int b = 0; b <= n; ++b) {
              v[a][b] = dp[i - 1][sim][a][b];
            }
          }
          sum[i - 1][sim] = PrefixSum2D<lli>(v);
        }
        const int remained = n - i + 1;
        for (int la = 0; la < remained; ++la) {
          for (int lb = 0; lb < remained; ++lb) {
            const int sa = remained - la;
            const int sb = remained - lb;
            // cout << make_pair(la, lb) << ' ' << make_pair(sa, sb) << ' ' << remained << endl;
            // (A[i+1]−A[i])(B[i+1]−B[i])>0
            lli x = 0;
            if (sim) {
              x += sum[i - 1][sim - 1].query(0, 0, la+1, lb+1); // 正正
              x += sum[i - 1][sim - 1].query(la+1, lb+1, remained, remained); // 負負
              x %= mod;
            }
            x += sum[i - 1][sim - 0].query(0, lb+1, la+1, remained); // 正負
            x += sum[i - 1][sim - 0].query(la+1, 0, remained, lb+1); // 負正
            x %= mod;

            // auto get = [&](int id, int lx, int rx, int ly, int ry) -> mint {
            //   if(lx >= rx or ly >= ry) return 0;
            //   return ct[id][rx][ry] - ct[id][lx][ry] - ct[id][rx][ly] + ct[id][lx][ly];
            // };

            // get(ns, 0, i + 1, j + 1, n+1-t) +
            // get(ns, i + 1, n+1-t, 0, j + 1) +
            // (ns ?
            //   get(ns - 1, 0, i + 1, 0, j + 1) +
            //   get(ns - 1, i + 1, n + 1 - t, j + 1, n + 1 - t) : 0);

            dp[i][sim][la][lb] = x;
          }
        }
      }
    }
    cout << dp[n - 1][k][0][0] << endl;
    // 3 2
    // [1,2,3],[1,2,3]
    // [3,2,1],[3,2,1]
    // [1,3,2],[1,3,2]
    // 3!=6通り

    // 3 1
    // 16通り

    // (3^2)^2=3^4=81
    //(+ 16 32 16) ; 64
  }
  return 0;
}
