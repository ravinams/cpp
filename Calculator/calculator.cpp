#include <cstdlib>
#include <iostream>
#include "stack.h"

using namespace std;

//function that utilises almost every other function to calculate and display the stack
// pre: getUserValue() has acceoted a char from the user
// post: this is the last function in the program
// usage:
void hpCalculator(char achar);

//fucntion that completes all arithmetic function for hpCalculator()
// pre: the top two values from the values stacj have been passed from hpCalculator
// post: value is passed back to hpCalculatorto push into the stack
// usage:
int arithmetic(char topOperation, char value1, char value2);

// get a char from the user 
// pre: first function called in main()
// post: user char is passed to hpCalculator)(
// usage:
char getUserValue();

//outputs the stack to the terminal
// pre: the values stack has been filled and arithmetic() has done proformed its' operations
// post: this function will continue to loop while isExit() is not true
// usage:
void printStack(Stack& stack);

// converts achar to an integer value
// pre: isDigit() has returned true
// post: the integer is pushed into the stack 
// usage:
int convertToAsciiToValue(char achar);

// checks if the user inputted value is an 'x' charecter to exit the program
// pre: getUserValue() has colleted the users value
// post: the bool value is passed to the hpCalculator() function 
// usage:
bool isExit(char achar);

// checks if the user inputted value is la negative number
// pre: getUserValue() has colleted the users value and convertToAsciiToValue() 
// post: the bool value is passed to the hpCalculator() function where the program exits
// usage:
bool isUnderflow(int afterOperationNumber);

// checks if the user inputted value is greater than 9
// pre: getUserValue() has colleted the users value and convertToAsciiToValue has return an integer
// post: the bool value is passed to the hpCalculator() function where the program exits
// usage:
bool isOverflow(int afterOperationNumber);

// finds the order of precedence for each operator
// pre: isOperator() has returned true 
// post: hpCalculator() moves the values in the stack to match their precedence
// usage:
int getPrecedence(ItemType achar);

// checks if the user inputted value is a division sumbol
// pre: getUserValue() has colleted the users value
// post: the bool value is passed to the hpCalculator() function 
// usage:
bool isDivision(char achar);

// checks if the user inputted value is a multipulcation symbol
// pre: getUserValue() has colleted the users value
// post: the bool value is passed to the hpCalculator() function 
// usage:
bool isMultiplication(char achar);

// checks if the user inputted value is a subtraction symbol
// pre: getUserValue() has colleted the users value
// post: the bool value is passed to the hpCalculator() function 
// usage:
bool isSubtraction(char achar);

// checks if the user inputted value is an addition symbol
// pre: getUserValue() has colleted the users value
// post: the bool value is passed to the hpCalculator() function 
// usage:
bool isAddition(char achar);

// checks if the user inputted value is an operator
// pre: getUserValue() has colleted the users value
// post: the bool value is passed to the hpCalculator() function 
// usage:
bool isOperator(char achar);

// checks if the user inputted value is a integer
// pre: getUserValue() has colleted the users value
// post: the bool value is passed to the hpCalculator() function 
// usage:
bool isDigit(char achar);


int main(){
	char achar;
	
	achar = getUserValue();
	hpCalculator(achar);
	
	
return 0;
}

bool isDigit(char achar){
   if(achar == '0' || achar == '1' || achar == '2' || achar == '3' || achar == '4' || achar == '5' || achar == '6' || achar == '7' || achar == '8' || achar == '9'){
      return true;
   }
   else{
      return false;
   }
}

bool isOperator(char achar){
	if(achar == '+' || achar == '-' || achar == '/' || achar == '*' || achar == '(' || achar == ')'){
		return true;
	}
	else{
		return false;
	}
}

bool isAddition(char achar){
   if(achar == '+'){
      return true;
   }
   else{
      return false;
   }
}

bool isSubtraction(char achar){
   if(achar == '-'){
      return true;
   }
   else{
      return false;
   }
}

