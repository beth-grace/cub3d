/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cadlard <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 18:33:09 by cadlard           #+#    #+#             */
/*   Updated: 2025/03/20 12:14:03 by cadlard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HOOKS_H
# define HOOKS_H

# include "mlx_setup.h"

int	loop_hook(t_hook_vars *hook_vars);
int	key_hook(int keycode, t_hook_vars *hook_vars);
int	mouse_hook(int mousecode, int x, int y, t_hook_vars *hook_vars);
int	exit_cleanly(t_hook_vars *hook_vars);

#endif
