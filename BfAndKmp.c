#include <stdio.h>


int slen(char* s)
{
	int i = 0;
	if (s == NULL) {
		return 0;
	}
	else {

		while (s[i] != '\0')
		{
			i++;
		}
		return i;
	}
}

//BF
int* bf(char* str,char *ptr)
{
	int i=0, j=0;
	int index = 0;
	int strlen = slen(str);
	int ptrlen = slen(ptr);


	while (i<strlen&&j<ptrlen)
	{

		if (str[i]==ptr[j]) {
			i++; 
			j++;
		}
		else {
			index++;
			i = index;
			j = 0;
		}
	}
	if (j == ptrlen) {
		return i-j;
	}
	else {
		return -1;
	}
	

}


//kmp
int* kmp(char* haystack, char* needle)
{
	int i = 0, j = 0;
	int strlen = slen(haystack);
	int ptrlen = slen(needle);

	while (i < strlen && j < ptrlen)
	{

		if (haystack[i] == needle[j]) {
			i++;
			j++;
		}
		else {
			i = i-j+1;
			j = 0;
		}
	}
	if (j == ptrlen) {
		return i - j;
	}
	else {
		return -1;
	}
}



int main(void)
{
	char *str= "hello";

	char* ptr = "ll";

	//int res=bf(str, ptr);

	int res = kmp(str, ptr);

	printf("%d \n",res);


	return 0;
}