// github.com/Johniel/contests
// codeforces/920div3/F/main.cpp

#include <bits/stdc++.h>

#define each(i, c) for (auto& i : c)
#define unless(cond) if (!(cond))
#define makepair(a, b) make_pair(a, b)
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
// constexpr lli mod = 1e9 + 7;
constexpr lli mod = 998244353;

int main(int argc, char *argv[])
{
  { int _; cin >> _; }
  int n, q;
  while (cin >> n >> q) {
    vec<lli> a(n);
    cin >> a;
    const int B = 322;
    const int N = 1e5 + B + 3;
    static lli sum1[B][N];
    static lli sum2[B][N];
    static lli w[B][N];
    for (int i = 0; i < B; ++i) {
      for (int j = 0; j <= n + B; ++j) {
        sum1[i][j] = sum2[i][j] = w[i][j] = 0;
      }
    }
    for (int d = 0; d < B; ++d) {
      int k = 0;
      for (int i = 0; i < n; ++i) {
        w[d][i + d] = w[d][i] + 1;
        sum1[d][i + d] += sum1[d][i] + a[i];
        sum2[d][i + d] += sum2[d][i] + a[i] * w[d][i];
      }
    }
    // vec<lli> v;
    while (q--) {
      int s, d, k;
      cin >> s >> d >> k;
      --s;
      if (B <= d) {
        lli z = 0;
        for (int i = 0; i < k; ++i) z += a[s + i * d] * (i + 1);
        // v.push_back(z);
        cout << z << ' ';
      } else {
        int begin = s;
        int end = s + d * k;
        lli z = (sum2[d][end] - sum2[d][begin]) - (sum1[d][end] - sum1[d][begin]) * (w[d][begin] - 1);
        // v.push_back(z);
        cout << z << ' ';
      }
    }
    cout << endl;
    // each (i, v) cout << i << ' '; cout << endl;
  }
  return 0;
}