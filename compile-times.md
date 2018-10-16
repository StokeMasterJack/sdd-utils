# SDD Compile Times

On my MacBook Pro

## camry vehicle rules

#### DaveDnnf top-down (pl-to-sd-dnnf):
- input pl: size: 2 kb
- compilation time: 313ms
- sd-dnnf size: 9kb
- model count: 520128

#### Darwiche bottom-up (cnf-to-sdd):
- input cnf: size: 5 kb
- compilation time: 980ms
- sdd size: 16 kb
- model count: 520128

#### Darwiche top-down (cnf-to-dnnf):
- input cnf: size: 5 kb
- compilation time: 001ms
- sdd size: 9 kb
- model count: 520128

## tundra vehicle rules

#### DaveDnnf top-down (pl-to-sd-dnnf):
- input pl: size: 10 kb
- compilation time: 1686ms
- sd-dnnf size: 88 kb
- model count: 1545337914624

#### Darwiche bottom-up (cnf-to-sdd):
- input cnf: size: 29 kb
- compilation time: 9.328 sec
- sdd size: 71 kb
- model count: 1545337914624

#### Darwiche top-down (cnf-to-dnnf):
- input cnf: size: 29 kb
- compilation time: 0.013s
- sdd size: 175 kb
- model count: 1545337914624

## 2013-toyota-minus-tundra vehicle rules

#### DaveDnnf top-down (pl-to-sd-dnnf):
- input pl: size: 382 kb
- compilation time: 1261ms
- sd-dnnf size: 178 kb
- model count: 7,063,787,081,822,699,558

#### Darwiche bottom-up (cnf-to-sdd):
- input cnf: size: 1.5 mb
- compilation time: 625 sec
- sdd size: 576 kb
- model count: 17,070,059,858,222,383,104

#### Darwiche top-down (cnf-to-dnnf):
- input cnf: size: 1.5 mb
- compilation time: never complete
- sdd size: ??
- model count: ??
