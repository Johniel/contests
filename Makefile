all: clean gen

.PHONY: gen
gen:
	bash ./scripts/gen.sh

.PHONY: clean
clean:
	rm -rf ./docs/codeforces ./docs/atcoder
