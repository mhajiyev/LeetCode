 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    int numComponents(ListNode* head, vector<int>& G) {
        if (G.size()==0) return 0;
        else if (G.size()==1) return 1;
     
        
       int count =1;
        int i = 0;
        int remaining = G.size();
        
        while (head!=NULL){
            
            if (remaining==0) return count;
            if (std::find(G.begin(), G.end(),head->val)!=G.end()) {head = head->next;remaining--;i=1;}
           
            else 
            {head = head->next;
             if (i)count++; i=0;}
        }
        

        
        
        return count;
    }
};
