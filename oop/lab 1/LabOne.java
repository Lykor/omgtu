import java.util.Scanner;

public class LabOne
{
	public static void main(String[] argc)
	{
		int i=0,sr=0;
		Scanner sc = new Scanner(System.in);

		System.out.print("Enter value for strings:");
		int n=sc.nextInt();
		String[] st = new String[n+1];
				
		System.out.println("Enter "+n+" Strings:");
		while(i<n+1)
		{

			st[i]=sc.nextLine();
			sr+=st[i].length();
			i++;
		}

		sr=sr/(i+1);
		i--;

		System.out.println();
		while(i>-1)
		{
			if(st[i].length()!=0)System.out.println("-"+st[i]);
			i--;
		}

		System.out.println();
		i++;
		System.out.println("sr = "+sr);
		while(i<n)
		{
			if(sr>=st[i].length()&&st[i].length()!=0)System.out.println("+"+st[i]+" : "+st[i].length());
			i++;
		}


	}
}