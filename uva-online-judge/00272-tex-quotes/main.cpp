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
  string res = "";
  bool in_quotes = false;
  
  while (getline(cin, line))
  {
    for (int i = 0; i < (int)line.size(); i++)
    {
      if (line[i] == '"')
      {
        if (in_quotes)
        {
          res += "''";
        }
        else
        {
          res += "``";
        }
        
        in_quotes = !in_quotes;
      }
      else
      {
        res += line[i];
      }
    }
    
    res += "\n";
  }
  
  cout << res;
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
