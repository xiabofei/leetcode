#include <vector>
#include <iostream>
#include <string>
#include <unordered_set>
#include <unordered_map>
#include <stack>
#include <queue>
#include <map>

using namespace std;

// https://leetcode.com/problems/transform-to-chessboard/discuss/115613/C++-O(N2)-time-solution-with-explantion
// 大概思路分两个
// 1) 判断是否合法 :
//    准则1 : 只能有两种行:要么完全相等,要么完全错开,且完全相等和完全错开的行数最多相差1(列同理)
//    准则2 : 每行0和1的个数最多相差1(列同理) 
// 2) 最小交换次数 : 分奇数偶数

class Solution {
public:
    int movesToChessboard(vector<vector<int>>& board) {
    	// 判断任意两行和两列要么是完全相等 要么是正好错开 公共判断条件是2*2异或是0
    	const int n = board.size();
    	for(int r=1; r<n; r++){
    		for(int c=1; c<n; c++){
    			if(board[r][c] ^ board[r-1][c] ^ board[r][c-1] ^ board[r-1][c-1]){
    				return -1;
    			}
    		}
    	}
    	// 找最小交换次数
    	vector<int> col(n, 0);
    	for(int i=0; i<n; i++){
    		col[i] = board[i][0];
    	}
    	return max(help(board[0])+help(col), -1);
    }
    int help(vector<int>& line){
    	// 分别统计奇/偶数 index的1的个数
    	int odd = 0;
    	int even = 0;
    	for(int i=0; i<line.size(); i++){
    		if(line[i]==1){
    			if(i & 1){
    				odd++;
    			}
    			else{
    				even++;
    			}
    		}
    	}
    	cout << odd << endl;
    	cout << even << endl;
    	// 1超过一半的数量 不合规
    	int gap = 2*odd + 2*even - line.size();
    	if(gap>1 || gap<-1){
    		return INT_MIN;
    	}
    	// board长度分奇/偶数 判断
    	if(line.size() & 1){
    		// 奇数位置的1都换掉
    		if((odd+even)>line.size()/2){
    			return odd;
    		}
    		// 偶数位置的1都换掉
    		return even;
    	}
    	else{
    		return min(odd, even);
    	}
    }
};

int main(int argc, char const *argv[])
{
	vector<vector<int>> dat;
	dat.push_back({1,1,0});
	dat.push_back({0,0,1});
	dat.push_back({0,0,1});
	cout << Solution().movesToChessboard(dat) << endl;
	return 0;
}