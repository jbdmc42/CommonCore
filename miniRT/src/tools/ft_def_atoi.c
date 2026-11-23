#include "minirt.h"

static int	check_type_atoi(int val, int type)
{
	if (type == FOV)
	{
		if (val > 180)
			return (180);
		else if (val < 0)
			return (0);
	}
	else if (type == RGB)
	{
		if (val > 255)
			return (255);
		else if (val < 0)
			return (0);
	}
	return (val);
}

int	ft_def_atoi(char *line, int *i, int type)
{
	int	val;
	int	sig;

	val = 0;
	sig = 1;
	while (line[*i] == '\t' || line[*i] == ' ' || line[*i] == ',')
		(*i)++;
	while (line[*i] == '+' || line[*i] == '-')
	{
		if (line[*i] == '-')
			sig *= -1;
		(*i)++;
	}
	while (line[*i] >= '0' && line[*i] <= '9')
	{
		val = line[*i] - '0' + val * 10;
		(*i)++;
	}
	return (skip_newline(line, i), check_type_atoi(val, type) * sig);
}
