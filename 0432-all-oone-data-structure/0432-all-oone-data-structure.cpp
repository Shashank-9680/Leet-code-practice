class AllOne {
public:
    unordered_map<string,int> count; 
    set<pair<int,string>> se;         
    
    AllOne() {
        count.clear();  
    }

    // Increment the count of the key
    void inc(string key) {
        int n = count[key];   // Get current count
        count[key]++;         // Increment the count
        se.erase({n, key});   // Remove the old pair from set
        se.insert({n+1, key}); // Insert the new pair with updated count
    }

    // Decrement the count of the key
    void dec(string key) {
        int n = count[key];   // Get current count
        count[key]--;         // Decrement the count
        se.erase({n, key});   // Remove the old pair from set
        if (count[key] > 0) se.insert({n-1, key});  // If count > 0, insert updated pair
        else count.erase(key);  // If count reaches 0, remove the key from map
    }

    // Get the key with the maximum count
    string getMaxKey() {
        if (!se.empty()) return se.rbegin()->second;  // Last element gives the maximum
        return "";
    }

    // Get the key with the minimum count
    string getMinKey() {
        if (!se.empty()) return se.begin()->second;  // First element gives the minimum
        return "";
    }
};