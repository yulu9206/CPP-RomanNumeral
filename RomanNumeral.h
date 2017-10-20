#ifndef ROMANNUMERAL_H_
#define ROMANNUMERAL_H_
#include <string>
#include <iostream>

using namespace std;

class RomanNumeral
{
public:
   // Constructors
    RomanNumeral();
    RomanNumeral(string roman_str);
    RomanNumeral(int decimal_int);
    
   //  Getter functions.
   int get_decimal();
   string get_roman();
   
   //  Friend functions.
   // == & !=
   friend bool operator == (RomanNumeral& r1, RomanNumeral& r2);
   friend bool operator != (RomanNumeral& r1, RomanNumeral& r2);
   // +, -, *, /
   friend int operator + (const RomanNumeral& r1, const RomanNumeral& r2);
   friend int operator - (RomanNumeral& r1, RomanNumeral& r2);
   friend int operator * (RomanNumeral& r1, RomanNumeral& r2);
   friend int operator / (RomanNumeral& r1, RomanNumeral& r2);
   // << & >>
   friend ostream& operator << (ostream& outs, RomanNumeral& r1);
   friend istream& operator >> (istream& ins, RomanNumeral& r1);
   
private:
   string roman;
   int decimal;
   void to_roman();
   void to_decimal();
   
};

#endif /* ROMANNUMERAL_H_ */
