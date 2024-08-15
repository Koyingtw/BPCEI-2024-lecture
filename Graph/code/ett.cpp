int n, timestamp = 1;
int intime[MAXN], outtime[MAXN];
vector<int> G[MAXN];
pair<int, int> ett[MAXN * 2];

void dfs(int i, int dep) {
	intime[i] = timestamp;
	ett[timestamp] = {i, dep};
	timestamp++;
	
	for (int e: G[i]) {
		dfs(e, dep + 1);
	}
	
	outtime[i] = timestamp;
	ett[timestamp] = {i, dep};
	timestamp++;
}