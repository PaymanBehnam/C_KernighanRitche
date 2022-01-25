#include <stdio.h>
#include <conio.h>
#include <math.h>
#define MAXLINE 75

void delrpt(int);

struct sets
{
	int Type;
	char Name;
	int slen;
	char string[20][40];
	char character[20];
	int Integer[20];
	float Float[20];
}set[40];

struct R
{
	int Type;
	char Name;
	int slen;
	char string[60][40];
	char character[60];
	int Integer[60];
	float Float[60];
}result;

char line[MAXLINE];
int setcnt=0;
void printresult();
void delrptresult();

char  hlptext[]={"Welcome to My Project\nPlease Attention:\n1.Max number of each set members is 20\n2.You can define at least 40 set\n3.Each set must have a name (you can not use unnamed sets)\n4.use this notation\n   a+b for Union\n   a-b for Difference\n   a*b for Intersection\n   -a  for Complement\n5.Use Ctrl+z to exit \n"};
char  hlptext2[]={"\nWarning:This program can not support empty set!\nWarning:This program is not full functional and can not support syntax errors!\nThen please enter correct command attention to above note\nMajid Zare (bm831063)\n\n"};


void hlp()
{
	int i=0;
	while(hlptext[i]!='\0')
	{
		putchar(hlptext[i]);
		i++;
	}
	i=0;
	while(hlptext2[i]!='\0')
	{
		putchar(hlptext2[i]);
		i++;
	}
}

//read function
int read(char s[],int lim)
{
	int c,i;
	putchar('>');
	putchar('>');
	putchar('>');
	for(i=0;i<lim-1 && (c=getchar())!=EOF && c!='\n';++i)
		s[i]=c;
	if(c=='\n')
		s[i++]='\n';
	s[i]='\0';
	return i;
}



//type function

int type(char s[])
{
	int i;
	for(i=3;s[i]!='\0';++i)
	{
		if(s[i]=='"')
			return 1;
		else if(s[i]=='\'')
			return 2;
		else if(s[i]=='.')
			return 3;
		}
		return 4;
}

//save function

void save(char s[])
{
	int k,e=0,i=0,j=0,ecnt=0,flg=0;
	char snumber[20];
	for(k=0;s[k]!='=';++k)
		;
	while(ecnt<setcnt)
	{
		if(set[ecnt].Name!=s[k-1])
			++ecnt;
		else
		{
			flg=1;
			break;
		}
	}

	if(!flg)
	{
		++setcnt;
		flg=0;
	}

	switch(type(s))
	{
		case 1:
			set[ecnt].Name=s[k-1];
			set[ecnt].Type=1;
			set[ecnt].slen=0;
			while(s[e]!='}')
			{
				if(s[e]=='"')
				{
					++e;
					for(e;s[e]!='"';++e)
						set[ecnt].string[i][j++]=s[e];
						++set[ecnt].slen;
					++i;
					j=0;
					++e;
				}
				else
					++e;
			}
			break;
		case 2:
			set[ecnt].Name=s[k-1];
			set[ecnt].Type=2;
			set[ecnt].slen=0;
			while(s[e]!='}')
			{
				if(s[e]=='\'' && s[e+1]!='}')
				{
					++e;
					if(s[e]!=',')
					{
						set[ecnt].character[i++]=s[e];
						++set[ecnt].slen;
					}
					++e;
				}
				else
					++e;
			}
			break;
		case 3:
			set[ecnt].Name=s[k-1];
			set[ecnt].Type=3;
			set[ecnt].slen=0;
			e=k+1;
			while(s[e]!='}')
			{
				if(s[e]==',' || s[e]=='{')
				{
					++e;
					for(e;s[e]!=',' && s[e]!='}';++e)
						snumber[i++]=s[e];
				}
				snumber[i]='\0';
				set[ecnt].Float[j++]=atof(snumber);
				++set[ecnt].slen;
				i=0;
			}
			break;
		case 4:
			set[ecnt].Name=s[k-1];
			set[ecnt].Type=4;
			set[ecnt].slen=0;
			e=k+1;
			while(s[e]!='}')
			{
				if(s[e]==',' || s[e]=='{')
				{
					++e;
					for(e;s[e]!=',' && s[e]!='}';++e)
						snumber[i++]=s[e];
				}
				snumber[i]='\0';
				set[ecnt].Integer[j++]=atoi(snumber);
				++set[ecnt].slen;
				i=0;
			}
			break;
		default:
			putchar('E');
			putchar('R');
			putchar('R');
			putchar('O');
			putchar('R');
			putchar('\n');
			break;
	}
	delrpt(getID(set[ecnt].Name));
}

