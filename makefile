CC = gcc -ansi -pedantic -g
CFLAGS = -Wall
EXE = game_loop set_test die_test space_test link_test inv_test

all : $(EXE)

.PHONY : clean
clean :
	rm -f *.o core $(EXE)
	rm -f *.log

$(EXE) : % : %.o command.o game.o graphic_engine.o screen.o space.o game_reader.o player.o object.o set.o die.o inventory.o link.o
	@echo "#---------------------------"
	@echo "# Generando $@ "
	@echo "# Depende de $^"
	@echo "# Ha cambiado $<"
	$(CC) $(CFLAGS) -o $@ $@.o command.o game.o graphic_engine.o screen.o space.o game_reader.o player.o object.o set.o die.o inventory.o link.o

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

inventory.o : inventory.c inventory.h
	@echo "#---------------------------"
	@echo "# Generando $@"
	@echo "# Depende de $^"
	@echo "# Ha cambiado $<"
	$(CC) $(CFLAGS) -c $<

link.o : link.c link.h
	@echo "#---------------------------"
	@echo "# Generando $@"
	@echo "# Depende de $^"
	@echo "# Ha cambiado $<"
	$(CC) $(CFLAGS) -c $<



tar:
	tar -zcvf I2_Grupo2161_JavierMartin_GonzaloMartinez.tar.gz *.h *.c *.dat *.log *.txt makefile README.txt

game_loop_test:
	@echo Ejecutando game_loop
	@ ./game_loop new_data.dat -l comandos.log

set_test_:
	@echo Ejecutando set_test
	@ ./set_test

die_test_:
	@echo Ejecutando set_die
	@ ./die_test

space_test_:
	@echo Ejecutando space_test
	@ ./space_test

link_test_:
	@echo Ejecutando link_test
	@ ./link_test

inv_test_:
	@echo Ejecutando inv_test
	@ ./inv_test


doxy:
	doxygen -g
	doxygen Doxyfile
