//
//  main.cpp
//  cellular
//
//  Created by 陈晓轩 on 2019/9/4.
//  Copyright © 2019 陈晓轩. All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <fstream>
#include <string>

#define oldage 50
#define users 10000000//百万

using namespace std;
char buf[200];
char loc[100]="/Users/chenxiaoxuan/Documents/MATLAB/4/";
int sec[users];

void convert(){
    ifstream srcfile(strcat(loc, "11.txt"),ios::in);
    if(!srcfile){
        cout<<"file not found"<<endl;
    }
    ofstream destfile(strcat(loc, "11.dat"),ios::out|ios::binary);
    int x,a,b,c;
    long long d;
    int i=0;
    char y;
    while(true){
        if(i%14==0){
            if(srcfile>>x){
                destfile.write((const char*)&x, sizeof(int));
            }else{
                break;
            }
        }else if(i%14==9){
            srcfile>>a>>y>>b>>y>>c;
            x=10000*a+100*b+c;
            destfile.write((const char*)&x,sizeof(int));
        }else if(i%14==10){
            srcfile>>a>>y>>b>>y>>c;
        }else if (i%14==2) {
            srcfile>>y;
            if (y==121) {
                srcfile>>d;
                d=-d;
                destfile.write((const char*)&d, sizeof(long long));
            }else{
                srcfile.seekg(-1,ios::cur);
                srcfile>>d;
                destfile.write((const char*)&d, sizeof(long long));
            }
            cout<<d;
        }else if(i%14==13){
            srcfile>>x;
            destfile.write((const char*)&x, sizeof(int));
            //去除片尾
            srcfile.getline(buf, 200);
        }else{
            srcfile>>x;
            destfile.write((const char*)&x, sizeof(int));
        }
        ++i;
    }
    destfile.close();
    srcfile.close();
};
//需要python对文件预处理
void age50(){
    ifstream srcfile(strcat(loc, "1.txt"),ios::in);
    if(!srcfile){
        cout<<"file not found"<<endl;
    }
    int i=0;
    int x,phone;
    char y;
    while (true) {
        if(i%5==0){
            if(!(srcfile>>phone)){
                cout<<phone<<endl;
                break;
            }
        }else if(i%5==3){
            srcfile>>y;
        }else if(i%5==4){
            srcfile>>x;
            if ((srcfile>>x)&&(x>=oldage)) {
                sec[phone]=1;
            }
            //去除片尾
            srcfile.getline(buf, 200);
        }else{
            srcfile>>x;
        }
        ++i;
    }
    cout<<i;
    srcfile.close();
}

class record{
public:
    int x1;
    int x2;//叫方号码
    long long d;
    int x[10];//x[0]是祝叫运营商，2主叫号码归属
};

int main(int argc, const char * argv[]) {
    // insert code here...
    
    age50();
    
    /*
    //文件源
    ifstream infile(strcat(loc, "11.dat"),ios::in|ios::binary);
    if(!infile){
        cout<<"file not found"<<endl;
    }
    //遍历每条记录
    record rec;
    while (infile.read((char*)&rec,sizeof(rec))) {
        
        //位置条件
        if ((rec.x[2]==rec.x[4])&&(rec.x[4]!=rec.x[5])){
            sec[rec.x2]+=rec.x[7];
        }
    }
    infile.close();*/
    return 0;
}
