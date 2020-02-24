/**
 *
 * Header
 *
 */

#include "ft_ls.h"

char    determine_file_type(t_file *file)
{
	int file_type;

	file_type = file->entry->st_mode & S_IFMT;
	if (S_ISDIR(file_type))
		return ('d');
	else if (S_ISLNK(file_type))
		return ('l');
	else if (S_ISREG(file_type))
		return ('-');
	else if (S_ISFIFO(file_type))
		return ('p');
	else if (S_ISCHR(file_type))
		return ('c');
	else if (S_ISBLK(file_type))
		return ('b');
	else if (S_ISSOCK(file_type))
		return ('s');
	else
		return ('?');
}

char    *get_privileges(t_file *file)
{
	char    *res;

	res = (char *)malloc(11);
	res[0] = determine_file_type(file);
	res[1] = file->entry->st_mode & S_IRUSR ? 'r' : '-';
	res[2] = file->entry->st_mode & S_IWUSR ? 'w' : '-';
	res[3] = file->entry->st_mode & S_IXUSR ? 'x' : '-';
	res[4] = file->entry->st_mode & S_IRGRP ? 'r' : '-';
	res[5] = file->entry->st_mode & S_IWGRP ? 'w' : '-';
	res[6] = file->entry->st_mode & S_IXGRP ? 'x' : '-';
	res[7] = file->entry->st_mode & S_IROTH ? 'r' : '-';
	res[8] = file->entry->st_mode & S_IWOTH ? 'w' : '-';
	res[9] = file->entry->st_mode & S_IXOTH ? 'x' : '-';
	res[10] = 0;
	return (res);
}