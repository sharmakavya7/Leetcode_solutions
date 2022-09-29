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
# define ll long long

const int N = 1e3 + 2 ;
int parent[N];
int sameRisk[N];
int riskFactor[N];
int mod = 1000000007;

int find_parent(int node) {
    if(parent[node] < 0) {
        return node;
    }
    return parent[node] = find_parent(parent[node]);
}

void join(int a, int b) {
    int p1 = find_parent(a);
    int p2 = find_parent(b);

    if(p1==p2) {
        return;
    }
    if(parent[p1] > parent[p2]) {
        swap(p1, p2);
    }
    parent[p1] += parent[p2];
    parent[p2] = p1;
}

void risks(int n) {

	unordered_map < int, int > parentID_leastRiskValue;
    for(int i=1; i<=n; i++) {

        int p = find_parent(i);
		if ( parentID_leastRiskValue.count(p) == 0 || riskFactor[i] < parentID_leastRiskValue[p] ) {
			parentID_leastRiskValue[p] = riskFactor[i];
			sameRisk[p] = 1;
		} else if ( riskFactor[i] == parentID_leastRiskValue[p] ) {
			sameRisk[p] ++;
		}
    }
}

int main() {
	int n;
    cin >> n;

    for(int i=1; i<=n; i++) {
        cin >> riskFactor[i];
    }

	int k;
    cin>>k;
	
    for(int i=1; i<=n; i++) {
        parent[i] = -1;
    }

    for(int i=1; i<=k; i++) {
        int a, b;
        cin >> a >> b;
        join(a,b);
    }

    risks(n);

    int cnt = 1;
    for(int i=1; i<=n; i++) {
        if(parent[i] < 0)
            cnt = ( 1LL * cnt * sameRisk[i] ) % mod;
    }

    cout<<cnt;
    return 0;
}