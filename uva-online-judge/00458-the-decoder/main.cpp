#include<bits/stdc++.h>
using namespace std;

typedef long long         ll;
typedef pair<int, int>    ii;
typedef vector<ii>        vii;
typedef vector<int>       vi;
#define INF 1000000000

void solve()
{
  string line;
  string ans = "";
  stringstream ss;
  char ch;
  
  while (getline(cin, line))
  {
    ss = stringstream(line);
    
    while (ss >> ch)
    {
      ans += ch - 7;
    }
    
    ans += '\n';
  }
  
  cout << ans;
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  #ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  freopen("my-output.txt", "w", stdout);
  freopen("error.txt", "w", stderr);
  #endif
  
  solve();
  
  cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;
  return 0;
}
