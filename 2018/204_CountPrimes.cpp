#include <vector>
#include <iostream>
#include <string>
#include <unordered_set>
#include <unordered_map>
#include <stack>
#include <queue>
#include <map>
#include <set>

using namespace std;


// https://blog.csdn.net/NoMasp/article/details/50617645
// 小细节多一些 
// i*i<n 比用 sqrt效率高

class Solution {
public:
	bool is_prime(int n){
		for(int i=2; i*i<=n; i++){
			if(n%i==0){
				return false;
			}
		}
		return true;
	}
    int countPrimes(int n) {
    	if(n<=2){return 0;}
    	int cnt = 1;
    	for(int i=3; i<n; i+=2){
    		if(is_prime(i)){
    			cnt++;
    		}
    	}
    	return cnt;
    }
};
int main(int argc, char const *argv[])
{
	cout << Solution().countPrimes(10) << endl;
	return 0;
}
