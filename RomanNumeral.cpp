using namespace std;
#include "RomanNumeral.h"
#include <string>
#include <iostream>

// Constructor
RomanNumeral::RomanNumeral() : roman(""), decimal(0) 
{
   
}
RomanNumeral::RomanNumeral(string roman_str): roman(roman_str), decimal(0){ to_decimal(); }
RomanNumeral::RomanNumeral(int decimal_int): roman(""), decimal(decimal_int){ to_roman(); }
 
//  Getter functions.
int RomanNumeral::get_decimal() { return decimal; }
string RomanNumeral::get_roman() { return roman; }

// == & !=
bool operator == (RomanNumeral& r1, RomanNumeral& r2) { return r1.decimal == r2.decimal; }
bool operator != (RomanNumeral& r1, RomanNumeral& r2) { return r1.decimal != r2.decimal; }
// +, -, *, /
int operator + (const RomanNumeral& r1, const RomanNumeral& r2) { return r1.decimal + r2.decimal; }
int operator - (RomanNumeral& r1, RomanNumeral& r2) { return r1.decimal - r2.decimal; }
int operator * (RomanNumeral& r1, RomanNumeral& r2) { return r1.decimal * r2.decimal; }
int operator / (RomanNumeral& r1, RomanNumeral& r2) { return r1.decimal / r2.decimal; }
// << & >>
ostream& operator << (ostream& outs, RomanNumeral& r1) 
{
   outs << "[" << r1.decimal << ":" << r1.roman << "]";
   return outs;
}
istream& operator >> (istream& ins, RomanNumeral& r1)
{
   string roman_str;
   ins >> roman_str;
   r1.roman = roman_str;
   r1.to_decimal();
   return ins;
}

// Roman & decimal convert
void RomanNumeral::to_roman()
{
  int num = decimal;
  if(num <= 0) roman = "";  
  
  string ret = "";  
  static int number[13] = {1000, 900, 500, 400, 100,90, 50, 40, 10, 9, 5, 4, 1};  
  static string flags[13] = {"M","CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};  
    
  for(int i = 0; i < 13 && num > 0; i++){   
      if(num < number[i]) continue;  
  
      while(num >= number[i]){  
          num-= number[i];  
          ret += flags[i];  
      }  
  }  
  roman = ret; 
}
void RomanNumeral::to_decimal()
{
  string s = roman;
  int tagVal[256];  
  tagVal['I'] = 1;  
  tagVal['V'] = 5;  
  tagVal['X'] = 10;  
  tagVal['C'] = 100;  
  tagVal['M'] = 1000;  
  tagVal['L'] = 50;  
  tagVal['D'] = 500;  
  int val = 0;  
  for(int i = 0; i < s.length(); i++){  
      if(i+1 >= s.length() || tagVal[s[i+1]] <= tagVal[s[i]])  
          val += tagVal[s[i]];  
      else  
          val -= tagVal[s[i]];   
  }  
  decimal = val;  
}
