all: Polaris

Polaris: ./src/BaseEditor.c
	$(CC) src/BaseEditor.c src/RawMode.c -Wall -Wextra -Wpedantic -std=c99 -o build/polaris

clean: 
	rm -f build/polaris.exe