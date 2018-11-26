//定长顺序存储结构定义为:
#include <stdlib.h>
#include <time.h>
/*顺序结构的存储结构代码*/
#define MAXSIZE 20
typedef int ElemType;


/*顺序存储结构的插入与删除*/

/*获得元素操作*/

#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0
typedef int Status;
typedef int SElemType;

#define MAX_STRLEN 256 
typedef struct
{
	char str[MAX_STRLEN];
	int length;
} StringType;

//串的联结操作
Status StrConcat(StringType s, StringType t)
/* 将串t联结到串s之后,结果仍然保存在s中 */
{
	int i, j;
	if ((s.length + t.length)>MAX_STRLEN)
		return ERROR; /* 联结后长度超出范围 */
	for (i = 0; i<t.length; i++)
		s.str[s.length + i] = t.str[i]; /* 串t联结到串s之后 */
	s.length = s.length + t.length; /*修改联结后的串长度 */
	return OK;
}

//求子串操作
Status SubString(StringType s, int pos, int len, StringType *sub)
{
	int k, j;
	if (pos<1 || pos>s.length || len<0 || len>(s.length - pos + 1))
		return ERROR; /* 参数非法 */
	sub->length = len - pos + 1; /* 求得子串长度 */
	for (j = 0, k = pos; k <= len; k++, j++)
		sub->str[j] = s.str[k]; /* 逐个字符复制求得子串 */
	return OK;
}

//求该字符在串中的位置

/*T为非空串，若主串S中第pos个字符之后存在与T相等的子串*/
/*则返回第一个这样的子串在S中的位置，否则返回0*/
#include"str.h"
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<assert.h>

void StrAssign(Str *s, const char *chars)//初始化串
{
	assert(s != NULL);
	int len = strlen(chars);

	/*if(s->length<len)
	{
	return;
	}*/
	s->length = len;
	for (int i = 0; i<len; i++)
	{
		s->elem[i] = chars[i];
	}
}

void StrCpy(Str*s, Str*t)//拷贝串
{
	for (int i = 0; i<t->length; i++)
	{
		s->elem[i] = t->elem[i];
	}
	s->length = t->length;
}

int Getlength(Str *s)//获取串的长度
{
	return s->length;
}

void Clear(Str *s)//清空串s
{
	s->length = 0;
}

bool SubStr(Str *sub, Str *s, int pos, int len)//空白字符不拷贝
{
	if (pos < 0 || len < 1 || pos >= s->length || pos + len>s->length - 1)
	{
		return false;
	}
	for (int i = pos; i<pos + len; i++)
	{
		sub->elem[i - pos] = s->elem[i];
	}
	sub->length = len;
	return true;
}

bool Inset(Str *s, int pos, Str *t)//在串s的pos位置插入串t
{
	assert(s != NULL);
	assert(t != NULL);
	if (pos<0 || pos>s->length || pos + t->length>SIZE)
	{
		return false;
	}
	for (int i = s->length - 1; i >= pos; i--)
	{
		s->elem[i + t->length] = s->elem[i];
	}
	for (int j = 0; j<t->length; j++)
	{
		s->elem[j + pos] = t->elem[j];
	}
	s->length += t->length;
	return true;
}
int BF(Str *s, Str *sub, int pos)//在串s里找第一个串sub，并返回串sub的第一个元素的下标
{
	if (pos<0 || pos>s->length)
	{
		return -1;
	}

	int i = pos;
	int j = 0;

	int lens = s->length;
	int lensub = sub->length;

	while (i < lens && j < lensub)
	{
		if (s->elem[i] == sub->elem[j])
		{
			i++;
			j++;
		}
		else
		{
			i = i - j + 1;
			j = 0;
		}
	}
	if (j >= lensub)
	{
		return i - j;
	}
	else
		return -1;
}

bool DeletePos(Str* s, int pos, int len)//从pos位置开始删除len个长度
{
	assert(s != NULL);
	if (pos<0 || pos + len>s->length || len<0)
	{
		return false;
	}
	//for(int i = pos;i<len+pos;i++)
	for (int i = pos; i<s->length - len; i++)
	{
		s->elem[i] = s->elem[i + len];
	}
	s->length -= len;
	return true;
}

bool Delete(Str *s, int pos, Str *t)//在串中的pos位置开始删除串t
{
	assert(s != NULL);
	assert(t != NULL);
	if (pos<0 || pos>s->length || t->length>s->length)
	{
		return false;
	}
	int index = BF(s, t, pos);
	if (index < 0)
	{
		return false;
	}
	return DeletePos(s, index, t->length);
}
bool Replace(Str *s, Str *t, Str *v, int pos)//用v替换从pos位置开始的第一个t
{
	assert(s != NULL);
	assert(t != NULL);
	assert(v != NULL);

	int index = BF(s, t, pos);
	if (index < 0)
	{
		return false;
	}
	DeletePos(s, index, t->length);
	return Inset(s, index, v);
}
bool RepIaceAll(Str *s, Str *t, Str *v)//在串s中查找到串t并用串v替换
{
	assert(s != NULL);
	assert(t != NULL);
	assert(v != NULL);

	while (Replace(s, t, v, 0));
	return true;
}
void Show(Str *s) //打印  
{
	for (int i = 0; i<Getlength(s); i++)
	{
		printf("%c", s->elem[i]);
	}
	printf("\n");
}


