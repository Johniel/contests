// github.com/Johniel/contests
// atcoder/abc465/F/main.cpp

#include <bits/stdc++.h>

#define each(i, c) for (auto& i : c)
#define unless(cond) if (!(cond))
#define __builtin_popcount(x) __builtin_popcountll(x)

using namespace std;

template<typename P, typename Q> ostream& operator << (ostream& os, pair<P, Q> p);
template<typename P, typename Q> istream& operator >> (istream& is, pair<P, Q>& p);
template<typename... Ts> ostream& operator << (ostream& os, const tuple<Ts...>& t) { os << "("; if constexpr (sizeof...(Ts) > 0) { apply([&](const Ts&... args) { ((os << args << ','), ...); }, t); } os << ")"; return os; }
template<typename... Ts> istream& operator >> (istream& is, tuple<Ts...>& t) { apply([&](Ts&... args) { ((is >> args), ...); }, t); return is; }
template<typename T> ostream& operator << (ostream& os, const vector<T>& v) { os << "("; for (const auto& i: v) os << i << ","; os << ")"; return os; }
template<typename T> istream& operator >> (istream& is, vector<T>& v) { for (auto& i: v) is >> i; return is; }
template<typename T> ostream& operator << (ostream& os, const set<T>& s) { os << "set{"; for (const auto& i: s) os << i << ","; os << "}"; return os; }
template<typename K, typename V> ostream& operator << (ostream& os, const map<K, V>& m) { os << "map{"; for (const auto& i: m) os << i << ","; os << "}"; return os; }
template<typename E, size_t N> istream& operator >> (istream& is, array<E, N>& a) { for (auto& i: a) is >> i; return is; }
template<typename E, size_t N> ostream& operator << (ostream& os, array<E, N>& a) { os << "[" << N << "]{"; for (const auto& i: a) os << i << ","; os << "}"; return os; }
template<typename T> ostream& operator << (ostream& os, stack<T> s) { os << "stack{"; while (s.size()) { os << s.top() << ","; s.pop(); } os << "}"; return os; }
template<typename T> ostream& operator << (ostream& os, queue<T> q) { os << "queue{"; while (q.size()) { os << q.front() << ","; q.pop(); } os << "}"; return os; }
template<typename T> ostream& operator << (ostream& os, const deque<T>& q) { os << "deque{"; for (int i = 0; i < q.size(); ++i) os << q[i] << ","; os << "}"; return os; }
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
  pair<size_t, size_t> size(void) const { return make_pair(sum.size() - 1, sum[0].size() - 1); }
};

    // for (int i1 = 0; i1 < 11; ++i1) {
    //   for (int i2 = 0; i2 < 11; ++i2) {
    //     for (int i3 = 0; i3 < 11; ++i3) {
    //       for (int i4 = 0; i4 < 11; ++i4) {
    //         for (int i5 = 0; i5 < 11; ++i5) {
    //           for (int i6 = 0; i6 < 11; ++i6) {
    //             sum[i1][i2][i3][i4][i5][i6] = 0;
    //           }
    //         }
    //       }
    //     }
    //   }
    // }


const int D = 11;
template<typename T>
struct PrefixSum6D {
  lli sum[11][11][11][11][11][11];
  PrefixSum6D() {}
  void init(void) {
    fill(&sum[0][0][0][0][0][0], &sum[D - 1][D - 1][D - 1][D - 1][D - 1][D - 1] + 1, 0);
  }

  // https://qiita.com/drken/items/56a6b68edef8fc605821#4-%E4%BA%8C%E6%AC%A1%E5%85%83%E7%B4%AF%E7%A9%8D%E5%92%8C
  // https://qiita.com/convexineq/items/afc84dfb9ee4ec4a67d5
  // https://atcoder.jp/contests/abc366/editorial/10643
  void build(void) {
    for (int i1 = 0; i1 + 1 < 11; ++i1) {
      for (int i2 = 0; i2 + 1 < 11; ++i2) {
        for (int i3 = 0; i3 + 1 < 11; ++i3) {
          for (int i4 = 0; i4 + 1 < 11; ++i4) {
            for (int i5 = 0; i5 + 1 < 11; ++i5) {
              for (int i6 = 0; i6 + 1 < 11; ++i6) {

                static vec<int> idx(6);
                for (int bit = 1; bit < (1 << 6); ++bit) {
                  for (int i = 0; i < 6; ++i) {
                    idx[i] = !!(bit & (1 << i));
                  }

                  T x = sum
                    [i1 + 1 - idx[0]]
                    [i2 + 1 - idx[1]]
                    [i3 + 1 - idx[2]]
                    [i4 + 1 - idx[3]]
                    [i5 + 1 - idx[4]]
                    [i6 + 1 - idx[5]];
                  int p = accumulate(idx.begin(), idx.end(), 0);
                  unless (p % 2) x *= -1;
                  sum[i1 + 1][i2 + 1][i3 + 1][i4 + 1][i5 + 1][i6 + 1] += x;
                }
              }
            }
          }
        }
      }
    }
    return ;
  }

  T query(int a1, int a2, int a3, int a4, int a5, int a6,
          int b1, int b2, int b3, int b4, int b5, int b6) const {
    T x = 0;
    const vec<int> a({a1, a2, a3, a4, a5, a6});
    const vec<int> b({b1, b2, b3, b4, b5, b6});

    for (int i = 0; i < 6; ++i) {
      unless (a[i] <= b[i]) return 0;
    }

    for (int bit = 0; bit < (1 << 6); ++bit) {
      static vec<int> idx(6);
      for (int i = 0; i < 6; ++i) {
        if (bit & (1 << i)) idx[i] = b[i];
        else idx[i] = a[i];
      }
      if (__builtin_popcountll(bit) % 2) {
        x -= sum[idx[0]][idx[1]][idx[2]][idx[3]][idx[4]][idx[5]];
      } else {
        x += sum[idx[0]][idx[1]][idx[2]][idx[3]][idx[4]][idx[5]];
      }
    }
    return x;
    // return sum[bi][bj] + sum[ai][aj] - sum[ai][bj] - sum[bi][aj];
  }
};

int main(int argc, char *argv[])
{
  int n;
  while (cin >> n) {
    static PrefixSum6D<lli> sum;
    sum.init();
    for (int i = 0; i < n; ++i) {
      str s;
      int v;
      cin >> s >> v;
      sum.sum
        [s[0] - '0' + 1]
        [s[1] - '0' + 1]
        [s[2] - '0' + 1]
        [s[3] - '0' + 1]
        [s[4] - '0' + 1]
        [s[5] - '0' + 1] += v;
    }
    // cout << "test" << endl;
    sum.build();
    int q;
    cin >> q;
    while (q--) {
      str a, b;
      cin >> a >> b;
      cout << sum.query(
        a[0] - '0',
        a[1] - '0',
        a[2] - '0',
        a[3] - '0',
        a[4] - '0',
        a[5] - '0',
        b[0] - '0' + 1,
        b[1] - '0' + 1,
        b[2] - '0' + 1,
        b[3] - '0' + 1,
        b[4] - '0' + 1,
        b[5] - '0' + 1) << endl;
    }
  }
  return 0;
}
