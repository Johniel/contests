// atcoder/abc241/F/main.cpp
// author: @___Johniel
// github: https://github.com/johniel/

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
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.setf(ios_base::fixed);
  cout.precision(15);

  int h, w, n;
  pair<int, int> s, g;
  while (cin >> h >> w >> n >> s >> g) {
    vec<pair<int, int>> v(n);
    cin >> v;
    each (i, v) --i.first, --i.second;
    --s.first;
    --s.second;
    --g.first;
    --g.second;

    map<int, vec<int>> H, W;
    each (i, v) {
      H[i.first].push_back(i.second);
      W[i.second].push_back(i.first);
    }
    each (i, H) sort(i.second.begin(), i.second.end());
    each (i, W) sort(i.second.begin(), i.second.end());

    queue<pair<int, int>> q;
    map<pair<int, int>, lli> cost;
    cost[s] = 0;
    const pair<int, int> ng = {-1, -1};
    cost[ng] = (1 << 29);
    for (q.push(s); q.size(); q.pop()) {
      pair<int, int> curr = q.front();
      if (curr == g) break;
      // cout << curr << ' ' << "cost:=" << cost[curr] << endl;

      if (H.count(curr.first)) {
        { // →
          pair<int, int> next = ng;
          auto itr = lower_bound(H[curr.first].begin(), H[curr.first].end(), curr.second + 1);
          unless (itr == H[curr.first].end()) {
            next = make_pair(curr.first, *itr - 1);
          }
          if (!cost.count(next)) {
            cost[next] = cost[curr] + 1;
            q.push(next);
          }
        }
        { // ←
          pair<int, int> next = ng;
          auto itr = lower_bound(H[curr.first].begin(), H[curr.first].end(), curr.second);
          if (itr != H[curr.first].begin()) {
            --itr;
            next = make_pair(curr.first, *itr + 1);
          }
          if (!cost.count(next)) {
            cost[next] = cost[curr] + 1;
            q.push(next);
          }
        }
      }


      if (W.count(curr.second)) {
        { // ↓
          pair<int, int> next = ng;
          auto itr = lower_bound(W[curr.second].begin(), W[curr.second].end(), curr.first + 1);
          unless (itr == W[curr.second].end()) {
            next = make_pair(*itr - 1, curr.second);
          }
          if (!cost.count(next)) {
            cost[next] = cost[curr] + 1;
            q.push(next);
          }
        }
        { // ↑
          pair<int, int> next = ng;
          auto itr = lower_bound(W[curr.second].begin(), W[curr.second].end(), curr.first);
          unless (itr == W[curr.second].begin()) {
            --itr;
            next = make_pair(*itr + 1, curr.second);
          }
          if (!cost.count(next)) {
            cost[next] = cost[curr] + 1;
            q.push(next);
          }
        }
      }
    }
    if (!cost.count(g)) cout << -1 << endl;
    else cout << cost[g] << endl;
  }

  return 0;
}
