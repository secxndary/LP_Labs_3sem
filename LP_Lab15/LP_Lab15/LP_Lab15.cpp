#include <iostream>
#include <stack>
#include <queue>
#define PLUS '+'
#define MINUS '-'
#define STAR '*'
#define DIRSLASH '/'
#define RIGHTTHESIS ')'
#define LEFTTHESIS '('
using namespace std;
bool Polish(char str[]);
stack<char> Stack;
queue<char> Queue;

int main()
{
	setlocale(LC_ALL, "Ru");
	char string[] = { "(a+b)*j/(c-g)/(a-(k+a)+b)" };															// ab+j*cg-/aka+-b+/	[  (a+b)/(c-d*(a+d))*(b-a)    ab+/cdad+*-ba-*  ]
	Polish(string);
}

bool Polish(char str[])
{

	int size = 0;
	int i = 0;
	try
	{
		do
		{
			if (str[i] >= 'a' && str[i] <= 'z')
			{
				Queue.push(str[i]);
			}
			else
			{

				switch (str[i])
				{
				case PLUS:
				case MINUS:
				{
					if (!Stack.empty() && Stack.top() != LEFTTHESIS)
					{
						Queue.push(Stack.top());
						Stack.pop();
					}

					Stack.push(str[i]);

				} break;
				case STAR:
				case DIRSLASH:
				{
					while (!Stack.empty())
					{
						Queue.push(Stack.top());
						Stack.pop();
					}

					Stack.push(str[i]);

				} break;
				case RIGHTTHESIS:
				{
					while (Stack.top() != LEFTTHESIS)
					{
						Queue.push(Stack.top());
						Stack.pop();
						if (Stack.empty())
							return false;
					}
					Stack.pop();
				} break;
				case LEFTTHESIS:
				{
					Stack.push(str[i]);
					
				} break;
				case '\0':
				{
					while (true)
					{
						Queue.push(Stack.top());
						Stack.pop();
						if (Stack.empty())
							break;
					}
				} break;
				default:
					throw "Неверное выражение!";
					break;
				}

			}
			if (str[i] == '\0')
				break;
			i++;
		} while (true);
		size = Queue.size();
		char* resultString = new char[size];
		for (int i = 0; i < size; i++)
		{
			resultString[i] = Queue.front();
			Queue.pop();
			cout << resultString[i];
		}
		delete[] resultString;
		return true;
	}
	catch (const char* exception)
	{
		std::cerr << "Ошибка: " << exception << '\n';
	}
}