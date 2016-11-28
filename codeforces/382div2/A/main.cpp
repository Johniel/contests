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
  int n, k;
  while (scanf("%d %d\n", &n, &k) == 2) {
    char s[n];
    scanf("%s\n", s);
    int g = 0;
    int t = 0;
    for (int i = 0; i < n; ++i) {
      if (s[i] == 'G') g = i;
      if (s[i] == 'T') t = i;
    }
    queue<int> q;
    for (q.push(g); q.size(); q.pop()) {
      int a = q.front() - k;
      int b = q.front() + k;
      vector<int> v = {a, b};
      each (i, v) {
        if (0 <= i && i < n && s[i] != '#') {
          s[i] = '#';
          q.push(i);
        }
      }
    }
    puts(s[t] == 'T' ? "NO" : "YES");
  }
  return 0;
}
