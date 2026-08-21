class Solution {
public:
    long long gcdll(long long a, long long b) {
        while (b) {
            long long temp = a % b;
            a = b;
            b = temp;
        }
        return a;
    }
    long long lcm(long long a, long long b) {
        return a / gcdll(a, b) * b;
    }
    long long findKthSmallest(vector<int>& coins, int k) {
        int n = coins.size();
        int total = 1 << n;
        vector<long long> L(total, 1);
        vector<int> sign(total);
        for (int mask = 1; mask < total; mask++) {
            int prev = mask & (mask - 1);
            int bit = 0;
            int temp = mask ^ prev;
            while ((temp & 1) == 0){
                temp >>= 1;
                bit++;
            }
            L[mask] = lcm(L[prev], coins[bit]);
            if (L[mask] > 1e18) L[mask] = 1e18;
            int bits = 0;
            int x = mask;
            while (x) {
                bits += x & 1;
                x >>= 1;
            }
            if (bits % 2 == 1) sign[mask] = 1;
            else sign[mask] = -1;
        }
        auto count = [&](long long x) {
            long long ans = 0;
            for (int mask = 1; mask < total; mask++) {
                if (L[mask] <= x) {
                    ans += sign[mask] * (x / L[mask]);
                }
            }
            return ans;
        };
        long long low = 1;
        long long high = 1LL * (*max_element(coins.begin(),coins.end())) * k;
        while (low < high) {
            long long mid = low + (high - low) / 2;
            if (count(mid) >= k) high = mid;
            else low = mid + 1;
        }
        return low;
    }
};