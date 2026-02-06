//?? 真题 3：跑步锻炼 (2020 省赛)
//【题目描述】 小蓝每天都锻炼身体。 正常情况下，小蓝每天跑 1 千米。 但是，如果某天是 周一 或者 月初（1号），为了激励自己，他会跑 2 千米。 （注意：如果这一天既是周一又是 1 号，他也只跑 2 千米，不会叠加成 4 千米，也不会是 3 千米，就是 2 千米）。
//
//时间范围：从 2000年1月1日 到 2020年10月1日（包含这两天）。 已知：2000年1月1日是 周六。
//
//请问：这段时间小蓝总共跑了多少千米？
#include<iostream>
using namespace std;
//闰年是2000，2004，2008，2012，2016，2020，共 6年
//平年有15年 
bool isrun(int year){
	if(year%4==0){
	return true;
}else{
	return false;
}
	} 
int su(){

	int year=2000;
	int month=1;
	int day=1;
	int count=0;
	int monthday[13]={0,31,28,31,30,31,30,31,31,30,31,30,31};
	int monthday2[13]={0,31,29,31,30,31,30,31,31,30,31,30,31};
	int weekday=6;
while(1){
	while(year<=2020){
		if(isrun(year)){		
		while(month<=12){
			while(day<=monthday2[month]){
				if(day==1&&month==10&&year==2020) return count;
			
				count++;
	if(weekday==1||day==1){
					count++;
				}

				if(weekday==7){
					weekday=1;
				}
				else{
					weekday++;
				}
				day++;
			}
			month++;
			day=1;		
		}
		year++;
		month=1;}
		else{
		while(month<=12){
			while(day<=monthday[month]){
				if(day==1&&month==10&&year==2020) return count;
			
				count++;
				if(weekday==1||day==1){
					count++;
				}

				if(weekday==7){
					weekday=1;
				}
				else{
					weekday++;
				}
				day++;
			}
			month++;
			day=1;
		
		}
		year++;
		month=1;}	
	}	
	
}	
}
int main(){
	int x=su();
	cout<<x+2;
}