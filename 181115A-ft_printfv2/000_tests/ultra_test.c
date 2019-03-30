/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ultra_test.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yforeau <yforeau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/03 18:35:34 by yforeau           #+#    #+#             */
/*   Updated: 2018/11/04 19:28:29 by yforeau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "include/ft_printf.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <limits.h>
#include <float.h>
#include <locale.h>
#include <stdint.h>
#include <wchar.h>

#define STR "Martine va en enfer\n"

//======================================================> conv_s

void	test_s_01(void)
{
	int ret1 = 0;
	int ret2 = 0;

	printf("Test_s => 01\n");
	ret1 = printf("orig : %s\n", "poney");
	ret2 = ft_printf("cust : %s\n", "poney");
	printf("\n");
	printf("ret_orig : %d\n", ret1);
	printf("ret_cust : %d\n", ret2);
	printf("\n");
}

void	test_s_02(void)
{
	int ret1 = 0;
	int ret2 = 0;

	printf("Test_s => 02\n");
	ret1 = printf("orig : %s\n" "4", "poney");
	ret2 = ft_printf("cust : %s\n" "4", "poney");
	printf("\n");
	printf("ret_orig : %d\n", ret1);
	printf("ret_cust : %d\n", ret2);
	printf("\n");
}

void	test_s_03(void)
{
	int ret1 = 0;
	int ret2 = 0;

	printf("Test_s => 03\n");
	ret1 = printf("orig : %s " "a1 " "a2 " "a3 " "\n", "poney");
	ret2 = ft_printf("cust : %s " "a1 " "a2 " "a3 " "\n", "poney");
	printf("\n");
	printf("ret_orig : %d\n", ret1);
	printf("ret_cust : %d\n", ret2);
	printf("\n");
}

void	test_s_04(void)
{
	int ret1 = 0;
	int ret2 = 0;

	printf("Test_s => 04\n");
	ret1 = printf("orig : %s\n", "poney truite");
	ret2 = ft_printf("cust : %s\n", "poney truite");
	printf("\n");
	printf("ret_orig : %d\n", ret1);
	printf("ret_cust : %d\n", ret2);
	printf("\n");
}

void	test_s_05(void)
{
	int ret1 = 0;
	int ret2 = 0;

	printf("Test_s => 05\n");
	ret1 = printf("orig : %4s\n", "poney truite");
	ret2 = ft_printf("cust : %4s\n", "poney truite");
	printf("\n");
	printf("ret_orig : %d\n", ret1);
	printf("ret_cust : %d\n", ret2);
	printf("\n");
}

void	test_s_06(void)
{
	int ret1 = 0;
	int ret2 = 0;

	printf("Test_s => 06\n");
	ret1 = printf("orig : %22s\n", "poney truite");
	ret2 = ft_printf("cust : %22s\n", "poney truite");
	printf("\n");
	printf("ret_orig : %d\n", ret1);
	printf("ret_cust : %d\n", ret2);
	printf("\n");
}

void	test_s_07(void)
{
	int ret1 = 0;
	int ret2 = 0;

	printf("Test_s => 07\n");
	ret1 = printf("orig : %.s\n", "poney truite");
	ret2 = ft_printf("cust : %.s\n", "poney truite");
	printf("\n");
	printf("ret_orig : %d\n", ret1);
	printf("ret_cust : %d\n", ret2);
	printf("\n");
}

void	test_s_08(void)
{
	int ret1 = 0;
	int ret2 = 0;

	printf("Test_s => 08\n");
	ret1 = printf("orig : %.4s\n", "poney truite");
	ret2 = ft_printf("cust : %.4s\n", "poney truite");
	printf("\n");
	printf("ret_orig : %d\n", ret1);
	printf("ret_cust : %d\n", ret2);
	printf("\n");
}

void	test_s_09(void)
{
	int ret1 = 0;
	int ret2 = 0;

	printf("Test_s => 09\n");
	ret1 = printf("orig : %.20s\n", "poney truite");
	ret2 = ft_printf("cust : %.20s\n", "poney truite");
	printf("\n");
	printf("ret_orig : %d\n", ret1);
	printf("ret_cust : %d\n", ret2);
	printf("\n");
}

void	test_s_10(void)
{
	int ret1 = 0;
	int ret2 = 0;

	printf("Test_s => 10\n");
	ret1 = printf("orig : %30.7s\n", STR);
	ret2 = ft_printf("cust : %30.7s\n", STR);
	printf("\n");
	printf("ret_orig : %d\n", ret1);
	printf("ret_cust : %d\n", ret2);
	printf("\n");
}

void	test_s_11(void)
{
	int ret1 = 0;
	int ret2 = 0;

	printf("Test_s => 11\n");
	ret1 = printf("orig : %-30.7s\n", STR);
	ret2 = ft_printf("cust : %-30.7s\n", STR);
	printf("\n");
	printf("ret_orig : %d\n", ret1);
	printf("ret_cust : %d\n", ret2);
	printf("\n");
}

void	test_s_12(void)
{
	int ret1 = 0;
	int ret2 = 0;

	printf("Test_s => 12\n");
	ret1 = printf("orig : %-6.7s %s %-2.9s %s\n", STR, " ", "mange des tartes", "zombies");
	ret2 = ft_printf("cust : %-6.7s %s %-2.9s %s\n", STR, " ", "mange des tartes", "zombies");
	printf("\n");
	printf("ret_orig : %d\n", ret1);
	printf("ret_cust : %d\n", ret2);
	printf("\n");
}

void	test_s_13(void)
{
	int ret1 = 0;
	int ret2 = 0;

	printf("Test_s => 13\n");
	ret1 = printf("orig : %-6.7s %s %-2.9s %s\n" " r2d2 %10s\n", STR, " ", "mange des tartes", "zombies", "chips");
	ret2 = ft_printf("cust : %-6.7s %s %-2.9s %s\n" " r2d2 %10s\n", STR, " ", "mange des tartes", "zombies", "chips");
	printf("\n");
	printf("ret_orig : %d\n", ret1);
	printf("ret_cust : %d\n", ret2);
	printf("\n");
}

void	test_s_14(void)
{
	int ret1 = 0;
	int ret2 = 0;

	printf("Test_s => 14\n");
	 //ft_printf("@moulitest: %s", NULL);
	ret1 = printf("orig : %20.0s\n", NULL);
	ret2 = ft_printf("cust : %20.0s\n", NULL);
	printf("\n");
	printf("ret_orig : %d\n", ret1);
	printf("ret_cust : %d\n", ret2);
	printf("\n");
}

void	test_s_15(void)
{
	int ret1 = 0;
	int ret2 = 0;

	printf("Test_s => 15\n");
	 //ft_printf("@moulitest: %s", NULL);
	ret1 = printf("orig : %-12s*\n", NULL);
	ret2 = ft_printf("cust : %-12s*\n", NULL);
	printf("\n");
	printf("ret_orig : %d\n", ret1);
	printf("ret_cust : %d\n", ret2);
	printf("\n");
}

void	test_s_16(void)
{
	int ret1 = 0;
	int ret2 = 0;

	printf("Test_s => 16\n");
	 //ft_printf("@moulitest: %s", NULL);
	ret1 = printf("orig : %20.0s*\n", "toy story");
	ret2 = ft_printf("cust : %20.0s*\n", "toy story");
	printf("\n");
	printf("ret_orig : %d\n", ret1);
	printf("ret_cust : %d\n", ret2);
	printf("\n");
}

void	test_s_17(void)
{
	int ret1 = 0;
	int ret2 = 0;

	printf("Test_s => 17\n");
	ret1 = printf("orig : {%05.s}\n", 0);
	ret2 = ft_printf("cust : {%05.s}\n", 0);
	printf("\n");
	printf("ret_orig : %d\n", ret1);
	printf("ret_cust : %d\n", ret2);
	printf("\n");
}

void	test_s_18(void)
{
	int ret1 = 0;
	int ret2 = 0;

	printf("Test_s => 18\n");
	ret1 = printf("orig : {%.0s}\n", 0);
	ret2 = ft_printf("cust : {%.0s}\n", 0);
	printf("\n");
	printf("ret_orig : %d\n", ret1);
	printf("ret_cust : %d\n", ret2);
	printf("\n");
}

/*
void	test_s_14(void)
{
	int ret1 = 0;
	int ret2 = 0;

	printf("Test_s => 14\n");
	ret1 = printf("orig : %-6.7s %s %-2.9s %s\n" " r2d2 %10s", STR, " ", "mange des tartes", "zombies", "chips");
	ret2 = ft_printf("orig : %-6.7s %s %-2.9s %s\n" " r2d2 %10s", STR, " ", "mange des tartes", "zombies", "chips");
	printf("\n");
	printf("ret_orig : %d\n", ret1);
	printf("ret_cust : %d\n", ret2);
	printf("\n");
}

*/
/*
void	test_s_16(void)
{
	int ret1 = 0;
	int ret2 = 0;

	printf("Test_s => 16\n");
	ret1 = printf("orig : %s\n", NULL);
	ret2 = ft_printf("orig : %s\n", NULL);
	printf("\n");
	printf("ret_orig : %d\n", ret1);
	printf("ret_cust : %d\n", ret2);
	printf("\n");
}
*/
//
// void	test_s_13(void)
// {
// 	int ret1 = 0;
// 	int ret2 = 0;
//
// 	printf("Test_s => 13\n");
// 	ret1 = printf("orig : %025s\n", "steak hache");
// 	ret2 = ft_printf("cust : %025s\n", "steak hache");
// 	printf("\n");
// 	printf("ret_orig : %d\n", ret1);
// 	printf("ret_cust : %d\n", ret2);
// 	printf("\n");
// }



//=====================================================> conv_S

void	test_ls_01(void)
{
	int ret1 = 0;
	int ret2 = 0;

	setlocale(LC_ALL, "");
	printf("Test_S => 01\n");
	ret1 = printf("orig : %S\n", L"chewing gum🤗 🤗 🤗 🤗\0");
	ret2 = ft_printf("cust : %S\n", L"chewing gum🤗 🤗 🤗 🤗\0");
	printf("\n");
	printf("ret_orig : %d\n", ret1);
	printf("ret_cust : %d\n", ret2);
	printf("\n");
}

void	test_ls_02(void)
{
	int ret1 = 0;
	int ret2 = 0;

	setlocale(LC_ALL, "");
	printf("Test_S => 02\n");
	ret1 = printf("orig : %45S\n", L"chewing gum🤗 🤗 🤗 🤗\0");
	ret2 = ft_printf("cust : %45S\n", L"chewing gum🤗 🤗 🤗 🤗\0");
	printf("\n");
	printf("ret_orig : %d\n", ret1);
	printf("ret_cust : %d\n", ret2);
	printf("\n");
}

void	test_ls_03(void)
{
	int ret1 = 0;
	int ret2 = 0;

	setlocale(LC_ALL, "");
	printf("Test_S => 03\n");
	ret1 = printf("orig : %5S\n", L"🤗");
	ret2 = ft_printf("cust : %5S\n", L"🤗");
	printf("\n");
	printf("ret_orig : %d\n", ret1);
	printf("ret_cust : %d\n", ret2);
	printf("\n");
}

void	test_ls_04(void)
{
	int ret1 = 0;
	int ret2 = 0;

	setlocale(LC_ALL, "");
	printf("Test_S => 04\n");
	ret1 = printf("orig : %5S\n", L"©");
	ret2 = ft_printf("cust : %5S\n", L"©");
	printf("\n");
	printf("ret_orig : %d\n", ret1);
	printf("ret_cust : %d\n", ret2);
	printf("\n");
}

void	test_ls_05(void)
{
	int ret1 = 0;
	int ret2 = 0;

	setlocale(LC_ALL, "");
	printf("Test_S => 05\n");
	ret1 = printf("orig : %5S\n", L"ᚙ");
	ret2 = ft_printf("cust : %5S\n", L"ᚙ");
	printf("\n");
	printf("ret_orig : %d\n", ret1);
	printf("ret_cust : %d\n", ret2);
	printf("\n");
}

void	test_ls_06(void)
{
	int ret1 = 0;
	int ret2 = 0;

	setlocale(LC_ALL, "");
	printf("Test_S => 06\n");
	ret1 = printf("orig : %S\n", L"123456🤗");
	ret2 = ft_printf("cust : %S\n", L"123456🤗");
	printf("\n");
	printf("ret_orig : %d\n", ret1);
	printf("ret_cust : %d\n", ret2);
	printf("\n");
}

void	test_ls_07(void)
{
	int ret1 = 0;
	int ret2 = 0;

	setlocale(LC_ALL, "");
	printf("Test_S => 07\n");
	ret1 = printf("orig : %S\n", L"🤗🤗🤗🤗");
	ret2 = ft_printf("cust : %S\n", L"🤗🤗🤗🤗");
	printf("\n");
	printf("ret_orig : %d\n", ret1);
	printf("ret_cust : %d\n", ret2);
	printf("\n");
}

void	test_ls_08(void)
{
	int ret1 = 0;
	int ret2 = 0;

	setlocale(LC_ALL, "");
	printf("Test_S => 08\n");
	ret1 = printf("orig : %S\n", L"🤗🤗");
	ret2 = ft_printf("cust : %S\n", L"🤗🤗");
	printf("\n");
	printf("ret_orig : %d\n", ret1);
	printf("ret_cust : %d\n", ret2);
	printf("\n");
}

void	test_ls_09(void)
{
	int ret1 = 0;
	int ret2 = 0;

	setlocale(LC_ALL, "");
	printf("Test_S => 09\n");
	ret1 = printf("orig : %2S\n", L"🤗🤗🤗🤗");
	ret2 = ft_printf("cust : %2S\n", L"🤗🤗🤗🤗");
	printf("\n");
	printf("ret_orig : %d\n", ret1);
	printf("ret_cust : %d\n", ret2);
	printf("\n");
}

void	test_ls_10(void)
{
	int ret1 = 0;
	int ret2 = 0;

	setlocale(LC_ALL, "");
	printf("Test_S => 10\n");
	ret1 = printf("orig : %15S\n", NULL);
	ret2 = ft_printf("cust : %15S\n", NULL);
	printf("\n");
	printf("ret_orig : %d\n", ret1);
	printf("ret_cust : %d\n", ret2);
	printf("\n");
}

void	test_ls_11(void)
{
	int ret1 = 0;
	int ret2 = 0;

	setlocale(LC_ALL, "");
	printf("Test_S => 11\n");
	ret1 = printf("orig : %.3S\n", NULL);
	ret2 = ft_printf("cust : %.3S\n", NULL);
	printf("\n");
	printf("ret_orig : %d\n", ret1);
	printf("ret_cust : %d\n", ret2);
	printf("\n");
}

void	test_ls_12(void)
{
	int ret1 = 0;
	int ret2 = 0;

	setlocale(LC_ALL, "");
	printf("Test_S => 12\n");
	ret1 = printf("orig : %.10S\n", L"Valgrind ©©©©");
	ret2 = ft_printf("cust : %.10S\n", L"Valgrind ©©©©");
	printf("\n");
	printf("ret_orig : %d\n", ret1);
	printf("ret_cust : %d\n", ret2);
	printf("\n");
}

void	test_ls_13(void)
{
	int ret1 = 0;
	int ret2 = 0;

	setlocale(LC_ALL, "");
	printf("Test_S => 13\n");
	ret1 = printf("orig : %.5S\n", L"Valgrind ©©©©");
	ret2 = ft_printf("cust : %.5S\n", L"Valgrind ©©©©");
	printf("\n");
	printf("ret_orig : %d\n", ret1);
	printf("ret_cust : %d\n", ret2);
	printf("\n");
}

void	test_ls_14(void)
{
	int ret1 = 0;
	int ret2 = 0;

	setlocale(LC_ALL, "");
	printf("Test_S => 14\n");
	ret1 = printf("orig : %.11S\n", L"Valgrind ©©©©");
	ret2 = ft_printf("cust : %.11S\n", L"Valgrind ©©©©");
	printf("\n");
	printf("ret_orig : %d\n", ret1);
	printf("ret_cust : %d\n", ret2);
	printf("\n");
}

void	test_ls_15(void)
{
	int ret1 = 0;
	int ret2 = 0;

	setlocale(LC_ALL, "");
	printf("Test_S => 15\n");
	ret1 = printf("orig : %.12S\n", L"Valgrind ©©©©");
	ret2 = ft_printf("cust : %.12S\n", L"Valgrind ©©©©");
	printf("\n");
	printf("ret_orig : %d\n", ret1);
	printf("ret_cust : %d\n", ret2);
	printf("\n");
}

void	test_ls_16(void)
{
	int ret1 = 0;
	int ret2 = 0;

	setlocale(LC_ALL, "");
	printf("Test_S => 16\n");
	ret1 = printf("orig : %.12S\n", L"Valgrind ©🀙");
	ret2 = ft_printf("cust : %.12S\n", L"Valgrind ©🀙");
	printf("\n");
	printf("ret_orig : %d\n", ret1);
	printf("ret_cust : %d\n", ret2);
	printf("\n");
}

void	test_ls_17(void)
{
	int ret1 = 0;
	int ret2 = 0;

	setlocale(LC_ALL, "");
	printf("Test_S => 17\n");
	ret1 = printf("orig : %S, %S\n", L"暖炉", L"لحم خنزير");
	ret2 = ft_printf("cust : %S, %S\n", L"暖炉", L"لحم خنزير");
	printf("\n");
	printf("ret_orig : %d\n", ret1);
	printf("ret_cust : %d\n", ret2);
	printf("\n");
}

void	test_ls_18(void)
{
	int ret1 = 0;
	int ret2 = 0;

	setlocale(LC_ALL, "");
	printf("Test_S => 18\n");
	ret1 = printf("orig : %030S\n", L"©©©");
	ret2 = ft_printf("cust : %030S\n", L"©©©");
	printf("\n");
	printf("ret_orig : %d\n", ret1);
	printf("ret_cust : %d\n", ret2);
	printf("\n");
}

void	test_ls_19(void)
{
	int ret1 = 0;
	int ret2 = 0;

	setlocale(LC_ALL, "");
	printf("Test_S => 19\n");
	ret1 = printf("orig : {%05.S}\n", L"42 c est cool");
	ret2 = ft_printf("cust : {%05.S}\n", L"42 c est cool");
	printf("\n");
	printf("ret_orig : %d\n", ret1);
	printf("ret_cust : %d\n", ret2);
	printf("\n");
}

void	test_ls_20(void)
{
	int ret1 = 0;
	int ret2 = 0;

	setlocale(LC_ALL, "");
	printf("Test_S => 20\n");
	ret1 = printf("orig : {%.22S}\n", L"🤗🤗🤗🤗🤗©©");
	ret2 = ft_printf("cust : {%.22S}\n", L"🤗🤗🤗🤗🤗©©");
	printf("\n");
	printf("ret_orig : %d\n", ret1);
	printf("ret_cust : %d\n", ret2);
	printf("\n");
}

//======================================================> conv_d

void	test_d_01(void)
{
	int ret1 = 0;
	int ret2 = 0;

	printf("Test_d => 01\n");
	ret1 = printf("orig : %d\n", 42);
	ret2 = ft_printf("cust : %d\n", 42);
	printf("\n");
	printf("ret_orig : %d\n", ret1);
	printf("ret_cust : %d\n", ret2);
	printf("\n");
}

void	test_d_02(void)
{
	int ret1 = 0;
	int ret2 = 0;

	printf("Test_d => 02\n");
	ret1 = printf("orig : %d\n", INT_MIN);
	ret2 = ft_printf("cust : %d\n", INT_MIN);
	printf("\n");
	printf("ret_orig : %d\n", ret1);
	printf("ret_cust : %d\n", ret2);
	printf("\n");
}

void	test_d_03(void)
{
	int ret1 = 0;
	int ret2 = 0;

	printf("Test_d => 03\n");
	ret1 = printf("orig : %d\n", INT_MAX);
	ret2 = ft_printf("cust : %d\n", INT_MAX);
	printf("\n");
	printf("ret_orig : %d\n", ret1);
	printf("ret_cust : %d\n", ret2);
	printf("\n");
}

void	test_d_04(void)
{
	int ret1 = 0;
	int ret2 = 0;

	printf("Test_d => 04\n");
	ret1 = printf("orig : %.8d\n", 25);
	ret2 = ft_printf("cust : %.8d\n", 25);
	printf("\n");
	printf("ret_orig : %d\n", ret1);
	printf("ret_cust : %d\n", ret2);
	printf("\n");
}

void	test_d_05(void)
{
	long a = LONG_MIN;
	int ret1 = 0;
	int ret2 = 0;

	printf("Test_d => 05\n");
	ret1 = printf("orig : %ld\n", a);
	ret2 = ft_printf("cust : %ld\n", a);
	printf("\n");
	printf("ret_orig : %d\n", ret1);
	printf("ret_cust : %d\n", ret2);
	printf("\n");
}

void	test_d_06(void)
{
	int ret1 = 0;
	int ret2 = 0;

	printf("Test_d => 06\n");
	ret1 = printf("orig : %.08d\n", 25);
	ret2 = ft_printf("cust : %.08d\n", 25);
	printf("\n");
	printf("ret_orig : %d\n", ret1);
	printf("ret_cust : %d\n", ret2);
	printf("\n");
}

