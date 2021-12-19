/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsavinel <bsavinel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/18 16:39:45 by bsavinel          #+#    #+#             */
/*   Updated: 2021/12/19 13:15:04 by bsavinel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
int		ft_printf(const char *str, ...);

int	main(void)
{
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
	printf("====== TEST decimal =====\n");
	printf("|%i\n", printf("%06d", -15));
	printf("|%i\n", printf("%06.d", -15));
}
