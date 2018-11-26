//����˳��洢�ṹ����Ϊ:
#include <stdlib.h>
#include <time.h>
/*˳��ṹ�Ĵ洢�ṹ����*/
#define MAXSIZE 20
typedef int ElemType;


/*˳��洢�ṹ�Ĳ�����ɾ��*/

/*���Ԫ�ز���*/

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

//�����������
Status StrConcat(StringType s, StringType t)
/* ����t���ᵽ��s֮��,�����Ȼ������s�� */
{
	int i, j;
	if ((s.length + t.length)>MAX_STRLEN)
		return ERROR; /* ����󳤶ȳ�����Χ */
	for (i = 0; i<t.length; i++)
		s.str[s.length + i] = t.str[i]; /* ��t���ᵽ��s֮�� */
	s.length = s.length + t.length; /*�޸������Ĵ����� */
	return OK;
}

//���Ӵ�����
Status SubString(StringType s, int pos, int len, StringType *sub)
{
	int k, j;
	if (pos<1 || pos>s.length || len<0 || len>(s.length - pos + 1))
		return ERROR; /* �����Ƿ� */
	sub->length = len - pos + 1; /* ����Ӵ����� */
	for (j = 0, k = pos; k <= len; k++, j++)
		sub->str[j] = s.str[k]; /* ����ַ���������Ӵ� */
	return OK;
}

//����ַ��ڴ��е�λ��

/*TΪ�ǿմ���������S�е�pos���ַ�֮�������T��ȵ��Ӵ�*/
/*�򷵻ص�һ���������Ӵ���S�е�λ�ã����򷵻�0*/
#include"str.h"
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<assert.h>

void StrAssign(Str *s, const char *chars)//��ʼ����
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

void StrCpy(Str*s, Str*t)//������
{
	for (int i = 0; i<t->length; i++)
	{
		s->elem[i] = t->elem[i];
	}
	s->length = t->length;
}

int Getlength(Str *s)//��ȡ���ĳ���
{
	return s->length;
}

void Clear(Str *s)//��մ�s
{
	s->length = 0;
}

bool SubStr(Str *sub, Str *s, int pos, int len)//�հ��ַ�������
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

bool Inset(Str *s, int pos, Str *t)//�ڴ�s��posλ�ò��봮t
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
int BF(Str *s, Str *sub, int pos)//�ڴ�s���ҵ�һ����sub�������ش�sub�ĵ�һ��Ԫ�ص��±�
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

bool DeletePos(Str* s, int pos, int len)//��posλ�ÿ�ʼɾ��len������
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

bool Delete(Str *s, int pos, Str *t)//�ڴ��е�posλ�ÿ�ʼɾ����t
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
bool Replace(Str *s, Str *t, Str *v, int pos)//��v�滻��posλ�ÿ�ʼ�ĵ�һ��t
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
bool RepIaceAll(Str *s, Str *t, Str *v)//�ڴ�s�в��ҵ���t���ô�v�滻
{
	assert(s != NULL);
	assert(t != NULL);
	assert(v != NULL);

	while (Replace(s, t, v, 0));
	return true;
}
void Show(Str *s) //��ӡ  
{
	for (int i = 0; i<Getlength(s); i++)
	{
		printf("%c", s->elem[i]);
	}
	printf("\n");
}


