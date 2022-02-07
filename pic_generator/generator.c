#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <stdlib.h>

void	free_map(int **map, int size)
{
	for (int i = 0; i < size; i++)
		free(map[i]);
	free(map);
}

int	**copy_map(int **map, int size)
{
	int	**res;
	res = malloc(sizeof(int *) * size);
	for (int i = 0; i < size; i++)
		res[i] = malloc(sizeof(int) * size);
	for (int i = 0; i < size; i++)
		for (int j = 0; j < size; j++)
			res[i][j] = map[i][j];
	return (res);
}

void	left_rotate90_map(int **map, int size)
{
	int	**tmpmap = copy_map(map, size);
	for (int i = 0; i < size; i++)
		for (int j = 0; j <  size; j++)
			map[size - j - 1][i] = tmpmap[i][j];

	free_map(tmpmap, size);
}

void	right_rotate90_map(int **map, int size)
{
	int	**tmpmap = copy_map(map, size);
	for (int i = 0; i < size; i++)
		for (int j = 0; j <  size; j++)
			map[j][size - i - 1] = tmpmap[i][j];

	free_map(tmpmap, size);
}

void	inverse_map(int **map, int size)
{
	for (int i = 0; i < size; i++)
		for (int j = 0; j < size; j++)
			map[i][j] = !map[i][j];
}

void	print_map(int **map, int size)
{
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
			printf("%d", map[i][j]);
		printf("\n");
	}
	printf("\n");
}

int	write_map_to_file(char *fileName, int **map, int size)
{
	FILE *fp;
	if ((fp = fopen(fileName, "a")) == NULL) {
		printf("Cannot open file.\n");
		return (1);
	}
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
			fprintf(fp, "%d", map[i][j]);
		fprintf(fp, "\n");
	}
	fprintf(fp, "\n");
	return (0);
}

int	generate_map(int **map, int size)
{
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			if (j > size - 3 && i < 2)
				map[i][j] = 1;
			else if (j < 2 && i > size - 3)
				map[i][j] = 0;
			else
				map[i][j] = rand() % 2;
		}
	}
	return (0);
}

int	main(int argc, char **argv)
{
	int		size;
	int		**map;
	int		n;
	char	*filename = "pic.txt";

	if (argc != 3)
	{
		printf("./generator [size of map] [num of maps]\n");
		return (1);
	}
	FILE	*fp;
	if ((fp = fopen(filename, "w")) == NULL) {
		printf("Cannot open file.\n");
		return (1);
	}
	srand(time(NULL));

	size = atoi(argv[1]);
	n = atoi(argv[2]);

	map = malloc(sizeof(int *) * size);
	for (int i = 0; i < size; i++)
		map[i] = malloc(sizeof(int) * size);
	
	for (int i = 0; i < n; i++)
	{
		// print_map(map, size);
		generate_map(map, size);
		if (write_map_to_file(filename, map, size))
			return (1);
		// inverse_map(map, size);
		// left_rotate90_map(map,size);
		// right_rotate90_map(map, size);
	}
	fclose(fp);
	free_map(map, size);
	return (0);
}