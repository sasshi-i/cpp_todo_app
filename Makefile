PWD := $(shell pwd)
SRC_DIR := /src
SRCS := /src/main.cpp /src/database.cpp /src/tasks.cpp
OBJS := /src/main.o /src/database.o /src/tasks.o
TARGET := todo
LDLIBS := -lm -lmysqlcppconn

# $(OBJS): $(SRC_DIR)/%.cppの形で実装するように要修正
cp:
	docker run --rm -v $(PWD)/src:/src cpp_todo_app g++ -O2 -c -o /src/main.o /src/main.cpp
	docker run --rm -v $(PWD)/src:/src cpp_todo_app g++ -O2 -c -o /src/database.o /src/database.cpp $(LDLIBS)
	docker run --rm -v $(PWD)/src:/src cpp_todo_app g++ -O2 -c -o /src/tasks.o /src/tasks.cpp
	docker run --rm -v $(PWD)/src:/src cpp_todo_app g++ -o /src/todo $(OBJS) $(LDLIBS)

# $(OBJS): $(SRC_DIR)/%.cpp
# 	docker run --rm -v $(PWD)/src:/src cpp_todo_app g++ -O2 -c -o $@ $<

exec:
	docker-compose run --rm -v $(PWD)/src:/src app ./src/todo $(MODE) $(ARG1) $(ARG2)

clean:
	rm -f ./src/todo
	rm -f ./src/*.o