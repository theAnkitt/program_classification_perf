

## Perf
The perf command is used as a primary interface to the Linux kernel performance monitoring capabilities and can record CPU performance counters and trace points. <br />

>perf [--version] [--help] [OPTIONS] COMMAND [ARGS] <br />
>perf --help

help command will give you more insight into perf tools.<br/>

Steps to get the values of perf events :- <br/>
**step 1** : create file filename.sh <br/>
**step 2** : paste the code given below and edit the file name each time.(filename is c program filename)


```
clang filename.c -o filename

sudo perf stat -e power/energy-pkg/,uncore_imc/data_reads/,uncore_imc/data_writes/ ./filename

sudo perf stat -e branches,branch-misses,branch-loads,branch-load-misses,cache-misses,cpu-cycles,instructions,context-switches,fp_arith_inst_retired.scalar_single,LLC-stores,LLC-loads ./filename

sudo perf stat -e LLC-store-misses,LLC-load-misses,L1-dcache-stores,L1-dcache-loads ./filename  

sudo perf stat -e L1-dcache-load-misses,L1-icache-load-misses ./filename
```
**step 3** : save the .sh file to the same location where c program is saved. Gvie executable permission to sh file. <br/>
**step 4** : configure the c program file and get the input file for the programs.<br/>
**step 5** : run the .sh file.<br/>

Result will looks something like this : <br/>

![Output Screenshort](https://i.pinimg.com/750x/e5/87/80/e587801d3323bff8741bdc4e891c9a48.jpg?raw=true) <br/>



<br/>
create file filename.sh and write the following code inside and save it and run inside the folder with the programs. <br/>



## Programs

1. Selected algorithms.
    * BFS
    * Quick Sort
    * Fibonacci series
    * Tower of Hanoi
    * Fractional Knapsack
    * Bubble Sort
    * Selection Sort
    * Insertion Sort
    * Merge Sort
    * Bucket Sort
    * Radix sort
2. Benchmark
    * coremark
    * Dhrystone
        *   dhrystone
        *   dhrystone-reg
    * linpack
        *   linpackdp
        *   linpacksp
    * tripforce
        *   tripfind
<br />

Benchmark program source : https://github.com/nfinit/ansibench <br/>
For benchmark program go through the readme file in ansibench.<br/>
<br/>

| APPLICATIONS | INPUT SIZE |
| ------------ | ---------- |
| BFS	| 30000 |
| Quick Sort	| 500000 |
| Fibonacci series | 50 |
| Tower of Hanoi	| 35 |
| Fractional Knapsack	| 1000000 |
| Bubble Sort	| 100000 |
| Selection Sort	| 500000 |
| Insertion Sort	| 500000 |
| Merge Sort	| 500000 |
| Bucket Sort	| 100000 | 
| Radix sort	| 500000 |
| coremark	| 2000000 |
| dhrystone	| 1410065408 |
| dhrystone-reg	| 1410065408 |
| linpackdp	| 3000 |
| linpacksp	| 3000 |
| tripfind	| NA |

<br/>

input files are in input folder.

<br/>
Generated dataset link : https://docs.google.com/spreadsheets/d/1TPHpm2SB1pnXAvvm9By__Ly6OQd9IzUZ/edit?rtpof=true#gid=527532308 
