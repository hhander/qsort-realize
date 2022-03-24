#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct stu
{
	char name[20];
	int age;
}stu;

void swap(char* buf1, char* buf2, int width)
{
	int i = 0;
	for (i = 0; i < width; i++)
	{
		char tem = *buf1;
		*buf1 = *buf2;
		*buf2 = tem;
		buf1++;
		buf2++;
	}
}

void Bubble_sort(void* base, int sz, int width, int(*cmp)(const void* a, const void* b))
{
	int i = 0;
	int j = 0;
	for (i = 1; i < sz; i++)
	{
		for (j = 0; j < sz - i; j++)
		{
			if (cmp((char*)base + width * j, (char*)base + width * (j + 1)) > 0)
			{
				swap((char*)base + width * j, (char*)base + width * (j + 1), width);
			}
		}
	}
}

int cmp_int(const void* a,const void* b)
{
	return *(int*)a - *(int*)b;
}

int cmp_struct(const void* a, const void* b)
{
	return strcmp(((stu*)a)->name,((stu*)b)->name);
}
void test1()
{
	int arr[] = { 9,8,7,6,5,4,3,2,1,0 };
	int sz = sizeof(arr) / sizeof(arr[0]);
	Bubble_sort(arr,sz,sizeof(arr[0]),cmp_int);
}

void test2()
{
	stu s[3] = { {"zhangsan",30},{"lisi",20},{"wangwu",10}};
	int sz = sizeof(s) / sizeof(s[0]);
	Bubble_sort(s,sz,sizeof(s[0]),cmp_struct);
}




int main()
{
	test2();
}










//typedef struct stu
//{
//	char name[20];
//	int age;
//}stu;
//
//int compare(const void* s1, const void* s2)
//{
//	return strcmp(((stu*)s1)->age,((stu*)s2)->age);
//}
//
//
//int main()
//{
//	stu s[3] = { {"zhangsan",30},{"lisi",20},{"wangwu",10} };
//	int sz = sizeof(s) / sizeof(s[0]);
//	qsort(s->age, sz, sizeof(s[0]), compare);
//	printf("%s", s[1].name);
//	return 0;
//}










//int compare(const void* a, const void* b)
//{
//	return *(double*)a - *(double*)b;
//}
//
//
//int main()
//{
//	double arr[10] = { 9.0,8.0,7.0,6.0,5.0,4.0,3.0,2.0,1.0 };
//	qsort(arr, 10, sizeof(arr[0]), compare);
//	int i = 0;
//	for (i = 0; i < 10; i++)
//	{
//		printf("%f ", arr[i]);
//	}
//	return 0;
//}

//void print(char* str)
//{
//	printf("%s", str);
//}
//
//
//void test(void(*p)(char*))
//{
//	p("hehe");
//}
//
//
//int main()
//{
//	test(print);
//	return 0;
//}







//void Bubble_Sort(int arr[], int sz)
//{
//	int i = 0;
//	int flag = 0;
//	for (i = 1; i < sz; i++)
//	{
//		int j = 0;
//		for (j = 0; j < sz - i;j++)
//		{
//	
//			if (arr[j] > arr[j + 1])
//			{
//				int ret = arr[j];
//				arr[j] = arr[j + 1];
//				arr[j + 1] = ret;
//				flag = 1;
//			}
//			if (flag == 0)
//			{
//				break;
//			}
//		}
//	}
//}
//
//
//
//int main()
//{
//	int arr[10] = { 1,2,3,4,5,6,7,8,9,0 };
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	Bubble_Sort(arr,sz);
//	int i = 0;
//	for (i = 0; i < sz; i++)
//	{
//		printf("%d", arr[i]);
//	}
//	return 0;
//}
//	 









//int main()
//{
//	int arr[10] = { 0 };
//	int(*p)[10] = &arr;
//
//	int(*pArr[10])(int, int);
//	int(*(*ppArr)[10])(int, int) = &pArr;
//	return 0;
//}










//void menu()
//{
//	printf("**********************\n");
//	printf("****1. add  2. sub****\n");
//	printf("****3. mul  4. div****\n");
//	printf("***     0. exit    ***\n");
//}
//
//int add(int x, int y)
//{
//	return x + y;
//}
//int sub(int x, int y)
//{
//	return x - y;
//}
//int mul(int x, int y)
//{
//	return x*y;
//}
//int div(int x, int y)
//{
//	return x / y;
//}
//
//void calc(int(*pf)(int, int))
//{
//	int x = 0;
//	int y = 0;
//	printf("请输入");
//	scanf("%d%d", &x, &y);
//	printf("%d",pf(x, y));
//}
//
//
//
//int main()
//{
//	int x = 0;
//	int y = 0;
//	int input = 0;
//	do
//	{
//		menu();
//		int(*pfArr[5])(int, int) = { 0,add,sub,mul,div };
//		printf("请选择功能");
//		scanf("%d", &input);
//		if (input >= 1 && input <= 4)
//		{
//			printf("请输入参数");
//			scanf("%d%d", &x, &y);
//			int ret = (*pfArr[input])(x, y);
//			printf("%d\n", ret);
//		}
//		else if (input == 0)
//		{
//			printf("退出");
//		}
//		else
//		{
//			printf("err");
//		}
//	} while (input);
//	/*do
//	{
//		menu();
//		printf("请选择");
//		scanf("%d", &input);
//		
//		switch (input)
//		{
//			case 1:
//			{
//				calc(add);
//				break;
//			}
//			case 2:
//			{
//				calc(sub);
//				break;
//			}
//			case 3:
//			{
//				calc(mul);
//				break;
//			}
//			case 4:
//			{
//				calc(div);
//				break;
//			}
//			case 0:
//			{
//				break;
//			}
//		defalut:
//			{
//				printf("err");
//				break;
//			}
//		}
//	} while (input);*/
//	return 0;
//}