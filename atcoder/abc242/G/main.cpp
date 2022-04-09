// atcoder/abc242/G/main.cpp
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
// constexpr lli mod = 998244353;

template<typename T>
struct Mo {
  // # [Mo's Algorithm](https://codeforces.com/blog/entry/7383)
  // + 列(長さN)の更新がない
  // + ある区間の解から両端のどちらかを±1別の区間への解がO(1)で求まる(もしくは充分小さい計算量で求まる)。
  // + クエリ(Q個)を先読み出来る。
  //
  // 列の長さをNとしたときに、左端(始点)を√Nの区間のどこに属するかでソートする。
  // もし同じ区間の場合は右端でソートする。O(QlogQ)
  //
  // 両端のポインタを移動させながら解を求めていくことを考える。
  // ## 左端
  // √N個の区間の中で行ったり来たりさせる。
  // １つの区間を端から端まで移動するコストはO(√N)で、クエリはQ個あるためO(Q√N)。
  // ## 右端
  // ひたすら増加する方向にだけ移動させる。
  // 左端の区間を固定(√N個)した際に、右端の移動回数はNなのでO(N√N)。

  int n;
  vector<T> v;
  vector<pair<int, int>> qs;
  vec<int> idx;

  void build(std::vector<T> _v, std::vector<std::pair<int, int>> _queries)
  {
    v = _v;
    qs = _queries;

    n = v.size() / min<int>(v.size(), sqrt(v.size()));
    idx.resize(qs.size());
    iota(idx.begin(), idx.end(), 0);
    sort(idx.begin(), idx.end(), [&] (auto i, auto j) { return cmp(qs[i], qs[j]); });
  }

  bool cmp(const pair<int, int>& a, const pair<int, int>& b)
  {
    if (a.first / n != b.first / n) return a.first / n < b.first / n;
    // 左端の偶奇で昇順降順を分けると定数倍がましになるらしい？
    if ((a.first / n) % 2) {
      return a.second > b.second;
    } else {
      return a.second < b.second;
    }
  }

  void run(void)
  {
    int z = 0;
    vec<int> cnt(1e5 + 1, 0); // MEMO: これをmapにするとTELしやすいかも。
    auto append = [&] (T x) {
      z -= cnt[x] / 2;
      ++cnt[x];
      z += cnt[x] / 2;
      return;
    };
    auto remove = [&] (T x) {
      z -= cnt[x] / 2;
      --cnt[x];
      z += cnt[x] / 2;
      return;
    };

    int begin = 0;
    int end = 0;

    vec<int> res(qs.size(), -1);
    each (i, idx) {
      while (begin > qs[i].first) append(v.at(--begin));
      while (end < qs[i].second) append(v.at(end++));
      while (begin < qs[i].first) remove(v.at(begin++));
      while (end > qs[i].second) remove(v.at(--end));
      res[i] = z;
    }
    each (i, res) cout << i << endl;
    return ;
  }
};

int main(int argc, char *argv[])
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.setf(ios_base::fixed);
  cout.precision(15);

  int n;
  while (cin >> n) {
    vec<int> a(n);
    cin >> a;
    each (i, a) --i;
    int m;
    cin >> m;
    vec<pair<int, int>> v(m);
    cin >> v;
    each (i, v) --i.first;
    Mo<int> mo;
    mo.build(a, v);
    mo.run();
  }

  return 0;
}
