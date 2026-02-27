// github.com/Johniel/contests
// atcoder/awc0015/E/main.cpp

#include <bits/stdc++.h>

#define each(i, c) for (auto& i : c)
#define unless(cond) if (!(cond))
#define __builtin_popcount(x) __builtin_popcountll(x)

using namespace std;

template<typename P, typename Q> ostream& operator << (ostream& os, pair<P, Q> p);
template<typename P, typename Q> istream& operator >> (istream& is, pair<P, Q>& p);
template<typename... Ts> ostream& operator << (ostream& os, const tuple<Ts...>& t) { os << "("; if constexpr (sizeof...(Ts) > 0) { apply([&](const Ts&... args) { ((os << args << ','), ...); }, t); } os << ")"; return os; }
template<typename... Ts> istream& operator >> (istream& is, tuple<Ts...>& t) { apply([&](Ts&... args) { ((is >> args), ...); }, t); return is; }
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

constexpr lli mod = 998244353; // 1e9 + 7;

namespace Mo {
  // ABC242G,ABC293G

  // MEMO: pair<int,int>にせずとも外に状態を持てるから注意すること。ただしmapへのアクセスは避ける。
  using Push = function<void(int)>;
  using Pop = function<void(int)>;
  using Report = function<void(int)>;

  inline bool cmp(int N, const pair<int, int>& a, const pair<int, int>& b)
  {
    if (a.first / N != b.first / N) return a.first / N < b.first / N;
    // 左端の偶奇で昇順降順を分けると定数倍がましになるらしい？
    if ((a.first / N) % 2) {
      return a.second > b.second;
    } else {
      return a.second < b.second;
    }
  }

  // ある区間の解が分かっている状態で、その両端のどちらかを±1した区間の解がO(α)で求まるときに
  // 区間に対するクエリ列てに対してO(αQ√N)で答える。
  // ※クエリは半開区間。
  void run(
    const int N,
    const vec<pair<int, int>>& qs,
    Push pushFront,
    Pop popFront,
    Push pushBack,
    Pop popBack,
    Report report)
  {
    vec<int> idx(qs.size());
    iota(idx.begin(), idx.end(), 0);
    const int n = N / min<int>(N, sqrt(N));
    sort(idx.begin(), idx.end(), [&] (auto i, auto j) {
      return cmp(n, qs[i], qs[j]);
    });
    int begin = 0;
    int end = 0;
    each (i, idx) {
      while (begin > qs[i].first) pushFront(--begin);
      while (end < qs[i].second) pushBack(end++);
      while (begin < qs[i].first) popFront(begin++);
      while (end > qs[i].second) popBack(--end);
      report(i);
    }
    return ;
  }
};

int main(int argc, char *argv[])
{
  int n, q;
  while (cin >> n >> q) {
    vec<int> p(n);
    cin >> p;
    vec<pair<int, int>> v(q);
    cin >> v;
    each (i, v) --i.first;

    const int N = 1e5 + 3;
    vec<int> vis(N, 0);
    vec<int> u(v.size(), -1);
    int z = 0;

    Mo::Push pushFront = [&] (int k) {
      ++vis[p[k]];
      z += (vis[p[k]] == 1);
    };
    Mo::Push pushBack  = [&] (int k) {
      ++vis[p[k]];
      z += (vis[p[k]] == 1);
    };
    Mo::Pop popFront = [&] (int k) {
      --vis[p[k]];
      z -= (vis[p[k]] == 0);
    };
    Mo::Pop popBack  = [&] (int k) {
      --vis[p[k]];
      z -= (vis[p[k]] == 0);
    };
    Mo::Report report = [&] (int k) { assert(u[k] == -1); u[k] = z; };
    Mo::run(n, v, pushFront, popFront, pushBack, popBack, report);
    each (k, u) cout <<k << endl;
  }
  return 0;
}
