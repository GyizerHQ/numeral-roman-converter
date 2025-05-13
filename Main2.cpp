//this is user based program , user will enter the input.
#include<iostream>
#include<utility>
#include<vector>
#include<cstring>
#include<string>
using namespace std;

void Roman(int integer)
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
	
			cout<<"Roman number of "<<ref<<" is "<<result<<endl;
			cout<<"-------------------------------------------------------"<<endl;

}


void Number(string Roman)
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
    cout<<"Roman numeral of "<<Roman<<" integer value is "<<result<<endl;
    cout<<"-------------------------------------------------------"<<endl;

}

int main()
{
	
     int choice;
	    do {
	    	
	
	printf("1.Integer to Roman numeral \n2.Roman numeral to Integer\n3.Exit\n-->Enter your choice ");
	cin>>choice;
	
    switch(choice)
	{
		case 1:
			{
				int integer;
				printf("Enter Integer value between 1 to 3999\n");
				cin>>integer;
				if(integer>0&&integer<4000)
				{
					Roman(integer);
				}else{
					cout<<"out of range";
				}
				
			}
			break;
		
		case 2:
			{
				string roman;
				printf("Enter Roman numeral\n");
				cin>>roman;
				Number(roman);
		
			}
			break;
		
		case 3:
		exit(0);
				
		
		default:
		{cout<<"enter a vailid number"<<endl;
			}	
	}
	
 
 
    } while(choice<3||choice>0);
	
	
	return 0;
}