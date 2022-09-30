class Solution {
public:
    static bool comp(pair<int, int> &p1, pair<int, int> &p2) {
		if (p1.first == p2.first) return p1.second < p2.second;
		return p1.first < p2.first;
	}
	vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
		vector<pair<int, int>> list;
		vector<vector<int>> ans;

		for (auto x : buildings) {

			list.push_back({x[0], -x[2]}); list.push_back({x[1], x[2]});
		}

		sort(list.begin(), list.end(), comp);
		for(auto x : list) {
		    cout<<" [" << x.first << ", " << x.second << "] ";
		}


		multiset<int> pq; pq.insert(0);
		int current_height = 0;
		for (auto x : list) {

			if (x.second < 0) {
				// starting point
				pq.insert(-x.second);
				if (*pq.rbegin() > current_height) {
					ans.push_back({x.first, -x.second});
					current_height = -x.second;
				}

			} else {
				pq.erase(pq.find(x.second));
				if (*pq.rbegin() < current_height) {
					ans.push_back({x.first, *pq.rbegin()});
					current_height = *pq.rbegin();
				}
			}
		}

		return ans;

	}
};