    
//
//  main.cpp
//  歌手
//
//  Created by s20181105880 on 2019/6/19.
//  Copyright ? 2019 。. All rights reserved.
#define STUDENTNUMBER 6
#define REFEREENUMBER 7
#include <stdio.h>
#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
using namespace std;
struct Referee{
    string Name;
    double Grade[STUDENTNUMBER];
}referee[REFEREENUMBER];
struct Student{
    string Number;
    string Name;
    string College;
    string Sex;
    double Grades[REFEREENUMBER];
    double Sum=0;
}student[STUDENTNUMBER];
bool judge(Student &Object1,Student &Object2)
{
    if(Object1.Sum>Object2.Sum)
        return true;
    else
        return false;
}
int main()
{   int i=0;
    ifstream Refereein("/Users/s20181105880/Desktop/裁判.txt");
    ifstream Studentin("/Users/s20181105880/Desktop/学生.txt");
    ofstream OutputAchievements("/Users/s20181105880/Desktop/输出.xls");
    if(Refereein.is_open())//裁判输入
    {
        while(!Refereein.eof() && i<REFEREENUMBER)
        {
            Refereein>>referee[i].Name;
            for(int k=0;k<STUDENTNUMBER;k++)
            {
                Refereein>>referee[i].Grade[k];
            }
            i++;
        }
        Refereein.close();
    }
    i=0;
    if (Studentin.is_open())//参赛者输入
    {
        while(!Studentin.eof() && i<STUDENTNUMBER)
        {
            Studentin>>student[i].Number;
            Studentin>>student[i].Name;
            Studentin>>student[i].Sex;
            Studentin>>student[i].College;
            i++;
        }
        Studentin.close();
    }
    for(int i=0;i<STUDENTNUMBER;i++)
    {
        for(int j=0;j<REFEREENUMBER;j++)
            student[i].Grades[j]=referee[j].Grade[i];
        double Midnumber=0;
        for(int k=0;k<REFEREENUMBER-1;k++)
        {
            for(int j=0;j<REFEREENUMBER-1;j++)
            {
                if(student[i].Grades[j]>student[i].Grades[j+1])
                {
                    Midnumber=student[i].Grades[j];
                    student[i].Grades[j]=student[i].Grades[j+1];
                    student[i].Grades[j+1]=Midnumber;
                }
            }
        }
        for(int k=1;k<STUDENTNUMBER;k++)
            student[i].Sum+=student[i].Grades[k];
            student[i].Sum=student[i].Sum/(REFEREENUMBER-2);
    }
    sort(student,student+STUDENTNUMBER,judge);
    for(int i=0;i<STUDENTNUMBER;i++)
    {
        OutputAchievements<<student[i].Number;
        OutputAchievements<<" "<<student[i].Name;
        OutputAchievements<<" "<<student[i].Sex;
        OutputAchievements<<" "<<student[i].College;
        OutputAchievements<<" "<<student[i].Sum;
        OutputAchievements<<endl;
    }
    return 0;
}
