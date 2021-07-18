#include "ft_printf.h" // your header file here
#include <limits.h>

void	resetColor() {
  printf("\033[0m");
}

int ft_add_checksum(int ml, int pl, int *checksum_ft, int *checksum_sys)
{
	static int test_id = 1;
	printf("\033[0;35m=== END TEST-ID: %d =============================\033[0m\n", test_id);
	if (ml != pl)
	{
		printf("\n\033[0;31m FAILED TEST NUMBER: %d\n", test_id);
		resetColor();
	}
	*checksum_ft += ml;
	*checksum_sys += pl;
	test_id++;
	if (test_id != 44)
	{
		printf("\033[0;35m=== START TEST-ID: %d =============================\033[0m\n", test_id);
		printf("\033[0;34m Running test: \033[0m\n");
	}
	else
		printf("\n\nTESTS FINISHED! Let's see how you did...\n");
}

int main()
{
	char *testpointer = NULL;
	char *emptystring = "";
	int int1 = 0;
	int int2 = 0;
	int int3 = -0;
	int int4 = 0;
	char *test3 = "TEST";
	char *test4 = 0;

	int c_ft = 0;
	int c_sys = 0;

	// Currently leaking print address (%p)
	// also leaking: %x
	int ml = 	 ft_printf("Teasdasdasdsdst! %%%%%%%%%%%%%%%% %% %d %d %s %%%%%%%% Das ist ziemlich cool! %% %% %% test mich %u %i %p %x %s %d %p %p \n", int1, int2, "TEST ME", int3, int4, testpointer, int4, NULL, 4, NULL, NULL);
	int pl =   		 printf("Teasdasdasdsdst! %%%%%%%%%%%%%%%% %% %d %d %s %%%%%%%% Das ist ziemlich cool! %% %% %% test mich %u %i %p %x %s %d %p %p \n", int1, int2, "TEST ME", int3, int4, testpointer, int4, NULL, 4, NULL, NULL);
	ft_add_checksum(ml, pl, &c_ft, &c_sys);
	int ml2 =    ft_printf("A %% AAA %d\n", 0);
	int pl2 =       printf("A %% AAA %d\n", 0);
	ft_add_checksum(ml2, pl2, &c_ft, &c_sys);
	int ml3 =    ft_printf("");
	int pl3 =    	printf("");
	ft_add_checksum(ml3, pl3, &c_ft, &c_sys);
	int ml4 =    ft_printf("aa\n");
	int pl4 =    	printf("aa\n");
	ft_add_checksum(ml4, pl4, &c_ft, &c_sys);
	int ml5 =    ft_printf("%%\n");
	int pl5 =       printf("%%\n");
	ft_add_checksum(ml5, pl5, &c_ft, &c_sys);
	int ml6 =    ft_printf("%% A %% A %% \n");
	int pl6 =       printf("%% A %% A %% \n");
	ft_add_checksum(ml6, pl6, &c_ft, &c_sys);
	int ml7 =    ft_printf("!!%d %%\n", -2147483647);
	int pl7 =       printf("!!%d %%\n", -2147483647);
	ft_add_checksum(ml7, pl7
	, &c_ft, &c_sys);
	int ml8 =    ft_printf("!!%d %% %s \n", -123123, emptystring);
	int pl8 =       printf("!!%d %% %s \n", -123123, emptystring);
	ft_add_checksum(ml8, pl8
	, &c_ft, &c_sys);
	int ml9 =    ft_printf("!!%d %% %s %u %p \n", -123123, emptystring, (unsigned int) 4294967295, emptystring);
	int pl9 =       printf("!!%d %% %s %u %p \n", -123123, emptystring, (unsigned int) 4294967295, emptystring);
	ft_add_checksum(ml9, pl9
	, &c_ft, &c_sys);
	int ml10 =    ft_printf("%d\n", 0);
	int pl10 =       printf("%d\n", 0);
	ft_add_checksum(ml10, pl10
	, &c_ft, &c_sys);
	int ml11 =    ft_printf("%d\n", -111);
	int pl11 =       printf("%d\n", -111);
	ft_add_checksum(ml11, pl11
	, &c_ft, &c_sys);
	int ml12 =    ft_printf("%u\n", -123123);
	int pl12 =       printf("%u\n", -123123);
	ft_add_checksum(ml12, pl12
	, &c_ft, &c_sys);
	int ml13 =    ft_printf("%u\n", 221474836412318);
	int pl13 =       printf("%u\n", 221474836412318);
	ft_add_checksum(ml13, pl13
	, &c_ft, &c_sys);
	int ml14 =    ft_printf("%u\n", NULL);
	int pl14 =       printf("%u\n", NULL);
	ft_add_checksum(ml14, pl14
	, &c_ft, &c_sys);
	int ml15 =    ft_printf("%x\n", 0x0);
	int pl15 =       printf("%x\n", 0x0);
	ft_add_checksum(ml15, pl15
	, &c_ft, &c_sys);
	int ml16 =    ft_printf("%X\n", 0x0);
	int pl16 =       printf("%X\n", 0x0);
	ft_add_checksum(ml16, pl16
	, &c_ft, &c_sys);
	int ml17 =    ft_printf("%p\n", 0x0);
	int pl17 =       printf("%p\n", 0x0);
	ft_add_checksum(ml17, pl17
	, &c_ft, &c_sys);
	int ml18 =    ft_printf("%dp\n", 0);
	int pl18 =       printf("%dp\n", 0);
	ft_add_checksum(ml18, pl18
	, &c_ft, &c_sys);
	int ml19 =    ft_printf("%d\n", INT_MAX	);
	int pl19 =       printf("%d\n", INT_MAX	);
	ft_add_checksum(ml19, pl19
	, &c_ft, &c_sys);
	int ml20 =    ft_printf("%d\n", INT_MIN	);
	int pl20 =       printf("%d\n", INT_MIN	);
	ft_add_checksum(ml20, pl20
	, &c_ft, &c_sys);
	int ml21 =    ft_printf("%p\n", 18446744073709551615	);
	int pl21 =       printf("%p\n", 18446744073709551615	);
	ft_add_checksum(ml21, pl21
	, &c_ft, &c_sys);
	int ml22 =    ft_printf("%x\n", -1844674407	);
	int pl22 =       printf("%x\n", -1844674407	);
	ft_add_checksum(ml22, pl22
	, &c_ft, &c_sys);
	int ml23 =    ft_printf("%x\n", 0	);
	int pl23 =       printf("%x\n", 0	);
	ft_add_checksum(ml23, pl23
	, &c_ft, &c_sys);
	int ml24 =    ft_printf("%%p\n", &emptystring	);
	int pl24 =       printf("%%p\n", &emptystring	);
	ft_add_checksum(ml24, pl24
	, &c_ft, &c_sys);
	int ml25 =    ft_printf("%%%%%%%%\n");
	int pl25 =       printf("%%%%%%%%\n");
	ft_add_checksum(ml25, pl25
	, &c_ft, &c_sys);
	int ml26 =    ft_printf("%u\n", LONG_MAX	);
	int pl26 =       printf("%u\n", LONG_MAX	);
	ft_add_checksum(ml26, pl26
	, &c_ft, &c_sys);
	int ml27 =    ft_printf("%u\n", LONG_MIN	);
	int pl27 =       printf("%u\n", LONG_MIN	);
	ft_add_checksum(ml27, pl27
	, &c_ft, &c_sys);
	int ml28 =    ft_printf("%p\n", LONG_MAX	);
	int pl28 =       printf("%p\n", LONG_MAX	);
	ft_add_checksum(ml28, pl28
	, &c_ft, &c_sys);
	int ml29 =    ft_printf("%p\n", LONG_MIN	);
	int pl29 =       printf("%p\n", LONG_MIN	);
	ft_add_checksum(ml29, pl29
	, &c_ft, &c_sys);
	int ml30 =    ft_printf("%X\n", LONG_MAX	);
	int pl30 =       printf("%X\n", LONG_MAX	);
	ft_add_checksum(ml30, pl30
	, &c_ft, &c_sys);
	int ml31 =    ft_printf("%x\n", LONG_MAX	);
	int pl31 =       printf("%x\n", LONG_MAX	);
	ft_add_checksum(ml31, pl31
	, &c_ft, &c_sys);
	int ml32 =    ft_printf("%x\n", LONG_MAX	);
	int pl32 =       printf("%x\n", LONG_MAX	);
	ft_add_checksum(ml32, pl32
	, &c_ft, &c_sys);
	int ml33 =    ft_printf("%%d\n", INT_MAX	);
	int pl33 =       printf("%%d\n", INT_MAX	);
	ft_add_checksum(ml33, pl33
	, &c_ft, &c_sys);
	int ml34 =    ft_printf("%%d\n", INT_MIN	);
	int pl34 =       printf("%%d\n", INT_MIN	);
	ft_add_checksum(ml34, pl34
	, &c_ft, &c_sys);
	int ml35 =    ft_printf("%x\n", INT_MIN	);
	int pl35 =       printf("%x\n", INT_MIN	);
	ft_add_checksum(ml35, pl35
	, &c_ft, &c_sys);
	int ml36 =    ft_printf("%x %d %d %d %%d \n", INT_MAX, INT_MIN, 0, -1	);
	int pl36 =       printf("%x %d %d %d %%d \n", INT_MAX, INT_MIN, 0, -1	);
	ft_add_checksum(ml36, pl36
	, &c_ft, &c_sys);
	int ml37 =    ft_printf("%x %d %d %d %%d %s\n", INT_MAX, INT_MIN, 0, -1, "HELLO!");
	int pl37 =       printf("%x %d %d %d %%d %s\n", INT_MAX, INT_MIN, 0, -1, "HELLO!");
	ft_add_checksum(ml37, pl37
	, &c_ft, &c_sys);
	int ml38 =    ft_printf("%x %%%% %d %u %%d %s\n", 4, 4, 0, "HELLO!");
	int pl38 =       printf("%x %%%% %d %u %%d %s\n", 4, 4, 0, "HELLO!");
	ft_add_checksum(ml38, pl38
	, &c_ft, &c_sys);
	int ml39 =    ft_printf("%x %u %%%%%%%%%%%%%%%% %%d %s\n", LONG_MAX, LONG_MAX, "HI!");
	int pl39 =       printf("%x %u %%%%%%%%%%%%%%%% %%d %s\n", LONG_MAX, LONG_MAX, "HI!");
	ft_add_checksum(ml39, pl39
	, &c_ft, &c_sys);
	int ml40 =    ft_printf("%x %d %d %d %%d %s\n", LONG_MAX, INT_MIN, 0, -1, "HELLO!");
	int pl40 =       printf("%x %d %d %d %%d %s\n", LONG_MAX, INT_MIN, 0, -1, "HELLO!");
	ft_add_checksum(ml40, pl40
	, &c_ft, &c_sys);
	int ml41 =    ft_printf("%x %d %d %d %%d %s\n", NULL, INT_MIN, 0, -1, "HELLO!");
	int pl41 =       printf("%x %d %d %d %%d %s\n", NULL, INT_MIN, 0, -1, "HELLO!");
	ft_add_checksum(ml41, pl41
	, &c_ft, &c_sys);
	int ml42 =    ft_printf("%%%% %%%%\n");
	int pl42 =       printf("%%%% %%%%\n");
	ft_add_checksum(ml42, pl42
	, &c_ft, &c_sys);
	int ml43 =    ft_printf("%%%% %%%% %d %%%% %%%% %%%%d\n", 1, 2);
	int pl43 =       printf("%%%% %%%% %d %%%% %%%% %%%%d\n", 1, 2);
	ft_add_checksum(ml43, pl43
	, &c_ft, &c_sys);
	printf("================================================================\n");
	if (c_sys == c_ft)
		 printf("\033[0;32m ALL 44 TEST PASSED! The mandatory part should be correct.");
	else
		printf("\033[0;31m FAILED SOME TESTS. \n Scroll up and look for the output. Sorry for the stupid formatted output.");

	resetColor();
	printf("\n\n");
	// fscanf(stdin, "c"); // uncomment this and use `ps aux | grep a.out` (your executable name) and then `leaks executable-pid` to find leaks in the program!
	return 0;
}
