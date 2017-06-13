#include "Array.h"
#include "Stack.h"
#include "Fixed_Array.h"
#include "Queue.h"

int main()
{
	
	Array<int> numbers(5);
	Stack<char> letters;
	Queue<double> doubleNumber;
	Fixed_Array<int,5> num;

	numbers[0] = 3;

	letters.push('D');
	letters.push('r');
	letters.push('.');
	letters.push('H');
	letters.push('I');
	letters.push('L');
	letters.push('L');
	letters.push('!');

	doubleNumber.enqueue(5.5);
	doubleNumber.enqueue(11.5);
	doubleNumber.enqueue(2.5);
	doubleNumber.enqueue(33.5);

	doubleNumber.dequeue();
	doubleNumber.dequeue();


}
