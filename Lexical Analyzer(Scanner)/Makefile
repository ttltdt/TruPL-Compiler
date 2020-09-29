token.o:	token.h token.cpp
	clang++ -c -g -Wall --pedantic token.cpp

keywordtoken.o:	keywordtoken.h keywordtoken.cpp token.h
	clang++ -c -g -Wall --pedantic keywordtoken.cpp

punctoken.o:	punctoken.h punctoken.cpp token.h
	clang++ -c -g -Wall --pedantic punctoken.cpp

reloptoken.o:	reloptoken.h reloptoken.cpp token.h
	clang++ -c -g -Wall --pedantic reloptoken.cpp

addoptoken.o:	addoptoken.h addoptoken.cpp token.h
	clang++ -c -g -Wall --pedantic addoptoken.cpp

muloptoken.o:	muloptoken.h muloptoken.cpp token.h
	clang++ -c -g -Wall --pedantic muloptoken.cpp

idtoken.o:	idtoken.h idtoken.cpp token.h
	clang++ -c -g -Wall --pedantic idtoken.cpp

numtoken.o:	numtoken.h numtoken.cpp token.h
	clang++ -c -g -Wall --pedantic numtoken.cpp

eoftoken.o:	eoftoken.h eoftoken.cpp token.h
	clang++ -c -g -Wall --pedantic eoftoken.cpp

buffer.o:	buffer.h buffer.cpp
	clang++ -c -g -Wall --pedantic buffer.cpp

scanner.o:	scanner.h scanner.cpp buffer.h token.h keywordtoken.h \
		punctoken.h reloptoken.h addoptoken.h muloptoken.h \
		idtoken.h numtoken.h eoftoken.h
	clang++ -c -g -Wall --pedantic scanner.cpp

test_scanner.o:	test_scanner.cpp scanner.h token.h keywordtoken.h \
		punctoken.h reloptoken.h addoptoken.h muloptoken.h \
		idtoken.h numtoken.h eoftoken.h
	clang++ -c -g -Wall --pedantic test_scanner.cpp

test_scanner:	test_scanner.o scanner.o buffer.o token.o keywordtoken.o \
		punctoken.o reloptoken.o addoptoken.o \
		muloptoken.o idtoken.o numtoken.o eoftoken.o
	clang++ -o test_scanner -g -Wall --pedantic scanner.o \
		buffer.o eoftoken.o numtoken.o \
		idtoken.o muloptoken.o \
		addoptoken.o reloptoken.o punctoken.o keywordtoken.o \
		token.o test_scanner.o

tokendriver.o:	tokendriver.cpp token.h keywordtoken.h \
		punctoken.h reloptoken.h addoptoken.h muloptoken.h \
		idtoken.h numtoken.h eoftoken.h
	clang++ -c -g -Wall --pedantic tokendriver.cpp

tokendriver:	tokendriver.o token.o keywordtoken.o \
		punctoken.o reloptoken.o addoptoken.o \
		muloptoken.o idtoken.o numtoken.o eoftoken.o
	clang++ -o tokendriver -g -Wall --pedantic\
		eoftoken.o numtoken.o \
		idtoken.o muloptoken.o \
		addoptoken.o reloptoken.o punctoken.o keywordtoken.o \
		token.o tokendriver.o

buffer_driver.o: buffer_driver.cpp buffer.h
	clang++ -c -g -Wall --pedantic buffer_driver.cpp

buffer_driver: buffer.cpp buffer.o buffer_driver.cpp buffer_driver.o 
	clang++ -o buffer_driver -g -Wall --pedantic buffer.o buffer_driver.o

clean:	
	rm -f *.o test_scanner

all:	test_scanner
