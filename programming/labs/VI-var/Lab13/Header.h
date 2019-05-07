
extern const int n = 4;
extern const int m = 5;


void outArr(int arr[n][m])
{
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++)
			printf("%d ", arr[i][j]);
		printf("\n");
	}
	printf("\n");
}

void outArrkv(int arr[m][m])
{
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < m; j++)
			printf("%d ", arr[i][j]);
		printf("\n");
	}
	printf("\n");
}



void MatrixPow(int arr[m][m], int pow)
{
	
	int res[m][m] = { 0 };
	int p = 0;
	while (++p <= pow)
	{
		for (int i = 0; i < m; i++)
		{

			for (int j = 0; j < m; j++)
			{
		
				for (int k = 0; k < m; k++)
				{
							 
				 res[i][j] += arr[i][k] * arr[k][j];
					
				}
				
				
			}
		}
		
	}

	for (int i = 0; i < m; i++)
		for (int j = 0; j < m; j++)
			arr[i][j] = res[i][j];

}


void vvodkv(int arr[m][m])
{
	printf("Want generate? - (Press Enter - yes)\n");
	if (_getch() == 13)
	{
		for (int i = 0; i < m; i++)
			for (int j = 0; j < m; j++)
				arr[i][j] = (i == j) ? rand() % 10 : rand() % 10;
	}
	else
	{
		for (int i = 0; i < m ;i++)
			for (int j = 0; j < m; j += 5)
				scanf("%d %d %d %d %d", &arr[i][j], &arr[i + 1][j + 1], &arr[i + 2][j + 2], &arr[i + 3][j + 3], &arr[i + 4][j + 4]);
	}
}

void vvod(int arr[n][m])
{
	printf("Want generate? - (Press Enter - yes)\n");
	if (_getch() == 13)
	{
		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++)
				arr[i][j] = (i==j)?rand() % 10:rand()%10;
	}
	else
	{
		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j += 5)
				scanf("%d %d %d %d %d", &arr[i][j], &arr[i + 1][j + 1], &arr[i + 2][j + 2], &arr[i + 3][j + 3], &arr[i + 4][j + 4]);
	}
}

int otric(int arr[n][m])
{
	int otricat = 0;

	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			(arr[i][j] < 0) ? otricat++ : 0;


	return 	otricat;
}