void	test_d_07(void)
{
	int ret1 = 0;
	int ret2 = 0;

	printf("Test_d => 07\n");
	ret1 = printf("orig : %8d\n", -2525);
	ret2 = ft_printf("cust : %8d\n", -2525);
	printf("\n");
	printf("ret_orig : %d\n", ret1);
	printf("ret_cust : %d\n", ret2);
	printf("\n");
}

void	test_d_08(void)
{
	char a = CHAR_MAX;
	int ret1 = 0;
	int ret2 = 0;

	printf("Test_d => 08\n");
	ret1 = printf("orig : %hhd\n", a);
	ret2 = ft_printf("cust : %hhd\n", a);
	printf("\n");
	printf("ret_orig : %d\n", ret1);
	printf("ret_cust : %d\n", ret2);
	printf("\n");
}

void	test_d_09(void)
{
	char a = CHAR_MIN;
	int ret1 = 0;
	int ret2 = 0;

	printf("Test_d => 09\n");
	ret1 = printf("orig : %hhd\n", a);
	ret2 = ft_printf("cust : %hhd\n", a);
	printf("\n");
	printf("ret_orig : %d\n", ret1);
	printf("ret_cust : %d\n", ret2);
	printf("\n");
}

void	test_d_10(void)
{
	size_t a = INT_MAX;
	int ret1 = 0;
	int ret2 = 0;

	printf("Test_d => 10\n");
	ret1 = printf("orig : %zd\n", a);
	ret2 = ft_printf("cust : %zd\n", a);
	printf("\n");
	printf("ret_orig : %d\n", ret1);
	printf("ret_cust : %d\n", ret2);
	printf("\n");
}

void	test_d_11(void)
{
	size_t a = INT_MAX;
	int ret1 = 0;
	int ret2 = 0;

	printf("Test_d => 11\n");
	ret1 = printf("orig : %12zd\n", a);
	ret2 = ft_printf("cust : %12zd\n", a);
	printf("\n");
	printf("ret_orig : %d\n", ret1);
	printf("ret_cust : %d\n", ret2);
	printf("\n");
}

void	test_d_12(void)
{
	short a = SHRT_MAX;
	int ret1 = 0;
	int ret2 = 0;

	printf("Test_d => 12\n");
	ret1 = printf("orig : %hd\n", a);
	ret2 = ft_printf("cust : %hd\n", a);
	printf("\n");
	printf("ret_orig : %d\n", ret1);
	printf("ret_cust : %d\n", ret2);
	printf("\n");
}


void	test_d_13(void)
{
	short a = SHRT_MIN;
	int ret1 = 0;
	int ret2 = 0;

	printf("Test_d => 13\n");
	ret1 = printf("orig : %hd\n", a);
	ret2 = ft_printf("cust : %hd\n", a);
	printf("\n");
	printf("ret_orig : %d\n", ret1);
	printf("ret_cust : %d\n", ret2);
	printf("\n");
}

void	test_d_14(void)
{
	int ret1 = 0;
	int ret2 = 0;

	printf("Test_d => 14\n");
	ret1 = printf("orig : %.12d\n", 50);
	ret2 = ft_printf("cust : %.12d\n", 50);
	printf("\n");
	printf("ret_orig : %d\n", ret1);
	printf("ret_cust : %d\n", ret2);
	printf("\n");
}

void	test_d_15(void)
{
	short a = 126;
	int ret1 = 0;
	int ret2 = 0;

	printf("Test_d => 15\n");
	ret1 = printf("orig : %-.012hd\n", a);
	ret2 = ft_printf("cust : %-.012hd\n", a);
	printf("\n");
	printf("ret_orig : %d\n", ret1);
	printf("ret_cust : %d\n", ret2);
	printf("\n");
}

void	test_d_16(void)
{
	int a = 123456789;
	int ret1 = 0;
	int ret2 = 0;

	printf("Test_d => 16\n");
	ret1 = printf("orig : %.4d\n", a);
	ret2 = ft_printf("cust : %.4d\n", a);
	printf("\n");
	printf("ret_orig : %d\n", ret1);
	printf("ret_cust : %d\n", ret2);
	printf("\n");
}

void	test_d_17(void)
{
	int a = 123456789;
	int ret1 = 0;
	int ret2 = 0;

	printf("Test_d => 17\n");
	ret1 = printf("orig : %.d\n", a);
	ret2 = ft_printf("cust : %.d\n", a);
	printf("\n");
	printf("ret_orig : %d\n", ret1);
	printf("ret_cust : %d\n", ret2);
	printf("\n");
}

void	test_d_18(void)
{
	int a = 42;
	int ret1 = 0;
	int ret2 = 0;

	printf("Test_d => 18\n");
	ret1 = printf("orig : %-.12d\n", a);
	ret2 = ft_printf("cust : %-.12d\n", a);
	printf("\n");
	printf("ret_orig : %d\n", ret1);
	printf("ret_cust : %d\n", ret2);
	printf("\n");
}

void	test_d_19(void)
{
	int a = -42;
	int ret1 = 0;
	int ret2 = 0;

	printf("Test_d => 19\n");
	ret1 = printf("orig : %-25.12d\n", a); //return stupid
	ret2 = ft_printf("cust : %-25.12d\n", a);
	printf("\n");
	printf("ret_orig : %d\n", ret1);
	printf("ret_cust : %d\n", ret2);
	printf("\n");
}

void	test_d_20(void)
{
	int a = 42;
	int ret1 = 0;
	int ret2 = 0;

	printf("Test_d => 20\n");
	ret1 = printf("orig : %.*d\n", 5, a);
	ret2 = ft_printf("cust : %.*d\n", 5, a);
	printf("\n");
	printf("ret_orig : %d\n", ret1);
	printf("ret_cust : %d\n", ret2);
	printf("\n");
}

void	test_d_21(void)
{
	int a = -42;
	int ret1 = 0;
	int ret2 = 0;

	printf("Test_d => 21\n");
	ret1 = printf("orig : %.*d\n", 5, a);
	ret2 = ft_printf("cust : %.*d\n", 5, a);
	printf("\n");
	printf("ret_orig : %d\n", ret1);
	printf("ret_cust : %d\n", ret2);
	printf("\n");
}

void	test_d_22(void)
{
	int a = -2525;
	int ret1 = 0;
	int ret2 = 0;

	printf("Test_d => 22\n");
	ret1 = printf("orig : %10.5d\n", a);
	// ret1 = printf("orig : %10d\n", a);
	ret2 = ft_printf("cust : %10.5d\n", a);
	printf("\n");
	printf("ret_orig : %d\n", ret1);
	printf("ret_cust : %d\n", ret2);
	printf("\n");
}

void	test_d_23(void)
{
	int ret1 = 0;
	int ret2 = 0;

	printf("Test_d => 23\n");
	ret1 = printf("orig : %.8d\n", 585);
	ret2 = ft_printf("cust : %.8d\n", 585);
	printf("\n");
	printf("ret_orig : %d\n", ret1);
	printf("ret_cust : %d\n", ret2);
	printf("\n");
}

void	test_d_24(void)
{
	int a = -42;
	int ret1 = 0;
	int ret2 = 0;

	printf("Test_d => 24\n");
	ret1 = printf("orig : %020.10d\n", a); //return stupid
	ret2 = ft_printf("cust : %020.10d\n", a);
	//width of 50, justify left precision of 12
	printf("\n");
	printf("ret_orig : %d\n", ret1);
	printf("ret_cust : %d\n", ret2);
	printf("\n");
}

void	test_d_25(void)
{
	int a = -12345678;
	int ret1 = 0;
	int ret2 = 0;

	printf("Test_d => 25\n");
	ret1 = printf("orig : %012.1d\n", a); //return stupid
	ret2 = ft_printf("cust : %012.1d\n", a);
	printf("\n");
	printf("ret_orig : %d\n", ret1);
	printf("ret_cust : %d\n", ret2);
	printf("\n");
}

void	test_d_26(void)
{
	int ret1 = 0;
	int ret2 = 0;

	printf("Test_d => 26\n");
	ret1 = printf("orig : %-.8d\n", 585);
	ret2 = ft_printf("cust : %-.8d\n", 585);
	printf("\n");
	printf("ret_orig : %d\n", ret1);
	printf("ret_cust : %d\n", ret2);
	printf("\n");
}

void	test_d_27(void)
{
	int ret1 = 0;
	int ret2 = 0;

	printf("Test_d => 27\n");
	ret1 = printf("orig : %-8d\n", 585);
	ret2 = ft_printf("cust : %-8d\n", 585);
	printf("\n");
	printf("ret_orig : %d\n", ret1);
	printf("ret_cust : %d\n", ret2);
	printf("\n");
}

void	test_d_28(void)
{
	int a = -54321;
	int ret1 = 0;
	int ret2 = 0;

	printf("Test_d => 28\n");
	ret1 = printf("orig : %10d\n", a);
	ret2 = ft_printf("cust : %10d\n", a);
	printf("\n");
	printf("ret_orig : %d\n", ret1);
	printf("ret_cust : %d\n", ret2);
	printf("\n");
}

void	test_d_29(void)
{
	int a = -54321;
	int ret1 = 0;
	int ret2 = 0;

	printf("Test_d => 29\n");
	ret1 = printf("orig : %.10d\n", a);
	ret2 = ft_printf("cust : %.10d\n", a);
	printf("\n");
	printf("ret_orig : %d\n", ret1);
	printf("ret_cust : %d\n", ret2);
	printf("\n");
}

void	test_d_30(void)
{
	int a = -54321;
	int ret1 = 0;
	int ret2 = 0;

	printf("Test_d => 30\n");
	ret1 = printf("orig : %010d\n", a);
	ret2 = ft_printf("cust : %010d\n", a);
	printf("\n");
	printf("ret_orig : %d\n", ret1);
	printf("ret_cust : %d\n", ret2);
	printf("\n");
}

void	test_d_31(void)
{
	int a = 54321;
	int ret1 = 0;
	int ret2 = 0;

	printf("Test_d => 31\n");
	ret1 = printf("orig : % 4d\n", a);
	ret2 = ft_printf("cust : % 4d\n", a);
	printf("\n");
	printf("ret_orig : %d\n", ret1);
	printf("ret_cust : %d\n", ret2);
	printf("\n");
}

void	test_d_32(void)
{
	int a = 54321;
	int ret1 = 0;
	int ret2 = 0;

	printf("Test_d => 32\n");
	ret1 = printf("orig : % 8d\n", a);
	ret2 = ft_printf("cust : % 8d\n", a);
	printf("\n");
	printf("ret_orig : %d\n", ret1);
	printf("ret_cust : %d\n", ret2);
	printf("\n");
}

void	test_d_33(void)
{
	int a = 54321;
	int ret1 = 0;
	int ret2 = 0;

	printf("Test_d => 33\n");
	ret1 = printf("orig : % .8d\n", a);
	ret2 = ft_printf("cust : % .8d\n", a);
	printf("\n");
	printf("ret_orig : %d\n", ret1);
	printf("ret_cust : %d\n", ret2);
	printf("\n");
}

void	test_d_34(void)
{
	int a = -54321;
	int ret1 = 0;
	int ret2 = 0;

	printf("Test_d => 34\n");
	ret1 = printf("orig : % .2d\n", a);
	ret2 = ft_printf("cust : % .2d\n", a);
	printf("\n");
	printf("ret_orig : %d\n", ret1);
	printf("ret_cust : %d\n", ret2);
	printf("\n");
}

void	test_d_35(void)
{
	int a = -54321;
	int ret1 = 0;
	int ret2 = 0;

	printf("Test_d => 35\n");
	ret1 = printf("orig : %+.2d\n", a);
	ret2 = ft_printf("cust : %+.2d\n", a);
	printf("\n");
	printf("ret_orig : %d\n", ret1);
	printf("ret_cust : %d\n", ret2);
	printf("\n");
}

void	test_d_36(void)
{
	int a = 321;
	int ret1 = 0;
	int ret2 = 0;

	printf("Test_d => 36\n");
	ret1 = printf("orig : %+d\n", a);
	ret2 = ft_printf("cust : %+d\n", a);
	printf("\n");
	printf("ret_orig : %d\n", ret1);
	printf("ret_cust : %d\n", ret2);
	printf("\n");
}

void	test_d_37(void)
{
	int a = 42;
	int ret1 = 0;
	int ret2 = 0;

	printf("Test_d => 37\n");
	ret1 = printf("orig : % +d\n", a);
	ret2 = ft_printf("cust : % +d\n", a);
	printf("\n");
	printf("ret_orig : %d\n", ret1);
	printf("ret_cust : %d\n", ret2);
	printf("\n");
}
//  ft_printf("%0+5d", 42);
void	test_d_38(void)
{
	int a = 42;
	int ret1 = 0;
	int ret2 = 0;

	printf("Test_d => 38\n");
	ret1 = printf("orig : %0+5d\n", a);
	ret2 = ft_printf("cust : %0+5d\n", a);
	printf("\n");
	printf("ret_orig : %d\n", ret1);
	printf("ret_cust : %d\n", ret2);
	printf("\n");
}

void	test_d_39(void)
{
	long a = LONG_MAX;
	int ret1 = 0;
	int ret2 = 0;

	printf("Test_d => 39\n");
	ret1 = printf("orig : %jd\n", a);
	ret2 = ft_printf("cust : %jd\n", a);
	printf("\n");
	printf("ret_orig : %d\n", ret1);
	printf("ret_cust : %d\n", ret2);
	printf("\n");
}

void	test_d_40(void)
{
	int ret1 = 0;
	int ret2 = 0;

	printf("Test_d => 40\n");
	ret1 = printf("orig : %.d %.0d\n", 0, 0);
	ret2 = ft_printf("cust : %.d %.0d\n", 0, 0);
	printf("\n");
	printf("ret_orig : %d\n", ret1);
	printf("ret_cust : %d\n", ret2);
	printf("\n");
}

void	test_d_41(void)
{
	int ret1 = 0;
	int ret2 = 0;

	printf("Test_d => 41\n");
	ret1 = printf("orig : %zhd\n", 4294967296);
	ret2 = ft_printf("cust : %zhd\n", 4294967296);
	printf("\n");
	printf("ret_orig : %d\n", ret1);
	printf("ret_cust : %d\n", ret2);
	printf("\n");
}

void	test_d_42(void)
{
	int ret1 = 0;
	int ret2 = 0;

	printf("Test_d => 42\n");
	ret1 = printf("orig : % 03d\n", 0);
	ret2 = ft_printf("cust : % 03d\n", 0);
	printf("\n");
	printf("ret_orig : %d\n", ret1);
	printf("ret_cust : %d\n", ret2);
	printf("\n");
}

//======================================================> conv_D

void	test_ld_01(void)
{
	int ret1 = 0;
	int ret2 = 0;

	printf("Test_D => 01\n");
	ret1 = printf("orig : %D\n", 42);
	ret2 = ft_printf("cust : %D\n", 42);
	printf("\n");
	printf("ret_orig : %d\n", ret1);
	printf("ret_cust : %d\n", ret2);
	printf("\n");
}

void	test_ld_02(void)
{
	int ret1 = 0;
	int ret2 = 0;

	printf("Test_D => 02\n");
	ret1 = printf("orig : %D\n", UINT_MAX);
	ret2 = ft_printf("cust : %D\n", UINT_MAX);
	printf("\n");
	printf("ret_orig : %d\n", ret1);
	printf("ret_cust : %d\n", ret2);
	printf("\n");
}

void	test_ld_03(void)
{
	int ret1 = 0;
	int ret2 = 0;

	printf("Test_D => 03\n");
	ret1 = printf("orig : %D\n", INT_MIN);
	ret2 = ft_printf("cust : %D\n", INT_MIN);
	printf("\n");
	printf("ret_orig : %d\n", ret1);
	printf("ret_cust : %d\n", ret2);
	printf("\n");
}

void	test_ld_04(void)
{
	int ret1 = 0;
	int ret2 = 0;

	printf("Test_D => 04\n");
	ret1 = printf("orig : %D\n", INT_MAX);
	ret2 = ft_printf("cust : %D\n",INT_MAX);
	printf("\n");
	printf("ret_orig : %d\n", ret1);
	printf("ret_cust : %d\n", ret2);
	printf("\n");
}

void	test_ld_05(void)
{
	short a = SHRT_MAX;
	int ret1 = 0;
	int ret2 = 0;

	printf("Test_D => 05\n");
	ret1 = printf("orig : %hD\n", a);
	ret2 = ft_printf("cust : %hD\n", a);
	printf("\n");
	printf("ret_orig : %d\n", ret1);
	printf("ret_cust : %d\n", ret2);
	printf("\n");
}

void	test_ld_06(void)
{
	short a = SHRT_MIN;
	int ret1 = 0;
	int ret2 = 0;

	printf("Test_D => 06\n");
	ret1 = printf("orig : %hD\n", a);
	ret2 = ft_printf("cust : %hD\n", a);
	printf("\n");
	printf("ret_orig : %d\n", ret1);
	printf("ret_cust : %d\n", ret2);
	printf("\n");
}

void	test_ld_07(void)
{
	unsigned short a = USHRT_MAX;
	int ret1 = 0;
	int ret2 = 0;

	printf("Test_D => 07\n");
	ret1 = printf("orig : %hD\n", a);
	ret2 = ft_printf("cust : %hD\n", a);
	printf("\n");
	printf("ret_orig : %d\n", ret1);
	printf("ret_cust : %d\n", ret2);
	printf("\n");
}

void	test_ld_08(void)
{
	char a = CHAR_MAX;
	int ret1 = 0;
	int ret2 = 0;

	printf("Test_D => 08\n");
	ret1 = printf("orig : %hhD\n", a);
	ret2 = ft_printf("cust : %hhD\n", a);
	printf("\n");
	printf("ret_orig : %d\n", ret1);
	printf("ret_cust : %d\n", ret2);
	printf("\n");
}

void	test_ld_09(void)
{
	char a = CHAR_MIN;
	int ret1 = 0;
	int ret2 = 0;

	printf("Test_D => 09\n");
	ret1 = printf("orig : %hhD\n", a);
	ret2 = ft_printf("cust : %hhD\n", a);
	printf("\n");
	printf("ret_orig : %d\n", ret1);
	printf("ret_cust : %d\n", ret2);
	printf("\n");
}

void	test_ld_10(void)
{
	unsigned char a = UCHAR_MAX;
	int ret1 = 0;
	int ret2 = 0;

	printf("Test_D => 10\n");
	ret1 = printf("orig : %hhD\n", a);
	ret2 = ft_printf("cust : %hhD\n", a);
	printf("\n");
	printf("ret_orig : %d\n", ret1);
	printf("ret_cust : %d\n", ret2);
	printf("\n");
}

void	test_ld_11(void)
{
	long long a = LONG_MAX;
	int ret1 = 0;
	int ret2 = 0;

	printf("Test_D => 11\n");
	ret1 = printf("orig : %llD\n", a);
	ret2 = ft_printf("cust : %llD\n", a);
	printf("\n");
	printf("ret_orig : %d\n", ret1);
	printf("ret_cust : %d\n", ret2);
	printf("\n");
}

void	test_ld_12(void)
{
	long a = LONG_MAX;
	int ret1 = 0;
	int ret2 = 0;

	printf("Test_D => 12\n");
	ret1 = printf("orig : %lD\n", a);
	ret2 = ft_printf("cust : %lD\n", a);
	printf("\n");
	printf("ret_orig : %d\n", ret1);
	printf("ret_cust : %d\n", ret2);
	printf("\n");
}

void	test_ld_13(void)
{
	intmax_t a = ULONG_MAX;
	int ret1 = 0;
	int ret2 = 0;

	printf("Test_D => 13\n");
	ret1 = printf("orig : %jD\n", a);
	ret2 = ft_printf("cust : %jD\n", a);
	printf("\n");
	printf("ret_orig : %d\n", ret1);
	printf("ret_cust : %d\n", ret2);
	printf("\n");
}

void	test_ld_14(void)
{
	uintmax_t a = ULONG_MAX;
	int ret1 = 0;
	int ret2 = 0;

	printf("Test_D => 14\n");
	ret1 = printf("orig : %jD\n", a);
	ret2 = ft_printf("cust : %jD\n", a);
	printf("\n");
	printf("ret_orig : %d\n", ret1);
	printf("ret_cust : %d\n", ret2);
	printf("\n");
}

void	test_ld_15(void)
{
	uintmax_t a = ULONG_MAX;
	int ret1 = 0;
	int ret2 = 0;

	printf("Test_D => 15\n");
	ret1 = printf("orig : %.*jD\n", 5, a);
	ret2 = ft_printf("cust : %.*jD\n", 5, a);
	printf("\n");
	printf("ret_orig : %d\n", ret1);
	printf("ret_cust : %d\n", ret2);
	printf("\n");
}

void	test_ld_16(void)
{
	uintmax_t a = ULONG_MAX;
	int ret1 = 0;
	int ret2 = 0;

	printf("Test_D => 16\n");
	ret1 = printf("orig : %D\n", -1L);
	ret2 = ft_printf("cust : %D\n", -1L);
	printf("\n");
	printf("ret_orig : %d\n", ret1);
	printf("ret_cust : %d\n", ret2);
	printf("\n");
}

//======================================================> conv_i

