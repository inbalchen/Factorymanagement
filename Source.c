#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define SIZE_FILE 20
typedef enum{ A = 1, B = 2, C = 3 } status;
typedef enum { First_name = 1, Last_name, City_of_residence, Phone, ID, Status }details;
typedef enum { Reports = 1, Add_employee, Delete_employee, Update_personal_details, Update_employeds_details, Treatment_malfunction, Order_products, Delete_products, Exit }maneger_opp;
typedef enum { REPORTS = 1, ADD_employee, dell_emploeey, Update_Personal_Details, Order_Products, Delete_Products, Customer_order, Delete_Customer_order, EXIT }secretary_opp;
typedef enum { FALSE = 0, TRUE = 1 } Boolean;
typedef enum{ reports = 1, Update_Personal_details, ADD_Constraints_employee, Treatment_MAlfunction, Resignation, Update_daily_product, Delleting_daily_product, Update_Constraints_employee, EXit }Employee_opp;
typedef enum { number_of_hours = 1, amount_of_Product }power_opp;
typedef enum{ Date_of_shift = 1, SIFTE }constraint_opp;
typedef struct
{
	char F_name[15];
	char L_name[20];
	char City[15];
	char Phone[20];
	char Id[15];
	char access;

}users;
typedef struct
{
	int num_order;
	char Name[25];
	int amount;
	char date[10];
	char status[4];
}inventory;
typedef struct
{
	int num_order;
	char Name_order[20];
	char amount_order[10];
	char price[10];
	char Name_client[10];
	char Address_client[20];
	char Phone_client[15];
	char date_order[10];
	char status_booking[2];
}orders;
typedef struct {
	char name_machin[10];
	char day_of_treat[10];
	char name_of_mechanic[20];
	char status_treat[2];
}Treatment;
typedef struct {
	char NAME_employee[15];
	char id_Employee[15];
	float num_of_hour;
	float amount_Of_Product;
}products;
typedef struct {
	char NAME_employee_shift[15];
	char id_Employee_shift[15];
	char date_shift[15];
	char shift[15];
}constraints;

void Count_Size_file(char *name, int *size);
int VerifyID(users *user, int* size);
void create(users* user, int* size, inventory *inventor, int* size2, orders *ordery, int* size3, Treatment *treat, int* size4, products *power, int* size5, constraints *constraint, int* size6);
int maneger_menu();
void add_employee(users* user, int *size);
void Dell_employee(users* user, int *size);
void Updating_personal_data(users* user, int *size);
void Update_Employeds_Details(users* user, int *size);
void order_products(inventory *inventor, int* size2, int *Num_order);
void Dell_Products(inventory *inventor, int* size2);
void PrintReport(inventory *inventor, int* size2, orders *ordery, int* size3);
void Treatment_Malfunction(Treatment *treat, int* size4);
int secretary_menu();
void Report_secretary(users* user, int *size, orders *ordery, int* size3);
void add_booking(orders *ordery, int* size3, int *Num_booking);
void dell_booking(orders *ordery, int* size3);
int Employee_menu();
void Report_Employee(products *power, int* size5, Treatment *treat, int* size4);
void UPdate_daily_product(products *power, int* size5);
void DELLET_daily_product(products *power, int* size5);
void Add_Constraints_employee(constraints *constraint, int* size6);
void UPdate_Constraints_Employee(constraints *constraint, int* size6);

int main()
{
	users *user;
	inventory *inventor;
	orders *ordery;
	Treatment *treat;
	products *power;
	constraints *constraint;
	int size = 0, size2 = 0, size3 = 0, size4 = 0, size5 = 0, size6 = 0, Num_order = 1000, Num_booking = 110, ok = 1;

	Count_Size_file("users.txt", &size);
	user = (users*)malloc(size*sizeof(users));
	Count_Size_file("inventory.txt", &size2);
	inventor = (inventory*)malloc(size2*sizeof(inventory));
	Count_Size_file("order.txt", &size3);
	ordery = (orders*)malloc(size3*sizeof(orders));
	Count_Size_file("Treatments.txt", &size4);
	treat = (Treatment*)malloc(size4*sizeof(Treatment));
	Count_Size_file("product.txt", &size5);
	power = (products*)malloc(size5*sizeof(products));
	Count_Size_file("constraints.txt", &size6);
	constraint = (constraints*)malloc(size6*sizeof(constraints));
	if (user == NULL || inventor == NULL || ordery == NULL || treat == NULL || power == NULL || constraint == NULL)
		printf("Can not allocation  Memory\n");
	else
	{
		create(user, &size, inventor, &size2, ordery, &size3, treat, &size4, power, &size5, constraint, &size6);
		switch (VerifyID(user, &size))
		{
		case 'A':case 'a':
		{
					 while (ok){
						 switch (maneger_menu())
						 {
						 case Reports:PrintReport(inventor, &size2, ordery, &size3); break;
						 case Add_employee: add_employee(user, &size); break;
						 case Delete_employee:Dell_employee(user, &size); break;
						 case Update_personal_details: Updating_personal_data(user, &size); break;
						 case Update_employeds_details: Update_Employeds_Details(user, &size); break;
						 case Treatment_malfunction:Treatment_Malfunction(treat, &size4); break;
						 case Order_products:order_products(inventor, &size2, &Num_order); break;
						 case Delete_products:Dell_Products(inventor, &size2); break;
						 case Exit:printf("Have a nice day:)\n"); ok = 0; break;
						 }
						 break;
					 }
		}
		case 'B':case 'b':
		{
					 while (ok){
						 switch (secretary_menu())
						 {
						 case REPORTS:Report_secretary(user, &size, ordery, &size3); break;
						 case ADD_employee: add_employee(user, &size); break;
						 case dell_emploeey:Dell_employee(user, &size); break;
						 case Update_Personal_Details: Updating_personal_data(user, &size); break;
						 case Order_Products:order_products(inventor, &size2, &Num_order); break;
						 case Delete_Products:Dell_Products(inventor, &size2); break;
						 case Customer_order:add_booking(ordery, &size3, &Num_booking); break;
						 case Delete_Customer_order:dell_booking(ordery, &size3); break;
						 case EXIT:printf("Have a nice day:)\n"); ok = 0; break;
						 }
						 break;
					 }
		}
		case 'C':case'c':
		{
					 while (ok){
						 switch (Employee_menu())
						 {
						 case reports:Report_Employee(power, &size5, treat, &size4); break;
						 case Update_Personal_details: Updating_personal_data(user, &size); break;
						 case ADD_Constraints_employee:Add_Constraints_employee(constraint, &size6); break;
						 case Treatment_MAlfunction:Treatment_Malfunction(treat, &size4); break;
						 case Resignation: Dell_employee(user, &size); ok = 0; break;
						 case Update_daily_product:UPdate_daily_product(power, &size5); break;
						 case Delleting_daily_product: DELLET_daily_product(power, &size5); break;
						 case Update_Constraints_employee:UPdate_Constraints_Employee(constraint, &size6); break;
						 case EXit:printf("Have a nice day:)\n"); ok = 0; break;
						 }
						 break;
					 }
		}
		}
	}
	return 0;
}

