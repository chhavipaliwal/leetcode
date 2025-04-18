class Solution {
public:
    long long Solve(string& word, int k) {
        int n = word.length();
        int i = 0, j = 0;
        long long ans = 0;
        map<char, int> mp;  // Corrected map type
        int cnt = 0;

        while (j < n) {
            if (word[j] == 'a' || word[j] == 'e' || word[j] == 'i' || word[j] == 'o' || word[j] == 'u') {
                mp[word[j]]++;
            } else {
                cnt++;
            }

            while (mp.size() == 5 && cnt >= k) { // All vowels must be present
                ans += word.size() - j;
                
                if (mp.find(word[i]) != mp.end()) { // Fixed syntax error
                    mp[word[i]]--;
                    if (mp[word[i]] == 0) {
                        mp.erase(word[i]);
                    }
                } else {
                    cnt--;
                }
                i++;
            }
            j++;
        }
        return ans;  // Added return statement
    }

    long long countOfSubstrings(string word, int k) {
        return Solve(word, k) - Solve(word, k + 1); // Fixed function call (case-sensitive)
    }
};