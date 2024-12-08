#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct medicine
{
	int no;
	char name[100];
	char code[5];
	char mfg_date[50];
	char exp_date[50];
	float cost;
	float price;
};
void data_1();
void inventory_2();
void detail_3();
void filing_5();
void delete_6();

int main()
{
	FILE* fptr;
    char name [100];
    char code [5];
    int no;
    int sno;
    float total;
	int quantity;
	char choice; 
	int choice2;
	printf("\t\t\tFor better experience, view the program in full screen\n\n");
	printf("\t\t\t\tWelcome to Online-Pharmacy Portal\n");
	printf("\t\t\t\t---------------------------------\n");
	printf("\nAre you looking for a medicine? If yes then you have reached the right place.");
	printf("\nIf yes, please type 'Y':");
	printf("\nIf No,  please type 'N'\nEnter Choice : ");
	scanf("%c",&choice);
	while(choice!='N'||'n')
	{
	
	switch(choice)
	{
		case 'N': case 'n':
			printf("\n\nWell, It seems that you are all good.\nWe always welcome you if you need any assistance in your future.");
			printf("\nTake a good care of yours");
			printf("\n*****");
			return 0;
	
		case 'Y': case 'y':
			printf("\n\n");
			printf("---------------------------------\n");
			printf("Menu:\n");
			printf("1. Show Medicines List:\n");
			printf("2. Show Inventory:\n");
			printf("3. Show details of one specific medicine:\n");
			printf("4. Purchase\n");
			printf("5. Update the Inventory\n");
			printf("6. Delete Inventory\n");
			printf("7. Exit\n");
			scanf("%d",&choice2);
			printf("---------------------------------\n");
			if(choice2==1)
				{
						data_1();	
				}
			else if(choice2==2)
				{
					inventory_2();
				}
			else if(choice2==3)
				{
						data_1();
						detail_3();				
				}
			else if(choice2==4)	
				{
						data_1();
						printf("\n\nEnter S.No of the Medicine from the above List : ");
						scanf("%d",&sno);
						printf("Enter Code of the Medicine : ");
						scanf("%s", name);
						printf("Enter Quantity : ");
						scanf("%d", &quantity);
						int num;
						int i=0;
						FILE *ptr, *fptr;
						fptr=fopen("Num.txt","r");
						if (ptr == NULL)
							{
								printf("Error!");
								exit(1);
							}
						else
							{
								fscanf(fptr,"%d",&num);
							}
						fclose(fptr);
						struct medicine s[num];
						ptr=fopen("inventory.txt","r");
						if (ptr == NULL)
							{
								printf("Error!");
								exit(1);
							}
						else
							{
							for(i=0;i<num;i++)
								{
									fscanf(ptr,"%d %s %s %s %s %f %f", &s[i].no, s[i].name, s[i].code, s[i].mfg_date, s[i].exp_date, &s[i].cost, &s[i].price );
									if(sno == (i+1))
									{
										float total;
										total = quantity * s[i].price;
										printf("\n---------------------------------\n");
										printf("\n\nS.No\tName\t\t\tQuantity\t\tPrice\n\n");
										printf("\n%d\t%s\t\t\t%d\t\t\t%.2f",sno,s[i].name,quantity,total);	
									}
								}
						}
				}
			else if(choice2==5)
				{
					filing_5();
				}
			else if(choice2==6){
				delete_6();
			}
			else if(choice2==7)
						{
								printf("\nTHANK YOU FOR USING OUR PROGRAM.\nWE ALWAYS WELCOME YOU IF YOU NEED ANY ASSITANCE IN THE FUTURE");
								printf("\nTake a good care of yours");
								printf("\n*****");
								return 0;
						}
		}
	}
}
void data_1(){
	int no, num;
	char name[100];
	char code[5];
	char mfg_date[50];
	char exp_date[50];
	float cost;
	float price;
	int i=0;
	
	FILE *ptr, *fptr;
	fptr=fopen("Num.txt","r");
	if (ptr == NULL)
	{
		printf("Error!");
		exit(1);
	}
	else
	{
		fscanf(fptr,"%d",&num);
	}
	fclose(fptr);
	ptr=fopen("inventory.txt","r");
	if (ptr == NULL)
	{
		printf("Error!");
		exit(1);
	}
	else
	{
		struct medicine s[num];
	for(i=0;i<num;i++)
		{
			fscanf(ptr,"%d %s %s %s %s %f %f", &s[i].no, s[i].name, s[i].code, s[i].mfg_date, s[i].exp_date, &s[i].cost, &s[i].price );
		};
		for(i=0;i<num-1;i++)
		{
			printf("\n%d\t%s  %s", s[i].no, s[i].name, s[i].code);
		}
			fclose(ptr);
	}

}
void inventory_2(){
	int no,num;
	char name[100];
	char code[5];
	char mfg_date[50];
	char exp_date[50];
	float cost;
	float price;
	int i=0;
	
	FILE *ptr, *fptr;
	fptr=fopen("Num.txt","r");
	if (ptr == NULL)
	{
		printf("Error!");
		exit(1);
	}
	else
	{
		fscanf(fptr,"%d",&num);
	}
	fclose(fptr);
	ptr=fopen("inventory.txt","r");
	if (ptr == NULL)
	{
		printf("Error!");
		exit(1);
	}
	else
	{
		struct medicine s[num];
	for(i=0;i<num;i++)
		{
			fscanf(ptr,"%d %s %s %s %s %f %f", &s[i].no, s[i].name, s[i].code, s[i].mfg_date, s[i].exp_date, &s[i].cost, &s[i].price );
		}
			for(i=0;i<num-1;i++)
		{
			printf("\b\b%d\t%s %s\t\t\t%s\t%s\t%.2f\t%.2f\n", s[i].no,s[i].name,s[i].code,s[i].mfg_date,s[i].exp_date,s[i].cost,s[i].price);
		}
			fclose(ptr);
	}

}

