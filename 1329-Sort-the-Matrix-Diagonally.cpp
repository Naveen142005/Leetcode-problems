class Solution {
public:
    vector<vector<int>> diagonalSort(vector<vector<int>>& ____matrix_to_sort____) {
        ios_base::sync_with_stdio(false);
        if (____matrix_to_sort____.size() == 1) return ____matrix_to_sort____;
        vector<int> ____sortedNumbers____;
        int ____row_index____ = ____matrix_to_sort____.size() - 2
        , ____col_index____ = 0
        , ____row_size____ = ____matrix_to_sort____.size()
        , ____col_size____ = ____matrix_to_sort____[0].size()
        ,____row_copy____ 
        , ____col_copy____
        ,____temp_of_row____
        ,____temp_of_col____;

        bool ____is_reached_top____ = true;
        

        while (____col_index____ < ____col_size____ && ____row_index____ < ____row_size____) {
            ____row_copy____ = ____row_index____;
            ____col_copy____ = ____col_index____;
            while (____row_index____ < ____row_size____ && ____col_index____ < ____col_size____) {
                ____sortedNumbers____.push_back(____matrix_to_sort____[____row_index____][____col_index____]);

                if (____row_index____ + 1 < ____row_size____ &&
                    ____col_index____ + 1 < ____col_size____)
                    ____row_index____ = ____row_index____ + 1
                    ,____col_index____ = ____col_index____ + 1;
                 else {
                    sort(____sortedNumbers____.begin(), ____sortedNumbers____.end());
                     ____temp_of_row____ = ____row_index____;
                     ____temp_of_col____ = ____col_index____;

                    for (int i = ____sortedNumbers____.size() - 1; i >= 0; --i)
                        ____matrix_to_sort____[____temp_of_row____--][____temp_of_col____--] = ____sortedNumbers____[i];

                    ____sortedNumbers____.clear();
                   
                    break;
                }
            }
            
            if (____row_copy____ > 0 && ____is_reached_top____)
                ____row_index____ = ____row_copy____ - 1 ,  ____col_index____ = 0;
            else {
                ____is_reached_top____ = false;
                ____row_index____ = 0;
                ____col_index____ = ____col_copy____ + 1;
            }
        }

        return ____matrix_to_sort____;
    }
};
