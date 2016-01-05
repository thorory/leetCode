#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define TAB_SIZE 65536
#define HALF_TAB_SIZE (TAB_SIZE/2)

int* twoSum(int* nums, int numsSize, int target)
{
    int tab[TAB_SIZE], index1, index2;
    int i, j;
    int *result = malloc(sizeof(result[0]) * 2);


    /* init the tab */
    /* index = value + HAL_TAB_SIZE */
    memset(result, 0, sizeof(result[0] * 2));
    memset(tab, -1, sizeof(tab[0]) * TAB_SIZE);
    for(i = 0; i < numsSize; i++)
        tab[nums[i] + HALF_TAB_SIZE] = i;

    for(i = 0; i < numsSize; i++)
    {
        index2 = target - nums[i] + HALF_TAB_SIZE;
        if(index2 >= 0)
            index1 = tab[index2];
        else
            continue;

        if(index1 > i)
        {
            result[0] = i +1;
            for(j = i + 1; j < numsSize; j++)
            {
               if(nums[j] == (target - nums[i]))
               {
                   result[1] = j + 1;
                   break;
               }
            }
            break;
         }
    }

    return result;
}



/* test client */
int main()
{
    int array[] = {0, 4, 2, 0}, *result;
    int i;

    result = twoSum(array, 4, 0);

    printf("index1 %d, index2 %d\n", result[0], result[1]);

    free(result);
    return 0;
}

