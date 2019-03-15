/**
 * 冒泡排序：C 语言
 *
 * @author skywang
 * @date 2014/03/11
 *
 * modified:
 * by XieLong
 * date 2019/03/15
 */

#include <stdio.h>

// 数组长度
#define LENGTH(array) ( (sizeof(array)) / (sizeof(array[0])) )
// 交互数值
#define swap(a,b)	(a^=b,b^=a,a^=b)

/*
 * 冒泡排序
 *
 * 返回值说明：
 *     s -- 算法循环的次数
 * 参数说明：
 *     a -- 待排序的数组
 *     n -- 数组的长度
 */
int bubble_sort1(int a[], int n)
{
	int i, j, s = 0;

	for (i = n-1; i > 0; i--)
	{
        // 将a[0...i]中最大的数据放在末尾
		for (j = 0; j < i; j++)
		{
			if (a[j] > a[j+1])
            {
				swap(a[j], a[j+1]);
            }
            s++;
		}
	}
    return s;
}

/*
 * 冒泡排序(改进版)
 *
 * 返回值说明：
 *     s -- 算法循环的次数
 * 参数说明：
 *     a -- 待排序的数组
 *     n -- 数组的长度
 */
int bubble_sort2(int a[], int n)
{
	int i, j, s = 0;
	int flag; 				// 标记

	for (i = n-1; i > 0; i--)
	{
		flag = 0;			// 初始化标记为0

        // 将a[0...i]中最大的数据放在末尾
		for (j = 0; j < i; j++)
		{
			if (a[j] > a[j+1])
			{
				swap(a[j], a[j+1]);
				flag = 1;	// 若发生交换，则设标记为1
			}
            s++;            // 记录循环次数
		}

		if (flag == 0)
			break;			// 若没发生交换，则说明数列已有序。
	}
    return s;
}

int main()
{
	int i;
	int a[] = {10,20,40,30,10,60,50,70};
    int b[] = {10,20,40,30,10,60,50,70};
	int alen = LENGTH(a);
    int blen = LENGTH(b);

	printf("before sort:");
	for (i = 0; i < alen; i++)
		printf("%d ", a[i]);
	printf("\n");

	int as = bubble_sort1(a, alen);
	int bs = bubble_sort2(b, blen);

	printf("after sort1:");
	for (i = 0; i < alen; i++)
		printf("%d ", a[i]);
	printf("\nafter sort2:");
    for (i = 0; i < blen; i++)
        printf("%d ", b[i]);
    printf("\n");

    printf("bubble_sort1 used %d time(s) to swap.\n", as);
    printf("bubble_sort2 used %d time(s) to swap.\n", bs);

    return 0;
}
