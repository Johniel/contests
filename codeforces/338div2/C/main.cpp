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

const int N = 2100 + 10;

bool is_possible(string s, string t)
{
  set<char> C(s.begin(), s.end());
  each (c, t) if (C.count(c) == 0) return false;
  return true;
}

int main(int argc, char *argv[])
{
  char buff_s[N];
  char buff_t[N];
  while (scanf("%s\n%s\n", buff_s, buff_t) == 2) {
    string s(buff_s);
    string t(buff_t);
    if (!is_possible(s, t)) {
      puts("-1");
      continue;
    }
    string r = s;
    reverse(r.begin(), r.end());

    static int lcp1[N][N];
    fill(&lcp1[0][0], &lcp1[N - 1][N - 1] + 1, 0);
    static int lcp2[N][N];
    fill(&lcp2[0][0], &lcp2[N - 1][N - 1] + 1, 0);

    for (int t_idx = t.size() - 1; 0 <= t_idx; --t_idx) {
      for (int s_idx = s.size() - 1; 0 <= s_idx; --s_idx) {
        if (s[s_idx] == t[t_idx]) {
          lcp1[t_idx][s_idx] = lcp1[t_idx + 1][s_idx + 1] + 1;
        }
      }
      for (int r_idx = r.size() - 1; 0 <= r_idx; --r_idx) {
        if (r[r_idx] == t[t_idx]) {
          lcp2[t_idx][r_idx] = lcp2[t_idx + 1][r_idx + 1] + 1;
        }
      }        
    }
    
    vector<pair<int, int>> v;
    for (int idx = 0; idx < t.size(); ) {
      int* a = max_element(lcp1[idx], lcp1[idx] + N);
      int* b = max_element(lcp2[idx], lcp2[idx] + N);
      if (*a < *b) {
        int i = (b - lcp2[idx]);
        int j = i + *b - 1;
        v.push_back(make_pair(r.size() - i, r.size() - j));
      } else {
        int i = (a - lcp1[idx]) + 1;
        int j = i + *a - 1;
        v.push_back(make_pair(i, j));
      }
      idx += max(*a, *b);
    }

    printf("%d\n", v.size());
    each (p, v) printf("%d %d\n", p.first, p.second);
  }
  return 0;
}
