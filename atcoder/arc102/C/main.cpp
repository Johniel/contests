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

template<typename T>
ostream& operator << (ostream& os, vector<T> v)
{
  os << "(";
  each (i, v) os << i << ",";
  os << ")";
  return os;
}

int main(int argc, char *argv[])
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  lli n, k;
  while (cin >> n >> k) {
    const int N = 2 * 1e5 + 10;
    static lli cnt[N];
    fill(cnt, cnt + N, 0);

    for (int i = 1; i <= n; ++i) {
      ++cnt[i % k];
    }

    lli sum = 0;
    sum += cnt[0] * cnt[0] * cnt[0];
    if (k % 2 == 0) {
      sum += cnt[k / 2] * cnt[k / 2] * cnt[k / 2];
    }
    cout << sum << endl;
  }
  
  return 0;
}
