// github.com/Johniel/contests
// atcoder/abc297/G/main.cpp

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
template<typename T> using heap = priority_queue<T>;

constexpr array<int, 8> di({0, 1, -1, 0, 1, -1, 1, -1});
constexpr array<int, 8> dj({1, 0, 0, -1, 1, -1, -1, 1});
constexpr lli mod = 1e9 + 7;
// constexpr lli mod = 998244353;

namespace nim {
  // 山N個、それぞれXi個、取り除く石は1個ずつ
  //   Xiのxorが0かどうか
  // 山N個、それぞれXi個、取り除く石はAi個のどれか
  //   grundy(Xi)のxorが0かどうか ただしgrundy(Xi)は0<=Xi-Ajとなるgrundy(Xi-Aj)のMEX
  // 山N個、それぞれXi個、取り除く石はL個以上R個以下
  //   grundy(Xi)のxorが0かどうか ただしgrundy(Xi)はfloor((Xi%(L+R))/L)

  using grundy_num = function<lli(lli)>;
  // solve returns 先手必勝orNot
  bool solve(vec<lli> v, grundy_num gn) {
    lli x = 0;
    each (i, v) x ^= gn(i);
    return x != 0;
  }
  // 蟻本P281
  // int N, K, X[MAX_N], A[MAX_N];
  // int grundy[MAX_X + 1];
  // void solve() {
  //   grundy[0] = 0;
  //   int max_x = *max_element(X, X + N);
  //   for (int j = 1; j <= max_x; ++j) {
  //     set<int> s;
  //     for (int i = 0; i < K; ++i) {
  //       if (A[i] <= j) s.insert(grundy[j - A[j]]);
  //     }
  //     int g = 0;
  //     while (s.count(g)) ++g;
  //     grundy[j] = g;
  //   }
  // }
};

int main(int argc, char *argv[])
{
  int n, L, R;
  while (cin >> n >> L >> R) {
    vec<lli> a(n);
    cin >> a;
    nim::grundy_num fn = [&] (lli x) { return x % (L + R) / L; };
    cout << (nim::solve(a, fn) ? "First" : "Second")<< endl;
  }
  return 0;
}
