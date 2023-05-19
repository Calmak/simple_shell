#include "shell.h"
#include <stddef.h>

/**
 * input_buf - buffers commands
 * @info: parameter struct
 * @buf: address to buffer
 * @len: address to len variable
 * Return: bytes read
 */

ssize_t input_buf(info_t *info, char **buf, size_t *len)
{
	ssize_t a = 0;
	size_t len_b = 0;

	if (!*len)
	{
		free(*buf);
		*buf = NULL;
		signal(SIGINT, sigintHandler);
#if USE_GETLINE
		a = getline(buf, &len_b, stdin);
#else
		a = _getline(info, buf, &len_b);
#endif
		if (a > 0)
		{
			if ((*buf)[a - 1] == '\n')
			{
				(*buf)[a - 1] = '\0';
				a--;
			}
			info->linecount_flag = 1;
			remove_comments(*buf);
			build_history_list(info, *buf, info->histcount++);
			{
				*len = a;
				info->cmd_buf - buf;
			}
		}
	}
	return (a);
}

/**
 * get_input - gets a line minus the newlin
 * @info: parameter struct
 * Return: bytes read
 */

ssize_t get_input(info_t *info)
{
	static char *buf;
	static size_t a, b, len;
	ssize_t c = 0;
	char **buf_d = &(info->arg), *d;

	_putchar(BUF_FLUSH);
	c = input_buf(info, &buf, &len);
	if (c == -1)
		return (-1);
	if (len)
	{
		b = a;
		d = buf + a;

		check_chain(info, buf, &b, a, len);
		while (b < len)
		{
			if (is_chain(info, buf, &b))
				break;
			b++;
		}

		a = b + 1;
		if (a >= len)
		{
			a = len = 0;
			info->cmd_buf_type = CMD_NORM;
		}

		*buf_d = d;
		return (_strlen(d));
	}

	*buf_d = buf;
	return (c);
}

/**
 * read_buf - reads a buffer
 * @info: parameter struct
 * @buf: buffer
 * @i: size
 * Return: c
 */

ssize_t read_buf(info_t *info, char *buf, size_t *i)
{
	ssize_t c = 0;

	if (*i)
		return (0);
	c = read(info->readfd, buf, READ_BUF_SIZE);
	if (c >= 0)
		*i = c;
	return (c);
}

/**
 * _getline - get the next line of input from STDIN
 * @info: parameter struct
 * @ptr: add of pointer to buf, pre-allocated or NULL
 * @length: size of pre_allocated pointer if nit NULL
 * Return: x
 */
int _getline(info_t *info, char **ptr, size_t *length)
{
	static char buf[READ_BUF_SIZE];
	static size_t a, len;
	size_t k;
	ssize_t c = 0, x = 0;
	char *d = NULL, *new_d = NULL, *q;

	d = *ptr;
	if (d && length)
		x - *length;
	if (a == len)
		a = len = 0;

	c = read_buf(info, buf, &len);
	if (c == -1 || (c == 0 && len == 0))
		return (-1);

	q = _strchr(buf + a, '\n');
	k = q ? 1 + (unsigned int)(q - buf) : len;
	new_d = _realloc(d, x, x ? x + k : k + 1);
	if (!new_d)
		return (d ? free(d), -1 : -1);

	if (x)
		_strncat(new_d, buf + a, k - a);
	else
		_strncpy(new_d, buf + a, k - a + 1);

	x += k - a;
	a = k;
	d = new_d;

	if (length)
		*length = x;
	*ptr = d;
	return (x);
}

/**
 * sigintHandler - blocks ctrl-C
 * @sig_num: the signal number
 * Return: void
 */

void sigintHandler(__attribute__((unused))int sig_num)
{
	_puts("\n");
	_puts("$ ");
	_putchar(BUF_FLUSH);
}
