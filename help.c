#include "shell.h"
/**
 *help - help builtin command
 *@cmd: the command line inserted
 *Return: 0 if sucess (always)
 *
 */

int help(char *cmd)

{
	char *file;
	int fd, r;
	char *s;

	if (cmd == NULL)
	{
		s = "help: no builtin entered.\n";
		r = _strlen(s);
		r = write(1, s, r);
		return (0);
	}
	if (!_strcmp(cmd, "cd"))
	{
		file = "help_cd";
		fd = open(file, O_RDWR);
		s = malloc(256);
		if (s == NULL)
			return (-1);
		while ((r = read(fd, s, 256)) > 0)
		{
			r = write(1, s, r);
			if  (r == -1)
			{
				return (-1);
			}
		}

