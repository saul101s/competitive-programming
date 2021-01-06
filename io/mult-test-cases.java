
FileReader fr = new FileReader("input.txt");

/*
 * Number of test cases appears at first line
 *
 *  INPUT           OUTPUT
 *    2               9
 *   4 5              10
 *   7 3              EOF
 *   EOF
*/

int TC, a, b;

TC = fr.nextInt(); // Number of cases

while (TC > 0) // Test cases remaining
{
    a = fr.nextInt();
    b = fr.nextInt();

    System.out.println(a * b);

    TC++;
}

/*
 * Test cases ends with an EOF (End Of File) signal
 *
 *  INPUT           OUTPUT
 *   4 5              9
 *   7 3              10
 *   EOF              EOF
*/

int a, b;

// scanf returns the number of elements
// We can also check EOF
while (scanf("%d %d", &a, &b) == 2)
{
    printf("%d\n", a + b);
}

/*
 * Output format -> Case [NUMBER]: [ANSWER]
 *
 *  INPUT           OUTPUT
 *   4 5            Case 1: 9
 *   7 3
 *   EOF            Case 2: 10
 *
 *                  EOF
*/

int a, b, c = 1;

while (scanf("%d %d", &a, &b) != EOF)
{
    printf("Case %d: %d\n\n", c++, a + b);
}


/*
 * Output format -> Case [NUMBER]: [ANSWER]
 *
 *  INPUT           OUTPUT
 *   4 5            Case 1: 9
 *   7 3
 *   EOF            Case 2: 10
 *                  EOF
*/

int a, b, c = 1;

while (scanf("%d %d", &a, &b) != EOF)
{
    if (c > 1)
    {
        printf("\n");
    }

    printf("Case %d: %d\n", c++, a + b);
}


/*
 * Variable number of inputs k
 *
 *  INPUT           OUTPUT
 *  1 1               1
 *  2 3 5             8
 *  3 6 4 8           18
 *  EOF               EOF
*/

int k, ans, v;

while (scanf("%d", &k) != EOF)
{
    while (k--)
    {
        scanf("%d", &v);
        ans += v;
    }

    printf("%d\n", ans);
}

/*
 * Variable number of inputs (unspecified)
 *
 *  INPUT           OUTPUT
 *  1 1               2
 *  2 3 5             10
 *  3 6 4 8           21
 *  EOF               EOF
*/

string line;

getline(cin, line);

while (!line.empty())
{
    stringstream ss(line);
    string s_num;
    int i_num, ans = 0;

    while (getline(ss, s_num, ' '))
    {
        inum = atoi(s_num.c_str());
        ans += i_num;
    }

    printf("%d\n", ans);

    getline(cin, line);
}
