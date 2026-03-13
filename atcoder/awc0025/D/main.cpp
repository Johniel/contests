// github.com/Johniel/contests
// atcoder/awc0025/D/main.cpp

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

namespace doubling {
  constexpr int N = 2 * 1e5 + 5;
  constexpr int DEPTH = 63;

  int T[N][DEPTH];
  function<int(int)> fn;

  void build(const int size, function<int(int)> fn_)
  {
    fn = fn_;

    fill(&T[0][0], &T[N - 1][DEPTH], -1);
    for (int i = 0; i < size; ++i) {
      T[i][0] = fn(i);
    }

    for (int i = 1; i < DEPTH; ++i) {
      for (int j = 0; j < size; ++j) {
        T[j][i] = T[T[j][i - 1]][i - 1];
      }
    }

    return ;
  }

  int query(int x, lli ntimes)
  {
    for (int i = DEPTH; 0 <= i; --i) {
      if (ntimes & (1LL << i)) {
        x = T[x][i];
      }
    }
    return x;
  }
}

int main(int argc, char *argv[])
{
  int n, s;
  lli q;
  while (cin >> n >> s >> q) {
    vec<lli> x(n);
    cin >> x;
    vec<pair<lli, int>> y;
    for (int i = 0; i < x.size(); ++i) {
      y.push_back(make_pair(x[i], i));
    }
    sort(y.begin(), y.end());
    --s;
    vec<int> v(n, -(1 << 29));
    for (int i = 0; i < x.size(); ++i) {
      const lli inf = (1LL << 60);
      pair<lli, int> mn = make_pair(inf, -1);
      if (i + 1 < v.size()) {
        int j = i + 1;
        setmin(mn, make_pair(abs(y[i].first - y[j].first), y[j].second));
      }
      if (0 <= i - 1) {
        int j = i - 1;
        setmin(mn, make_pair(abs(y[i].first - y[j].first), y[j].second));
      }
      v[y[i].second] = mn.second;
    }
    auto fn = [&] (int i) { return v[i]; };
    doubling::build(n, fn);
    cout << doubling::query(s, q) + 1 << endl;
  }
  return 0;
}
