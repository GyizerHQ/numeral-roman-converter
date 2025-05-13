//this program for verifing you given numbers or roman values
#include<iostream>
#include<utility>
#include<vector>
#include<cstring>
#include<string>
using namespace std;


void Roman(int integer,string comp)
{
	int value[]={1000,900,500,400,100,90,50,40,10,9,5,4,1};
	string roman[]={"M","CM","D","CD","C","XC","L","XL","X","IX","V","IV","I"};
	vector<int> v;
	int ref=integer;
	for(int i=0;i<13;i++)
	{
		if(integer>=value[i])
		{
			while(integer>=value[i])
			{
				v.push_back(i);
				integer=integer-value[i];
			}
		}
		
	}
	string result;
	for(int j=0;j<v.size();j++)
	{
		
		result=result+roman[v[j]];
	}
	if(comp==result)
    {
        cout<<ref<<" is verified."<<endl;
    }
			// cout<<"Roman number of "<<ref<<" is "<<result<<endl;
			// cout<<"-------------------------------------------------------"<<endl;

}


void Number(string Roman,int val)
{
	
	
	int value[]={1000,500,100,50,10,5,1};
	char ROMAN[] = {'M', 'D', 'C', 'L', 'X', 'V', 'I'};
	char roman[] = {'m', 'd', 'c', 'l', 'x', 'v', 'i'};
	int compare=4000;
	int result=0;	
	for(int i=0;i<Roman.length();i++)
	{
		for(int j=0;j<7;j++)
		{
			if(Roman[i]==ROMAN[j]||roman[j]==Roman[i])
			{
				if(value[j]<=compare)
				{
					result=result+value[j];
					compare=value[j];
				}else{
					result=result+value[j]-(2*compare);
					compare=value[j];
				}
				break;
			}
		}

    }
    //cout<<"Roman numeral of "<<Roman<<" integer value is "<<result<<endl;
    if(result==val)
    {
        cout<<Roman<<" is verified."<<endl;
    }
    

}
void test_roman_numerals() {
    // assert(RomanNumerals::to_roman(4) == "IV");
    // assert(RomanNumerals::to_roman(1) == "I");
    // assert(RomanNumerals::to_roman(4) == "IV");
    // assert(RomanNumerals::to_roman(9) == "IX");
    // assert(RomanNumerals::to_roman(58) == "LVIII");
    // assert(RomanNumerals::to_roman(1994) == "MCMXCIV");


    // assert(RomanNumerals::from_roman("I") == 1);
    // assert(RomanNumerals::from_roman("IV") == 4);
    // assert(RomanNumerals::from_roman("IX") == 9);
    // assert(RomanNumerals::from_roman("LVIII") == 58);
    // assert(RomanNumerals::from_roman("MCMXCIV") == 1994);

    Roman(4,"IV");
    Roman(1,"I");
    Roman(9,"IX");
    Roman(58,"LVIII");
    Roman(1994,"MCMXCIV");

    Number("I",1);
    Number("IV",4);
    Number("IX",9);
    Number("LVIII",58);
    Number("MCMXCIV",1994);



}


int main()
{
	
    test_roman_numerals();

     
	return 0;
}