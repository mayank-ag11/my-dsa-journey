#include <algorithm>
#include <sstream>
#include <iostream>
#include <vector>
#include <string>

using std::vector;
using std::string;

int isGreaterOrEqual(string digit, string max)
{
  if(digit==max)
   return 1;

  string l = digit + max;
  string r = max + digit;

  for(int i=0; i<l.size(); i++)
  {
      if((l[i]-'0') > (r[i]-'0'))
        return 1;
      else if((l[i]-'0') < (r[i]-'0'))
        return 0;
  }
  return 1;
}
/* this method doesn't work for fn(121,12) / fn(85,858)
int isGreaterOrEqual(string digit, string max)
{
  if(digit==max)
   return 1;

  if(digit.size()<=max.size())
  {
    int i=0,j=0;
    while(j<max.size())
    {
      if(i==digit.size())
       i = 0;
      if(digit[i]-'0'>max[j]-'0')
       return 1;
      else if(digit[i]-'0'<max[j]-'0')
       return 0;

      i++;
      j++;
    }
    return 0;
  }
  else
  {
    int i=0, j=0;
    while(i<digit.size())
    {
      if(j==max.size())
       j = 0;
      if(digit[i]-'0'>max[j]-'0')
       return 1;
      else if(digit[i]-'0'<max[j]-'0')
       return 0;

      i++;
      j++;
    }
    return 1;
  }
  return 0;
} */
string largest_number(vector<string> a) {
  
  std::stringstream ret;

  for(size_t i = 0; i < a.size(); i++) {
    string max = "0";
    int max_index = 0;
    for(size_t j = 0; j < a.size(); j++)
    {
      if(isGreaterOrEqual(a[j], max))
      {
	max = a[j];
	max_index = j;
      }
    }
    ret << max;
    a[max_index] = "0";
  }

  string result;
  ret >> result;
  return result;
}

int main() {
  int n;
  std::cin >> n;
  vector<string> a(n);
  for (size_t i = 0; i < a.size(); i++) {
    std::cin >> a[i];
  }
  string l = largest_number(a);
  std::cout << l << "\n";
}
