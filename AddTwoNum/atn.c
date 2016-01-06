// AddTwoNumbers.cpp : 定义控制台应用程序的入口点。
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*****************************************************************************
 * TYPE DEFINE
*****************************************************************************/
struct ListNode {
	int val;
	struct ListNode *next;
};

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
	struct ListNode *new_list;
	int cin = 0, tmp = 0;
	struct ListNode *start_list, *end_list;
	int flag = 0;

	/* initial */
	start_list = end_list = NULL;

	while (1)
	{
		if (l1 == NULL)
		{
			if(flag == 0)
			{
				start_list = l2;
				return start_list;
			}
			while (l2 != NULL)
			{
				end_list->next = l2;
				if (cin == 0)
					return start_list;
				tmp = (l2->val + cin) ;
				l2->val = tmp % 10;
				cin = tmp / 10;
				end_list = l2;
				l2 = l2->next;
			}
			if(cin > 0)
			{
				new_list = (struct ListNode*)malloc(sizeof(l1[0]));
				new_list->val = cin;
				new_list->next = NULL;
				end_list->next = new_list;
			}

			return start_list;
		}
		if (l2 == NULL)
		{
			if(flag == 0)
			{
				start_list = l1;
				return start_list;
			}
			while (l1 != NULL)
			{
				end_list->next = l1;
				if (cin == 0)
					return start_list;
				tmp = (l1->val + cin) ;
				l1->val = tmp % 10;
				cin = tmp / 10;
				end_list = l1;
				l1 = l1->next;
			}
			if(cin > 0)
			{
				new_list = (struct ListNode*)malloc(sizeof(l1[0]));
				new_list->val = cin;
				new_list->next = NULL;
				end_list->next = new_list;
			}
			return start_list;
		}

		/* add two number */
		new_list = (struct ListNode*)malloc(sizeof(l1[0]));
		new_list->val = (l1->val + l2->val + cin) % 10;
		cin = (l1->val + l2->val + cin)  / 10;
		new_list->next = NULL;
		if(flag == 0)
		{
			start_list = new_list;
			end_list = new_list;
			flag = 1;
		}
		else
		{
			end_list->next = new_list;
			end_list = new_list;
		}
		l1 = l1->next;
		l2 = l2->next;
	}
	return start_list;
}

int main()
{
	struct ListNode l1, l2,  l3, *l = NULL;
	l1.next = NULL;
	l1.val = 1;

	l2.next = &l3;
	l2.val = 9;

	l3.val = 9;
	l3.next = NULL;

	l = addTwoNumbers(&l1,  &l2);

	while(l != NULL)
	{
		printf("%d->", l->val);
		l = l->next;
	}
	printf("\n");

	return 0;
}