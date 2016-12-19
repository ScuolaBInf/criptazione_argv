#include <iostream>
#include "criptazione_argv.h"
#include <conio.h>	//IN DEBUG MODE FOR GETCH();

using namespace std;

main (int argc, char** argv)
	{
		keyCryptManager crypt;
		
		if (argc != 10)													/***************/
			{															/*IN DEBUG MODE*/
				cout << "Nessuna chiave passata come parametro!";		/***************/
			}
		else
			{
				int key[] =
					{
						crypt.decrypt(argv, 1),
						crypt.decrypt(argv, 2),
						crypt.decrypt(argv, 3),
						crypt.decrypt(argv, 4),	
						crypt.decrypt(argv, 5),
						crypt.decrypt(argv, 6),
						crypt.decrypt(argv, 7),
						crypt.decrypt(argv, 8),
					};
					
				for (int i = 0; i < 8; i++) 
				cout << key[i] << endl;
			}
			
		getch();														//IN DEBUG MODE		
	}
