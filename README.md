Write-Up by @BryceEJackson

# PDN Programming:  Parallel, Distributed and Network Programming

This repo contains coding practice and notes from:<br>"An Introduction to Parallel Programming", <br>
by Peter S. Pacheco and Matthew Malensek

#
## CHAPTER 1
#
Why we need ever-increasing performance: 
* We've been enjoying the increases in computational power for decades.
* Advances in fields like science, the internet, and entertainment. 
* With more computational power, our problem solving ability increases. 
* Climate Modeling, Protien Folding, Drug Discovery, Energy Research, Data Analysis...
#
Why we're building parallel systems: 
* Single-processor performance was driven by increasing transistor density. 
* As systems get smaller their clock speeds can be increased, but this uses more energy. 
* Much of this energy is dissipated as heat. 
* Systems have reached their thermal limits for the time being. 
* Because of these facts, we move to improve the parralelism of the systems. 
* a SINGLE CORE system is synonymous to a SINGLE CPU system. 
#
Why we need to write parallel programs: 
* Programs written for single core systems can't exploit the presence of multiple cores. 
* We need to rewrite serial programs so that they run parallel. 
* Conversion of serial C/C++/Java programs to parallel can't be done by a program. 
* Writing parallel programs means creating new algorithms that are different from their serial counterparts. 
#
How we write parallel programs: 
* parallelism requires partitioning the work to be done among the cores. 
* There are two widely used approached: task-parallelism & data-parallelism
* Task Parallelism: partition the various tasks among the cores. 
* Data Parallelism: partition the data among the cores, each core carries out similar operations. 
* matrix multiplication algorithm (Sec. 1.3) is considered to be data-paralelism. 
* The parallel approach requires cores to be coordinated.
* Coordination encompases COMMUNICATION, LOAD BALANCING, and SYNCHRONIZATION. 
* SYNCHRONIZATION brings about the RACE CONDITION. 
#
What we'll be doing: 
* learning to write programs that are explicitly parallel. 
* We will be using the C language, and FOUR API's
* MPI, POSIX threads(Pthreads), OpenMP, and CUDA
* MPI and Pthreads are libraries of type definitions, functions, and macros that can be used in C programs. 
* OpenMP consists of a library and some modifications to the C compiler. 
* CUDA consists of a library and modifications to the C++ compiler. 
* Two Types of Parallel Systems: one is considering the memory that the different cores have access to, the other is to consider whether the cores can operate independently of eachother. 
* We'll cover SHARED and DISTRIBUTED MEMORY systems. 
* SHARED: cores share access to memory. each core can read/write each memory location.
* In a shared memory system, we can coordinate the cores by having them examine and update shared memory locations.
DISTRIBUTED: each core has its own, private memory. cores communicate explicitly by sending mesages across the network.
* MIMD: Multiple Instruction Multiple Data ( Conventional Processors )
* Two cores can execute different instructions in SIMD
* SIMD: Single Instruction Multiple Data( Cores Share Control Unit )
* Two cores either execute the same instruction, or one waits idle until the other is finished executing its instruction.
* MPI is for distributed memory MIMD systems. 
* Pthreads is for shared memory MIMD systems. 
* OpenMP is for shared memory MIMD and SIMD systems, although we will focus on MIMD. 
* CUDA is for Nvidia GPU's, we will focus on shared memory SIMD/MIMD
#
Concurrent, Parallel, and Distributed systems

CONCURRENT: a program has multiple tasks in progress at a time. <br>
PARALLEL: A program has multiple tasts cooperate to solve a problem. <br>
DISTRIBUTED: A program may need to cooperate with another program to solve a problem.
#
## CHAPTER 2
#
 TODO
#
