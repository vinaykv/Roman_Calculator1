/* 
Roman calculator: performs addition and subtraction of roman values
Author: Vinay vittal Karagod
File dependents: main.c, calculator.h, calculator.c,calculator-test.check
Date: 09/06/2016
*/

# include "calculator.h"
# include <check.h>
# include <stdio.h>
# include <math.h>
# include <errno.h>
# include <stdlib.h>
# include <string.h>

int romanValue(char r_Character)
{
	int value=0;
	switch(r_Character){
	case 'I': value = 1; 
	break;
	case 'V': value = 5; 
	break;
	case 'X': value = 10; 
	break;
	case 'L': value = 50; 
	break;
	case 'C': value = 100; 
	break;
	case 'D': value = 500; 
	break;
	case 'M': value = 1000; 
	break;	
	case '\0': value = 0; 
	break;
	default: value = -1;
	}
	return value;
}

int roman_decimal(char number[])
	{
	int index_value = 0;
	int decnum = 0; // value to store the dicimal value 
	while(number[index_value] == 'I' || number[index_value] == 'V' || number[index_value] == 'X' || number[index_value] == 'L'|| number[index_value] == 'C' || number[index_value] == 'D' || number[index_value] == 'M')
	{

	if(romanValue(number[index_value]) < 0) // condition to check the invalid numbers
		{
			printf("%d",romanValue(number[index_value]));
			printf("Invalid roman digit : %c",number[index_value]);
			exit(0);
		}
	if((strlen(number) - index_value) > 2)
		{
			if(romanValue(number[index_value]) < romanValue(number[index_value+2])){
				printf("Invalid roman number");
				exit(0);
			}
		}
	if(romanValue(number[index_value]) >= romanValue(number[index_value+1])) // reading each roman from the string
			decnum = decnum + romanValue(number[index_value]);
		else{
			decnum = decnum + (romanValue(number[index_value+1]) - romanValue(number[index_value]));
			index_value++;
	}
	index_value++;
	}
return decnum;
}
// storing the predigits for example: 40 has to be stored as XL 
char* predigits(char character1,char character2,char* buffer)
{
	*buffer = character1;
	buffer++;
	*buffer = character2;
	buffer++;
	return buffer;
}

//storing the post digits
char* postdigits(char character,int count,char* buffer)
{
	int loop;
	for(loop=0;loop<count;loop++){
		*buffer = character;
		buffer++;
	}
	return buffer;
}

char* decimal_roman(int total,char* buffer)
	{
	char *roman_num = buffer;

	while(total !=0)
	{
	if(total >= 1000){ // converstion for 1000
			buffer = postdigits('M',total/1000,buffer);
			total = total - (total/1000) * 1000;
		}
	
	else if(total >=500){ // conversion for 500
		if(total <(500 + 4*100 )){
				buffer = postdigits('D',total/500,buffer);
				total = total - (total/500) * 500;
			}
		else{
				buffer = predigits('C','M',buffer);
				total = total - (1000-100);
	}
	}

	}/*end of while loop*/	

	*buffer = '\0';
return roman_num;
}




