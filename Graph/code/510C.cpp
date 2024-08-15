int n, m;
int in[30];
vector<int> G[30];
string s[MAXN];

void sol() {
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> s[i];
	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			for (int k = 0; k < s[i].size(); k++) {
				if (k >= s[j].size()) {
					cout << "Impossible" << endl;
					return;
				}
				
				if (s[i][k] != s[j][k]) {
					G[s[i][k] - 'a'].push_back(s[j][k] - 'a');
					in[s[j][k] - 'a']++;
					break;
				}
			}
		}
	}
	
	queue<int> q;
	string ans = "";
	
	for (int i = 0; i < 26; i++) {
		if (!in[i]) {
			q.push(i);
			in[i] = INF;
		}
	}
	
	while (q.size()) {
		int now = q.front();
		q.pop();
		
		ans += (char)('a' + now);
		
		
		for (int e: G[now]) {
			in[e]--;
			
			if (!in[e]) {
				q.push(e);
				in[e] = INF;
			}
		}
	}
	
	if (ans.size() == 26)
		cout << ans << endl;
	else
		cout << "Impossible" << endl;
}