#include <stdio.h>
#include <stdlib.h>
#include <string.h>


double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size)
{
    int index1 = nums1Size / 2, index2 = nums2Size / 2;
    int pos = (nums1Size + nums2Size) / 2 - (nums1Size + nums2Size + 1) % 2;
    int hi1 = nums1Size, hi2 = nums2Size;
    int lo1 = 0, lo2 = 0;

    int val = nums1[index1];
    int flag = 0;

    if(nums1Size == 0 && nums2Size != 0)
        return nums2[index2];
    if(nums1Size != 0 && nums2Size == 0)
        return nums1[index1];

    while(1)
    {
       if(flag == 0)
       {
           index2 = pos - index1;
           if(index2 < lo2)
           {
               index2 = lo2;
               hi1 = pos -index2;
           }
           if(index2 > hi2)
           {
               index2 = hi2;
               lo1 = pos - index2;
           }

           val = nums1[pos-index2];
           if(val < nums2[index2-1])
           {
                hi2 = index2;
                index2 = (index2 + lo2) / 2;
                flag = 1;
           }
           else if(val > nums2[index2])
           {
                lo2 = index2;
                index2 = (index2 + hi2) / 2;
                flag = 1;
           }
           else
               break;
       }
       else
       {
           index1 = pos - index2;
           if(index1 < lo1)
           {
               index1 = lo1;
               hi2 = pos - index1;
           }
           if(index1 > hi1)
           {
               index1 = hi1;
               lo2 = pos - index1;
           }

           val = nums2[pos - index1];
           if(val < nums1[index1-1])
           {
                hi1 = index1;
                index1 = (index1 + lo1) / 2;
                flag = 0;
           }
           else if(val > nums1[index1])
           {
                lo1 = index1;
                index1 = (index1 + hi1) / 2;
                flag = 0;
           }
           else
               break;
        }
    }
    return (double)val;
}

int main()
{
    int a[] = {1,2,5,7,9};
    int b[] = {1,2,6,8,9,9,9,10};

    double val;

    val = findMedianSortedArrays(a, 3, b, 2);

    printf("%f\n", val);
}


