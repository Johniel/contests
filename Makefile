all: gen

.PHONY: gen
gen:
		find codeforces atcoder -name "README.md" | go run ./scripts/gen.go
