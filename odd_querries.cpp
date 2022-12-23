#include <iostream>
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

#define ordered_set tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>

#define int long long int
vector<int> solve()
{
    int n, q;
    cin >> n >> q;
    vector<int> v(n + 1);
    vector<int> res;
    v[0] = 0;
    for (int i = 1; i <= n; i++)
        cin >> v[i];

    map<int, ordered_set> mp;
    for (int i = 1; i <= n; i++)
        mp[v[i]].insert(i);

    while (q--)
    {
        int mod, x, y;
        cin >> mod >> x >> y;
        if (mod == 1)
        {
            mp[v[x]].erase(x);
            mp[y].insert(x);
        }
        else
        {
            int ans = 0;
            for (auto &i : mp)
            {
                int a = i.second.order_of_key(y + 1);
                int b = i.second.order_of_key(x);
                int d = abs(a - b);
                if (d & 1)
                    ans++;
            }
            res.push_back(ans);
        }
    }
    return res;
}
int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    cin >> t;
    while (t--)
    {
        int sum = 0;
        vector<int> res = solve();
        for (auto &i : res)
            
        cout << i << " ";
        cout << endl;
    }

    return 0;
}