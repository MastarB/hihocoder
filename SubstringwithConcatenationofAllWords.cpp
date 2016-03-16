#include<iostream>
#include<map>
#include<vector>
#include<string> 
using namespace std;

class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words)
	{
		map<string,int>wordss;
		vector<int>ans;
    	for(int i = 0; i<words.size(); i++)
    	{
			if(wordss.find(words[i])== wordss.end())
				wordss[words[i]]=1;
			else	wordss[words[i]]++;
		}
    	int wordl = words[0].size();
    	int l = wordl*words.size();
    	//the return type of method "size()" is unsigned_int type which is also the return type of operator "sizeof" 
    	//cout<<s.size()<<endl;
    	//cout<<l<<endl;
    	//cout<<s.size()-l<<endl;
    	for(int i = 0; i < s.size()-l+1; i++)
		{	
			if(findall(s,wordss,i,wordl))
				ans.push_back(i);
		}
		return ans;
	}
	
	bool findall(string& s, map<string,int>&wordss, int cout, int wordl)
    {
    	if(wordss.empty())return true;
    	bool ans;
    	string temp;
    	map<string,int>::iterator isFound = wordss.find(s.substr(cout,wordl));
    	if(isFound != wordss.end())
    	{
    		
    		temp = (*isFound).first;
    		(*isFound).second--;
    		if((*isFound).second ==0)wordss.erase(isFound);
    		
    		ans = findall(s,wordss,cout+wordl,wordl);
    			
    		map<string,int>::iterator insertback = wordss.find(temp);
			if(insertback != wordss.end())
				(*insertback).second++;
			else wordss[temp] = 1;
    		return ans;
		}
		else return false;
	}	
    
    
    
};

int main()
{
		string s("a");
		vector<string>words;
		words.push_back("a");
		words.push_back("a");
		Solution so;
		vector<int>ans = so.findSubstring(s,words);
		//for(int i =0; i< ans.size(); i++)
		//	cout<<ans[i]<<' ';
}
