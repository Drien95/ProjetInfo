#
SRC = src
INC = inc 
BIN = bin
SAVE = save
current_dir = $(shell pwd)
dir = $(notdir $(shell pwd))
#
CC = gcc
EXEC = toto
CFLAGS = -Wall -std=c99 -fsanitize=address -static-libasan -g
#
SOURCE = $(wildcard ${SRC}/*.c)
INCO = $(wildcard ${INC}/*.h)
OBJ = $(patsubst %,$(BIN)/%,$(notdir $(SOURCE:.c=.o)))
#
RM = rm -f all ${BIN}/*.o
# 



.PHONY : all
all : ${EXEC}

${EXEC} : ${OBJ}
	${CC} -o $@ $^ -lm -fsanitize=address -static-libasan -g
${BIN}/%.o : ${SRC}/%.c
	${CC} ${CFLAGS} -c $< -o $@ 

.PHONY : clean
clean : 
	@${RM} ${EXEC}

.PHONY : run save restore tar
run : ${EXEC}
	./${EXEC}
save : ${SOURCE} ${INCO}
	@cp -r ${SRC} ${SAVE}/ 
	@cp -r ${INC} ${SAVE}/
restore :
	@rm -rf ${INC}
	@rm -rf ${SRC}
	@cp -r ${SAVE}/${INC} ./
	@cp -r ${SAVE}/${SRC} ./
tar : 
	tar -czvf ${dir}.tar.gz ${current_dir}
