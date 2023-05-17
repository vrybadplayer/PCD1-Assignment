#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>
#include <string.h>
#pragma warning (disable:4996)

int optionPage();
int viewMenu();
void fieldToViewDetails1();
void fieldToViewDetails2();
void fieldToViewDetails3();
int fieldToViewDetails();
int salesOrder();
int summaryReport();
int nextOrderSelection();
int arrays();
int sales();

double price, /*tP = totalPrice*/ tP, /*pA = price A*/pA = 69.00, pB = 70.00, pC = 55.50, pD = 58.00, pE = 65.00, pF = 89.00, pG = 73.50, pH = 80.00, pI = 50.00,/*total to pay*/ ttP, discounts;
int i, w, x, y, z, numRead = 0, num = 1, charRead = 0, character = 1;
long numSalesOrder, amount, /* tA = totalAmountBookOrderA */ tA, tB, tC, tD, tE, tF, tG, tH, tI, /*tOO = totalAmountBookOrdered*/ tOO;
char bookOrder; bookOrderTotal[999];
char bookRange[] = { 'A', 'B', 'C', 'D' ,'E', 'F', 'G', 'H', 'I', 'XXX' };

void main() {

	optionPage();
	scanf("%d", &y);
	rewind(stdin);
	if (y == 1) {
		viewMenu();
		scanf("%d", &x);
		if (x == -999)
			main();

		else if (x < 1 || x > 3) {
			printf("\n\nPlease Enter a valid input\n\n");
			system("pause");
			printf("\n\n");
			main();
		}
		fieldToViewDetails();
		printf("\n");
		main();
	}
	else if (y == 2) {
		salesOrder();
		summaryReport();
		nextOrderSelection();
		rewind(stdin);
		scanf("%c", &w);
		if (w == 'N')
			printf("BYE BYE :D");

		else if (w == 'Y') {
			printf("Ok, now teleporting you back to option selection page ......");
			system("pause");
			main();
		}

		else if (w != 'Y' || w != 'N') {
			do {
				printf("Only Y or N, Please reenter > ");
				scanf("%c", w);
			} while (w != 'Y' || w != 'N');

			if (w == 'N')
				printf("BYE BYE :D");

			else if (w == 'Y') {
				system("pause");
				main();
			}
		}
	}

	else if (y == 3) {
		printf("BYE BYE :D");
	}

	else if (y < 0 || y > 3) {
		printf("\n\nError, Please Enter a number within the range\n\n");
		main();
	}

	else {
		printf("\n\nError, Please Enter a valid input\n\n");
		main();
	}

	int number = arrays();
	printf("Returned number : %d\n", number);
	sales();

}

int optionPage() {

	printf("Select an option (1 = View menu, 2 = Sales Order, 3 = Exit):");
	return 0;
}

//menu print
int viewMenu() {

	printf("\n\nSelect a field to view: ");
	printf("\n");
	printf("1 = Software Developement Programming ");
	printf("\n");
	printf("2 = Web Programming ");
	printf("\n");
	printf("3 = Mobile Programming ");
	printf("\n");
	printf("\n\nEnter the way u want to go (Enter -999 to reselect option choice):  ");
	return 0;
}


//fieldToViewDetails print
void fieldToViewDetails1() {

	printf("\n\nSoftware Developement Programming Books: \n");
	printf("A = Beginning with Programming Logic and Design   RM69.00 \n");
	printf("B = C Programming                                 RM70.00 \n");
	printf("C = Programming Fundamentals                      RM55.50 \n");

	return;
}

void fieldToViewDetails2() {

	printf("Web Programming Books : \n");
	printf("D = HTML and CSS Design                           RM58.00 \n");
	printf("E = Web Programming                               RM65.00 \n");
	printf("F = ASP .NET Programming                          RM89.00 \n");

	return;
}

void fieldToViewDetails3() {

	printf("Mobile Programming Books : \n");
	printf("G = Mobile Design and Programming                           RM73.50 \n");
	printf("H = Building Mobile App                               RM80.00 \n");
	printf("I = Andriod Programming                          RM50.00 \n");

	return;
}