bool isMultiplication(char achar){
   if(achar == '*'){
      return true;
   }
   else{
      return false;
   }
}

bool isDivision(char achar){
   if(achar == '/'){
      return true;
   }
   else{
      return false;
   }
}


int getPrecedence(ItemType achar){
  switch (achar){
    case '+':
    case '-':
      return 1;
    case '*':
    case '/':
      return 2;
   case '(':
   case ')':
      return 3;
   default:
      return -1;
   }
}

bool isOverflow(int afterOperationNumber){
	if(afterOperationNumber > 9){
		return true;
	}
	else{
		return false;
	}
}

bool isUnderflow(int afterOperationNumber){
	if(afterOperationNumber < 0){
		return true;
	}
	else{
		return false;
	}
}

bool isExit(char achar){
	if(achar == 'x'){
		return true;
	}
	else{
		return false;
	}
}

int convertToAsciiToValue(char achar){
  int ascii;
  ascii = achar;
  return(ascii - '0');
}

void printStack(Stack& values){
	bool isAdded = true;
	ItemType topItem;
	Stack copyStack;
	while(not values.isEmpty()){
		values.retrieve(topItem);
		copyStack.push(topItem, isAdded);
		values.pop();
	}
	while(not copyStack.isEmpty()){
		copyStack.retrieve(topItem);
		values.push(topItem, isAdded);
		for(int k = 1; k < 3; k++){
			cout << k << ": " << topItem << endl;
			copyStack.pop();
		}

	}
}

char getUserValue(){
	char achar;
	cin >> achar;
	return achar;
	
}

int arithmetic(char operation, char value1, char value2){
	int val1 = convertToAsciiToValue(value1);
	int val2 = convertToAsciiToValue(value2);
	
	if(isAddition(operation) == true){
      return val1 + val2;
	}
	if(isSubtraction(operation) == true){
		return val1 - val2;
	}
    if(isMultiplication(operation) == true){
		return val1 * val2;
    }
	if(isDivision(operation) == true){
		return val1 / val2;
	}
}


void hpCalculator(char achar){
	Stack operators;
	Stack values;
	
	bool isAdded = true;
	char topValue;
	int afterOperationNumber;
	char topOperation;
	char tempOperation;
	char value1;
	char value2;
	
	
	while(isExit(achar) == false){
		if(isOperator(achar) == true){
			 operators.retrieve(topOperation);
			if( !operators.isEmpty() && getPrecedence(achar) > getPrecedence(topOperation)){
				operators.push(achar, isAdded);
			}
			if else(!operators.isEmpty() && getPrecedence(achar) <= getPrecedence(topOperation){
				tempOperation = topOperation;
				topOperation = achar;
				operators.pop();
				operators.push(tempOperation, isAdded);
				operators.push(achar, isAdded);
			}
			else{
				operators.push(achar, isAdded);
			}
		}
		if(isDigit(achar) = true){
			if(values.isEmpty()){
				topValue = achar;
				values.push(topValue, isAdded)
			}
			if(!values.isEmpty() && !operators.isEmpty()){
				value1 = values.retrieve(topValue);
				value2 = achar;
				topOperation = operators.retrieve(topOperation);
				afterOperationNumber = arithmetic(value1, value2);
				if(isOverflow(afterOperationNumber) = true){
					cout << "3:" << endl;
					cout << "2:" << endl;
					cout << "1: OVERFLOW" << endl;
				exit(-1);
				}

				if(isUnderflow(afterOperationNumber) = true){
					cout << "3:" << endl;
					cout << "2:" << endl;
					cout << "1: UNDERFLOW" << endl;
					exit(-1);
				}
				values.pop();
				operators.pop();
				values.push(afterOperationNumber, isAdded);
			
			}
		}
			printStack(values const& stack);
		achar = getUserValue();
	}
	if(isExit(achar) = true){
		cout << "Goodbye. Thanks for using our calculator" << endl;
		exit(-1);
	}
}




	
