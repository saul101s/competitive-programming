#include<bits/stdc++.h>
using namespace std;

typedef long long 			ll;
typedef pair<int, int> 		ii;
typedef vector<ii> 			vii;
typedef vector<int> 		vi;
#define INF 1000000000;

int k;

void solve()
{
  int arr[k];
  
  for (int i = 0; i < k; i++)
  {
    cin >> arr[i];
  }
  
  for (int a = 0; a < k - 5; a++)
  {
    for (int b = a + 1; b < k - 4; b++)
    {
      for (int c = b + 1; c < k - 3; c++)
      {
        for (int d = c + 1; d < k - 2; d++)
        {
          for (int e = d + 1; e < k - 1; e++)
          {
            for (int f = e + 1; f < k; f++)
            {
              printf("%d %d %d %d %d %d\n", arr[a], arr[b],
                arr[c], arr[d], arr[e], arr[f]);
            }
          }
        }
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

  cin >> k;

  while (k != 0)
  {
    solve();
    
    cin >> k;
    
    if (k != 0)
    {
      printf("\n");
    }
  }

  cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;
  return 0;
}
