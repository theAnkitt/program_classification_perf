

## Perf
The perf command is used as a primary interface to the Linux kernel performance monitoring capabilities and can record CPU performance counters and trace points. <br />

>perf [--version] [--help] [OPTIONS] COMMAND [ARGS] <br />
>perf --help

help command will give you more insight into perf tools.<br/>

Steps to get the values of perf events :- <br/>
**step 1** : create file filename.sh <br/>
**step 2** : paste the code given below and edit the file name each time.


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

![Output Screenshort]( https://github.com/theAnkitt/program_classification_perf/blob/main/output.jpeg?raw=true) <br/>



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

