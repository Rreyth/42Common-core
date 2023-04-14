#include <iostream>

int main(int argc, char **argv)
{
	int	i;
	int	j;
	std::string res = "";

	i = 1;
	if (argc == 1)
		res = "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
	while (i < argc)
	{
		j = 0;
		while (argv[i][j])
		{
			res += (char) std::toupper(argv[i][j]);
			j++;
		}
		i++;
	}
	std::cout << res << std::endl;
	return (0);
}
