#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <stdlib.h>

int	main(int argc, char **argv)
{
	FILE	*fp;
	int		n;
	int		size;

	if (argc != 3)
	{
		printf("./generator [size of map]\n");
		return (1);
	}
	n = atoi(argv[2]);
	size = atoi(argv[1]);
	srand(time(NULL));
	if ((fp = fopen("pic.txt", "w")) == NULL) {
		printf("Cannot open file.\n");
		return (1);	
	}

	for (int k = 0; k < n; k++)
	{
		for (int i = 0; i < size; i++)
		{
			for (int j = 0; j < size; j++)
			{
				if (j > size - 3 && i < 2)
					fprintf(fp, "%d", 1);
				else if (j < 2 && i > size - 3)
					fprintf(fp, "%d", 0);
				else
					fprintf(fp, "%d", rand() % 2);
			}
			fprintf(fp, "%s", "\n");	
		}
		if (k != n - 1)
			fprintf(fp, "%s", "\n");
	}
	fclose(fp);
}