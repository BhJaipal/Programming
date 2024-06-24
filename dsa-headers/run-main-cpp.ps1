if (!(Test-Path -Path 'out')) {
  New-Item -ItemType Directory -Path 'out'
}

if (!(Test-Path -Path 'out\c')) {
  New-Item -ItemType Directory -Path 'out\c'
}
if (!(Test-Path -Path 'out\cpp')) {
  New-Item -ItemType Directory -Path 'out\cpp'
}
g++ main.cpp -o out/cpp/run.exe
./out/cpp/run.exe
