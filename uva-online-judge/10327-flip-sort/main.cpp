#include<bits/stdc++.h>
using namespace std;

typedef long long         ll;
typedef pair<int, int>    ii;
typedef vector<ii>        vii;
typedef vector<int>       vi;
#define INF 1000000000

int numbers[1000];
int n = 0;

void swapNumbers(int i0, int i1) {
	int tmp = numbers[i0];
	numbers[i0] = numbers[i1];
	numbers[i1] = tmp;
}

void solve()
{
  unsigned int min_ops = 0;
  for (int i = 0; i < n; i++) { cin >> numbers[i]; }
  
  bool sorted = false;
  while(!sorted) {
	sorted = true;
	
	for (int i = 0; i < n - 1; i++) {
	  if (numbers[i] > numbers[i+1]) {
		swapNumbers(i, i+1);
		min_ops++;
		sorted = false;
	  }
	}
  }
  
  cout << "Minimum exchange operations : " << min_ops;
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

  while (cin >> n)
  {
    solve();
    cout << "\n";
  }

  cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;
  return 0;
}
