/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   test_binary.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: sbos <sbos@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/06/20 14:28:24 by sbos          #+#    #+#                 */
/*   Updated: 2022/06/20 16:41:16 by sbos          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

////////////////////////////////////////////////////////////////////////////////

#include "get_next_line_tests.h"

////////////////////////////////////////////////////////////////////////////////

Test(binary)
{
	int fd = open("test_files/binary", O_RDONLY);
	if (fd == -1)
	{
		assert(false);
	}

	// massert(get_next_line(fd), (char *)NULL);

	char *out = get_next_line(fd);
	massert(out, "world\0hello\n");
	massert(memcmp(out, "world\0hello\n", 13), 0);
	massert_free(get_next_line(fd), "bye");
	massert_free(get_next_line(fd), (char *)NULL);
	free(out);

	close(fd);
}

////////////////////////////////////////////////////////////////////////////////
