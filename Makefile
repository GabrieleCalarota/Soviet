Soviet: Main.o Map.o Node.o Player.o Inventario.o MyLibrary.o Letters.hpp Armor.o Visore.o SpecialAbility.o Weapon.o StartSoviet.o Tutorial.o Boss.o Coda.o Phrases.hpp Hash.o Task.o Enemy.o Database.o
	g++ -o Soviet Main.o Map.o Node.o Player.o Inventario.o MyLibrary.o Task.o Hash.o Visore.o Boss.o Enemy.o Tutorial.o SpecialAbility.o StartSoviet.o Database.o Coda.o Armor.o Weapon.o
Main.o: Main.cpp StartSoviet.hpp
	g++ -c Main.cpp
StartSoviet.o: StartSoviet.cpp StartSoviet.hpp
	g++ -c StartSoviet.cpp
Inventario.o: Inventario.cpp Inventario.hpp
	g++ -c Inventario.cpp
Player.o: Player.cpp Player.hpp 
	g++ -c Player.cpp
Map.o: Map.cpp Map.hpp Node.hpp
	g++ -c Map.cpp
Node.o: Node.cpp Node.hpp 
	g++ -c Node.cpp
MyLibrary.o: MyLibrary.cpp MyLibrary.hpp Colors.hpp
	g++ -c MyLibrary.cpp
Task.o: Task.cpp Task.hpp
	g++ -c Task.cpp
Enemy.o: Enemy.cpp Enemy.hpp
	g++ -c Enemy.cpp
Database.o: Database.cpp Database.hpp InfoEnemy.hpp
	g++ -c Database.cpp
Boss.o: Boss.cpp Boss.hpp
	g++ -c Boss.cpp
Coda.o: Coda.cpp Coda.hpp
	g++ -c Coda.cpp
Weapon.o: Weapon.cpp Weapon.hpp WeaponInfo.hpp
	g++ -c Weapon.cpp
Armor.o: Armor.cpp Armor.hpp ArmorInfo.hpp
	g++ -c Armor.cpp
Hash.o: Hash.cpp Hash.hpp
	g++ -c Hash.cpp
SpecialAbility.o: SpecialAbility.cpp SpecialAbility.hpp
	g++ -c SpecialAbility.cpp
Visore.o: Visore.cpp Visore.hpp
	g++ -c Visore.cpp
Tutorial.o: Tutorial.cpp Tutorial.hpp
	g++ -c Tutorial.cpp
clean:
	rm *.o *.exe
