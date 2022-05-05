
#
# Template of rule in GCC makefile
#
# <target>: <pre-requisites>
#	<command 1>
#	<command 2>
#
# In the above template, the list of commands below the target comprise of
# what is called the recipe.
#
# For example:
#
# main.o : main.c types.h
# 	cc -c main.c -o main.o
#
#
# The rule tells two things:
# 1) When to decide to execute the target:
#     A target is run/executed when it is not present at all OR
#     when the pre-requisites are found to be more recent than
#     the target.
#
# 2) What do to when you find that the target needs to be run:
# 	   Execute the list of command(s) in the recipe
#

#
# Automatic variables : These are variables preceded by $ and followed
# 	by a special character. Few automatic variables used in this makefile
# 	are:
#
# $@ : Refers to the filename in the target
# $< : Refers to the first file in the pre-requisite
# $^ : Refers to all the files in the pre-requisites. If a file name is
#      repeated more than once, it shall be considered only once.
#

include makedefs

# Compile command
CC = gcc

# Delete/Remove command
RM = rm

# Archive command
AR = ar

ECHO = echo

#
# A phony target here will ensure that the target 'all' does not collude
# with any file named 'all' that might be present in the same folder as
# this makefile.
#
# Note that the PHONY target is used for targets which are not names of
# files by themselves. To declare a PHONY target, write '.PHONY' followed
# by the target name as a pre-requisite.
#

# Build all

.PHONY: all
all: bld_archive


.PHONY: bld_archive
bld_archive: $(ARDIR)/$(ARNAME)

#
# Rule for building the archive out of the object files
#

$(ARDIR)/$(ARNAME): $(OBJFILES)
	@echo Building the archive 'libdrv.a' from the object files
	@$(AR) $(ARFLAGS) $@ $^

#
# Added an order-only prerequisite namely $OBJDIR).
# This target will create a folder of the same name.
# This will ensure that it creates a folder named 'bin',
# if it is not present. 
#
# Order-only prerequisites are placed to the right of the
# pipe (|) symbol in a pre-requisite list. Anything to the
# left of the pipe symbol are normal pre-requisites.
#

$(OBJFILES): | $(OBJDIR)

$(OBJDIR):
	@$(ECHO) Creating binary directory
	mkdir $(OBJDIR)
	mkdir $(OBJDIR)/src
	mkdir $(OBJDIR)/src/sll/
	mkdir $(OBJDIR)/src/dll/

#
# Each object file looks for a source file with the same name
#

$(OBJDIR)/%.o : %.c
	@$(ECHO) Compiling file $^
	@$(CC) -c $^ -o $@ $(CFLAGS)

#
# Remove the built binaries
#

.PHONY: clean
clean:
	$(RM) -rf $(BINDIR)

.PHONY: print
print:
	@ echo Source file names only : $(SRC_FILENAMES_ONLY)
	@ echo File names without any extension : $(BASE_FILENAMES_WITHOUT_EXT)
	@ echo Object file extensions added : $(OBJ_FILE_EXT_ADDED)
	@ echo Eventual object files : $(OBJFILES)
