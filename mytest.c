/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mytest.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjimpei <yjimpei@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/14 11:03:49 by yjimpei           #+#    #+#             */
/*   Updated: 2021/06/06 11:38:25 by yjimpei          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <limits.h>
int	ft_printf(const char *format, ...);

void	test(int (*f)(const char*, ...))
{
	f("hoge");
	printf("\n");
	f("%10s", "xxxxxx");
	printf("\n");
	f("%-10s", "xxxxxx");
	printf("\n");
	f("%c", 'z');
	printf("\n");
	f("%c", '\300');
	printf("\n");
	f("%x", "xxxxxx");
	printf("\n");
	f("%X", "xxxxxx");
	printf("\n");
	f("%030d", INT_MIN);
	printf("\n");
	f("%-030d", INT_MIN);
	printf("\n");
	f("%030d", LONG_MAX);
	printf("\n");
	f("%030d", LONG_MIN);
	printf("\n");
	f("%030p", LONG_MIN);
	printf("\n");
	f("%%");
	printf("\n");
	f("%rrrrrr");
	printf("\n");
	f("%%%%%r");
	printf("\n");
	f("%.10d", -300);
	printf("\n");
	f("%010d", -300);
	printf("\n");
	f("%10d", -300);
	printf("\n");
	f("%.30d", -30000000);
	printf("\n");
	f("%.30i", -300000.3);
	printf("\n");
	f("%.30d", -300000.3);
	printf("\n");
	f("%u", 300000);
	printf("\n");
}

void	test_no(int (*f)(const char*, ...))
{
	f("abcdefg\n");
	f("xxx		xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx\n");
	f("\n");
	f("    fhdsak\300bahsd!@#*&\n");
}

void	test_vali(int (*f)(const char*, ...))
{
	f("aa=%3d\n", 2);
	f("aa=%03d\n", 2);
	f("aa=%0-3d\n", 2);
	f("aa=%-03d\n", 2);
	f("aa=%.3d\n", 2);
	f("aa=%*d\n", 9);
	f("aa=%3s\n", "xxxxxxx");
	f("aa=%-9d\n", 23);
	f("aa=%9d\n", 23);
	f("aa=%d\n", 23);
	f("aa=%3s\n", "xxxxxxx");
	f("aa=%.-9d\n", 23);
	f("aa=%.9d\n", 23);
	f("aa=%.d\n", 23);
	f("aa=%.07X\n", 2642387);
	f("aa=%.-07x\n", 2642387);
}

void	test_s(int (*f)(const char*, ...))
{
	f("s=%s\n", "hoge");
	f("s=%.10s\n", "hoge");
	f("s=%10s\n", "hoge");
	f("s=%010s\n", "hoge");
	f("s=%0.10s\n", "hoge");
	f("s=%-0.10s\n", "hoge");
	f("s=%0-.10s\n", "hoge");
	f("s=%000-.10s\n", "hoge");
	f("s=%000-.10s///\n", "hoge");
	f("s=%000-.-10s///\n", "hoge");
	f("s=%000-.1-0s///\n", "hoge");
	f("s=%...000-.10s///\n", "hoge");
	f("s=%.---..000-.10s///\n", "hoge");
	f("s=%.0---..000-.10s///\n", "hoge");
	f("s=%0s///\n", "hoge");
	f("s=%.0s///\n", "hoge");
	f("s=%010.1s///\n", "hoge");
	f("s=%10s,s2=%s\n", "hoge", "geho");
	f("s2=%.2s\n", "hoge");
	f("s2=%.4s\n", "hoge");
	f("s2=%.5s\n", "hoge");
	f("xx=%.3s\n", "hogehoge");
	f("xx=%-.3s\n", "hogehoge");
	f("xx=%-.1s\n", "hogehoge");
	f("s=%-.2s///\n", "hoge");
	f("xx=%-.9s\n", "hogehoge");
	f("xx=%-.30s\n", "hogehoge");
	f("s=%-010.1s///\n", "hoge");
	f("s=%010-.0s///\n", "hoge");
	f("s=%010.-0s///\n", "hoge");
	f("s=%010s,s2=%-4.0s\n", "hoge", "geho");
	f("s2=%-4.0s\n", "hoge");
	f("s2=%-9.0s\n", "hoge");
	f("s2=%-5.1s\n", "hoge");
	f("s2=%-2.0s\n", "hoge");
	f("s2=%-2.1s\n", "hoge");
	f("s2=%2.0s\n", "hoge");
	f("s2=%2.1s\n", "hoge");
	f("s2=%9.0s\n", "hoge");
	f("s2=%4.0s\n", "hoge");
	f("s2=%5.1s\n", "hoge");
	f("s2=%5.3s\n", "hoge");
	f("s2=%5  .4s,s1=%020--6-68--.-.....s\n", "hoge", "xxxxxxx   x");
	f("s2=%s\n", NULL);
	f("s2\n");
}

void	test_as(int (*f)(const char*, ...))
{
	f("xx=%*23s\n", 1003, "hogehoge");
	f("xx=%0*23s\n", 1003, "hogehoge");
	f("xx=%*s\n", 30, "hogehoge");
	f("xx=%.*s\n", 30, "hogehoge");
	f("xx=%-.*s\n", 3, "hogehoge");
	f("xx=%010*.*s\n",10, 3, "hogehoge");
	f("%-0.000000sxx=%01-0*.*s\n","hoge",10, 3, "hogehoge");
	f("%30s%20s\n","hoge", "hogehoge");
}

void	test_c(int (*f)(const char*, ...))
{
	f("c=%c\n", 6);
	f("c=%c\n", 30);
	f("c=%c\n", 50);
	f("c=%c\n", 20);
	f("c=%c\n", 0);
	f("c=%c\n", -3);
	f("c=%c\n", 900);
	f("c=%c\n", 100000);
	f("c=%c\n", 'h');
	f("c=%10-c\n", 'h');
	f("c=%0c\n", 'h');
	f("c=%030c\n", 'h');
	f("c=%.c\n", 'h');
	f("c=%.0c\n", 'h');

	f("c=%10-.4c\n", 'h');
	f("c=%-10-.4c\n", 'h');
	f("c=%0.-4c\n", 'h');
	f("c=%0-.4c\n", 'h');
	f("c=%.0c\n", 'h');
	f("c=%0c\n", 'h');
	f("c=%1c\n", 'h');
	f("c=%.1c\n", 'h');
	f("c=%-.0c\n", 'h');
	f("c=%-0c\n", 'h');
	f("c=%-1c\n", 'h');
	f("c=%-.1c\n", 'h');
	f("c=%-.2c\n", 'h');
	f("c=%-.3c\n", 'h');
	f("c=%-4c\n", 'h');
	f("c=%-5c\n", 'h');
	f("c=%-.2c\n", 'h');
	f("c=%030-2c\n", 'h');
	f("c=%002c\n", 'h');
	f("c=%-10-.4c%3c\n", 'h', 'x');
	f("c=%4c%8c\n", 'h', 'x');
	f("c=%--...--4c%08c\n", 'h', 'x');
	f("c=%-*-...--4c%08c\n",15, 'h', 'x');
}

void	test_sc(int (*f)(const char*, ...))
{
	f("s=%s,c=%c\n", "hogehoge", 'x');
	f("%.s%030c\n", "hogehoge", 'x');
}

void	test_d(int (*f)(const char*, ...))
{
	f("d=%d\n", 0);
	f("d=%d\n", INT_MIN);
	f("d=%d\n", INT_MAX);
	f("d=%d\n", 34980);
	f("d=%d\n", -237480);
	f("d=%d\n", LONG_MIN);
	f("d=%d\n", LONG_MAX);
	f("d=%.d\n", INT_MAX);
	f("d=%3.d\n", INT_MIN);
	f("d=%.1d\n", INT_MIN);
	f("d=%.5d\n", INT_MIN);
	f("d=%-.d\n", INT_MIN);
	f("d=%-3.d\n", INT_MIN);
	f("d=%-.1d\n", INT_MIN);
	f("d=%-.5d\n", INT_MIN);
	f("d=%.-d\n", INT_MIN);
	f("d=%3.-d\n", INT_MIN);
	f("d=%.-1d\n", INT_MIN);
	f("d=%.-5d\n", INT_MIN);
	f("d=%.1-d\n", INT_MIN);
	f("d=%.5-d\n", INT_MIN);
	f("d=%-.5d\n", INT_MIN);
	f("d=%.-5d\n", INT_MIN);
	f("d=%.14d\n", INT_MIN);
	f("d=%.14d\n", INT_MIN);
	f("d=%-.14d\n", INT_MIN);

	f("d=%-.d\n", INT_MIN);
	f("d=%0-.d\n", INT_MIN);
	f("d=%13.d\n", INT_MIN);
	f("d=%-13.d\n", INT_MIN);

	f("d=%0-13.d\n", INT_MIN);
	f("d=%13.1d\n", INT_MIN);
	f("d=%-13.1d\n", INT_MIN);
	f("d=%0-13.1d\n", INT_MIN);
	f("d=%13.9d\n", INT_MIN);
	f("d=%-13.9d\n", INT_MIN);
	f("d=%0-13.9d\n", INT_MIN);
	f("d=%13.15d\n", INT_MIN);
	f("d=%-13.15d\n", INT_MIN);
	f("d=%0-13.15d\n", INT_MIN);
	f("d=%-.14d\n", INT_MIN);
	f("d=%0-.14d\n", INT_MIN);
	f("d=%3.d\n", INT_MIN);
	f("d=%-3.d\n", INT_MIN);
	f("d=%0-3.d\n", INT_MIN);
	f("d=%.2d\n", INT_MIN);
	f("d=%-.2d\n", INT_MIN);
	f("d=%0-.2d\n", INT_MIN);
	f("d=%.14d\n", INT_MIN);
	f("d=%.0d\n", INT_MIN);
	f("d=%-.0d\n", INT_MIN);
	f("d=%0-.0d\n", INT_MIN);
}

void	test_i(int (*f)(const char*, ...))
{
	f("i=%.0i\n", 0);
	f("i=%0.0i\n", 0);
	f("i=%-0.0i\n", 0);
	f("i=%i\n", 0);
	f("i=%i\n", INT_MIN);
	f("i=%i\n", INT_MAX);
	f("i=%i\n", 34980);
	f("i=%i\n", -237480);
	f("i=%i\n", LONG_MIN);
	f("i=%i\n", LONG_MAX);
	f("i=%.i\n", INT_MAX);
	f("i=%3.i\n", INT_MIN);
	f("i=%.1i\n", INT_MIN);
	f("i=%.5i\n", INT_MIN);
	f("i=%-.i\n", INT_MIN);
	f("i=%-3.i\n", INT_MIN);
	f("i=%-.1i\n", INT_MIN);
	f("i=%-.5i\n", INT_MIN);
	f("i=%.-i\n", INT_MIN);
	f("i=%3.-i\n", INT_MIN);
	f("i=%.-1i\n", INT_MIN);
	f("i=%.-5i\n", INT_MIN);
	f("i=%.1-i\n", INT_MIN);
	f("i=%.5-i\n", INT_MIN);
	f("i=%-.5i\n", INT_MIN);
	f("i=%.-5i\n", INT_MIN);
	f("i=%.14i\n", INT_MIN);
	f("i=%.14i\n", INT_MIN);
	f("i=%-.14i\n", INT_MIN);
	f("i=%-.i\n", INT_MIN);
	f("i=%0-.i\n", INT_MIN);
	f("i=%13.i\n", INT_MIN);
	f("i=%-13.i\n", INT_MIN);
	f("i=%0-13.i\n", INT_MIN);
	f("i=%13.1i\n", INT_MIN);
	f("i=%-13.1i\n", INT_MIN);
	f("i=%0-13.1i\n", INT_MIN);
	f("i=%13.9i\n", INT_MIN);
	f("i=%-13.9i\n", INT_MIN);
	f("i=%0-13.9i\n", INT_MIN);
	f("i=%13.15i\n", INT_MIN);
	f("i=%-13.15i\n", INT_MIN);
	f("i=%0-13.15i\n", INT_MIN);
	f("i=%-.14i\n", INT_MIN);
	f("i=%0-.14i\n", INT_MIN);
	f("i=%3.i\n", INT_MIN);
	f("i=%-3.i\n", INT_MIN);
	f("i=%0-3.i\n", INT_MIN);
	f("i=%.2i\n", INT_MIN);
	f("i=%-.2i\n", INT_MIN);
	f("i=%0-.2i\n", INT_MIN);
	f("i=%.14i\n", INT_MIN);
	f("i=%.0i\n", INT_MIN);
	f("i=%-.0i\n", INT_MIN);
	f("i=%0-.0i\n", INT_MIN);


	f("i=%-2.7i\n", -222367);
	f("i=%-9.7i\n", -222367);
	f("i=%-.5i\n", -2367);
	f("i=%.5-i\n", -2367);
	f("i=%-.5i\n", -2367);
	f("i=%.5i\n", -2367);
	f("i=%-.5i\n", 2367);
	f("i=%.5-i\n", 2367);
	f("i=%-.5i\n", 2367);
	f("i=%.5i\n", 23671);
	f("i=%-.5i\n", 23671);
	f("i=%.5-i\n", 23671);
	f("i=%-.5i\n", 23671);
	f("i=%.5i\n", 23671);


	f("i=%3.i\n", -2367);
	f("i=%.1i\n", -2367);
	f("i=%-.i\n", -2367);
	f("i=%-3.i\n", -2367);
	f("i=%-.1i\n", -2367);
	f("i=%.-i\n", -2367);
	f("i=%3.-i\n", -2367);
	f("i=%.-1i\n", -2367);
	f("i=%.-5i\n", -2367);
	f("i=%.1-i\n", -2367);
	f("i=%.-5i\n", -2367);
	f("i=%.14i\n", -2367);
	f("i=%.14i\n", -2367);
	f("i=%-.14i\n", -2367);
	f("i=%-.i\n", -2367);
	f("i=%0-.i\n", -2367);
	f("i=%13.i\n", -2367);
	f("i=%-13.i\n", -2367);

	f("i=%0-13.i\n", -2367);
	f("i=%13.1i\n", -2367);
	f("i=%-13.1i\n", -2367);
	f("i=%0-13.1i\n", -2367);
	f("i=%013.9i\n", 2367);


	f("i=%013.9i\n", -22367);
	f("i=%013.9i\n", -2367);
	f("i=%-13.9i\n", -2367);
	f("i=%13.9i\n", -2367);
	f("i=%0-13.9i\n", -2367);
	f("i=%13.15i\n", -2367);
	f("i=%-13.15i\n", -2367);
	f("i=%0-13.15i\n", -2367);
	f("i=%-.14i\n", -2367);
	f("i=%0-.14i\n", -2367);
	f("i=%3.i\n", -2367);
	f("i=%-3.i\n", -2367);
	f("i=%0-3.i\n", -2367);
	f("i=%3.i\n", 9283);
	f("i=%.1i\n", 9283);
	f("i=%.5i\n", 9283);
	f("i=%-.i\n", 9283);
	f("i=%-3.i\n", 9283);
	f("i=%-.1i\n", 9283);
	f("i=%-.5i\n", 9283);
	f("i=%.-i\n", 9283);
	f("i=%3.-i\n", 9283);
	f("i=%.-1i\n", 9283);
	f("i=%.-5i\n", 9283);
	f("i=%-6.8i\n", 213);
	f("i=%-10.8i\n", 213);
	f("i=%6.8i\n", 213);
	f("i=%10.8i\n", 213);
	f("i=%3.3i\n", 21);
	f("i=%6.3i\n", 223456);
	f("i=%06.02i\n", 213);
	f("i=%6.1i\n", 213);
	f("i=%6.0i\n", 213);
	f("i=%6.3i\n", 2133456);
	f("i=%3.3i\n", 2133456);
	f("i=%3.3i\n", 213);
	f("----\n");
	f("i=%-6.3i\n", 223456);
	f("i=%-06.02i\n", 213);
	f("i=%-6.1i\n", 213);
	f("i=%-6.0i\n", 213);
	f("i=%-6.3i\n", 2133456);
	f("i=%-3.3i\n", 2133456);
	f("i=%-3.3i\n", 213);
	f("i=%.1-i\n", 9283);
	f("i=%.5-i\n", 9283);
	f("i=%-.5i\n", 9283);
	f("i=%.-5i\n", 9283);
	f("i=%.14i\n", 9283);
	f("i=%.14i\n", 9283);
	f("i=%-.14i\n", 9283);
	f("i=%-.i\n", 9283);
	f("i=%0-.i\n", 9283);
	f("i=%13.i\n", 9283);
	f("i=%-13.i\n", 9283);
	f("i=%0-13.i\n", 9283);
	f("i=%13.1i\n", 9283);
	f("i=%-13.1i\n", 9283);
	f("i=%0-13.1i\n", 9283);
	f("i=%13.9i\n", 9283);
	f("i=%-13.9i\n", 9283);
	f("i=%0-13.9i\n", 9283);
	f("i=%13.15i\n", 9283);
	f("i=%-13.15i\n", 9283);
	f("i=%0-13.15i\n", 9283);
	f("i=%-.14i\n", 9283);
	f("i=%0-.14i\n", 9283);
	f("i=%3.i\n", 9283);
	f("i=%-3.i\n", 9283);
	f("i=%0-3.i\n", 9283);
	f("i=%.2i\n", 9283);
}

void	test_u(int (*f)(const char*, ...))
{
	f("u=%u\n", 0);
	f("u=%u\n", 4294967295);
	f("u=%u\n", 4294967296);
	f("u=%u\n", 4294967297);
	f("u=%u\n", 4294967298);
	f("u=%u\n", 1);
	f("u=%u\n", 10);
	f("u=%u\n", -10);
	f("u=%u\n", INT_MAX);
	f("u=%u\n", 2147483647);
	f("u=%u\n", 2147483648);
	f("u=%u\n", LONG_MAX);
	f("u=%u\n", INT_MIN);
	f("u=%u\n", LONG_MIN);
}

void	tester(int (*f)(const char*, ...))
{
	f("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",(char)128,(char)129,(char)130,(char)131,(char)132,(char)133,(char)134,(char)135,(char)136,(char)137,(char)138,(char)139,(char)140,(char)141,(char)142,(char)143,(char)144,(char)145,(char)146,(char)147,(char)148,(char)149,(char)150,(char)151,(char)152,(char)153,(char)154,(char)155,(char)156,(char)157,(char)158,(char)159,(char)160,(char)161,(char)162,(char)163,(char)164,(char)165,(char)166,(char)167,(char)168,(char)169,(char)170,(char)171,(char)172,(char)173,(char)174,(char)175,(char)176,(char)177,(char)178,(char)179,(char)180,(char)181,(char)182,(char)183,(char)184,(char)185,(char)186,(char)187,(char)188,(char)189,(char)190,(char)191,(char)192,(char)193,(char)194,(char)195,(char)196,(char)197,(char)198,(char)199,(char)200,(char)201,(char)202,(char)203,(char)204,(char)205,(char)206,(char)207,(char)208,(char)209,(char)210,(char)211,(char)212,(char)213,(char)214,(char)215,(char)216,(char)217,(char)218,(char)219,(char)220,(char)221,(char)222,(char)223,(char)224,(char)225,(char)226,(char)227,(char)228,(char)229,(char)230,(char)231,(char)232,(char)233,(char)234,(char)235,(char)236,(char)237,(char)238,(char)239,(char)240,(char)241,(char)242,(char)243,(char)244,(char)245,(char)246,(char)247,(char)248,(char)249,(char)250,(char)251,(char)252,(char)253,(char)254,(char)255);
	f("%c", (char)255);
	f("aa%c", 30);
	f("c%s", "ddd");
	f("aa%c\n", 30);
}

void	test_d2(int (*f)(const char*, ...))
{
	f("%5.0d", 0);
	f("\n");
	f("%5.d", 0);
	f("\n");
	f("%-5.0d", 0);
	f("\n");
	f("%-5.d", 0);
}

void	test_s2(int (*f)(const char*, ...))
{
	f("%7.5s", "yolo");
	f("\n");
	f("%-7.5s", "yolo");
	f("\n");
	f("%7.7s%7.7s", "hello", "world");
	f("\n");
	f("%2.9s\n", "hello");
	f("%7.3s\n", "hello");
	f("%07.3s\n", "hello");
	f("%-07.3s\n", "hello");
	f("%3.s\n", "hello");
	f("%7.7s\n", "hello");
}

void	test_p2(int (*f)(const char*, ...))
{
	f("\n");
	f("%3p", 0);
	f("\n");
	f("%.p", NULL);
	f("\n");
	f("%.1p", NULL);
	f("\n");
	f("%.1p", 0);
	f("\n");
	f("%.p", 15);
	f("\n");
	f("%.p", 15);
	f("\n");
	f("%p", 15);
	f("\n");
	f("%10p", 15);
	f("\n");
	f("%10p", 16);
	f("\n");
	f("%10p", 8);
	f("\n");
	f("%10p", 0);
	f("\n");
	f("%p", NULL);
	f("\n");
	f("%p", 0);
	f("\n");
	f("%10p", NULL);
	f("\n");
	f("%10p", 0);
	f("\n");
	f("\n");
	f("%9.2p", NULL);
	f("\n");
	f("%9.2p", 0);
	f("\n");
	f("%9.2p", 12);
	f("\n");
	f("%9.2p", 15);
	f("\n");
	f("%9.2p", 16);
	f("\n");
	f("%9.2p", 17);
	f("\n");
	f("%9.2p", 1234);
	f("\n");
	f("%2.9p", 1234);
	f("\n");
	f("%.5p", 0);
}

void	test_crash(int (*f)(const char*, ...))
{
	f("%% *.5i 42 == |%*.5i|", 4, 42);
	f("\n");
	f("%% *.5i 42 == |%*.5i|", 4, 42);
	f("\n");
	f("%010.5s", "123456");
	f("\n");
	f("%5");
	f("\n");
	f("%05");
	f("\n");
	f("%-05");
	f("\n");
	f("%-5");
	f("\n");
	f("%%d 	 == |%d|", 0x09);
	f("\n");
	f("%-*s", 32, "abc");
	f("\n");
	f("%-*.*s", -7, -3, "yolo");
	f("\n");
	f("%--7.-3s", "yolo");
	f("\n");
	f("%.*i", -6, -3);
	f("\n");
	f("%.-6i", -3);
	f("\n");
	f("%0*i", -7, -54);
	f("\n");
	f("%*i", -14, 94827);
	f("\n");
	f("%*s", -32, "abc");
	f("\n");
	f("%%*i 42 == |%*i|", 2, 42);
	f("\n");
	f("%%*i 42 == |%*i|", 3, 42);
	f("\n");
}

void	new(int (*f)(const char*, ...))
{
	//f("%1c", 'a');
	//f("\n");
	//f("%1.1c", 'a');
	//f("\n");
	//f("%1.c", 'a');
	//f("\n");
	//f("%5.c", 'a');
	//f("%8.5d", 1020);
	//f("\n");
	//f("%20.5d", 1020);
	//f("\n");
	//f("%-20.5d", -1020);
	//f("\n");
	//f("%20.5d", -1020);
	//f("\n");
	//f("%20.5i", -1024);
	//f("\n");
	//f("%020.5d", -1024);
	//f("\n");
	//f("%020.5i", -1024);
	//f("\n");
	//f("%-*.156x%0033.100u%0.104i%-4.150x%-90.%" ,28,4190048377u,3783020883u,-1750158056,3765069756u);
	//f("\n");
	//f("\n");
	//f("-->|%16.p|<-- ", 0);
	//f("\n");
	//f("-->|%-2.p|<-- ", 0);
	//f("\n");
	//f("-->|%-16.p|<-- ", 0);
	//f("\n");
	//f("-->|%-16.p|<-- ", NULL);
	//f("\n");
	//f("%0*.*i", 2, 0, 8);
	//f("\n");
	//f("%02.0i", 8);
	//f("\n");
	//f("%02.i", 8);
	//f("\n");
	//f("%02.1i", 8);
	//f("\n");
	//f("%2.1i", 8);
	//f("%0*.*d", 4, 0, 12);
	//f("\n");
	//f("%04.0d", 12);
	//f("\n");
	f("%0*.*u", 2, 0, 8);
	f("\n");
	f("%02.0u", 8);
	f("\n");
	f("%0*.*u", 3, 0, 8);
	f("\n");
	f("%03.0u", 8);
	f("\n");
	f("%0*.*d", 4, 0, -12);
	f("\n");
}

int	ft_printf(const char *format, ...);

int main(int argc, char **argv)
{
	int	(*p1)(const char*, ...);
	int	(*p2)(const char*, ...);

	p1 = printf;
	p2 = ft_printf;
	if (argc != 2)
		return (0);
	if (argv[1][0] == '1')
	{
		//test_crash(p1);
		//test_s(p1);
		//test_as(p1);
		//test_c(p1);
		//test_sc(p1);
		//test_i(p1);
		//test_u(p1);
		//tester(p1);
		test_d2(p1);
		//test_s2(p1);
		//test_p2(p1);
		//new(p1);
	}
	else if (argv[1][0] == '2')
	{
		//test_crash(p2);
		//test_s(p2);
		//test_as(p2);
		//test_c(p2);
		//test_sc(p2);
		//test_i(p2);
		//test_u(p2);
		//tester(p2);
		test_d2(p2);
		//test_s2(p2);
		//test_p2(p1);
		//new(p2);
	}
	//system("leaks tester.a");
	return (0);
}
