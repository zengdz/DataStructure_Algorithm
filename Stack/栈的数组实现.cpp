/*
 * 使用数组简单实现栈，包含入栈退栈以及返回栈顶
 */
#include <iostream>

using namespace std;

#define MAX_SIZE 101
int A[MAX_SIZE];
int top = -1; // 栈顶索引,初始值-1表示空栈

void ArrStackPush(int x)
{
	if (top == MAX_SIZE - 1) {
		cout << "Error: stack overflow!" << endl;
		return;
	}
	A[++top] = x;
}

void ArrStackPop()
{
	if (top == -1) {
		cout << "Error: no element to pop!" << endl;
		return;
	}
	--top; // 索引退1即可
}

int ArrStackTop()
{
	return A[top];
}

void Print(const char *s, const int arr[], const int length)
{
	cout << s << endl;
	for (int i = 0; i <= length; ++i) {
		cout << arr[i] << " ";
	}
	cout << endl;
}

int main()
{
	ArrStackPush(1);
	ArrStackPush(13);
	ArrStackPush(6);
	Print("Stack:", A, top);
	ArrStackPop();
	Print("Stack:", A, top);
	ArrStackPush(33);
	Print("Stack:", A, top);
	cout << "Top of stack is: " << ArrStackTop() << endl;
	return 0;
}
