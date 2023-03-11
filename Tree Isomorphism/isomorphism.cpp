/*
Изоморфизм деревьев O(NlogN)
*/
int k;
map<vector<int>, int> id;
struct tree
{
    int n, root;
    vector<vector<int>> v;
    tree(int n, int root = 1)
    {
        this->n = n;
        this->root = root;
        v.resize(n + 1);
    }
    void add_edge(int x, int y)
    {
        v[x].pb(y);
        v[y].pb(x);
    }
    int get_id(int x = -1, int pr = -1)
    {
        if (x == -1)
            x = root;
        vector<int> a;
        for (int to : v[x])
        {
            if (to == pr)
                continue;
            int to_id = get_id(to, x);
            a.pb(to_id);
        }
        sort(a.begin(), a.end());
        if (!id.count(a))
            return id[a] = ++k;
        return id[a];
    }
};