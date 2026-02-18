ADD = git add .
COMMIT = git commit -m "cast"
PUSH = git pussh

all:
	$(ADD) && $(COMMIT) && $(PUSH)
