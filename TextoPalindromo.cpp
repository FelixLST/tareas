#include <iostream>
#include <string.h>

using namespace std;

bool EsPalindromo(char c[20],int i,int f);

int main()
{
	char c[20];
	bool res=0;
	int f;
	cout << "Este programa te dice si un texto es palindromo\n";
	cin.getline(c,20);
	f=strlen(c)-1;
	res=EsPalindromo(c,0,f)
	if(res==1)
	{
		cout << "El texto es palindromo\n";
		return 0;
	}
	else
		cout << "El texto no es palindromo\n";
	return 0;

}

bool EsPalindromo(char c[20],int i,int f)
{
	if(i<f)
	{
		if(c[i]==' ')
			return EsPalindromo(c,++i,f);
		else if(c[f]==' ')
			return EsPalindromo(c,i,--f);
		else if(c[i]==c[f])
			return EsPalindromo(c,++i,--f);
		else 
			return 0;
	}
	else 
		return 1;
}
