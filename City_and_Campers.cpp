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

const int N = 1e5 + 2;
int parent[N];
multiset<int>sizes;   // at any point stores the sizes of groups

int find_parent(int node) {
    if(parent[node] < 0) {
        return node;
    }
    // cout<<node<<" ";
    return parent[node] = find_parent(parent[node]);
}

void merge(int a, int b) {
    int sizeA = -parent[a];
    int sizeB = -parent[b];
    // cout<<sizeA<<" ";
    // exisiting element hata kr new wala insert kr
    sizes.erase(sizes.find(sizeA));
    sizes.erase(sizes.find(sizeB));

    sizes.insert(sizeA+sizeB);

}

void join(int a, int b) {
    int p1 = find_parent(a);
    int p2 = find_parent(b);
    // cout<<p1<<" ";
    if(p1==p2) {
        return;
    }
    if(parent[p1]>parent[p2] ) {
        swap(p1, p2);
    }
    merge(p1, p2);
    parent[p1] += parent[p2];
    parent[p2] = p1;
}


int main() {
    int n, q;
    cin >> n >> q;

    for(int i=1; i<=n; i++) {
        parent[i] = -1;
        sizes.insert(1);
    }
    
    for(int i=1; i<=q; i++) {
        // cout<<"yo"<<" ";
        int u, v;
        cin >> u >> v;
        // cout<<"yo"<<" ";
        join(u,v);

        if(sizes.size()==1) {
            cout<<0<<endl;
        }
        else {
            int mini = *(sizes.begin());
            int maxi = *(--sizes.end());
            cout<<maxi - mini<<endl;
        }
    }
    return 0;
}

/*

the last value in the multi-set is the iterator, just before the end()

So, there are multiple ways of doing this
1. int maxi = *(prev(sizes.end()));
2. int maxi = *(sizes.rbegin());
3. int maxi = *(--sizes.end());
use either of these lines

Explanations: 
1. prev(it) function finds the previous value for a given iterator 'it'. 
And dereferencing that shall give u correct answer
2. rbegin() is reverse iterator. So, the first value in the reverse iterator 
is what u are looking for

*/