#include<bits/stdc++.h>
using namespace std;

typedef long long         ll;
typedef pair<int, int>    ii;
typedef vector<ii>        vii;
typedef vector<int>       vi;
#define INF 1000000000;

int N, res, counter = 1;
char board[15][15];
bitset<30> rw, ld, rd; // row and diagonals

bool can_place(int r, int c)
{
  return board[r][c] != '*' && !rw[r] && !ld[r-c+N-1] && !rd[r+c];
}

void backtrack(int c)
{
  if (c == N)
  {
    res++;
  }
  else
  {
    for (int r = 0; r < N; r++)
    {
      if (can_place(r, c))
      {
        rw[r] = ld[r-c+N-1] = rd[r+c] = true;
        backtrack(c + 1);
        rw[r] = ld[r-c+N-1] = rd[r+c] = false;
      }
    }
  }
}

void solve()
{
  res = 0;
  
  for (int i = 0; i < N; i++)
  {
    for (int j = 0; j < N; j++)
    {
      cin >> board[i][j];
    }
  }
  
  backtrack(0);
  cout << "Case " << counter++ << ": " << res;
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

  while (cin >> N && N)
  {
    solve();
    cout << "\n";
  }

  cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;
  return 0;
}
