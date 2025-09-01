class Solution {
public:
    double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {
        // A max priority queue to store pairs of {gain, class_index}.
        // The gain is the first element so the queue sorts by it automatically.
        priority_queue<pair<double, int>> pq;

        // --- 1. Initial Population ---
        // Calculate the initial gain for each class and populate the priority queue.
        for (int i = 0; i < classes.size(); ++i) {
            double pass = classes[i][0];
            double total = classes[i][1];
            
            // The gain is the difference between the new ratio and the old ratio.
            double gain = (pass == total) ? 0.0 : ((pass + 1.0) / (total + 1.0)) - (pass / total);
            pq.push({gain, i});
        }

        // --- 2. Process the Students ---
        // Greedily assign each extra student to the class with the highest potential gain.
        while (extraStudents > 0) {
            // Get the class with the current maximum gain.
            pair<double, int> top = pq.top();
            pq.pop();
            int classIndex = top.second;

            // Update the class by adding one student.
            classes[classIndex][0]++;
            classes[classIndex][1]++;

            // Recalculate the new gain for the updated class.
            double newPass = classes[classIndex][0];
            double newTotal = classes[classIndex][1];
            double newGain = (newPass == newTotal) ? 0.0 : ((newPass + 1.0) / (newTotal + 1.0)) - (newPass / newTotal);
            
            // Push it back into the queue with its new gain.
            pq.push({newGain, classIndex});
            
            extraStudents--;
        }

        // --- 3. Final Calculation ---
        // Calculate the average of the final ratios.
        double totalRatioSum = 0;
        for (const auto& c : classes) {
            totalRatioSum += static_cast<double>(c[0]) / c[1];
        }

        return totalRatioSum / classes.size();
    }
};