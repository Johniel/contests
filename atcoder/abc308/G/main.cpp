// github.com/Johniel/contests
// atcoder/abc308/G/main.cpp

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

constexpr array<int, 8> di({0, 1, -1, 0, 1, -1, 1, -1});
constexpr array<int, 8> dj({1, 0, 0, -1, 1, -1, -1, 1});
constexpr lli mod = 1e9 + 7;
// constexpr lli mod = 998244353;

int main(int argc, char *argv[])
{
  int r;
  while (cin >> r) {
    map<lli, vec<int>> idx;
    set<int> live;
    set<pair<lli, int>> vis;
    priority_queue<pair<lli, pair<int, int>>> q;
    for (int i = 0; i < r; ++i) {
      int op;
      cin >> op;
      if (op == 1) {
        lli x;
        cin >> x;
        idx[x].push_back(i);
        live.insert(i);
        vis.insert(make_pair(x, i));
        {
          auto itr = vis.find(make_pair(x, i));
          if (itr != vis.begin()) {
            --itr;
            lli v = itr->first ^ x;
            q.push(make_pair(-v, make_pair(itr->second, i)));
          }
        }
        {
          auto itr = vis.find(make_pair(x, i));
          ++itr;
          if (itr != vis.end()) {
            lli v = itr->first ^ x;
            q.push(make_pair(-v, make_pair(itr->second, i)));
          }
        }
      }
      if (op == 2) {
        lli x;
        cin >> x;
        int j = idx[x].back();
        idx[x].pop_back();
        live.erase(j);
        auto itr1 = vis.find(make_pair(x, j));
        auto itr2 = vis.find(make_pair(x, j));
        if (itr1 != vis.begin()) {
          --itr1;
          ++itr2;
          if (itr2 != vis.end()) {
            lli v = itr1->first ^ itr2->first;
            q.push(make_pair(-v, make_pair(itr1->second, itr2->second)));
          }
        }
        vis.erase(make_pair(x, j));
      }
      if (op == 3) {
        while (true) {
          pair<lli, pair<int, int>> p = q.top();
          int a = p.second.first;
          int b = p.second.second;
          if (live.count(a) && live.count(b)) break;
          q.pop();
        }
        assert(q.size());
        cout << abs(q.top().first) << endl;
      }
    }
  }
  return 0;
}
