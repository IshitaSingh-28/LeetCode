class Solution {
public:
    int minBitFlips(int start, int goal) {
        
        int a = (start ^ goal); 
        int count = 0; 
        while(a){
            if(a&1){
                count++;
            }
        a = a>>1;  
        }
        return count;
    }
};