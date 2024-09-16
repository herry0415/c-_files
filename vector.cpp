#include<iostream> 
#include<vector>  //标准头文件
#include<bits/stdc++.h>
using namespace std;
int main()
{
  vector<int> v1(10); //内置类型 
  vector<double> v2; //内置类型
  vector<string> v3(10); //自定义类型
  vector<vector<int>> v4(10); //自定义类型
  v2.push_back(1);
  v2.push_back(2);
  v2.push_back(3);
  v2.resize(10,7);
  vector<double>::iterator it;
  for(it = v2.begin();it != v2.end();it ++)
  cout<<*it<<" ";
  v2.insert(v2.begin()+1,-1);
  v2.insert(v2.end(),-2);
  cout<<"v1.size: "<<v1.size()<<endl;
  for(int i=0;i<v1.size();i++) cout<<v1[i]<<" ";cout<<endl;
  
  //遍历方式二  迭代器遍历
  cout<<"v2.size: "<<v2.size()<<endl;
  for(it = v2.begin();it != v2.end();it ++)
  cout<<*it<<" ";
  cout<<endl;
  it = find(v2.begin(),v2.end(),2);
  if(it!=v2.end()) v2.erase(it);

  //遍历方式三  for+迭代器
  for(auto t : v2){
  	 cout<<t<<" ";
  }
  cout<<endl;
  for(int i=0;i<v2.size();i++) cout<<v2[i]<<" ";
  cout<<endl;
  return 0;
}