clear
if [ $2 = "app" ]; then
	if [ -f bin/run.exe ]; then
		./bin/run.exe
	else
		echo "\033[1;31mError:\033[0m No executable found, please build app first"
	fi
elif [ $2 = "test" ]; then
	if [ -f bin/test-run.exe ]; then
		./bin/test-run.exe
	else
		echo "\033[1;31mError:\033[0m No executable found, please build test first"
	fi
else
	echo "\033[1;31mError:\033[0m Invalid argument.\n\tPlease provide either 'app' or 'test' as an argument."
fi
