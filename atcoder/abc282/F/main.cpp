// github.com/Johniel/contests
// atcoder/abc282/F/main.cpp

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

int main(int argc, char *argv[])
{
  int n;
  while (cin >> n) {

    vec<pair<int, int>> v;
    int cnt = 0;
    const int N = 4000 + 2;
    static vec<int> X[N];
    static vec<int> Y[N];
    for (int i = 0; i < n; ++i) {
      lli x = 1;
      while (i + x <= n) {
        v.push_back(make_pair(i, i + x - 1));
        x *= 2;
      }
      lli y = 1;
      while (0 <= i - y) {
        v.push_back(make_pair(i - y + 1, i));
        y *= 2;
      }
    }
    sort(v.begin(), v.end());
    v.erase(unique(v.begin(), v.end()), v.end());

    cout << v.size() << endl;
    each (i, v) {
      cout << i.first+1 << ' ' << i.second+1 << endl;
    }
    map<pair<int, int>, int> name;
    for (int i = 0; i < v.size(); ++i) {
      name[v[i]] = i;
    }

    vec<int> x[N], y[N];
    each (i, v) {
      x[i.first].push_back(i.second);
      y[i.second].push_back(i.first);
    }

    // for (int i = 0; i < n; ++i) cout << x[i] << ' ' << y[i] << endl;

    int q;
    cin >> q;
    while (q--) {
      int a, b;
      cin >> a >> b;
      --a;
      --b;

      auto itr1 = lower_bound(x[a].begin(), x[a].end(), b+1);
      --itr1;
      auto itr2 = lower_bound(y[b].begin(), y[b].end(), a);

      pair<int, int> s = make_pair(a, *itr1);
      pair<int, int> t = make_pair(*itr2, b);
      cout << name[s]+1 << ' ' << name[t]+1 << endl;
    }
  }
  return 0;
}
