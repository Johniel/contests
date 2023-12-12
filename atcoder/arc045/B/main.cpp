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
  int n, m;
  while (cin >> n >> m) {
    vector<pair<int, int>> v;
    for (int i = 0; i < m; ++i) {
      int a, b;
      cin >> a >> b;
      v.push_back(make_pair(a, b));
    }
    const int N = (300000 + 1) * 2;
    static int cnt[N];
    fill(cnt, cnt + N, 0);
    for (int i = 0; i < v.size(); ++i) {
      ++cnt[v[i].first * 2 - 1];
      --cnt[v[i].second * 2 + 1];
    }
    for (int i = 1; i < N; ++i) {
      cnt[i] += cnt[i - 1];
    }

    // for (int i = 1; i <= n*2; i += 2) {
    //   cout << cnt[i] << ' ' ;
    // }
    // cout << endl;

    const int M = (300000 + 1);
    static int end[M];
    end[M] = (cnt[(M) * 2] >= 2 ? M : -1);
    for (int i = M - 1; 0 <= i; --i) {
      if (cnt[i * 2] < 2) end[i] = -1;
      else {
        end[i] = max(end[i + 1], i);
      }
    }

    // for (int i = 0; i <= n; ++i) {
    //   cout << end[i] << ' ';
    // }
    // cout << endl;


    set<int> ok;
    for (int i = 0; i < v.size(); ++i) {
      if (v[i].second <= end[v[i].first]) ok.insert(i + 1);
    }
    cout << ok.size() << endl;
    each (i, ok) {
      cout << i << endl;
    }
  }
  return 0;
}
