№1
{
p = (int*) malloc(3*sizeof(int));
(*p) = a[0];
*(p+1) = a[1];
*(p+2) = a[2];
}
№2
{
unsigned int positive(int x)
{
 if (x < 0)
	return (-x);
else
	return x;
}
}
№3
{
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
int main()
{
    freopen("input.txt", "r+", stdin);
    freopen("output.txt", "w+", stdout);

    int n, i;
    scanf("%d", &n);
    long long a = 0, b = 0;
    for (i = 1; i <= n; i++)
    {
        a += i * i;
        b += i;
    }
    b *= b;
    int ans = b - a;
    printf("%d", ans);

    fclose(stdin);
    fclose(stdout);

    return 0;
}
}
№4
{
struct DateGoroh delta(struct DateGoroh d1, struct DateGoroh d2)
{
    long long day1 = (((d1.vek * 20) + d1.god) * 12 + d1.m) * 30 + d1.d;
    long long day2 = (((d2.vek * 20) + d2.god) * 12 + d2.m) * 30 + d2.d;
    long long d = day2 - day1;
    struct DateGoroh D;
    D.d = d % 30;
    d /= 30;
    D.m = d % 12;
    d /= 12;
    D.god = d % 20;
    d /= 20;
    D.vek = d;
    return D;
}
}
№5
{
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
int main()
{
    char c;
    while (scanf("%c", &c) != EOF)
    {
        printf("%c", c);
        if ((c == '.') ||
            (c == ',') ||
            (c == ':') ||
            (c == ';') ||
            (c == '!') ||
            (c == '?'))
            printf(" ");
    }

    return 0;
}
}
№6
{
#include <algorithm>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>
#include <math.h>
#include <iomanip>
#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <stack>
#define all(c) c.begin(), c.end()
#define MAXN 200
typedef unsigned long long ull;
typedef long double ld;
typedef double type;
using namespace std;
int n; // число вершин
vector< vector <int > > g; // граф
bool used[MAXN];
vector<int> ans;
void dfs (int v)
{
	used[v] = true;
	for (int i = 0; i < g[v].size(); ++i) {
		int to = g[v][i];
		if (! used[to])
			dfs(to);
	}
	ans.push_back(v);
}
void topological_sort()
{
	for (int i = 0; i < n; ++i)
		used[i] = false;
	ans.clear();
	for (int i = 0; i < n; ++i)
		if (! used[i])
			dfs(i);
	reverse(ans.begin(), ans.end());
}
int main()
{
    g.clear();
    cin >> n;
    g.resize(n);

    string s;
    getline(cin, s);

    for (int i = 0; i < n; i++)
    {
        getline(cin, s);
//        cout << "s - " << s << endl;
        for (int j = 0; j < i; j++)
        {
            if (s[j] == '+')
                g[i].push_back(j);
            if (s[j] == '-')
                g[j].push_back(i);
        }
    }
/*
    for (int i = 0; i < n; i++)
    {
        cout << i << " - ";
        for (int j = 0; j < g[i].size(); j++)
            cout << g[i][j] << " ";
        cout << endl;
    }
*/
    topological_sort();

//    cout << endl;
    for (int i = 0; i < ans.size(); i++)
        cout << ans[i] + 1 << " ";

    return 0;
}
}
№7
{
#include <algorithm>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>
#include <math.h>
#include <iomanip>
#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <stack>

#define all(c) c.begin(), c.end()
#define MAXN 200

typedef unsigned long long ull;
typedef long double ld;
typedef double type;

using namespace std;

struct box
{
    vector <int> p;
};

bool comparator (box b1, box b2)
{
    if (b1.p[0] > b2.p[0] &&
        b1.p[1] > b2.p[1])
        return true;
    return false;
}

bool inserts(box b, int &x, int &y)
{
    if (x < y)
        swap(x, y);
    if (x > b.p[0] && y > b.p[1])
    {
        x = b.p[0];
        y = b.p[1];
        return true;
    }
    if (x > b.p[1] && y > b.p[2])
    {
        x = b.p[1];
        y = b.p[2];
        return true;
    }
    return false;
}

int main()
{
    int n;
    cin >> n;
    vector <box> boxes (n);
    for (int i = 0; i < n; i++)
    {
        boxes[i].p.resize(3);
        cin >> boxes[i].p[0] >> boxes[i].p[1] >> boxes[i].p[2];
        sort(all(boxes[i].p));
        reverse(all(boxes[i].p));
    }

    sort(all(boxes), comparator);

/*
    cout << endl;
    for (int i = 0; i < n; i++)
        cout << boxes[i].p[0] << " " << boxes[i].p[1] << " " << boxes[i].p[2] << endl;
    cout << endl;
*/
    int ans = 1, x = boxes[0].p[0], y = boxes[0].p[1];
    for (int i = 1; i < n; i++)
    {
        if (!inserts(boxes[i], x, y))
            ans++;
    }

    cout << ans;

    return 0;
}
}
№8
{
#include <algorithm>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>
#include <math.h>
#include <iomanip>
#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <stack>

#define all(c) c.begin(), c.end()
#define MAXN 200

typedef unsigned long long ull;
typedef long double ld;
typedef double type;

using namespace std;

typedef int Data;

struct Node
{
    Data val;
    struct Node * next;
};

void print_lst(struct Node * head)
{
    while (head != NULL)
    {
        cout << (*head).val << " ";
        head = (*head).next;
    }
    return;
}

void add_to_head(struct Node ** list, Data x)
{
    struct Node * new_head = (struct Node *) malloc(sizeof(struct Node));
    (*new_head).next = (*list);
    (*list) = new_head;
    return;
}

Data find_min(struct Node ** list)
{
    struct Node * head = (*list);
    Data minn = (*head).val;
    while (head != NULL)
    {
        minn = min(minn, (*head).val);
        head = (*head).next;
    }
}

bool search(struct Node * head, Data x)
{
    while (head != NULL)
    {
        if ((*head).val == x)
            return true;
        head = (*head).next;
    }
    return false;
}

struct Node ** reverse_lst(struct Node ** list)
{
    struct Node ** new_head = list;
    struct Node * head = (*list);
    while (head != NULL)
    {
        add_to_head(new_head, (*head).val);
        head = (*head).next;
    }
    return new_head;
}

void add_to_sorted()
{

}

void list_sort(struct Node ** list)
{
    struct Node * head = *(list);

    if (list == NULL)
        return;


    struct Node * new_head = (struct Node *) malloc(sizeof(struct Node));
    (*new_head).val = find_min(list);



    list = reverse_lst(list);
}

int main()
{


    return 0;
}
}