void 	test_i_01(void)
{
	int ret1 = 0;
	int ret2 = 0;
	int a = INT_MAX;

	printf("Test_i => 01\n");
	ret1 = printf("orig : %i\n", a);
	ret2 = ft_printf("cust : %i\n", a);
	printf("\n");
	printf("ret_orig : %d\n", ret1);
	printf("ret_cust : %d\n", ret2);
	printf("\n");
}

void 	test_i_02(void)
{
	int ret1 = 0;
	int ret2 = 0;
	int a = INT_MIN;

	printf("Test_i => 02\n");
	ret1 = printf("orig : %i\n", a);
	ret2 = ft_printf("cust : %i\n", a);
	printf("\n");
	printf("ret_orig : %d\n", ret1);
	printf("ret_cust : %d\n", ret2);
	printf("\n");
}

void 	test_i_03(void)
{
	int ret1 = 0;
	int ret2 = 0;
	short a = SHRT_MAX;

	printf("Test_i => 03\n");
	ret1 = printf("orig : %hi\n", a);
	ret2 = ft_printf("cust : %hi\n", a);
	printf("\n");
	printf("ret_orig : %d\n", ret1);
	printf("ret_cust : %d\n", ret2);
	printf("\n");
}

void 	test_i_04(void)
{
	int ret1 = 0;
	int ret2 = 0;
	short a = SHRT_MIN;

	printf("Test_i => 04\n");
	ret1 = printf("orig : %hi\n", a);
	ret2 = ft_printf("cust : %hi\n", a);
	printf("\n");
	printf("ret_orig : %d\n", ret1);
	printf("ret_cust : %d\n", ret2);
	printf("\n");
}

void 	test_i_05(void)
{
	int ret1 = 0;
	int ret2 = 0;
	char a = CHAR_MAX;

	printf("Test_i => 05\n");
	ret1 = printf("orig : %hhi\n", a);
	ret2 = ft_printf("cust : %hhi\n", a);
	printf("\n");
	printf("ret_orig : %d\n", ret1);
	printf("ret_cust : %d\n", ret2);
	printf("\n");
}

void 	test_i_06(void)
{
	int ret1 = 0;
	int ret2 = 0;
	long a = INT_MAX;


	printf("Test_i => 06\n");
	ret1 = printf("orig : %li\n", a);
	ret2 = ft_printf("cust : %li\n", a);
	printf("\n");
	printf("ret_orig : %d\n", ret1);
	printf("ret_cust : %d\n", ret2);
	printf("\n");
}

void 	test_i_07(void)
{
	int ret1 = 0;
	int ret2 = 0;
	unsigned long a = UINT_MAX;


	printf("Test_i => 07\n");
	ret1 = printf("orig : %li\n", a);
	ret2 = ft_printf("cust : %li\n", a);
	printf("\n");
	printf("ret_orig : %d\n", ret1);
	printf("ret_cust : %d\n", ret2);
	printf("\n");
}

void 	test_i_08(void)
{
	int ret1 = 0;
	int ret2 = 0;
	long long a = LONG_MAX;

	printf("Test_i => 08\n");
	ret1 = printf("orig : %lli\n", a);
	ret2 = ft_printf("cust : %lli\n", a);
	printf("\n");
	printf("ret_orig : %d\n", ret1);
	printf("ret_cust : %d\n", ret2);
	printf("\n");
}

void 	test_i_09(void)
{
	int ret1 = 0;
	int ret2 = 0;
	long long a = LONG_MAX;

	printf("Test_i => 09\n");
	ret1 = printf("orig : %25.20lli\n", a);
	ret2 = ft_printf("cust : %25.20lli\n", a);
	printf("\n");
	printf("ret_orig : %d\n", ret1);
	printf("ret_cust : %d\n", ret2);
	printf("\n");
}


/*
void	test_ld_08(void)
{
	char a = MAX;

	printf("Test_D => 07\n");
	printf("orig : %hhD\n", a);
	ft_printf("cust : %hD\n", a);
	printf("\n");
}

void	test_ld_06(void)
{
	short a = SHRT_MIN;
	printf("Test_D => 06\n");
	printf("orig : %hD\n", a);
	ft_printf("cust : %hD\n", a);
	printf("\n");
}
*/

//======================================================> conv_o

void 	test_o_01(void)
{
	int ret1 = 0;
	int ret2 = 0;
	int a = INT_MAX;

	printf("Test_o => 01\n");
	ret1 = printf("orig : %o\n", a);
	ret2 = ft_printf("cust : %o\n", a);
	printf("\n");
	printf("ret_orig : %d\n", ret1);
	printf("ret_cust : %d\n", ret2);
	printf("\n");
}

void 	test_o_02(void)
{
	int ret1 = 0;
	int ret2 = 0;
	int a = INT_MIN;

	printf("Test_o => 02\n");
	ret1 = printf("orig : %o\n", a);
	ret2 = ft_printf("cust : %o\n", a);
	printf("\n");
	printf("ret_orig : %d\n", ret1);
	printf("ret_cust : %d\n", ret2);
	printf("\n");
}

void 	test_o_03(void)
{
	int ret1 = 0;
	int ret2 = 0;
	short a = SHRT_MAX;

	printf("Test_o => 03\n");
	ret1 = printf("orig : %ho\n", a);
	ret2 = ft_printf("cust : %ho\n", a);
	printf("\n");
	printf("ret_orig : %d\n", ret1);
	printf("ret_cust : %d\n", ret2);
	printf("\n");
}

void 	test_o_04(void)
{
	int ret1 = 0;
	int ret2 = 0;
	char a = CHAR_MAX;

	printf("Test_o => 04\n");
	ret1 = printf("orig : %10hho\n", a);
	ret2 = ft_printf("cust : %10hho\n", a);
	printf("\n");
	printf("ret_orig : %d\n", ret1);
	printf("ret_cust : %d\n", ret2);
	printf("\n");
}

void 	test_o_05(void)
{
	int ret1 = 0;
	int ret2 = 0;
	int a = INT_MAX;

	printf("Test_o => 05\n");
	ret1 = printf("orig : %.4o\n", a);
	ret2 = ft_printf("cust : %.4o\n", a);
	printf("\n");
	printf("ret_orig : %d\n", ret1);
	printf("ret_cust : %d\n", ret2);
	printf("\n");
}

void 	test_o_06(void)
{
	int ret1 = 0;
	int ret2 = 0;
	int a = 42;

	printf("Test_o => 06\n");
	ret1 = printf("orig : %.12o\n", a);
	ret2 = ft_printf("cust : %.12o\n", a);
	printf("\n");
	printf("ret_orig : %d\n", ret1);
	printf("ret_cust : %d\n", ret2);
	printf("\n");
}

void 	test_o_07(void)
{
	int ret1 = 0;
	int ret2 = 0;
	long long a = LONG_MAX;

	printf("Test_o => 07\n");
	ret1 = printf("orig : %.12llo\n", a);
	ret2 = ft_printf("cust : %.12llo\n", a);
	printf("\n");
	printf("ret_orig : %d\n", ret1);
	printf("ret_cust : %d\n", ret2);
	printf("\n");
}

void 	test_o_08(void)
{
	int ret1 = 0;
	int ret2 = 0;
	long long a = LONG_MIN;

	printf("Test_o => 08\n");
	ret1 = printf("orig : %llo\n", a);
	ret2 = ft_printf("cust : %llo\n", a);
	printf("\n");
	printf("ret_orig : %d\n", ret1);
	printf("ret_cust : %d\n", ret2);
	printf("\n");
}

void 	test_o_09(void)
{
	int ret1 = 0;
	int ret2 = 0;
	intmax_t a = ULONG_MAX;

	printf("Test_o => 09\n");
	ret1 = printf("orig : %.30jo\n", a);
	ret2 = ft_printf("cust : %.30jo\n", a);
	printf("\n");
	printf("ret_orig : %d\n", ret1);
	printf("ret_cust : %d\n", ret2);
	printf("\n");
}

void 	test_o_10(void)
{
	int ret1 = 0;
	int ret2 = 0;
	int a = 42;

	printf("Test_o => 10\n");
	ret1 = printf("orig : %#16.3o\n", a);
	ret2 = ft_printf("cust : %#16.3o\n", a);
	printf("\n");
	printf("ret_orig : %d\n", ret1);
	printf("ret_cust : %d\n", ret2);
	printf("\n");
}

void 	test_o_11(void)
{
	int ret1 = 0;
	int ret2 = 0;
	int a = 42;

	printf("Test_o => 11\n");
	ret1 = printf("orig : %#o\n", a);
	ret2 = ft_printf("cust : %#o\n", a);
	printf("\n");
	printf("ret_orig : %d\n", ret1);
	printf("ret_cust : %d\n", ret2);
	printf("\n");
}

void 	test_o_12(void)
{
	int a = 0;
	int ret1 = 0;
	int ret2 = 0;

	printf("Test_o => 12\n");
	ret1 = printf("orig : %#o\n", a);
	ret2 = ft_printf("cust : %#o\n", a);
	printf("\n");
	printf("ret_orig : %d\n", ret1);
	printf("ret_cust : %d\n", ret2);
	printf("\n");
}

void 	test_o_13(void)
{
	int ret1 = 0;
	int ret2 = 0;

	printf("Test_o => 13\n");
	ret1 = printf("orig : %.0o %.o\n", 0, 0);
	ret2 = ft_printf("cust : %.0o %.o\n", 0, 0);
	printf("\n");
	printf("ret_orig : %d\n", ret1);
	printf("ret_cust : %d\n", ret2);
	printf("\n");
}

void 	test_o_14(void)
{
	int ret1 = 0;
	int ret2 = 0;

	printf("Test_o => 14\n");
	ret1 = printf("orig : %#.0o %#.0o\n", 0, 0);
	ret2 = ft_printf("cust : %#.0o %#.0o\n", 0, 0);
	printf("\n");
	printf("ret_orig : %d\n", ret1);
	printf("ret_cust : %d\n", ret2);
	printf("\n");
}

void 	test_o_15(void)
{
	int ret1 = 0;
	int ret2 = 0;

	printf("Test_o => 15\n");
	ret1 = printf("orig : %o\n", 0);
	ret2 = ft_printf("cust : %o\n", 0);
	printf("\n");
	printf("ret_orig : %d\n", ret1);
	printf("ret_cust : %d\n", ret2);
	printf("\n");
}

void 	test_o_16(void)
{
	int ret1 = 0;
	int ret2 = 0;

	printf("Test_o => 16\n");
	ret1 = printf("orig : %hho, %hho\n", 0, UCHAR_MAX + 42);
	ret2 = ft_printf("cust : %hho, %hho\n", 0, UCHAR_MAX + 42);
	printf("\n");
	printf("ret_orig : %d\n", ret1);
	printf("ret_cust : %d\n", ret2);
	printf("\n");
}

void 	test_o_17(void)
{
	int ret1 = 0;
	int ret2 = 0;

	printf("Test_o => 17\n");
	ret1 = printf("orig : %+o\n", 0);
	ret2 = ft_printf("cust : %+o\n", 0);
	printf("\n");
	printf("ret_orig : %d\n", ret1);
	printf("ret_cust : %d\n", ret2);
	printf("\n");
}

void 	test_o_18(void)
{
	int ret1 = 0;
	int ret2 = 0;

	printf("Test_o => 18\n");
	ret1 = printf("orig : %o, %ho, %hho\n", -42, -42, -42);
	ret2 = ft_printf("cust : %o, %ho, %hho\n", -42, -42, -42);
	printf("\n");
	printf("ret_orig : %d\n", ret1);
	printf("ret_cust : %d\n", ret2);
	printf("\n");
}

void 	test_o_19(void)
{
	int ret1 = 0;
	int ret2 = 0;

	printf("Test_o => 19\n");
	ret1 = printf("orig : %o\n", -1);
	ret2 = ft_printf("cust : %o\n", -1);
	printf("\n");
	printf("ret_orig : %d\n", ret1);
	printf("ret_cust : %d\n", ret2);
	printf("\n");
}

void 	test_o_20(void)
{
	int ret1 = 0;
	int ret2 = 0;

	printf("Test_o => 20\n");
	ret1 = printf("orig : %lo, %lo\n", 0, ULONG_MAX);
	ret2 = ft_printf("cust : %lo, %lo\n", 0, ULONG_MAX);
	printf("\n");
	printf("ret_orig : %d\n", ret1);
	printf("ret_cust : %d\n", ret2);
	printf("\n");
}

void 	test_o_21(void)
{
	int ret1 = 0;
	int ret2 = 0;

	printf("Test_o => 21\n");
	ret1 = printf("orig : %lo, %lo\n", 0, LONG_MAX);
	ret2 = ft_printf("cust : %lo, %lo\n", 0, LONG_MAX);
	printf("\n");
	printf("ret_orig : %d\n", ret1);
	printf("ret_cust : %d\n", ret2);
	printf("\n");
}

//======================================================> conv_O
void 	test_lo_01(void)
{
	int ret1 = 0;
	int ret2 = 0;
	int a = 42;

	printf("Test_O => 01\n");
	ret1 = printf("orig : %O\n", a);
	ret2 = ft_printf("cust : %O\n", a);
	printf("\n");
	printf("ret_orig : %d\n", ret1);
	printf("ret_cust : %d\n", ret2);
	printf("\n");
}

void 	test_lo_02(void)
{
	int ret1 = 0;
	int ret2 = 0;
	int a = INT_MAX;

	printf("Test_O => 02\n");
	ret1 = printf("orig : %O\n", a);
	ret2 = ft_printf("cust : %O\n", a);
	printf("\n");
	printf("ret_orig : %d\n", ret1);
	printf("ret_cust : %d\n", ret2);
	printf("\n");
}

void 	test_lo_03(void)
{
	int ret1 = 0;
	int ret2 = 0;
	int a = INT_MIN;

	printf("Test_O => 03\n");
	ret1 = printf("orig : %O\n", a);
	ret2 = ft_printf("cust : %O\n", a);
	printf("\n");
	printf("ret_orig : %d\n", ret1);
	printf("ret_cust : %d\n", ret2);
	printf("\n");
}

void 	test_lo_04(void)
{
	int ret1 = 0;
	int ret2 = 0;
	unsigned int a = UINT_MAX;

	printf("Test_O => 04\n");
	ret1 = printf("orig : %O\n", a);
	ret2 = ft_printf("cust : %O\n", a);
	printf("\n");
	printf("ret_orig : %d\n", ret1);
	printf("ret_cust : %d\n", ret2);
	printf("\n");
}

void 	test_lo_05(void)
{
	int ret1 = 0;
	int ret2 = 0;
	unsigned int a = 0;

	printf("Test_O => 05\n");
	ret1 = printf("orig : %10.0O*\n", a);
	ret2 = ft_printf("cust : %10.0O*\n", a);
	printf("\n");
	printf("ret_orig : %d\n", ret1);
	printf("ret_cust : %d\n", ret2);
	printf("\n");
}

void 	test_lo_06(void)
{
	int ret1 = 0;
	int ret2 = 0;
	unsigned int a = 0;

	printf("Test_O => 06\n");
	ret1 = printf("orig : %0O*\n", a);
	ret2 = ft_printf("cust : %0O*\n", a);
	printf("\n");
	printf("ret_orig : %d\n", ret1);
	printf("ret_cust : %d\n", ret2);
	printf("\n");
}

void 	test_lo_07(void)
{
	int ret1 = 0;
	int ret2 = 0;

	printf("Test_O => 07\n");
	ret1 = printf("orig : %O*\n", LONG_MAX);
	ret2 = ft_printf("cust : %O*\n", LONG_MAX);
	printf("\n");
	printf("ret_orig : %d\n", ret1);
	printf("ret_cust : %d\n", ret2);
	printf("\n");
}

void 	test_lo_08(void)
{
	int ret1 = 0;
	int ret2 = 0;

	printf("Test_O => 08\n");
	ret1 = printf("orig : %O*\n", LONG_MIN);
	ret2 = ft_printf("cust : %O*\n", LONG_MIN);
	printf("\n");
	printf("ret_orig : %d\n", ret1);
	printf("ret_cust : %d\n", ret2);
	printf("\n");
}

void 	test_lo_09(void)
{
	int ret1 = 0;
	int ret2 = 0;

	printf("Test_O => 09\n");
	ret1 = printf("orig : %#O\n", LONG_MIN);
	ret2 = ft_printf("cust : %#O\n", LONG_MIN);
	printf("\n");
	printf("ret_orig : %d\n", ret1);
	printf("ret_cust : %d\n", ret2);
	printf("\n");
}

void 	test_lo_10(void)
{
	int ret1 = 0;
	int ret2 = 0;

	printf("Test_O => 10\n");
	ret1 = printf("orig : %#30O\n", 1);
	ret2 = ft_printf("cust : %#30O\n", 1);
	printf("\n");
	printf("ret_orig : %d\n", ret1);
	printf("ret_cust : %d\n", ret2);
	printf("\n");
}

void 	test_lo_11(void)
{
	int ret1 = 0;
	int ret2 = 0;

	printf("Test_O => 11\n");
	ret1 = printf("orig : %O, %O\n", 0, LONG_MAX);
	ret2 = ft_printf("cust : %O, %O\n", 0, LONG_MAX);
	printf("\n");
	printf("ret_orig : %d\n", ret1);
	printf("ret_cust : %d\n", ret2);
	printf("\n");
}

void 	test_lo_12(void)
{
	int ret1 = 0;
	int ret2 = 0;

	printf("Test_O => 12\n");

	ret1 = printf("orig : %hO, %hO\n", 0, USHRT_MAX);
	ret2 = ft_printf("cust : %hO, %hO\n", 0, USHRT_MAX);
	printf("\n");
	printf("ret_orig : %d\n", ret1);
	printf("ret_cust : %d\n", ret2);
	printf("\n");
}

void 	test_lo_13(void)
{
	unsigned short foo = USHRT_MAX;
	int ret1 = 0;
	int ret2 = 0;

	printf("Test_O => 13\n");

	ret1 = printf("orig : %hhO, %hhO\n", 0, foo);
	ret2 = ft_printf("cust : %hhO, %hhO\n", 0, foo);
	printf("\n");
	printf("ret_orig : %d\n", ret1);
	printf("ret_cust : %d\n", ret2);
	printf("\n");
}


//======================================================> conv_x

void	test_u_01(void)
{
	unsigned int a = UINT_MAX;
	int ret1 = 0;
	int ret2 = 0;

	printf("Test_u => 01\n");
	ret1 = printf("orig : %u\n", a);
	ret2 = ft_printf("cust : %u\n", a);
	printf("\n");
	printf("ret_orig : %d\n", ret1);
	printf("ret_cust : %d\n", ret2);
	printf("\n");


}

void	test_u_02(void)
{
	unsigned long a = LONG_MAX;
	int ret1 = 0;
	int ret2 = 0;

	printf("Test_u => 02\n");
	ret1 = printf("orig : %lu\n", a);
	ret2 = ft_printf("cust : %lu\n", a);
	printf("\n");
	printf("ret_orig : %d\n", ret1);
	printf("ret_cust : %d\n", ret2);
	printf("\n");


}

void	test_u_03(void)
{
	unsigned char a = UCHAR_MAX;
	int ret1 = 0;
	int ret2 = 0;

	printf("Test_u => 03\n");
	ret1 = printf("orig : %hhu\n", a);
	ret2 = ft_printf("cust : %hhu\n", a);
	printf("\n");
	printf("ret_orig : %d\n", ret1);
	printf("ret_cust : %d\n", ret2);
	printf("\n");


}

void	test_u_04(void)
{
	size_t a = UINT_MAX;
	int ret1 = 0;
	int ret2 = 0;

	printf("Test_u => 04\n");
	ret1 = printf("orig : %zu\n", a);
	ret2 = ft_printf("cust : %zu\n", a);
	printf("\n");
	printf("ret_orig : %d\n", ret1);
	printf("ret_cust : %d\n", ret2);
	printf("\n");


}

void	test_u_05(void)
{
	unsigned int a = UINT_MAX;
	int ret1 = 0;
	int ret2 = 0;

	printf("Test_u => 05\n");
	ret1 = printf("orig : %#u\n", a);
	ret2 = ft_printf("cust : %#u\n", a);
	printf("\n");
	printf("ret_orig : %d\n", ret1);
	printf("ret_cust : %d\n", ret2);
	printf("\n");
}

void	test_u_06(void)
{
	unsigned int a = UINT_MAX;
	int ret1 = 0;
	int ret2 = 0;

	printf("Test_u => 06\n");
	ret1 = printf("orig : % u\n", a);
	ret2 = ft_printf("cust : % u\n", a);
	printf("\n");
	printf("ret_orig : %d\n", ret1);
	printf("ret_cust : %d\n", ret2);
	printf("\n");
}

void	test_u_07(void)
{
	unsigned int a = UINT_MAX;
	int ret1 = 0;
	int ret2 = 0;

	printf("Test_u => 07\n");
	ret1 = printf("orig : %016u\n", a);
	ret2 = ft_printf("cust : %016u\n", a);
	printf("\n");
	printf("ret_orig : %d\n", ret1);
	printf("ret_cust : %d\n", ret2);
	printf("\n");
}

void	test_u_08(void)
{
	unsigned int a = UINT_MAX;
	int ret1 = 0;
	int ret2 = 0;

	printf("Test_u => 08\n");
	ret1 = printf("orig : %+u\n", a);
	ret2 = ft_printf("cust : %+u\n", a);
	printf("\n");
	printf("ret_orig : %d\n", ret1);
	printf("ret_cust : %d\n", ret2);
	printf("\n");
}

