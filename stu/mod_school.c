#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <mysql/mysql.h>
#include "cgic.h"
char * headname = "head.html";
char * footname = "footer.html";
int cgiMain()
{


	FILE * fd;
	char ch;
	fprintf(cgiOut, "Content-type:text/html;charset=utf-8\n\n");

	if(!(fd = fopen(headname, "r"))){
			fprintf(cgiOut, "Cannot open file, %s\n", headname);
			return -1;
		}
		ch = fgetc(fd);

		while(ch != EOF){
			fprintf(cgiOut, "%c", ch);
			ch = fgetc(fd);
		}
	fclose(fd);

	char xname[32] = "\0";
	char xno[32] = "\0";
	int status = 0;

	status = cgiFormString("xname", xname, 32);
	if (status != cgiFormSuccess)
	{
		fprintf(cgiOut, "get xname error!\n");
		return 1;
	}


	status = cgiFormString("xno",  xno, 32);
	if (status != cgiFormSuccess)
	{
		fprintf(cgiOut, "get xno error!\n");
		return 1;
	}



	//fprintf(cgiOut, "name = %s, age = %s, stuId = %s\n", name, age, stuId);

	int ret;
	char sql[128] = "\0";
	MYSQL *db;

	//初始化
	db = mysql_init(NULL);
	if (db == NULL)
	{
		fprintf(cgiOut,"mysql_init fail:%s\n", mysql_error(db));
		return -1;
	}

	//连接数据库
	db = mysql_real_connect(db, "127.0.0.1", "root", "123456", "stu",  3306, NULL, 0);
	if (db == NULL)
	{
		fprintf(cgiOut,"mysql_real_connect fail:%s\n", mysql_error(db));
		mysql_close(db);
		return -1;
	}


	sprintf(sql, "update school set xname = '%s' where xno = '%s' ", xname, xno);
	if ((ret = mysql_real_query(db, sql, strlen(sql) + 1)) != 0)
	{
		fprintf(cgiOut,"mysql_real_query fail:%s\n", mysql_error(db));
		mysql_close(db);
		return -1;
	}



	fprintf(cgiOut, "update school ok!\n");
	mysql_close(db);
	return 0;
}
