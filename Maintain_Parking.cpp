#include<stdio.h>     //using this header file so that we can use printf and scanf
#include<conio.h>     //so that we can use clrscr() and getch();clrscr is used to clear the window of the console &getch()used for pushing the console
#include<stdlib.h>    //exit(),malloc(),free(),alloc(), function is here in this library.exit() is used in this program.
//Declaring all the functions that we've used in the entire program
int Menu();
void Bus();
void Cycle();
void Riksha();
void Delete();
void ShowDetail();

int nor=0,nob=0,noc=0,amount=0,count=0;  //nor means no.of rikshas;initially keeping it 0 as no Riksha is there initially;amount variable stores the amount,count variable is used to count total number of riksha,bus and cycle.
//after defining all the functions Menu(),Delete(),ShowDetail(),Riksha(),Cycle(),Bus() now we'll have to code for the main function
int main()
{
	//the program will run for only once.Once we enter the choice it will show all the results and the program will exit.But we have do here something so that it runs in a loop.So we'll use here an infinite loop
	while(1)     //1 in C means True
	{
//	clrscr();  //this will also be inside the while loop bcz once the data is inputted again the program will run,so the data we have entried will be cleared.Suppose 1st we have enterd 4,we'll see all details then if we choose 2 then prev details will still be there on the screen.
	//since we have choices so simply we'll not all the functions that we have defined so we'll have to use here switch case
	switch(Menu())  //calling the Menu() function,all the printf lines of Menu() will be printed then the choice that I have entered that will be returned from where the function is called i.e to the Menu(),if choice value entered by the user 
	//comes to the switch(Menu()) I'll have to check that choice is matching with which case
	{
		//if choice==1,then we'll have to do entry for bus;so have to call the Bus()
		case 1:
			Bus();
			break; //if we don't give break then all the cases case2,3,4,5 all will be executed
		case 2:
			Cycle();
			break;
		case 3:
			Riksha();
			break;
		case 4:
			ShowDetail();
			break;
		case 5:
			Delete();
			break;
			//have to add another case for 6
		case 6:
			exit(0);     //exit is a predefined function,where I'll pass 0.work of exit is to terminate the whole program,andwe're passing 0 in it means I myself is ending the program.
			//no need to write here the break statement program will automatically end as we have used here exit()
			//if no value matches then default
		default:
			//printing just a message in default
			printf("\nInvalid choice.");
	}
	getch();
}
}
//Now to make a menu we're making a function
int Menu()   //it'll not be void menu() as the choice value that this function will be returning is of int type not of void.
{
	int choice;  //choice is a local variable
	printf("\n1.Enter Bus: ");
	printf("\n2.Enter Cycle: ");
	printf("\n3.Enter Riksha: ");
	//To show thw status
	printf("\n4.Show Status: ");
	//To delete data
	printf("\n5.Delete data: ");
	//entering one more choice 6 bcz the while loop will run infinite times.to exit we need to give 1 more choice i.e 6.
	printf("\n6.Exit:");
	//what user wants to input?user's choice
	printf("\n\nEnter your choice(1/2/3/4/5/6):\n");
	scanf("%d",&choice);
	//when we'll call the Menu(),choice value must be returned.
	return(choice);   //value of choice after returning will go to main() as we'll call the Menu() in the main() method
}
//to delete data when vehicle is removed
void Delete()
{
	//have to make nob,noc,nor 0
	nob=0;
	noc=0;
	nor=0;
	amount=0;
	count=0;
}

//to show status have to declare a function
void ShowDetail()
{
	printf("\nNumber of Bus=%d",nob);   //we need to print number of bus so nob
	printf("\nNumber of Cycle=%d",noc);
	printf("\nNumber of Riksha=%d",nor);
	printf("\nTotal number of vehicle=%d",count);  //as count means (nob+noc+nor)
	printf("\nTotal amount gain=Rs%d",amount);
}
//suppose a Riksha is coming so I'll a make a function with name Riksha that will not return anything.
void Riksha()
{
    printf("\n Riksha entry successful.");
	//now suppose a Riksha is coming so I'll have to increment the number of Riksha,and have to increment the total amount.
	nor++;
	amount=amount+50; //initially amount was 0 when a riksha comes parking charge is 50 so adding 50 with previous amount.
	count++;
}
//In the same way as Riksha() I'll make a function Cycle(),Bus()
void Cycle()      //here also I'll not pass any value
{
    printf("\nCycle entry successful.");
	noc++;
	amount=amount+20;
	count++;
}
void Bus()
{
printf("\nBus entry successful.");
nob++;
amount=amount+100;
count++;	
}

