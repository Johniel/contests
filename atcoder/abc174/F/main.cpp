// atcoder/abc174/F/main.cpp
// author: @___Johniel
// github: https://github.com/johniel/

#include <bits/stdc++.h>

#define each(i, c) for (auto& i : c)
#define unless(cond) if (!(cond))

using namespace std;

template<typename P, typename Q> ostream& operator << (ostream& os, pair<P, Q> p) { os << "(" << p.first << "," << p.second << ")"; return os; }
template<typename P, typename Q> istream& operator >> (istream& is, pair<P, Q>& p) { is >> p.first >> p.second; return is; }
template<typename T> ostream& operator << (ostream& os, vector<T> v) { os << "("; for (auto& i: v) os << i << ","; os << ")"; return os; }
template<typename T> istream& operator >> (istream& is, vector<T>& v) { for (auto& i: v) is >> i; return is; }
template<typename T> ostream& operator << (ostream& os, set<T> s) { os << "#{"; for (auto& i: s) os << i << ","; os << "}"; return os; }
template<typename K, typename V> ostream& operator << (ostream& os, map<K, V> m) { os << "{"; for (auto& i: m) os << i << ","; os << "}"; return os; }

template<typename T> inline T setmax(T& a, T b) { return a = std::max(a, b); }
template<typename T> inline T setmin(T& a, T b) { return a = std::min(a, b); }

using lli = long long int;
using ull = unsigned long long;
using point = complex<double>;
using str = string;
template<typename T> using vec = vector<T>;

constexpr array<int, 8> di({0, 1, -1, 0, 1, -1, 1, -1});
constexpr array<int, 8> dj({1, 0, 0, -1, 1, -1, -1, 1});
constexpr lli mod = 1e9 + 7;

constexpr int N = 5 * 1e5 + 5;
// https://ei1333.github.io/luzhiled/snippets/other/mo.html
namespace mo {
  static int cnt[N];
  static int ans[N];
  int ret;
    static int color[N];

  inline void add(int idx) { if(cnt[color[idx]]++ == 0) ret++; };
  inline void del(int idx) { if(cnt[color[idx]]-- == 1) --ret; };
  inline void rem(int idx) { ans[idx] = ret; };

  static int order[N];
  static int left[N], left_idx;
  static int right[N], right_idx;

  int width;
  vector< bool > v;
  int Q;


  void init(int N, int Q_) {
    ret = 0;
    fill(cnt, cnt + N, 0);
    fill(ans, ans + N, 0);
    left_idx = right_idx = 0;
    Q = Q_;
    v.resize(N);
    width = (int)sqrt(N);
    iota(begin(order), end(order), 0);
  }

  void add(int l, int r) { /* [l, r) */
    // left.emplace_back(l);
    // right.emplace_back(r);
    left[left_idx++] = l;
    right[right_idx++] = r;
  }

  void run(void) {
    // assert(left.size() == order.size());
    sort(order, order + Q, [&](int a, int b) {
      int ablock = left[a] / width, bblock = left[b] / width;
      if(ablock != bblock) return ablock < bblock;
      if(ablock & 1) return right[a] < right[b];
      return right[a] > right[b];
    });
    int nl = 0, nr = 0;
    auto push = [&](int idx) {
      v[idx].flip();
      if(v[idx]) add(idx);
      else del(idx);
    };
    for(auto idx : order) {
      while(nl > left[idx]) push(--nl);
      while(nr < right[idx]) push(nr++);
      while(nl < left[idx]) push(nl++);
      while(nr > right[idx]) push(--nr);
      rem(idx);
    }
  }
};

int main(int argc, char *argv[])
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.setf(ios_base::fixed);
  cout.precision(15);

  int n, q;
  // while (cin >> n >> q) {
  while (scanf("%d%d", &n, &q) == 2) {
    for (int i = 0; i < n; ++i) {
      int x;
      scanf("%d", &x);
      mo::color[i] = x;
    }
    static pair<int, int> u[N];
    for (int i = 0; i < q; ++i) {
      // cin >> u[i].first >> u[i].second;
      int a, b;
      scanf("%d%d", &a, &b);
      u[i] = make_pair(a, b);
      --u[i].first, --u[i].second;
    }

    // constexpr int Q = N;
    mo::init(N, q);
    for (int i = 0; i < q; ++i) {
      mo::add(u[i].first, u[i].second + 1);
    }

    mo::run();
    for(int i = 0; i < q; i++) {
      printf("%d\n", mo::ans[i]);
    }
  }

  return 0;
}
