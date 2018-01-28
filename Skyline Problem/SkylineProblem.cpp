#include <vector>
#include <algorithm>
#include <queue>
#include <functional>
using namespace std;

struct Building {
    int h, l, r, index;
    Building(int _index, int _h, int _l, int _r) : index(_index), h(_h), l(_l), r(_r) { }
};

struct MyPoint {
    int x, y, bIndex;
    MyPoint(int _x, int _y, int _bIndex) : x(_x), y(_y), bIndex(_bIndex) {}
};

class Solution {
public:
    vector<pair<int, int>> getSkyline(vector<vector<int>>& A) {
        vector<Building> buildings;
        vector<MyPoint> points;
        for (int i = 0; i<A.size(); i++) {
            buildings.push_back(Building(i, A[i][2], A[i][0], A[i][1]));
            points.push_back(MyPoint(A[i][0], A[i][2], i));
            points.push_back(MyPoint(A[i][1], 0, i));
        }

        sort(points.begin(), points.end(), [](const MyPoint &a, const MyPoint &b) {
            if (a.x == b.x) return a.y > b.y;
            return a.x < b.x;
            }
        );

        priority_queue < pair<int, int>, vector<pair<int, int> >, std::less<pair<int, int> > > Q;
        vector<pair<int, int> > ans;
        int curI = 0;

        for (auto p : points) {
            curI = p.x;
            if (p.y != 0) {
                // push this guy into our queue which is sorted by height
                Q.push(make_pair(p.y, p.bIndex));
            }

            // remove heights till curI
            while (!Q.empty() && buildings[Q.top().second].r <= curI) Q.pop();
            
            // x would be curI and y would be max height of the queue or 0
            int maxHeight = Q.empty() ? 0 : Q.top().first;
            if (ans.size() == 0 || ans.back().second != maxHeight) {
                ans.push_back(make_pair(curI, maxHeight));
            }
        }

        return ans;
    }
};


int main() {
    vector<vector<int> > v = { { 2, 9, 10 },{ 3, 7, 15 },{ 3, 7, 15 },{ 5, 12, 12 },{ 15, 20, 10 },{ 19, 24, 8 } };
    Solution s;
    auto ans = s.getSkyline(v);
}
