#
# Environment settings - change to suit your environment
#

UNITTEST_CPP_PATH=/opt/unittest-cpp/UnitTest++
OTP_INSTALL_PATH=/home/darach/otp-R13B04
ERL_INTERFACE_VSN=3.6.5

#
# Other - no need to change
#

PWD =	$(shell pwd)
BINDIR = $(PWD)/bin
OSUPPER = $(shell uname -s 2>/dev/null | tr [:lower:] [:upper:])
OSLOWER = $(shell uname -s 2>/dev/null | tr [:upper:] [:lower:])
SRCDIR ?=

ROOTOBJDIR=obj

verbose=1

mkdirs: objdirectory

objdirectory:
	$(VERBOSE)mkdir -p $(OBJDIR)

clean:
	$(VERBOSE)rm -rf $(ROOTOBJDIR)
	$(VERBOSE) rm -f lib*.so

