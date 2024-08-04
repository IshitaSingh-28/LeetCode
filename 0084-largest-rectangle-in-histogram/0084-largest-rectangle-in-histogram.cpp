class Solution {
public:
    int largestRectangleArea(vector<int>& hts) {
        int size=hts.size();
        int to_right[size];
        stack<int> st;
        for(int i=size-1;i>=0;--i){
            while(!st.empty() and hts[st.top()]>=hts[i])
                st.pop();
            to_right[i]=st.empty()?size:st.top();
            st.push(i);
        }
        while(!st.empty())st.pop();
        int maxarea=0;
        for(int i=0;i<size;++i){
            while(!st.empty() and hts[st.top()]>=hts[i])
                st.pop();
            int to_left=st.empty()?-1:st.top();
            maxarea=max(maxarea,(to_right[i]-to_left-1)*hts[i]);
            st.push(i);
        }
        
        return maxarea;
        
    }
};