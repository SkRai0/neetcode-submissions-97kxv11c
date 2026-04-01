class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        vector<int> pse(n);
        vector<int> nse(n);
        stack<int> s;

        for(int i=0;i<n;i++){
            while(!s.empty() && heights[s.top()]>=heights[i]) s.pop();
            pse[i] = s.empty()?-1:s.top();
            s.push(i);
        }

        s = stack<int>();

        for(int i=n-1;i>=0;i--){
            while(!s.empty() && heights[s.top()]>=heights[i]) s.pop();
            nse[i] = s.empty()?n:s.top();
            s.push(i);
        }

        int maxArea = INT_MIN;
        for(int i=0;i<n;i++){
            int area = (nse[i]-pse[i]-1)*heights[i];
            maxArea = max(maxArea, area);
        }

        return maxArea;
    }
};
