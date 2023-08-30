#change filename before executing this bash code.

clang filename.c -o filename

sudo perf stat -e power/energy-pkg/,uncore_imc/data_reads/,uncore_imc/data_writes/ ./filename

sudo perf stat -e branches,branch-misses,branch-loads,branch-load-misses,cache-misses,cpu-cycles,instructions,context-switches,fp_arith_inst_retired.scalar_single,LLC-stores,LLC-loads ./filename

sudo perf stat -e LLC-store-misses,LLC-load-misses,L1-dcache-stores,L1-dcache-loads ./filename  

sudo perf stat -e L1-dcache-load-misses,L1-icache-load-misses ./filename
