// github.com/Johniel/contests
// atcoder/abc407/D/main.cpp

#include <bits/stdc++.h>

#define each(i, c) for (auto& i : c)
#define unless(cond) if (!(cond))
#define __builtin_popcount(x) __builtin_popcountll(x)

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

constexpr lli mod = 998244353; // 1e9 + 7;

int h, w;
const int H = 20;
const int W = 20;
int name[H][W];
const int HW = 20;
const int B = 1 << HW;
bool vis[B];
lli a[H][W];
bool gg[H][W];
lli mx = 0;

void rec(int b, lli z)
{
  if (vis[b]) return ;
  vis[b] = true;
  setmax(mx, z);
  for (int i = 0; i < h; ++i) {
    for (int j = 0; j < w; ++j) {
      if (gg[i][j]) continue;
      gg[i][j] = true;
      for (int d = 0; d < 2; ++d) {
        int di[] = {0, 1};
        int dj[] = {1, 0};
        int ni = i + di[d];
        int nj = j + dj[d];
        unless (0 <= ni && ni < h) continue;
        unless (0 <= nj && nj < w) continue;
        int nb = b | (1 << name[i][j]) | (1 << name[ni][nj]);
        if (vis[nb]) continue;
        if (gg[ni][nj]) continue;
        gg[ni][nj] = true;
        rec(nb, z ^ a[i][j] ^ a[ni][nj]);
        gg[ni][nj] = false;
      }
      gg[i][j] = false;
    }
  }
  return ;
}

int main(int argc, char *argv[])
{
  while (cin >> h >> w) {
    mx = 0;
    lli x = 0;
    for (int i = 0; i < h; ++i) {
      for (int j = 0; j < w; ++j) {
        cin >> a[i][j];
        x = (x ^ a[i][j]);
      }
    }
    {
      int cnt = 0;
      for (int i = 0; i < h; ++i) {
        for (int j = 0; j < w; ++j) {
          name[i][j] = cnt;
          ++cnt;
        }
      }
      assert(cnt <= 20);
    }
    fill(&gg[0][0], &gg[H - 1][W - 1] + 1, false);
    fill(vis, vis + B, false);
    rec(0, x);
    cout << mx << endl;
  }
  return 0;
}
