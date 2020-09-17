class Solution {
public:
    vector<double> twoSum(int n) {
        vector<double> pre_prob = {1.0/6, 1.0/6, 1.0/6, 1.0/6, 1.0/6, 1.0/6};
        for(int i = 2; i <= n; i++){ //i个骰子
            vector<double> prob(5 * i + 1, 0);
            for(int j = 0; j < pre_prob.size(); j++){//i-1个骰子
                for(int k = 0; k < 6; k++){//1个骰子
                    prob[j + k] += pre_prob[j] * 1.0 / 6;
                }
            }
            pre_prob = prob;
        }
        return pre_prob;
    }
};