LATEXCMD = pdflatex -shell-escape -output-directory build/
export TEXINPUTS=.:src/tex/:
export max_print_line = 1048576

help:
	@echo "This makefile builds KACTL (KTH Algorithm Competition Template Library)"
	@echo ""
	@echo "Available commands are:"
	@echo "	make fast		- to build KACTL, quickly (only runs LaTeX once)"
	@echo "	make kactl		- to build KACTL"
	@echo "	make clean		- to clean up the build process"
	@echo "	make veryclean		- to clean up and remove kactl.pdf"
	@echo "	make test		- to run all the stress tests in stress-tests/"
	@echo "	make test-compiles	- to test compiling all headers"
	@echo "	make help		- to show this information"
	@echo "	make showexcluded	- to show files that are not included in the doc"
	@echo ""
	@echo "For more information see the file 'doc/README'"

fast: | build
	$(LATEXCMD) src/kactl.tex </dev/null
	cp build/kactl.pdf kactl.pdf

kactl: test-session.pdf | build
	$(LATEXCMD) src/kactl.tex && $(LATEXCMD) src/kactl.tex
	cp build/kactl.pdf kactl.pdf

clean:
	cd build && rm -f kactl.aux kactl.log kactl.tmp kactl.toc kactl.pdf kactl.ptc

veryclean: clean
	rm -f kactl.pdf test-session.pdf

.PHONY: help fast kactl clean veryclean

build:
	mkdir -p build/

test:
	./doc/scripts/run-all.sh .

test-compiles:
	./doc/scripts/compile-all.sh .

test-session.pdf: src/test-session/test-session.tex src/test-session/chapter.tex | build
	$(LATEXCMD) src/test-session/test-session.tex
	cp build/test-session.pdf test-session.pdf

showexcluded: build
	grep -RoPh '^\s*\\kactlimport{\K.*' src/ | sed 's/.$$//' > build/headers_included
	find ./src -name "*.h" -o -name "*.py" -o -name "*.java" | grep -vFf build/headers_included
