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

const int N = 2 * 100000 + 5;
int rad[N * 2];

int longest_palindrome(const char *text, int n)
{
  int i, j, k;
  for (i = 0, j = 0; i < 2*n; i += k, j = max(j-k, 0)) {
    while (i-j >= 0 && i+j+1 < 2*n && text[(i-j)/2] == text[(i+j+1)/2]) ++j;
    rad[i] = j;
    for (k = 1; i-k >= 0 && rad[i]-k >= 0 && rad[i-k] != rad[i]-k; ++k)
      rad[i+k] = min(rad[i-k], rad[i]-k);
  }
  return *max_element(rad, rad+2*n); // ret. centre of the longest palindrome
}

int main(int argc, char *argv[])
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  string s;
  while (cin >> s) {
    map<char, lli> cnt;
    each (c, s) ++cnt[c];
    const lli n = s.size();
    lli sum = n * (n - 1) / 2 + 1;
    each (i, cnt) sum -= i.second * (i.second - 1) / 2;
    cout << sum << endl;
  }
  
  return 0;
}


// (length "abracadabra") ; 11
// (/ (* 11 (- 11 1)) 2) ; 55
