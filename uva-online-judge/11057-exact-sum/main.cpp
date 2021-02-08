#include<bits/stdc++.h>
using namespace std;

typedef long long         ll;
typedef pair<int, int>    ii;
typedef vector<ii>        vii;
typedef vector<int>       vi;
#define INF 1000000000;

int N;

void solve()
{
  int books_prices[N];
  int* it;
  ii selected_books_prices;
  int better_ans = INF;
  int M, tmp;
  
  for (int i = 0; i < N; i++)
  {
    cin >> books_prices[i];
  }
  
  sort(books_prices, books_prices + N);
  
  cin >> M;
  
  for (int i = 0; i < N; i++)
  {
    it = lower_bound(books_prices + 1 + i, books_prices + N, M - books_prices[i]);
    
    if (it == books_prices + N)
    {
      continue;
    }
    
    tmp = *it;
    
    if (tmp + books_prices[i] == M && abs(tmp - books_prices[i]) < better_ans)
    {
      selected_books_prices = make_pair(books_prices[i], tmp);
      better_ans = abs(tmp - books_prices[i]);
    }
  }
  
  cout << "Peter should buy books whose prices are " <<
    selected_books_prices.first << " and " <<
    selected_books_prices.second << ".";
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

  while (cin >> N)
  {
    solve();
    cout << "\n\n";
  }

  cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;
  return 0;
}
