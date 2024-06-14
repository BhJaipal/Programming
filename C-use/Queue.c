#include <stdio.h>
#include <malloc.h>

typedef struct _Queue
{
	int *arr;
	int len;
} Queue;

int main()
{
	Queue queue;
	queue.arr = malloc(sizeof(int));
	queue.len = 0;
	while (1)
	{
		printf("Select anyone: \n");
		printf("1. Add an element\n2. Remove front element\n3. Take a peek\n4. Show whole queue\n5. Quit\n");
		printf("Enter your choice: ");
		int choice;
		scanf("%d", &choice);
		if (choice == 1)
		{
			int el = 0;
			printf("Enter an element: ");
			scanf("%d", &el);
			queue.arr = realloc(queue.arr, sizeof(int) * (queue.len + 1));
			queue.arr[queue.len] = el;
			queue.len++;
			printf("%d is added to queue\n\n", el);
		}
		else if (choice == 2)
		{
			if (queue.len != 0)
			{
				printf("Poped queue element: %d\n\n", queue.arr[0]);
				for (int i = 0; i < queue.len - 1; i++)
				{
					queue.arr[i] = queue.arr[i + 1];
				}
				queue.arr[queue.len - 1] = 0;
				queue.arr = realloc(queue.arr, sizeof(int) * (queue.len - 1));
				queue.len--;
			}
			else
			{
				printf("Queue is empty\n\n");
			}
		}
		else if (choice == 3)
		{
			if (queue.len != 0)
			{
				printf("Front element: %d\n\n", queue.arr[0]);
			}
			else
			{
				printf("Queue is empty\n\n");
			}
		}
		else if (choice == 4)
		{
			if (queue.len == 0)
			{
				printf("Queue is empty\n\n");
			}
			else
			{
				printf("Queue is: ");
				for (int i = 0; i < queue.len; i++)
				{
					printf("%d  ", queue.arr[i]);
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

	free(queue.arr);
	queue.len = 0;
	printf("Memory freed\n");
	return 0;
}
