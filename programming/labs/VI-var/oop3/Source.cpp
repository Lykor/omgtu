#include <stdio.h>
#include <conio.h>
#include <string.h>

/*

ÎÎÏ
ëàáîðàòîðíàÿ 3
6 - âàðèàíò

Ñîçäàòü êëàññ-ðîäèòåëü «òåëåôîí» è åãî êëàññ-íàñëåäíèê «àäðåñ» (âûâåñòè, èçìåíèòü).


*/
class telephone
{
protected:
	int number;
	char *name;
	int id;
	char *house;

public:
	telephone(int number, char* name)
	{
		this->number = number;
		this->name = name;
	}
	telephone()
	{
		telephone(911, "police");
	}
	


};

class address :public telephone
{

public:
	
	address(int id, char* name)
	{
		this->id = id;
		this->house = name;
	}


	void getNum()
	{
		printf("%d - name: %s\n", number,name);
	}

	void getAddres()
	{
		printf("%d %s\n", id, house);
	}

	void setAddres(int id, char* house)
	{
		this->id = id;
		this->house = house;
	}

	void setNum(int number,char* name)
	{
		this->number = number;
		this->name = name;
	}



};



void main()
{
	
	address Astana(1,"domdam");

	Astana.getAddres();
	Astana.getNum();

	Astana.setAddres(2, "poselkovaya");
	Astana.setNum(6999, "dominator");

	Astana.getAddres();
	Astana.getNum();

	_getch();
}