//delrpt function

void delrpt(int a)
{
	int i,j,k;
	switch (set[a].Type)
	{
		case 1:
			for(i=0;i<set[a].slen;++i)
			{
				j=i+1;
				while(j<set[a].slen)
				{
					if(!strcmp(set[a].string[i],set[a].string[j]))
					{
						for(k=j;k<set[a].slen;++k)
							strcpy(set[a].string[k],set[a].string[k+1]);
						--set[a].slen;
					}
					else
						j++;
				}
			}
			break;
		case 2:
			for(i=0;i<set[a].slen;++i)
			{
				j=i+1;
				while(j<set[a].slen)
				{
					if(set[a].character[i]==set[a].character[j])
					{
						for(k=j;k<set[a].slen;++k)
							set[a].character[k]=set[a].character[k+1];
						--set[a].slen;
					}
					else
						j++;
				}
			}
			break;
		case 3:
			for(i=0;i<set[a].slen;++i)
			{
				j=i+1;
				while(j<set[a].slen)
				{
					if(set[a].Float[i]==set[a].Float[j])
					{
						for(k=j;k<set[a].slen;++k)
							set[a].Float[k]=set[a].Float[k+1];
						--set[a].slen;
					}
					else
						j++;
				}
			}
			break;
		case 4:
			for(i=0;i<set[a].slen;++i)
			{
				j=i+1;
				while(j<set[a].slen)
				{
					if(set[a].Integer[i]==set[a].Integer[j])
					{
						for(k=j;k<set[a].slen;++k)
							set[a].Integer[k]=set[a].Integer[k+1];
						--set[a].slen;
					}
					else
						j++;
				}
			}
			break;
		default:
			putchar('E');
			putchar('\n');
			break;
	}
}

//delrptresult function
void delrptresult()
{
	int i,j,k;
	switch (result.Type)
	{
		case 1:
			for(i=0;i<result.slen;++i)
			{
				j=i+1;
				while(j<result.slen)
				{
					if(!strcmp(result.string[i],result.string[j]))
					{
						for(k=j;k<result.slen;++k)
							strcpy(result.string[k],result.string[k+1]);
						--result.slen;
					}
					else
						j++;
				}
			}
			break;
		case 2:
			for(i=0;i<result.slen;++i)
			{
				j=i+1;
				while(j<result.slen)
				{
					if(result.character[i]==result.character[j])
					{
						for(k=j;k<result.slen;++k)
							result.character[k]=result.character[k+1];
						--result.slen;
					}
					else
						j++;
				}
			}
			break;
		case 3:
			for(i=0;i<result.slen;++i)
			{
				j=i+1;
				while(j<result.slen)
				{
					if(result.Float[i]==result.Float[j])
					{
						for(k=j;k<result.slen;++k)
							result.Float[k]=result.Float[k+1];
						--result.slen;
					}
					else
						j++;
				}
			}
			break;
		case 4:
			for(i=0;i<result.slen;++i)
			{
				j=i+1;
				while(j<result.slen)
				{
					if(result.Integer[i]==result.Integer[j])
					{
						for(k=j;k<result.slen;++k)
							result.Integer[k]=result.Integer[k+1];
						--result.slen;
					}
					else
						j++;
				}
			}
			break;
		default:
			putchar('E');
			putchar('\n');
			break;
	}
}



