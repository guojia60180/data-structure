
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define OK      1 
#define ERROR   0
#define TRUE    1
#define FALSE   0
#define MAXSIZE 50

typedef int Status;
typedef int SElemType;

//定义一个顺序存储栈
typedef struct
{
	SElemType data[MAXSIZE];
	int top;
}SqStack;

/*******************栈的基本操作********************************/
Status init_stack(SqStack *s)
{
	s->top = -1;
	return OK;
}

Status clear_stack(SqStack *s)
{
	s->top = -1;
	return OK;
}

Status stack_empty(SqStack s)
{
	if (s.top == -1)
		return TRUE;
	else
		return FALSE;
}

int stack_length(SqStack *s)
{
	return s->top + 1;
}

Status push(SqStack *s, SElemType e)
{
	if (s->top == MAXSIZE - 1)
		return ERROR;
	s->top++;
	s->data[s->top] = e;
	return OK;
}

Status pop(SqStack *s, SElemType *e)
{
	if (s->top == -1)
		return ERROR;
	*e = s->data[s->top];
	s->top--;
	return OK;
}

/*******************中序表达式转换为后续表达式********************************/
Status infix_to_postfix(char *infix, char *postfix)
{
	SqStack s;
	int e = 0;
	int i = 0, j = 0;
	int flag = 0;

	if (init_stack(&s) != OK)
		return ERROR;

	while (infix[i] != '\0')
	{
		while (infix[i] >= '0' && infix[i] <= '9')    //如果是数字则输出
		{
			if (flag)
			{
				flag = 0;
				postfix[j++] = '-';
			}
			postfix[j++] = infix[i];
			i++;
			if (infix[i]<'0' || infix[i]>'9')
				postfix[j++] = ' ';
		}
		if (infix[i] == ')' || infix[i] == ']' || infix[i] == '}')       //如果符号，则进行栈操作
		{
			pop(&s, &e);
			while (e != '(' && e != '[' && e != '{')
			{
				postfix[j++] = e;
				postfix[j++] = ' ';
				pop(&s, &e);
			}
		}
		else if (infix[i] == '+' || infix[i] == '-')
		{
			if (infix[i] == '-' && (i == 0 || (i != 0 && (infix[i - 1]<'0' || infix[i - 1]>'9'))))  //当'-'号处于第一位，或前面是符号时，为负号标志
				flag = 1;
			else if (stack_empty(s))
				push(&s, infix[i]);
			else
			{
				do
				{
					pop(&s, &e);
					if (e == '(' || e == '[' || e == '{')
						push(&s, e);
					else
					{
						postfix[j++] = e;
						postfix[j++] = ' ';
					}
				} while (!stack_empty(s) && e != '(' && e != '[' && e != '{');
				push(&s, infix[i]);
			}
		}
		else if (infix[i] == '*' || infix[i] == '/' || infix[i] == '(' || infix[i] == '[' || infix[i] == '{')
			push(&s, infix[i]);
		else if (infix[i] == '\0')
			break;
		else
			return ERROR;
		i++;
	}

	while (!stack_empty(s))
	{
		pop(&s, &e);
		postfix[j++] = e;
		postfix[j++] = ' ';
	}

	clear_stack(&s);
	return OK;
}

/*******************根据后续表达式计算结果********************************/
Status calculate(char *postfix, int *result)
{
	SqStack s;
	char *op; //存放后缀表达式中的每个因数或运算符  
	char *buf = postfix; //声明bufhe saveptr两个变量，是strtok_r函数的需要。  
	char *saveptr = NULL;
	int d, e, f;

	if (init_stack(&s) != OK)
		return ERROR;

	while ((op = strtok(buf, " ")) != NULL)
	{
		buf = NULL;
		switch (op[0])
		{
		case '+':
			pop(&s, &d);
			pop(&s, &e);
			f = d + e;
			push(&s, f);
			break;
		case '-':
			if (op[1] >= '0' && op[1] <= '9')    //是负号而不是减号
			{
				d = atoi(op);
				push(&s, d);
				break;
			}
			pop(&s, &d);
			pop(&s, &e);
			f = e - d;
			push(&s, f);
			break;
		case '*':
			pop(&s, &d);
			pop(&s, &e);
			f = e*d;
			push(&s, f);
			break;
		case '/':
			pop(&s, &d);
			pop(&s, &e);
			f = e / d;
			push(&s, f);
			break;
		default:
			d = atoi(op);
			push(&s, d);
			break;
		}
	}
	pop(&s, result);
	clear_stack(&s);
}

void main()
{
	char infix[MAXSIZE] = { 0 };
	char postfix[MAXSIZE] = { 0 };
	int result = 0;

	scanf("%s", infix);

	infix_to_postfix(infix, postfix);
	calculate(postfix, &result);

	printf("%d\n", result);
}
