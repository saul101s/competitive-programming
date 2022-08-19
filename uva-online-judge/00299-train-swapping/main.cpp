#include<bits/stdc++.h>
using namespace std;

typedef long long         ll;
typedef pair<int, int>    ii;
typedef vector<ii>        vii;
typedef vector<int>       vi;
#define INF 1000000000

int carriages[51];

void solve()
{
  int length, optimal = 0, i = 0;
  memset(carriages, 0, sizeof(carriages));
  
  cin >> length;
  
  while (i < length)
  {
    cin >> carriages[i++];
    //cout << carriages[i-1] << endl;
  }
  
  for (int num = 1; num <= length; num++)
  {
    for (int i = num - 1; i < length; i++)
    {
      if (carriages[i] == num)
      {
        for (int j = i; j >= num; j--)
        {
          carriages[j] = carriages[j - 1];
          optimal++;
        }
        carriages[num - 1] = num;
      }
    }
  }
  
  cout << "Optimal train swapping takes " << optimal << " swaps.";
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
