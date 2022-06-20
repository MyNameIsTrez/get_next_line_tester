/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   test_real_empty.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: sbos <sbos@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/06/20 14:28:24 by sbos          #+#    #+#                 */
/*   Updated: 2022/06/20 15:51:43 by sbos          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

////////////////////////////////////////////////////////////////////////////////

#include "get_next_line_tests.h"

////////////////////////////////////////////////////////////////////////////////

Test(empty)
{
	int fd = open("test_files/empty", O_RDONLY);
	if (fd == -1)
	{
		assert(false);
	}
	massert(get_next_line(fd), (char *)NULL);
}

////////////////////////////////////////////////////////////////////////////////