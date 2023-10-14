// github.com/Johniel/contests
// codeforces/e156/C/main.cpp

#include <bits/stdc++.h>

#define each(i, c) for (auto& i : c)
#define each_with_index(i, e, c) for (const auto i: views::iota(0, (int)c.size())) if (auto& e = c.at(i); true)
#define each_pair(p, c) for (const auto _i: views::iota(0, (int)c.size())) if (std::pair<const int, decltype((c.at(_i)))> p = {_i, c[_i]}; true)
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

int main(int argc, char *argv[])
{
  int _;
  cin >> _;

  str s;
  lli pos;
  while (cin >> s >> pos) {
    --pos;
    lli removed = 0;
    lli len = 0;
    while (true) {
      lli next = len + (int)s.size() - removed;
      if (pos < next) {
        break;
      } else {
        ++removed;
        len = next;
      }
    }

    // cout << make_pair(len, removed) << endl;

    set<int> alive;
    for (int i = 0; i < s.size(); ++i) alive.insert(i);

    priority_queue<pair<int, int>> q;
    for (int i = 0; i + 1 < s.size(); ++i) {
      int j = i + 1;
      if (s[i] > s[j]) q.push(make_pair(-i, -j));
    }

    while (removed--) {
      pair<int, int> p = make_pair(-1, -1);
      while (q.size()) {
        p = q.top();
        p.first = abs(p.first);
        p.second = abs(p.second);
        q.pop();
        if (alive.count(p.first) && alive.count(p.second)) break;
        p = make_pair(-1, -1);
      }
      if (p.first == -1) {
        auto itr = alive.rbegin();
        s[*itr] = '_';
        alive.erase(*itr);
      } else {
        s[p.first] = '_';
        auto itr1 = alive.find(p.first);
        if (itr1 != alive.begin()) {
          auto itr2 = itr1;
          --itr1;
          ++itr2;
          if (itr2 != alive.end()) {
            if (s[*itr1] > s[*itr2]) q.push(make_pair(*itr1, *itr2));
          }
        }
        alive.erase(p.first);
      }
    }
    int req = pos - len;
    // cout << req << endl;
    for (int i = 0; i < s.size(); ++i) {
      if (s[i] != '_') {
        if (req == 0) {
          cout << s[i];
          break;
        }
        --req;
      }
    }
    // cout << "," << s << endl;
  }
  cout << endl;
  return 0;
}
