#include <stdio.h>
/*
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 */

#define MAX_ARRAY_SIZE 10000
#define HASH_LENGTH MAX_ARRAY_SIZE * 2 +1
#define INSTALLATION -1

void twoSum(int nums[], int nums_size, int target);

int main() {
	int target;
	int nums[MAX_ARRAY_SIZE] = {0};
	int array_size = 0;

	scanf("%d", &target);

	while (scanf("%d", &nums[array_size++]) == 1);
	array_size--;

	twoSum(nums, array_size, target);

	return (0);
}

void twoSum(int nums[], int nums_size, int target)
{
	/* YOUR CODE HERE */
    int hashtable[HASH_LENGTH];
    for (int i = 0; i < HASH_LENGTH; ++i)
    {
       hashtable[i] = INSTALLATION;
    }
    for (int i = 0; i < nums_size; ++i)
    {
        int comp = target - nums[i];
        if(hashtable[comp + MAX_ARRAY_SIZE] != INSTALLATION)
        {
            printf("(%d, %d)\n", hashtable[comp + MAX_ARRAY_SIZE],i);
            return;
        }
        hashtable[nums[i] + MAX_ARRAY_SIZE] = i;
    }

}

