#include <iostream>

typedef struct {
	int one;
	int two;
} pair;

int cmp_char(char* first, char* second)
{
	return *first == *second;
}

int cmp_int(int* first, int* second)
{
	return *first == *second;
}

int cmp_pair(pair* first, pair* second)
{
	return (first->one == second->one & first->two == second->two);
}

int linearSearch(void* array, size_t elemSize, int len, void* key, int (*cmp)(void* a, void* b))
{
	if (!array || !key || !cmp) {
		return -1;
	}

	for (int i = 0; i < len; i++)
	{
		void* currentElem = (void*)((size_t)array + elemSize * i);
		if ((cmp)(currentElem, key))
		{
			return i;
		}
	}
	return -1;

}

int main()
{
	int arr[10] = { 3, 4, 1, 7, 5, 8, 11, 42, 3, 13 };
	int size = sizeof(arr[0]);
	int key = 11;
	int length = sizeof(arr) / sizeof(arr[0]);
	int index = linearSearch(arr, size, length, &key, (int(*) (void*, void*))cmp_int);

	if (index == -1) {
		printf("The element is not present in the arr.");
	}
	else {
		printf("The element is present at arr[%d].", index);
	}

	char arrchar[10] = { 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j' };
	int sizechar = sizeof(arrchar[0]);
	char keychar = 'k';
	int lengthchar = sizeof(arrchar) / sizeof(arrchar[0]);

	int index_char = linearSearch(arrchar, sizechar, lengthchar, &keychar, (int(*) (void*, void*))cmp_char);

	if (index_char == -1) {
		printf("The element is not present in the arr.");
	}
	else {
		printf("The element is present at arr[%d].", index_char);
	}

	return 0;
}
