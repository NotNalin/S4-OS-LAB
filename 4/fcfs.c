#include <stdio.h>
#include <stdlib.h>
void main()
{
	struct process
	{
		int ID;
		int AT;
		int BT;
		int CT;
		int WT;
		int TAT;
	};
	int num, ID, AT, BT, TAT, CT, WT;
	printf("Enter number of processes : ");
	scanf("%d", &num);
	struct process plist[num];
	for (int i = 0; i < num; i++)
	{
		printf("\n");
		printf("enter id : ");
		scanf("%d", &ID);
		printf("enter BT : ");
		scanf("%d", &BT);
		printf("enter AT : ");
		scanf("%d", &AT);
		plist[i].ID = ID;
		plist[i].AT = AT;
		plist[i].BT = BT;
	}
	plist[0].CT = plist[0].BT + plist[0].AT;
	for (int i = 1; i < num; i++)
	{
		plist[i].CT = plist[i - 1].CT + plist[i].BT;
	}
	for (int i = 0; i < num; i++)
	{
		plist[i].TAT = plist[i].CT - plist[i].AT;
	}
	for (int i = 0; i < num; i++)
	{
		plist[i].WT = plist[i].TAT - plist[i].BT;
	}
	double AWT;
	for (int i = 0; i < num; i++)
	{
		AWT = AWT + plist[i].WT;
	}
	AWT = AWT / num;
	double ATAT;
	for (int i = 0; i < num; i++)
	{
		ATAT = ATAT + plist[i].TAT;
	}
	ATAT = ATAT / num;
	printf("ID\tAT\tBT\tWT\tTAT\n");
	for (int i = 0; i < num; i++)
	{
		printf("%d\t%d\t%d\t%d\t%d\n", plist[i].ID, plist[i].AT, plist[i].BT, plist[i].WT, plist[i].TAT);
	}
	printf("AWT : %f\n", AWT);
	printf("ATAT : %f\n", ATAT);
}
