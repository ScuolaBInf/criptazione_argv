#include<iostream>

class keyCryptManager
	{
		private:
			int key[8];
			int workCryptArray[8][8];
			
			void convertStringToInt(char**);
			void convertIntToArrayInt();
			void decryptCryptedArray();
			void convertArrayToInt();
			
		public:
			
			int decrypt(char** argv, int keyNum);
			
			void printArrayResult(int key[][8]);
			void cryptArray(int workCryptArray[][8]);
			void printResult(int key[8]);
	};