void	test_u_09(void)
{
	unsigned int a = UINT_MAX;
	int ret1 = 0;
	int ret2 = 0;

	printf("Test_u => 09\n");
	ret1 = printf("orig : %.5u\n", a);
	ret2 = ft_printf("cust : %.5u\n", a);
	printf("\n");
	printf("ret_orig : %d\n", ret1);
	printf("ret_cust : %d\n", ret2);
	printf("\n");
}

void	test_u_10(void)
{
	unsigned int a = UINT_MAX;
	int ret1 = 0;
	int ret2 = 0;

	printf("Test_u => 10\n");
	ret1 = printf("orig : %.12u\n", a);
	ret2 = ft_printf("cust : %.12u\n", a);
	printf("\n");
	printf("ret_orig : %d\n", ret1);
	printf("ret_cust : %d\n", ret2);
	printf("\n");
}

void	test_u_11(void)
{
	unsigned int a = UINT_MAX;
	int ret1 = 0;
	int ret2 = 0;

	printf("Test_u => 11\n");
	ret1 = printf("orig : %16.12u\n", a);
	ret2 = ft_printf("cust : %16.12u\n", a);
	printf("\n");
	printf("ret_orig : %d\n", ret1);
	printf("ret_cust : %d\n", ret2);
	printf("\n");
}

void	test_u_12(void)
{
	unsigned int a = 0;
	int ret1 = 0;
	int ret2 = 0;

	printf("Test_u => 12\n");
	ret1 = printf("orig : %0.12u\n", a);
	ret2 = ft_printf("cust : %0.12u\n", a);
	printf("\n");
	printf("ret_orig : %d\n", ret1);
	printf("ret_cust : %d\n", ret2);
	printf("\n");
}

void	test_u_13(void)
{
	unsigned int a = 0;
	int ret1 = 0;
	int ret2 = 0;

	printf("Test_u => 13\n");
	ret1 = printf("orig : %.0u\n", a);
	ret2 = ft_printf("cust : %.0u\n", a);
	printf("\n");
	printf("ret_orig : %d\n", ret1);
	printf("ret_cust : %d\n", ret2);
	printf("\n");
}

void	test_u_14(void)
{
	unsigned int a = 0;
	int ret1 = 0;
	int ret2 = 0;

	printf("Test_u => 14\n");
	ret1 = printf("orig : %0u\n", a);
	ret2 = ft_printf("cust : %0u\n", a);
	printf("\n");
	printf("ret_orig : %d\n", ret1);
	printf("ret_cust : %d\n", ret2);
	printf("\n");
}

void	test_u_15(void)
{
	unsigned int a = 0;
	int ret1 = 0;
	int ret2 = 0;

	printf("Test_u => 15\n");
	ret1 = printf("orig : %0.0u\n", a);
	ret2 = ft_printf("cust : %0.0u\n", a);
	printf("\n");
	printf("ret_orig : %d\n", ret1);
	printf("ret_cust : %d\n", ret2);
	printf("\n");
}

void	test_u_16(void)
{
	unsigned int a = 0;
	int ret1 = 0;
	int ret2 = 0;

	printf("Test_u => 16\n");
	ret1 = printf("orig : *%010.0u*\n", a);
	ret2 = ft_printf("cust : *%010.0u*\n", a);
	printf("\n");
	printf("ret_orig : %d\n", ret1);
	printf("ret_cust : %d\n", ret2);
	printf("\n");
}

void	test_u_17(void)
{
	unsigned int a = 0;
	int ret1 = 0;
	int ret2 = 0;

	printf("Test_u => 17\n");
	ret1 = printf("orig : *%#.0u*\n", a);
	ret2 = ft_printf("cust : *%#.0u*\n", a);
	printf("\n");
	printf("ret_orig : %d\n", ret1);
	printf("ret_cust : %d\n", ret2);
	printf("\n");
}



//======================================================> conv_lu

void	test_lu_01(void)
{
	int ret1 = 0;
	int ret2 = 0;

	printf("Test_U => 01\n");
	ret1 = printf("orig : %U\n", 42);
	ret2 = ft_printf("cust : %U\n", 42);
	printf("\n");
	printf("ret_orig : %d\n", ret1);
	printf("ret_cust : %d\n", ret2);
	printf("\n");
}

void	test_lu_02(void)
{
	unsigned short a = USHRT_MAX;
	int ret1 = 0;
	int ret2 = 0;

	printf("Test_U => 02\n");
	ret1 = printf("orig : %hU\n", a);
	ret2 = ft_printf("cust : %hU\n", a);
	printf("\n");
	printf("ret_orig : %d\n", ret1);
	printf("ret_cust : %d\n", ret2);
	printf("\n");
}

void	test_lu_03(void)
{
	int ret1 = 0;
	int ret2 = 0;

	printf("Test_U => 03\n");
	ret1 = printf("orig : %U\n", 4294967295);
	ret2 = ft_printf("cust : %U\n", 4294967295);
	printf("\n");
	printf("ret_orig : %d\n", ret1);
	printf("ret_cust : %d\n", ret2);
	printf("\n");
}

void	test_lu_04(void)
{
	int ret1 = 0;
	int ret2 = 0;

	printf("Test_U => 04\n");
	ret1 = printf("orig : %hhU\n", ULONG_MAX);
	ret2 = ft_printf("cust : %hU\n", ULONG_MAX);
	printf("\n");
	printf("ret_orig : %d\n", ret1);
	printf("ret_cust : %d\n", ret2);
	printf("\n");
}

void	test_lu_05(void)
{
	int ret1 = 0;
	int ret2 = 0;

	printf("Test_U => 05\n");
	ret1 = printf("orig : %U\n", 4294967296);
	ret2 = ft_printf("cust : %U\n", 4294967296);
	printf("\n");
	printf("ret_orig : %d\n", ret1);
	printf("ret_cust : %d\n", ret2);
	printf("\n");
}

void	test_lu_06(void)
{
	int ret1 = 0;
	int ret2 = 0;

	printf("Test_U => 06\n");
	ret1 = printf("orig : %zU\n", 4294967296);
	ret2 = ft_printf("cust : %zU\n", 4294967296);
	printf("\n");
	printf("ret_orig : %d\n", ret1);
	printf("ret_cust : %d\n", ret2);
	printf("\n");
}

void	test_lu_07(void)
{
	int ret1 = 0;
	int ret2 = 0;

	printf("Test_U => 07\n");
	ret1 = printf("orig : %.2zU\n", 4294967296);
	ret2 = ft_printf("cust : %.2zU\n", 4294967296);
	printf("\n");
	printf("ret_orig : %d\n", ret1);
	printf("ret_cust : %d\n", ret2);
	printf("\n");
}

void	test_lu_08(void)
{
	int ret1 = 0;
	int ret2 = 0;

	printf("Test_U => 08\n");
	ret1 = printf("orig : %.0U*\n", 0);
	ret2 = ft_printf("cust : %.0U*\n", 0);
	printf("\n");
	printf("ret_orig : %d\n", ret1);
	printf("ret_cust : %d\n", ret2);
	printf("\n");
}

void	test_lu_09(void)
{
	int ret1 = 0;
	int ret2 = 0;

	printf("Test_U => 09\n");
	ret1 = printf("orig : %0U*\n", 0);
	ret2 = ft_printf("cust : %0U*\n", 0);
	printf("\n");
	printf("ret_orig : %d\n", ret1);
	printf("ret_cust : %d\n", ret2);
	printf("\n");
}



//======================================================> conv_x

void	test_x_01(void)
{
	int ret1 = 0;
	int ret2 = 0;

	printf("Test_x => 01\n");
	ret1 = printf("orig : %x\n", 42);
	ret2 = ft_printf("cust : %x\n", 42);
	printf("\n");
	printf("ret_orig : %d\n", ret1);
	printf("ret_cust : %d\n", ret2);
	printf("\n");
}

void	test_x_02(void)
{
	int ret1 = 0;
	int ret2 = 0;

	printf("Test_x => 02\n");
	ret1 =printf("orig : %x\n", 6889);
	ret2 = ft_printf("cust : %x\n", 6889);
	printf("\n");
	printf("ret_orig : %d\n", ret1);
	printf("ret_cust : %d\n", ret2);
	printf("\n");
}

void	test_x_03(void)
{
	int a = INT_MAX;
	int ret1 = 0;
	int ret2 = 0;

	printf("Test_x => 03\n");
	ret1 = printf("orig : %x\n", a);
	ret2 = ft_printf("cust : %x\n", a);
	printf("\n");
	printf("ret_orig : %d\n", ret1);
	printf("ret_cust : %d\n", ret2);
	printf("\n");
}

void	test_x_04(void)
{
	int a = INT_MIN;
	int ret1 = 0;
	int ret2 = 0;

	printf("Test_x => 04\n");
	ret1 = printf("orig : %x\n",	a);
	ret2 = ft_printf("cust : %x\n",	a);
	printf("\n");
	printf("ret_orig : %d\n", ret1);
	printf("ret_cust : %d\n", ret2);
	printf("\n");
}

void	test_x_05(void)
{
	int a = INT_MIN;
	int ret1 = 0;
	int ret2 = 0;

	printf("Test_x => 05\n");
	ret1 = printf("orig : %3x\n", a);
	ret2 = ft_printf("cust : %3x\n",	a);
	printf("\n");
	printf("ret_orig : %d\n", ret1);
	printf("ret_cust : %d\n", ret2);
	printf("\n");
}

void	test_x_06(void)
{
	int ret1 = 0;
	int ret2 = 0;

	printf("Test_x => 06\n");
	ret1 = printf("orig : %#x\n", 2147);
	ret2 = ft_printf("cust : %#x\n", 2147);
	printf("\n");
	printf("ret_orig : %d\n", ret1);
	printf("ret_cust : %d\n", ret2);
	printf("\n");
}

void	test_x_07(void)
{
	int ret1 = 0;
	int ret2 = 0;

	printf("Test_x => 07\n");
	ret1 = printf("orig : %x\n", -42);
	ret2 = ft_printf("cust : %x\n", -42);
	printf("\n");
	printf("ret_orig : %d\n", ret1);
	printf("ret_cust : %d\n", ret2);
	printf("\n");
}

void	test_x_08(void)
{
	int ret1 = 0;
	int ret2 = 0;

	printf("Test_x => 08\n");
	ret1 = printf("orig : %-15x*\n", 542);
	ret2 = ft_printf("cust : %-15x*\n", 542);
	printf("\n");
	printf("ret_orig : %d\n", ret1);
	printf("ret_cust : %d\n", ret2);
	printf("\n");
}

void	test_x_09(void)
{
	char a = 127;
	int ret1 = 0;
	int ret2 = 0;

	printf("Test_x => 09\n");
	ret1 = printf("orig : %hhx\n", a);
	ret2 = ft_printf("cust : %hhx\n", a);
	printf("\n");
	printf("ret_orig : %d\n", ret1);
	printf("ret_cust : %d\n", ret2);
	printf("\n");
}

void	test_x_10(void)
{
	char a = 128;
	int ret1 = 0;
	int ret2 = 0;

	printf("Test_x => 10\n");
	ret1 = printf("orig : %hhx\n", a);
	ret2 = ft_printf("cust : %hhx\n", a);
	printf("\n");
	printf("ret_orig : %d\n", ret1);
	printf("ret_cust : %d\n", ret2);
	printf("\n");
}

void	test_x_11(void)
{
	short a = SHRT_MAX;
	int ret1 = 0;
	int ret2 = 0;

	printf("Test_x => 11\n");
	ret1 = printf("orig : %hx\n", a);
	ret2 = ft_printf("cust : %hx\n", a);
	printf("\n");
	printf("ret_orig : %d\n", ret1);
	printf("ret_cust : %d\n", ret2);
	printf("\n");
}

void	test_x_12(void)
{
	short a = SHRT_MIN;
	int ret1 = 0;
	int ret2 = 0;

	printf("Test_x => 12\n");
	ret1 = printf("orig : %hx\n", a);
	ret2 = ft_printf("cust : %hx\n", a);
	printf("\n");
	printf("ret_orig : %d\n", ret1);
	printf("ret_cust : %d\n", ret2);
	printf("\n");
}

void	test_x_13(void)
{
	int a = 12345;
	int ret1 = 0;
	int ret2 = 0;

	printf("Test_x => 13\n");
	ret1 = printf("orig : %.10x\n", a);
	ret2 = ft_printf("cust : %.10x\n", a);
	printf("\n");
	printf("ret_orig : %d\n", ret1);
	printf("ret_cust : %d\n", ret2);
	printf("\n");
}

void	test_x_14(void)
{
	int a = 12345;
	int ret1 = 0;
	int ret2 = 0;

	printf("Test_x => 14\n");
	ret1 = printf("orig : %18.10x\n", a);
	ret2 = ft_printf("cust : %18.10x\n", a);
	printf("\n");
	printf("ret_orig : %d\n", ret1);
	printf("ret_cust : %d\n", ret2);
	printf("\n");
}

void	test_x_15(void)
{
	int a = 12345;
	int ret1 = 0;
	int ret2 = 0;

	printf("Test_x => 15\n");
	ret1 = printf("orig : %-20.10x|\n", a);
	ret2 = ft_printf("cust : %-20.10x|\n", a);
	printf("\n");
	printf("ret_orig : %d\n", ret1);
	printf("ret_cust : %d\n", ret2);
	printf("\n");
}

void	test_x_16(void)
{
	int a = 12345;
	int ret1 = 0;
	int ret2 = 0;

	printf("Test_x => 16\n");
	ret1 = printf("orig : %#20.10x|\n", a);
	ret2 = ft_printf("cust : %#20.10x|\n", a);
	printf("\n");
	printf("ret_orig : %d\n", ret1);
	printf("ret_cust : %d\n", ret2);
	printf("\n");
}

void	test_x_17(void)
{
	int a = 12345;
	int ret1 = 0;
	int ret2 = 0;

	printf("Test_x => 17\n");
	ret1 = printf("orig : %#2.2x\n", a);
	ret2 = ft_printf("cust : %#2.2x\n", a);
	printf("\n");
	printf("ret_orig : %d\n", ret1);
	printf("ret_cust : %d\n", ret2);
	printf("\n");
}

void	test_x_18(void)
{
	long long var = 9223372036854775807;
	int ret1 = 0;
	int ret2 = 0;

	printf("Test_x => 18\n");
	ret1 = printf("orig : %llx\n",	var);
	ret2 = ft_printf("cust : %llx\n",	var);
	printf("\n");
	printf("ret_orig : %d\n", ret1);
	printf("ret_cust : %d\n", ret2);
	printf("\n");
}

void	test_x_19(void)
{
	uintmax_t var = 9223372036854775807;
	int ret1 = 0;
	int ret2 = 0;

	printf("Test_x => 19\n");
	ret1 = printf("orig : %jx\n",	var);
	ret2 = ft_printf("cust : %jx\n",	var);
	printf("\n");
	printf("ret_orig : %d\n", ret1);
	printf("ret_cust : %d\n", ret2);
	printf("\n");
}

void	test_x_20(void)
{
	short var = 32767;
	int ret1 = 0;
	int ret2 = 0;

	printf("Test_x => 20\n");
	ret1 = printf("orig : %hx\n", var);
	ret2 = ft_printf("cust : %hx\n", var);
	printf("\n");
	printf("ret_orig : %d\n", ret1);
	printf("ret_cust : %d\n", ret2);
	printf("\n");
}

void	test_x_21(void)
{
	short var = SHRT_MIN;
	int ret1 = 0;
	int ret2 = 0;

	printf("Test_x => 21\n");
	ret1 = printf("orig : %#hx\n", var);
	ret2 = ft_printf("cust : %#hx\n", var);
	printf("\n");
	printf("ret_orig : %d\n", ret1);
	printf("ret_cust : %d\n", ret2);
	printf("\n");
}

void	test_x_22(void)
{
	int var = 256;
	int ret1 = 0;
	int ret2 = 0;

	printf("Test_x => 22\n");
	ret1 = printf("orig : %#.10x\n", var);
	ret2 = ft_printf("cust : %#.10x\n", var);
	printf("\n");
	printf("ret_orig : %d\n", ret1);
	printf("ret_cust : %d\n", ret2);
	printf("\n");
}

void	test_x_23(void)
{
	int var = 256;
	int ret1 = 0;
	int ret2 = 0;

	printf("Test_x => 23\n");
	ret1 = printf("orig : %#10x\n", var);
	ret2 = ft_printf("cust : %#10x\n", var);
	printf("\n");
	printf("ret_orig : %d\n", ret1);
	printf("ret_cust : %d\n", ret2);
	printf("\n");
}

void	test_x_24(void)
{
	size_t var = INT_MAX;
	int ret1 = 0;
	int ret2 = 0;

	printf("Test_x => 24\n");
	ret1 = printf("orig : %zx\n", var);
	ret2 = ft_printf("cust : %zx\n", var);
	printf("\n");
	printf("ret_orig : %d\n", ret1);
	printf("ret_cust : %d\n", ret2);
	printf("\n");
}

void	test_x_25(void)
{
	size_t var = INT_MAX;
	int ret1 = 0;
	int ret2 = 0;

	printf("Test_x => 25\n");
	ret1 = printf("orig : %#010zx\n", var);
	ret2 = ft_printf("cust : %#010zx\n", var);
	printf("\n");
	printf("ret_orig : %d\n", ret1);
	printf("ret_cust : %d\n", ret2);
	printf("\n");
}


void	test_x_26(void)
{
	size_t var = INT_MAX;
	int ret1 = 0;
	int ret2 = 0;

	printf("Test_x => 26\n");
	ret1 = printf("orig : %#011zx\n", var);
	ret2 = ft_printf("cust : %#011zx\n", var);
	printf("\n");
	printf("ret_orig : %d\n", ret1);
	printf("ret_cust : %d\n", ret2);
	printf("\n");
}

void	test_x_27(void)
{
	size_t var = INT_MAX;
	int ret1 = 0;
	int ret2 = 0;

	printf("Test_x => 27\n");
	ret1 = printf("orig : %080.40zx\n", var);
	ret2 = ft_printf("cust : %080.40zx\n", var);
	printf("\n");
	printf("ret_orig : %d\n", ret1);
	printf("ret_cust : %d\n", ret2);
	printf("\n");
}

void	test_x_28(void)
{
	int var = 0x12345;
	int ret1 = 0;
	int ret2 = 0;

	printf("Test_x => 28\n");
	ret1 = printf("orig : %#8.6x\n", var);
	ret2 = ft_printf("cust : %#8.6x\n", var);
	printf("\n");
	printf("ret_orig : %d\n", ret1);
	printf("ret_cust : %d\n", ret2);
	printf("\n");
}

void	test_x_29(void)
{
	int var = 0;
	int ret1 = 0;
	int ret2 = 0;

	printf("Test_x => 29\n");
	ret1 = printf("orig : %#x\n", var);
	ret2 = ft_printf("cust : %#x\n", var);
	printf("\n");
	printf("ret_orig : %d\n", ret1);
	printf("ret_cust : %d\n", ret2);
	printf("\n");
}

void	test_x_30(void)
{
	int var = 0;
	int ret1 = 0;
	int ret2 = 0;

	printf("Test_x => 30\n");
	ret1 = printf("orig : %#.2x\n", var);
	ret2 = ft_printf("cust : %#.2x\n", var);
	printf("\n");
	printf("ret_orig : %d\n", ret1);
	printf("ret_cust : %d\n", ret2);
	printf("\n");
}

void	test_x_31(void)
{
	int var = 42;
	int ret1 = 0;
	int ret2 = 0;

	printf("Test_x => 31\n");
	ret1 = printf("orig : %#-8x\n", var);
	ret2 = ft_printf("cust : %#-8x\n", var);
	printf("\n");
	printf("ret_orig : %d\n", ret1);
	printf("ret_cust : %d\n", ret2);
	printf("\n");
}

	//ft_printf("@moulitest: %#.x %#.0x", 0, 0);
void	test_x_32(void)
{
	int ret1 = 0;
	int ret2 = 0;

	printf("Test_x => 32\n");
	ret1 = printf("orig : %#.x %#.0x\n", 0, 0);
	ret2 = ft_printf("cust : %#.x %#.0x\n", 0, 0);
	printf("\n");
	printf("ret_orig : %d\n", ret1);
	printf("ret_cust : %d\n", ret2);
	printf("\n");
}

void	test_x_33(void)
{
	size_t var = INT_MAX;
	int ret1 = 0;
	int ret2 = 0;

	printf("Test_x => 27\n");
	ret1 = printf("orig : %080.20zx\n", var);
	ret2 = ft_printf("cust : %080.20zx\n", var);
	printf("\n");
	printf("ret_orig : %d\n", ret1);
	printf("ret_cust : %d\n", ret2);
	printf("\n");
}
/*
void	test_x_33(void)
{
	int ret1 = 0;
	int ret2 = 0;

	printf("Test_x => 33\n");
	ret1 = printf("orig : %#.x\n", 1);
	ret2 = ft_printf("cust : %#.x\n", 0);
	printf("\n");
	printf("ret_orig : %d\n", ret1);
	printf("ret_cust : %d\n", ret2);
	printf("\n");
}
*/

