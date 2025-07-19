class Solution {
public:
    vector<string> removeSubfolders(vector<string>& folder) {
        // Sort the folders lexicographically
        sort(folder.begin(), folder.end());
        
        vector<string> result;
        
        for (const string& f : folder) {
            // If result is empty or current folder is not a subfolder of the last added folder
            if (result.empty() || !isSubfolder(f, result.back())) {
                result.push_back(f);
            }
        }
        
        return result;
    }
    
private:
    bool isSubfolder(const string& folder, const string& parent) {
        // Check if folder is a subfolder of parent
        // A subfolder must start with parent + "/"
        if (folder.length() <= parent.length()) {
            return false;
        }
        
        // Check if folder starts with parent
        if (folder.substr(0, parent.length()) != parent) {
            return false;
        }
        
        // Check if the next character after parent is '/'
        return folder[parent.length()] == '/';
    }
};