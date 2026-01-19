class Solution {
public:
    using ll = long long;
    int mod = 1000000007;
    int maximizeSquareArea(int m, int n, vector<int>& h, vector<int>& v) {
        h.push_back(1);
        h.push_back(m);
        v.push_back(1);
        v.push_back(n);
        sort(h.begin(), h.end());
        sort(v.begin(), v.end());
        vector<int> gh, gv;
        for (int i = 1; i < h.size(); i++) {
            gh.push_back(h[i] - h[i - 1]);
        }
        for (int i = 1; i < v.size(); i++) {
            gv.push_back(v[i] - v[i - 1]);
        }
        unordered_map<ll, bool> sumC;
        int nh = gh.size(), nv = gv.size();
        for (int i = 0; i < nh; i++) {
            ll sum = 0;
            for (int j = i; j < nh; j++) {
                sum += gh[j];
                sumC[sum] = true;
            }
        }
        ll res = -1;
        for (int i = 0; i < nv; i++) {
            ll sum = 0;
            for (int j = i; j < nv; j++) {
                sum += gv[j];
                if (sumC[sum])
                    res = max(res, (sum * sum));
            }
        }
        return res%mod;
    }
};