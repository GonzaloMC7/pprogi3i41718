CC = gcc -ansi -pedantic -g
CFLAGS = -Wall
EXE = game_loop set_test die_test

all : $(EXE)

.PHONY : clean
clean :
	rm -f *.o core $(EXE)

$(EXE) : % : %.o command.o game.o graphic_engine.o screen.o space.o game_reader.o player.o object.o set.o die.o
	@echo "#---------------------------"
	@echo "# Generando $@ "
	@echo "# Depende de $^"
	@echo "# Ha cambiado $<"
	$(CC) $(CFLAGS) -o $@ $@.o command.o game.o graphic_engine.o screen.o space.o game_reader.o player.o object.o set.o die.o

 command.o : command.c command.h
	@echo "#---------------------------"
	@echo "# Generando $@"
	@echo "# Depende de $^"
	@echo "# Ha cambiado $<"
	$(CC) $(CFLAGS) -c $<

 game.o : game.c game.h
	@echo "#---------------------------"
	@echo "# Generando $@"
	@echo "# Depende de $^"
	@echo "# Ha cambiado $<"
	$(CC) $(CFLAGS) -c $<
	
 game_reader.o : game_reader.c game_reader.h
	@echo "#---------------------------"
	@echo "# Generando $@"
	@echo "# Depende de $^"
	@echo "# Ha cambiado $<"
	$(CC) $(CFLAGS) -c $<	

 graphic_engine.o : graphic_engine.c graphic_engine.h
	@echo "#---------------------------"
	@echo "# Generando $@"
	@echo "# Depende de $^"
	@echo "# Ha cambiado $<"
	$(CC) $(CFLAGS) -c $<

 screen.o : screen.c screen.h
	@echo "#---------------------------"
	@echo "# Generando $@"
	@echo "# Depende de $^"
	@echo "# Ha cambiado $<"
	$(CC) $(CFLAGS) -c $<

 space.o : space.c space.h
	@echo "#---------------------------"
	@echo "# Generando $@"
	@echo "# Depende de $^"
	@echo "# Ha cambiado $<"
	$(CC) $(CFLAGS) -c $<
	
 object.o : object.c object.h
	@echo "#---------------------------"
	@echo "# Generando $@"
	@echo "# Depende de $^"
	@echo "# Ha cambiado $<"
	$(CC) $(CFLAGS) -c $<
	
 player.o : player.c player.h
	@echo "#---------------------------"
	@echo "# Generando $@"
	@echo "# Depende de $^"
	@echo "# Ha cambiado $<"
	$(CC) $(CFLAGS) -c $< 
	
 set.o : set.c set.h
	@echo "#---------------------------"
	@echo "# Generando $@"
	@echo "# Depende de $^"
	@echo "# Ha cambiado $<"
	$(CC) $(CFLAGS) -c $<
	
 die.o : die.c die.h
	@echo "#---------------------------"
	@echo "# Generando $@"
	@echo "# Depende de $^"
	@echo "# Ha cambiado $<"
	$(CC) $(CFLAGS) -c $<
	
tar:
	tar -zcvf I2_Grupo2161_JavierMartin_GonzaloMartinez.tar.gz *.h *.c *.dat *.txt makefile README.txt
	
game_loop_test:
	@echo Ejecutando game_loop
	@./game_loop new_data.dat

set_test_:
	@echo Ejecutando set_test
	@ valgrind --leak-check=full ./set_test 
	
die_test_:
	@echo Ejecutando set_die
	@ valgrind --leak-check=full ./die_test 

	