//=====================================================> conv_X

void	test_lx_01(void)
{
	int ret1 = 0;
	int ret2 = 0;

	printf("Test_X => 01\n");
	ret1 = printf("orig : %X\n", INT_MAX);
	ret2 = ft_printf("cust : %X\n", INT_MAX);
	printf("\n");
	printf("ret_orig : %d\n", ret1);
	printf("ret_cust : %d\n", ret2);
	printf("\n");
}

void	test_lx_02(void)
{
	int a = INT_MIN;
	int ret1 = 0;
	int ret2 = 0;

	printf("Test_X => 02\n");
	ret1 = printf("orig : %X\n", a);
	ret2 = ft_printf("cust : %X\n", a);
	printf("\n");
	printf("ret_orig : %d\n", ret1);
	printf("ret_cust : %d\n", ret2);
	printf("\n");
}

void	test_lx_03(void)
{
	short a = SHRT_MAX;
	int ret1 = 0;
	int ret2 = 0;

	printf("Test_X => 03\n");
	ret1 = printf("orig : %hX\n", a);
	ret2 = ft_printf("cust : %hX\n", a);
	printf("\n");
	printf("ret_orig : %d\n", ret1);
	printf("ret_cust : %d\n", ret2);
	printf("\n");
}

void	test_lx_04(void)
{
	unsigned int a = UINT_MAX;
	int ret1 = 0;
	int ret2 = 0;

	printf("Test_X => 04\n");
	ret1 = printf("orig : %#X\n", a);
	ret2 = ft_printf("cust : %#X\n", a);
	printf("\n");
	printf("ret_orig : %d\n", ret1);
	printf("ret_cust : %d\n", ret2);
	printf("\n");
}

void	test_lx_05(void)
{
	short a = SHRT_MAX;
	int ret1 = 0;
	int ret2 = 0;

	printf("Test_X => 05\n");
	ret1 = printf("orig : %hX\n", a);
	ret2 = ft_printf("cust : %hX\n", a);
	printf("\n");
	printf("ret_orig : %d\n", ret1);
	printf("ret_cust : %d\n", ret2);
	printf("\n");
}

void	test_lx_06(void)
{
	char a = CHAR_MAX;
	int ret1 = 0;
	int ret2 = 0;

	printf("Test_X => 06\n");
	ret1 = printf("orig : %hhX\n", a);
	ret2 = ft_printf("cust : %hhX\n", a);
	printf("\n");
	printf("ret_orig : %d\n", ret1);
	printf("ret_cust : %d\n", ret2);
	printf("\n");
}

void	test_lx_07(void)
{
	long a = LONG_MAX;
	int ret1 = 0;
	int ret2 = 0;

	printf("Test_X => 07\n");
	ret1 = printf("orig : %lX\n", a);
	ret2 = ft_printf("cust : %lX\n", a);
	printf("\n");
	printf("ret_orig : %d\n", ret1);
	printf("ret_cust : %d\n", ret2);
	printf("\n");
}

void	test_lx_08(void)
{
	long long a = LONG_MAX;
	int ret1 = 0;
	int ret2 = 0;

	printf("Test_X => 08\n");
	ret1 = printf("orig : %#llX\n", a);
	ret2 = ft_printf("cust : %#llX\n", a);
	printf("\n");
	printf("ret_orig : %d\n", ret1);
	printf("ret_cust : %d\n", ret2);
	printf("\n");
}

void	test_lx_09(void)
{
	long long a = LONG_MAX;
	int ret1 = 0;
	int ret2 = 0;

	printf("Test_X => 09\n");
	ret1 = printf("orig : %#25.20llX\n", a);
	ret2 = ft_printf("cust : %#25.20llX\n", a);
	printf("\n");
	printf("ret_orig : %d\n", ret1);
	printf("ret_cust : %d\n", ret2);
	printf("\n");
}

void	test_lx_10(void)
{
	long long a = 768548987678657;
	int ret1 = 0;
	int ret2 = 0;

	printf("Test_X => 10\n");
	ret1 = printf("orig : %-#28.16llX|\n", a);
	ret2 = ft_printf("cust : %-#28.16llX|\n", a);
	printf("\n");
	printf("ret_orig : %d\n", ret1);
	printf("ret_cust : %d\n", ret2);
	printf("\n");
}

void	test_lx_11(void)
{
	size_t a = INT_MAX;
	int ret1 = 0;
	int ret2 = 0;

	printf("Test_X => 11\n");
	ret1 = printf("orig : %28.16zX|\n", a);
	ret2 = ft_printf("cust : %28.16zX|\n", a);
	printf("\n");
	printf("ret_orig : %d\n", ret1);
	printf("ret_cust : %d\n", ret2);
	printf("\n");
}

void	test_lx_12(void)
{
	long long a = LONG_MIN;
	int ret1 = 0;
	int ret2 = 0;

	printf("Test_X => 12\n");
	ret1 = printf("orig : %20.14llX|\n", a);
	ret2 = ft_printf("cust : %20.14llX|\n", a);
	printf("\n");
	printf("ret_orig : %d\n", ret1);
	printf("ret_cust : %d\n", ret2);
	printf("\n");
}

//=====================================================> conv_C

void	test_c_01(void)
{
	int ret1 = 0;
	int ret2 = 0;

	printf("Test_c => 01\n");
	ret1 = printf("orig : %c\n", 'G');
	ret2 = ft_printf("cust : %c\n", 'G');
	printf("\n");
	printf("ret_orig : %d\n", ret1);
	printf("ret_cust : %d\n", ret2);
	printf("\n");
}

void	test_c_02(void)
{
	int ret1 = 0;
	int ret2 = 0;

	printf("Test_c => 02\n");
	ret1 = printf("orig : %lc	%c\n", 'G', 'e');
	ret2 = ft_printf("cust : %lc	%c\n", 'G', 'e');
	printf("\n");
	printf("ret_orig : %d\n", ret1);
	printf("ret_cust : %d\n", ret2);
	printf("\n");
}

void	test_c_03(void)
{
	int ret1 = 0;
	int ret2 = 0;

	printf("Test_c => 03\n");
	ret1 = printf("orig : %5c\n", 'G');
	ret2 = ft_printf("cust : %5c\n", 'G');
	printf("\n");
	printf("ret_orig : %d\n", ret1);
	printf("ret_cust : %d\n", ret2);
	printf("\n");
}

void	test_c_04(void)
{
	int ret1 = 0;
	int ret2 = 0;

	printf("Test_c => 04\n");
	ret1 = printf("orig : %c\n", NULL);
	ret2 = ft_printf("cust : %c\n", NULL);
	printf("\n");
	printf("ret_orig : %d\n", ret1);
	printf("ret_cust : %d\n", ret2);
	printf("\n");
}

void	test_c_05(void)
{
	int ret1 = 0;
	int ret2 = 0;

	printf("Test_c => 05\n");
	ret1 = printf("orig : %5c\n", 0);
	ret2 = ft_printf("cust : %5c\n", 0);
	printf("\n");
	printf("ret_orig : %d\n", ret1);
	printf("ret_cust : %d\n", ret2);
	printf("\n");
}

void	test_c_06(void)
{
	int ret1 = 0;
	int ret2 = 0;

	printf("Test_c => 06\n");
	ret1 = printf("orig : %1c\n", 0);
	ret2 = ft_printf("cust : %1c\n", 0);
	printf("\n");
	printf("ret_orig : %d\n", ret1);
	printf("ret_cust : %d\n", ret2);
	printf("\n");
}

void	test_c_07(void)
{
	int ret1 = 0;
	int ret2 = 0;

	printf("Test_c => 07\n");
	ret1 = printf("orig : %.2c\n", NULL);
	ret2 = ft_printf("cust : %.2c\n", NULL);
	printf("\n");
	printf("ret_orig : %d\n", ret1);
	printf("ret_cust : %d\n", ret2);
	printf("\n");
}

void	test_c_08(void)
{
	int ret1 = 0;
	int ret2 = 0;

	printf("Test_c => 08\n");
	ret1 = printf("orig : %.1c\n", NULL);
	ret2 = ft_printf("cust : %.1c\n", NULL);
	printf("\n");
	printf("ret_orig : %d\n", ret1);
	printf("ret_cust : %d\n", ret2);
	printf("\n");
}

void	test_c_09(void)
{
	int ret1 = 0;
	int ret2 = 0;

	printf("Test_c => 09\n");
	ret1 = printf("orig : %.3c\n", NULL);
	ret2 = ft_printf("cust : %.3c\n", NULL);
	printf("\n");
	printf("ret_orig : %d\n", ret1);
	printf("ret_cust : %d\n", ret2);
	printf("\n");
}

void	test_c_10(void)
{
	int ret1 = 0;
	int ret2 = 0;

	printf("Test_c => 10\n");
	ret1 = printf("orig : %lc, %lc\n", L'暖', L'ح');
	ret2 = ft_printf("cust : %lc, %lc\n", L'暖', L'ح');
	printf("\n");
	printf("ret_orig : %d\n", ret1);
	printf("ret_cust : %d\n", ret2);
	printf("\n");
}

void	test_c_11(void)
{
	int ret1 = 0;
	int ret2 = 0;

	printf("Test_c => 11\n");
	ret1 = printf("orig : {%3c}\n", 0);
	ret2 = ft_printf("cust : {%3c}\n", 0);
	printf("\n");
	printf("ret_orig : %d\n", ret1);
	printf("ret_cust : %d\n", ret2);
	printf("\n");
}

void	test_c_12(void)
{
	int ret1 = 0;
	int ret2 = 0;

	printf("Test_c => 12\n");
	ret1 = printf("orig : {%03c}\n", 0);
	ret2 = ft_printf("cust : {%03c}\n", 0);
	printf("\n");
	printf("ret_orig : %d\n", ret1);
	printf("ret_cust : %d\n", ret2);
	printf("\n");
}

void	test_c_13(void)
{
	int ret1 = 0;
	int ret2 = 0;

	printf("Test_c => 13\n");
	ret1 = printf("orig : %c\n", 0);
	ret2 = ft_printf("cust : %c\n", 0);
	printf("\n");
	printf("ret_orig : %d\n", ret1);
	printf("ret_cust : %d\n", ret2);
	printf("\n");
}

void	test_c_14(void)
{
	int ret1 = 0;
	int ret2 = 0;

	printf("Test_c => 14\n");
	ret1 = printf("orig : {%05.c}\n", 0);
	ret2 = ft_printf("cust : {%05.c}\n", 0);
	printf("\n");
	printf("ret_orig : %d\n", ret1);
	printf("ret_cust : %d\n", ret2);
	printf("\n");
}

void	test_c_15(void)
{
	int ret1 = 0;
	int ret2 = 0;

	printf("Test_c => 15\n");
	ret1 = printf("orig : {%.c %.0c}\n", 'a', 'b');
	ret2 = ft_printf("cust : {%.c %.0c}\n", 'a', 'b');
	printf("\n");
	printf("ret_orig : %d\n", ret1);
	printf("ret_cust : %d\n", ret2);
	printf("\n");
}

//=====================================================> conv_C

void	test_lc_01(void)
{
	int ret1 = 0;
	int ret2 = 0;

	printf("Test_lc => 01\n");
	ret1 = printf("orig : %C\n", 'G');
	ret2 = ft_printf("cust : %C\n", 'G');
	printf("\n");
	printf("ret_orig : %d\n", ret1);
	printf("ret_cust : %d\n", ret2);
	printf("\n");
}

void	test_lc_02(void)
{
	int ret1 = 0;
	int ret2 = 0;

	printf("Test_C => 02\n");
	ret1 = printf("orig : %C\n", L'©');
	ret2 = ft_printf("cust : %C\n", L'©');
	printf("\n");
	printf("ret_orig : %d\n", ret1);
	printf("ret_cust : %d\n", ret2);
	printf("\n");
}

void	test_lc_03(void)
{
	int ret1 = 0;
	int ret2 = 0;

	setlocale(LC_ALL, "");
	printf("Test_C => 03\n");
	ret1 = 	printf("orig : %C\n", L'©');
	ret2 = ft_printf("cust : %C\n", L'©');
	printf("\n");
	printf("ret_orig : %d\n", ret1);
	printf("ret_cust : %d\n", ret2);
	printf("\n");
}

void	test_lc_04(void)
{
	int ret1 = 0;
	int ret2 = 0;

	setlocale(LC_ALL, "");
	printf("Test_C => 04\n");
	ret1 = printf("orig : %C\n", L'ߺ');
	ret2 = ft_printf("cust : %C\n", L'ߺ');
	printf("\n");
	printf("ret_orig : %d\n", ret1);
	printf("ret_cust : %d\n", ret2);
	printf("\n");
}

void	test_lc_05(void)
{
	int ret1 = 0;
	int ret2 = 0;

	setlocale(LC_ALL, "");
	printf("Test_C => 05\n");
	ret1 = printf("orig : %C\n", L'ࠀ');
	ret2 = ft_printf("cust : %C\n", L'ࠀ');
	printf("\n");
	printf("ret_orig : %d\n", ret1);
	printf("ret_cust : %d\n", ret2);
	printf("\n");
}

void	test_lc_06(void)
{
	int ret1 = 0;
	int ret2 = 0;

	setlocale(LC_ALL, "");
	printf("Test_C => 06\n");
	ret1 = printf("orig : %C\n", L'🤗');
	ret2 = ft_printf("cust : %C\n", L'🤗');
	printf("\n");
	printf("ret_orig : %d\n", ret1);
	printf("ret_cust : %d\n", ret2);
	printf("\n");
}

void	test_lc_07(void)
{
	char a = 126;
	int ret1 = 0;
	int ret2 = 0;

	setlocale(LC_ALL, "");
	printf("Test_C => 07\n");
	ret1 = printf("orig : %C\n", a);
	ret2 = ft_printf("cust : %C\n", a);
	printf("\n");
	printf("ret_orig : %d\n", ret1);
	printf("ret_cust : %d\n", ret2);
	printf("\n");
}

void	test_lc_08(void)
{
	char a = 127;
	int ret1 = 0;
	int ret2 = 0;

	setlocale(LC_ALL, "");
	printf("Test_C => de merde\n");
	ret1 = printf("orig : %C\n", a);
	ret2 = ft_printf("cust : %C\n", a);
	printf("\n");
	printf("ret_orig : %d\n", ret1);
	printf("ret_cust : %d\n", ret2);
	printf("\n");
}

void	test_lc_09(void)
{
	wchar_t a = 248;
	int ret1 = 0;
	int ret2 = 0;

	setlocale(LC_ALL, "");
	printf("Test_C => 09\n");
	ret1 = printf("orig : %C\n", a);
	ret2 = ft_printf("cust : %C\n", a);
	printf("\n");
	printf("ret_orig : %d\n", ret1);
	printf("ret_cust : %d\n", ret2);
	printf("\n");
}

void	test_lc_10(void)
{
	wchar_t a = 248;
	int ret1 = 0;
	int ret2 = 0;

	setlocale(LC_ALL, "C");
	printf("Test_C => 10\n");
	ret1 = printf("orig : %C\n", L'©');
	ret2 = ft_printf("cust : %C\n", L'©');
	printf("\n");
	printf("ret_orig : %d\n", ret1);
	printf("ret_cust : %d\n", ret2);
	printf("\n");
}

void	test_lc_11(void)
{
	wchar_t a = 248;
	int ret1 = 0;
	int ret2 = 0;

	setlocale(LC_ALL, "");
	printf("Test_C => 11\n");
	ret1 = printf("orig : %C\n", L'©');
	ret2 = ft_printf("cust : %C\n", L'©');
	printf("\n");
	printf("ret_orig : %d\n", ret1);
	printf("ret_cust : %d\n", ret2);
	printf("\n");
}

void	test_lc_12(void)
{
	wchar_t a = 248;
	int ret1 = 0;
	int ret2 = 0;

	setlocale(LC_ALL, "C");
	printf("Test_C => 12\n");
	ret1 = printf("orig : %C\n", L'¡');
	ret2 = ft_printf("cust : %C\n", L'¡');
	printf("\n");
	printf("ret_orig : %d\n", ret1);
	printf("ret_cust : %d\n", ret2);
	printf("\n");
}

void	test_lc_13(void)
{
	//wchar_t a = 248;
	int ret1 = 0;
	int ret2 = 0;

	setlocale(LC_ALL, "C");
	printf("Test_C => 13\n");
	ret1 = printf("orig : %C\n", 173);
	ret2 = ft_printf("cust : %C\n", 173);
	printf("\n");
	printf("ret_orig : %d\n", ret1);
	printf("ret_cust : %d\n", ret2);
	printf("\n");
}

void	test_lc_14(void)
{
	int ret1 = 0;
	int ret2 = 0;

	setlocale(LC_ALL, "C");
	printf("Test_C => 14\n");
	ret1 = printf("orig : %C\n", 35);
	ret2 = ft_printf("cust : %C\n", 35);
	printf("\n");
	printf("ret_orig : %d\n", ret1);
	printf("ret_cust : %d\n", ret2);
	printf("\n");
}

void	test_lc_15(void) //broke printf
{
	int ret1 = 0;
	int ret2 = 0;

	setlocale(LC_ALL, "C");
	printf("Test_C => 15\n");
	ret1 = printf("orig : %C\n", -5);
	ret2 = ft_printf("cust : %C\n", -5);
	printf("\n");
	printf("ret_orig : %d\n", ret1);
	printf("ret_cust : %d\n", ret2);
	printf("\n");
}

void	test_lc_16(void)
{
	int ret1 = 0;
	int ret2 = 0;

	setlocale(LC_ALL, "C");
	printf("Test_C => 16\n");
	ret1 = printf("orig : %C\n", 255);
	ret2 = ft_printf("cust : %C\n", 255);
	printf("\n");
	printf("ret_orig : %d\n", ret1);
	printf("ret_cust : %d\n", ret2);
	printf("\n");
}

void	test_lc_17(void)
{
	int ret1 = 0;
	int ret2 = 0;

	setlocale(LC_ALL, "C");
	printf("Test_C => 17\n");
	ret1 = printf("orig : %C\n", 256);
	ret2 = ft_printf("cust : %C\n", 256);
	printf("\n");
	printf("ret_orig : %d\n", ret1);
	printf("ret_cust : %d\n", ret2);
	printf("\n");
}

void	test_lc_18(void)
{
	int ret1 = 0;
	int ret2 = 0;

	setlocale(LC_ALL, "C");
	printf("Test_C => 18\n");
	ret1 = printf("orig : %C\n", 35);
	ret2 = ft_printf("cust : %C\n", 35);
	printf("\n");
	printf("ret_orig : %d\n", ret1);
	printf("ret_cust : %d\n", ret2);
	printf("\n");
}


//=====================================================> conv_p

void	test_p_01(void)
{
	int a = 234235;
	int ret1 = 0;
	int ret2 = 0;

	printf("Test_p => 01\n");
	ret1 = printf("orig : %p\n", &a);
	ret2 = ft_printf("cust : %p\n", &a);
	printf("\n");
	printf("ret_orig : %d\n", ret1);
	printf("ret_cust : %d\n", ret2);
	printf("\n");
}

void	test_p_02(void)
{
	int b = 234235;
	int ret1 = 0;
	int ret2 = 0;

	printf("Test_p => 02\n");
	ret1 = printf("orig : %5p\n", &b);
	ret2 = ft_printf("cust : %5p\n", &b);
	printf("\n");
	printf("ret_orig : %d\n", ret1);
	printf("ret_cust : %d\n", ret2);
	printf("\n");
}

void	test_p_03(void)
{
	int b = 234235;
	int ret1 = 0;
	int ret2 = 0;

	printf("Test_p => 03\n");
	ret1 = printf("orig : %25p\n", &b);
	ret2 = ft_printf("cust : %25p\n", &b);
	printf("\n");
	printf("ret_orig : %d\n", ret1);
	printf("ret_cust : %d\n", ret2);
	printf("\n");
}
//printf("%p", &i)

void	test_p_04(void)
{
	int *i;
	int ret1 = 0;
	int ret2 = 0;

	printf("Test_p => 04\n");
	ret1 = printf("orig : %p\n", &i);
	ret2 = ft_printf("cust : %p\n", &i);
	printf("\n");
	printf("ret_orig : %d\n", ret1);
	printf("ret_cust : %d\n", ret2);
	printf("\n");
}

void	test_p_05(void)
{
	int *i;
	int ret1 = 0;
	int ret2 = 0;

	printf("Test_p => 05\n");
	ret1 = printf("orig : %.0p, %.p\n", 0, 0);
	ret2 = ft_printf("cust : %.0p, %.p\n", 0, 0);
	printf("\n");
	printf("ret_orig : %d\n", ret1);
	printf("ret_cust : %d\n", ret2);
	printf("\n");
}

void	test_p_06(void)
{
	int *i;
	int ret1 = 0;
	int ret2 = 0;

	printf("Test_p => 06\n");
	ret1 = printf("orig : %.0p, %.p\n", 0, 0);
	ret2 = ft_printf("cust : %.0p, %.p\n", 0, 0);
	printf("\n");
	printf("ret_orig : %d\n", ret1);
	printf("ret_cust : %d\n", ret2);
	printf("\n");
}

