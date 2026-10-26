class Solution {
public:
    int countOdds(int low, int high) {
        if(low == high ) if(low%2!=0) return 1 ; else return 0;
        if(low + 1 == high) return 1 ;
        int cnt = 0;
        for(int i = low ; i <= high ; i++){
            if(i % 2 !=0) cnt ++;
        }
        return cnt ;
    }
};