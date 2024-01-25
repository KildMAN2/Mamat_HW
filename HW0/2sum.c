#include <stdio.h>


#define MAX_ARRAY_SIZE 10000
#define HASH_LENGTH MAX_ARRAY_SIZE * 2 +1
#define INSTALLATION -1

void twoSum(int nums[], int nums_size, int target);

int main() {
	int target;
	int nums[MAX_ARRAY_SIZE] = {0};
	int array_size = 0;

	if(!scanf("%d", &target))
        return 0;

	while (array_size < MAX_ARRAY_SIZE && scanf("%d", &nums[array_size]) == 1)
    {
        array_size++;
    }
    if(array_size <2)
        return 0;

	twoSum(nums, array_size, target);

	return (0);
}

void twoSum(int nums[], int nums_size, int target) {
    /* YOUR CODE HERE */
    for (int i = 0; i < nums_size - 1; ++i) {
        for (int j = i + 1; j < nums_size; ++j) {
            if (nums[i] + nums[j] == target) {
                printf("(%d, %d)\n", i, j);
                return;
            }
        }

    }
}

