class Solution {
public:
   
    int bitwiseComplement(int n) {
         if(n==0)return 1;
        int x=int(log2(n))+1;
        return (int(pow(2,x))-1)^n;
    }
};