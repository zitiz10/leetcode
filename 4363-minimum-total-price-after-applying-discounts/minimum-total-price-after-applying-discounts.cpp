class Solution {
public:
    double minPrice(vector<int>& prices, vector<int>& discounts) {
         
         sort(prices.begin() , prices.end() , greater<int>()) ; 
         sort(discounts.begin() , discounts.end() , greater<int>()) ;
        
        double sum = 0 ; 
        int m = discounts.size() ; 

        for(int i = 0 ; i<prices.size() ; i++){

            if(i < m){
                sum += (double)prices[i] *(100-discounts[i])/100 ; 
            }
            else{
                sum += prices[i] ; 
            }
        }
        return sum ; 
         
         
         }
};