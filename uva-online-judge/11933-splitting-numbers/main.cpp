#include<bits/stdc++.h>
using namespace std;

int num;

void solve()
{
	bitset<32> bin(num);
	int a = 0; // a & b can also be bitsets
	int b = 0;
	bool set_a = true;
	
	for (int i = 0; i < 32; i++)
	{
		if (bin.test(i))
		{
			if (set_a)
			{
				a = a | (1 << i);
			}
			else
			{
				b = b | (1 << i);
			}
			
			set_a = !set_a;
		}
	}
	
	cout << a << " " << b;
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

    cin >> num;

    while (num != 0)
    {
        solve();
        cout << "\n";
        
        cin >> num;
    }

    cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}
