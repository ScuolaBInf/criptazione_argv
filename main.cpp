#include <iostream>
#include "criptazione_argv.h"
#include <conio.h>	//IN DEBUG MODE FOR GETCH();

using namespace std;

main (int argc, char** argv)
	{
		keyCryptManager crypt(argv);
		
		if (argc != 10)													/***************/
			{															/*IN DEBUG MODE*/
				cout << "Nessuna chiave passata come parametro!";		/***************/
			}
		else
			{
				for (int i = 0; i < 8; i++)
					{
						cout << endl << crypt.keyReturn(i);				//stampa l'argomento
					}
			}
			
		getch();														//IN DEBUG MODE		
	}
