// atcoder/arc027/B/main.cpp
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

class UnionFind {
public:
  UnionFind(int n) {
    r.resize(n, 0);
    p.resize(n, -1);
  }
  void unite(int a, int b) {
    a = find(a);
    b = find(b);
    if (a == b) return ;
    if (r[a] > r[b]) {
      p[a] += p[b];
      p[b] = a;
    } else {
      p[b] += p[a];
      p[a] = b;
      if(r[a] == r[b]) r[b]++;
    }
    return ;
  }
  int find(int a) {
    return (p[a] < 0) ? a : p[a] = find(p[a]);
  }
  bool same(int a, int b) {
    return find(a) == find(b);
  }
  size_t size(int n) {
    return -p[find(n)];
  }
private:
  vector<int> r, p;
};

int main(int argc, char *argv[])
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.setf(ios_base::fixed);
  cout.precision(15);

  int n;
  str a, b;
  while (cin >> n >> a >> b) {
    map<char, int> idx;
    for (char c = '0'; c <= '9'; ++c) {
      idx[c] = idx.size();
    }
    for (char c = 'A'; c <= 'Z'; ++c) {
      idx[c] = idx.size();
    }

    const int N = idx.size();
    UnionFind uf(N);
    for (char c = '0'; c <= '9'; ++c) {
      int p = idx[c];
      int q = idx[c];
      uf.unite(p, q);
    }

    for (int i = 0; i < a.size(); ++i) {
      int p = idx[a[i]];
      int q = idx[b[i]];
      uf.unite(p, q);
    }

    str s = a;
    for (int i = 0; i < s.size(); ++i) {
      for (int j = i + 1; j < s.size(); ++j) {
        unless ('A' <= s[i] && s[i] <= 'Z') continue;
        unless ('A' <= s[j] && s[j] <= 'Z') continue;
        int p = idx[s[i]];
        int q = idx[s[j]];
        if (uf.same(p, q)) {
          s[j] = s[i];
        }
      }
    }

    for (int i = 0; i < s.size(); ++i) {
      for (char c = '0'; c <= '9'; ++c) {
        int p = idx[s[i]];
        int q = idx[c];
        if (uf.same(p, q)) {
          s[i] = c;
        }
      }
    }

    set<char> vis;
    ull x = 1;
    for (int i = 0; i < s.size(); ++i) {
      if (vis.count(s[i])) continue;
      vis.insert(s[i]);
      unless ('A' <= s[i] && s[i] <= 'Z') continue;
      if (i) x *= 10;
      else x *= 9;
    }
    cout << x << endl;
  }

  return 0;
}