int fieldToViewDetails() {

	if (x == 1)
		fieldToViewDetails1();

	else if (x == 2)
		fieldToViewDetails2();

	else if (x == 3)
		fieldToViewDetails3();

	else
		printf("Error");
	return 0;
}

int salesOrder() {

	numSalesOrder = 1, i = 0;
	tA, tB, tC, tD, tE, tF, tG, tH, tI, tP = 0;

	do {

		printf("\nSales Order No %d \n", numSalesOrder);
		printf("Book A,B,C,D,E,F,G,H,I (X = Confirm Order):");
		rewind(stdin);
		scanf("%c", bookOrder);
		bookOrder = getchar();
		rewind(stdin);

		if (isalpha(bookOrder) != 0) {
			bookOrder = toupper(bookOrder);

			if (bookOrder == 'X' || bookOrder == 'x')
				continue;

			else if (bookOrder != 'X' && bookOrder != 'x' && bookOrder == 'A' || bookOrder == 'B' || bookOrder == 'C' || bookOrder == 'D' || bookOrder == 'E' || bookOrder == 'F' || bookOrder == 'G' || bookOrder == 'H' || bookOrder == 'I') {
				// Im using method up there of multiple || than using array cuz I am in pain T_T
				do {
					if (bookOrder == bookRange[i])
						continue;

					else if (bookOrder != bookRange[i])
						i++;

					while(i == 9){
						printf("\n\nNot within range, Please Enter again\n\n");
						fflush(stdin);
						printf("\nBook A,B,C,D,E,F,G,H,I (X = Confirm Order):");
						scanf("%c", &bookOrder);
						if (bookOrder != bookRange)
							i = 8;
						else if (bookOrder == bookRange)
							i = 9;
					}

				} while (i <= 9 || bookOrder == bookRange[i]);
				printf("\n Quantity         > ");
				numRead = scanf("%d", &amount);
				while (numRead != 1) {
					printf("\nPlease Enter a Valid input. \n");
					fflush(stdin);
					rewind(stdin);
					printf("\n Quantity         > ");
					numRead = scanf("%d", &amount);
				}
				printf("\nYou entered %d for Quantity\n", amount);
			}

			else {
				printf("\n\nNot within range, Please make sure to enter available option.\n\n");
				salesOrder();
			}

		}

		else {
			printf("Error, Please enter a valid input T_T");
			printf("\n");
			salesOrder();
		}

		if (bookOrder == 'A') {
			price = pA * amount;
			tA += amount;
		}

		else if (bookOrder == 'B') {
			price = pB * amount;
			tB += amount;
		}

		else if (bookOrder == 'C') {
			price = pC * amount;
			tC += amount;
		}

		else if (bookOrder == 'D') {
			price = pD * amount;
			tD += amount;
		}

		else if (bookOrder == 'E') {
			price = pE * amount;
			tE += amount;
		}

		else if (bookOrder == 'F') {
			price = pF * amount;
			tF += amount;
		}

		else if (bookOrder == 'G') {
			price = pG * amount;
			tG += amount;
		}

		else if (bookOrder == 'H') {
			price = pH * amount;
			tH += amount;
		}
		else if (bookOrder == 'I') {
			price = pI * amount;
			tI += amount;
		}

		else if (bookOrder == 'X')
			printf("Exit Successfully :D \n");

		else {
			printf("Not within Range");
			printf("\n");
			break;
		}

		tOO += amount;
		tP += price;
		numSalesOrder += 1;
	} while (numSalesOrder > 999 || bookOrder != 'X');

	printf("\n\nOrder confirmed\n\n\n");
	system("pause");
	printf("\n\n\n\n");

	if (numSalesOrder == 1)
		main();

	if (tP > 200 && tP <= 300) {
		discounts = 0.05;
	}

	else if (tP > 300 && tP <= 500) {
		discounts = 0.1;
	}

	else if (tP > 500) {
		discounts = 0.15;
	}

	ttP = tP - (tP * discounts);

	if (tA != 0)
		printf("Book A: %d @ %.2f                                                =             RM%6.2f\n", tA, pA, tA * pA);

	if (tB != 0)
		printf("Book B: %d @ %.2f                                                =             RM%6.2f\n", tB, pB, tB * pB);

	if (tC != 0)
		printf("Book C: %d @ %.2f                                                =             RM%6.2f\n", tC, pC, tC * pC);

	if (tD != 0)
		printf("Book D: %d @ %.2f                                                =             RM%6.2f\n", tD, pD, tD * pD);

	if (tE != 0)
		printf("Book E: %d @ %.2f                                                =             RM%6.2f\n", tE, pE, tE * pE);

	if (tF != 0)
		printf("Book F: %d @ %.2f                                                =             RM%6.2f\n", tF, pF, tF * pF);

	if (tG != 0)
		printf("Book G: %d @ %.2f                                                =             RM%6.2f\n", tG, pG, tG * pG);

	if (tH != 0)
		printf("Book H: %d @ %.2f                                                =             RM%6.2f\n", tH, pH, tH * pH);

	if (tI != 0)
		printf("Book I: %d @ %.2f                                                =             RM%6.2f\n", tI, pI, tI * pI);

	printf("                                                                               ========\n");
	printf("Subtotal                                                         =             RM%6.2f \n", tP);
	printf("\n");
	printf("Discounts                                                        =             RM%6.2f \n", tP * discounts);
	printf("\n");
	printf("Total to Pay                                                     =             RM%6.2f \n", ttP);

}

