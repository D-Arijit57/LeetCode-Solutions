class Solution {
public:
    struct TrieNode {
        unordered_map<string, TrieNode*> children;
        bool deleted = false;
    };
    
    vector<vector<string>> deleteDuplicateFolder(vector<vector<string>>& paths) {
        // Build trie
        TrieNode* root = new TrieNode();
        
        for (auto& path : paths) {
            TrieNode* cur = root;
            for (string& folder : path) {
                if (cur->children.find(folder) == cur->children.end()) {
                    cur->children[folder] = new TrieNode();
                }
                cur = cur->children[folder];
            }
        }
        
        // Map from serialized structure to list of nodes with that structure
        unordered_map<string, vector<TrieNode*>> structureToNodes;
        
        // DFS to serialize and identify duplicates
        function<string(TrieNode*)> dfs = [&](TrieNode* node) -> string {
            if (node->children.empty()) {
                return "()";
            }
            
            vector<string> childStructures;
            for (auto& [folderName, childNode] : node->children) {
                string childStructure = dfs(childNode);
                childStructures.push_back("(" + folderName + childStructure + ")");
            }
            
            sort(childStructures.begin(), childStructures.end());
            
            string structure = "";
            for (string& s : childStructures) {
                structure += s;
            }
            
            structureToNodes[structure].push_back(node);
            return structure;
        };
        
        dfs(root);
        
        // Mark nodes for deletion if they have duplicates and are not leaf nodes
        for (auto& [structure, nodes] : structureToNodes) {
            if (nodes.size() > 1 && structure != "()") {
                for (TrieNode* node : nodes) {
                    markForDeletion(node);
                }
            }
        }
        
        // Collect remaining paths
        vector<vector<string>> result;
        vector<string> currentPath;
        
        function<void(TrieNode*)> collectPaths = [&](TrieNode* node) {
            // Add current path if it's not the root (currentPath is not empty)
            if (!currentPath.empty()) {
                result.push_back(currentPath);
            }
            
            for (auto& [folderName, childNode] : node->children) {
                if (!childNode->deleted) {
                    currentPath.push_back(folderName);
                    collectPaths(childNode);
                    currentPath.pop_back();
                }
            }
        };
        
        collectPaths(root);
        
        return result;
    }
    
private:
    void markForDeletion(TrieNode* node) {
        node->deleted = true;
        for (auto& [folderName, childNode] : node->children) {
            markForDeletion(childNode);
        }
    }
};