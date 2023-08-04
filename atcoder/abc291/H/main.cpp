// github.com/Johniel/contests
// atcoder/abc291/H/main.cpp

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

namespace tree_centroid_decomposition {
  const int N = 1e5 + 3;
  vector<int> g[N];
  vec<int> centroids;
  bool removed[N];
  int subtree_size[N];

  void init(void)
  {
    fill(removed, removed + N, false);
    fill(g, g + N, vector<int>());
    return ;
  }

  int count_substee_size(int curr, int prev)
  {
    int s = 1;
    for (int next: g[curr]) {
      if (next == prev || removed[next]) continue;
      s += count_substee_size(next, curr);
    }
    return subtree_size[curr] = s;
  }

  void search_centroids(int curr, int prev, const int size)
  {
    bool found = true;
    for (int next: g[curr]) {
      if (next == prev || removed[next]) continue;
      search_centroids(next, curr, size);
      if (subtree_size[next] > size / 2) found = false;
    }
    if (size - subtree_size[curr] > size / 2) found = false;
    if (found) centroids.push_back(curr);
    return ;
  }

  int run(int root = 0)
  {
    centroids.clear();
    count_substee_size(root, root);
    search_centroids(root, root, subtree_size[root]);
    assert(centroids.size() <= 2);
    return centroids.front();
  }

  // https://atcoder.jp/contests/abc291/tasks/abc291_h
  vector<int> rebuild(const int n)
  {
    fill(removed, removed + N, false);
    vector<int> parent(n, -1);
    queue<tuple<int, int, int>> q;
    for (q.push(make_tuple(0, n, -1)); q.size(); q.pop()) {
      auto [curr, size, prev] = q.front();
      int c = run(curr);
      parent[c] = prev;
      removed[c] = true;
      for (int next: g[c]) {
        if (removed[next]) continue;
        if (subtree_size[next] > subtree_size[c]) {
          q.push(make_tuple(next, size - subtree_size[c], c));
        } else {
          q.push(make_tuple(next, subtree_size[next], c));
        }
      }
    }
    return parent;
  }

};
using namespace tree_centroid_decomposition;


int main(int argc, char *argv[])
{
  int n;
  while (cin >> n) {
    init();
    for (int i = 0; i < n - 1; ++i) {
      int a, b;
      cin >> a >> b;
      --a;
      --b;
      g[a].push_back(b);
      g[b].push_back(a);
    }
    vec<int> p = rebuild(n);
    each (i, p) {
      if (i == -1) cout << -1 << ' ';
      else cout << i+1 << ' ';
    }
    cout << endl;
  }
  return 0;
}
