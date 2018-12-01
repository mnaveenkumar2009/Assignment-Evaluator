#include <bits/stdc++.h>
#define f(i,n) for(i=0;i<n;i++)
#define ld long double
using namespace std;
#define ll long long
string str(ll i){
    string s;
    s.push_back('0'+i);
    return s;
}

int main(){
    string s;
    ifstream noq("teacher/noq.txt");
    int n,i;
    noq>>n;
    int total=0,totalmarks=0;
    f(i,n){
        ifstream marks("teacher/marks"+str(i)+".txt");
        int marki,mark;
        marks>>marki;
        totalmarks+=marki;
        ifstream mism("mismatchs/"+str(i)+".txt");
        mism>>mark;
        if(mark)continue;
        mark=0;
        ifstream expans("teacher/answer"+str(i)+".txt");
        ifstream studans("student/answer"+str(i)+".txt");
        // unordered_map <string,bool> xyz;
        vector <string> abcd;
        while(studans>>s){
            int h;
            f(h,s.length()){
                s[h]=tolower(s[h]);
            }
            // cout<<s<<'\n';
            if(s.length()>=3&&s!="the"){
                abcd.push_back(s);
            }
        }
        int match=0;
        sort(abcd.begin(),abcd.end());
        while(expans>>s){
            int h;
            f(h,s.length()){
                s[h]=tolower(s[h]);
            }
            // cout<<s<<'\n';
            if(s.length()>=3&&s!="the"){
                if(binary_search(abcd.begin(),abcd.end(),s))
                    match++;
            }
        }
        // cout<<match<<'\n';
        // cout<<abcd.size()<<'\n';
        if((ld)match/(ld)abcd.size()>=0.5){
            total+=marki;
        }
    }
    cout<<"Marks obtained by the student is\n"<<total<<'/'<<totalmarks<<'\n';
}