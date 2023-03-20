tests.exe: TestUserRules.o f.o MockUserRepository.o UserRules.o ModelUser.o exceptions.o IUserRepository.o
	g++ -o $@ $^ -lgtest

ModelUser.o: ../../business_logic/models/ModelUser.cpp
	g++ -c -o $@ $<

TestUserRules.o: TestUserRules.cpp
	g++ -c -o $@ $<

MockUserRepository.o: ../../data_access/MockRepositories/MockUserRepository.cpp
	g++ -c -o $@ $<

UserRules.o: ../../business_logic/rules/UserRules.cpp
	g++ -c -o $@ $<

exceptions.o: ../../business_logic/exceptions/exceptions.cpp
	g++ -c -o $@ $<

IUserRepository.o: ../../business_logic/IRepositories/IUserRepository.cpp
	g++ -c -o $@ $<

f.o: f.cpp
	g++ -c -o $@ $<

#./tests.exe --gtest_filter=g