#include<bits/stdc++.h>

using namespace std;

string fiveprobability,fourprobability,threeprobability,increaseprobaility,increasetime,fourguaranteed,lanauage;

double fivep,fourp,threep,increasep;

int increaset,fourpt,five=0,four=0,three=0;

string extraction(string s,string a,string b,int times=1){
    if(times==1) return s.substr(s.find(a)+1,s.find(b)-s.find(a)-1);
    else return extraction(s.substr(s.find(b)+1,s.length()),a,b,--times);
}

void readText(string file)
{
    ifstream infile; 
    infile.open(file.data());
    assert(infile.is_open());
    string s;
    int k=0;
    while(getline(infile,s))
    {
        k++;
        switch(k){
            case 4:
                fiveprobability=extraction(s,"[","]");
            case 5:
                fourprobability=extraction(s,"[","]");
            case 6:
                threeprobability=extraction(s,"[","]");
            case 9:
                increasetime=extraction(s,"[","]");
                increaseprobaility=extraction(s,"[","]",2);
            case 10:
                fourguaranteed=extraction(s,"[","]");
            case 13:
                lanauage=extraction(s,"[","]");
        } 
    }
    infile.close();     
}

int stringswitchint(string s){
    int temp=1,ans=0;
    for(int i=s.length()-1;i>=0;i--){
        ans+=temp*(s[i]-'0');
        temp*=10;
    }
    return ans;
}

double stringswitchdouble(string s){
    double ans=0;
    int temp=1;
    if(s.find("%")==string::npos){
        for(int i=s.find(".")-1;i>=0;i--){
            ans+=temp*(s[i]-'0');
            temp*=10;
        }
        double tans=0;
        temp=1;
        for(int i=s.length()-1;i>s.find(".");i--){
            tans+=temp*(s[i]-'0');
            temp*=10;
        }
        tans*=pow(0.1,s.length()-s.find(".")-1);
        ans+=tans;
        if(ans*pow(10,5)>=1) return ans;
        else return pow(0.1,5);
    }else{
        s=s.substr(0,s.length()-1);
        for(int i=s.find(".")-1;i>=0;i--){
            ans+=temp*(s[i]-'0');
            temp*=10;
        }
        double tans=0;
        temp=1;
        for(int i=s.length()-1;i>s.find(".");i--){
            tans+=temp*(s[i]-'0');
            temp*=10;
        }
        tans*=pow(0.1,s.length()-s.find(".")-1);
        ans+=tans;
        if(ans*pow(10,3)>=1) return ans*0.01;
        else return pow(0.1,5);
    }
}

void newswitch(){
    fivep=stringswitchdouble(fiveprobability);
    fourp=stringswitchdouble(fourprobability);
    threep=stringswitchdouble(threeprobability);
    increasep=stringswitchdouble(increaseprobaility);
    increaset=stringswitchint(increasetime);
    fourpt=stringswitchint(fourguaranteed);
}

int lanauagechoose(){
    if(lanauage=="zh-cn") return 1;
    else return 2;
}

void judgment1(){
    if(fivep+fourp+threep!=1||increasep>1||increaset<0||fourpt<0){
        cout<<"你输入的概率数据不正确，请仔细阅读配置文件中的提示"<<endl;
        exit(0);
    }
}

void judgment2(){
    if(fivep+fourp+threep!=1||increasep>1){
        cout<<"Your probability data is not entered correctly, please read the tips in the setting file carefully"<<endl;
        exit(0);
    }
}

void statistics(){
    cout<<"你抽到的:"<<endl;
    cout<<"5星:"<<five<<"个"<<endl;
    cout<<"4星:"<<four<<"个"<<endl;
    cout<<"3星:"<<three<<"个"<<endl;
}

void clear(){
    five=0;
    four=0;
    three=0;
    cout<<"数据已清空"<<endl;
}

void sweepstakes(int times=1){
    int sum=100000;
    srand(time(NULL));
    int number=number=(rand()%sum)+1;
    cout<<"获得:"<<endl;
    while(times--){
        number=(rand()%sum)+1;
        if(number>=1&&number<=sum*fivep) cout<<"5星",five++;
        else if(number<=sum&&number>=(sum-(fourp*sum))) cout<<"4星",four++;
        else cout<<"3星",three++;
        if(times!=0) cout<<",";
    }
    cout<<endl;
}

void m(){
    judgment1();
    int options;
    cout<<"现在的概率为："<<endl<<"5星获取概率："<<fivep*100<<"%"<<endl<<"四星获取概率："<<fourp*100<<"%"<<endl<<"三星获取概率："<<threep*100<<"%"<<endl<<fourpt<<"抽内必定获取到四星角色"<<endl<<"若从第"<<increaset<<"抽之前都没有获取到5星角色，则接下来每次获取5星的概率提升"<<increasep*100<<"%"<<endl<<"接下来请选择:"<<endl<<"1.抽取一次"<<endl<<"2.抽取十次"<<endl<<"3.数据统计"<<endl<<"4.清空数据"<<endl<<"其他.退出程序"<<endl;
    while(cin>>options){
        switch(options){
            case 1:
                sweepstakes();
                continue;
            case 2:
                sweepstakes(10);
                continue;
            case 3:
                statistics();
                continue;
            case 4:
                clear();
                continue;
            default:
                exit(0);
        }
    }
}

int main(){
    readText("setting.in");
    newswitch();
    m();
    return 0;
}
