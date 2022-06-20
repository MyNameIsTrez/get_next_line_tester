/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   test_basic_with_newline_end.c                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: sbos <sbos@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/06/20 14:28:24 by sbos          #+#    #+#                 */
/*   Updated: 2022/06/20 16:40:58 by sbos          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

////////////////////////////////////////////////////////////////////////////////

#include "get_next_line_tests.h"

////////////////////////////////////////////////////////////////////////////////

Test(basic_with_newline_end)
{
	int fd = open("test_files/basic_with_newline_end", O_RDONLY);
	if (fd == -1)
	{
		assert(false);
	}

	massert_free(get_next_line(fd), "foobar\n");
	massert_free(get_next_line(fd), "bazbee\n");
	massert_free(get_next_line(fd), (char *)NULL);

	close(fd);
}

////////////////////////////////////////////////////////////////////////////////
