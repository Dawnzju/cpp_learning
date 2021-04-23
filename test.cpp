#include<iostream>
#include<algorithm>
#include<cmath>
#include<string>
using namespace std;
string a[20];
long long int sltoshi(string str)//十六进制转换位十进制 
{
    long long int sum1=0;
    int len=str.length();
    int j=0;
    for(j=0;j<len;j++)
    {
       if(str[j]>='A')
       {
      sum1+=(str[j]-'A'+10)*(pow(16,len-1-j));
    }
    else
    {
     sum1+=(str[j]-'0')*(pow(16,len-1-j));
    }
    }
    cout<<sum1<<endl;
    return sum1;
} 
void shitoba(long long int s)//十进制转8进制 
{
 string ve="";
 int i=0;
 int count=0;
 while(s>=8)
 {
  ve+=(s%8+'0');
  s=s/8;
  cout<<s<<endl;
 } 
 cout<<ve<<endl;
 ve+=s+'0';
 reverse(ve.begin(),ve.end());
 cout<<ve<<endl;
 for(i=0;i<ve.length();i++)
 cout<<ve[i]<<endl;
}
int main()
{
 int n;
 cin>>n;
 int i=0;
 for(i=0;i<n;i++)
 {
  cin>>a[i];
 }
 long long int sum=0;
 for(i=0;i<n;i++)
 {
   sum=sltoshi(a[i]);
   shitoba(sum);
   cout<<"here"<<endl;
 }
 return 0;
}
