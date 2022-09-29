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

const int N = 102 ;
int parent[N] ;

int find_parent(int node) {
    if(parent[node]<0) {
        return node;
    }
    return parent[node] = find_parent(parent[node]);
    // isko visualize tree bna ke karo
    // if it is not the parent of itself, 
    // then jo bhi uska parent hai (say x), then go and find x ka parent ans so on(upr jaate jao)
    //     1
    //      \               Find parent of 4, 4 se 1 tak travel krna hai:
    //       2              here, 4 ka parent is 3, 3 ka parent is 2, and 2 ka parent is 1, 
    //        \             1 is the parent of itself, so 1 pe -ve value hogi
    //         3            hence, we finally found the parent of 4
    //          \
    //           4
    // parent[node] = find_parent(parent[node]); is operation me humne sath sath 4, 3 , 2 ka bhi
    // parent change kr dia to 1, jitne bhi path me involved hai, sabka parent = 1
    // jaise jaise we're calling find_parent, hum path compress kr rhe hai
    // now the tree will look like this:   1
    //                                   / | \
    //                                  2  3  4
}

void join (int a, int b) {
    int p1 = find_parent(a);
    int p2 = find_parent(b);

    if(p1==p2) {
        return;
    }
    // we always want p1 to be larger tree than p2
    // so whenever p2 will become greater, swasp them to keep p1 always greater
    if(parent[p1] < parent[p2]) {
        swap(p1,p2);
    }
    // ab kya? ab hum jod rhe hai, p1 ke neeche p2 ko, to p1 me nodes aur add hongi? yes!
    // size inc hoga? yes! So add it, update the value at p1 in parent array
    parent[p1]+=parent[p2];
    // now, p2 ka parent is p1
    parent[p2] = p1;
}

int main() {
    // input();
    int n;
    cin>>n;
    vector<pair<int,int>>coordinates(n);
    
    for(int i=0; i<n; i++) {
        cin>>coordinates[i].first;
        cin>>coordinates[i].second;
    }
    for(int i=0; i<n; i++) {
        parent[i] = -1;
    }
    // join those coordinates, who lie at either same x axis or same y axis
    // meaning x coordinates same ho ya y coordinates same ho
    for(int i=0; i<n; i++) {
        for(int j=i+1; j<n; j++) {
            if(coordinates[i].first==coordinates[j].first || coordinates[i].second==coordinates[j].second) {
                join(i, j);
            }
        }
    }
    // now count the connected components why?
    // bcz jitne connected components honge, 
    // usse 1 kam points chaiye honge hume to connect them all
    int connected_cnt = 0;
    // connected components count kaise kre?
    // just see kon kiska parent hai
    // same parent hai, mtlb they lie in same component
    for(int i=0; i<n; i++) {
        if(parent[i]<0) {
            connected_cnt++;
        }
    }
    // int ans = connected_cnt-1;
    cout<<connected_cnt-1;
    return 0;
}