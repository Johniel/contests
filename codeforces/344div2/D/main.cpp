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

int* buildFail(pair<lli, char> p[], const int m)
{
  int *fail = new int[m+1];
  int j = fail[0] = -1;
  for (int i = 1; i <= m; ++i) {
    while (j >= 0 && p[j] != p[i-1]) j = fail[j];
    fail[i] = ++j;
  }
  return fail;
}

pair<lli, char> H;
pair<lli, char> T;

lli match(pair<lli, char> t[], pair<lli, char> p[], const int n, const int m)
{
  int* fail = buildFail(p, m);
  lli count = 0;
  for (int i = 0, k = 0; i < n; ++i) {
    while (k >= 0 && p[k] != t[i]) k = fail[k];
    if (++k >= m) {
      // match at t[i-m+1 .. i]
      if (0 <= i-m+1-1 && i + 1 < n) {
        pair<lli, char> x = t[i-m+1-1];
        pair<lli, char> y = t[i + 1];
        count += (x.first >= H.first) * (x.second == H.second) * (y.first >= T.first) * (y.second == T.second);
      }
      k = fail[k];
    }
  }
  return count;
}

pair<lli, char> s[200000];
pair<lli, char> t[200000];

int main(int argc, char *argv[])
{
  int n, m;
  while (scanf("%d%d", &n, &m) == 2) {
    for (int i = 0; i < n; ++i) {
      lli l;
      char c;
      scanf("%lld-%c", &l, &c);
      if (i && s[i - 1].second == c) {
        --n;
        --i;
        s[i].first += l;
      } else {
        s[i] = make_pair(l, c);
      }
    }
    for (int i = 0; i < m; ++i) {
      lli l;
      char c;
      scanf("%lld-%c", &l, &c);
      if (i && t[i - 1].second == c) {
        --m;
        --i;
        t[i].first += l;
      } else {
        t[i] = make_pair(l, c);
      }
    }
    if (m == 1) {
      lli cnt = 0;
      for (int i = 0; i < n; ++i) {
        lli c = s[i].first - (t[0].first - 1);
        cnt += (s[i].first >= t[0].first) * (s[i].second == t[0].second) * c;
      }
      printf("%lld\n", cnt);
    } else if (m == 2) {
      lli cnt = 0;
      for (int i = 0; i + 1 < n; ++i) {
        cnt +=
          (s[i + 0].first >= t[0].first) * (s[i + 0].second == t[0].second) *
          (s[i + 1].first >= t[1].first) * (s[i + 1].second == t[1].second);
      }
      printf("%lld\n", cnt);
    } else {
      H = t[0];
      T = t[m - 1];
      printf("%lld\n", match(s, t + 1, n, m - 2));
    }
  }
  return 0;
}
