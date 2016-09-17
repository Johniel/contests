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
  const int M = 50000 + 10;
  char s[M];
  while (scanf("%s", s) == 1) {
    const int N = strlen(s);
    map<char, int> cnt;

    auto fn = [&] () {
      int sum = 0;
      for (char c = 'A'; c <= 'Z'; ++c) {
        if (cnt[c] >= 2) return false;
        sum += cnt[c];
      }
      // cout << sum << ' ' << cnt['?']  << endl;
      return sum + cnt['?'] == 26;
    };
    
    bool f = false;
    int i = 0;
    int j = 0;
    for (; i < N; ++i) {
      ++cnt[s[i]];
      if (j + 25 == i) {
        // cout << make_pair(j, i) << endl;
        // each (p, cnt) cout << p << endl;
        if (fn()) { f = true; break; }
        --cnt[s[j]];
        ++j;
      }
    }

    if (f) {
      set<char> x;
      for (char c = 'A'; c <= 'Z'; ++c) x.insert(c);
      for (int k = j; k <= i; ++k) {
        x.erase(s[k]);
      }
      vector<char> v(x.begin(), x.end());
      for (int k = 0; k < N; ++k) {
        if (s[k] == '?') {
          if (j <= k && k <= i) {
            s[k] = v.back();
            v.pop_back();
          } else {
            s[k] = 'A';
          }
        }
      }
      puts(s);
    }
    else puts("-1");
  }
  return 0;
}
