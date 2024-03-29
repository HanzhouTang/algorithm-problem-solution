class Solution {
public:
    long long maximumBeauty(vector<int>& flowers, long long newFlowers, int target, int full, int partial) {
        vector<long long> prefix_sum(flowers.size());
        vector<long long> have_to;
        sort(flowers.begin(),flowers.end());
        long long sum = 0; 
        for(int i = flowers.size()-1;i>=0;i--) {
            sum += max(0,target - flowers[i]);
            have_to.push_back(sum);
        }
        have_to.push_back(LLONG_MAX);
        prefix_sum[0] = flowers[0];
        for(int i = 1;i<flowers.size();i++) {
            prefix_sum[i] = prefix_sum[i-1] + flowers[i];
        } 
        auto ptr = upper_bound(have_to.begin(),have_to.end(),newFlowers);
        long long ret = full * (long long)(ptr - have_to.begin());
        const int n = flowers.size(); 
        for(long long t = flowers[0];t<target;t++) {
            auto ptr = lower_bound(flowers.begin(),flowers.end(),t+1); 
            if(ptr == flowers.begin()) {
                continue; 
            }
            int index = ptr - flowers.begin() - 1; 
            //[0 .. index] -> t 
            long long need = (index + 1) * t - prefix_sum[index];
            if(need > newFlowers) {
                break; 
            }
            long long rest = newFlowers - need; 
            auto q = upper_bound(have_to.begin(),have_to.end(),rest);
            long long len = q - have_to.begin(); // current target 
            long long left = rest;
            if(len > n - index - 1) {
                len =  (long long)n - index - 1; 
                if (len>0)
                    left = rest - have_to[len-1];
            }  else if(q != have_to.begin()) {
                q--; 
                left = rest - *q;
            }
            long long k = left / (target - t);
            k = min(k,(long long)index);
            len += k; 
            long long score = len * full + partial * t;
            ret = max(ret, score);
        }
        return ret; 
    }
};