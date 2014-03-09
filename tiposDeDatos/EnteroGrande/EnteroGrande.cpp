#include <iostream.h>
#include <stdio.h>
#include <stdlib.h>

class EnteroGrande
{
private:

	unsigned int entero0;
	unsigned int entero1;
	unsigned int entero2;
	unsigned int entero3;
	unsigned int entero[4];


public:

	EnteroGrande (int e0, int e1, int e2, int e3)
	{
		entero0 = e0;
		entero1 = e1;
		entero2 = e2;
		entero3 = e3;
		entero[0] = entero0;
		entero[1] = entero1;
		entero[2] = entero2;
		entero[3] = entero3;
		cout << "Tamaño: " << sizeof(entero) << endl;
	}


	int sumar(EnteroGrande eg)
	{
		unsigned a = 0;

		unsigned i = 0;
		unsigned acarreo = 0;
	    
		unsigned tempResult = 0;
		unsigned result[4];
		unsigned b = 0;
		while(a<4)
		{
			unsigned tempA = entero[a];
		unsigned tempB = eg.entero[a];

	while(i<(sizeof(unsigned int) * 8))
		{
			tempResult = (tempA &0x00000001)+(tempB &0x00000001)+ acarreo;
			acarreo = (tempResult>>1)&0x00000001;
			result[b] = (((tempResult &0x00000001)<<i)| result[b]);
			tempA = tempA>>1;
			tempB = tempB>>1;
			i++;
			
		
		
		}
			a++;b++;
	
		}

		cout<<result[0]<<result[1]<<result[2]<<result[3]<<endl;
			
		return(0);
	}




  


};
void main()
	{
		EnteroGrande ent1(0,0,0,0);
		EnteroGrande ent2(0,0,0,1);

		for (int i = 0; i < 51 ; i++) {
		  
		  ent1.sumar(ent2);
		  ent2.sumar(ent2);
		}
	}