void	test_p_07(void)
{
	int *i;
	int ret1 = 0;
	int ret2 = 0;

	printf("Test_p => 07\n");
	ret1 = printf("orig : %p\n", 0);
	ret2 = ft_printf("cust : %p\n", 0);
	printf("\n");
	printf("ret_orig : %d\n", ret1);
	printf("ret_cust : %d\n", ret2);
	printf("\n");
}

//=====================================================> conv_%

void	test_modulo_01(void)
{
	int ret1 = 0;
	int ret2 = 0;
	printf("Modulo_test => 01\n");
	ret1 = printf("*%    %*\n");
	ret2 = ft_printf("*%   %*\n");
	printf("\n");
	printf("ret_orig : %d\n", ret1);
	printf("ret_cust : %d\n", ret2);
	printf("\n");
}

void	test_modulo_02(void)
{
	int ret1 = 0;
	int ret2 = 0;
	printf("Modulo_test => 02\n");
	ret1 = printf("orig : *%    5%*\n");
	ret2 = ft_printf("cust : *%   5%*\n");
	printf("\n");
	printf("ret_orig : %d\n", ret1);
	printf("ret_cust : %d\n", ret2);
	printf("\n");
}

void	test_modulo_03(void)
{
	int ret1 = 0;
	int ret2 = 0;
	printf("Modulo_test => 03\n");
	ret1 = printf("orig : *%-5%*\n");
	ret2 = ft_printf("cust : *%-5%*\n");
	printf("\n");
	printf("ret_orig : %d\n", ret1);
	printf("ret_cust : %d\n", ret2);
	printf("\n");
}

void	test_modulo_04(void)
{
	int ret1 = 0;
	int ret2 = 0;
	printf("Modulo_test => 04\n");
	ret1 = printf("*%.0%*\n");
	ret2 = ft_printf("*%.0%*\n");
	printf("\n");
	printf("ret_orig : %d\n", ret1);
	printf("ret_cust : %d\n", ret2);
	printf("\n");
}

void	test_modulo_05(void)
{
	int ret1 = 0;
	int ret2 = 0;
	printf("Modulo_test => 05\n");
	ret1 = printf("orig : % ");
	ret2 = ft_printf("cust : % ");
	printf("\n");
	printf("ret_orig : %d\n", ret1);
	printf("ret_cust : %d\n", ret2);
	printf("\n");
}

void	test_modulo_06(void)
{
	int ret1 = 0;
	int ret2 = 0;
	printf("Modulo_test => 06\n");
	ret1 = printf("orig : {%05.%}\n", 0);
	ret2 = ft_printf("cust : {%05.%}\n", 0);
	printf("\n");
	printf("ret_orig : %d\n", ret1);
	printf("ret_cust : %d\n", ret2);
	printf("\n");
}

//=====================================================> conv_b

void 	test_b_01(void)
{
	int ret2 = 0;

	printf("conv_b => 01\n", 42);
	printf("fake : 101010\n");
	ret2 = ft_printf("cust : %b\n", 42);
	printf("\n");
	printf("ret_cust : %d\n", ret2);
	printf("\n");
}

void 	test_b_02(void)
{
	int ret2 = 0;

	printf("conv_b => 02\n");
	ret2 = ft_printf("cust : %b\n", INT_MAX);
	printf("\n");
	printf("ret_cust : %d\n", ret2);
	printf("\n");
}

void 	test_b_03(void)
{
	int ret2 = 0;

	printf("conv_b => 03\n");
	ret2 = ft_printf("cust : %.2b\n", ULONG_MAX);
	printf("\n");
	printf("ret_cust : %d\n", ret2);
	printf("\n");
}

void 	test_b_04(void)
{
	int ret2 = 0;

	printf("conv_b => 04\n");
	ret2 = ft_printf("cust : %.10b\n", 42);
	printf("\n");
	printf("ret_cust : %d\n", ret2);
	printf("\n");
}

void 	test_b_05(void)
{
	int ret2 = 0;

	printf("conv_b => 05\n");
	ret2 = ft_printf("cust : *%-16.8b*\n", 42);
	printf("\n");
	printf("ret_cust : %d\n", ret2);
	printf("\n");
}

void 	test_b_06(void)
{
	int ret2 = 0;

	printf("conv_b => 06\n");
	ret2 = ft_printf("cust : *%16.8b*\n", 42);
	printf("\n");
	printf("ret_cust : %d\n", ret2);
	printf("\n");
}

void 	test_b_07(void)
{
	int ret2 = 0;

	printf("conv_b => 07\n");
	ret2 = ft_printf("cust : *%#16.8b*\n", 42);
	printf("\n");
	printf("ret_cust : %d\n", ret2);
	printf("\n");
}

void 	test_b_08(void)
{
	int ret2 = 0;

	printf("conv_b => 08\n");
	ret2 = ft_printf("cust : *%016b*\n", 42);
	printf("\n");
	printf("ret_cust : %d\n", ret2);
	printf("\n");
}

void 	test_b_09(void)
{
	int ret2 = 0;

	printf("conv_b => 09\n");
	printf("orig : * 0b101010*\n");
	ret2 = ft_printf("cust : *%#9b*\n", 42);
	printf("\n");
	printf("ret_cust : %d\n", ret2);
	printf("\n");
}

//=====================================================> test_null
void 	test_null_01(void)
{
	int ret1 = 0;
	int ret2 = 0;

	printf("test_null => 01\n");
	ret1 = printf("cust : {%10R}\n", 42);
	ret2 = ft_printf("cust : {%10R}\n", 42);
	printf("\n");
	printf("ret_orig : %d\n", ret1);
	printf("ret_cust : %d\n", ret2);
	printf("\n");
}

void 	test_null_02(void)
{
	int ret1 = 0;
	int ret2 = 0;

	printf("test_null => 02\n");
	ret1 = printf("cust : {%-10R}\n", 42);
	ret2 = ft_printf("cust : {%-10R}\n", 42);
	printf("\n");
	printf("ret_orig : %d\n", ret1);
	printf("ret_cust : %d\n", ret2);
	printf("\n");
}

void 	test_null_03(void)
{
	int ret1 = 0;
	int ret2 = 0;

	printf("test_null => 03\n");
	ret1 = printf("cust : {%05.Z}\n", 0);
	ret2 = ft_printf("cust : {%05.Z}\n", 0);
	printf("\n");
	printf("ret_orig : %d\n", ret1);
	printf("ret_cust : %d\n", ret2);
	printf("\n");
}

//=====================================================> test_pitch_star

void	test_pitch_star_01(void)
{
	int ret2 = 0;
	int ret1 = 0;

	printf("test_pitch_star => 01\n");
	ret1 = printf("orig : *%.6d*\n", 42, 8);
	ret2 = ft_printf("cust : *%.6d*\n", 42, 8);
	printf("\n");
	printf("ret_orig : %d\n", ret1);
	printf("ret_cust : %d\n", ret2);
	printf("\n");
}

void	test_pitch_star_02(void)
{
	int ret2 = 0;
	int ret1 = 0;

	printf("test_pitch_star => 02\n");
	ret1 = printf("orig : *%.*d*\n", 42, 8);
	ret2 = ft_printf("cust : *%.*d*\n", 42, 8);
	printf("\n");
	printf("ret_orig : %d\n", ret1);
	printf("ret_cust : %d\n", ret2);
	printf("\n");
}

void	test_pitch_star_03(void)
{
	int ret2 = 0;
	int ret1 = 0;

	printf("test_pitch_star => 03\n");
	ret1 = printf("orig : *%.*d*\n", 5, 42, 8, 9);
	ret2 = ft_printf("cust : *%.*d*\n", 5, 42, 8, 9);
	printf("\n");
	printf("ret_orig : %d\n", ret1);
	printf("ret_cust : %d\n", ret2);
	printf("\n");
}

void	test_pitch_star_04(void)
{
	int ret2 = 0;
	int ret1 = 0;

	printf("test_pitch_star => 04\n");
	ret1 = printf("orig : *%.*d %.*d %.*d*\n", 5, 42, 8, 9, 12, 25);
	ret2 = ft_printf("cust : *%.*d %.*d %.*d*\n", 5, 42, 8, 9, 12, 25);
	printf("\n");
	printf("ret_orig : %d\n", ret1);
	printf("ret_cust : %d\n", ret2);
	printf("\n");
}

void	test_pitch_star_05(void)
{
	int ret2 = 0;
	int ret1 = 0;

	printf("test_pitch_star => 05\n");
	ret1 = printf("orig : *%.*x %.*x %.*x*\n", 5, 42, 8, 9, 12, 25);
	ret2 = ft_printf("cust : *%.*x %.*x %.*x*\n", 5, 42, 8, 9, 12, 25);
	printf("\n");
	printf("ret_orig : %d\n", ret1);
	printf("ret_cust : %d\n", ret2);
	printf("\n");
}

void	test_pitch_star_06(void)
{
	int ret2 = 0;
	int ret1 = 0;

	printf("test_pitch_star => 06\n");
	ret1 = printf("orig : {%.*d}\n", -5, 42);
	ret2 = ft_printf("cust : {%.*d}\n", -5, 42);
	printf("\n");
	printf("ret_orig : %d\n", ret1);
	printf("ret_cust : %d\n", ret2);
	printf("\n");

}

void	test_pitch_star_07(void)
{
	int ret2 = 0;
	int ret1 = 0;

	printf("test_pitch_star => 07\n");
	ret1 = printf("orig : {%.*s}\n", -5, "42");
	ret2 = ft_printf("cust : {%.*s}\n", -5, "42");
	printf("\n");
	printf("ret_orig : %d\n", ret1);
	printf("ret_cust : %d\n", ret2);
	printf("\n");

}


//=====================================================> test_width_star

void	test_width_star_01(void)
{
	int ret2 = 0;
	int ret1 = 0;

	printf("test_width_star => 01\n");
	ret1 = printf("orig : *%*d*\n", 5, 42, 8, 9, 12, 25);
	ret2 = ft_printf("cust : *%*d*\n", 5, 42, 8, 9, 12, 25);
	printf("\n");
	printf("ret_orig : %d\n", ret1);
	printf("ret_cust : %d\n", ret2);
	printf("\n");
}

void	test_width_star_02(void)
{
	int ret2 = 0;
	int ret1 = 0;

	printf("test_width_star => 02\n");
	ret1 = printf("orig : *%*d %*d %*d*\n", 5, 42, 8, 9, 12, 25);
	ret2 = ft_printf("cust : *%*d %*d %*d*\n", 5, 42, 8, 9, 12, 25);
	printf("\n");
	printf("ret_orig : %d\n", ret1);
	printf("ret_cust : %d\n", ret2);
	printf("\n");
}

void	test_width_star_03(void)
{
	int ret2 = 0;
	int ret1 = 0;

	printf("test_width_star => 03\n");
	ret1 = printf("orig : *%*x %*x %*x*\n", 5, 42, 8, 9, 12, 25);
	ret2 = ft_printf("cust : *%*x %*x %*x*\n", 5, 42, 8, 9, 12, 25);
	printf("\n");
	printf("ret_orig : %d\n", ret1);
	printf("ret_cust : %d\n", ret2);
	printf("\n");
}

void	test_width_star_04(void)
{
	int ret2 = 0;
	int ret1 = 0;

	printf("test_width_star => 04\n");
	ret1 = printf("orig : *%*.*x %*.*x %*.*x*\n", 5, 12, 8, 9, 12, 25, 44);
	ret2 = ft_printf("cust : *%*.*x %*.*x %*.*x*\n", 5, 12, 8, 9, 12, 25, 44);
	printf("\n");
	printf("ret_orig : %d\n", ret1);
	printf("ret_cust : %d\n", ret2);
	printf("\n");
}

void	test_width_star_05(void)
{
	int ret2 = 0;
	int ret1 = 0;

	printf("test_width_star => 05\n");
	ret1 = printf("orig : *%*.*x*\n", 0, 0, 0, 0, 0, 0, 0);
	ret2 = ft_printf("cust : *%*.*x*\n", 0, 0, 0, 0, 0, 0, 0);
	printf("\n");
	printf("ret_orig : %d\n", ret1);
	printf("ret_cust : %d\n", ret2);
	printf("\n");
}

void	test_width_star_06(void)
{
	int ret2 = 0;
	int ret1 = 0;

	printf("test_width_star => 06\n");
	ret1 = printf("orig : {%*d}\n", -5, 42);
	ret2 = ft_printf("cust : {%*d}\n", -5, 42);
	printf("\n");
	printf("ret_orig : %d\n", ret1);
	printf("ret_cust : %d\n", ret2);
	printf("\n");
}

void	test_width_star_07(void)
{
	int ret2 = 0;
	int ret1 = 0;

	printf("test_width_star => 07\n");
	ret1 = printf("orig : {%*d}\n", 0, 42);
	ret2 = ft_printf("cust : {%*d}\n", 0, 42);
	printf("\n");
	printf("ret_orig : %d\n", ret1);
	printf("ret_cust : %d\n", ret2);
	printf("\n");
}

void	test_width_star_08(void)
{
	int ret1 = 0;
	int ret2 = 0;

	printf("test_width_star => 08\n");
	ret1 = printf("orig : {%*c}\n", -15, 0);
	ret2 = ft_printf("cust : {%*c}\n", -15, 0);
	printf("\n");
	printf("ret_orig : %d\n", ret1);
	printf("ret_cust : %d\n", ret2);
	printf("\n");
}

void	test_width_star_09(void)
{
	int ret1 = 0;
	int ret2 = 0;

	printf("test_width_star => 09\n");
	ret1 = printf("orig : {%*5d}\n", 0, 0);
	ret2 = ft_printf("cust : {%*5d}\n", 0, 0);
	printf("\n");
	printf("ret_orig : %d\n", ret1);
	printf("ret_cust : %d\n", ret2);
	printf("\n");
}

void	test_width_star_10(void)
{
	int ret1 = 0;
	int ret2 = 0;

	printf("test_width_star => 10\n");
	ret1 = printf("orig : {%5*d}\n", 0, 0);
	ret2 = ft_printf("cust : {%5*d}\n", 0, 0);
	printf("\n");
	printf("ret_orig : %d\n", ret1);
	printf("ret_cust : %d\n", ret2);
	printf("\n");
}

void	test_width_star_11(void)
{
	int ret1 = 0;
	int ret2 = 0;

	printf("test_width_star => 11\n");
	ret1 = printf("orig : {%*5d}\n", 3, 0);
	ret2 = ft_printf("cust : {%*5d}\n", 3, 0);
	printf("\n");
	printf("ret_orig : %d\n", ret1);
	printf("ret_cust : %d\n", ret2);
	printf("\n");
}



// void	test_width_star_02(void)
// {
// 	int ret2 = 0;
// 	int ret1 = 0;
//
// 	printf("test_pitch_star => 01\n");
// 	ret1 = printf("orig : *%*d*\n", 5, 42, 8, 9, 12, 25);
// 	ret2 = ft_printf("cust : *%*d*\n", 5, 42, 8, 9, 12, 25);
// 	printf("\n");
// 	printf("ret_orig : %d\n", ret1);
// 	printf("ret_cust : %d\n", ret2);
// 	printf("\n");
// }
/*
void	test_width_star_02(void)
{
	int ret2 = 0;
	int ret1 = 0;

	printf("test_pitch_star => 02\n");
	ret1 = printf("orig : *%.*d %.*d %.*d*\n", 5, 42, 8, 9, 12, 25);
	ret2 = ft_printf("cust : *%.*d %.*d %.*d*\n", 5, 42, 8, 9, 12, 25);
	printf("\n");
	printf("ret_orig : %d\n", ret1);
	printf("ret_cust : %d\n", ret2);
	printf("\n");
}
*/

//=====================================================> mutant_test

void 	mutant_01(void)
{
	long long a = LONG_MAX;
	int ret1 = 0;
	int ret2 = 0;

	printf("Mutant_test => 01\n");
	ret1 = printf("*%5%*\n");
	ret2 = ft_printf("*%5%*\n");
	printf("\n");
	printf("ret_orig : %d\n", ret1);
	printf("ret_cust : %d\n", ret2);
	printf("\n");
}

void 	mutant_02(void)
{
	long long a = LONG_MAX;
	int ret1 = 0;
	int ret2 = 0;

	printf("Mutant_test => 02\n");
	ret1 = printf("*%-5%*\n");
	ret2 = ft_printf("*%-5%*\n");
	printf("\n");
	printf("ret_orig : %d\n", ret1);
	printf("ret_cust : %d\n", ret2);
	printf("\n");
}

void 	mutant_03(void)
{
	printf("Mutant_test => 03\n");
	//printf("%   %", "test");
	//ft_printf("%   %", "test");
	printf("\n");
}

void 	mutant_04(void)
{
	printf("Mutant_test => 04\n");
	//ft_printf("%069999999d\n", 42);
	printf("\n");
}

void 	mutant_05(void)
{
	printf("Mutant_test => 05\n");
	printf("");
	ft_printf("");

	printf("\n");
}

void 	mutant_06(void)
{
	int ret1 = 0;
	int ret2 = 0;
	printf("Mutant_test => 06\n");
	ret1 = printf("%    m\n");
	ret2 = ft_printf("%   m\n");
	printf("\n");
	printf("ret_orig : %d\n", ret1);
	printf("ret_cust : %d\n", ret2);
	printf("\n");
}

void	mutant_07(void)
{
	size_t a = LONG_MAX;
	int ret1 = 0;
	int ret2 = 0;

	printf("Mutant_test => 07\n");
	ret1 = printf("orig : %-20.5s.2 %s %012d %x\n", STR, "pain au chocolat", 254, 9874);
	ret2 = ft_printf("cust : %-20.5s.2 %s %012d %x\n", STR, "pain au chocolat", 254, 9874);
	printf("\n");
	printf("ret_orig : %d\n", ret1);
	printf("ret_cust : %d\n", ret2);
	printf("\n");
}
	//assert_printf("s: %s, p: %p, d:%d", "a string", &test_simple_mix, 42);
void	mutant_08(void)
{
	size_t a = LONG_MAX;
	int ret1 = 0;
	int ret2 = 0;

	printf("Mutant_test => 08\n");
	ret1 = printf("orig : %s %p %d\n", "a string", &mutant_08, 42);
	ret2 = ft_printf("cust : %s %p %d\n", "a string", &mutant_08, 42);
	printf("\n");
	printf("ret_orig : %d\n", ret1);
	printf("ret_cust : %d\n", ret2);
	printf("\n");
}

void	mutant_09(void)
{
	size_t a = LONG_MAX;
	int ret1 = 0;
	int ret2 = 0;

	printf("Mutant_test => 09\n");
	ret1 = printf("orig : %o\n", 42);
	ret2 = ft_printf("cust : %o\n", 42);
	printf("\n");
	printf("ret_orig : %d\n", ret1);
	printf("ret_cust : %d\n", ret2);
	printf("\n");
}

void	mutant_10(void)
{
	char c = 'z';
	size_t a = LONG_MAX;
	int ret1 = 0;
	int ret2 = 0;

	setlocale(LC_ALL, "");
	printf("Mutant_test => 10\n");
	ret1 = printf("orig : %s %d %p %% %S D|%D i|%i o|%o %O %u%U%x%X%c%C\n","bonjour", 42, &c, L"暖炉", LONG_MAX, 42, 42, 42, 100000, ULONG_MAX, 42, 42, 'c', L'플');
	fflush(stdout);
	ret2 = ft_printf("cust : %s %d %p %% %S D|%D i|%i o|%o %O %u%U%x%X%c%C\n","bonjour", 42, &c, L"暖炉", LONG_MAX, 42, 42, 42, 100000, ULONG_MAX, 42, 42, 'c', L'플');
	ret2 = ft_printf("cust : %s %d %p %% %S D|%D i|%i o|%o %O %u%U%x%X%c%C\n","bonjour", 42, &c, L"暖炉", LONG_MAX, 42, 42, 42, 100000, ULONG_MAX, 42, 42, 'c', L'플');
	ret2 = ft_printf("cust : %s %d %p %% %S D|%D i|%i o|%o %O %u%U%x%X%c%C\n","bonjour", 42, &c, L"暖炉", LONG_MAX, 42, 42, 42, 100000, ULONG_MAX, 42, 42, 'c', L'플');
	ret2 = ft_printf("cust : %s %d %p %% %S D|%D i|%i o|%o %O %u%U%x%X%c%C\n","bonjour", 42, &c, L"暖炉", LONG_MAX, 42, 42, 42, 100000, ULONG_MAX, 42, 42, 'c', L'플');
	ret2 = ft_printf("cust : %s %d %p %% %S D|%D i|%i o|%o %O %u%U%x%X%c%C\n","bonjour", 42, &c, L"暖炉", LONG_MAX, 42, 42, 42, 100000, ULONG_MAX, 42, 42, 'c', L'플');
	ret2 = ft_printf("cust : %s %d %p %% %S D|%D i|%i o|%o %O %u%U%x%X%c%C\n","bonjour", 42, &c, L"暖炉", LONG_MAX, 42, 42, 42, 100000, ULONG_MAX, 42, 42, 'c', L'플');

	ft_printf("o == probleme\n");
	ft_printf("o == probleme\n");
	ft_printf("o == probleme\n");
	ft_printf("o == probleme\n");
	ft_printf("o == probleme\n");
	ft_printf("o == probleme\n");
	ft_printf("o == probleme\n");
	ft_printf("o == probleme\n");
	ft_printf("o == probleme\n");
	printf("\n");
	printf("ret_orig : %d\n", ret1);
	printf("ret_cust : %d\n", ret2);
	printf("\n");
}

