#include <vector>
#include <iostream>
#include <string>
#include <unordered_set>
#include <unordered_map>
#include <stack>
#include <queue>
#include <map>

using namespace std;

// 走两遍 左边隔着最近的1 右边隔着最近的1 min(左, 右)

class Solution {
public:
    int maxDistToClosest(vector<int>& seats) {
    	if(seats.size()==1){return 0;}
    	if(seats.size()==2){return 1;}
    	// i往左最近的1 记录下标
    	vector<int> l_closest(seats.size(), 0);
    	// cout << "left" << endl;
    	l_closest[0] = (seats[0]==1 ? 0 : -20000);
    	for(int i=1; i<seats.size(); i++){
    		l_closest[i] = (seats[i-1]==1 ? i-1 : l_closest[i-1]);
    		// cout << l_closest[i] << endl;
    	}
    	// right closest
    	// cout << "right" << endl;
    	vector<int> r_closest(seats.size(), seats.size()-1);
    	r_closest[seats.size()-1] = (seats[seats.size()-1]==1 ? seats.size()-1 : 20000);
    	for(int i=seats.size()-2; i>=0; i--){
    		r_closest[i] = (seats[i+1]==1 ? i+1 : r_closest[i+1]);
    		// cout << r_closest[i] << endl;
    	}
    	// 比较获得最大的间隔
    	int ret = -1;
    	for(int i=0; i<seats.size(); i++){
    		if(seats[i]==1){
    			continue;
    		}
    		ret = max(min(i-l_closest[i], r_closest[i]-i), ret);
    	}
    	return ret;
    }
};

int main(int argc, char const *argv[])
{
	vector<int> dat = {1, 0, 0, 0};
	Solution().maxDistToClosest(dat);
	return 0;
}
