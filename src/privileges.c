/**
 *
 * Header
 *
 */

#include "ft_ls.h"

char    determine_file_type(t_file *file)
{
	// TODO hello
	if (isdir(file))
		return ('d');
	else
		return ('-');
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