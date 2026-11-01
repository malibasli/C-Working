/*******************************************************************
Filename = q5
Author = Kaya Turgut
Date = 3.10.2020
Description = Fifth question related to valiade if the account is legal or not.
*******************************************************************/

//includes input/output header to use "cin/cout" funtion
#include<iostream>

//To omit std:: notation for cout/cin/endl
using namespace std;

///function takes digit input and calculate the check sum
int f_sum(int d)
{
	return ((2*d)%10 + (2*d)/10);
}


/*function main begins program execution
  each program must include main function*/
int main(void)
{
	//Define account number as int
	int account_number;
	//Define copy account number as int
	int copy_account_number;
	//Define digit as int
	int digit;
	//Define the number of digits as int and initialized as 0
	int digit_num = 0;
	//Define the check_sum as int and initialized as 0
	int check_sum = 0;
	
	cout<<"Enter the account number (decimal digits like 17327):"; //Print the explanation for user
	cin>>account_number; //Prompt the a values
		
	copy_account_number = account_number; // Assign the account number to copy_account_number
	
	//Adjust the loop to find the number of decimal digit 
	while((copy_account_number/10) !=0)
	{	
		copy_account_number = copy_account_number/10; // Discard the last digit and update the copy account number with remaining part  
		digit_num += 1; //increase the digit number by one
	}
	cout<<"Digit num:"<<digit_num+1<<endl;
	
	//Adjust the loop according to the number of decimal digit 
	for (int i=digit_num;i>=0;i--)
	{	
		digit = account_number%10; //Get the last digit
		if (digit_num%2!=0) // if the last digit is odd, implement the f function and add the result to check_sum
			check_sum += f_sum(digit); // Update the check_sum by calling function
		else // if the last digit is even, add the last digit to check_sum directly
			check_sum += digit; // Update the check_sum
		
		account_number /= 10; // Discard the last digit and update the account number with remaining part
	}
	
	//check the account number 
	if (check_sum%10 == 0) //If the check sum is multiple of 10, then it is legal.
		cout<<"The account number is legal"<<endl;
	else // Otherwise, it is not legal
		cout<<"The account number is NOT legal"<<endl;
	
	
	//indcates successful termination
	return 0;
}
