#include <iostream>
#include <vector>
#include <map>
#include <stack>

using namespace std;

class Solution{
public:
    static string simplifyPath(string path)
    {
    	if ( path.empty() ) return path;
    	path = path + "/";
    	string ret = "";
    	stack<string> sta;
    	vector<char> content;
    	// analyze the Path
    	for ( int i=0; i<path.size(); ++i )
    	{
    		if ( path[i]!='/' ){
    			content.push_back(path[i]);
    		}
    		else{
    			if ( content.empty() ) continue;
    			string tmp = string(content.begin(), content.end());
    			if ( tmp=="." ){
    				content.clear();
    			}
    			else if ( tmp==".." ){
    				if ( !sta.empty() )
    				{
    					sta.pop();
    				}
    			}
    			else{
    				sta.push(tmp);
    			}
    			content.clear();
    		}
    	}
    	// recover the path
    	if ( sta.empty() ) return "/";
    	while ( !sta.empty() )
    	{
    		ret = "/" + sta.top() + ret;
    		sta.pop();
    	}
    	return ret;
    }
};
int main(int argc, char const *argv[])
{
	string path = "/a/./b/../../c/";
	cout << Solution::simplifyPath(path) << endl;
	return 0;
}