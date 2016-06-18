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
  int n;
  while (scanf("%d", &n) == 1) {
    priority_queue<int, vector<int>, greater<int>> q;
    for (int i = 0; i < n; ++i) {
      int a;
      scanf("%d", &a);
      q.push(a);
    }
    int target = 1;
    while (true) {
      while (q.size() && q.top() < target) q.pop();
      if (q.empty()) break;
      ++target;
      q.pop();
    }
    printf("%d\n", target);
  }
  return 0;
}
