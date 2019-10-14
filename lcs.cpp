#include<bits/stdc++.h>

using namespace std;

int lcs(string s, string t)
{
  int len1 = s.size();
  int len2 = t.size();

  int arr[len1+1][len2+1];
  memset(arr,0,sizeof arr);
  int ans =0;

  for(int i=1;i<=len1;i++)
  {
    for(int j =1;j<=len2;j++)
    {
      if(s[i-1] == t[j-1])
        arr[i][j] = arr[i-1][j-1] +1;
      else
        arr[i][j] = max(arr[i-1][j],arr[i][j-1]);

      ans = max(ans, arr[i][j]);
    }
  }

  return ans;
}


int main()
{
 string s,t;
 cin>>s>>t;

 cout<<lcs(s,t);

 return 0;
}
