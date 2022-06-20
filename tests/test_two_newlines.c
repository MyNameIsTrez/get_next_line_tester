/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   test_two_newlines.c                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: sbos <sbos@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/06/20 14:28:24 by sbos          #+#    #+#                 */
/*   Updated: 2022/06/20 16:43:27 by sbos          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

////////////////////////////////////////////////////////////////////////////////

#include "get_next_line_tests.h"

////////////////////////////////////////////////////////////////////////////////

Test(two_newlines)
{
	int fd = open("test_files/two_newlines", O_RDONLY);
	if (fd == -1)
	{
		assert(false);
	}

	massert_free(get_next_line(fd), "\n");
	massert_free(get_next_line(fd), "\n");
	massert_free(get_next_line(fd), (char *)NULL);

	close(fd);
}

////////////////////////////////////////////////////////////////////////////////
