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

#define UP 1
#define LEFT 2
#define SLANT 3

string LCS(string a, string b)
{
  int t[a.size()+1][b.size()+1];
  int move[a.size()+1][b.size()+1];
  fill(&move[0][0], &move[a.size()][b.size()+1], 0);
  fill(&t[0][0], &t[0][b.size()+1], 0);
  for(int i=1; i<a.size()+1; i++){
    t[i][0] = 0;
  }
 
  for(int i=1; i<a.size()+1; i++){
    for(int j=1; j<b.size()+1; j++){
      if(a[i-1] == b[j-1]){
        t[i][j] = t[i-1][j-1] + 1;
        move[i][j] = SLANT;
      }
      else if(t[i-1][j] >= t[i][j-1]){
        t[i][j] = t[i-1][j];
        move[i][j] = UP;
      }
      else if(t[i-1][j] < t[i][j-1]){
        t[i][j] = t[i][j-1];
        move[i][j] = LEFT;
      }
    }
  }
 
  string result;
  int i = a.size(), j = b.size();
  while(i != 0 && j != 0){
    if(move[i][j] == SLANT){
      result += a[i-1];
      i--;
      j--;
    }
    else if(move[i][j] == UP)
      i--;
    else if(move[i][j] == LEFT)
      j--;
  }
  reverse(result.begin(), result.end());
  return result;
}

int main(int argc, char *argv[])
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n;
  while (cin >> n) {
    vector<string> v(n);
    cin >> v;
    for (int i = 0; i < v.size(); ++i) {
      string s = v[i];
      sort(s.begin(), s.end());
      v[i] = s;
    }

    string s = v[0];
    for (int i = 1; i < v.size(); ++i) {
      s = LCS(s, v[i]);
    }
    cout << s << endl;
  }
  
  return 0;
}
