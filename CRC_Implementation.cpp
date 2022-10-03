/**
Implementation of CRC ERROR DETECTION MODEL
**/
#include<bits/stdc++.h>
using namespace std;

class CRC{
    string input,divisor,dividend,result;
    int len_dividend,len_divisor,len_input;

public:
    string fun_xor(string a,string b){
        string result="";
        if(a[0]=='0'){
            return a.substr(1);
        }else{
           for(int i=0;i<len_divisor;i++){
            result += (a[i]==b[i] ? '0' : '1');
           }
           return result.substr(1);
        }
    }
    void division(){
        string temp_divisor=divisor;
        string temp_dividend=dividend.substr(0,len_divisor);
        int j=len_divisor;
        while(j<len_dividend){
            temp_dividend = fun_xor(temp_dividend,temp_divisor);
            temp_dividend += dividend[j];
            j++;
        }
        result = input + fun_xor(temp_dividend,temp_divisor);
        cout<<"\n CRC : "<<fun_xor(temp_dividend,temp_divisor)<<endl;
    }
    void getData(){
        cout<<"\n Enter input : ";
        cin>>input;
        cout<<"\n Enter divisor : ";
        cin>>divisor;
        len_divisor = divisor.length();
        len_input = input.length();
        dividend = input;
        for(int i=0;i<len_divisor-1;i++){
            dividend += '0';
        }
        len_dividend = dividend.length();
        division();
    }
    void senderSide(){
        cout<<"\n Input : "<<input<<endl;
        cout<<"\n Divisor : "<<divisor<<endl;
        cout<<"\n Dividend : "<<dividend<<endl;
        cout<<"\n Data to be sent : "<<result<<endl;
    }

    void receiverSide(){
        string data_rcv;
        cout<<"\n Enter Received Data : ";
        cin>>data_rcv;

        string temp_divisor=divisor;
        string temp_dividend=data_rcv.substr(0,len_divisor);
        int j=len_divisor;
        while(j<data_rcv.length()){
            temp_dividend = fun_xor(temp_dividend,temp_divisor);
            temp_dividend += data_rcv[j];
            j++;
        }
        string error = fun_xor(temp_dividend,temp_divisor);

        cout<<"\n Remainder : "<<error<<endl;
        ///checking  weather error is occurred or not
        bool flag=0;
        for(int i=0;i<len_divisor-1;i++){
            if(error[i]=='1'){
                flag=1;
                break;
            }
        }
        if(flag){
            cout<<"\n Data is received with ERROR."<<endl;
        }
        else{
            cout<<"\n Data is received with NO ERROR."<<endl;
        }

    }
};


int main(){
    CRC crc;
    crc.getData();
    crc.senderSide();
    crc.receiverSide();
    return 0;
}














