class Solution {
public:
    int maxDistance(vector<vector<int>>& arrays) {

        ios_base::sync_with_stdio(false);
        vector<tuple<int, int>> min_es;
        vector<tuple<int, int>> max_es;
       
        int c = 0;
        for (auto& arr : arrays) {
            if (!arr.empty()) {
                int firstElement = arr.front();
                int lastElement = arr.back();
                min_es.push_back(make_tuple(firstElement, c));
                max_es.push_back(make_tuple(lastElement, c));
                c++;
            }
        }

        sort(min_es.begin(), min_es.end());
        sort(max_es.rbegin(), max_es.rend());

        auto [min_first, min_c] = min_es[0];
        auto [max_first, max_c] = max_es[0];
        if (min_c != max_c)
            return abs(min_first - max_first);

        int max_1;
        for (size_t j = 0; j < min_es.size(); ++j) {
            auto [min_f, c1] = min_es[j];
            auto [max_f, c2] = max_es[j];
            if (c1 != max_c) {
                max_1 =  abs(min_f - max_first);
                break;
            }
            
        }
        int max_2;
        for (size_t j = 0; j < min_es.size(); ++j) {
            auto [min_f, c1] = min_es[j];
            auto [max_f, c2] = max_es[j];
            if (c2 != min_c) {
                max_2 =  abs(max_f - min_first);
                break;
            }
        }

        return max_1 > max_2 ? max_1  :max_2;
    }
};