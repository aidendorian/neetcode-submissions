class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<vector<int>> pos_speed;
        int n = position.size();
        for(int i=0;i<n; i++)
            pos_speed.push_back({position[i], speed[i]});
        sort(pos_speed.begin(), pos_speed.end(), greater<vector<int>>());
        int fleet = 0;
        float t = 0;
        for(int i = 0; i<n; i++){
            float time = (float)(target - pos_speed[i][0])/pos_speed[i][1];
            if(time>t){
                t = time;
                fleet++;
            }
        }
        return fleet;
    }
};
