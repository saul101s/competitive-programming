#include<bits/stdc++.h>
using namespace std;

int N, n;

void solve()
{
	int N_cp = N, n_cp = n;
	char bs[N][N];
	char ss[n][n];
	int row = 0, rotations = 4, res = 0, upd_k = 0;
	bool match = true;
	string input;
	
	getline(cin, input);
	
	while (N_cp--)
	{
		getline(cin, input);
		
		for (int i = 0; i < (int)input.size(); i++)
		{
			bs[row][i] = input[i];
		}
		
		row++;
	}
	
	row = 0;
	
	while (n_cp--)
	{	
		getline(cin, input);
		
		for (int i = 0; i < (int)input.size(); i++)
		{
			ss[row][i] = input[i];
		}
		
		row++;
	}
	
	while (rotations--)
	{
		res = 0;
		
		for (int i = 0; i <= N - n; i++)
		{
			for (int j = 0; j <= N - n; j++)
			{
				match = true;
				
				for (int k = 0; k < n * n; k++)
				{
					upd_k = k;
					
					if (rotations == 2)
					{
						// 90º
						upd_k = (n * n) - n + (k / n) - (n * (k % n));
					}
					else if (rotations == 1)
					{
						// 180º
						upd_k = (n * n) - (k + 1);
					}
					else if (rotations == 0)
					{
						// 270º
						upd_k = (n - 1) - (k / n) + n * (k % n);
					}
					
					// cerr << k << " " << upd_k << endl;
					// cerr << "ss[" << upd_k / n << ", " << upd_k % n << "]" << endl;
					// cerr << "bs[" << i + k / n << ", " << j + k % n << "]" << endl << endl;
					
					if (ss[upd_k / n][upd_k % n] != bs[i + k / n][j + k % n])
					{
						match = false;
						break;
					}
				}
				
				if (match)
				{
					res++;
				}
			}
		}
		
		cout << res;
		
		if (rotations > 0)
		{
			cout << " ";
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

    cin >> N >> n;

    while (N && n)
    {
        solve();
        cout << "\n";
        
        cin >> N >> n;
    }

    cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}