//union function

void Union(char a,char b)
{
	int i,j,k,e;
	e=0;
	i=getID(a);
	j=getID(b);
	if(i<0 && j<0)
	{
		putchar('E');
		putchar('\n');
		return;
	}
	else if(set[i].Type!=set[j].Type)
	{
		putchar('E');
		putchar('\n');
		return;
	}
	else
	{
		switch(result.Type=set[i].Type)
		{
			case 1:
				for(k=0;k<set[i].slen;++k)
				       strcpy(result.string[e++],set[i].string[k]);
				for(k=0;k<set[j].slen;++k)
				       strcpy(result.string[e++],set[j].string[k]);
				break;
			case 2:
		      //		strcat(result.character,set[i].character);
			//	strcat(result.character,set[j].character);
				for(k=0;k<set[i].slen;++k)
					result.character[e++]=set[i].character[k];
				for(k=0;k<set[j].slen;++k)
					result.character[e++]=set[j].character[k];

				break;
			case 3:
				for(k=0;k<set[i].slen;++k)
					result.Float[e++]=set[i].Float[k];
				for(k=0;k<set[j].slen;++k)
					result.Float[e++]=set[j].Float[k];
				break;
			case 4:
				for(k=0;k<set[i].slen;++k)
					result.Integer[e++]=set[i].Integer[k];
				for(k=0;k<set[j].slen;++k)
					result.Integer[e++]=set[j].Integer[k];
				break;
			default:
				putchar('E');
				putchar('\n');
		}
		result.slen=set[i].slen+set[j].slen;
	}
}



//getID function



int getID(char a)
{
	int i;
	for(i=0;i<setcnt;++i)
		if(set[i].Name==a)
			return i;
	return -1;
}

//intersect  function

void intersect(char a,char b)
{
	int i,j,e,k,t=0;
	i=getID(a);
	j=getID(b);
	if(i<0 && j<0)
	{
		putchar('E');
		putchar('\n');
		return;
	}
	else if(set[i].Type!=set[j].Type)
	{
		putchar('E');
		putchar('\n');
		return;
	}
	else
	{
		switch(result.Type=set[i].Type)
		{
			case 1:
				for(e=0;e<set[i].slen;++e)
				{
					for(k=0;k<set[j].slen;++k)
						if(strcmp(set[i].string[e],set[j].string[k])==0)
							strcpy(result.string[t++],set[i].string[e]);
				}
				result.slen=t;
				break;
			case 2:
				for(e=0;e<set[i].slen;++e)
					for(k=0;k<set[j].slen;++k)
						if(set[i].character[e]==set[j].character[k])
							result.character[t++]=set[i].character[e];
				result.slen=t;
				break;
			case 3:
				for(e=0;e<set[i].slen;++e)
					for(k=0;k<set[j].slen;++k)
						if(set[i].Float[e]==set[j].Float[k])
							result.Float[t++]=set[i].Float[e];
				result.slen=t;
				break;
			case 4:
				for(e=0;e<set[i].slen;++e)
					for(k=0;k<set[j].slen;++k)
						if(set[i].Integer[e]==set[j].Integer[k])
							result.Integer[t++]=set[i].Integer[e];
				result.slen=t;
				break;
			default:
				putchar('E');
				break;
		}
	}
}

//difference function

