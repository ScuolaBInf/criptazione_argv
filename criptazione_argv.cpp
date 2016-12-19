#include <iostream>	//NECESSARIA
#include <stdlib.h> //NECESSARIA
#include <math.h>	//NECESSARIA
#include "criptazione_argv.h"

using namespace std;

void keyCryptManager::convertStringToInt(char** argv)
	{
		for (int i = 0; i < 8; i++)
			{
				key[i] = atoi(argv[i+2]);
			}
	}

void keyCryptManager::convertIntToArrayInt()
	{
		for (int i = 0; i < 8; i++)
			{
				for (int j = 0; j < 8; j++)
					{
						workCryptArray[i][7 - j] = key[j] % 10;
						key[j] /= 10;	
					}
			}
	}

void keyCryptManager::decryptCryptedArray()
	{
		for (int i = 0; i < 8; i++)
			{	
				for (int j = 0; j < 7; j++)
					{
						if (workCryptArray[6 - j][7 - i] % 2 == 0 && 
							workCryptArray[6 - j][7 - i] != 0 && 
							workCryptArray[7 - j][7 - i] != 0 && 
							workCryptArray[7 - j][7 - i] != 9)
							{
								workCryptArray[7 - j][7 - i]++;
							}
						else if (workCryptArray[6 - j][7 - i] % 2 != 0 && 
								 workCryptArray[6 - j][7 - i] != 0 && 
								 workCryptArray[7 - j][7 - i] != 0 && 
								 workCryptArray[7 - j][7 - i] != 9)
							{
								workCryptArray[7 - j][7 - i]--;
							}
					}
					
				for (int j = 0; j < 8; j++)
					{
						if (workCryptArray[7 - j][7 - i] == 0)
							{
								workCryptArray[7 - j][7 - i] = 9;
							}
						else if (workCryptArray[7 - j][7 - i] == 9)
							{
								workCryptArray[7 - j][7 - i] = 0;
							}
					}		
			}
	}
		
void keyCryptManager::convertArrayToInt()
	{
		for (int i = 0; i < 8; i++)
			{	
				for (int j = 0; j < 8; j++)
					{	
						key[i] += workCryptArray[7 - j][7 - i] * pow(10, 7 - j);
					}							
			}
	}

/**************************************** in debug mode ****************************************/
/***/																						/***/
/***/	void keyCryptManager::printArrayResult(int key[][8])								/***/
/***/	{																					/***/
/***/		cout << endl;																	/***/
/***/		for (int i = 0; i < 8; i++)														/***/
/***/			{																			/***/
/***/				for (int j = 0; j < 8; j++)												/***/
/***/					{																	/***/
/***/						cout << key[7 - j][7 - i];										/***/
/***/					}																	/***/
/***/				cout << endl;															/***/
/***/			}																			/***/
/***/		cout << endl;																	/***/
/***/		}																				/***/
/***/																						/***/
/**************************************** in debug mode ****************************************/
/***/																						/***/
/***/	void keyCryptManager::cryptArray(int workCryptArray[][8])							/***/
/***/	{																					/***/
/***/		for (int i = 0; i < 8; i++)														/***/
/***/			{																			/***/
/***/				for (int j = 0; j < 8; j++)												/***/
/***/					{																	/***/
/***/						if (workCryptArray[7 - j][7 - i] == 0)							/***/
/***/							{															/***/
/***/								workCryptArray[7 - j][7 - i] = 9;						/***/
/***/							}															/***/
/***/						else if (workCryptArray[7 - j][7 - i] == 9)						/***/
/***/							{															/***/
/***/								workCryptArray[7 - j][7 - i] = 0;						/***/
/***/							}															/***/
/***/					}																	/***/
/***/																						/***/
/***/				for (int j = 1; j < 8; j++)												/***/
/***/					{																	/***/
/***/						if (workCryptArray[j - 1][7 - i] % 2 == 0 && 					/***/
/***/							workCryptArray[j - 1][7 - i] != 0 && 						/***/
/***/							workCryptArray[j][7 - i] != 0 && 							/***/
/***/							workCryptArray[j][7 - i] != 9)								/***/
/***/							{															/***/
/***/								workCryptArray[j][7 - i]--;								/***/
/***/							}															/***/
/***/						else if (workCryptArray[j - 1][7 - i] % 2 != 0 && 				/***/
/***/								 workCryptArray[j - 1][7 - i] != 0 && 					/***/
/***/								 workCryptArray[j][7 - i] != 0 && 						/***/
/***/								 workCryptArray[j][7 - i] != 9)							/***/
/***/							{															/***/
/***/								workCryptArray[j][7 - i]++;								/***/
/***/							}															/***/
/***/					}																	/***/
/***/			}																			/***/
/***/	}																					/***/
/***/																						/***/
/**************************************** in debug mode ****************************************/
/***/																						/***/
/***/	void keyCryptManager::printResult(int key[8])										/***/
/***/	{																					/***/
/***/		for (int i = 0; i < 8; i++)														/***/
/***/		cout << key[i] << endl;															/***/
/***/	}																					/***/
/***/																						/***/
/**************************************** in debug mode ****************************************/

int keyCryptManager::decrypt(char** argv, int keyNum)
	{
		convertStringToInt(argv);	//converte i parametri argv, passati dal Patcher, in un numero intero, necessita della libreria standard del C\C++ stdlib.h, la funzione interesserà solamente i parametri delle chiavi, non altri parametri (come ad esempio il nome o il parametro di controllo)
		convertIntToArrayInt();		//in preparazione all'algoritmo di criptazione trasferisce le 8 chiavi di tipo intero in una matrice 8x8.		
		decryptCryptedArray();		//cripta l'intera matrice sulla base dell'algoritmo di criptazione.
		convertArrayToInt();		//converte la matrice di interi in un array di interi, ovvero l'array contentente le 8 chiavi precedentemente offuscate
		return key[keyNum -1];
	}