void detail_3()
{
	int no,num;
	char name[100];
	char code[5];
	char mfg_date[50];
	char exp_date[50];
	float cost;
	float price;
	int i=0;
	struct medicine s[num];
	FILE *fptr;
	fptr=fopen("Num.txt","r");
	if (fptr == NULL)
	{
		printf("Error!");
		exit(1);
	}
	else
	{
		fscanf(fptr,"%d",&num);
	}
	fclose(fptr);
	FILE *ptr;
	ptr=fopen("inventory.txt","r");
	if (ptr == NULL)
	{
		printf("Error!");
		exit(1);
	}
	else
	{
	for(i=0;i<num;i++)
		{
			fscanf(ptr,"%d %s %s %s %s %f %f", &s[i].no, s[i].name, s[i].code, s[i].mfg_date, s[i].exp_date, &s[i].cost, &s[i].price );
		};
			fclose(ptr);
	}
	int n;
	printf("\n\nEnter medicine code:");
	scanf("%d",&n);
	printf("S.No\tName\t\t\tMFG Date\tExp Date\tCost\t\tPrice\n\n");
	for(i=0;i<num;i++)
	{
		if(n==s[i].no)
		{
		printf("\b\b%d\t%s %s\t\t\t%s\t%s\t%.2f\t\t%.2f\n", s[i].no,s[i].name,s[i].code,s[i].mfg_date,s[i].exp_date,s[i].cost,s[i].price);
		}
	}
	
}	
void filing_5()
	{
			FILE *fptr, *ptr;
			int count,num;
			ptr=fopen("Num.txt","r");
			if (ptr == NULL)
			{
				printf("Error!");
				exit(1);
			}
			else
			{
				fscanf(ptr,"%d",&num);
			}
			fclose(ptr);
			count = num;
			fptr=fopen("inventory.txt","a"); 
			if(fptr==NULL)
			{
				printf("Error");
				exit(1);
			}
			else
			{
				struct medicine s1;
				printf("\nEnter Name of the medicine : ");
				scanf("%s",s1.name);
				printf("\nEnter code of the medicine : ");
				scanf("%s",s1.code);
				printf("Enter MFG Date of the medicine : ");
				scanf("%s",s1.mfg_date);
				printf("Enter EXP Date : ");
				scanf("%s", s1.exp_date);
				printf("Enter Cost : ");
				scanf("%f", &s1.cost);
				printf("Enter Price : ");
				scanf("%f", &s1.price);
				fprintf(fptr,"%d\t%s %s\t\t\t%s\t%s\t%.2f\t%.2f\n",count,s1.name,s1.code,s1.mfg_date,s1.exp_date,s1.cost,s1.price);
				printf("\n\nInventory Updated");
				fclose(fptr);	   
				count++;
				ptr=fopen("Num.txt","w+");
				if (ptr == NULL)
				{
					printf("Error!");
					exit(1);
				}
				else
				{
					fprintf(ptr,"%d",count);
				}
				fclose(ptr);
				}
}
void delete_6(){
	int i,j,sno,cur_line=1,lno=0;
	printf("\nEnter serial number to delete: ");
	scanf("%d",&sno);
	FILE *ptr;
	ptr =fopen("Num.txt","r");
	int counter;
	if(ptr!=NULL){
		fscanf(ptr,"%d",&counter);
	}
	fclose (ptr);
	FILE *fptr;
	int no[counter];
	char name[counter-1][100];
	fptr=fopen("inventory.txt","r+");
	if(fptr!= NULL){
	printf("OLD LIST\n");
	for(i=0;i<(counter-1);i++){
		fscanf(fptr,"%d %[^\n]s",&no[i],name[i]);
		puts(name[i]);
	}}else{printf("ERROR!");
	}
	fclose(fptr);
	FILE *temp;
	temp=fopen("inventory.txt","w");
	if(temp!=NULL){
		printf("\n-------------------\nUpdated List: \n");
		for (j=0;j<(counter-1);j++,cur_line++){
			
			if(cur_line!=sno){
				lno++;	
				fprintf(temp,"%d\t%s\n",lno,name[j]);
			}
		}
	}else{printf("ERROR");
	}printf("%d",counter);
	
fclose(temp);
	counter--;
	ptr=fopen("Num.txt","w");
	fprintf(ptr,"%d",counter);
	fclose(ptr);
	
}
