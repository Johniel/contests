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

  lli n, hp;
  while (cin >> n >> hp) {
    vector<pair<lli, lli>> v(n);
    for (int i = 0; i < n; ++i) {
      cin >> v[i];
    }
    sort(v.begin(), v.end());
    pair<lli, lli> p = v.back();
    v.pop_back();

    vector<lli> u;
    each (i, v) {
      if (p.first < i.second) u.push_back(i.second);
    }

    lli cnt = 0;
    sort(u.begin(), u.end());
    while (u.size() && u.back() <= hp) {
      if (hp <= p.second) {
        break;
      }
      hp -= u.back();
      u.pop_back();
      ++cnt;
    }
    if (hp <= 0) {
      cout << cnt << endl;
      continue;
    }

    lli x = u.size() ? max(p.second, u.back()) : p.second;
    if (hp <= x) {
      cout << cnt + 1 << endl;
      continue;
    }

    lli y = (hp - p.second) / p.first;
    cnt += y;
    hp -= y * p.first;
    for (lli i = 0; i < 100; ++i) {
      lli z = hp - (p.first * i) - p.second;
      if (z <= 0) {
        cnt += i + 1;
        break;
      }
    }
    cout << cnt << endl;
  }

  return 0;
}
