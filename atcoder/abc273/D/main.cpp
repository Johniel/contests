// github.com/Johniel/contests
// atcoder/abc273/D/main.cpp

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
template<typename E, size_t N> ostream& operator << (ostream& os, array<E, N>& a) { os << "[]{"; for (auto& i: a) os << i << ","; os << "}"; return os; }

template<typename T> inline T setmax(T& a, T b) { return a = std::max(a, b); }
template<typename T> inline T setmin(T& a, T b) { return a = std::min(a, b); }

__attribute__((constructor)) static void ___initio(void) { ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.setf(ios_base::fixed); cout.precision(15); return ; }

using lli = long long int;
using ull = unsigned long long;
using str = string;
template<typename T> using vec = vector<T>;

constexpr array<int, 8> di({0, 1, -1, 0, 1, -1, 1, -1});
constexpr array<int, 8> dj({1, 0, 0, -1, 1, -1, -1, 1});
constexpr lli mod = 1e9 + 7;
// constexpr lli mod = 998244353;

int main(int argc, char *argv[])
{

  int h, w;
  pair<int, int> src;
  int n;
  while (cin >> h >> w >> src >> n) {
    --src.first;
    --src.second;
    map<int, vec<int>> hh, ww;
    for (int _ = 0; _ < n; ++_) {
      int i, j;
      cin >> i >> j;
      --i;
      --j;
      hh[i].push_back(j);
      ww[j].push_back(i);
    }
    each (i, hh) {
      sort(i.second.begin(), i.second.end());
      i.second.erase(unique(i.second.begin(), i.second.end()), i.second.end());
    }
    each (i, ww) {
      sort(i.second.begin(), i.second.end());
      i.second.erase(unique(i.second.begin(), i.second.end()), i.second.end());
    }
    int q;
    cin >> q;
    int i = src.first;
    int j = src.second;
    while (q--) {
      char dir;
      int len;
      cin >> dir >> len;

      // cout << str(10, '>') << dir << ' ' << len << endl;

      if (dir == 'U') {
        unless (ww.count(j)) {
          i = max(0, i - len);
        } else {
          auto itr = lower_bound(ww[j].begin(), ww[j].end(), i);
          if (itr != ww[j].begin()) {
            --itr;
            i = max(*itr + 1, i - len);
          } else {
            i = max(0, i - len);
          }
        }
      }

      if (dir == 'L') {
        unless (hh.count(i)) {
          j = max(0, j - len);
        } else {
          auto itr = lower_bound(hh[i].begin(), hh[i].end(), j);
          if (itr != hh[i].begin()) {
            --itr;
            j = max(*itr + 1, j - len);
          } else {
            j = max(0, j - len);
          }
        }
      }

      if (dir == 'D') {
        unless (ww.count(j)) {
          i = min(h - 1, i + len);
        } else {
          auto itr = lower_bound(ww[j].begin(), ww[j].end(), i + 1);
          if (itr != ww[j].end()) {
            i = min(*itr - 1, i + len);
          } else {
            i = min(h - 1, i + len);
          }
        }
      }

      if (dir == 'R') {
        unless (hh.count(i)) {
          j = min(w - 1, j + len);
        } else {
          auto itr = lower_bound(hh[i].begin(), hh[i].end(), j + 1);
          if (itr != hh[i].end()) {
            j = min(*itr - 1, j + len);
          } else {
            j = min(w - 1, j + len);
          }
        }
      }


      cout << i + 1 << ' ' << j + 1 << endl;
    }
  }

  return 0;
}