int VerifyID(users *user, int* size)
{
	int  i, ok = 1, go_on, count = 0;
	char status_acsses, check_ID[15];
	while (ok)
	{
		count = 0;
		printf("Dear user please enter ID to Login:\n");
		scanf("%s", &check_ID);
		for (i = 0; i < (*size); i++)
		{
			if (strcmp(check_ID, user[i].Id) == 0)
			{
				status_acsses = user[i].access;
				ok = 0;
				return status_acsses;
			}
			else
				count++;
		}
		if (count == *size)
		{
			printf("ID not existed!!\n");
			printf("Do you want to try again?(1-YES/2-NO)\n");
			scanf("%d", &go_on);
			if (go_on == 2)
			{
				ok = 0;
				break;
			}
		}
	}
	return 0;
}
void create(users* user, int* size, inventory *inventor, int* size2, orders *ordery, int* size3, Treatment *treat, int* size4, products *power, int* size5, constraints *constraint, int* size6)
{
	FILE *Fptr, *fp, *fp3, *fp4, *fp5, *fp6;
	int i;

	printf("WELCOME TO REDIMIX\n----------------\n");
	if ((Fptr = fopen("users.txt", "r+")) == NULL)
		printf("error can not open file\n");
	else
	{
		for (i = 0; i < (*size); i++)
		{
			fscanf(Fptr, "%s %s %s %s %s %c", &user[i].F_name, &user[i].L_name, &user[i].City, &user[i].Phone, &user[i].Id, &user[i].access);
			//printf("%s %s %s %s %s %c\n", user[i].F_name, user[i].L_name, user[i].City, user[i].Phone, user[i].Id, user[i].access);
		}
		fclose(Fptr);
	}

	if ((fp = fopen("inventory.txt", "r+")) == NULL)
		printf("error can not openned file\n");
	else
	{
		for (i = 0; i < (*size2); i++)
		{
			fscanf(fp, "%d %s %d %s %s", &inventor[i].num_order, &inventor[i].Name, &inventor[i].amount, &inventor[i].date, &inventor[i].status);
			//printf("%d %s %d %s %s\n", inventor[i].num_order, inventor[i].Name, inventor[i].amount, inventor[i].date, inventor[i].status);
		}
		fclose(fp);
	}

	if ((fp3 = fopen("order.txt", "r+")) == NULL)
		printf("error can not openned file\n");
	else
	{
		for (i = 0; i < (*size3); i++)
		{
			fscanf(fp3, "%d %s %s %s %s %s %s %s %s", &ordery[i].num_order, &ordery[i].Name_order, &ordery[i].amount_order, &ordery[i].price, &ordery[i].Name_client, &ordery[i].Address_client, &ordery[i].Phone_client, &ordery[i].date_order, &ordery[i].status_booking);
			//printf("%d %s %s %s %s %s %s %s %s\n", ordery[i].num_order, ordery[i].Name_order, ordery[i].amount_order, ordery[i].price, ordery[i].Name_client, ordery[i].Address_client, ordery[i].Phone_client, ordery[i].date_order, ordery[i].status_booking);
		}
		fclose(fp3);
	}

	if ((fp4 = fopen("Treatments.txt", "r+")) == NULL)
		printf("error can not openned file\n");
	else
	{
		for (i = 0; i < (*size4); i++)
		{
			fscanf(fp4, "%s %s %s %s", &treat[i].name_machin, &treat[i].day_of_treat, &treat[i].name_of_mechanic, &treat[i].status_treat);
			//printf("%s %s %s %s \n", treat[i].name_machin, treat[i].day_of_treat, treat[i].name_of_mechanic, treat[i].status_treat);
		}
		fclose(fp4);
	}

	if ((fp5 = fopen("product.txt", "r+")) == NULL)
		printf("error can not open file\n");
	else
	{
		for (i = 0; i < (*size5); i++)
		{
			fscanf(fp5, "%s %s %f %f", &power[i].NAME_employee, &power[i].id_Employee, &power[i].num_of_hour, &power[i].amount_Of_Product);
			//printf("%s %s %3f %f\n", power[i].NAME_employee, power[i].id_Employee, power[i].num_of_hour, power[i].amount_Of_Product);
		}
		fclose(fp5);
	}
	if ((fp6 = fopen("constraints.txt", "r+")) == NULL)
		printf("error can not open file\n");
	else
	{
		for (i = 0; i < (*size6); i++)
		{
			fscanf(fp6, "%s %s %s %s ", &constraint[i].NAME_employee_shift, &constraint[i].id_Employee_shift, &constraint[i].date_shift, &constraint[i].shift);
			//printf("%s %s %s %s \n", constraint[i].NAME_employee_shift, constraint[i].id_Employee_shift, constraint[i].date_shift, constraint[i].shift);
		}
		fclose(fp6);
	}

}
int maneger_menu()
{
	int menu_choice = 0;
	do{
		printf("Welcome Dear Manager\n---------------------\n");
		printf("Please enter your choice\n");
		printf("(1)reports\n");
		printf("(2)Add employee\n");
		printf("(3)Delete employee\n");
		printf("(4)Update personal details\n");
		printf("(5)Update employed's details\n");
		printf("(6)Treatment malfunction\n");
		printf("(7)Order products\n");
		printf("(8)Delete products\n");
		printf("(9)Exit\n");
		scanf("%d", &menu_choice);
		if (menu_choice < 1 || menu_choice>9)
			printf("***Select NOT in range!Try again***\n");

	} while (menu_choice<1 || menu_choice>9);

	return menu_choice;
}
void add_employee(users* user, int *size)
{
	FILE *Fptr;
	int newsize = (*size);

	user = (users*)realloc(user, 1 * sizeof(users));
	if (user == NULL)
		printf("Error");
	else
	{
		Fptr = fopen("users.txt", "a+");
		if (Fptr == NULL)
			printf("error can not openned file\n");
		else
		{
			printf("Employee details\n----------------\n");
			newsize += 1;
			printf("Enter First name:");
			scanf("%s", &user[newsize].F_name);
			printf("Enter Last name:");
			scanf("%s", &user[newsize].L_name);
			printf("Enter City of residence:");
			scanf("%s", &user[newsize].City);
			printf("Enter Phone:");
			scanf("%s", &user[newsize].Phone);
			printf("Enter ID:");
			scanf("%s", &user[newsize].Id);
			printf("Enter status (A/B/C):");
			scanf("%s", &user[newsize].access);
			getchar();
			printf("%s %s %s %s %s %c\n", user[newsize].F_name, user[newsize].L_name, user[newsize].City, user[newsize].Phone, user[newsize].Id, user[newsize].access);
			fprintf(Fptr, "%s %s %s %s %s %c\n", user[newsize].F_name, user[newsize].L_name, user[newsize].City, user[newsize].Phone, user[newsize].Id, user[newsize].access);
		}
		fclose(Fptr);
		*size = newsize;
	}
}
void Dell_employee(users* user, int *size)
{
	FILE *Fptr;
	int i = 0, size1 = 0, check = 0;
	char line[255], del_id[15];

	if ((Fptr = fopen("users.txt", "w+")) == NULL)
		printf("error can not openned file\n");
	else
	{
		do
		{
			printf("Enter id employee for delete:\n");
			scanf("%s", &del_id);
			for (i = 0; i < *size; i++)
			{
				if (strcmp(user[i].Id, del_id) == 1)
				{
					fprintf(Fptr, "%s %s %s %s %s %c\n", user[i].F_name, user[i].L_name, user[i].City, user[i].Phone, user[i].Id, user[i].access);
					check++;

				}
			}
			if (check == (*size))
				printf("ID Not found in the database!!\nTry again\n");
			else
				printf("***Cancellation employee is successfully updated***\n");
		} while (check == (*size));
	}
	fclose(Fptr);
	/**copy from file too struct**/
	if ((Fptr = fopen("users.txt", "r+")) == NULL)
		printf("error can not openned file\n");
	else
	{
		while (fgets(line, 255, Fptr) != NULL)      /*count of line in file*/
			size1++;

		fclose(Fptr);
		if ((Fptr = fopen("users.txt", "r+")) == NULL)
			printf("error can not openned file\n");
		else
		{
			user = (users*)malloc(size1*sizeof(users));
			for (i = 0; i < size1; i++)
			{
				fscanf(Fptr, "%s %s %s %s %s %c", &user[i].F_name, &user[i].L_name, &user[i].City, &user[i].Phone, &user[i].Id, &user[i].access);
				printf("%s %s %s %s %s %c\n", user[i].F_name, user[i].L_name, user[i].City, user[i].Phone, user[i].Id, user[i].access);
			}
		}
		*size = size1;
		fclose(Fptr);
	}

}
void Updating_personal_data(users* user, int *size)
{
	FILE *Fptr;
	int choice = 0, i = 0, check = 0, go_on = 1;
	char id_conf[15];
	do
	{
		printf("Pleaes enter ID to verification:\n");
		scanf("%s", &id_conf);
		for (i = 0; i < *size; i++)
		{
			if (strcmp(id_conf, user[i].Id) == 0)
			{
				check = TRUE;
				do
				{
					printf("Dear user What do you want to change in your personal details:\n");
					printf("(1)First name\n");
					printf("(2)Last name\n");
					printf("(3)City of residence\n");
					printf("(4)Phone\n");
					scanf("%d", &choice);
					if (choice != 1 && choice != 2 && choice != 3 && choice != 4)
					{
						printf("ERROR---> Do you want to Try again?(1-YES/2-NO)\n");
						scanf("%d", &go_on);
						if (go_on == 2)
							break;
					}
				} while (go_on != 1);

				switch (choice)
				{
				case First_name:
				{
								   printf("Enter First name:\n");
								   scanf("%s", &user[i].F_name);
								   break;
				}
				case Last_name:
				{
								  printf("Enter Last name:\n");
								  scanf("%s", &user[i].L_name);
								  break;
				}
				case City_of_residence:
				{
										  printf("Enter City of residence:\n");
										  scanf("%s", &user[i].City);
										  break;
				}
				case Phone:
				{
							  printf("Enter Phone:\n");
							  scanf("%s", &user[i].Phone);
							  break;
				}
				default:
					break;
				}


				if ((Fptr = fopen("users.txt", "w+")) == NULL)
					printf("error can not openned file\n");
				else
				{
					for (i = 0; i < *size; i++)
					{
						fprintf(Fptr, "%s %s %s %s %s %c\n", user[i].F_name, user[i].L_name, user[i].City, user[i].Phone, user[i].Id, user[i].access);
						printf("%s %s %s %s %s %c\n", user[i].F_name, user[i].L_name, user[i].City, user[i].Phone, user[i].Id, user[i].access);
					}
				}
			}
		}
		if (check != TRUE)
		{
			printf("No existent ID!!\nDo you want to try again? (1-YES/ 2-NO)\n");
			scanf("%d", &go_on);
			if (go_on == 2)
				break;
		}
	} while (check != TRUE);

}
void Update_Employeds_Details(users* user, int *size)
{
	FILE *Fptr;
	int choice = 0, i = 0, check = 0, go_on = 1;
	char id_employee[15];
	do
	{
		printf("Dear Manager enter ID employee that you want to uptate:\n");
		scanf("%s", &id_employee);
		for (i = 0; i < *size; i++)
		{
			if (strcmp(id_employee, user[i].Id) == 0)
			{
				check = TRUE;
				do
				{
					printf("Dear user What do you want to change in your personal details:\n");
					printf("(1)First name\n");
					printf("(2)Last name\n");
					printf("(3)City of residence\n");
					printf("(4)Phone\n");
					printf("(5)ID\n");
					printf("(6)Status\n");

					scanf("%d", &choice);
					if (choice != 1 && choice != 2 && choice != 3 && choice != 4 && choice != 5 && choice != 6)
					{
						printf("ERROR---> Doo you want to Try again?(1-YES/2-NO)\n");
						scanf("%d", &go_on);
						if (go_on == 2)
							break;
					}
				} while (go_on != 1);

				switch (choice)
				{
				case First_name:
				{
								   printf("Enter First name:\n");
								   scanf("%s", &user[i].F_name);
								   break;
				}
				case Last_name:
				{
								  printf("Enter Last name:\n");
								  scanf("%s", &user[i].L_name);
								  break;
				}
				case City_of_residence:
				{
										  printf("Enter City of residence:\n");
										  scanf("%s", &user[i].City);
										  break;
				}
				case Phone:
				{
							  printf("Enter Phone:\n");
							  scanf("%s", &user[i].Phone);
							  break;
				}
				case ID:
				{
						   printf("Enter ID:\n");
						   scanf("%s", &user[i].Id);
						   break;
				}
				case Status:
				{
							   printf("Enter Status:\n");
							   //_flushall();
							   getchar();
							   scanf("%c", &user[i].access);
							   getchar();
							   break;
				}
				default:
					break;
				}


				if ((Fptr = fopen("users.txt", "w+")) == NULL)
					printf("error can not openned file\n");
				else
				{
					for (i = 0; i < *size; i++)
					{
						fprintf(Fptr, "%s %s %s %s %s %c\n", user[i].F_name, user[i].L_name, user[i].City, user[i].Phone, user[i].Id, user[i].access);
						printf("%s %s %s %s %s %c\n", user[i].F_name, user[i].L_name, user[i].City, user[i].Phone, user[i].Id, user[i].access);
					}
				}
			}
		}
		if (check != TRUE)
		{
			printf("No existent ID!!\nDo you want to try again? (1-YES/ 2-NO)\n");
			scanf("%d", &go_on);
			if (go_on == 2)
				break;
		}
	} while (check != TRUE);

}
void order_products(inventory *inventor, int* size2, int *Num_order)
{
	FILE *fp;
	int newsize = (*size2);
	if ((fp = fopen("inventory.txt", "a+")) == NULL)
		printf("error can not openned file\n");
	else
	{
		(*Num_order) += 1;
		newsize += 1;
		inventor = (inventory*)realloc(inventor, 1 * sizeof(inventory));
		printf("Orders details\n----------------\n");

		printf("Enter amount of products:");
		scanf("%d", &inventor[newsize].amount);
		printf("Enter date of orders:");
		scanf("%s", &inventor[newsize].date);
		printf("Enter name of products:");
		scanf("%s", &inventor[newsize].Name);
		printf("Enter status of orders (in/out):");
		scanf("%s", &inventor[newsize].status);
		inventor[newsize].num_order = *Num_order;

		printf("***Your order was successful***\nNum of order=> %d\n", *Num_order);
		printf("%d %s %d %s %s\n", inventor[newsize].num_order, inventor[newsize].Name, inventor[newsize].amount, inventor[newsize].date, inventor[newsize].status);
		fprintf(fp, "%d %s %d %s %s\n", inventor[newsize].num_order, inventor[newsize].Name, inventor[newsize].amount, inventor[newsize].date, inventor[newsize].status);
	}
	fclose(fp);
	*size2 = newsize;
	//return 1;
}
void Dell_Products(inventory *inventor, int* size2)
{
	FILE *fp;
	int i = 0, size1 = 0, del_order = 0, check = 0;
	char line[255];

	if ((fp = fopen("inventory.txt", "w+")) == NULL)
		printf("error can not openned file\n");
	else
	{
		do{
			printf("Enter number of order for delete:\n");
			scanf("%d", &del_order);
			for (i = 0; i < *size2; i++)
			{
				if (inventor[i].num_order != del_order)
				{
					fprintf(fp, "%d %s %d %s %s\n", inventor[i].num_order, inventor[i].Name, inventor[i].amount, inventor[i].date, inventor[i].status);
					check++;
				}
			}
			if (check == (*size2))
				printf("Num order Not found in the database!!\nTry again\n");
			else
				printf("***Cancellation of order Products is successfully updated***\n");
		} while (check == (*size2));
	}
	fclose(fp);
	/**copy from file too struct**/
	if ((fp = fopen("inventory.txt", "r+")) == NULL)
		printf("error can not openned file\n");
	else
	{
		while (fgets(line, 255, fp) != NULL)      /*count of line in file*/
			size1++;

		fclose(fp);
		if ((fp = fopen("inventory.txt", "r+")) == NULL)
			printf("error can not openned file\n");
		else
		{
			inventor = (inventory*)malloc(size1*sizeof(inventory));
			for (i = 0; i < size1; i++)
			{
				fscanf(fp, "%d %s %d %s %s", &inventor[i].num_order, &inventor[i].Name, &inventor[i].amount, &inventor[i].date, &inventor[i].status);
				printf("%d %s %d %s %s \n", inventor[i].num_order, inventor[i].Name, inventor[i].amount, inventor[i].date, inventor[i].status);

			}
		}

	}
	*size2 = size1;
	fclose(fp);
	//return 1;
}
void Count_Size_file(char *name_file, int *size)
{
	FILE *Fptr;
	char line[255];

	if ((Fptr = fopen(name_file, "r+")) == NULL)
		printf("error can not openned file\n");
	else
	{
		while (fgets(line, 255, Fptr) != NULL)      /*count of line in file*/
			(*size)++;
		fclose(Fptr);
	}
}
void PrintReport(inventory *inventor, int* size2, orders *ordery, int* size3)
{
	int report_choose = 0, go_on = 0, choice = 0, i = 0;
	char status_in[] = { "in" }, status_out[] = { "out" };


	do
	{
		printf("Dear Maneger which Report you want to print\n");
		printf("(1)inventory in\n");
		printf("(2)inventory out\n");
		printf("(3)general orders\n");
		printf("(4)exit\n");
		scanf("%d", &report_choose);
		if (report_choose == 1)
		{
			for (i = 0; i < *size2; i++)
			{
				if ((strcmp(inventor[i].status, status_in)) == 0)
					printf("%s %d %s %s\n", inventor[i].Name, inventor[i].amount, inventor[i].date, inventor[i].status);
			}
		}
		else if (report_choose == 2)
		{
			for (i = 0; i < *size2; i++)
			{
				if ((strcmp(inventor[i].status, status_out)) == 0)
					printf("%s %d %s %s\n", inventor[i].Name, inventor[i].amount, inventor[i].date, inventor[i].status);
			}
		}
		else if (report_choose == 3)
		{
			for (i = 0; i < *size3; i++)
			{
				printf("%d %s %s %s %s %s %s %s %s \n", ordery[i].num_order, ordery[i].Name_order, ordery[i].amount_order, ordery[i].price, ordery[i].Name_client, ordery[i].Address_client, ordery[i].Phone_client, ordery[i].date_order, ordery[i].status_booking);
			}
		}
		else if (report_choose == 4)
		{
			break;
		}
		else
		{
			printf("ERROR---> Doo you want to Try again?(1-YES/2-NO)\n");
			scanf("%d", &go_on);
			if (go_on == 2)
				break;
		}
	} while (go_on != 2);
}
void Treatment_Malfunction(Treatment *treat, int* size4)
{
	FILE *fp4;
	int i, check = 0, go_on = 1;
	char choice[10];

	do
	{
		fp4 = fopen("Treatments.txt", "r+");
		if (fp4 == NULL)
			printf("error can not openned file\n");
		else
		{
			printf("Dear Manager/Employee enter name of machin that you want to treat:\n");
			for (i = 0; i < *size4; i++)
				printf("Machin %d: %s\n", i + 1, treat[i].name_machin);
			scanf("%s", &choice);
			fclose(fp4);
			fp4 = fopen("Treatments.txt", "r+");
			if (fp4 == NULL)
				printf("error can not openned file\n");
			else
			{
				check = 0;
				for (i = 0; i < *size4; i++)
				{
					if ((strcmp(treat[i].name_machin, choice)) == 0)
					{
						printf("Dear Manager/Employee enter your name: ");
						scanf("%s", &treat[i].name_of_mechanic);
						printf("Enter day of treatment: ");
						scanf("%s", &treat[i].day_of_treat);
						printf("Enter Status (Y=treat/N=not treat): ");
						scanf("%s", &treat[i].status_treat);
					}
					else
						check++;
				}
				if (check == *size4)
				{
					printf("A machine doesn't exist!\nDo you want to try again?(1=no)\n");
					scanf("%d", &go_on);
					if (go_on == 1)
						break;
				}
			}

		}
	} while (go_on != 1);
	fclose(fp4);
	fp4 = fopen("Treatments.txt", "w+");
	if (fp4 == NULL)
		printf("error can not openned file\n");
	else
	{
		for (i = 0; i < *size4; i++)
		{
			printf("%s %s %s %s\n", treat[i].name_machin, treat[i].day_of_treat, treat[i].name_of_mechanic, treat[i].status_treat);
			fprintf(fp4, "%s %s %s %s\n", treat[i].name_machin, treat[i].day_of_treat, treat[i].name_of_mechanic, treat[i].status_treat);
		}
	}
	fclose(fp4);
}
int secretary_menu()
{
	int menu_choice = 0;
	do{
		printf("Welcome Dear Secretary:\n---------------------\n");
		printf("Please enter your choice\n");
		printf("(1)reports\n");
		printf("(2)Add employee\n");
		printf("(3)Delete employee\n");
		printf("(4)Update personal details\n");
		printf("(5)Order products\n");
		printf("(6)Delete products\n");
		printf("(7)Customer order\n");
		printf("(8)Delete Customer order\n");
		printf("(9)Exit\n");
		scanf("%d", &menu_choice);
		if (menu_choice < 1 || menu_choice>9)
			printf("***Select NOT in range!Try again***\n");

	} while (menu_choice<1 || menu_choice>9);

	return menu_choice;
}
void Report_secretary(users* user, int *size, orders *ordery, int* size3)
{
	int report_choose = 0, go_on = 0, choice = 0, i = 0;
	char status_treat[] = { "Y" }, status_no_treat[] = { "N" };
	do
	{
		printf("Dear Secretary which Report you want to print\n");
		printf("(1)Bookings handled\n");
		printf("(2)Bookings not yet treated\n");
		printf("(3)Employee information\n");
		printf("(4)exit\n");
		scanf("%d", &report_choose);
		if (report_choose == 1)
		{
			for (i = 0; i < *size3; i++)
			{
				if ((strcmp(ordery[i].status_booking, status_treat)) == 0)
					printf("%d %s %s %s %s %s %s %s %s \n", ordery[i].num_order, ordery[i].Name_order, ordery[i].amount_order, ordery[i].price, ordery[i].Name_client, ordery[i].Address_client, ordery[i].Phone_client, ordery[i].date_order, ordery[i].status_booking);
			}
		}
		else if (report_choose == 2)
		{
			for (i = 0; i < *size3; i++)
			{
				if ((strcmp(ordery[i].status_booking, status_no_treat)) == 0)
					printf("%d %s %s %s %s %s %s %s %s \n", ordery[i].num_order, ordery[i].Name_order, ordery[i].amount_order, ordery[i].price, ordery[i].Name_client, ordery[i].Address_client, ordery[i].Phone_client, ordery[i].date_order, ordery[i].status_booking);
			}
		}
		else if (report_choose == 3)
		{
			for (i = 0; i < *size; i++)
			{
				printf("%s %s %s %s %s %c\n", user[i].F_name, user[i].L_name, user[i].City, user[i].Phone, user[i].Id, user[i].access);
			}
		}
		else if (report_choose == 4)
		{
			break;
		}
		else
		{
			printf("ERROR---> Doo you want to Try again?(1-YES/2-NO)\n");
			scanf("%d", &go_on);
			if (go_on == 2)
				break;
		}
	} while (go_on != 2);
}
void add_booking(orders *ordery, int* size3, int *Num_booking)
{
	FILE *fp;
	int newsize = (*size3);
	if ((fp = fopen("order.txt", "a+")) == NULL)
		printf("error can not openned file\n");
	else
	{
		(*Num_booking) += 1;
		newsize += 1;
		ordery = (orders*)realloc(ordery, 1 * sizeof(orders));
		printf("Booking details\n----------------\n");
		ordery[newsize].num_order = *Num_booking;
		printf("Enter name of products(white_cement): ");
		scanf("%s", &ordery[newsize].Name_order);
		printf("Enter amount of products: ");
		scanf("%s", &ordery[newsize].amount_order);
		printf("Enter price:");
		scanf("%s", &ordery[newsize].price);
		printf("Enter name of client: ");
		scanf("%s", &ordery[newsize].Name_client);
		printf("Enter address of client: ");
		scanf("%s", &ordery[newsize].Address_client);
		printf("Enter phone of client: ");
		scanf("%s", &ordery[newsize].Phone_client);
		printf("Enter date of booking (d/m/y): ");
		scanf("%s", &ordery[newsize].date_order);
		printf("Enter status of booking (Y=done/N=not done): ");
		scanf("%s", &ordery[newsize].status_booking);

		printf("***Your booking was successful***\nNum of => %d\n", *Num_booking);
		printf("%d %s %s %s %s %s %s %s %s\n", ordery[newsize].num_order, ordery[newsize].Name_order, ordery[newsize].amount_order, ordery[newsize].price, ordery[newsize].Name_client, ordery[newsize].Address_client, ordery[newsize].Phone_client, ordery[newsize].date_order, ordery[newsize].status_booking);
		fprintf(fp, "%d %s %s %s %s %s %s %s %s\n", ordery[newsize].num_order, ordery[newsize].Name_order, ordery[newsize].amount_order, ordery[newsize].price, ordery[newsize].Name_client, ordery[newsize].Address_client, ordery[newsize].Phone_client, ordery[newsize].date_order, ordery[newsize].status_booking);
	}
	fclose(fp);
	*size3 = newsize;
}
void dell_booking(orders *ordery, int* size3)
{
	FILE *fp;
	int i = 0, size1 = 0, del_order = 0, check = 0;
	char line[255];

	if ((fp = fopen("order.txt", "r+")) == NULL)
		printf("error can not openned file\n");
	else
	{
		do{
			printf("Enter number of booking for delete:\n");
			for (i = 0; i < *size3; i++)
			{
				printf("%d %s %s %s %s %s %s %s %s\n", ordery[i].num_order, ordery[i].Name_order, ordery[i].amount_order, ordery[i].price, ordery[i].Name_client, ordery[i].Address_client, ordery[i].Phone_client, ordery[i].date_order, ordery[i].status_booking);
			}
			scanf("%d", &del_order);
			fclose(fp);
			if ((fp = fopen("order.txt", "w+")) == NULL)
				printf("error can not openned file\n");

			for (i = 0; i < *size3; i++)
			{
				if (ordery[i].num_order != del_order)
				{
					fprintf(fp, "%d %s %s %s %s %s %s %s %s\n", ordery[i].num_order, ordery[i].Name_order, ordery[i].amount_order, ordery[i].price, ordery[i].Name_client, ordery[i].Address_client, ordery[i].Phone_client, ordery[i].date_order, ordery[i].status_booking);
					check++;
				}
			}
			if (check == (*size3))
				printf("Num booking Not found in the database!!\nTry again\n");
			else
				printf("***Cancellation of booking is successfully updated***\n");
		} while (check == (*size3));
	}
	fclose(fp);
	/**copy from file too struct**/
	if ((fp = fopen("order.txt", "r+")) == NULL)
		printf("error can not openned file\n");
	else
	{
		while (fgets(line, 255, fp) != NULL)      /*count of line in file*/
			size1++;

		fclose(fp);
		if ((fp = fopen("order.txt", "r+")) == NULL)
			printf("error can not openned file\n");
		else
		{
			ordery = (orders*)malloc(size1*sizeof(orders));
			for (i = 0; i < size1; i++)
			{
				fscanf(fp, "%d %s %s %s %s %s %s %s %s", &ordery[i].num_order, &ordery[i].Name_order, &ordery[i].amount_order, &ordery[i].price, &ordery[i].Name_client, &ordery[i].Address_client, &ordery[i].Phone_client, &ordery[i].date_order, &ordery[i].status_booking);
				printf("%d %s %s %s %s %s %s %s %s\n", ordery[i].num_order, ordery[i].Name_order, ordery[i].amount_order, ordery[i].price, ordery[i].Name_client, ordery[i].Address_client, ordery[i].Phone_client, ordery[i].date_order, ordery[i].status_booking);
			}
		}
	}
	*size3 = size1;
	fclose(fp);
}
int Employee_menu()
{
	int menu_choice = 0;
	do{
		printf("Welcome Dear Employee:\n---------------------\n");
		printf("Please enter your choice\n");
		printf("(1)reports\n");
		printf("(2)Update personal details\n");
		//	printf("(3)Treatment malfunction\n");
		printf("(4)Treatment malfunction\n");
		printf("(5)Resignation\n");
		printf("(6)Update daily product\n");
		printf("(7)Inventory check\n");
		printf("(8)Messages\n");
		printf("(9)Exit\n");
		scanf("%d", &menu_choice);
		if (menu_choice < 1 || menu_choice>9)
			printf("***Select NOT in range!Try again***\n");

	} while (menu_choice<1 || menu_choice>9);

	return menu_choice;
}
void Report_Employee(products *power, int* size5, Treatment *treat, int* size4)
{
	int report_choose = 0, go_on = 0, choice = 0, i = 0, check = 0;
	char status_treat[] = { "Y" }, status_no_treat[] = { "N" }, id_conf[15];

	do
	{
		printf("Dear Secretary which Report you want to print\n");
		printf("(1)Power report\n");
		printf("(2)Custom Power report \n");
		printf("(3)Treatment report\n");
		printf("(4)exit\n");
		scanf("%d", &report_choose);
		if (report_choose == 1)
		{
			for (i = 0; i < *size5; i++)
			{
				printf("%s %s %3f %f\n", power[i].NAME_employee, power[i].id_Employee, power[i].num_of_hour, power[i].amount_Of_Product);
			}
		}
		else if (report_choose == 2)
		{
			do{
				printf("Pleaes enter ID to verification:\n");
				scanf("%s", &id_conf);
				for (i = 0; i < *size5; i++)
				{
					if (strcmp(id_conf, power[i].id_Employee) == 0)
					{
						check = TRUE;
						printf("%s %s %3f %f\n", power[i].NAME_employee, power[i].id_Employee, power[i].num_of_hour, power[i].amount_Of_Product);
					}
				}
				if (check != TRUE)
				{
					printf("No existent ID!!\nDo you want to try again? (1-YES/ 2-NO)\n");
					scanf("%d", &go_on);
					if (go_on == 2)
						break;
				}
			} while (check != TRUE);
		}
		else if (report_choose == 3)
		{
			for (i = 0; i < *size4; i++)
			{
				printf("%s %s %s %s\n", treat[i].name_machin, treat[i].day_of_treat, treat[i].name_of_mechanic, treat[i].status_treat);
			}
		}
		else if (report_choose == 4)
		{
			break;
		}
		else
		{
			printf("ERROR---> Doo you want to Try again?(1-YES/2-NO)\n");
			scanf("%d", &go_on);
			if (go_on == 2)
				break;
		}
	} while (go_on != 2);
}
void UPdate_daily_product(products *power, int* size5)
{
	FILE *Fptr;
	int choice = 0, i = 0, check = 0, go_on = 1;
	char id_employee[15];
	do
	{
		printf("Dear Manager enter ID employee that you want to uptate:\n");
		scanf("%s", &id_employee);
		for (i = 0; i < *size5; i++)
		{
			if (strcmp(id_employee, power[i].id_Employee) == 0)
			{
				check = TRUE;
				do
				{
					printf("Dear user What do you want to change in your personal power:\n");
					printf("(1)number of hours\n");
					printf("(2)amount of Product\n");

					scanf("%d", &choice);
					if (choice != 1 || choice != 2)
					{
						printf("ERROR---> Doo you want to Try again?(1-YES/2-NO)\n");
						scanf("%d", &go_on);
						if (go_on == 2)
							break;
					}
				} while (go_on != 1);

				switch (choice)
				{
				case number_of_hours:
				{
										printf("Enter number of hours:\n");
										scanf("%s", &power[i].num_of_hour);
										break;
				}
				case amount_of_Product:
				{
										  printf("amount of Product:\n");
										  scanf("%s", &power[i].amount_Of_Product);
										  break;
				}
				default:
					break;
				}


				if ((Fptr = fopen("product.txt", "w+")) == NULL)
					printf("error can not openned file\n");
				else
				{
					for (i = 0; i < *size5; i++)
					{
						fprintf(Fptr, "%s %s %f %f\n", power[i].NAME_employee, power[i].id_Employee, power[i].num_of_hour, power[i].amount_Of_Product);
						printf("%s %s %3f %f\n", power[i].NAME_employee, power[i].id_Employee, power[i].num_of_hour, power[i].amount_Of_Product);
					}
				}
			}
		}
		if (check != TRUE)
		{
			printf("No existent ID!!\nDo you want to try again? (1-YES/ 2-NO)\n");
			scanf("%d", &go_on);
			if (go_on == 2)
				break;
		}
	} while (check != TRUE);
}
void DELLET_daily_product(products *power, int* size5)
{
	FILE *Fptr;
	int i = 0, size1 = 0, check = 0;
	char line[255], del_id[15];

	if ((Fptr = fopen("users.txt", "w+")) == NULL)
		printf("error can not openned file\n");
	else
	{
		do
		{
			printf("Enter id employee for delete:\n");
			scanf("%s", &del_id);
			for (i = 0; i < *size5; i++)
			{
				if (strcmp(power[i].id_Employee, del_id) == 1)
				{
					fprintf(Fptr, "%s %s %f %f\n", power[i].NAME_employee, power[i].id_Employee, power[i].num_of_hour, power[i].amount_Of_Product);
					check++;

				}
			}
			if (check == (*size5))
				printf("ID Not found in the database!!\nTry again\n");
			else
				printf("***Cancellation employee is successfully updated***\n");
		} while (check == (*size5));
	}
	fclose(Fptr);
	/**copy from file too struct**/
	if ((Fptr = fopen("product.txt", "r+")) == NULL)
		printf("error can not openned file\n");
	else
	{
		while (fgets(line, 255, Fptr) != NULL)      /*count of line in file*/
			size1++;

		fclose(Fptr);
		if ((Fptr = fopen("product.txt", "r+")) == NULL)
			printf("error can not openned file\n");
		else
		{
			power = (products*)malloc(size1*sizeof(products));
			for (i = 0; i < size1; i++)
			{
				fscanf(Fptr, "%s %s %f %f", &power[i].NAME_employee, &power[i].id_Employee, &power[i].num_of_hour, &power[i].amount_Of_Product);
				printf("%s %s %3f %f\n", power[i].NAME_employee, power[i].id_Employee, power[i].num_of_hour, power[i].amount_Of_Product);
			}
		}
		*size5 = size1;
		fclose(Fptr);
	}
}
void Add_Constraints_employee(constraints *constraint, int* size6)
{
	FILE *Fptr;
	int newsize = (*size6);

	constraint = (constraints*)realloc(constraint, 1 * sizeof(constraints));
	if (constraint == NULL)
		printf("Error");
	else
	{
		Fptr = fopen("constraints.txt", "a+");
		if (Fptr == NULL)
			printf("error can not openned file\n");
		else
		{
			printf("constraints details\n----------------\n");
			newsize += 1;
			printf("Enter First name:");
			scanf("%s", &constraint[newsize].NAME_employee_shift);
			printf("Enter id:");
			scanf("%s", &constraint[newsize].id_Employee_shift);
			printf("Enter date for constraints:");
			scanf("%s", &constraint[newsize].date_shift);
			printf("Enter shift(Morning/evening/night):");
			scanf("%s", &constraint[newsize].shift);

			printf("%s %s %s %s\n", constraint[newsize].NAME_employee_shift, constraint[newsize].id_Employee_shift, constraint[newsize].date_shift, constraint[newsize].shift);
			fprintf(Fptr, "%s %s %s %s\n", constraint[newsize].NAME_employee_shift, constraint[newsize].id_Employee_shift, constraint[newsize].date_shift, constraint[newsize].shift);
		}
		fclose(Fptr);
		*size6 = newsize;
	}
}
void UPdate_Constraints_Employee(constraints *constraint, int* size6)
{
	FILE *Fptr;
	int choice = 0, i = 0, check = 0, go_on = 1;
	char id_employee[15];
	do
	{
		printf("Dear Manager enter ID employee that you want to uptate:\n");
		scanf("%s", &id_employee);
		for (i = 0; i < *size6; i++)
		{
			if (strcmp(id_employee, constraint[i].id_Employee_shift) == 0)
			{
				check = TRUE;
				do
				{
					printf("Dear user What do you want to change in your personal constraints:\n");
					printf("(1)date of shift\n");
					printf("(2)shift\n");

					scanf("%d", &choice);
					if (choice != 1 || choice != 2)
					{
						printf("ERROR---> Doo you want to Try again?(1-YES/2-NO)\n");
						scanf("%d", &go_on);
						if (go_on == 2)
							break;
					}
				} while (go_on != 1);

				switch (choice)
				{
				case Date_of_shift:
				{
									  printf("date of shift:\n");
									  scanf("%s", &constraint[i].date_shift);
									  break;
				}
				case SIFTE:
				{
							  printf("Enter shift:\n");
							  scanf("%s", &constraint[i].shift);
							  break;
				}
				default:
					break;
				}


				if ((Fptr = fopen("constraints.txt", "w+")) == NULL)
					printf("error can not openned file\n");
				else
				{
					for (i = 0; i < *size6; i++)
					{
						fprintf(Fptr, "%s %s %s %s\n", constraint[i].NAME_employee_shift, constraint[i].id_Employee_shift, constraint[i].date_shift, constraint[i].shift);
						printf("%s %s %s %s\n", constraint[i].NAME_employee_shift, constraint[i].id_Employee_shift, constraint[i].date_shift, constraint[i].shift);
					}
				}
			}
		}
		if (check != TRUE)
		{
			printf("No existent ID!!\nDo you want to try again? (1-YES/ 2-NO)\n");
			scanf("%d", &go_on);
			if (go_on == 2)
				break;
		}
	} while (check != TRUE);
}