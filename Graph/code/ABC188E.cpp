const int INF = 0x3f3f3f3f3f3f3f3f;
#define MAXN 200005

int n, m;
int price[MAXN], in[MAXN];
int dp[MAXN];
vector<int> G[MAXN];

void sol() {
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		cin >> price[i];
	for (int i = 0, a, b; i < m; i++) {
		cin >> a >> b;
		G[a].push_back(b);
		in[b]++;
	}
	
	queue<int> q;
	
	for (int i = 1; i <= n; i++) {
		dp[i] = INF;
		if (!in[i]) {
			q.push(i);
			in[i] = INF;
		}
	}
	
	int ans = -INF;
		
	while (q.size()) {
		int now = q.front();
		q.pop();
		
        ans = max(ans, price[now] - dp[now]);
		dp[now] = min(dp[now], price[now]);
		
		for (int e: G[now]) {
			in[e]--;
			
			dp[e] = min(dp[e], dp[now]);
			
			if (!in[e]) {
				q.push(e);
				in[e] = INF;
			}
		}
	}
	cout << ans << endl;
}