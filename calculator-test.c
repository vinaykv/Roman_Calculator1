#include <check.h>

#line 1 "calculator-test.check"
/* 
Roman calculator: performs addition and subtraction of roman values
Author: Vinay vittal Karagod
File dependents: main.c, calculator.h, calculator.c,calculator-test.check
Date: 09/07/2016
calculator-test.check: Test file used to pass the input values to calculate roman numbers.
*/

# include "calculator.h"
# include "roman_decimal.h"
# include "decimal_roman.h"
# include "error.h"
char buffer[50];

START_TEST(roman_digit_to_decimal)
{
#line 16

/* checking the conditions for the single roman value*/
ck_assert_msg(roman_to_decimal_digit_value('I') == 1,"operation failed for I");
ck_assert_msg(roman_to_decimal_digit_value('V') == 5,"operation failed for V");
ck_assert_msg(roman_to_decimal_digit_value('X') == 10,"operation failed for X");
ck_assert_msg(roman_to_decimal_digit_value('L') == 50,"operation failed for L");
ck_assert_msg(roman_to_decimal_digit_value('C') == 100,"operation failed for C");
ck_assert_msg(roman_to_decimal_digit_value('D') == 500,"operation failed for D");
ck_assert_msg(roman_to_decimal_digit_value('M') == 1000,"operation failed for M");

}
END_TEST

START_TEST(invalid_roman_digit)
{
#line 27
ck_assert_msg(roman_to_decimal_digit_value('\0') == 0,"operation failed for end of line");
ck_assert_msg(roman_to_decimal_digit_value('K') == -1,"operation failed for passing wrong input");

}
END_TEST

START_TEST(roman_string_to_decimal)
{
#line 31
/*condition to check the string of roman numbers*/
ck_assert_msg(roman_string_to_decimal_value("MD") == 1500,"operation failed to convert roman to decimal");
ck_assert_msg(roman_string_to_decimal_value("MM") == 2000,"operation failed to convert roman to decimal");

}
END_TEST

START_TEST(invalid_roman_string)
{
#line 36
ck_assert_msg(roman_string_to_decimal_value("DM") == 1500,"wrong format to pass the roman value");
}
END_TEST

START_TEST(invalid_roman_string1)
{
ck_assert_msg(roman_string_to_decimal_value("MMMDM") == 4500,"wrong format to pass the roman value");
}
END_TEST

START_TEST(decimal_to_roman_string)
{
#line 39
/*condition to convert back from decimal to roman number*/
ck_assert_msg(strcmp(decimal_number_to_roman_string(1000,buffer),"M") == 0,"Operation failed to convert decimal to roman");
ck_assert_msg(strcmp(decimal_number_to_roman_string(1500,buffer),"MD") == 0,"Operation failed to convert decimal to roman");
ck_assert_msg(strcmp(decimal_number_to_roman_string(1900,buffer),"MCM") == 0,"Operation failed to convert decimal to roman");
ck_assert_msg(strcmp(decimal_number_to_roman_string(150,buffer),"CL") == 0,"Operation failed to convert decimal to roman");
ck_assert_msg(strcmp(decimal_number_to_roman_string(15,buffer),"XV") == 0,"Operation failed to convert decimal to roman");
ck_assert_msg(strcmp(decimal_number_to_roman_string(4,buffer),"IV") == 0,"Operation failed to convert decimal to roman");

/*condition to perform addition and subtraction operation of roman numbers*/
}
END_TEST

START_TEST(roman_addition)
{
#line 49
ck_assert_msg(strcmp(calculate_roman_numbers("M","D","ADD",buffer),"MD") == 0,"Operation failed to return the roman value");
ck_assert_msg(strcmp(calculate_roman_numbers("M","D","add",buffer),"MD") == 0,"Operation failed to return the roman value");

}
END_TEST

START_TEST(roman_addition_small_numbers)
{
ck_assert_msg(strcmp(calculate_roman_numbers("II","II","ADD",buffer),"IV") == 0,"Operation failed to return the roman value");
ck_assert_msg(strcmp(calculate_roman_numbers("V","V","add",buffer),"X") == 0,"Operation failed to return the roman value");
}
END_TEST

START_TEST(roman_subtraction)
{
#line 53
ck_assert_msg(strcmp(calculate_roman_numbers("MMMMD","D","SUBTRACT",buffer),"MMMM") == 0,"Operation failed to return the roman value");
ck_assert_msg(strcmp(calculate_roman_numbers("M","D","subtract",buffer),"D") == 0,"Operation failed to return the roman value");

}
END_TEST

START_TEST(invalid_operation)
{
#line 57
ck_assert_msg(strcmp(calculate_roman_numbers("M","D","XXX",buffer),"0") != 0,"Passed invalid option");

}
END_TEST

START_TEST(limit_exceeded)
{
#line 60
ck_assert_msg(strcmp(calculate_roman_numbers("MM","MM","ADD",buffer),"0") != 0,"limit exceeds maximum value");

}
END_TEST

int main(void)
{
    Suite *s1 = suite_create("Core");
    TCase *tc1_1 = tcase_create("Core");
    SRunner *sr = srunner_create(s1);
    int nf;

    suite_add_tcase(s1, tc1_1);
    tcase_add_test(tc1_1, roman_digit_to_decimal);
    tcase_add_test(tc1_1, invalid_roman_digit);
    tcase_add_test(tc1_1, roman_string_to_decimal);
    tcase_add_test(tc1_1, invalid_roman_string);
    tcase_add_test(tc1_1, invalid_roman_string1);
    tcase_add_test(tc1_1, decimal_to_roman_string);
    tcase_add_test(tc1_1, roman_addition);
    tcase_add_test(tc1_1, roman_addition_small_numbers);
    tcase_add_test(tc1_1, roman_subtraction);
    tcase_add_test(tc1_1, invalid_operation);
    tcase_add_test(tc1_1, limit_exceeded);

    srunner_run_all(sr, CK_ENV);
    nf = srunner_ntests_failed(sr);
    srunner_free(sr);

    return nf == 0 ? 0 : 1;
}
