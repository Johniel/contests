// codeforces/ozon2020/B/main.cpp
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

int di[] = {0, 1, -1, 0, 1, -1, 1, -1};
int dj[] = {1, 0, 0, -1, 1, -1, -1, 1};
constexpr lli mod = 1e9 + 7;

struct PrefixSum {
  vector<long long int> sum;
  PrefixSum(vector<long long int> v) {
    sum.push_back(0);
    for (int i = 0; i < v.size(); ++i) {
      sum.push_back(sum.back() + v[i]);
    }
  }

  long long int query(size_t begin, size_t end) const {
    return sum[end] - sum[begin];
  }
  long long int operator () (size_t begin, size_t end) const {
    assert(begin <= end);
    return sum[end] - sum[begin];
  }
};

int main(int argc, char *argv[])
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  str s;
  while (cin >> s) {
    vector<vector<int>> v;

    while (true) {
      vector<lli> a;
      vector<lli> b;
      for (int i = 0; i < s.size(); ++i) {
        a.push_back(s[i] == '(');
      }
      for (int i = 0; i < s.size(); ++i) {
        b.push_back(s[i] == ')');
      }
      PrefixSum x(a);
      PrefixSum y(b);

      int idx = -1;
      int mx = 0;
      for (int i = 0; i < s.size(); ++i) {
        int mn = min<lli>(x(0, i), y(i, s.size()));
        if (mx < mn) {
          idx = i;
          mx = mn;
        }
      }

      if (idx == -1) break;
      vector<int> u;
      int cnt = mx;
      for (int i = 0; cnt && i < idx; ++i) {
        if (s[i] == '(') {
          s[i] = '@';
          u.push_back(i);
          --cnt;
        }
      }
      cnt = mx;
      for (int i = s.size() - 1; cnt && idx <= i; --i) {
        if (s[i] == ')') {
          s[i] = '@';
          u.push_back(i);
          --cnt;
        }
      }
      v.push_back(u);
    }

    cout << v.size() << endl;
    each (i, v) {
      sort(i.begin(), i.end());
      cout << i.size() << endl;
      each (j, i) cout << j + 1 << ' '; cout << endl;
    }
    // cout << endl;
  }

  return 0;
}