void difference(char a,char b)
{
	int i,j,e,k,t=0,flag=0;
	i=getID(a);
	j=getID(b);
	if(i<0 && j<0)
	{
		putchar('E');
		return;
	}
	else if(set[i].Type!=set[j].Type)
	{
		putchar('E');
		return;
	}
	else
	{
		switch(result.Type=set[i].Type)
		{
			case 1:
				for(e=0;e<set[i].slen;++e)
				{
					for(k=0;k<set[j].slen;++k)
						if(strcmp(set[i].string[e],set[j].string[k])==0)
						{
							flag=1;
							break;
						}
					if(!flag)
						strcpy(result.string[t++],set[i].string[e]);

					flag=0;

				}
				result.slen=t;
				break;
			case 2:
				for(e=0;e<set[i].slen;++e)
				{
					for(k=0;k<set[j].slen;++k)
						if(set[i].character[e]==set[j].character[k])
						{
							flag=1;
							break;
						}
					if(!flag)
						result.character[t++]=set[i].character[e];
					flag=0;
				}
				result.slen=t;
				break;
			case 3:
				for(e=0;e<set[i].slen;++e)
				{
					for(k=0;k<set[j].slen;++k)
						if(set[i].Float[e]==set[j].Float[k])
						{
							flag=1;
							break;
						}
					if(!flag)
						result.Float[t++]=set[i].Float[e];
					flag=0;
				}
				result.slen=t;
				break;
			case 4:
				for(e=0;e<set[i].slen;++e)
				{
					for(k=0;k<set[j].slen;++k)
						if(set[i].Integer[e]==set[j].Integer[k])
						{
							flag=1;
							break;
						}
					if(!flag)
						result.Integer[t++]=set[i].Integer[e];
					flag=0;
				}
				result.slen=t;
				break;
			default:
				putchar('E');
				break;
		}
	}
}


//differenceresult function

void differenceresult(char b)
{
	int i,j,e,k,t=0,flag=0;
	j=getID(b);
	if(j<0)
	{
		putchar('E');
		return;
	}


		switch(result.Type)
		{
			case 1:
				for(e=0;e<result.slen;++e)
				{
					for(k=0;k<set[j].slen;++k)
						if(strcmp(result.string[e],set[j].string[k])==0)
						{
							flag=1;
							break;
						}
					if(!flag)
						strcpy(result.string[t++],result.string[e]);

					flag=0;

				}
				result.slen=t;
				break;
			case 2:
				for(e=0;e<result.slen;++e)
				{
					for(k=0;k<set[j].slen;++k)
						if(result.character[e]==set[j].character[k])
						{
							flag=1;
							break;
						}
					if(!flag)
						result.character[t++]=result.character[e];
					flag=0;
				}
				result.slen=t;
				break;
			case 3:
				for(e=0;e<result.slen;++e)
				{
					for(k=0;k<set[j].slen;++k)
						if(result.Float[e]==set[j].Float[k])
						{
							flag=1;
							break;
						}
					if(!flag)
						result.Float[t++]=result.Float[e];
					flag=0;
				}
				result.slen=t;
				break;
			case 4:
				for(e=0;e<result.slen;++e)
				{
					for(k=0;k<set[j].slen;++k)
						if(result.Integer[e]==set[j].Integer[k])
						{
							flag=1;
							break;
						}
					if(!flag)
						result.Integer[t++]=result.Integer[e];
					flag=0;
				}
				result.slen=t;
				break;
			default:
				putchar('E');
				break;
		}

}

//complement function

void complement(int a)
{
	int i,counter,j;
	result.slen=0;
	result.Type=set[a].Type;
	for(i=0;i<setcnt;++i)
		if(set[i].Type==set[a].Type  &&  set[i].Name!=set[a].Name)
		{
			switch(set[a].Type)
			{
				case 1:
					for(j=0;j<set[i].slen;++j)
						strcpy(result.string[result.slen++],set[i].string[j]);
					break;
				case 2:
					for(j=0;j<set[i].slen;++j)
						result.character[result.slen++]=set[i].character[j];
					break;
				case 3:
					for(j=0;j<set[i].slen;++j)
						result.Float[result.slen++]=set[i].Float[j];
					break;
				case 4:
					for(j=0;j<set[i].slen;++j)
						result.Integer[result.slen++]=set[i].Integer[j];
					break;
			}
			++counter;
		}
	switch (counter)
	{
		case 1:
			putchar('{');
			putchar('}');
			putchar('\n');
			break;
		default:
			delrptresult();
			differenceresult(set[a].Name);
			printresult();
	}
}

