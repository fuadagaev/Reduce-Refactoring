#! /bin/bash

# Used as a helper for packing the distribution

rm -rf distrib
mkdir distrib
mkdir distrib/psl
mkdir distrib/csl

cp README.for.distribution distrib/README

cp -r $1/cslbuild/*/csl/*.app distrib/csl
cp runcsl.sh distrib/csl/redcsl
chmod +x distrib/csl/redcsl

cp -r $1/pslbuild/*/psl distrib/psl
cp -r $1/pslbuild/*/red distrib/psl
cp runpsl.sh distrib/psl/redpsl
chmod +x distrib/psl/redpsl

cp Reduce-source.tar.bz2 distrib/Reduce_source_`date +%Y%m%d`.tar.bz2

cp $1/doc/manual/manual.pdf distrib/reduce-manual.pdf

exit
