/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> dir={{0,1},{1,0},{0,-1},{-1,0}};
    vector<vector<int>> spiralMatrix(int m, int n, ListNode* head) {
        int i=0,j=0;
        int curDir = 0;
        vector<vector<int>> ans(m,(vector<int>(n,-1)));
        if(m==1 && n==1 && head) {ans[0][0]=head->val; return ans;} // handle edge case 

        int x=m,y=n;
        int times=y-1; // no of times the particular dimension is to be traversed.
        int filled=0; // to account for the fact where we have completed filling all the columns
        while(head !=nullptr && filled < m*n ){
            if(times>0 && x>0 && y>0){
                filled++;
                ans[i][j]=head->val;
                head = head->next;
                i+=dir[curDir][0];
                j+=dir[curDir][1];
                times--;
            } else if(times ==0 && (x==0 || y==0)){  // handle edge case 
                filled++;   
                ans[i][j]=head->val;
                head = head->next;
                i+=dir[curDir][0];
                j+=dir[curDir][1];
                times--;
            } else {
                // change dir and reduce the dimension length 
                // of the upcoming dimension to be traversed before assigning it to times
                if(curDir == 0) {times=--x;}
                else if(curDir == 1) {times=--y;}
                else if(curDir == 2) {times=--x;}
                else if(curDir == 3) {times=--y;}
                curDir= (curDir+1)%4;
            }
        }
        return ans;
    }
};