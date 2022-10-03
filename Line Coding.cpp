#include<bits/stdc++.h>
using namespace std;
void NRZ(string s)
{
    cout<<"Graph for NRZ\n";
    int lst=(s[0]-'0')^1;
    string ans1="";
    string ans2="";
    for(char cc:s)
    {
        int cur=cc-'0';
        if(lst^cur)
            {
                ans1+=" ";
                ans2+="|";
            }
        if(cur==0)
        {
            ans1+="  ";
            ans2+="__";
        }
        else
        {
            ans1+="__";
            ans2+="  ";
        }
        lst=cur;
    }
    cout<<ans1<<"\n";
    cout<<ans2<<"\n\n";
}
void NRZL(string s)
{
    cout<<"Graph for NRZ-L\n";
    int lst=(s[0]-'0')^1;
    string ans1="";
    string ans2="";
    string ans3="";
    for(char cc:s)
    {
        int cur=cc-'0';
        if(lst^cur)
            {
                ans1+=" ";
                ans2+="|";
                ans3+="|";
            }
        if(cur==1)
        {   ans1+="  ";
            ans2+="  ";
            ans3+="__";
        }
        else
        {
            ans1+="__";
            ans2+="  ";
            ans3+="  ";
        }
        lst=cur;
    }
    cout<<ans1<<"\n";
    cout<<ans2<<"\n";
    cout<<ans3<<"\n\n";
}
void Manchester(string s)
{
    cout<<"Graph for Manchester\n";
    int lst=(s[0]-'0')^1;
    string ans1="";
    string ans2="";
    string ans3="";
    for(char cc:s)
    {
        int cur=cc-'0';
        if(lst==cur)
            {
                ans1+=" ";
                ans2+="|";
                ans3+="|";
            }
        if(cur==1)
        {   ans1+="   __";
            ans2+="  |  ";
            ans3+="__|  ";
        }
        else
        {
            ans1+="__   ";
            ans2+="  |  ";
            ans3+="  |__";
        }
        lst=cur;
    }
    cout<<ans1<<"\n";
    cout<<ans2<<"\n";
    cout<<ans3<<"\n\n";
}
void dManchester(string s)
{
    cout<<"Graph for dManchester\n";
    int lst;
    string ans1=" ";
    string ans2="|";
    string ans3="|";
    if(s[0]=='0')
    {
        ans1+="   __";
        ans2+="  |  ";
        ans3+="__|  ";
        lst=1;
    } 
    else
    {
        ans1+="__   ";
        ans2+="  |  ";
        ans3+="  |__";
        lst=0;
    }
    for(int i=1;i<s.size();i++)
    {
        char cc=s[i];
        int cur=cc-'0';
        if(!cur)
            {
                ans1+=" ";
                ans2+="|";
                ans3+="|";
            }
        if(cur^lst)            
        {  
            ans1+="   __";
            ans2+="  |  ";
            ans3+="__|  ";
            lst=1;
        }
        else
        {
            ans1+="__   ";
            ans2+="  |  ";
            ans3+="  |__";
            lst=0;
        }
    }
    cout<<ans1<<"\n";
    cout<<ans2<<"\n";
    cout<<ans3<<"\n\n";
}
int main()
{
    string s;
    cin>>s;
    NRZ(s);
    NRZL(s);
    Manchester(s);
    dManchester(s);
} 