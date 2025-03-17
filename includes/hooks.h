/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cadlard <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 18:33:09 by cadlard           #+#    #+#             */
/*   Updated: 2025/03/17 18:55:42 by cadlard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HOOKS_H
# define HOOKS_H

# include "mlx_setup.h"

// WRONG
# define ESCAPE_KEYCODE 53
# define UP_ARROW 126
# define DOWN_ARROW 125
# define LEFT_ARROW 123
# define RIGHT_ARROW 124

int	loop_hook(t_hook_vars *hook_vars);
int	key_hook(int keycode, t_hook_vars *hook_vars);
int	mouse_hook(int mousecode, int x, int y, t_hook_vars *hook_vars);
int	exit_cleanly(t_hook_vars *hook_vars);

#endif
