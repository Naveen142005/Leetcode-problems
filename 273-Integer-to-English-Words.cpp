class Solution {
public:
    vector<string> twos = {"",        "One",       "Two",      "Three",
                           "Four",    "Five",      "Six",      "Seven",
                           "Eight",   "Nine",      "Ten",      "Eleven",
                           "Twelve",  "Thirteen",  "Fourteen", "Fifteen",
                           "Sixteen", "Seventeen", "Eighteen", "Nineteen"};
    vector<string> tens = {"",      "Ten",   "Twenty",  "Thirty", "Forty",
                           "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"};

    string calfunction(int n, string s) {
        string ans = "";
        if (n) {
            if (n < 20) {
                ans += twos[n] + " ";
            } else {
                ans += tens[(n / 10)] + " ";
                if (n%10) ans += twos[(n%10)] + " ";
            }
            ans += s + " ";
        }
        return ans;
    }
    string numberToWords(int num) {
        ios_base::sync_with_stdio(false);
        if(!num)
            return "Zero";
        string return_ans = "";
        string k = "";
        return_ans += calfunction(num / 1000000000, "Billion");
        return_ans += calfunction((num / 100000000) % 10, "Hundred");
        if((num / 1000000) % 100 == 0 && (num / 100000000) % 10)return_ans += "Million ";
        return_ans += calfunction((num / 1000000) % 100, "Million");
        return_ans += calfunction((num / 100000) % 10, "Hundred");
        k = calfunction((num / 1000) % 100, "Thousand");
        return_ans += k;
        if((num / 10000) % 10 == 0 && (num / 100000) % 10){
                string j ="";
                if (k != "") {
                bool f = false;
                    for (auto& i : k) {
                        if ( i == ' ') 
                            f = true;
                        if (f) j += i;
                    }
                }
                if ( j !=" Thousand " )
                    return_ans += "Thousand ";
        }
        return_ans += calfunction((num / 100) % 10, "Hundred");
        return_ans += calfunction((num % 100), "");
        if(return_ans[return_ans.size()-1] == ' ') return_ans.pop_back();
        if(return_ans[return_ans.size()-1] == ' ') return_ans.pop_back();
        return return_ans;
    }
};