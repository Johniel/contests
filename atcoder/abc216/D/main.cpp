// atcoder/abc216/D/main.cpp
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
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.setf(ios_base::fixed);
  cout.precision(15);

  int n, m;
  while (cin >> n >> m) {
    const int N = 2 * 1e5 + 5;
    static queue<int> q[N];
    fill(q, q + N, queue<int>());
    static vec<int> v[N];
    fill(v, v + N, vec<int>());
    static int freq[N];
    fill(freq, freq + N, 0);
    for (int i = 0; i < m; ++i) {
      int k;
      cin >> k;
      for (int j = 0; j < k; ++j) {
        int x;
        cin >> x;
        q[i].push(x);
        v[x].push_back(i);
      }
    }
    priority_queue<pair<int, int>> p;
    for (int i = 0; i < N; ++i) {
      if (q[i].size()) {
        int x = q[i].front();
        ++freq[x];
        p.push(make_pair(freq[x], x));
      }
    }
    int cnt = 0;
    while (p.size()) {
      auto curr = p.top();
      p.pop();
      if (curr.first != 2) continue;
      int a = v[curr.second][0];
      int b = v[curr.second][1];
      q[a].pop();
      q[b].pop();
      if (q[a].size()) {
        int y = q[a].front();
        ++freq[y];
        p.push(make_pair(freq[y], y));
      }
      if (q[b].size()) {
        int z = q[b].front();
        ++freq[z];
        p.push(make_pair(freq[z], z));
      }
      ++cnt;
    }
    cout << (cnt == n ? "Yes" : "No") << endl;
  }

  return 0;
}
