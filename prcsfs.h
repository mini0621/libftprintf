/* ************************************************************************** */

/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prcsfs.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnishimo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/19 18:43:41 by mnishimo          #+#    #+#             */
/*   Updated: 2018/12/19 18:43:41 by mnishimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRCSFS_H
# define PRCSFS_H

#include "libftprintf.h"

t_funcs	g_prcsfs[] =
{
	{'d', &prcs_d},
	{'i', &prcs_d},
	{'o', &prcs_o},
	{'u', &prcs_u},
	{'x', &prcs_x},
	{'X', &prcs_x},
	{'c', &prcs_c},
	{'s', &prcs_s},
	{'p', &prcs_x},
	{'f', &prcs_f},
	{'e', &prcs_e},
	{'j', &prcs_d},
	{'\0', NULL}
};

#endif
