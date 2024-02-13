#include<bits/stdc++.h>
using namespace std;
int Min(int a,int b)
{
    return (a>b) ? a : b;
}
int findOverlappingPair(string str1,string str2,string& str)
{
    int Max=INT_MIN;
    int len1=str1.size();
    int len2=str2.size();
    for(int i=0;i<=min(len1,len2);i++)
    {
        if(str1.compare(len1-i,i,str2,0,i)==0)
        {
            if(Max<i)
            {
                Max=i;
                str=str1+str2.substr(i);
            }
        }
    }
     for(int i=0;i<=min(len1,len2);i++)
    {
        if(str1.compare(0,i,str2,len2-i,i)==0)
        {
            if(Max<i)
            {
                Max=i;
                str=str1+str2.substr(i);
            }
        }
    }
    return Max;
}
string findShortestSuperstring(string arr[],int len)
{
    while(len!=1)
    {
        int Max=INT_MIN;
        int l,r;
        string resStr;
        for(int i=0;i<len;i++)
        {
            for(int j=i+1;j<len;j++)
            {
                string str;
               int res = findOverlappingPair(arr[i],arr[j],str);
               if(Max<res)
               {
                   Max=res;
                   resStr.assign(str);
                   l=i,r=j;
               }
            }
        }
        len--;
        if(Max==INT_MIN)
        {
            arr[0]+=arr[len];
        }
        else
        {
            arr[l]=resStr;
            arr[r]=arr[len];
        }
    }
    return arr[0];
}
int main()
{
    string arr[] = {"catgc", "ctaagt",
                    "gcta", "ttca", "atgcatc"};
    int len = sizeof(arr)/sizeof(arr[0]);

    // Function Call
    cout << "The Shortest Superstring is "
         << findShortestSuperstring(arr, len);

    return 0;
}
