#include<iostream>

class keyCryptManager
	{
		private:
			int key[8];											//	Chiavi decriptate
			int workCryptArray[8][8];							//	Variabile di lavoro contentente le cifre delle otto chiavi intere (8cifre x 8chiavi)
			
			void convertStringToInt(char**);					//	Converte le stringhe passate come parametro (argv), in interi, in preparazione alla scomposizione per cifre
			void convertIntToArrayInt();						//	Scompone le chiavi intere in cifre, passandole ad un vettore di interi
			void decryptCryptedArray();							//	Decripta le chiavi tramite l'algoritmo di decripatazione
			void convertArrayToInt();							//	Riconverte l'array in un intero ed inserisce i valori all'interno di key[8]
			
		public:
			
			keyCryptManager(char** argv);						//	Costruttore dell'Oggetto: richiama i metodi privati in modo tale da salvare nella variabile key le chiavi decriptate.
			
			void printArrayResult();							//	PER DEBUG
			void cryptArray();									//	PER DEBUG
			void printResult();									//	PER DEBUG
			
			int keyReturn(int);									//	Ritorna il valore della chiave desiderata (parametro indice della chiave)
	};
