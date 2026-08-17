#include <vector>
#include <unordered_map>
#include <queue>

using namespace std;

class Solution {
  public:
    int minThrows(int n, vector<int>& lad, vector<int>& sn) {
        unordered_map<int,int> ladder;
        unordered_map<int,int> snake;

        for (int i = 0; i < lad.size(); i += 2) {
            ladder[lad[i]] = lad[i + 1];
        }

        for (int i = 0; i < sn.size(); i += 2) {
            snake[sn[i]] = sn[i + 1];
        }

        queue<pair<int,int>> q;
        q.push({1, 0});

        int target = n * n;
        vector<int> vis(target + 1, 0);
        vis[1] = 1;

        while(!q.empty()){
            int no = q.front().first;
            int throws = q.front().second;
            q.pop();

            if(no == target) return throws;

            for(int i = 1; i <= 6; i++){
                int newno = no + i;
                if(newno > target) continue;

                // 1. Resolve final destination first
                int dest = newno;
                if(ladder.count(newno)){
                    dest = ladder[newno];
                } else if(snake.count(newno)){
                    dest = snake[newno];
                }

                // 2. Only push and mark visited on the actual DESTINATION
                if(!vis[dest]){
                    vis[dest] = 1;
                    q.push({dest, throws + 1});
                }
            }
        }
        return -1; 
    }
};
//GFG POTD solution for 17 August
