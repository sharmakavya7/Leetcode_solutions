#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <cstdlib> 
#include <string>
#include <map>
#include <climits>
#include <iterator>
#include <set>
#include <unordered_set>
#include <unordered_map>
#include <utility>
#include <deque>
#include <queue>
#include <stack>
using namespace std;

const int N = 1e5 + 2 ;
int parent[N];

int find_set(int v) {
	if (parent[v] < 0)
		return v;
	return parent[v] = find_set(parent[v]);
}

void join(int a, int b) {
	int p1 = find_set(a);
	int p2 = find_set(b);
	if (p1 == p2)
		return;
	
	if(parent[p1]>parent[p2]) {
		swap(p1,p2);
	}
	parent[p1]+=parent[p2];
	parent[p2] = p1;
}

int main() {
	int n, k;
	cin >> n >> k;

	for(int i=1; i<=n; i++) {
		parent[i] = -1;
	}

	for(int i=1; i<=k; i++) {
		int a, b;
		cin >> a >> b;
		join(a, b);
	}
	int cnt=0;
	for(int i=1; i<=n; i++) {
		if(parent[i]<0) {
			cnt++;
		}
	}
	cout<<cnt<<endl;
}