#! /bin/sh

# To try to make things behave better on machines where the versions of
# autoconf and automake are not the same as the ones I run, this will
# commit a set of changes but will NOT commit files whose names are in
# the list "gen" below - and that is intended to be a list of things
# regenerated by autotconf etc.
#
# The idea is that the first time somebody checks stuff out they get a full
# set of ready-to-go versions of Makefile.in and confiure and the rest.
# When they go "make" then there is a fair chance that autoconf will be
# reinvoked for them and they will get locally customised versions. When the
# central set of files updates (eg) configure.ac then that but none of the
# files derived from it gets updated (usually!) so the users will need to have
# the automatic regeneration done.  There are long stories about why this is
# the best idea I have at present about how to minimise global pain!

# Before I do anything else I will update revision numbers
# I want this script to be one I can launch from anywhere, but at least
# some of its sub-scripts will not be so generous. So find out where it
# lives so that other locations can be found relative to that.
here="$0";while test -L "$here";do here=`ls -ld "$here" | sed 's/.*-> //'`;done
here=`dirname "$here"`
here=`cd "$here"; pwd -P`

rev=`$here/revision.sh`
# I will predict that the revision after this checkin increments by 1!
rev=$(( $rev + 1 ))

# I will try to keep a revision history linking dates to revision numbers.

touch revision_history.txt
printf "Revision $rev : date `date +%Y-%m-%d`\n" > revision_history.tmp
cat revision_history.txt >> revision_history.tmp
mv revision_history.txt revision_history.old
mv revision_history.tmp revision_history.txt

# I will update version.h is cslbase if my checkin is from a directory
# that contains it. An effect will be that any checkin from either the
# PSL part of the tree or of the packages directory will not update
# the CSL revision record.
if test -f trunk/csl/cslbase/version.h || \
   test -f csl/cslbase/version.h || \
   test -f cslbase/version.h || \
   test -f version.h
then
  sed -e "s/#define REVISION.*/#define REVISION $rev/" \
      < $here/../csl/cslbase/version.h > version.tmp
  mv version.tmp $here/../csl/cslbase/version.h
fi
# I will update the Reduce-based record of revision if the checkin
# either includes support/revision.red or is in some lower-level
# part of the packages directory.
newrevision=""
if test -f trunk/packages/support/revision.red || \
   test -f packages/support/revision.red || \
   test -f support/revision.red || \
   test -f revision.red || \
   test -f ../support/revision.red || \
   test -f ../../support/revision.red || \
   test -f ../../../support/revision.red
then
  sed -e "s/revision!\* :=.*/revision!\* := $rev;/" \
      < $here/../packages/support/revision.red > revision.tmp
  mv revision.tmp $here/../packages/support/revision.red
  newrevision="$here/../packages/support/revision.red "
fi
svn status > /tmp/svnstatus
grep ^A < /tmp/svnstatus  > /tmp/svndiffs
grep ^D < /tmp/svnstatus >> /tmp/svndiffs
grep ^M < /tmp/svnstatus >> /tmp/svndiffs
cut -b 9- < /tmp/svndiffs > /tmp/svnfiles
gen="aclocal.m4 compile config.guess config.sub configure depcomp Makefile.in \
  install-sh ltmain.sh missing test-driver config.h.in mdate-sh mkinstalldirs \
  py-compile texinfo.tex ylwrap ar-lib libtool.m4 ltoptions.m4 \
  ltsugar.m4 ltversion.m4 lt~obsolete.m4"
for x in $gen
do
# printf "Getting rid of %s\n" "$x"
  grep -v "/$x\$" < /tmp/svnfiles | \
    grep -v "^$x\$" > /tmp/work
  mv /tmp/work /tmp/svnfiles
done

tmp="svn ci $newrevision"
for x in `cat /tmp/svnfiles`
do
  tmp="$tmp $x"
done
echo $tmp
if ! $tmp
then
  mv revision_history.old revision_history.txt
  printf "Reverted revision_history.txt\n"
fi

# I strongly suggest use of "scripts/status.sh" or perhaps just "svn status"
# after using this to commit changes so as to review whether more things
# need checking in!

# end of script
