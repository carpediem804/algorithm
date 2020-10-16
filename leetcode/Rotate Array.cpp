class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        k = k % nums.size();
	    vector<int> temp(k);
	
	    int j = 0;
	    // Store the last k elements in the temporary array
	    for (int i=nums.size()-k; i<nums.size(); i++) {
	    	temp[j++] = nums[i];
	}
    
	    j = nums.size() - 1;
	    // Right shift all the elements by k steps
	    for (int i=nums.size()-k-1; i>=0; i--) {
		    nums[j--] = nums[i];
	    }
	
	    // Populate the first k elements with the temporary array elements
	    for (int i=0; i<k; i++) {
		    nums[i] = temp[i];
	    }
    }
};