void	mutant_11(void)
{
	size_t a = LONG_MAX;
	int ret1 = 0;
	int ret2 = 0;

	printf("Mutant_test => 11\n");
	ret1 = printf("orig : {%10R}\n");
	ret2 = ft_printf("cust : {%10R}\n");
	printf("\n");
	printf("ret_orig : %d\n", ret1);
	printf("ret_cust : %d\n", ret2);
	printf("\n");
}

void	mutant_12(void)
{
	size_t a = LONG_MAX;
	int ret1 = 0;
	int ret2 = 0;

	printf("Mutant_test => 12\n");
	ret1 = printf("orig : {esgrdth}{%10R}\n");
	ret2 = ft_printf("cust : {esgrdth}{%10R}\n");
	printf("\n");
	printf("ret_orig : %d\n", ret1);
	printf("ret_cust : %d\n", ret2);
	printf("\n");
}
/*
void	mutant_09(void)
{
	size_t a = LONG_MAX;
	int ret1 = 0;
	int ret2 = 0;

	setlocale(LC_ALL, "");
	printf("Mutant_test => 09\n");
	ret1 = printf("orig : %S\n", L"米");
	ret2 = ft_printf("cust : %S\n", L"米");
	printf("\n");
	printf("ret_orig : %d\n", ret1);
	printf("ret_cust : %d\n", ret2);
	printf("\n");
}
*/


//=====================================================> test_e

void 	test_e_01(void)
{
	int ret1 = 0;
	int ret2 = 0;

	printf("test_e => 01\n");
	ret1 = printf("cust : %e\n", 78);
	ret2 = ft_printf("cust : %e\n", 78);
	printf("\n");
	printf("ret_orig : %d\n", ret1);
	printf("ret_cust : %d\n", ret2);
	printf("\n");
}

void 	test_e_02(void)
{
	int ret1 = 0;
	int ret2 = 0;

	printf("test_e => 02\n");
	ret1 = printf("cust : %e\n", 1);
	ret2 = ft_printf("cust : %e\n", 1);
	printf("\n");
	printf("ret_orig : %d\n", ret1);
	printf("ret_cust : %d\n", ret2);
	printf("\n");
}

void 	test_e_03(void)
{
	int ret1 = 0;
	int ret2 = 0;

	printf("test_e => 03\n");
	ret1 = printf("cust : %e\n", 1.000);
	ret2 = ft_printf("cust : %e\n", 1.000);
	printf("\n");
	printf("ret_orig : %d\n", ret1);
	printf("ret_cust : %d\n", ret2);
	printf("\n");
}

void 	test_e_04(void)
{
	int ret1 = 0;
	int ret2 = 0;

	printf("test_e => 04\n");
	ret1 = printf("cust : %e\n", 4242.42424242);
	ret2 = ft_printf("cust : %e\n", 4242.42424242);
	printf("\n");
	printf("ret_orig : %d\n", ret1);
	printf("ret_cust : %d\n", ret2);
	printf("\n");
}

void 	test_e_05(void)
{
	int ret1 = 0;
	int ret2 = 0;

	printf("test_e => 05\n");
	ret1 = printf("cust : %e\n", 0.0004242);
	ret2 = ft_printf("cust : %e\n", 0.0004242);
	printf("\n");
	printf("ret_orig : %d\n", ret1);
	printf("ret_cust : %d\n", ret2);
	printf("\n");
}

void 	test_e_06(void)
{
	int ret1 = 0;
	int ret2 = 0;

	printf("test_e => 06\n");
	ret1 = printf("cust : %.3e\n", 0.0004242);
	ret2 = ft_printf("cust : %.3e\n", 0.0004242);
	printf("\n");
	printf("ret_orig : %d\n", ret1);
	printf("ret_cust : %d\n", ret2);
	printf("\n");
}

void 	test_e_07(void)
{
	int ret1 = 0;
	int ret2 = 0;

	printf("test_e => 07\n");
	ret1 = printf("cust : %10.2e\n", 0.0004242);
	ret2 = ft_printf("cust : %10.2e\n", 0.0004242);
	printf("\n");
	printf("ret_orig : %d\n", ret1);
	printf("ret_cust : %d\n", ret2);
	printf("\n");
}

void 	test_e_08(void)
{
	int ret1 = 0;
	int ret2 = 0;

	printf("test_e => 08\n");
	ret1 = printf("cust : %#5.12e\n", 0.0004242);
	ret2 = ft_printf("cust : %#5.12e\n", 0.0004242);
	printf("\n");
	printf("ret_orig : %d\n", ret1);
	printf("ret_cust : %d\n", ret2);
	printf("\n");
}

void 	test_e_09(void)
{
	int ret1 = 0;
	int ret2 = 0;

	printf("test_e => 08\n");
	ret1 = printf("cust : %#5.12e\n", 0.0004242);
	ret2 = ft_printf("cust : %#5.12e\n", 0.0004242);
	printf("\n");
	printf("ret_orig : %d\n", ret1);
	printf("ret_cust : %d\n", ret2);
	printf("\n");
}

//=====================================================> test_le

void 	test_le_01(void)
{
	int ret1 = 0;
	int ret2 = 0;

	printf("test_E => 01\n");
	ret1 = printf("cust : %e\n", 78);
	ret2 = ft_printf("cust : %e\n", 78);
	printf("\n");
	printf("ret_orig : %d\n", ret1);
	printf("ret_cust : %d\n", ret2);
	printf("\n");
}

//=====================================================> test_f

void 	test_f_01(void)
{
	int ret1 = 0;
	int ret2 = 0;

	printf("test_f => 01\n");
	ret1 = printf("orig : %f\n", 42);
	ret2 = ft_printf("cust : %f\n", 42);
	printf("\n");
	printf("ret_orig : %d\n", ret1);
	printf("ret_cust : %d\n", ret2);
	printf("\n");
}

void 	test_f_02(void)
{
	int ret1 = 0;
	int ret2 = 0;

	printf("test_f => 02\n");
	ret1 = printf("orig : %f\n", 42.00);
	ret2 = ft_printf("cust : %f\n", 42.00);
	printf("\n");
	printf("ret_orig : %d\n", ret1);
	printf("ret_cust : %d\n", ret2);
	printf("\n");
}

void 	test_f_03(void)
{
	int ret1 = 0;
	int ret2 = 0;

	printf("test_f => 03\n");
	ret1 = printf("orig : {%f}\n", 1.42);
	ret2 = ft_printf("cust : {%f}\n", 1.42);
	printf("\n");
	printf("ret_orig : %d\n", ret1);
	printf("ret_cust : %d\n", ret2);
	printf("\n");
}
//	assert_printf("{%f}{%F}", 1.42, 1.42);

//=====================================================> test_g

void 	test_g_01(void)
{
	int ret1 = 0;
	int ret2 = 0;

	printf("test_g => 01\n");
	ret1 = printf("cust : %g\n", 42);
	ret2 = ft_printf("cust : %g\n", 42);
	printf("\n");
	printf("ret_orig : %d\n", ret1);
	printf("ret_cust : %d\n", ret2);
	printf("\n");
}

void 	test_g_02(void)
{
	int ret1 = 0;
	int ret2 = 0;

	printf("test_g => 02\n");
	ret1 = printf("cust : %g\n", 42.000);
	ret2 = ft_printf("cust : %g\n", 42.000);
	printf("\n");
	printf("ret_orig : %d\n", ret1);
	printf("ret_cust : %d\n", ret2);
	printf("\n");
}

void 	test_g_03(void)
{
	int ret1 = 0;
	int ret2 = 0;

	printf("test_g => 02\n");
	ret1 = printf("cust : %g\n", 42.420);
	ret2 = ft_printf("cust : %g\n", 42.420);
	printf("\n");
	printf("ret_orig : %d\n", ret1);
	printf("ret_cust : %d\n", ret2);
	printf("\n");
}


//=====================================================> test_color

void 	test_color_01(void)
{
	int ret1 = 0;
	int ret2 = 0;

	printf("test_color => 01\n");
	ret2 = ft_printf("cust :{black} %s{eoc} no color\n", "black");
	printf("\n");
	//printf("ret_orig : %d\n", ret1);
	printf("ret_cust : %d\n", ret2);
	printf("\n");
}

void 	test_color_02(void)
{
	int ret1 = 0;
	int ret2 = 0;

	printf("test_color => 02\n");
	ret2 = ft_printf("cust :{red} %s{eoc} no color\n", "red");
	printf("\n");
	//printf("ret_orig : %d\n", ret1);
	printf("ret_cust : %d\n", ret2);
	printf("\n");
}

void 	test_color_03(void)
{
	int ret1 = 0;
	int ret2 = 0;

	printf("test_color => 03\n");
	ret2 = ft_printf("cust :{green} %s{eoc} no color\n", "green");
	printf("\n");
	printf("ret_orig : %d\n", ret1);
	printf("ret_cust : %d\n", ret2);
	printf("\n");
}

void 	test_color_04(void)
{
	int ret1 = 0;
	int ret2 = 0;

	printf("test_color => 04\n");
	ret2 = ft_printf("cust :{yellow} %s{eoc} no color\n", "yellow");
	printf("\n");
	printf("ret_orig : %d\n", ret1);
	printf("ret_cust : %d\n", ret2);
	printf("\n");
}

void 	test_color_05(void)
{
	int ret1 = 0;
	int ret2 = 0;

	printf("test_color => 05\n");
	ret2 = ft_printf("cust :{blue} %s{eoc} no color\n", "blue");
	printf("\n");
	printf("ret_orig : %d\n", ret1);
	printf("ret_cust : %d\n", ret2);
	printf("\n");
}

void 	test_color_06(void)
{
	int ret1 = 0;
	int ret2 = 0;

	printf("test_color => 06\n");
	ret2 = ft_printf("cust :{magenta} %s{eoc} no color\n", "magenta");
	printf("\n");
	printf("ret_orig : %d\n", ret1);
	printf("ret_cust : %d\n", ret2);
	printf("\n");
}

void 	test_color_07(void)
{
	int ret1 = 0;
	int ret2 = 0;

	printf("test_color => 07\n");
	ret2 = ft_printf("cust :{cyan} %s{eoc} no color\n", "cyan");
	printf("\n");
	printf("ret_orig : %d\n", ret1);
	printf("ret_cust : %d\n", ret2);
	printf("\n");
}

void 	test_color_08(void)
{
	int ret1 = 0;
	int ret2 = 0;

	printf("test_color => 08\n");
	ret2 = ft_printf("cust :{white} %s{eoc} no color\n", "white");
	printf("\n");
	printf("ret_orig : %d\n", ret1);
	printf("ret_cust : %d\n", ret2);
	printf("\n");
}





void	test_s(void)
{
	test_s_01();
	test_s_02();
	test_s_03();
	test_s_04();
	test_s_05();
	test_s_06();
	test_s_07();
	test_s_08();
	test_s_09();
	test_s_10();
	test_s_11();
	test_s_12();
	test_s_13();
	test_s_14();
	test_s_15();
	test_s_16();
	test_s_17();
	test_s_18();
}

void	test_ls(void)
{
	test_ls_01();
	test_ls_02();
	test_ls_03();
	test_ls_04();
	test_ls_05();
	test_ls_06();
	test_ls_07();
	test_ls_08();
	test_ls_09();
	test_ls_10();
	test_ls_11();
	test_ls_12();
	test_ls_13();
	test_ls_14();
	test_ls_15();
	test_ls_16();
	test_ls_17();
	test_ls_18();
	test_ls_19();
	test_ls_20();
}

void 	test_d(void)
{
	test_d_01();
	test_d_02();
	test_d_03();
	test_d_04();
	test_d_05();
	test_d_06();
	test_d_07();
	test_d_08();
	test_d_09();
	test_d_10();
	test_d_11();
	test_d_12();
	test_d_13();
	test_d_14();
	test_d_15();
	test_d_16();
	test_d_17();
	test_d_18();
	test_d_19();
	test_d_20();
	test_d_21();
	test_d_22();
	test_d_23();
	test_d_24();
	test_d_25();
	test_d_26();
	test_d_27();
	test_d_28();
	test_d_29();
	test_d_30();
	test_d_31();
	test_d_32();
	test_d_33();
	test_d_34();
	test_d_35();
	test_d_36();
	test_d_37();
	test_d_38();
	test_d_39();
	test_d_40();
	test_d_41();
	test_d_42();

}

void 	test_ld(void)
{
	test_ld_01();
	test_ld_02();
	test_ld_03();
	test_ld_04();
	test_ld_05();
	test_ld_06();
	test_ld_07();
	test_ld_08();
	test_ld_09();
	test_ld_10();
	test_ld_11();
	test_ld_12();
	test_ld_13();
	test_ld_14();
	test_ld_15();
	test_ld_16();
}

void 	test_x(void)
{
	test_x_01();
	test_x_02();
	test_x_04();
	test_x_05();
	test_x_06();
	test_x_07();
	test_x_08();
	test_x_09();
	test_x_10();
	test_x_11();
	test_x_12();
	test_x_13();
	test_x_14();
	test_x_15();
	test_x_16();
	test_x_17();
	test_x_18();
	test_x_19();
	test_x_20();
	test_x_21();
	test_x_22();
	test_x_23();
	test_x_24();
	test_x_25();
	test_x_26();
	test_x_27();
	test_x_28();
	test_x_29();
	test_x_30();
	test_x_31();
	test_x_32();
}

void test_lx(void)
{
	test_lx_01();
	test_lx_02();
	test_lx_03();
	test_lx_04();
	test_lx_05();
	test_lx_06();
	test_lx_07();
	test_lx_08();
	test_lx_09();
	test_lx_10();
	test_lx_11();
	test_lx_12();
}

void 	test_i(void)
{
	test_i_01();
	test_i_02();
	test_i_03();
	test_i_04();
	test_i_05();
	test_i_06();
	test_i_07();
	test_i_08();
	test_i_09();
}

void 	test_o(void)
{
	test_o_01();
	test_o_02();
	test_o_03();
	test_o_04();
	test_o_05();
	test_o_06();
	test_o_07();
	test_o_08();
	test_o_09();
	test_o_10();
	test_o_11();
	test_o_12();
	test_o_13();
	test_o_14();
	test_o_15();
	test_o_16();
	test_o_17();
	test_o_18();
	test_o_19();
	test_o_20();
	test_o_21();
}

void	test_lo(void)
{
	test_lo_01();
	test_lo_02();
	test_lo_03();
	test_lo_04();
	test_lo_05();
	test_lo_06();
	test_lo_07();
	test_lo_08();
	test_lo_09();
	test_lo_10();
	test_lo_11();
	test_lo_12();
	test_lo_13();
}

void	test_u(void)
{
	test_u_01();
	test_u_02();
	test_u_03();
	test_u_04();
	test_u_05();
	test_u_06();
	test_u_07();
	test_u_08();
	test_u_09();
	test_u_10();
	test_u_11();
	test_u_12();
	test_u_13();
	test_u_14();
	test_u_15();
	test_u_16();
	test_u_17();
}

void	test_lu(void)
{
	test_lu_01();
	test_lu_02();
	test_lu_03();
	test_lu_04();
	test_lu_05();
	test_lu_06();
	test_lu_07();
	test_lu_08();
	test_lu_09();

}


void	test_p(void)
{
	test_p_01();
	test_p_02();
	test_p_03();
	test_p_04();
	test_p_05();
	test_p_06();
	test_p_07();
}

void	test_c(void)
{
	test_c_01();
	test_c_02();
	test_c_03();
	test_c_04();
	test_c_05();
	test_c_06();
	test_c_07();
	test_c_08();
	test_c_09();
	test_c_10();
	test_c_11();
	test_c_12();
	test_c_13();
	test_c_14();
	test_c_15();
}

void	test_lc(void)
{
	test_lc_01();
	test_lc_02();
	test_lc_03();
	test_lc_04();
	test_lc_05();
	test_lc_06();
	test_lc_07();
	test_lc_08();
	test_lc_09();
	test_lc_10();
	test_lc_11();
	test_lc_12();
	test_lc_13();
	test_lc_14();
	// test_lc_15();
	test_lc_16();
	// test_lc_17();
	// test_lc_18();
}

void	test_modulo(void)
{
	test_modulo_01();
	test_modulo_02();
	test_modulo_03();
	test_modulo_04();
	test_modulo_05();
	test_modulo_06();

}

void	test_null(void)
{
	test_null_01();
	test_null_02();
	test_null_03();

}

void	test_b(void)
{
	test_b_01();
	test_b_02();
	test_b_03();
	test_b_04();
	test_b_05();
	test_b_06();
	test_b_07();
	test_b_08();
	test_b_09();

}

void	test_pitch_star(void)
{
	test_pitch_star_01();
	test_pitch_star_02();
	test_pitch_star_03();
	test_pitch_star_04();
	test_pitch_star_05();
	test_pitch_star_06();
	test_pitch_star_07();
}

void	test_width_star(void)
{
	test_width_star_01();
	test_width_star_02();
	test_width_star_03();
	test_width_star_04();
	test_width_star_05();
	test_width_star_06();
	test_width_star_07();
	test_width_star_08();
	test_width_star_09();
	test_width_star_10();
	test_width_star_11();
}

void 	mutant_test(void)
{
	mutant_01();
	mutant_02();
	mutant_03();
	mutant_04();
	mutant_05();
	mutant_06();
	mutant_07();
	mutant_08();
	mutant_09();
	mutant_10();
	mutant_11();
	mutant_12();
}

void	test_e(void)
{
	test_e_01();
	test_e_02();
	test_e_03();
	test_e_04();
	test_e_05();
	test_e_06();
	test_e_07();
	test_e_08();
	test_e_09();

}

void	test_le(void)
{
	test_le_01();
}

void	test_f(void)
{
	test_f_01();
	test_f_02();
	test_f_03();
}

void	test_g(void)
{
	test_g_01();
	test_g_02();
	test_g_03();

}

void	test_color(void)
{
	test_color_01();
	test_color_02();
	test_color_03();
	test_color_04();
	test_color_05();
	test_color_06();
	test_color_07();
	test_color_08();

}

