class Solution {
public:
    bool judgeSquareSum(int c) {
        if(c==0){
            return true;
        }
        set<long long> store;
        long long count=0;
        long long val=0;
        store.insert(val);
        while(val<=c){
            count++;
            val=count*count;
            store.insert(val);
            if(store.count(c-val)){
                return true;
            }
        }
        return false;
    }
};