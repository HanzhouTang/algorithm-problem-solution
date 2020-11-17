class Solution {
public:
    int f(int state, const int& finish, int i, vector<int>& t, vector<int>& qs, vector<vector<int>>& dp) {
        if(state == finish) {
            return 1; 
        }
        if(i == t.size()) {
            return 2; 
        }
        if(dp[state][i]) {
            return dp[state][i];
        }
        int ret = 2; 
        const int value = t[i];
        const int sup = state ^ finish;
        int sub = sup;
        do {
            sub = (sub - 1) & sup;
            bool run = true; 
            for(int k = 0;k<qs.size();k++) {
                if((sub>>k)&1) {
                    if(t[i] >= qs[k]) {
                        t[i] -= qs[k];
                    } else {
                        run = false; 
                        break; 
                    }
                }
            }
            if(run) {
                ret = f(state|sub,finish,i+1,t,qs,dp);
            }
            t[i] = value; 
            if(ret == 1) {
                return dp[state][i] = 1;
            }
        } while(sub != sup);
        return dp[state][i] = 2; 
    }
    bool canDistribute(vector<int>& nums, vector<int>& qs) {
        unordered_map<int,int> m; 
        for(int x : nums) {
            m[x]++;
        }
        vector<int> t(m.size());
        int i = 0; 
        for(auto& p : m) {
            t[i++] = p.second;
        }
        vector<int> tmp; 
        sort(t.begin(),t.end());
        for(int i = 1;i<=t.size()&&i<=qs.size();i++) {
            tmp.push_back(t[t.size()-i]);
        }
        t = tmp; 
        int n = qs.size();
        vector<vector<int>> dp(1<<n,vector<int>(t.size()));
        int ret = f(0,(1<<n)-1,0,t,qs,dp);
        return ret == 1; 
    }
};