// github.com/Johniel/contests
// atcoder/abc254/G/main.cpp

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

namespace doubling {
  constexpr int N = 8 * 1e5 + 5;
  constexpr int DEPTH = 30;

  lli T[N][DEPTH];
  function<int(int)> fn;

  void build(const int size, function<int(int)> fn_)
  {
    fn = fn_;

    fill(&T[0][0], &T[N - 1][DEPTH], -(1 << 28));
    for (int i = 0; i < size; ++i) {
      T[i][0] = fn(i);
    }

    for (int i = 1; i < DEPTH; ++i) {
      for (int j = 0; j < size; ++j) {
        T[j][i] = T[T[j][i - 1]][i - 1];
      }
    }
    return ;
  }

  int query(int x, lli ntimes)
  {
    for (int i = DEPTH; 0 <= i; --i) {
      if (ntimes & (1LL << i)) {
        x = T[x][i];
      }
    }
    return x;
  }
}

bool intersection(pair<int, int> a, pair<int, int> b)
{
  unless (a.first < b.first) swap(a, b);
  return !(a.second < b.first);
}

int main(int argc, char *argv[])
{
  int n, m, q;
  while (cin >> n >> m >> q) {
    vec<pair<int, int>> v[n];
    for (int i = 0; i < m; ++i) {
      int a, b, c;
      cin >> a >> b >> c;
      --a;
      --b;
      --c;
      v[a].push_back(make_pair(min(b, c), max(b, c)));
    }
    vec<pair<pair<int, int>, pair<int, int>>> qs(q);
    cin >> qs;
    each (q, qs) {
      --q.first.first;
      --q.second.first;
      --q.first.second;
      --q.second.second;
    }
    for (int i = 0; i < n; ++i) {
      sort(v[i].begin(), v[i].end());
    }
    map<int, int> ord;
    {
      vec<int> u;
      for (int k = 0; k < n; ++k) {
        each (i, v[k]) {
          u.push_back(i.first);
          u.push_back(i.second);
        }
      }
      each (q, qs) {
        u.push_back(q.first.second);
        u.push_back(q.second.second);
      }
      u.push_back(0);
      sort(u.begin(), u.end());
      u.erase(unique(u.begin(), u.end()), u.end());
      for (int i = 0; i < u.size(); ++i) ord[u[i]] = i;
      for (int k = 0; k < n; ++k) {
        each (i, v[k]) {
          i.first = ord[i.first];
          i.second = ord[i.second];
        }
      }
      each (q, qs) {
        q.first.second = ord[q.first.second];
        q.second.second = ord[q.second.second];
      }
    }
    {
      for (int i = 0; i < n; ++i) {
        vec<pair<int, int>> u;
        each (j, v[i]) {
          if (u.size() && intersection(u.back(), j)) {
            setmax(u.back().second, j.second);
          } else {
            u.push_back(j);
          }
        }
        v[i] = u;
      }
    }

    assert(ord.size() < doubling::N);
    const int M = doubling::N + 2;
    static int mx[M];
    {
      iota(mx, mx + M, 0);
      for (int i = 0; i < n; ++i) {
        each (j, v[i]) setmax(mx[j.first], j.second);
      }
      for (int i = 1; i < M; ++i) {
        setmax(mx[i], mx[i - 1]);
      }
    }
    doubling::build(M, [&] (int i) { return mx[i]; });
    map<int, int> rev;
    each (i, ord) rev[i.second] = i.first;
    each (q, qs) {
      int x = q.first.first;
      int s = q.first.second;
      int y = q.second.first;
      int t = q.second.second;
      unless (s < t) {
        swap(x, y);
        swap(s, t);
      }
      const lli h = rev[t] - rev[s];
      if (v[x].size()) {
        auto itr = lower_bound(v[x].begin(), v[x].end(), make_pair(s + 1, 0));
        if (itr != v[x].begin()) {
          --itr;
          if (itr->first <= s && s <= itr->second) setmax(s, itr->second);
        }
      }
      if (v[y].size()) {
        auto itr = lower_bound(v[y].begin(), v[y].end(), make_pair(t + 1, 0));
        if (itr != v[y].begin()) {
          --itr;
          if (itr->first <= t && t <= itr->second) setmin(t, itr->first);
        }
      }
      unless (s < t) {
        cout << (x != y) + h << endl;
        continue;
      }
      int small = 0;
      int large = M;
      while (small + 1 < large) {
        int mid = (small + large) / 2;
        if (doubling::query(s, mid) < t) small = mid;
        else large = mid;
      }
      int z = -1;
      if (t <= doubling::query(s, large)) z = large;
      if (t <= doubling::query(s, small)) z = small;
      if (z == -1) cout << -1 << endl;
      else cout << z + h +1<< endl;
    }
  }
  return 0;
}
