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

int	**left_rotated90_map(int **map, int size)
{
	int	**resmap = malloc(sizeof(int *) * size);
	for (int i = 0; i < size; i++)
		resmap[i] = malloc(sizeof(int) * size);
	for (int i = 0; i < size; i++)
		for (int j = 0; j <  size; j++)
			resmap[size - j - 1][i] = map[i][j];

	return (resmap);
}

int	**right_rotated90_map(int **map, int size)
{
	int	**resmap = malloc(sizeof(int *) * size);
	for (int i = 0; i < size; i++)
		resmap[i] = malloc(sizeof(int) * size);
	for (int i = 0; i < size; i++)
		for (int j = 0; j <  size; j++)
			resmap[j][size - i - 1] = map[i][j];

	return (resmap);
}

int	**rotated180_map(int **map, int size)
{
	int	**resmap = malloc(sizeof(int *) * size);
	for (int i = 0; i < size; i++)
		resmap[i] = malloc(sizeof(int) * size);
	for (int i = 0; i < size; i++)
		for (int j = 0; j <  size; j++)
			resmap[j][i] = map[i][j];

	return (resmap);
}

int	**inversed_map(int **map, int size)
{
	int	**resmap = malloc(sizeof(int *) * size);
	for (int i = 0; i < size; i++)
		resmap[i] = malloc(sizeof(int) * size);
	for (int i = 0; i < size; i++)
		for (int j = 0; j < size; j++)
			resmap[i][j] = !map[i][j];
	
	return (resmap);
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

int	**get_expanded_map(int **map, int size)
{
	int	**exmap = malloc(sizeof(int *) * size * 2);
	for (int i = 0; i < 2 * size; i++)
		exmap[i] = malloc(sizeof(int) * size * 2);
	int	**map1 = left_rotated90_map(map, size);
	int	**map2 = copy_map(map, size);
	int	**map3 = rotated180_map(map, size);
	int	**map4 = right_rotated90_map(map, size);

	for (int i = 0; i < 2 * size; i++)
	{
		for (int j = 0; j < 2 * size; j++)
		{
			if (i < size && j < size)
				exmap[i][j] = map1[i][j];
			if (i > size && j < size)
				exmap[i][j] = map3[i - size - 1][j];
			if (i < size && j > size)
				exmap[i][j] = map2[i][j - size - 1];
			if (i > size && j > size)
				exmap[i][j] = map4[i - size - 1][j - size - 1];
		}
	}
	
	free_map(map1, size);
	free_map(map2, size);
	free_map(map3, size);
	free_map(map4, size);
	return (exmap);
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
	
	// for (int i = 0; i < n; i++)
	// {
		// print_map(map, size);
		generate_map(map, size);
		int **exmap = get_expanded_map(map, size);
		if (write_map_to_file(filename, exmap, 2 * size))
			return (1);
		// inverse_map(map, size);
		// left_rotate90_map(map,size);
		// right_rotate90_map(map, size);
	// }
	fclose(fp);
	free_map(map, size);
	return (0);
}