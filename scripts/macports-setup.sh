#! /bin/sh -v

# scripts/macports-setup.sh
#
# This script assumes that MacPorts has already been installed and that
# relevant changes have been made to your PATH so that it is ready for use.
# I hope you have gone "sudo port selfupdate" recently too.
# Given that it used "port install" to install a bunch of packages. The list
# here is intended to be such that once these have all been built and
# installed the things that they depend on will also have been installed
# and the result will be an environment in which Reduce can be built.
# Despite this list seeming fairly modest I find that in all I end up with
# just over 300 installed ports. Fetching and building them all is an
# overnight task!
#
# Some of the ports listed here are not essential for building Reduce, but
# I want them for one reason or another. Here is a short commentary on some
# of the ones you might most notably question. I note that their presence in
# the list here may also be for the things they depend on, so removing things
# you think you do not need might mean you lose other things you do need!
#
# astyle      Can be used to re-format C++ code, and I use it on the
#             CSL sources.
# autoconf-archive,
# autoconf213 I believe that having lots of versions of autoconf/automake
#             helps with portability of build sequences! 
# bc          used by scripts/testall.sh 
# dvipng      used to re-make documentation
# findutils   I count them as useful
# fontforge   I use this when checking fonts during development
# gdb         Invaluable following a bad crash
# git         Useful to access projects that use git not subversion!
# gnome-system-monitor Apart from the fact that I like this as a tool
#             to review system load etc, installing it causes port to
#             install many X11-related packages that I need.
# gnuplot     Used by Reduce for plotting
# gnutar      Probably not needed?
# gzip        For packing and unpacking things I wish to ship elsewhere
# md5sha1sum  For checking integrity of files I copy
# netpbm      Used for documentation
# polyml      My experiment with an ML implementation of TeX layout
#             algorithms needs this.
# psutils
# subversion  a newer version than the one that comes with OSX/Xcode
# TeX stuff   For building documentation
# timeout     Handy for making some scripts more robust
# vim         Some of you may want emacs (too?)
# wget        For fetching stuff from elsewhere.

# Let me again stress that some of the above are not shown because they
# are themselves needed for building Reduce, but because they call in
# dependencies that are. Some may be used when building optional or
# experimental variants on Reduce.

here="$0";while test -L "$here";do here=`ls -ld "$here" | sed 's/.*-> //'`;done
here=`dirname "$here"`
here=`cd "$here"; pwd -P`

save=`pwd`
cd $here

# First I intend to check if macports.conf is set up the way I want it!
# If it is then it should have the following two lines present:
#   macosx_deployment_target 10.10
#   buildfromsource always
# My check is CRUDE here and can be confused in both directions. For instance
# a line "buildfromsource always" with a comment marker in front of it might
# be spotted by "grep" here and accepted even though it is not operational,
# and a line with one of these directive but with variant whitespace (eg a
# a tab rather than a single space) between the words might not get noticed.
# I suggest you review the file by hand! But having a very simple test here
# is perhaps better than nothing.

conf=/opt/local/etc/macports/macports.conf
if ! test -f $conf || \
   ! grep macosx_deployment_target $conf > /dev/null || \
   ! grep "buildfromsource always" $conf > /dev/null
then
  printf "macports.conf seems not to exist, or does not contain the lines\n"
  printf "   macosx_deployment_target 10.10\n"
  printf "   buildfromsource always\n"
  printf "Please correct that and try again.\n"
  exit 1
fi

sudo port install          \
  astyle                   \
  autoconf                 \
  autoconf-archive         \
  autoconf213              \
  automake                 \
  bc                       \
  ccache                   \
  dvipng                   \
  findutils                \
  fontconfig               \
  fontforge                \
  gdb                      \
  git                      \
  gnuplot                  \
  gnutar                   \
  gzip                     \
  libffi                   \
  libiconv                 \
  md5sha1sum               \
  netpbm                   \
  pkgconfig                \
  polyml                   \
  psutils                  \
  rsync                    \
  subversion               \
  texinfo                  \
  texlive-fonts-extra      \
  texlive-formats-extra    \
  texlive-latex-extra      \
  texlive-plain-generic    \
  texlive-bin-extra        \
  texlive-fonts-recommended \
  timeout                  \
  vim                      \
  wget

# I like to have gnome-system-monitor installed, however there was a period
# when it failed to build and install via macports. If I left it listed
# amongst the long list of essentials this caused the entire install to
# end up incomplete.
# Because this utility is not essential for building CSL or Reduce I just
# lift the attempt to install it into a separate use of port, so that if the
# install there fails all that happens is that the system monitor does not
# get installed, and all important parts of Reduce are supported.
# If it mattered to me more I would take more agressive action, as I used
# to for fontconf g (see below).
# For this particular case https://trac.macports.org/ticket/56809 explains
# that basically "sudo port install gstreamer-gst-plugins-base +x11" will
# sort things out, but obviously changing from the default options on any
# package is to be done with some caution, and equally obviously it is
# probable that there will be adjustments made to all the macports
# configuration files so that manual action is not needed - so I am not going
# to automate my work-around, but just include this comment to encourage
# anybody who at some stage in the future faces a similar-looking problem.
# I wish to stress that with a collection of packages as large and as dynamic
# as that supported by macports it is utterly reasonable that at times one or
# more of the parts of it needs a bit of help before it builds. Just as
# a copy of Reduce fetched from subversion will - from time to time - be in
# need of some patching before it builds successfully!

sudo port install  gnome-system-monitor

# In around January 2016 and for some while after that I found that macports
# did not generate a libfontconfig.a while installing fontconfig, and that
# caused pain when I wanted to build my code with static linking. As of
# September 2018 this issue no longer applies, and that naturally-build
# fontconfig does all that I need. However again as an illustration of the
# sort of way in which potential issues can be worked around I leave the
# work-around that I used to have available but commented out.

#- cd $here/../csl/cslbase
#- ./make-static-fontconfig-for-macintosh.sh
#- cd $save

exit 0

# end of script