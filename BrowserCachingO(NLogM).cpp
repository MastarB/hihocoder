#include<iostream>
#include<map>
#include<list>
#include<string>
using namespace std;
void refresh(list<string>& qu, list<string>::iterator& d)
{
	qu.push_back(*d);
	qu.erase(d);
	d = --qu.end();
	
}


int main()
{
	
	map<string,list<string>::iterator>logs;
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
		if(logs.find(temp) != logs.end())
		{
			refresh(qu,logs[temp]);
			cout<<"Cache"<<endl;
		}
		
		else if(m == size)
		{
			string disc =  qu.front();
			qu.pop_front();
			logs.erase(disc);
			qu.push_back(temp);
			logs[temp] = --qu.end();
			cout<<"Internet"<<endl;
		}
		
		else if(m < size)
		{
			qu.push_back(temp);
			logs[temp] = --qu.end();
			m++;
			cout<<"Internet"<<endl;	
		}	
	}
  }
}

