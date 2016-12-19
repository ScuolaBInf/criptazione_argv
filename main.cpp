#include <iostream>
#include "criptazione_argv.h"
#include <conio.h>	//IN DEBUG MODE FOR GETCH();

using namespace std;

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

main (int argc, char** argv)
	{
		keyCryptManager crypt;
		
		if (argc != 10)													/***************/
			{															/*IN DEBUG MODE*/
				cout << "Nessuna chiave passata come parametro!";		/***************/
			}
		else
			{
				crypt.decrypt(argv);
				for (int i = 0; i < 8; i++)
				cout << endl << crypt.keyReturn(i);
			}
			
		getch();														//IN DEBUG MODE		
	}
