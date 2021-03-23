#include<bits/stdc++.h>
using namespace std;

typedef long long         ll;
typedef pair<int, int>    ii;
typedef vector<ii>        vii;
typedef vector<int>       vi;
#define INF 1000000000

char word[6], one[] = {'o', 'n', 'e'}, two[] = {'t', 'w', 'o'};

void solve()
{
  int length;
  bool one_error = false, two_error = false;
  
  cin >> word;
  length = strlen(word);
  
  if (length == 5) cout << 3;
  else
  {
    for (int i = 0; i < length; i++)
    {
      if (word[i] != one[i])
      {
        if (one_error)
        {
          cout << 2;
          break;
        }
        
        else one_error = true;
      }
      if (word[i] != two[i])
      {
        if (two_error)
        {
          cout << 1;
          break;
        }
        
        else two_error = true;
      }
    }
  }
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

  int t = 1;
  cin >> t;

  while (t--)
  {
    solve();
    cout << "\n";
  }

  cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;
  return 0;
}
