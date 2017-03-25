.PHONY: clean

container_test: container_of_test.o
	g++ -o $@ $< -lgtest -lgtest_main
clean:
	rm container_test *.o
