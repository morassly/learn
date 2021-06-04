
class Solution {
    using ll = long long;
    using PII = pair<int, int>;
    using PLI = pair<ll, int>;

public:
    vector<int> assignTasks(vector<int>& servers, vector<int>& tasks) {
        priority_queue<PLI, vector<PLI>, std::greater<PLI>> work;
        priority_queue<PII, vector<PII>, std::greater<PII>> sleep;

        int n = servers.size(), m = tasks.size();
        for (int i = 0; i < n; ++i)
            sleep.emplace(servers[i], i);
        int cnt = 0;
        ll time = 0;
        vector<int> ans;
        while (cnt < m) {
            while (!work.empty() && time >= work.top().first) {
                auto&& [_, index] = work.top();
                sleep.emplace(servers[index], index);
                work.pop();
            }
            while (time >= cnt && cnt < m && !sleep.empty()) {
                auto&& [_, index] = sleep.top();
                ans.push_back(index);
                work.emplace(time + (ll)tasks[cnt++], index);
                sleep.pop();
            }
            if (!sleep.empty())
                ++time;
            else
                time = max((ll)cnt, work.top().first);
        }
        return ans;
    }
};

static int speedup = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return 0;
}();