#include <stdio.h>

int mutex = 1, full = 0, empty, x = 0;

int wait(int S)
{
	return --S;
}
int signal(int S)
{
	return ++S;
}
void producer()
{
	mutex = wait(mutex);
	empty = wait(empty);
	x++;
	printf("Producer produces item %d\n", x);
	full = signal(full);
	mutex = signal(mutex);
}
void consumer()
{
	mutex = wait(mutex);
	full = wait(full);
	printf("Consumer comsumes item %d\n", x);
	x--;
	empty = signal(empty);
	mutex = signal(mutex);
}

void main()
{
	printf("Enter buffer size : ");
	scanf("%d", &empty);
	printf("1.Producer\n2.Consumer\n3.Exit\n");
	int ch = 0;
	do
	{
		printf("Enter the choice : ");
		scanf("%d", &ch);
		switch (ch)
		{
		case 1:
			if ((mutex == 1) && (empty != 0))
				producer();
			else
				printf("Buffer is full\n");
			break;
		case 2:
			if ((mutex == 1) && (full != 0))
				consumer();
			else
				printf("Buffer is Empty\n");
			break;
		case 3:
			break;
		}
	} while (ch != 3);
}
