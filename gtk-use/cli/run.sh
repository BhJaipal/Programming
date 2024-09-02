cd $1
cmake -S . -B build
cd build
make all
cd ..
./bin/run.exe
