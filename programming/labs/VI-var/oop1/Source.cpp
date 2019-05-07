#include <stdio.h>
#include <conio.h>
static const int n = 40;
/*

					ООП
				лабораторная 1
					6 - вариант

Создайте класс HugeInteger, который использует массив из 40 элементов для хранения целых чисел, 
содержащих до 40 цифр. Создайте функции элементы inputHugeInteger, outputHugeInte¬ger, 
addHugeIntegers и substractHugeIntegers для ввода, вывода, сложе¬ния и вычитания этих 
больших целых. 
Для сравнения объектов HugeInteger создайте функции isEqualTo (равно)...


*/
class HugeInteger
{
	   private:
					int arr[n];

	
		public:

			HugeInteger::HugeInteger()
			{
				
			}

			void inputHugeInteger(int opr[n])
			{
				for (int i = 0; i < n; i++)
					arr[i] = opr[i];
			}

			void outputHugeInteger()
			{


				for (int i = 0; i < n; i++)
					printf("%d ", arr[i]);

				printf("\n");
			}

			HugeInteger addHugeIntegers(HugeInteger arr2)
			{
				
				HugeInteger sum; 


				for (int i = 0; i < n; i++)
				{
					int temp = arr[i] + arr2.arr[i];
					arr[i] = temp;
				}
				return sum;
			
			}

			HugeInteger substractHugeIntegers(HugeInteger arr2)
			{
				HugeInteger sum;


				for (int i = 0; i < n; i++)
				{
					int temp = arr[i] - arr2.arr[i];
					arr[i] = temp;
				}
				return sum;
				
			}

			HugeInteger multiplication(HugeInteger opr2) 
			{
				HugeInteger product; 

				for (int i = n - 1; i >= 0; i--) 
				{
					int k = i; 
					int carryover[n] = { 0 }; 

													  
					for (int j = n - 1; j >= 0; j--)
					{
						int result = (arr[j] * opr2.arr[i]) + carryover[j]; 
						product.arr[k] += result % 10; 
						carryover[(j - 1)] = result / 10; 
						k--;
					} 
				} 

				int carryover[n] = { 0 }; 
				for (int k = n - 1; k >= 0; k--)
				{
					if (product.arr[k] > 9 || carryover[k] != 0) 
					{
						int result = product.arr[k] + carryover[k];

						product.arr[k] = result % 10;
						carryover[(k - 1)] = result / 10; 
					} 
				} 
				return product;
			} ;

			bool HugeInteger::isEqualTo(HugeInteger arr2)
			{
				int i = 0; 

				while (arr[i] == arr2.arr[i]) 
				{
					i++;
				} 
				if (i >= n) 
				{
					return true;
				}
				else 
				{
					return false;
				} 
			}

			bool HugeInteger::isNotEqualTo(HugeInteger arr2)
			{
				int oprIndex = 0;
				int opr2Index = 0;

	
				while (arr[oprIndex] == 0)
				{
					oprIndex++;
				} 


				while (arr2.arr[opr2Index] == 0)
				{
					opr2Index++;
				}

			
				if (oprIndex != opr2Index)
				{
					return true;
				}
				else
				{
				
					int i = 0; 
					while (arr[i] == arr2.arr[i] && i < n)
						
					{
						i++;
					} 

					 
					if (i >= n)
					{
						return false;
					}
					else
					{
						return true;
					} 
				} 	
			}

			bool HugeInteger::isGreaterThanOrEqualTo(HugeInteger arr2)
			{
				int oprIndex = 0;
				int opr2Index = 0;

				
				while (arr[oprIndex] == 0)
				{
					oprIndex++;
				}

				  
				while (arr2.arr[opr2Index] == 0)
				{
					opr2Index++;
				}

				
				if (oprIndex < opr2Index)
				{
					return true; 
				}
				else if (oprIndex > opr2Index)
				{
					return false; 
				}
				else 
				{
					
					int i = 0; 
					while (arr[i] == arr2.arr[i] && i < n)
						
					{
						i++;
					} 

					 
					if (arr[i] > arr2.arr[i] || i >= n)
					{
						return true; 
					}
					else
					{
						return false; 
					} 
				} 
			}

			bool HugeInteger::isLessThanOrEqualTo(HugeInteger arr2)
			{
				int oprIndex = 0;
				int opr2Index = 0;

				
				while (arr[oprIndex] == 0)
				{
					oprIndex++;
				} 

				  
				while (arr2.arr[opr2Index] == 0)
				{
					opr2Index++;
				}

				 
				if (oprIndex > opr2Index)
				{
					return true; 
				}
				else if (oprIndex < opr2Index)
				{
					return false; 
				}
				else 
				{
					
					int i = 0; 
					while (arr[i] == arr2.arr[i] && i < n)
						
					{
						i++;
					} 

					
					if (arr[i] < arr2.arr[i] || i >= n)
					{
						return true; 
					}
					else
					{
						return false; 
					}
				} 
			} 

			bool HugeInteger::isZero()
			{
				int i = 0; 
				while (arr[i] == 0 && i < n)
				{
					i++;
				} 
				if (i == n)
				{
					return true; 
				}
				else
				{
					return false; 
				} 
			} 




};




void main()
{
	HugeInteger A;
	HugeInteger B;


	int as[40];

	for (int i = 0; i < n; i++)
		as[i] = 1;


	A.inputHugeInteger(as);
	B.inputHugeInteger(as);
	
	printf("output A object:\n");
	A.outputHugeInteger();
	printf("output B object: \n");
	B.outputHugeInteger();

	
	A.addHugeIntegers(B);
	printf("output A+B , A object:\n");
	A.outputHugeInteger();

	A.substractHugeIntegers(B);
	printf("output A-B, A object:\n");
	A.outputHugeInteger();


	printf("%d isEquals A and B\n",A.isEqualTo(B));
	printf("%d isNotEquals A and B\n", A.isNotEqualTo(B));

	printf("%d isGreaterThanOrEqualTo A and B\n", A.isGreaterThanOrEqualTo(B));
	printf("%d isLessThanorEqualTo A nd B\n", A.isLessThanOrEqualTo(B));

	printf("%d isZero A\n%d isZero B\n", A.isZero(), B.isZero());

	_getch();

}