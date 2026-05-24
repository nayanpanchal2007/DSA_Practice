#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<vector<int>> merge_intervals(vector<vector<int>>& intervals) {
    vector<vector<int>> ans;
    sort(intervals.begin(), intervals.end());

    ans.push_back(intervals[0]);

    for (int i = 1; i < intervals.size(); i++) {
        int start = intervals[i][0];
        int end = intervals[i][1];

        int last_end = ans.back()[1];

        if (start <= last_end) {
            ans.back()[1] = max(last_end, end);
        } else {
            ans.push_back(intervals[i]);
        }
    }

    return ans;    
}

int main() {
    vector<vector<int>> intervals = {{1,3},{2,6},{8,10},{15,18}};

    vector<vector<int>> result = merge_intervals(intervals);

    for (auto interval : result) {
        cout << "[" << interval[0] << "," << interval[1] << "] ";
    }
    return 0;
}