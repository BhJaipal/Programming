if [ $2 = "test" ]; then
	rm -rf build/test
elif [ $2 = "app" ]; then
	rm -rf build/app
else
	echo "\033[1;31mError:\033[0m Invalid argument.\n\tPlease provide either 'app' or 'test' as an argument."
fi
