DOC=requirements


all: $(DOC).pdf

clean:
	rm $(DOC).log \
	$(DOC).pdf \
	$(DOC).toc \
	$(DOC).aux \
	$(DOC).out \

$(DOC).pdf: $(DOC).tex
	pdflatex -file-line-error -interaction=nonstopmode $(DOC)
	pdflatex -file-line-error -interaction=nonstopmode $(DOC)
