//
//  main.cpp
//  歌手
//
//  Created by s20181105880 on 2019/6/19.
//  Copyright ? 2019 。. All rights reserved.
//
#include <stdio.h>
#include <iostream>
#include <fstream>
#include <string>
using namespace std;
struct Referee{
	string name[7];
	int score;
};
/*class Referee{
public:
Referee(string name,int score):name(name),score(score){}
    friend ostream& operator << (ostream&,const Referee&);
private:
    string name;
    int score;
};
/*ostream& operator << (ostream&,const cp& s){
    os<<s.name<<' '<<s.score<<endl;
    
}*/
int main() {
    //Referee stu[]={Referee("1",90),Referee("2",90),Referee("3",90),Referee("4",90),Referee("5",90),Referee("6",90),Referee("7",90)};
    ofstream out("/Users/s20181105880/Desktop/裁判.txt");
    //out<<stu[0]<<stu[1]<<stu[2];
    out.close();
    ofstream gg("/Users/s20181105880/Desktop/歌手.txt");//
    ifstream GG("/Users/s20181105880/Desktop/歌手的副本.txt");//
    if(out.is_open()){
        //out<<stu[0]<<stu[1]<<stu[2];
        out.close();    }
    if(GG.is_open())//写入文件
    {
        int i;
        int a[7];
        for(i=0;i<7;i++)
        {
            GG>>a[i]; //7个裁判分数
        }
        /*for(i=0;i<7;i++)
        {
            cout<<a[i]<<endl;//输出7个分数
        }*/
        GG.close();
    }
    if (gg.is_open())//读的文件
    {
               gg.close();
    }
    
    
    return 0;
}
