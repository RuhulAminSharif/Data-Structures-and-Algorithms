#include<bits/stdc++.h>
using namespace std;
bool isDigit( char ch ) {
  if( ch >= '0' && ch <= '9' ) {
    return true;
  }
  return false;
}
int Atoi(string& s ) {
  int idx = 0, len = s.size();
  int sign = 1;
  while( idx < len && s[idx] == ' ' ) {
    idx += 1;
  }
  if( idx < len && ( s[idx] == '+' || s[idx] == '-' ) ) {
    sign = s[idx] == '+' ? 1 : -1; 
    idx += 1;
  }
  bool foundDigit = false;
  long long x = 0;
  while( idx < len && isDigit( s[idx] ) ) {
    foundDigit =  true;
    x = x * 10 + ( s[idx] - '0' );
    if( sign == 1 && x > INT_MAX ) return INT_MAX;
    if( sign == -1 && -x < INT_MIN ) return INT_MIN; 
    idx += 1;
  }
  if( foundDigit == false ) return 0;
  return (int)( sign * x );
}
int main()
{
  string s = "-123";
  cout << Atoi(s) << endl;
  s = "   -";
  cout << Atoi(s) << endl;
  s = "12312312313111133";
  cout << Atoi(s) << endl;
  s = "-999999999999";
  cout << Atoi(s) << endl;
  s = "    -0012gfg4";
  cout << Atoi(s) << endl;
}

// https://www.geeksforgeeks.org/problems/implement-atoi/1 