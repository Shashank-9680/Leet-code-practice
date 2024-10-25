class Solution {
public:
    vector<string> removeSubfolders(vector<string>& folder) {
        // Sort the folders by length to ensure subfolders appear after their parent folder
        sort(folder.begin(), folder.end(), [](const string &a, const string &b) {
            return a.size() < b.size();
        });

        vector<string> ans;
        unordered_set<string> s;

        for (const auto& it : folder) {
            string currentFolder = "";
            bool isSubfolder = false;
            
            for (int i = 1; i < it.size(); i++) {
                if (it[i] == '/') {
                    currentFolder = it.substr(0, i);
                    if (s.find(currentFolder) != s.end()) {
                        isSubfolder = true;
                        break;
                    }
                }
            }

            if (!isSubfolder) {
                ans.push_back(it);
                s.insert(it); // Insert the folder as it is a main folder
            }
              s.insert(it);
        }

        return ans;
    }
};
