#include<bits/stdc++.h>
using namespace std;

typedef long long         ll;
typedef pair<int, int>    ii;
typedef vector<ii>        vii;
typedef vector<int>       vi;
#define INF 1000000000

int B, N;
int bank_balance[21];

void solve()
{
  int debtor, creditor, value;
  
  for (int i = 1; i <= B; i++)
  {
    cin >> bank_balance[i];
  }
  
  while (N--)
  {
    cin >> debtor >> creditor >> value;
    
    bank_balance[creditor] += value;
    bank_balance[debtor] -= value;
  }
  
  
  bool can = true;
  
  for (int i = 1; i <= B && can; i++)
  {
    if (bank_balance[i] < 0) can = false;
  }
  
  cout << (can ? "S" : "N");
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

  cin >> B >> N;

  while (B != 0 || N != 0)
  {
    solve();
    cout << "\n";
    
    cin >> B >> N;
  }

  cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;
  return 0;
}
