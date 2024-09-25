class Solution {
public:
    struct Trie {
        struct Trie* freq[26] = {NULL};
        bool isLast = false;
        int cnt  = 0;
    };
    Trie* root = new Trie();
    void insert (string word ){
         Trie* temp = root;
         char l;
         for (auto& i : word) {
            if (temp -> freq[i - 'a'] ) {
                temp = temp -> freq [i - 'a'];
            }
            else {
                Trie* obj = new Trie();
                temp -> freq[i - 'a'] = obj;
                temp = obj;
            }
            temp -> isLast = true;
            temp -> cnt += 1;
         }
         
         
        
    }
    int search (string word) {
        Trie* temp = root;
        int cnt = 0;
         for (auto& i : word) {
            if (temp -> freq[i - 'a']) temp = temp -> freq[i - 'a'];
            if (temp -> isLast) cnt += temp -> cnt ;
         }
         return cnt;

    }
    vector<int> sumPrefixScores(vector<string>& words) {
        ios_base::sync_with_stdio(false);
        for (auto& word : words) {
           insert(word);
        }
        vector<int> ans;
        for (auto& word : words) {
            int cnt = 0;
            cnt += search(word);
            ans.push_back(cnt);
        }

        return ans;
        
    }
};