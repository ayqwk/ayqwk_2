#include<iostream>
#include<fstream>
#include<stdio.h>
#include<string>
#include<string.h>
#include<vector>
#include<map>
using namespace std;

struct Node{
  string name, id;
};

int main(int argc, char* argv[]){
  if(argc < 3){
    cout << "请输入文件名" << endl;
    return 0;
  }
  //打开读入文件
  ifstream infile;
  infile.open(argv[1]);
  if(!infile){
    cout << "打开文件失败" << endl;
    return 0;
  }

  //打开输出文件
  ofstream outfile;
  outfile.open(argv[2]);
  if(!outfile){
    cout << "打开文件失败" << endl;
    return 0;
  }

  //读入文件内容
  string s;
  vector<string>vec, pro;
  while(infile >> s){
    vec.push_back(s);
  }

  //实现分类
  map<string, vector<Node> >mp;
  int cnt = vec.size();
  for(int i = 0; i < cnt; i += 3){
    if(mp[vec[i]].size() == 0) pro.push_back(vec[i]);
    mp[vec[i]].push_back({vec[i+1], vec[i+2]});
  }

  //输出到文件
  if(argc == 4){ //如果参数有4个，即带有省份，则只输出该省份的城市
    string t;
    int len = strlen(argv[3]);
    for(int i = 0; i < len; i++) t.push_back(argv[3][i]);
    outfile << t << endl;
    for(Node i : mp[t]) outfile << i.name << " " << i.id << endl;
  }
  else{ //否则全部输出
    for(string i : pro){
      outfile << i << endl;
      for(Node j : mp[i]){
        outfile << j.name << " " << j.id << endl;
      }
      outfile << endl;
    }
  }
  infile.close();
  outfile.close();
  cout << "操作成功!" << endl;
  return 0;
}