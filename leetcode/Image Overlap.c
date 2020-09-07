using namespace std;
class Solution {
public:
    int calc(vector<vector <int>> A , vector <vector<int>> B, int xshift,int yshift){
        int cnt =0;
        int cmpx=0;
        for(int x=xshift;x<A.size();x++){
            int cmpy=0;
            for(int y= yshift;y<B.size();y++){
                if(A[x][y]==1 && A[x][y]==B[cmpx][cmpy]){
                    cnt ++;
                }
                cmpy++;
            }
            cmpx++;
        }
        return cnt ;
    }
    int largestOverlap(vector<vector<int>>& A, vector<vector<int>>& B) {
        int alen = A.size();
        int blen = B.size();
        int ans =0;
        for(int y_shift=0;y_shift<alen;y_shift++){
            for(int x_shift = 0;x_shift<blen;x_shift++){
                
                ans = max(ans,calc(A,B,x_shift,y_shift));
                ans = max(ans,calc(B,A,x_shift,y_shift));
            }
        }
        return ans ;
    }
};