CC=gcc
AFLAGS=-Wall -g
LDFLAGS= -lmysqlclient
OBJS= add.cgi del.cgi mod.cgi sel.cgi admin_del.cgi sel_score.cgi mod_score.cgi add_course.cgi sel_course.cgi mod_course.cgi del_course.cgi add_school.cgi sel_school.cgi mod_school.cgi del_school.cgi add_score.cgi

all:$(OBJS)

$(OBJS):%.cgi:%.c
	$(CC) $(AFLAGS) $< cgic.c -o $@ $(LDFLAGS)

.PHONY:clean
clean:
	rm ./*.cgi
install:
		cp *.cgi /usr/lib/cgi-bin/sx
		cp head.html footer.html  /usr/lib/cgi-bin/sx/
		sudo cp -r public/ index.html student.html teacher.html admin.html /var/www/html/
