/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsavinel <bsavinel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/17 14:31:39 by bsavinel          #+#    #+#             */
/*   Updated: 2021/12/17 17:29:55 by bsavinel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

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
	printf("   ** 6str null **\n");
	printf("|%i\n", printf("%5s", NULL));
	printf("|%i\n", printf("%8s", NULL));
	printf("|%i\n", printf("%.5s", NULL));
	printf("|%i\n", printf("%.8s", NULL));
	printf("|%i\n", printf("%10.8s", NULL));
	printf("|%i\n", printf("%2.8s", NULL));
	printf("|%i\n", printf("%2.4s", NULL));
	printf("|%i\n", printf("%.0s", "truc"));
	printf("|%i\n", printf("%.3s", "truc"));
	printf("|%i\n", printf("%.10s", "truc"));
	printf("|%i\n", printf("%10.3s", "truc"));
}
