// github.com/Johniel/contests
// atcoder/abc351/E/main.cpp

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

__attribute__((constructor)) static void _____(void) { ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.setf(ios_base::fixed); cout.precision(15); return ; }

using lli = long long int;
using ull = unsigned long long;
using str = string;
template<typename T> using vec = vector<T>;

// constexpr lli mod = 1e9 + 7;
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

int main(int argc, char *argv[])
{
  int n;
  while (cin >> n) {
    vec<pair<lli, lli>> v(n);
    cin >> v;

    vec<lli> d[2][2];
    for (int i = 0; i < v.size(); ++i) {
      int x = abs(v[i].first % 2);
      int y = abs(v[i].second % 2);
      auto j = manhattan_rot45(v[i]);
      d[x ^ y][0].push_back(j.first);
      d[x ^ y][1].push_back(j.second);
    }

    for (int k = 0; k < 2; ++k) {
      sort(d[k][0].begin(), d[k][0].end());
      sort(d[k][1].begin(), d[k][1].end());
    }

    {
      // これを効率よく計算したい。
      // lli z = 0;
      // for (int i = 0; i < n; ++i) {
      //   for (int j = i + 1; j < n; ++j) {
      //     z += a[j] - a[i];
      //   }
      // }
      // -a[i]の出現回数は(a.size()-i-1)回
      // +a[j]の出現回数はj*(j+1)/2
    }

    lli z = 0;
    for (int i = 0; i < 2; ++i) {
      for (int j = 0; j < 2; ++j) {
        auto& a = d[i][j];
        for (int k = 0; k < a.size(); ++k) {
          z -= a[k] * (a.size() - k - 1);
          z += a[k] * k;
        }
      }
    }
    cout << z/2 << endl;
  }
  return 0;
}
