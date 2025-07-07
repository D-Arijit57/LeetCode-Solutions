class Solution {
public:
    int maxEvents(vector<vector<int>>& events) {
        // Sort events by start day
        sort(events.begin(), events.end());
        
        // Min-heap to store end days of available events
        priority_queue<int, vector<int>, greater<int>> pq;
        
        int i = 0; // Index for events array
        int day = 1; // Current day
        int count = 0; // Number of events attended
        
        while (i < events.size() || !pq.empty()) {
            // Add all events that start on current day to the heap
            while (i < events.size() && events[i][0] <= day) {
                pq.push(events[i][1]); // Add end day to heap
                i++;
            }
            
            // Remove all events that have already ended
            while (!pq.empty() && pq.top() < day) {
                pq.pop();
            }
            
            // If there are available events, attend the one ending earliest
            if (!pq.empty()) {
                pq.pop(); // Attend this event
                count++;
            }
            
            day++;
        }
        
        return count;
    }
};