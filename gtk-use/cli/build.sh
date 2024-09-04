if [ $2 = "test" ]; then
	cd test
	cmake -S . -B ../build/test
	cd ../build/test
	make all
elif [ $2 = "app" ]; then
	cmake -S . -B build/app
	cd build/app
	make all
else
	echo -e "\033[1;31mError:\033[0m Invalid argument.\n\tPlease provide either 'app' or 'test' as an argument."
fi
