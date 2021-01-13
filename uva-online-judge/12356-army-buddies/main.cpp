#include<bits/stdc++.h>
using namespace std;

int S, B; // Soldiers & Reports

void solve()
{
	int left[S + 2];
	int right[S + 2];
	int L, R;
	
	for (int i = 0; i < S + 2; i++)
	{
		left[i] = i - 1;
		right[i] = i + 1;
	}
	
	while (B--)
	{
		cin >> L >> R;
		
		left[right[R]] = left[L];
		right[left[L]] = right[R];
		
		string result = "";
		result += left[L] < 1 ? "*" : to_string(left[L]);
		result += " ";
		result += right[R] > S ? "*" : to_string(right[R]);
		
		cout << result << endl;
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

    cin >> S >> B;

    while (S && B)
    {
        solve();
        cout << "-\n";
        
        cin >> S >> B;
    }

    cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}
