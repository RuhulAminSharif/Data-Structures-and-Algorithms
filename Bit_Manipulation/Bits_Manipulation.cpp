#include<bits/stdc++.h>
using namespace std; 
/// To set the i-th bit of a number
void setBit( int &num, int i )
{
    num |= ( 1 << i ) ;
    return ;
}
/// To unset/clear the i-th bit of a number
void unsetBit( int &num, int i )
{
    num &= ( ~(1 << i) ) ;
    return ;
}
/// To toggle the i-th bit of a number
void toggleBit( int &num, int i )
{
    num ^= ( 1 << i ); 
    return ;
}
/// To check if i-th bit is set or unset
bool isSet( int &num, int i )
{
    return ( num & ( 1 << i ) ); /// or return (num >> i) & 1;
}
/// To extract the i-th bit of a number
bool extractBit( int &num, int i )
{
    return ( num & ( 1 << i ) );
}
/// To fine 1's complement or flip every bit of a number
int flipBit(int &num )
{
    return ~num;
}
/// To find two's complement of a number
int twos_complement( int num )
{
    return ~num + 1 ;
}
/// To unset the last set bit or stripping off the lowest set bit
void unsetLastSetBit( int &num )
{
    num &= (num-1);
    return ;
}
/// To clear all bits from LSB to i-th bit
void LSB_to_ith_bit_clear( int &num, int i )
{
    int mask = ~((1 << i+1 ) - 1);
    num &= mask;
    return ;
}
/// To clear all bits from MSB to i-th bit
void MSB_to_ith_bit_clear( int &num, int i)
{
    int mask = ( 1 << i ) - 1 ;
    num &= mask;
    return ;
}
/// To count set bit in an integer
int countSetBit( int num )
{
    int cnt = 0;
    while( num ) {
        cnt += ( num & 1 );
        num >>= 1;
    }
    return cnt;
}
/// To find log base 2 pf 32 bit integer
int log2( int num )
{
    int res = 0;
    while( num >>= 1 ) res += 1;
    return res;
}
/// To check if a number is divisible by power of 2
bool isDivisibleByPowerOf2( int num, int k )
{
    int powerOf2 = 1 << k;
    return ( num & ( powerOf2 - 1) ) == 0;
}
/// To check if given 32-bit integer is power of 2
bool isPowerOf2( int num )
{
    return num && !( num & (num-1));
}
/// To clear all trailing ones
void clearAllTrailingOnes( int &num )
{
    num &= ( num + 1 );
    return ; 
}
/// To set the last cleared bit
void setLastUnsetBit( int &num ) 
{
    num |= ( num + 1 );
    return ;
}
/// To extract the last set bit
int extractLastSetBit( int num )
{
    return num & ~num;
}
/// To find the position of the last set bit
int lastSetBitPos( int num )
{
    return log2( num & -num );
}
/// To compute XOR of 1 to N
int computeXOR( int n )
{
    if( n % 4 == 0 ) return n;
    else if( n % 4 == 1 ) return 1;
    else if( n % 4 == 2 ) return n+1;
    else return 0;
}
/// To compute XOR from L to R i.e., L^(L+1)^...^(R-1)^R
int rangeXOR( int l, int r )
{
    return (computeXOR(l-1) ^ computeXOR(r));
}
/// To count of numbers (x) smaller than or equal to n such that n +  x = n ^ x
/// n + i = ( n ^ i ) + 2 * ( n & i )
int countValues(int n)
{
    int unset_bits=0;
    while (n)
    {
        if ((n & 1) == 0)
            unset_bits++;
        n=n>>1;
    }
    return 1 << unset_bits;
}
/// Find XOR of all subsets of a set
int subsetXOR( vector<int> st )
{
    if( st.size() == 1 ) return st[0];
    return 0;
}
/// To check if a number has bits in an alternate pattern
bool alternatePattern( int n )
{
    /// Alternate pattern means 10101 or 01010
    /// n > 0
    int x = n ^ ( n >> 1 ) ;
    return ( x & ( x + 1) ) == 0;

}
/// To find x ^ y in O ( log y )
long long power( long long x, long long y )
{
    long long res = 1;
    while( y ) {
        if( y & 1 ) res *= x;
        x *= x;
        y >>= 1;
    }
    return res;
}
/// To check whether a number is even or not
bool isEven( int x )
{
    return !(x&1);
}
void Swap( int &x, int &y )
{
    x ^= y;
    y ^= x;
    x ^= y;
}
/// To generate power set
void powerSet( vector<int>v )
{
    int len = v.size();
    vector<vector<int>> allSub;
    for( int i = 0; i < ( 1 << len); i += 1 ) {
        vector<int> sub;
        for( int idx = 0; idx < len; idx += 1 ) {
            if( i & ( 1 << idx) ) {
                sub.push_back( v[idx] );
            }
        }
        allSub.push_back(sub);
    }
    // for( int i = 0; i < ( 1 << len); i += 1 ) {
    //     for( int idx = 0; idx < allSub[i].size(); idx += 1 ) {
    //         cout << allSub[i][idx] << " ";
    //     }
    //     cout << endl;
    // }
}
int main()
{
    
}
