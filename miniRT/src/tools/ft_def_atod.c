#include "minirt.h"

int		get_decimal(char *line, int dec, int i)
{
	while (line[i] >= '0' && line[i] <= '9')
	{
		i++;
		dec++;
	}
	return (dec);
}

double	set_decimal(double val, int dec)
{
	while (dec > 0)
	{
		val /= 10;
		dec--;
	}
	return (val);
}

int		get_signal(char *line, int sig, int *i)
{
	while (line[*i] == '+' || line[*i] == '-')
	{
		if (line[*i] == '-')
			sig *= -1;
		(*i)++;
	}
	return (sig);
}

static double	check_type(double val, int type)
{
	if (type == RATIO)
	{
		if (val > 1.0)
			return (1);
		else if (val < 0.0)
			return (0);
	}
	else if (type == ORIENTATION)
	{
		if (val > 1)
			return (1);
		else if (val < -1)
			return (-1);
	}
	return (val);
}

double	ft_def_atod(char *line, int	*i, int type)
{
	double	val;
	int		sig;
	int		dec;
	int		odo;

	val = 0;
	sig = 1;
	dec = 0;
	odo = 0;
	while (line[*i] == '\t' || line[*i] == ' ' || line[*i] == ',')
		(*i)++;
	sig = get_signal(line, sig, i);
	while ((line[*i] >= '0' && line[*i] <= '9') || line[*i] == '.')
	{
		if (line[*i] == '.' && odo == 0)
		{
			dec = get_decimal(line, dec, *i + 1);
			odo = 1;
		}
		else
			val = line[*i] - '0' + val * 10;
		(*i)++;
	}
	val = set_decimal(val, dec);
	return (skip_newline(line, i), check_type(val, type) * sig);
}
