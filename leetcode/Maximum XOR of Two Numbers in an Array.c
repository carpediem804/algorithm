class tree_node{
    public : 
    tree_node* left;
    tree_node* right;
};

class Solution {
public:
    
    tree_node* insert(int n,tree_node* head){
        
        tree_node* curr = head;
        
        for(int i=31;i>=0;i--){
            int bit = (n>>i)&1;
            
            if(bit == 0){ //그 위치가 0일때
                if(!curr->left){
                    curr ->left = new tree_node();
                }
                curr =curr->left;
            }
            else{ //1일때
                if(!curr ->right){
                    curr->right = new tree_node();
                }
                curr = curr->right;
            }
            
        }
        
        return head ;
    }
    
    int maxxor(tree_node* head , vector<int> nums){
        
        int maxans = INT_MIN;
        for(int i=0;i<nums.size();i++){
            
            tree_node* curr = head ;
            int value = nums[i]; 
            int currxor=0;
            
            for(int j=31;j>=0;j--){ 
                
                int bit = (value>>j)&1; //2진수로 나타냇을 때 맨 앞 부터 
                
                if(bit ==0){
                    if(curr->right){ //같은 높이에서 1이 있다면  
                        currxor += pow(2,j); //2의 j승 
                        curr = curr->right;
                    }
                    else{ //1이 없을 때 
                        curr = curr->left; 
                    }
                }
                else{ // bit가 1일 때 
                    if(curr->left){ //같은 높이 층에서 0이 있으면 
                        currxor += pow(2,j);
                        curr = curr->left;
                    }
                    else {
                        curr = curr->right;
                    }
                }
            }
            maxans = max(currxor,maxans);
        }
        return maxans ;
    }
    
    int findMaximumXOR(vector<int>& nums) {
        tree_node* head = new tree_node();
        
        for(int i=0;i<nums.size();i++){
            head = insert(nums[i],head);
        } //노드그리기 
        
        return maxxor(head,nums);
        
    }
};