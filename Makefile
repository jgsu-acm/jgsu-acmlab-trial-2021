mk = latexmk -cd -xelatex

ifeq ($(OS), Windows_NT)
    rm = del
else
    rm = rm -f
endif

.PHONY: problem solution clean

all: problem solution

problem:
	$(mk) problem/problem.tex

solution:
	$(mk) solution/solution.tex

clean:
	cd problem && latexmk -C && $(rm) problem.bbl && $(rm) problem.run.xml
	cd solution && latexmk -C && $(rm) solution.bbl && $(rm) solution.run.xml
