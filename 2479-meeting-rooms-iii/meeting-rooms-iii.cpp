class Solution {
public:
    int mostBooked(int n, vector<vector<int>>& meetings) {
        // Sort meetings by start time
        sort(meetings.begin(), meetings.end());
        
        // Priority queue for available rooms (min-heap by room number)
        priority_queue<int, vector<int>, greater<int>> availableRooms;
        
        // Priority queue for busy rooms (min-heap by end time, then by room number)
        priority_queue<pair<long long, int>, vector<pair<long long, int>>, 
                      greater<pair<long long, int>>> busyRooms;
        
        // Initialize all rooms as available
        for (int i = 0; i < n; i++) {
            availableRooms.push(i);
        }
        
        // Count meetings for each room
        vector<int> meetingCount(n, 0);
        
        for (auto& meeting : meetings) {
            long long startTime = meeting[0];
            long long endTime = meeting[1];
            long long duration = endTime - startTime;
            
            // Free up rooms that have finished by current start time
            while (!busyRooms.empty() && busyRooms.top().first <= startTime) {
                int room = busyRooms.top().second;
                busyRooms.pop();
                availableRooms.push(room);
            }
            
            int assignedRoom;
            long long actualEndTime;
            
            if (!availableRooms.empty()) {
                // Room is available, use it at the original start time
                assignedRoom = availableRooms.top();
                availableRooms.pop();
                actualEndTime = endTime;
            } else {
                // No room available, delay the meeting
                // Find the earliest room that will be free
                long long earliestFreeTime = busyRooms.top().first;
                assignedRoom = busyRooms.top().second;
                busyRooms.pop();
                
                // Meeting starts when room becomes free
                actualEndTime = earliestFreeTime + duration;
            }
            
            // Schedule the meeting in the assigned room
            busyRooms.push({actualEndTime, assignedRoom});
            meetingCount[assignedRoom]++;
        }
        
        // Find the room with the most meetings
        int maxMeetings = 0;
        int result = 0;
        
        for (int i = 0; i < n; i++) {
            if (meetingCount[i] > maxMeetings) {
                maxMeetings = meetingCount[i];
                result = i;
            }
        }
        
        return result;
    }
};