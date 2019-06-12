// codeforces/566div2/C/main.cpp
// author: @___Johniel
// github: https://github.com/johniel/

#include <bits/stdc++.h>

#define each(i, c) for (auto& i : c)
#define unless(cond) if (!(cond))

using namespace std;

typedef long long int lli;
typedef unsigned long long ull;
typedef complex<double> point;

template<typename P, typename Q> ostream& operator << (ostream& os, pair<P, Q> p) { os << "(" << p.first << "," << p.second << ")"; return os; }
template<typename P, typename Q> istream& operator >> (istream& is, pair<P, Q>& p) { is >> p.first >> p.second; return is; }
template<typename T> ostream& operator << (ostream& os, vector<T> v) { os << "("; each (i, v) os << i << ","; os << ")"; return os; }
template<typename T> istream& operator >> (istream& is, vector<T>& v) { each (i, v) is >> i; return is; }

template<typename T> inline T setmax(T& a, T b) { return a = std::max(a, b); }
template<typename T> inline T setmin(T& a, T b) { return a = std::min(a, b); }

int main(int argc, char *argv[])
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n;
  while (cin >> n) {
    vector<string> v(n);
    cin >> v;

    auto is_v = [&] (char c) { return string("aiueo").find(c) != string::npos; };
    auto fn = [&] (string s) {
      int cnt = 0;
      char last;
      each (c, s) {
        if (is_v(c)) {
          ++cnt;
          last = c;
        }
      }
      return make_pair(cnt, last);
    };

    map<int, char> last;
    map<int, int> cnt;
    for (int i = 0; i < v.size(); ++i) {
      pair<int, char> p = fn(v[i]);
      cnt[i] = p.first;
      last[i] = p.second;
    }

    vector<int> idx;
    for (int i = 0; i < n; ++i) {
      idx.push_back(i);
    }
    sort(idx.begin(), idx.end(), [&] (int i, int j) {
      return make_pair(last[i], cnt[i]) < make_pair(last[j], cnt[j]);
    });

    set<int> vis;
    vector<pair<int, int>> a; // first words
    vector<pair<int, int>> b; // second words
    while (1 < idx.size()) {
      const int i = idx[idx.size() - 1];
      const int j = idx[idx.size() - 2];
      if (cnt[i] == cnt[j] && last[i] == last[j]) {
        b.push_back({i, j});
        idx.pop_back();
        idx.pop_back();
        vis.insert(i);
        vis.insert(j);
      } else {
        idx.pop_back();
      }
    }

    idx.clear();
    for (int i = 0; i < n; ++i) {
      if (vis.count(i) == 0) idx.push_back(i);
    }
    sort(idx.begin(), idx.end(), [&] (int i, int j) {
      return cnt[i] < cnt[j];
    });
    while (1 < idx.size()) {
      const int i = idx[idx.size() - 1];
      const int j = idx[idx.size() - 2];
      if (cnt[i] == cnt[j]) {
        a.push_back({i, j});
        idx.pop_back();
        idx.pop_back();
        vis.insert(i);
        vis.insert(j);
      } else {
        idx.pop_back();
      }
    }

    // cout << a << endl;
    // cout << b << endl;

    vector<pair<pair<int, int>, pair<int, int>>> w;
    while (b.size()) {
      pair<int, int> p = b.back();
      b.pop_back();

      pair<int, int> q;
      if (a.size()) {
        q = a.back();
        a.pop_back();
      } else if (b.size()) {
        q = b.back();
        b.pop_back();
      } else {
        break;
      }

      w.push_back({q, p});
    }

    cout << w.size() << endl;
    each (i, w) {
      cout << v[i.first.first] << ' ' << v[i.second.first] << endl;
      cout << v[i.first.second] << ' ' << v[i.second.second] << endl;
    }
  }

  return 0;
}
