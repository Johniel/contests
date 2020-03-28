// atcoder/abc160/D/main.cpp
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

int main(int argc, char *argv[])
{
  std::ios_base::sync_with_stdio(0);
  std::cin.tie(0);
  std::cout.setf(std::ios_base::fixed);
  std::cout.precision(15);

  lli n, x, y;
  while (cin >> n >> x >> y) {
    --x;
    --y;

    auto bfs = [&] (int src, vec<int>& cost){
      cost[src] = 0;
      queue<int> q;
      for (q.push(src); q.size(); q.pop()) {
        int curr = q.front();
        vec<int> v;
        v.push_back(curr - 1);
        v.push_back(curr + 1);
        if (curr == x) v.push_back(y);
        if (curr == y) v.push_back(x);
        each (next, v) {
          if (0 <= next && next < n && cost[next] == -1) {
            cost[next] = cost[curr] + 1;
            q.push(next);
          }
        }
      }
      return ;
    };

    vec<int> v(n, 0);

    for (int i = 0; i < n; ++i) {
      vec<int> c(n, -1);
      bfs(i, c);
      each (j, c) {
        ++v[j];
      }
    }
    for (int i = 1; i < v.size(); ++i) {
      cout << v[i] / 2 << endl;
    }
    // cout << endl;
  }

  return 0;
}
