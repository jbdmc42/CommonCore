#include "minirt.h"

int	main(int argc, char **argv)
{
	if (argc != 2)
	{
		printf("Error: Invalid argument count.");
		return (printf(" Usage: ./minirt <scene>\n"), E);
	}
	if (!input_validation(argv[1]))
	{
		printf("Error: Invalid argument type.");
		return (printf(" Expected 'scene.rt'.\n"), E);
	}
	return (program_execution(argv[1]));
}