int main(void)
{
	//setbuf(stdout, NULL);
	//Start Conv_s
	printf("=======> Conv_s <======= OK\n");
	test_s();

	//Start
	printf("=======> Conv_S <======= OK\n");
	test_ls();

	//Start conv_p
	printf("=======> Conv_p <======= OK\n");
	test_p();

	printf("=======> Conv_d <======= MEH\n");
	test_d();

	printf("=======> Conv_D <======= MEEEEEEEH\n");
	test_ld();

	printf("=======> Conv_i <======= OK\n");
	test_i();

	printf("=======> Conv_o <======= OK\n");
	test_o();

	printf("=======> Conv_O <======= MEEEEEEEH\n");
	test_lo();

	printf("=======> Conv_u <======= OK\n");
	test_u();

	printf("=======> Conv_lu <======= MEEEEEEH\n");
	test_lu();

	printf("=======> Conv_x <======= OK\n");
	test_x();

	printf("=======> Conv_lx <======= OK\n");
	test_lx();

	printf("=======> Conv_c <======= OK\n");
	test_c();
	//Start conv_lc
	printf("=======> Conv_lc <======= MEH\n");
	test_lc();

	printf("=======> Conv_%% <======= MEEEEEEEH\n");
	test_modulo();

	printf("=======> Conv_b <======= NOT IMP\n");
	// test_b();

	printf("=======> Conv_null <======= MEH\n");
	test_null();

	printf("=======> Pitch_Star <======= OK\n");
	test_pitch_star();

	printf("=======> Width_Star <======= MEH\n");
	test_width_star();

	//Start Mutants
	printf("=======> Mutant_Test <======= MEH\n");
	//mutant_test();

	printf("=======> Conv_e <======= NOT IMP\n");
	//test_e();

	printf("=======> Conv_E <======= NOT IMP\n");
	// mutant_test();

	printf("=======> Conv_f <======= NOT IMP\n");
	// test_f();

	printf("=======> Conv_g <=======\n");
	// test_g();

	printf("=======> Test_color <=======\n");
	//test_color();


	//test de merde

	// printf("printf : %x\n", 9223372036854775807);
	// ft_printf("ft_printf : %x\n", 9223372036854775807);
	// printf("printf : %x\n", -9223372036854775807);
	// ft_printf("ft_printf : %x\n", -9223372036854775807);
	// printf("printf : %x\n", 18446744073709551615);
	// ft_printf("ft_printf : %x\n", 18446744073709551615);
	// printf("printf : %hx\n", 18446744073709551615);
	// ft_printf("ft_printf : %hx\n", 18446744073709551615);
	// int i = 0;
	// char buffer[10000];
	// printf("orig hexa = %x\n", 42);
	// printf("orig hexa = %x\n", -42);
	// printf("orig hexa = %x\n", 87455477);
	// printf("hexa test = %x\n", 0x15f9);
	// printf("hexa test = %x\n", -5625);
	// printf("hexa test ll = %llx\n", INT_MAX+1);
	//print_binary(0);
	//ft_printf("cust = %d\n", INT_MAX);
	// printf("sizeof %lld\n", sizeof(uintmax_t));
	// printf("test printf llx %llx\n", -9223372036854775806);
	// printf("test printf llx %llx\n", -1000000000000000000);
	// printf("test printf llx %lld\n", 0xf21f494c589c0000);
	// printf("test printf llx %lld\n", 17446744073709552000);
	// printf("test printf x %x\n", INT_MIN);
	// printf("test printf llx %llx\n", INT_MIN);
	// printf("test printf x %x\n", INT_MAX + 5);
	// printf("test printf llx %llx\n", INT_MAX * INT_MAX);
	// printf("test printf unsigned llx %llx\n", 4294967295);
	// printf("test printf unsigned llx %llx\n", 9223372036854775807);
	// printf("\n");
	// printf("test printf 2147483647 %x\n", 2147483647);
	// printf("test printf %x\n\n", -2147483648);
	// printf("test printf %u\n", 4294967295 - 88);
	// printf("test printf %d\n", 4294967295 - 87);
	// printf("test printf %x\n", -88);
	// printf("test printf %d\n\n", 4294967208);
	// printf("test printf llx %llx\n", 18446744073709551615);
	// printf("test printf llx %llx\n", 4294967295);
	// printf("test printf llx %x\n", 4294967295);
	// printf("test printf llx %llx\n", 4294967295 - 87);
	// printf("test printf llx %llx\n", -88);
	// printf("test printf hexa llx %lld\n", 0x8000000000000000);
	// printf("test printf hexa llx 0xFFFFFFFFFFFFFFFF == %lld\n", 0xFFFFFFFFFFFFFFFF);
	// printf("test printf hexa llx 0xFFFFFFFFFFFFFFFE == %lld\n", 0xFFFFFFFFFFFFFFFE);
	// printf("test printf hexa llx 9223372036854775807 == 0x%llx\n", 9223372036854775907);
	// printf("test printf hexa llx test == %lld\n", 0x7FFFFFFFFFFFFFFF );
	// printf("test printf hexa lld test == %lld   cast in signed long long\n", 0x8000000000000000 );
	// printf("test printf hexa lld test == %lld   cast in signed long long\n", 0x0000000080000000 );
	// printf("test printf hexa lld test == %d   cast in signed int\n\n", 0x80000000 );
	//
	// printf("test printf hexa x test == 0x%x \n", 4294967296 );
	// printf("test x test == 0x%jx \n", 4294967296 );
	// printf("test x test == 0x%llx \n", 2147483649 );
	// printf("test x test == 0x%lld \n", 0x7FFFFFFFFFFFFFFF);
	// printf("test lld test == 0x%lld \n", 18446744073709551615);
	// printf("test u test == %llu \n", 0x8000000000000000);
	//
	// ft_printf("test ft d == %d\n", 2147483647);
	// ft_printf("test ft d == %d\n", 2);
	// ft_printf("test ft d == %d\n", 2147483680);
	// ft_printf("\n");
	//
	// ft_printf("test ft d 2 == %d\n\n", 2);
	// ft_printf("test ft d 2147483647 == %d\n", 2147483647);
	// ft_printf("test ft d 4294967296 == %d\n", 4294967296);
	// printf("printf dif d 4294967296 == %d\n\n", 4294967296);
	// ft_printf("test ft hd 4294967296 == %hd\n", 4294967296);
	// printf("printf dif hd 4294967296 == %hd\n", 4294967296);
	// ft_printf("test ft hd 4294 == %hd\n", 4294222);
	// printf("printf dif hd 4294 == %hd\n", 4294222);
	//ft_printf("test ft d 9223372036854775807 == %d\n", 9223372036854775807);
	//printf("printf dif d 9223372036854775807 == %d\n", 9223372036854775807);


	//ft_printf("cust = %d\n", UINT_MAX);
	// ft_printf("cust = %d\n\n", INT_MAX);
	//ft_printf("cust = %s\n", ft_itoa_base(88, 16));

//	ft_printf("cust = %s\n", ft_itoa_base(-88, 16));

	// printf("\n");
	// printf("When printf cast in ll   %x\n", -2147483648);
	// printf("When printf cast in ll   %x\n", -2147483649);
	// printf("When printf cast in ll   %llx\n", -2147483649);
	// printf("When printf cast in ll   %llx\n", -2147483647);


	// ft_printf("ft_printf %....12.6d\n", 1234);
	// printf("printf    %....12.6d\n", 1234);
	// printf("\n");
	// ft_printf("ft_printf %*3$d\n", 3, 5, 6, 7);
	// printf("printf %*3$d\n", 3, 5, 6, 7);
	// printf("\n");
	// ft_printf("ft_printf_star %.**#****d\n", 4, 5, 6, 7, 10, 25, 8, 7);
	// printf("printf_star %.**#****d\n", 4, 5, 6, 7, 10, 25, 8, 7);
	// printf("\n");
	// ft_printf("test cast h %hhd\n", 222);
	// printf("###$ printf test cast %hhd\n", 222);
	// ft_printf("test cast h %hd\n", 678912345);
	// ft_printf("test cast hh %hhd\n", 678912345);
	// printf("###$ printf test cast %hhd\n", 222);
	// ft_printf("test cast hh %hhd   \n", 222);
	// ft_printf("test cast -2147483648 to hhd %hhd \n", -2147483648);
	// ft_printf("test cast -2147483648 %d \n", -2147483648);
	// ft_printf("test cast bit %d \n", 1);
	// ft_printf("test cast bit %d \n", 0);
	// ft_printf("test cast bit %hhd \n", 256);
	// printf("printf cast bit %hhd \n", 256);
	// ft_printf("test cast bit %hd \n", 256000);
	// printf("printf cast bit %hd \n", 256000);
	// printf("\n");
	// ft_printf("test cast bit %d \n", 256000000);
	// ft_printf("test cast bit %d \n", 256000000);

	//printf("test itoa base = %s\n", ft_itoa_base(-2222, 8));
	//printf("###$ printf test cast %hhd\n", -2147483648);

	//End________________
	// ft_printf("Oldboy\n");
	// ft_printf("Oldboy Nemo\n");
	// ft_printf("Oldboy Nemo %d\n", 587);
	// ft_printf("Digit %d\n", 7);
	// ft_printf("Pokemon %s\n", "Bleu");
	// ft_printf("Sopalin 0x5BFB %#x\n", 23547);
	// ft_printf("Soja %s coccinelle %d\n", "perime", 53);
	// ft_printf("Egon %%%%%%%%%%\n");
	// ft_printf("Audio %c\n");
	// ft_printf("Bras %S\n");
	// ft_printf("Mouton %D\n", 87);
	// ft_printf("flag 0 false : %#010x\n", 847);
	// ft_printf("flag 0# : %#010x\n", 847);
	// ft_printf("flag 0# : %#010x_%#010x\n", 847, 412);
	// ft_printf("d flag 0# : %#010d\n", 235);
	// ft_printf("x flag 0# : %#010x\n", 235);
	// ft_printf("x flag 02 : %02x\n", 235);
	// ft_printf("x flag 0#02 : %#02x\n", 235);
	// ft_printf("x flag -0# : %-#010x\n", 235);
	// ft_printf("x flag -0# : %-#010x\n", 235);
	// printf("x flag -0# : %-#010x\n", 235);
	// ft_printf("x flag 0# : %#010x\n", 235);

	// printf("x flag printf -0# : %-#010x\n", 235);
	// printf("printf superiorite .*/.2$ %..*.3..*10$***.12d\n", 4, 87, 8, 12, 35, 17, 69, 57);
	//printf("d flag -0# : %-#010d\n", 235);
	//printf("d flag -0# : %-#010d\n", 235);
	// printf("flag 0 : %#0010x\n", 847);
	// printf("flag 0 : %#003x\n", 847);

	//printf("courgette %1  100   120  10d\n", 87);
	// printf("after ft_printf\n");
	// printf("% l   bordel\n");
	// printf("flag 0 : %#010x\n", 847);
	//
	// ft_printf("Sirop de mandarine%d\nfichtre %d bonnet %d\n", 132, 456, 789);
	// ft_printf("Multiple %d %d %d conversion\n");

	// ft_printf("Bilbo %%dkkkk\n");
	// printf("Bilbo %%dkkkk\n");
	// printf("\n");
	// ft_printf("L abeille coule %llllllbob\n");
	// ft_printf ("my  % % %d%\n", 42);
	// ft_printf ("my  % % %d%\n", 42);
	// printf("\n");
	// printf ("printf %%%d%", 42);
	// printf("\n");
	// printf("machin" "%d %d", 2, 2);
	// printf("##$  lapin  %%%d", 87);
	// printf("printf superiorite .*/.2$ %..*.3..*10$***.12d\n", 4, 87, 8, 12, 35, 17, 69, 57);

	// printf("printf %.6d\n", 874);
	// printf("printf %*d\n", 6,42,23);
	// printf("printf %*2$d\n", 10,5,23);
	//
	// printf("printf intmax_t %ju\n", 18446744073709551615, 12, 9);

	// printf("bob %.2s\n", "krevette"); // precision
	// printf("bob %2s\n", "krevette"); // precision
	//
	// printf("bob %5s\n", "krevette");
	// printf("bob %.*s\n", 2, "krevette");
	// printf("bob %*s\n", 40, "krevette");

	/*Ok donc la differene entre precision et largeur c est le ".", avec le point dans les str on crop, sans c est une taille minimum remplit de 0 ou d espace...
	*/

	// char happy[] = { 0xe2, 0x98, 0xba};
	// write(1, happy, 3);
	// char happy2[] = {227, 130, 166};
	// write(1, happy2, 3);
	// char happy3[] = {227, 131, 176};
	// write(1, happy3, 3);
	//char happy4[] = {240, 144, 166, 128};
	//write(1, happy4, 4);
	// char happy5[] = {225, 175, 164};
	// write(1, happy5, 3);
	// write(1, " ", 1);
	// char happy6[] = {226, 157, 132};
	// write(1, happy6, 3);
	// char happy7[] = {224, 182, 163};
	// write(1, " ", 1);
	// write(1, happy7, 3);
	// write(1, " ", 1);
	// write(1, " ", 1);
	// printf("%c%c\n", 0xC0 | (536 >> 6), 0x80 | (536 & 0x3f));
	// printf("%c\n", 0x80 | (536 & 0x3f));
	// printf("%c%c\n", 0xC0 | (536 >> 6), 0x80 | (536 & 0x3f));
	// printf("%c%c\n", 0x80 | (536 & 0x3f), 0xC0 | (536 >> 6));
	// printf("%c%c\n", 0xC0, 0x80);

	// printf("fuck %c%c\n", 0xC8, 0x18);
	// printf("i want you %C%C%C\n", 0xE2, 0xBB, 0x86);
	//printf("tac %c%c%c", 0xE2, 0x98); error
	// wchar_t test[3];
	//
	// test[0] = 0xE2;
	// test[1] = 0x82;
	// test[2] = 0xAC;


	//printf("Grim Fandango %S\n", 0xE2);
	// printf("%lc\n", (wint_t)536);
	// printf("\n");

	//
	// 0xC0 == 1100 0000;
	// 536 >> 6 == 0000 0000 1000;
	//
	// 0000 0000 1000   OR
	//      1100 0000
    // 0000 1100 1000
	//
	//
	// 0x80 == 1000 0000
	//
	// 0x3f == 0011 1111
	//
	// 0010 0001 1000 	AND
	// 0000 0011 1111
	// 0000 0001 1000
	//
	//
	// 0000 1100 1000 == 200  == 0xC8
	// 0000 0001 1000 == 24   == 0x18
	//
	//
	// 1100 0000
	// 1000 0000
	//
	// 0010 0001 1000
	// 0010 0001 1000
	//         xxxxxx
	// 0000 0000 1000
	// 0000 0000 1000
	//
	// a = 0xf == 1111;
	// b = a >> 3 == 0001;
	// a = b << 4 == 0001 0000;

	// if the lower bit is 0 its pair else if it is 1 its impair
	//
	// printf("%c\n", 'e');
	// printf("%C\n", 'e');


	//wchar_t z = 0xF0908D88;
	//printf("test = %C\n", z);
	// setlocale(LC_ALL, "");
	// printf("bite %C\n", L'é');
	// printf("bite %C%C%C\n", 0xE2, 0xBB, 0x86);
	// printf("bite %c%c\n", 0b11000010, 0b10101001);
	// printf("hook %C%C\n", 0xC2, 0xA9);
	//
	// wchar_t a;
	// wchar_t b;
	// wchar_t c;
	// wchar_t d;
	//
	// a = 0;
	// b = 0;
	// c = 0;
	// d = 0;
	//
	// a = 49833;
	// b = 580;
	// printf("castor %x\n", a);
	// printf("castor2 %i\n", x);
	//printf("%lu\n", sizeof(wchar_t));
	// ft_putchar(((b >> 6) & 0x1F) | 0xC0);
	// ft_putchar((b & 0x3F) | 0x80);
	//
	// int ko = 10052;
	// ft_putchar(' ');
	// ft_putchar(((ko >> 12) & 0xF) | 0xE0);
	// ft_putchar(((ko >> 6) & 0x3F) | 0x80);
	// ft_putchar((ko & 0x3F) | 0x80);
	// ft_putchar(' ');
	// b = a >> 8;
	// a = 49833;
	// c = a << 24;
	// d = c >> 24;


	// wchar_t	lune;

	// lune = L'©';

	// ft_putnbr(mal);
	// printf("ICI%C\n", mal);

	// write(1, &lune, 1);
	// write(1, &lune, 1);
	// write(1, &lune, 1);


	// lune = 0xC2;
	// write(1, &lune, 1);
	// lune = 0xA9;
	// write(1, &lune, 1);

	//printf("Cup %b\n", mordor);
	//mordor = 49833;
	// printf("%s\n", ft_itoa_base(mordor, 2));
	//mordor = mordor >> 8;
	//printf("Cup %x\n", mordor);

	//printf("%C" L'猫');

	// mordor = mordor >> 8;
	// printf("Cup %x\n", mordor);

	// printf("bob %.2s\n", "krevette"); // precision
	// printf("bob %2s\n", "krevette"); // precision
	//
	// printf("bob %5s\n", "krevette");
	// printf("bob %.*s\n", 2, "krevette");
	// printf("bob %*s\n", 40, "krevette");
	// printf("bob %2s\n", "krevette");
	// printf("bob %.2s\n", "krevette");
	// printf("bob %.2d\n", 12345678);
	// printf("bob %.2x\n", 0x12345678);
	// printf("bob %.2o\n", 01234567);
	// printf("bob %.20s\n", "krevette");
	// printf("bob %.20d\n", 12345678);
	// printf("bob %.20x\n", 0x12345678);
	// printf("bob %.20o\n", 01234567);
	// printf("bob %20s\n", "krevette");
	// printf("bob %20d\n", 12345678);
	// printf("bob %20x\n", 0x12345678);
	// printf("bob %20o\n", 01234567);
	// printf("bob %.o\n", 01234567);
	// printf("bob %.s\n", "krevette");
	//
	// printf("test = %#.10x\n", 3452);
	// printf("test = %#.10X\n", 3452);
	// printf("test = %#o\n", 5698);
	// printf("test = %#O\n", 5698);
	//
	//
	// printf("%  l%");
	// ft_printf("%%%");

	//conclusion : le pitch est a 0 si on a pas defini de nombre

	// printf("test : %e\n", 49995.46453);

	// double a = 23.9876;
	// float b = 42.564;

	// printf("test : %e\n", a);
	// printf("test : %d\n", (int)b);
	// printf("test : %hhd\n", b);
	// printf("test : %hhd\n", (char)b);

	// int zz = 0;
	// double db = DBL_MAX;

	// printf("DBL_MAX : %.320e\n", db);
	// printf("DBL_MIN : %.750e\n", DBL_MIN);
	// printf("FLT_MAX : %.50e\n", FLT_MAX);
	// printf("FLT_MIN : %.120e\n", FLT_MIN);

	// printf("test %e\n", db);
	// printf("test %d\n", db);
	// printf("test %d\n", db * 10);

	// printf("test %e\n", db/10);

	// double x = 4.98654321;
	// int y = 0;

	// y = (int)x;
	//
	// double o = DBL_MAX;
	//
	// o = o / 10000000000000000;
	// o = o*1000.0;
	//
	// printf("Test : %e\n", x*1);
	// printf("Test : %e\n", x*10);
	//ecriture scientifique e+01 nous donne le nombre de decplacement de la virgule vers la droite
	// printf("Test : %e\n", x/1);
	// printf("Test : %e\n", x/10);
	// x = x/10;
	// x = x/10;
	//et donc la e-01 vers la gauche

	// printf("Test : %e\n", x);
	//e == ecriture scientifique
	// printf("Test : %f\n", x);
	// x = x*10;
	// x = x*10;
	// x = x*1000000;
	// printf("Test : %f\n", x);
	//f = ecriture "normal"

	// x = 4.1;
	//
	// if ((x - (int)x) == 0)
	// 	printf("OK \n");
	// x = x*10;
	//
	// if ((x - (int)x) == 0)
	// 	printf("OK \n");

	//printf("%.120f\n", 4.2424242);
	//itoa_float(4.2424242);

	//
	// while (zz < 30)
	// {
	// 	printf("Test : %d\n", db);
	// 	db = db *10;
	// 	zz++;
	// }

	// double hy = DBL_MIN;
	//
	// orig test f :        2.542000000000170 530 256 58242404460906982421875000
	// bite test f : test : 2.542000000000259 348 098 552436567842960357666015625

	// if (0.000000000000000000000000000000000000000000 == 0.000000000000000000000000000000000)
		// ft_printf("HELLO\n");

	// printf("\n%f\n", 4042.0001);
	// printf("\n%e\n", 4042.0001);
	//ft_printf("test %e\n");
	// printf("\n");
	// printf("\n");
	//itoa_float(4242.4242);
	// ftoa(123456789.428745);
	// ftoa(0.428745);
	// ftoa(2.428745);

	// ftoa(0.254);
	// printf("%e\n", 0.254);

	//ftoa(10.254);
	// printf("%e\n", 10.254);

	// printf("\n");
	// printf("\n");
	//printf("orig test f :    %.100f\n", 25.42);
	// printf("orig test f :        %.2f\n", 5.5660);
	// printf("orig test f :        %.2f\n", 5.564);
	// printf("orig test f :        %.3f\n", 5.5396);
	// // printf("orig test f :        %.100lf\n", 25.424242424242424242424242424242);
	// ft_printf("bite test f : %f\n", 5.4242);
	//
	// printf("test              %.90f\n", 2.5433);
//						   2.543333333333333 445835933162015862762928009033203125000000000000000000000000000000000000000

	// ft_printf("test %f\n", 2.5433);

//2.543333333333333445835933162015862762928009033203125
//2.543333333545453545099235270754434168338775634765625
//2543300000000000051378798811890631969865728.000000
//254330000000000003264044860786387976192.000000
//2543299999999999957082584881949556342784.000000
	//
	// float zq=7.5;
	// int m,*p; p=&zq;
	// for (sizeof(int)*8-1;m>=0;m--)
	// 	printf("%d",(*p)>>m&1);

	//printf("test de merde : %.5e\n", 2.123546);

	// printf("test %.100f\n", 1.0001);
	// printf("test %.1000g\n", 1.000000001);
	// printf("test %.1000g\n", 1.1111111111111111111111111111111111111111111);
	// printf("test %.100f\n", 1.111111111111111111111111111111);
	// printf("test %.100f\n", 2.5555555555555);


//test 1.1000000000000000888178419700125232338905334472656250000000000000000000000000000000000000000000000000
//test 1.1000000000000000888178419700125232338905334472656250000000000000000000000000000000000000000000000000
//test 1.1000000000000000888178419700125232338905334472656250000000000000000000000000000000000000000000000000

	// printf("printf    %.60f\n", 1.005);
	// printf("printf    %.60f\n", 1.005);
	// ft_printf("ft_printf %f\n", 1.005);
	// ft_printf("ft_printf %f\n", 2.005);
	// float e = 1.005;
	// printf("printf %.60f\n", e);

	// double jui = DBL_MAX;
	// printf("DBL_MAX : %.320e\n", jui);
	// printf("\n");
	// printf("DBL_MIN : %.750e\n", DBL_MIN);

	// printf("\n\n");

	// printf("%.320f\n", -2.11111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111);

	// printf("\n\n");

	// double hm = -1.1111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111;
	// printf("%.320f\n", hm);

	// printf("\n\n");


	// ft_printf("ft_printf bite %f\n", DBL_MIN);
	// printf("ft_printf bite %f\n", DBL_MIN);

	// ft_printf("ft_printf bite %f\n", 2.04);

	//2.2250738585072014e-308

	// printf("test %.800f\n", 2.2250738585072014e-308);
	// ft_printf("test %f\n", 2.2250738585072014e-308);

	// printf("%.40f\n", 0.09e-10);
	// ft_printf("%f", 0.09e-10);

	// printf("test dollar %3$d\n", 40, 60, 5);
	// printf("test dollar %3$d %d\n", 40, 60, 5, 102);
	// printf("test dollar %1$d %1$d %1$d\n", 40, 60, 5, 102, 2);
	// printf("\n");
	// printf("test dollar %1**1$d\n", 40, 60, 5, 102, 2);



	return (0);
}