int summaryReport() {

	printf("\n\n\n\n");
	printf("                             DAILY SALES ORDER SUMMARY REPORT\n");
	printf("Total Number Of Sales Order(s) = %d \n", numSalesOrder);
	printf("Book                        Quantity Sold Sales             Amount \n");
	printf("  A                               %d                         %.2f                                                             \n", tA, tA * pA);


	printf("  B                               %d                         %.2f                                                             \n", tB, tB * pB);


	printf("  C                               %d                         %.2f                                                             \n", tC, tC * pC);


	printf("  D                               %d                         %.2f                                                             \n", tD, tD * pD);


	printf("  E                               %d                         %.2f                                                             \n", tE, tE * pE);


	printf("  F                               %d                         %.2f                                                             \n", tF, tF * pF);


	printf("  G                               %d                         %.2f                                                             \n", tG, tG * pG);


	printf("  H                               %d                         %.2f                                                             \n", tH, tH * pH);


	printf("  I                               %d                         %.2f                                                             \n", tI, tI * pI);

	printf("TOTAL                             %d                         %.2f", tOO, ttP);

	return 0;

}

int nextOrderSelection() {

	printf("\n\n\nThankiu, Have A Nice Day\n\n\n");
	printf("\n\nNext Order? Yes or No (Y = Yes, N = No), Please Enter Y or N > ");

	return 0;

}

//THESE TWO ARE ARRAY

int arrays() {

	char intChecking[] = "1234567890";
	char input[100];
	int correctInput = 0;
	do {
		printf("Enter an integer: ");
		scanf("%s", &input);
		for (int i = 0; i < strlen(intChecking); i++) {
			for (int j = 0; j < strlen(input); j++) {
				if (input[j] == intChecking[i]) {
					correctInput += 1;
					break;
				}
			}
		}
		if (correctInput < strlen(input)) {
			printf("Please enter correct input\n");
		}
	} while (correctInput < strlen(input));

	return atoi(input);


}


int sales() {
	char book[100];
	int quantity[100];
	int i = 0;
	

	printf("%s %d\n", "Sales Order No: ", i+1);
	do {
		printf("%s", "Book A,B,C,D,E,F,G,H,I (X=Exit)");
		scanf("%c", &book[i]);
		if (book[i] != 'X') {
			printf("%s", "Quantity");
			scanf("%d", &quantity[i]);
			i++;

		}
		rewind(stdin);

	} while (book[i] != 'X');
	
	for (int j = 0; j < i; j++) {
		printf("Book %c: %d @ RM xx.00 = RM %.2lf\n", book[j], quantity[j], quantity[j] * 69.00);
		
	}

}