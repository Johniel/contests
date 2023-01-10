// github.com/Johniel/contests
// codeforces/843div2/D/main.cpp

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
template<typename T> using heap = priority_queue<T>;

constexpr array<int, 8> di({0, 1, -1, 0, 1, -1, 1, -1});
constexpr array<int, 8> dj({1, 0, 0, -1, 1, -1, -1, 1});
constexpr lli mod = 1e9 + 7;
// constexpr lli mod = 998244353;

const int M = 3 * 1e5 + 3;
const int N = M * 2;
vec<int> g[N];

int main(int argc, char *argv[])
{
  int n;
  while (cin >> n) {
    int src, dst;
    vec<int> a(n);
    cin >> a >> src >> dst;

    if (src == dst) {
      cout << 1 << endl;
      cout << src << endl;
      continue;
    }

    src = src - 1 + M;
    dst = dst - 1 + M;
    static int id[N];
    fill(id, id + N, -1);
    for (int i = 0; i < a.size(); ++i) {
      id[a[i]] = i;
    }

    fill(g, g + N, vec<int>());
    for (int i = 0; i < a.size(); ++i) {
      for (lli j = 1; j * j <= a[i]; ++j) {
        if (a[i] % j == 0) {
          int k = a[i] / j;
          g[M + i].push_back(j);
          g[j].push_back(i + M);
          if (k != j) {
            g[M + i].push_back(k);
            g[k].push_back(i + M);
          }
        }
      }
    }
    g[1].clear();

    static int path[N];
    fill(path, path + N, -1);
    path[src] = src;
    queue<int> q;
    for (q.push(src); q.size(); q.pop()) {
      int curr = q.front();
      each (next, g[curr]) {
        if (path[next] == -1) {
          path[next] = curr;
          q.push(next);
        }
      }
    }
    if (path[dst] == -1) {
      cout << -1 << endl;
    } else {
      vec<int> v;
      for (int i = dst; i != path[i]; i = path[i]) {
        if (M <= i) v.push_back(i - M);
      }
      v.push_back(src - M);
      reverse(v.begin(), v.end());
      cout << v.size() << endl;
      each (i, v) cout << i+1 << ' ';
      cout << endl;
    }
  }
  return 0;
}
