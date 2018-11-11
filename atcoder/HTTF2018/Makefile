all:
	g++ -std=c++14 ./main.cpp -O2
	time ./a.out < sample1.in > sample1.out
	perl -pe 's/\n/\r\n/' ./sample1.out > ./sample1.out.dos
	cat ./sample1.out
