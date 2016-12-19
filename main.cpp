#include <iostream>
#include "criptazione_argv.h"
#include <conio.h>	//IN DEBUG MODE FOR GETCH();

using namespace std;

int main (int argc, char** argv)
	{
		keyCryptManager* crypt;
		
		if (argc != 10)													/***************/
			{															/*IN DEBUG MODE*/
				cout << "Nessuna chiave passata come parametro!";		/***************/
			}
		else
			{
				crypt = new keyCryptManager(argv);

				for (int i = 0; i < 8; i++)
					{
						cout << endl << crypt -> keyReturn(i);				//stampa chiave decriptata per parametro
					}
				
				crypt -> cryptArray();
				cout << endl;
				crypt -> printArrayResult();
			}
			
		getch();														//IN DEBUG MODE		
	}
