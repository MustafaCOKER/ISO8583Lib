SRC 	:= src
EXAMPLE	:= example
TEST	:= test

all: makedirs build

build:
	$(MAKE) -C $(SRC) build
	$(MAKE) -C $(EXAMPLE) build
	$(MAKE) -C $(TEST) build

makedirs:
	$(MAKE) -C $(SRC) makedirs
	$(MAKE) -C $(EXAMPLE) makedirs
	$(MAKE) -C $(TEST) makedirs
	
clean:
	$(MAKE) -C $(SRC) clean
	$(MAKE) -C $(EXAMPLE) clean
	$(MAKE) -C $(TEST) clean