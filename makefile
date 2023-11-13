default:
	gcc -std=c11 -fdiagnostics-color=always -g main.c -o bin/main.exe

windows:
	gcc -std=c11 -fdiagnostics-color=always -g main.c -o bin/main.exe

linux:
	gcc -std=c11 -fdiagnostics-color=always -g main.c -o bin/main