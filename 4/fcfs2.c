#include <stdio.h>
#include <stdlib.h>

struct process
{
	int ID;
	int AT;	 // Arrival Time
	int BT;	 // Burst Time
	int CT;	 // Completion Time
	int WT;	 // Waiting Time
	int TAT; // Turnaround Time
};

void main()
{
	int num;
	double AWT = 0, ATAT = 0;
	printf("Enter number of processes: ");
	scanf("%d", &num);
	struct process plist[num];
	for (int i = 0; i < num; i++)
	{
		printf("Enter ID, BT, AT for process %d: ", i + 1);
		scanf("%d %d %d", &plist[i].ID, &plist[i].BT, &plist[i].AT);
	}

	// Sort processes based on Arrival Time (AT) and, if equal, by ID
	for (int i = 0; i < num - 1; i++)
	{
		for (int j = 0; j < num - i - 1; j++)
		{
			if (plist[j].AT > plist[j + 1].AT)
			{
				struct process temp = plist[j];
				plist[j] = plist[j + 1];
				plist[j + 1] = temp;
			}
			else if (plist[j].AT == plist[j + 1].AT)
			{
				if (plist[j].ID > plist[j + 1].ID)
				{
					struct process temp = plist[j];
					plist[j] = plist[j + 1];
					plist[j + 1] = temp;
				}
			}
		}
	}
	// Calculate Completion Time (CT), Turnaround Time (TAT), and Waiting Time (WT)
	// (This calculation assumes no idle time between processes.)
	plist[0].CT = plist[0].AT + plist[0].BT;
	plist[0].TAT = plist[0].CT - plist[0].AT;
	plist[0].WT = plist[0].TAT - plist[0].BT;
	for (int i = 1; i < num; i++)
	{
		plist[i].CT = plist[i - 1].CT + plist[i].BT;
		plist[i].TAT = plist[i].CT - plist[i].AT;
		plist[i].WT = plist[i].TAT - plist[i].BT;
	}
	for (int i = 0; i < num; i++)
	{
		AWT = AWT + plist[i].WT;
		ATAT = ATAT + plist[i].TAT;
	}
	AWT = AWT / num;
	ATAT = ATAT / num;
	// Sort processes based on ID
	for (int i = 0; i < num - 1; i++)
	{
		for (int j = 0; j < num - i - 1; j++)
		{
			if (plist[j].ID > plist[j + 1].ID)
			{
				struct process temp = plist[j];
				plist[j] = plist[j + 1];
				plist[j + 1] = temp;
			}
		}
	}
	printf("\nID\tAT\tBT\tWT\tTAT\n");
	for (int i = 0; i < num; i++)
		printf("%d\t%d\t%d\t%d\t%d\n", plist[i].ID, plist[i].AT, plist[i].BT, plist[i].WT, plist[i].TAT);
	printf("AWT : %f\n", AWT);
	printf("ATAT : %f\n", ATAT);
}
