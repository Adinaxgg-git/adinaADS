#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
struct Date{
    int day,month,year;
    string original;
};
bool cmp(Date a, Date b){
    if(a.year!=b.year){
        return a.year<b.year;
    }
    if(a.month!=b.month){
        return a.month<b.month;
    }
    return a.day<b.day;
}
int main(){
    int n;
    cin>>n;
    vector<Date> dates(n);
    for(int i=0;i<n;i++){
        cin>>dates[i].original;
        dates[i].day=stoi(dates[i].original.substr(0,2));
        dates[i].month=stoi(dates[i].original.substr(3,2));
        dates[i].year=stoi(dates[i].original.substr(6,4));
    }
    sort(dates.begin(),dates.end(),cmp);
    for(int i=0;i<n;i++){
        cout<<dates[i].original<<'\n';
    }
    return 0;
}