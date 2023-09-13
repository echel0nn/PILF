# PILF
Projects I Would Like to Fuzz

## LIST

* [LibHTP](https://github.com/OISF/libhtp)
	* [Harness](harness_dir/fuzz_htp.c) 
* [LIEF](https://github.com/lief-project/LIEF)
	* [Harness](harness_dir/fuzz_lief_elf.cpp)
		- [found a bug](https://github.com/lief-project/LIEF/issues/958)
* [miasm](https://github.com/cea-sec/miasm)
	* [Harness](./harness_dir/fuzz_miasm.py)

## Utils 
* [ELF AFL++ Mutator based on LibGolf](https://github.com/AFLplusplus/AFLplusplus/blob/stable/custom_mutators/examples/elf_header_mutator.c)
* [ELF Binary Fuzzing Examples/Build Steps](https://github.com/echel0nn/golfuzz)
	* [Example Build Steps](https://github.com/echel0nn/golfuzz/blob/main/examples/04_afl/how_to_build.md)
* [afl-utils](https://gitlab.com/rc0r/afl-utils)
	* automated crash sample collection, verification, reduction and analysis (afl-collect, afl-vcrash)
	* easy management of parallel (multi-core) fuzzing jobs (afl-multicore, afl-multikill)
	* corpus optimization (afl-minimize)
	* fuzzer stats supervision (afl-stats)
	* fuzzer queue synchronisation (afl-sync)
	* autonomous utility execution (afl-cron)
* [Exploitable GDB Plugin](https://gitlab.com/rc0r/exploitable)

