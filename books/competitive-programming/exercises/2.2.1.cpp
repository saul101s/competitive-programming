#include<bits/stdc++.h>
using namespace std;

void print_array(vector<int> arr);

int main()
{
	// Initialize array randomly
	constexpr int ARRAY_LENGTH = 10;
	
    vector<int> v(ARRAY_LENGTH);
    
    default_random_engine generator;
    generator.seed(time(nullptr));
    uniform_int_distribution<int> distribution(0, ARRAY_LENGTH);
    
    for(auto it = v.begin(); it != v.end(); it++)
    {
		*it = distribution(generator);
	}
    
    // 1. Determine if v duplicated items
    sort(v.begin(), v.end());
    
    printf("Ordered Array: ");
    print_array(v);
	
	bool has_duplicated = false;
	
	for(auto it = v.begin(); it != v.end() - 1 && !has_duplicated; it++)
    {
		if (*it == *(it + 1))
		{
			has_duplicated = true;
		}
	}
	
	printf("Has duplicated elements: %s\n", has_duplicated ? "Yes" : "No");
	
	random_shuffle(v.begin(), v.end());
	printf("Shuffled Array: ");
	print_array(v);
	
	// 2. Find 2 elements in v, a and b so that s = a + b
	int a, b, s = 10;
	bool found = false;
	
	for (int i = 0; i < (int)v.size() && !found; i++)
	{
		for (int j = 0; j < (int)v.size() && !found; j++)
		{
			if ((j != i) && (v[i] + v[j] == s))
			{
				a = v[i];
				b = v[j];
				found = true;
			}
		}
	}
	
	if (found)
	{
		printf("%d + %d = %d\n", a, b, s);
	}
	
	// 3. Same as before with v being ordered
	sort(v.begin(), v.end());
	found = false;
	int i = 0, j = v.size() - 1;
	
	while (i < j && !found)
	{
		if (v[i] + v[j] > s)
		{
			j--;
		}
		else if (v[i] + v[j] < s)
		{
			i++;
		}
		else
		{
			a = v[i];
			b = v[j];
			found = true;
		}
	}
	
	if (found)
	{
		printf("%d + %d = %d\n", a, b, s);
	}
	
	random_shuffle(v.begin(), v.end());
	
	// 5. Size of the longest contiguous non-decreasing subarray
	int l = 0, max_l = 0;
	
	for (auto it = v.begin(); it != v.end() - 1; it++)
	{
		if (*it <= *(it + 1))
		{
			l++;
		}
		else
		{
			if (l > max_l)
			{
				max_l = l;
			}
		}
	}
	
	printf("Longest contiguous non-decreasing subarray size: %d\n", max_l);
	
	// 6. Determine the median of elements
	sort(v.begin(), v.end());
	
	int half = v.size() / 2;
	float median;
	
	if (v.size() % 2 == 0)
	{
		median = (v[half] + v[half - 1]) / 2.0;
	}
	else
	{
		median = v[half];
	}
	
	printf("Median of elements: %.2f\n", median);
	
}

void print_array(vector<int> arr)
{
	for (auto el : arr)
	{
		printf("%d ", el);
	}
	
	
	printf("\n");
}
