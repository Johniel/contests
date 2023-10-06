// github.com/Johniel/contests
// atcoder/abc314/G/main.cpp

#include <bits/stdc++.h>

#define each(i, c) for (auto& i : c)
#define each_with_index(i, e, c) for (const auto i: views::iota(0, (int)c.size())) if (auto& e = c.at(i); true)
#define each_pair(p, c) for (const auto _i: views::iota(0, (int)c.size())) if (const auto p = make_pair(_i, c.at(_i)); true)
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
// constexpr lli mod = 1e9 + 7;
constexpr lli mod = 998244353;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;

template<typename T>
class ordered_set : public tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update> {};
// find_by_order(k),order_of_key(k)
template<typename T> ostream& operator << (ostream& os, ordered_set<T>& s) { os << "&{"; for (int i = 0; i < s.size(); ++i) { os << *s.find_by_order(i) << ","; } os << "}"; return os; }

int main(int argc, char *argv[])
{
  int n, m;
  lli h;
  while (cin >> n >> m >> h) {
    vec<pair<lli, int>> v(n);
    cin >> v;
    each (i, v) --i.second;

    vec<lli> sum(m, 0);
    ordered_set<pair<lli, int>> large, small;
    set<pair<lli, int>> smallside;
    lli curr_h = h;
    vec<int> w(v.size(), 0);
    for (int ei = 0, ai = 0; ei < v.size(); ++ei) {
      {
        pair<lli, int> p = make_pair(sum[v[ei].second], v[ei].second);
        if (smallside.contains(p)) curr_h += p.first;
        large.erase(p);
        small.erase(p);
        smallside.erase(p);
      }
      {
        sum[v[ei].second] += v[ei].first;
        pair<lli, int> p = make_pair(sum[v[ei].second], v[ei].second);
        small.insert(p);
        smallside.insert(p);
        curr_h -= p.first;
      }
      if (large.size()) {
        pair<lli, int> mn = *large.find_by_order(0);
        large.erase(mn);
        small.insert(mn);
        smallside.insert(mn);
        curr_h -= mn.first;
      }

      while (curr_h <= 0) {
        while (large.size() < ai && small.size()) {
          int size = small.size();
          pair<lli, int> mx = *small.find_by_order(size - 1);
          small.erase(mx);
          smallside.erase(mx);
          large.insert(mx);
          curr_h += mx.first;
        }
        if (0 < curr_h) {
          w[ei] = ai;
        } else if (large.size() == ai) {
          ++ai;
        }
      }
      if (0 < curr_h) w[ei] = ai;
      else if (ei) w[ei] = w[ei - 1];
      else w[ei] = 0;
      // cout << make_pair(ei, ai) << ' ' << curr_h << ' ' << large << ' ' << small << ' ' << (curr_h <= 0 && small.size()) << endl;
    }
    vec<int> u(m+1, 0);
    for (int i = 0; i < w.size(); ++i) {
      if (w[i] != -1) u[w[i]] = (i + 1);
    }
    while (u.size() && u.back() == 0) u.pop_back();
    while (u.size() < m + 1) u.push_back(n);
    each (i, u) cout << i << ' ' ; cout << endl;
    // cout << endl;
  }
  return 0;
}
