cd $1/test && cmake -S . -B build && cd build && make all && cd ../../ && clear && ./bin/test-run.exe
