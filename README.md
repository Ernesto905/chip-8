# chip-8
Chip 8 ~~emulator~~ interpreter. Work in progress

# Spec
https://tobiasvl.github.io/blog/write-a-chip-8-emulator

# Build && run
1. Clone 
```bash
git clone --recursive https://github.com/Ernesto905/chip-8.git
```

2. Build 
```
cmake -S . -B build
cmake --build build
```

3. Run 
```
./build/chip_8 roms/IBM_Logo_test.ch8
```
