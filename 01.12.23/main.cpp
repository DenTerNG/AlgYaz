#include <cmath>
#include <cstddef>
#include <fstream>
#include <ios>
#include <iostream>
#include <string>
#include <sstream>
#include <vector>

using namespace std;

struct Book{
  string name;
  int x;
  int y;
};


int main() {
  int x;
  int y;
  std::vector<Book> vt;
  for(int i = 0; i < 10; ++i){
    Book bk;
    cin>>bk.x>>bk.y;
    vt.at();
  }
    //Book bk;

  string strr = "test1 for;test";
  string str1;
  istringstream ss(strr);
  getline(ss, str1, ' ');
  cout<<str1<<endl;
  getline(ss, str1);
  cout<<str1<<endl;
  while(ss>>str1){
    cout<<str1<<endl;
  }
  //ss.

  ofstream out("test.txt", ios::app);
  ofstream out1;
  out1.open("test1.txt", ios::app);
  //ifstream in("test.txt");
  //fstream fin("test.txt");  // Нормальная тема +rep !?*

  if(!out.is_open()){
    cout<<"can't open file"<<endl;
  }

  for(int i = 0; i < 10; ++i){
    out<<i<<endl;
  }

  //out<<name<<" "<<year<<" "<<"autrhor"<<endl;

  out.close();

  ifstream in("test.txt", ios::in | ios::ate);
  string str;
  char a;
  if(in.is_open()){
    while(getline(in, str)){
      cout<<str;
    }
  }else{
    cout<<"file cant open"<<endl;
  }

  fstream fin("test12.txt", ios::out | ios::in | ios::app);


  return 0;
}
=