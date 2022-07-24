// atcoder/abc242/G/main2.cpp
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
template<typename E, size_t N> istream& operator >> (istream& is, array<E, N>& a) { for (auto& i: a) is >> i; return is; }
template<typename E, size_t N> ostream& operator << (ostream& os, array<E, N>& a) { os << "[]{"; for (auto& i: a) os << i << ","; os << "}"; return os; }

template<typename T> inline T setmax(T& a, T b) { return a = std::max(a, b); }
template<typename T> inline T setmin(T& a, T b) { return a = std::min(a, b); }

using lli = long long int;
using ull = unsigned long long;
using str = string;
template<typename T> using vec = vector<T>;

constexpr array<int, 8> di({0, 1, -1, 0, 1, -1, 1, -1});
constexpr array<int, 8> dj({1, 0, 0, -1, 1, -1, -1, 1});
constexpr lli mod = 1e9 + 7;
// constexpr lli mod = 998244353;

namespace Mo {
  // ABC242G
  using Add = function<void(int)>;
  using Del = function<void(int)>;
  using Report = function<void(int)>;

  inline bool cmp(int N, const pair<int, int>& a, const pair<int, int>& b)
  {
    if (a.first / N != b.first / N) return a.first / N < b.first / N;
    // 左端の偶奇で昇順降順を分けると定数倍がましになるらしい？
    if ((a.first / N) % 2) {
      return a.second > b.second;
    } else {
      return a.second < b.second;
    }
  }

  // ある区間の解が分かっている状態で、その両端のどちらかを±1した区間の解がO(α)で求まるときに
  // 区間に対するクエリ列てに対してO(αQ√N)で答える。
  // ※クエリは半開区間。
  void run(
    const int N,
    vec<pair<int, int>> qs,
    Add add_left,
    Del del_left,
    Add add_right,
    Del del_right,
    Report report)
  {
    vec<int> idx(qs.size());
    iota(idx.begin(), idx.end(), 0);
    sort(idx.begin(), idx.end(), [&] (auto i, auto j) {
      int n = N / min<int>(N, sqrt(N));
      return cmp(n, qs[i], qs[j]);
    });
    int begin = 0;
    int end = 0;
    each (i, idx) {
      while (begin > qs[i].first) add_left(--begin);
      while (end < qs[i].second) add_right(end++);
      while (begin < qs[i].first) del_left(begin++);
      while (end > qs[i].second) del_right(--end);
      report(i);
    }
    return ;
  }
};

const int N = 1e5+1;
int cnt[N];
int z;
vec<int> a;
void add(int i)
{
  int x = a[i];
  z -= cnt[x] / 2;
  ++cnt[x];
  z += cnt[x] / 2;
  return ;
}

void del(int i)
{
  int x = a[i];
  z -= cnt[x] / 2;
  --cnt[x];
  z += cnt[x] / 2;
  return ;
}

int main(int argc, char *argv[])
{
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.setf(ios_base::fixed);
  cout.precision(15);

  int n;
  while (cin >> n) {
    // vec<int> a(n);
    a.resize(n);
    cin >> a;
    each (i, a) --i;

    int m;
    cin >> m;
    vec<pair<int, int>> v(m);
    cin >> v;
    each (i, v) --i.first;

    vec<int> u(m, -1);
    Mo::Report r = [&] (int i) {
      u[i] = z;
    };
    fill(cnt, cnt + N, 0);
    z = 0;
    Mo::run(n, v, add, del, add, del, r);
    each (i, u) cout << i << endl;
  }

  return 0;
}
