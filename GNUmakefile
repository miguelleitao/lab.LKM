


-include Makefile

all:
	make clean
	cp -p ok/mymodule1.c mymodule.c
	make
	make clean
	cp -p ok/mymodule2.c mymodule.c
	make
	make clean
	cp -p ok/mymodule3.c mymodule.c
	make
	make clean
	cp -p ok/mymodule4.c mymodule.c
	make
	make clean
	cp -p ok/mymodule5.c mymodule.c
	make
	make clean
	cp -p ok/mymodule6.c mymodule.c
	make

push:
	git add .
	git commit -m update
	git push

