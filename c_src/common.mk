#
# Copyright (c) Darach Ennis - 2011. All Rights Reserved.
# 
# The contents of this file are subject to the Erlang Public License,
# Version 1.1, (the "License"); you may not use this file except in
# compliance with the License. You should have received a copy of the
# Erlang Public License along with this software. If not, it can be
# retrieved online at http://www.erlang.org/.
# 
# Software distributed under the License is distributed on an "AS IS"
# basis, WITHOUT WARRANTY OF ANY KIND, either express or implied. See
# the License for the specific language governing rights and limitations
# under the License.
# 
#

include env.mk

#
# Use gcc-4.4
#
CXX        := g++-4.4 -shared -fPIC -m64
CC         := gcc-4.4 -shared -fPIC -m64
LINK       := g++-4.4 -shared -fPIC -m64 

#
# Setup include paths
#
INCLUDES  = -I../include -I$(OTP_INSTALL_PATH)/lib/erl_interface-$(ERL_INTERFACE_VSN)/include -I$(UNITTEST_CPP_PATH)/src

#
# Warning settings
#
CXXWARN_FLAGS := \
        -W -Wall \
        -Wimplicit \
        -Wswitch \
        -Wformat \
        -Wchar-subscripts \
        -Wparentheses \
        -Wmultichar \
        -Wtrigraphs \
        -Wpointer-arith \
        -Wcast-align \
        -Wreturn-type \
        -Wno-unused-function \
        $(SPACE)
CWARN_FLAGS := $(CXXWARN_FLAGS) \
        -Wstrict-prototypes \
        -Wmissing-prototypes \
        -Wmissing-declarations \
        -Wnested-externs \
        -Wmain \
        
LIB_ARCH  :=	x86_64

COMMONFLAGS += $(INCLUDES) -DUNIX

CXXFLAGS  := $(CXXWARN_FLAGS) $(COMMONFLAGS)
CFLAGS    := $(CWARN_FLAGS) $(COMMONFLAGS)

# Debug/release configuration
ifeq ($(dbg),1)
        COMMONFLAGS += -g
        CXXFLAGS    += -D_DEBUG
        CFLAGS      += -D_DEBUG
        BINSUBDIR   := debug
        LIBSUFFIX   := D
else
        COMMONFLAGS += -O2
        BINSUBDIR   := release
        LIBSUFFIX   :=
        CXXFLAGS    += -fno-strict-aliasing
        CFLAGS      += -fno-strict-aliasing
endif

LIB       := -L$(OTP_INSTALL_PATH)/lib/erl_interface-$(ERL_INTERFACE_VSN)/lib -L$(UNITTEST_CPP_PATH)  -lerl_interface -lei -lnsl -lpthread -lUnitTest++

LIB_LINKLINE  =  $(LINK) -o lib$(TARGET).so -shared -Wl,-soname,lib$(TARGET).so $(OBJS) $(LIB)

EXE_LINKLINE  =  $(LINK) -o $(TEST_TARGET) $(OBJS) $(LIB)

 # check if verbose 
ifeq ($(verbose), 1)
        VERBOSE :=
else
        VERBOSE := @
endif

OBJDIR := $(ROOTOBJDIR)/$(LIB_ARCH)/$(BINSUBDIR)
OBJS +=  $(patsubst %.cpp,$(OBJDIR)/%.cpp.o,$(notdir $(CCFILES)))
OBJS +=  $(patsubst %.c,$(OBJDIR)/%.c.o,$(notdir $(CFILES)))

$(OBJDIR)/%.c.o : $(SRCDIR)%.c $(C_DEPS)
	$(VERBOSE)$(CC) $(CFLAGS) -o $@ -c $<

$(OBJDIR)/%.cpp.o : $(SRCDIR)%.cpp $(C_DEPS)
	$(VERBOSE)$(CXX) $(CXXFLAGS) -o $@ -c $<

lib$(TARGET).so: $(OBJS)
	$(VERBOSE)$(LIB_LINKLINE)

$(TEST_TARGET): $(OBJS)
	$(VERBOSE)$(EXE_LINKLINE)

#
# Main target
#
all: mkdirs lib$(TARGET).so
