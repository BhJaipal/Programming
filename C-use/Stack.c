#include <stdio.h>
#include <malloc.h>

typedef struct _Stack
{
	int *arr;
	int len;
} Stack;

int main()
{
	Stack stack;
	stack.arr = malloc(sizeof(int));
	stack.len = 0;
	while (1)
	{
		printf("Select anyone: \n");
		printf("1. Add an element\n2. Remove top element\n3. Take a peek\n4. Show whole stack\n5. Quit\n");
		printf("Enter your choice: ");
		int choice;
		scanf("%d", &choice);
		if (choice == 1)
		{
			int el = 0;
			printf("Enter an element: ");
			scanf("%d", &el);
			stack.arr = realloc(stack.arr, sizeof(int) * (stack.len + 1));
			stack.arr[stack.len] = el;
			stack.len++;
			printf("%d added to stack\n\n", el);
		}
		else if (choice == 2)
		{
			if (stack.len == 0)
			{
				printf("Stack is empty\n\n");
			}
			else
			{
				printf("Poped stack element: %d\n\n", stack.arr[stack.len - 1]);
				stack.arr[stack.len - 1] = 0;
				stack.arr = realloc(stack.arr, sizeof(int) * (stack.len - 1));
				stack.len--;
			}
		}
		else if (choice == 3)
		{
			if (stack.len != 0)
			{
				printf("Top element: %d\n\n", stack.arr[stack.len - 1]);
			}
			else
			{
				printf("Stack is empty\n\n");
			}
		}
		else if (choice == 4)
		{
			if (stack.len == 0)
			{
				printf("Stack is empty\n\n");
			}
			else
			{
				printf("Stack is: ");
				for (int i = 0; i < stack.len; i++)
				{
					printf("%d  ", stack.arr[i]);
				}
				printf("\n\n");
			}
		}
		else if (choice == 5)
		{
			printf("Quitting process\n\n");
			break;
		}
		else
		{
			printf("Invalid choice\n\n");
		}
	}
	free(stack.arr);
	stack.len = 0;
	printf("Memory freed\n");
	return 0;
}
