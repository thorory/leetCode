#include <stdio.h>
#include <string.h>

#define TAB_SIZE 127

int lengthOfLongestSubstring(char* s) {
    int start = 0, end = 0;
	int max_len = 0, cur_len = 0;

    int tab[TAB_SIZE];
	memset(tab, 0, sizeof(tab[0]) * TAB_SIZE);

	while(*s != '\0')
	{
		/* do not have appeared */
		if(tab[*s] >= start)
			start = tab[*s];

		tab[*s++] = ++end;

		cur_len = end - start;
	    max_len = (max_len > cur_len) ? max_len : cur_len;
	}

	return max_len;
}

/* test client */
int main()
{
    char *s = "12345612342123";

    printf("%d\n", lengthOfLongestSubstring(s));

    return 0;
}
