#include <bits/stdc++.h>

#define each(i, c) for (auto& i : c)
#define unless(cond) if (!(cond))

using namespace std;

typedef long long int lli;
typedef unsigned long long ull;
typedef complex<double> point;

template<typename P, typename Q>
ostream& operator << (ostream& os, pair<P, Q> p)
{
  os << "(" << p.first << "," << p.second << ")";
  return os;
}

int main(int argc, char *argv[])
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n;
  while (cin >> n) {
    vector<int> a(n);
    each (i, a) cin >> i;

    map<int, int> cnt;

    auto fn =
      [&] () {
        bool f = true;
        for (int i = 0; i < 32; ++i) {
          f = f && (cnt[i] <= 1);
        }
        return f;
      };

    auto include =
      [&] (int n) {
        for (int i = 0; i < 32; ++i) {
          if (n & (1 << i)) {
            ++cnt[i];
          }
        }
        return ;
      };

    auto exclude =
      [&] (int n) {
        for (int i = 0; i < 32; ++i) {
          if (n & (1 << i)) {
            --cnt[i];
          }
        }
        return ;
      };

    int begin = 0;
    int end = 0;

    lli sum = 0;
    while (begin <= end) {
      while (end < n && fn()) {
        include(a[end]);
        ++end;
        if (!fn()) {
          --end;
          exclude(a[end]);
          break;
        }
      }

      sum += (end - begin) * fn();

      exclude(a[begin]);
      ++begin;
    }

    cout << sum << endl;
  }

  return 0;
}
