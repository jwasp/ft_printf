/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwasp <jwasp@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/01 18:44:46 by jwasp             #+#    #+#             */
/*   Updated: 2021/02/01 18:51:35 by jwasp            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_FLAGS_H
# define FT_FLAGS_H

typedef struct		s_flag
{
	int				minus;
	int				zero;
	int				accuracy;
	int				width;
	char			type;
}					t_flags;
t_flags				new_flags(void);

#endif
