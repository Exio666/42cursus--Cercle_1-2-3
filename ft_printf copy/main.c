/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsavinel <bsavinel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/17 14:31:39 by bsavinel          #+#    #+#             */
/*   Updated: 2021/12/19 14:20:38 by bsavinel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "printf.h"
//int		ft_printf(const char *str, ...);

int	main(void)
{
	ft_printf("====== TEST char =====\n");
	printf("|%i\n", ft_printf("%0c", 'c'));
	printf("|%i\n", ft_printf("%2c", 'c'));
	printf("|%i\n", ft_printf("%0-12c", 'c'));
	printf("|%i\n", ft_printf("%.0c", 'c'));
	printf("|%i\n", ft_printf("%.35c", 'c'));
	ft_printf("====== TEST str =====\n");
	printf("|%i\n", ft_printf("%0s", "truc"));
	printf("|%i\n", ft_printf("%4s", "truc"));
	printf("|%i\n", ft_printf("%10s", "truc"));
	ft_printf("   ** str null **\n");
	printf("|%i\n", ft_printf("%5s", NULL));
	printf("|%i\n", ft_printf("%8s", NULL));
	printf("|%i\n", ft_printf("%.5s", NULL));
	printf("|%i\n", ft_printf("%.8s", NULL));
	printf("|%i\n", ft_printf("%10.8s", NULL));
	printf("|%i\n", ft_printf("%2.8s", NULL));
	printf("|%i\n", ft_printf("%2.4s", NULL));
	printf("|%i\n", ft_printf("%2.-4s", NULL));
	ft_printf("   **  fin str null **\n");
	printf("|%i\n", ft_printf("%.0s", "truc"));
	printf("|%i\n", ft_printf("%.3s", "truc"));
	printf("|%i\n", ft_printf("%.10s", "truc"));
	printf("|%i\n", ft_printf("%10.3s", "truc"));
	ft_printf("====== TEST unsigned =====\n");
	printf("|%i\n", ft_printf("%+ #u", 15));
	printf("|%i\n", ft_printf("%4u", 15));
	printf("|%i\n", ft_printf("%-4u", 15));
	printf("|%i\n", ft_printf("%04u", 15));
	printf("|%i\n", ft_printf("%0-4u", 15));
	printf("|%i\n", ft_printf("%+ #u", 15));
	printf("|%i\n", ft_printf("%.4u", 15));
	printf("|%i\n", ft_printf("%.2u", 15));
	printf("|%i\n", ft_printf("%6.4u", 15));
	printf("|%i\n", ft_printf("%2.4u", 15));
	printf("|%i\n", ft_printf("%06.4u", 15));
	ft_printf("====== TEST decimal =====\n");
	printf("|%i\n", ft_printf("%d", -15));
	printf("|%i\n", ft_printf("%d", -15));
	
}
/*


	printf("====== TEST char =====\n");
	printf("|%i\n", printf("%0c", 'c'));
	printf("|%i\n", printf("%2c", 'c'));
	printf("|%i\n", printf("%0-12c", 'c'));
	printf("|%i\n", printf("%.0c", 'c'));
	printf("|%i\n", printf("%.35c", 'c'));
	printf("====== TEST str =====\n");
	printf("|%i\n", printf("%0s", "truc"));
	printf("|%i\n", printf("%4s", "truc"));
	printf("|%i\n", printf("%10s", "truc"));
	printf("   ** str null **\n");
	printf("|%i\n", printf("%5s", NULL));
	printf("|%i\n", printf("%8s", NULL));
	printf("|%i\n", printf("%.5s", NULL));
	printf("|%i\n", printf("%.8s", NULL));
	printf("|%i\n", printf("%10.8s", NULL));
	printf("|%i\n", printf("%2.8s", NULL));
	printf("|%i\n", printf("%2.4s", NULL));
	printf("|%i\n", printf("%2.-4s", NULL));
	printf("   **  fin str null **\n");
	printf("|%i\n", printf("%.0s", "truc"));
	printf("|%i\n", printf("%.3s", "truc"));
	printf("|%i\n", printf("%.10s", "truc"));
	printf("|%i\n", printf("%10.3s", "truc"));
	printf("====== TEST unsigned =====\n");
	printf("|%i\n", printf("%+ #u", 15));
	printf("|%i\n", printf("%4u", 15));
	printf("|%i\n", printf("%-4u", 15));
	printf("|%i\n", printf("%04u", 15));
	printf("|%i\n", printf("%0-4u", 15));
	printf("|%i\n", printf("%+ #u", 15));
	printf("|%i\n", printf("%.4u", 15));
	printf("|%i\n", printf("%.2u", 15));
	printf("|%i\n", printf("%6.4u", 15));
	printf("|%i\n", printf("%2.4u", 15));
	printf("|%i\n", printf("%06.4u", 15));
*/