ADD = git add .
COMMIT = git commit -m "cast"
PUSH = git push

all:
	$(ADD) && $(COMMIT) && $(PUSH)
