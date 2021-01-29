#include<bits/stdc++.h>
using namespace std;

typedef long long         ll;
typedef pair<int, int>    ii;
typedef vector<ii>        vii;
typedef vector<int>       vi;
#define INF 1000000000;

bitset<20> rw, ld, rd;
int new_row[8];
int row[8];
int min_movements = INF;
int movements, counter = 1;

bool can_place(int r, int c)
{
  return !rw[r] && !ld[r-c+7] && !rd[r+c];
}

void backtrack(int c)
{
  if (c == 8)
  {
    movements = 0;
    
    for (int r = 0; r < 8; r++)
    {
      if (row[r] != new_row[r])
      {
        movements++;
      }
    }
    min_movements = min(min_movements, movements);
  }
  else
  {
    for (int r = 0; r < 8; r++)
    {
      if (can_place(r, c))
      {
        rw[r] = ld[r-c+7] = rd[r+c] = true;
        new_row[c] = r;
        backtrack(c+1);
        rw[r] = ld[r-c+7] = rd[r+c] = false;
      }
    }
  }
}

void solve()
{
  min_movements = INF;
  backtrack(0);
  
  cout << "Case " << counter++ << ": " << min_movements;
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

  while (cin >> row[0])
  {
    row[0]--;
    for (int i = 1; i < 8; i++)
    {
      cin >> row[i];
      row[i]--;
    }
    
    solve();
    cout << "\n";
  }

  cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;
  return 0;
}
