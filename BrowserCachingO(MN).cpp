#include<iostream>
#include<map>
#include<list>
#include<string>
using namespace std;
void refresh(list<string>& qu, string d)
{
	qu.remove(d);	
	qu.push_back(d);
}


int main()
{
	
	map<string,bool>logs;
	list<string>qu;
	int size;
	int m ;
	int n;
	string temp;
	while(cin>>n>>size)
  {
  	m = 0;
  	logs.clear();
  	qu.clear();
	while(n--)
	{
		cin>>temp;
		if(logs[temp] == true)
		{
			refresh(qu,temp);
			cout<<"Cache"<<endl;
		}
		
		else if(m == size)
		{
			string disc =  qu.front();
			qu.pop_front();
			logs[disc] = false;
			logs[temp] = true;
			qu.push_back(temp);
			cout<<"Internet"<<endl;
		}
		
		else if(m < size)
		{
			logs[temp] = true;
			qu.push_back(temp);
			m++;
			cout<<"Internet"<<endl;	
		}	
	}
  }
}
