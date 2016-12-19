#include <iostream>	//NECESSARIA
#include <stdlib.h> //NECESSARIA
#include <math.h>	//NECESSARIA
#include "criptazione_argv.h"

using namespace std;

keyCryptManager::keyCryptManager(char** argv)
	{
		convertStringToInt(argv);
		convertIntToArrayInt();
		decryptCryptedArray();
		convertArrayToInt();
	}
	
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
/***/	void keyCryptManager::printArrayResult()													/***/
/***/	{																					/***/
/***/		cout << endl;																	/***/
/***/		for (int i = 0; i < 8; i++)														/***/
/***/			{																			/***/
/***/				for (int j = 0; j < 8; j++)												/***/
/***/					{																	/***/
/***/						cout << workCryptArray[7 - j][7 - i];										/***/
/***/					}																	/***/
/***/				cout << endl;															/***/
/***/			}																			/***/
/***/		cout << endl;																	/***/
/***/		}																				/***/
/***/																						/***/
/**************************************** in debug mode ****************************************/
/***/																						/***/
/***/	void keyCryptManager::cryptArray()											/***/
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
/***/	void keyCryptManager::printResult(int key[8])														/***/
/***/	{																					/***/
/***/		for (int i = 0; i < 8; i++)														/***/
/***/		cout << key[i] << endl;															/***/
/***/	}																					/***/
/***/																						/***/
/**************************************** in debug mode ****************************************/
	
int keyCryptManager::keyReturn(int keyNum)
	{
		return key[keyNum];
	}
