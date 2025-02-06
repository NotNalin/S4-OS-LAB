#include <stdio.h>
#include <stdlib.h>
struct process
{
	int ID;
	int AT;
	int BT;
	int CT;
	int WT;
	int TAT;
};
void main()
{
	int num;
	double AWT = 0, ATAT = 0;
	printf("Enter number of processes: ");
	scanf("%d", &num);
	struct process pl[num];
	for (int i = 0; i < num; i++)
	{
		printf("Enter ID, AT, BT for process : ");
		scanf("%d %d %d", &pl[i].ID, &pl[i].AT, &pl[i].BT);
	}
	for (int i = 0; i < num - 1; i++)
	{
		for (int j = 0; j < num - i - 1; j++)
		{
			if (pl[j].AT > pl[j + 1].AT)
			{
				struct process temp = pl[j];
				pl[j] = pl[j + 1];
				pl[j + 1] = temp;
			}
			else if (pl[j].AT == pl[j + 1].AT)
			{
				if (pl[j].ID > pl[j + 1].ID)
				{
					struct process temp = pl[j];
					pl[j] = pl[j + 1];
					pl[j + 1] = temp;
				}
			}
		}
	}
	int time = 0, count = 0, over = 0;
	while (over < num)
	{
		count = 0;
		for (int i = over; i < num; i++)
		{
			if (pl[i].AT <= time)
				count++;
		}
		if (count > 1)
		{
			for (int i = over; i < over + count; i++)
			{
				for (int j = over; j < over + count - 1; j++)
				{
					if (pl[j].BT > pl[j + 1].BT)
					{
						struct process temp = pl[j];
						pl[j] = pl[j + 1];
						pl[j + 1] = temp;
					}
				}
			}
		}
		time = time + pl[over].BT;
		pl[over].CT = time;
		pl[over].TAT = pl[over].CT - pl[over].AT;
		pl[over].WT = pl[over].TAT - pl[over].BT;
		over++;
	}
	// pl[0].CT = pl[0].AT + pl[0].BT;
	// pl[0].TAT = pl[0].CT - pl[0].AT;
	// pl[0].WT = pl[0].TAT - pl[0].BT;
	// for (int i = 1; i < num; i++)
	// {
	// 	pl[i].CT = pl[i - 1].CT + pl[i].BT;
	// 	pl[i].TAT = pl[i].CT - pl[i].AT;
	// 	pl[i].WT = pl[i].TAT - pl[i].BT;
	// }
	for (int i = 0; i < num; i++)
	{
		AWT = AWT + pl[i].WT;
		ATAT = ATAT + pl[i].TAT;
	}
	AWT = AWT / num;
	ATAT = ATAT / num;
	for (int i = 0; i < num - 1; i++)
	{
		for (int j = 0; j < num - i - 1; j++)
		{
			if (pl[j].ID > pl[j + 1].ID)
			{
				struct process temp = pl[j];
				pl[j] = pl[j + 1];
				pl[j + 1] = temp;
			}
		}
	}
	printf("\nID\tAT\tBT\tWT\tTAT\n");
	for (int i = 0; i < num; i++)
		printf("%d\t%d\t%d\t%d\t%d\n", pl[i].ID, pl[i].AT, pl[i].BT, pl[i].WT, pl[i].TAT);
	printf("AWT : %f\n", AWT);
	printf("ATAT : %f\n", ATAT);
}
