if [ $2 = "test" ]; then
	cd test
	cmake -S . -B build
	cd build
	make all
elif [ $2 = "app" ]; then
	cmake -S . -B build
	cd build
	make all
else
	echo "\033[1;31mError:\033[0m Invalid argument.\n\tPlease provide either 'app' or 'test' as an argument."
fi
