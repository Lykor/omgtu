
import java.util.ArrayList;
import java.util.Scanner;

/* вариант 7

Выполнить попарное суммирование произвольного конечного ряда чисел следующим образом: 
на первом этапе суммируются попарно рядом стоящие числа, 
на втором этапе суммируются результаты первого этапа и т.д. до тех пор, 
пока не останется одно число.

работа программы:
1 2 3 4 5 6 7 8 9
3 7 11 15 9
10 26 9
36 9
45

*/

public class Main 
{


	public static void main(String[] args) 
		{

		ArrayList<Integer> list = new ArrayList<Integer>();
		int next = 0,n; /* next - будет рядом стоящее число */


		System.out.print("Enter your N - ");
		Scanner sc = new Scanner(System.in);
		n = sc.nextInt(); /* ввод переменной, которая характеризует длину массива и является конечная переменная в массиве
*/

		for(int i=0;i<n;i++)list.add(i+1); /* числа до переменной N 
*/
		System.out.println("List: " + list.toString()); 

		while(list.size()!=1) // Пока размер массива не сократится до одного элемента [0,1,3,...]->[666]
		{
			ArrayList<Integer>temp = new ArrayList<Integer>(); /* временный лист */


			for(int i=0;i<list.size();i=i+2) /* i=i+2 2-т.к. складываются числа попарно, с их индексами 
			представить проще 0+(0+1)<-->2+(2+1) и т.д.	*/
		{
			if(i==list.size()-1)next = 0;else next = list.get(i+1);
			/*если счетчик равен размеру массива, то следующий элемент будет равен 0 или 
			следующий элемент отсутсвует. Необходимо это, чтобы последний элемент не пропадал
			в случае если последний элемент считывается как пустое место и при сложении дает нуль.
			Если же условие false, то следующий элемент присваиваем переменной next */

		System.out.print(list.get(i)+" + " + next+" "); // визуализация процесса
		temp.add(list.get(i)+next); // добавление элемента в массив
		}
		System.out.println();

		list=temp;// присваиваем массиву list элементы массива temp.
	} 

	System.out.println(list.toString()); // вывод элементов массива list
}}

/* 										Zharkov Valeriy OmGTU 16.11.2018	PI-171							*/
/*													Jeffry													*/