//print function

void print(int a)
{
	int i;
	switch(set[a].Type)
	{
		case 1:
			putchar('{');
			for(i=0;i<set[a].slen;++i)
			{
				putchar('"');
				printf("%s",set[a].string[i]);
				putchar('"');
				if(i+1!=set[a].slen)
					putchar(',');
			}
			putchar('}');
			putchar('\n');
			break;
		case 2:
			putchar('{');
			for(i=0;i<set[a].slen;++i)
			{
				putchar('\'');
				putchar(set[a].character[i]);
				putchar('\'');
				if(i+1!=set[a].slen)
					putchar(',');
			}
			putchar('}');
			putchar('\n');
			break;
		case 3:
			putchar('{');
			for(i=0;i<set[a].slen;++i)
			{
				printf("%2.3f",set[a].Float[i]);
				if(i+1!=set[a].slen)
					putchar(',');
			}
			putchar('}');
			putchar('\n');
			break;
		case 4:
			putchar('{');
			for(i=0;i<set[a].slen;++i)
			{
				printf("%d",set[a].Integer[i]);
				if(i+1!=set[a].slen)
					putchar(',');
			}
			putchar('}');
			putchar('\n');
			break;
		default:
			putchar('E');
			break;
	}
}

//printresult function

void printresult()
{
	int i;
	delrptresult();
	switch(result.Type)
	{
		case 1:
			putchar('{');
			for(i=0;i<result.slen;++i)
			{
				putchar('"');
				printf("%s",result.string[i]);
				putchar('"');
				if(i+1!=result.slen)
					putchar(',');
			}
			putchar('}');
			putchar('\n');
			break;
		case 2:
			putchar('{');
			for(i=0;i<result.slen;++i)
			{
				putchar('\'');
				putchar(result.character[i]);
				putchar('\'');
				if(i+1!=result.slen)
					putchar(',');
			}
			putchar('}');
			putchar('\n');
			break;
		case 3:
			putchar('{');
			for(i=0;i<result.slen;++i)
			{
				printf("%2.3f",result.Float[i]);
				if(i+1!=result.slen)
					putchar(',');
			}
			putchar('}');
			putchar('\n');
			break;
		case 4:
			putchar('{');
			for(i=0;i<result.slen;++i)
			{
				printf("%d",result.Integer[i]);
				if(i+1!=result.slen)
					putchar(',');
			}
			putchar('}');
			putchar('\n');
			break;
		default:
			putchar('E');
			break;
	}
}

//find function

int find(char a[],char b)
{
	int i,counter=0;
	for(i=0;a[i]!=EOF;++i)
		if(a[i]==b)
			++counter;
	return counter;
}


main()
{
	char line[MAXLINE];
	int n,counter=0;
	clrscr();
	hlp();
	while((n=read(line,MAXLINE)))
	{
		if(find(line,'{'))
		{
			save(line);
		}
		else
		{
			switch(n)
			{
				case 1:
					break;
				case 2:
					if(getID(line[0])>=0)
						print(getID(line[0]));
					else
						putchar('E');
					break;
				case 3:
					if(find(line,'-'))
					{
						if(getID(line[1])>=0)
							complement(getID(line[1]));
						else
							putchar('E');
					}
					else
						putchar('E');
					break;
				case 4:
					if(find(line,'*'))
					{
						intersect(line[0],line[2]);
						printresult();
					}
					else if(find(line,'+'))
					{
						Union(line[0],line[2]);
						printresult();
					}
					if(find(line,'-'))
					{
						difference(line[0],line[2]);
						printresult();
					 }
					 break;
				default :
					putchar('E');
					break;
			}
		}
	}
	getche();
}
