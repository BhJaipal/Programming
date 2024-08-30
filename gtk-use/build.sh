if [ ! -d "out/" ]; then
	mkdir out
fi

cd out && cmake .. && make all
