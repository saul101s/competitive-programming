#include<bits/stdc++.h>
using namespace std;

typedef long long         ll;
typedef pair<int, int>    ii;
typedef vector<ii>        vii;
typedef vector<int>       vi;
#define INF 1000000000

int N, Q, D, M;
int A[200];
long memo[205][15][45];

int c = 1, qr = 1;

int ways(int pos, int rem, int sum)
{
  if (rem == 0) return (sum == 0 ? 1 : 0);
  if (N - pos < rem) return 0; // rem greater than remaining elements in A
  if (memo[pos][rem][sum+20] != -1) return memo[pos][rem][sum+20];
  
  return memo[pos][rem][sum+20] = ways(pos+1, rem - 1, ((long)sum + A[pos]) % D) +
                                  ways(pos+1, rem, sum);
}

void solve()
{
  for (int i = 0; i < N; i++)
  {
    cin >> A[i];
  }
  
  cout << "SET " << c++ << ":\n";
  
  qr = 1;
  while (Q--)
  {
    cin >> D >> M;
    
    memset(memo, -1, sizeof memo);
    cout << "QUERY " << qr++ << ": " <<  ways(0, M, 0) << "\n";
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

  while (cin >> N >> Q && N && Q)
  {
    solve();
  }

  cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;
  return 0;
}
