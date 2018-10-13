# SDD Compile Times

On my MacBook Pro

## Trial 1: CNF-to-SDD  (bottom-up)

#### Compiler
sdd-package-2/sdd-2.0
I called from code using function: fnf_to_sdd()

#### CNF file
sdd-package-2/sdd-2.0/cnf/c432.isc.cnf
File size: 11kb
vars=432
clauses=986

#### Results
Compilation time: 19.926 sec
Model count: 68719476736
sdd file size: 221kb

## Trial 2: CNF-to-Decision-DNNF (top-down)

#### Compiler
miniC2D-1.0.0
I called from the command line using:
./bin/darwin/miniC2D -C -c ../sdd-package-2/sdd-2.0/cnf/c432.isc.cnf

#### CNF file
sdd-package-2/sdd-2.0/cnf/c432.isc.cnf
File size: 11kb
vars=432
clauses=986


#### Results
Compilation time: 4.359s
Model count: 68719476736
nnf file size: 10.1mb

#### Output
```
Constructing CNF... DONE
CNF stats: 
  Vars=432 / Clauses=986
  CNF Time	0.002s
Constructing vtree (from primal graph)... DONE
Vtree stats:
  Vtree widths: con<=29, c_con=201 v_con=29
  Vtree Time	0.036s
Compiling... DONE
  NNF memory      	38.9 MB
  Learned clauses      	102
Cache stats:
  hit rate   	92.5%
  lookups    	353984
  ent count  	16848
  ent memory 	1.2 MB
  ht  memory 	152.6 MB
  clists     	1.0 ave, 2 max
  keys       	24.0b ave, 32.0b max, 2.0b min
  Compile Time	4.359s
Saving compiled NNF to file... DONE
  Save Time       	0.409s
NNF stats:
  Nodes           	850536
  Edges           	1699344
Post compilation
  Loading NNF from file... DONE
  Load Time       	0.485s
NNF stats:
  Nodes           	850536
  Edges           	1699344
  Counting... 68719476736 models / 0.673s
Total Time: 6.065s
```
