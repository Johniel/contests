// github.com/Johniel/contests
// atcoder/abc366/D/main.cpp

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

// __attribute__((constructor)) static void _____(void) { ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.setf(ios_base::fixed); cout.bcision(15); return ; }

using lli = long long int;
using ull = unsigned long long;
using str = string;
template<typename T> using vec = vector<T>;

template<std::integral T>
struct PrefixSum3D {
  // ABC366D
  PrefixSum3D(vector<vector<vector<T>>> a) {
    sum = vector<vector<vector<lli>>>(a.size() + 1, vector<vector<T>>(a[0].size() + 1, vector<T>(a[0][0].size() + 1, 0)));
    for (int i = 0; i < a.size(); ++i) {
      for (int j = 0; j < a[i].size(); ++j) {
        for (int k = 0; k < a[j].size(); ++k) {
          sum[i + 1][j + 1][k + 1] = (sum[i][j + 1][k + 1]
                                      + sum[i + 1][j][k + 1]
                                      + sum[i + 1][j + 1][k]
                                      - sum[i][j][k + 1]
                                      - sum[i][j + 1][k]
                                      - sum[i + 1][j][k]
                                      + sum[i][j][k]
                                      + a[i][j][k]);
        }
      }
    }
  }

  T query(int bx, int ex, int by, int ey, int bz, int ez) const {
    assert(0 <= bx && bx <= ex && ex <= sum.size());
    assert(0 <= by && by <= ey && ey <= sum[bx].size());
    assert(0 <= bz && bz <= ez && ez <= sum[bx][by].size());
    return (sum[ex][ey][ez]
            - sum[bx][ey][ez]
            - sum[ex][by][ez]
            - sum[ex][ey][bz]
            + sum[bx][by][ez]
            + sum[bx][ey][bz]
            + sum[ex][by][bz]
            - sum[bx][by][bz]);
  }

  vector<vector<vector<T>>> sum;
};

int main(int argc, char *argv[])
{
  int n;
  while (cin >> n) {
    vec<vec<vec<lli>>> a(n, vec<vec<lli>>(n, vec<lli>(n, 0)));
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j) {
        for (int k = 0; k < n; ++k) {
          cin >> a[i][j][k];
        }
      }
    }

    PrefixSum3D<lli> sum(a);

    int q;
    cin >> q;
    while (q--) {
      int lx, rx;
      int ly, ry;
      int lz, rz;
      cin >> lx >> rx;
      cin >> ly >> ry;
      cin >> lz >> rz;

      --lx;
      --ly;
      --lz;

      cout << sum.query(lx, rx, ly, ry, lz, rz) << endl;
    }
  }
  return 0;
}
