// github.com/Johniel/contests
// atcoder/abc370/D/main.cpp

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

__attribute__((constructor)) static void _____(void) { ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.setf(ios_base::fixed); cout.precision(15); return ; }

using lli = long long int;
using ull = unsigned long long;
using str = string;
template<typename T> using vec = vector<T>;

// constexpr lli mod = 1e9 + 7;
constexpr lli mod = 998244353;

int main(int argc, char *argv[])
{
  int h, w, q;
  while (cin >> h >> w >> q) {
    set<int> a[h];
    set<int> b[w];

    for (int i = 0; i < h; ++i) {
      for (int j = 0; j < w; ++j) {
        a[i].insert(j);
      }
    }
    for (int j = 0; j < w; ++j) {
      for (int i = 0; i < h; ++i) {
        b[j].insert(i);
      }
    }


    bool vis[h][w];
    for (int i = 0; i < h; ++i) {
      for (int j = 0; j < w; ++j) {
        vis[i][j] = false;
      }
    }

    while (q--) {
      int i, j;
      cin >> i >> j;
      --i;
      --j;
      // cout << ">> " << make_pair(i, j) << endl;
      // cout << "a:" << endl;
      // for (int i = 0; i < h; ++i) cout << a[i] << endl;
      // cout << "b:" << endl;
      // for (int j = 0; j < w; ++j) cout << b[j] << endl;

      unless (vis[i][j]) {
        vis[i][j] = true;
        assert(a[i].count(j));
        assert(b[j].count(i));
        a[i].erase(j);
        b[j].erase(i);
        continue;
      }

      {
        auto itr = a[i].lower_bound(j);
        vec<int> v;
        if (itr != a[i].end()) v.push_back(*itr);
        if (itr != a[i].begin()) {
          --itr;
          v.push_back(*itr);
        }
        // cout << i << ' ' << v << endl;
        each (j, v) {
          assert(a[i].count(j));
          a[i].erase(j);
          b[j].erase(i);
          vis[i][j] = true;
        }
      }

      {
        auto itr = b[j].lower_bound(i);
        vec<int> v;
        if (itr != b[j].end()) v.push_back(*itr);
        if (itr != b[j].begin()) {
          --itr;
          v.push_back(*itr);
        }
        // cout << v << ' ' << j << endl;
        each (i, v) {
          assert(b[j].count(i));
          b[j].erase(i);
          a[i].erase(j);
          vis[i][j] = true;
        }
      }
    }

    // for (int i = 0; i < h; ++i) {
    //   for (int j = 0; j < w; ++j) {
    //     cout << vis[i][j] << ' ';
    //   }
    //   cout << endl;
    // }

    int z = 0;
    for (int i = 0; i < h; ++i) {
      for (int j = 0; j < w; ++j) {
        z += (vis[i][j] == false);
      }
    }
    cout << z << endl;
    // break;
  }
  return 0;
}