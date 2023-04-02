testsUserRepo.exe: TestUserRepo.o PgUserRepository.o UserRules.o ModelUser.o connection.o PostgresCommands.o exceptions.o
	g++ -o $@ $^ -lgtest -lpqxx

ModelUser.o: ../../business_logic/models/ModelUser.cpp
	g++ -c -o $@ $<

ModelManager.o: ../../business_logic/models/ModelManager.cpp
	g++ -c -o $@ $<

ModelBank.o: ../../business_logic/models/ModelBank.cpp
	g++ -c -o $@ $<

ModelClient.o: ../../business_logic/models/ModelClient.cpp
	g++ -c -o $@ $<

ModelProduct.o: ../../business_logic/models/ModelProduct.cpp
	g++ -c -o $@ $<

ModelRequest.o: ../../business_logic/models/ModelRequest.cpp
	g++ -c -o $@ $<

TestUserRepo.o: TestUserRepo.cpp
	g++ -c -o $@ $<

PgUserRepository.o: ../../data_access/PostgresRepositories/PgUserRepository.cpp
	g++ -c -o $@ $<

UserRules.o: ../../business_logic/rules/UserRules.cpp
	g++ -c -o $@ $<

ManagerRules.o: ../../business_logic/rules/ManagerRules.cpp
	g++ -c -o $@ $<

ProductRules.o: ../../business_logic/rules/ProductRules.cpp
	g++ -c -o $@ $<

RequestRules.o: ../../business_logic/rules/RequestRules.cpp
	g++ -c -o $@ $<

ClientRules.o: ../../business_logic/rules/ClientRules.cpp
	g++ -c -o $@ $<

BankRules.o: ../../business_logic/rules/BankRules.cpp
	g++ -c -o $@ $<

exceptions.o: ../../business_logic/exceptions/exceptions.cpp
	g++ -c -o $@ $<

connection.o: ../../data_access/connection/connection.cpp
	g++ -c -o $@ $<

PostgresCommands.o: ../../data_access/commands/PostgresCommands.cpp
	g++ -c -o $@ $<

f.o: f.cpp
	g++ -c -o $@ $<

clean:
	rm -rf *.o *.exe
#./tests.exe --gtest_filter=g