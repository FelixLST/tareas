#include <iostream>
#include <fstream>

using namespace std;
void Menu();
int Moda(int NumPregun,int Contador[365]); //Regresa la moda de la preguntra dada
int Contador(int NumPregun,int Contador[365]); //Cuenta las respuestra de la pregunta dada y da la frecuencia de cada una
int FrecuenciaRelativaYAcum(int NumPregun,int Contador[365]); //Regresa la fecuencia relativa y acumulada de los resultados de la pregunta dada
void LectorPrincipal(Char Respuestas[][73],int r); //Lee todo el archivo de exel-Felix
void impresorExelDatos(int NumPregun,char IndiPregun[73], char Respuestas[][73]int r);// Crea un archivo con los datos del resumen-Felix
void LectorPregunta(int NumPregun,char RespuestaColum[365]);//Lee solo los datos de la preungta dada
void ResumenGeneral(int Contador[365],Char IndiPregun[73], char Respuestas[][73],int r);//Imprime en pantalla los datos de todo el archivo (Todas las modas, todas las fecuencias,etc)

int main()
{
	ifstream archi("c:\\datos\\PIBaseDeDatos.xlsx",ios::in)
	int op,Numpregun;
	char IndiPregun[73];
	char Respuestas[365][73];
	char RespuestaColum[365][10];
	int Contador[365];
	do
	{
		op=Menu();
		if(op==1)
		{
			cout << "De que Pregunta desea saber la moda?\n";
			cin >> NumPregun;
			cout << "La moda de la pregunta " << NumPregun << " es " << Moda(NumPregun); << endl;
		}
		else if(op==2);
		{
			cout << "De que pregunta desea saber la frecuencia \n";
			cin >> Numpregun;
			cout << "Las frecuencias  de la pregunta " << Numpregun << " es " << Contador(NumPregun) << endl;
		}
		else if(op==3);
		{
			cout << "De que pregunta desea saber la Frecuencia relativa y  acumulada\n";
			cin >> Numpregun;
			cout << "La fecuencia relativa acumulada de la pregunta " << Numpregun << "es" << FrecuenciaRelativaYAcum(Numpregun) << endl;
		}
		else if(op==4);
		{
			cout << " Si desea guardar los datos en un archivo de exel precione 1 si no lo desea preicone 2\n";
			cin >> Numpregun;
			if(Numpregun==1)
			{
				ResumenGeneral();
				impresorExelDatos();
				cout << "Se an guardado los resultados en un archivo de exel llamado *Resultado de encuenstas* en la carpeta Encuestas PI en el disco duro\n";

			}
			else
				ResumenGeneral();

		}
		
	}while(op!=0);
}
void Menu();
{
	int op;
	cout << "Bienvenido a la calculadora Estadistica MKI\n";
	cout << "Selecione una de las opciones de la acciones a relaisar tecleando un numero su elecion y precione 0 para salir\n";
	cout << "Para Obtener la moda de alguna pregunta preicone 1\n";
	cout << "Para Obtener las frecuenncias de las respuestas de una preguntra precione 2\n";
	cout << "Para obtener la frecuencia relativa acumulada de las respuestas precione 3\n";
	cout << "Para obtener el resumen general de toda la encuesta precione 4\n";
	cin >> op;
	return op;
}
void impresorExelDatos(int NumPregun);//poner una oopcion para imprimir todo el archivo y no solo 1 pregunta.
{

}
void LectorPrincipal();
{
	ifstream archi("c:\\datos\\PIBaseDeDatos.xlsx",ios::in);

}
