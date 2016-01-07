#include <stdio.h>
#include <stdlib.h>
#include <string.h>


double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size)
{
    int pos = (nums1Size + nums2Size) / 2 - (nums1Size + nums2Size + 1) % 2;
    int hi1 = nums1Size, hi2 = nums2Size;
    int lo1 = 0, lo2 = 0;
    int index1, index2;
    double val;
    int flag = (nums1Size + nums2Size) % 2;
    int min;

    if(nums1Size == 0)
    	if(flag == 0)
    		return (nums2[nums2Size / 2 - 1] + nums2[nums2Size / 2]) / 2.0;
    	else
    		return nums2[nums2Size / 2];
    if(nums2Size == 0)
    	if(flag == 0)
    		return (nums1[nums1Size / 2 - 1] + nums1[nums1Size / 2]) / 2.0;
    	else
    		return nums1[nums1Size / 2];

    while(1)
    {
    	/* nums1 */
    	index1 = (hi1 + lo1) / 2;
    	val = nums1[index1];
    	index2 = pos - index1;
    	if(index2 < lo2)
    	{
    		hi1 = index1 - 1;
    		continue;
    	}
    	if(index2 > hi2)
    	{
    		lo1 = index1 + 1;
    		continue;
    	}
    	if(val > nums2[index2])
    	{
    		if(index2 == hi2)
    			if(flag == 0)
				{
					if(val == nums1[index2-1])
						return val;
					else if(index1 != nums1Size-1 && index2 !=nums2Size-1)
					{
						min = (nums1[index1+1] < nums2[index2]) ? nums1[index1+1] : nums2[index2];
						return (val + min ) / 2.0;
					}
				}
				else
					return val;
  
    		hi1 = index1;
    	}
    	else if(val < nums2[index2-1])
    	{
    		if(index2 - 1 == lo2)
    			if(flag == 0)
				{
					if(val == nums1[index2-1])
						return val;
					else if(index1 != nums1Size-1 && index2 !=nums2Size-1)
					{
						min = (nums1[index1+1] < nums2[index2]) ? nums1[index1+1] : nums2[index2];
						return (val + min ) / 2.0;
					}
				}
				else
					return val;

    		lo1 = index1;
    	}
    	else
    	{
    		if(flag == 0)
			{
				if(val == nums1[index2-1])
					return val;
				else if(index1 != nums1Size-1 && index2 !=nums2Size-1)
				{
					min = (nums1[index1+1] < nums2[index2]) ? nums1[index1+1] : nums2[index2];
					return (val + min ) / 2.0;
				}
			}
			else
				return val;
    	}

    	    	/* nums1 */
    	index2 = (hi2 + lo2) / 2;
    	val = nums2[index2];
    	index1 = pos - index2;
    	if(index1 < lo1)
    	{
    		hi2 = index2 - 1;
    		continue;
    	}
    	if(index1 > hi1)
    	{
    		lo2 = index2 + 1;
    		continue;
    	}
    	if(val > nums1[index1])
    	{
    		if(index1 == hi1)
    			if(flag == 0)
				{
					if(val == nums1[index1-1])
						return val;
					else if(index1 != nums1Size-1 && index2 !=nums2Size-1)
					{
						min = (nums1[index1] < nums2[index2+1]) ? nums1[index1] : nums2[index2+1];
						return (val + min ) / 2.0;
					}
				}
				else
					return val;
    		hi2 = index2;
    	}
    	else if(val < nums1[index1-1])
    	{
    		if(index1 - 1 == lo1)
	    		if(flag == 0)
				{
					if(val == nums1[index1-1])
						return val;
					else if(index1 != nums1Size-1 && index2 !=nums2Size-1)
					{
						min = (nums1[index1] < nums2[index2+1]) ? nums1[index1] : nums2[index2+1];
						return (val + min ) / 2.0;
					}
				}
				else
					return val;
    		lo2 = index2;
    	}
    	else
    	{
    		if(flag == 0)
			{
				if(val == nums1[index1-1])
					return val;
				else if(index1 != nums1Size-1 && index2 !=nums2Size-1)
				{
					min = (nums1[index1] < nums2[index2+1]) ? nums1[index1] : nums2[index2+1];
					return (val + min ) / 2.0;
				}
			}
			else
				return val;
    	}
    }

}

int main()
{
    int a[] = {1,2};
    int b[] = {1,2,4,5};

    double val;

    val = findMedianSortedArrays(a, 2, b, 2);

    printf("%f\n", val);
}


