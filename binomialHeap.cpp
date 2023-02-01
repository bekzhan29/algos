/*
Биномиальная пирамида
- объединить 2 пирамиды O(logN)
- найти минимум O(logN)
- добавить элемент O(logN)
- удалить минимум O(logN)
*/
ll head[N + 10], val[N + 10], sib[N + 10], son[N + 10], par[N + 10], cnt[N + 10], sz;
void print(ll head)
{
    while (head)
    {
        cout << "(" << val[head] << ", " << cnt[head] << ") - ";
        head = sib[head];
    }
    cout << endl;
}
ll uni(ll x, ll y)
{
    if (val[x] < val[y])
        swap(x, y);
    par[x] = y;
    sib[x] = son[y];
    son[y] = x;
    cnt[y]++;
    return y;
}
ll merge(ll x, ll y)
{
    ll head = 0, cur = 0, last = 0, next, go;
    if (!x || !y)
        return x ? x : y;
    if (cnt[x] < cnt[y])
        head = cur = x, x = sib[x];
    else
        head = cur = y, y = sib[y];
    while (x && y)
    {
        if (cnt[x] < cnt[y])
            sib[cur] = x, cur = x, x = sib[x];
        else
            sib[cur] = y, cur = y, y = sib[y];
    }
    while (x)
        sib[cur] = x, cur = x, x = sib[x];
    while (y)
        sib[cur] = y, cur = y, y = sib[y];
    cur = head;
    while (cur)
    {
        next = sib[cur];
        while (next && cnt[cur] == cnt[next] && (sib[next] == 0 || cnt[sib[next]] != cnt[next]))
        {
            go = sib[next];
            cur = uni(cur, next);
            if (last > 0)
                sib[last] = cur;
            else
                head = cur;
            sib[cur] = go;
            next = go;
        }
        last = cur;
        cur = sib[cur];
    }
    return head;
}
ll getMin(ll head)
{
    ll ans = val[head];
    while (head)
    {
        ans = min(ans, val[head]);
        head = sib[head];
    }
    return ans;
}
ll extractMin(ll &head)
{
    ll ans = val[head], cur = head, last = 0, pos = head, prev = 0;
    while (cur)
    {
        if (ans > val[cur])
            ans = val[cur], pos = cur, prev = last;
        last = cur;
        cur = sib[cur];
    }
    if (prev == 0)
        head = sib[head];
    else
        sib[prev] = sib[pos];
    cur = son[pos];
    ll nhead = 0, next;
    while (cur)
    {
        par[cur] = 0;
        next = sib[cur];
        sib[cur] = nhead;
        nhead = cur;
        cur = next;
    }
    head = merge(head, nhead);
    return ans;
}
void add(ll &head, ll x)
{
    sz++;
    sib[sz] = son[sz] = par[sz] = cnt[sz] = 0;
    val[sz] = x;
    head = merge(head, sz);
}
