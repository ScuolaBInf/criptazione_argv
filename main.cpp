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
				int* key = new int[8];
				key = crypt.decrypt(argv);
				crypt.printResult(key);
			}
			
		getch();														//IN DEBUG MODE		
	}
