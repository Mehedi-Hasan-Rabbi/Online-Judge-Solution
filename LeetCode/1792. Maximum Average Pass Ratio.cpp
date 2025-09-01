class Solution {
public:
    double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {
        priority_queue<pair<double, vector<int>>> pq;

        for (auto u: classes) {
            double currRatio = u[0] * 1.0 / u[1];
            double updateRation = ( (u[0] + 1) * 1.0 ) / (u[1] + 1);
            double changeInRation = updateRation - currRatio;

            pq.push({changeInRation, u});
        }
        
        while (extraStudents > 0) {
            pair<double, vector<int>> highestRation = pq.top();
            pq.pop();
            
            highestRation.second[0] += 1;
            highestRation.second[1] += 1;

            double currRatio = highestRation.second[0] * 1.0 / highestRation.second[1];
            double updateRation = ( (highestRation.second[0] + 1) * 1.0 ) / (highestRation.second[1] + 1);
            double changeInRation = updateRation - currRatio;

            highestRation.first = changeInRation;
            pq.push(highestRation);
            extraStudents--;
        }

        double sum = 0.0;
        while (!pq.empty()) {
            sum += pq.top().second[0] * 1.0 / pq.top().second[1];
            pq.pop();
        }

        double ans = sum / classes.size();

        return ans;
    }
};