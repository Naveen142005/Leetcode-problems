class Solution:
    def reverse(self, x: int) -> int:
        k = x
        if (x < 0 ): 
            x = x * -1
            #if(x >= 1534236469): return 0
        x = int(str(x)[::-1])
        if(x >= 2147483648 or x <= -2147483648): return 0
        if(k < 0):
            return -1 * x
        else:
            return x
# class MagicDictionary {
# public:
#     struct node {
#         struct node* fq[26];
#         bool isLast;
#         struct node* last;
#     };
#     struct node* root = new node();
#     struct node* temp = nullptr;
#     struct node* new_node;
#     void buildDict(vector<string> dictionary) {
#         for (auto& i : dictionary) {
#             temp = root;
#             for (int j = 0; j < i.size(); j++) {
#                 cout<<i[j] - 'a'<<\ \;
#                 if (temp->fq[i[j] - 'a'])
#                     temp = temp->fq[i[j] - 'a'];
#                 else {
#                     new_node = new node();
#                     temp->fq[i[j] - 'a'] = new_node;
#                     temp->isLast = false;
#                     temp = new_node;
#                 }
#             }
#             new_node = new node();
#             temp->last = new_node;
#             new_node->isLast = true;
#         }
#     }

#     bool search(string searchWord) {
#         bool isChange = false, isPresent = true;
#         temp = root;
      
#         for (int i = 0; i < searchWord.size(); i++) {
            
#             if (temp->fq[searchWord[i] - 'a'])
#                 temp = temp->fq[searchWord[i] - 'a'];
#             else if (temp->isLast)
#                 return false;
#             else {
#                 if (!isChange) {
#                     isChange = true;
#                     //temp = temp->fq[searchWord[i] - 'a'];
#                 } else {
#                     isPresent = false;
#                     break;
#                 }
#             }
#         }
#         return 1;
#     }
# };

# /**
#  * Your MagicDictionary object will be instantiated and called as such:
#  * MagicDictionary* obj = new MagicDictionary();
#  * obj->buildDict(dictionary);
#  * bool param_2 = obj->search(searchWord);
#  */


        