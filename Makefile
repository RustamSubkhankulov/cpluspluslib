#==========================================================
#CONFIG
#==========================================================

# compilers
CXX  = g++
CC   = gcc

# object files output directory
OBJ_DIR = obj

# source files input directory
SRC_DIR = src

# header files directory
INC_DIR = include

# bool flag (0 or 1) - shows whether use flags ot not
USE_DEBUG_FLAGS = 0

#==========================================================
# FLAGS
#==========================================================

# flags for c++ 
CXXFLAGS = --std=c++20

# flags for c
CFLAGS   = 

#----------------------------------------------------------

# flags needed to use with sfml
SFML_FLAGS = -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio

#----------------------------------------------------------

ifeq ($(USE_DEBUG_FLAGS), 1)

	DEBUG_FLAGS = 												\
	-lubsan -D NDEBUG -g -std=c++20 -fmax-errors=1 				\
	-Wall -Wextra -Weffc++ -Waggressive-loop-optimizations  	\
	-Wc++0x-compat -Wc++11-compat -Wc++14-compat  				\
	-Wcast-qual -Wchar-subscripts -Wconditionally-supported 	\
	-Wconversion  -Wctor-dtor-privacy -Wempty-body 				\
	-Wfloat-equal -Wformat-nonliteral -Wformat-security 		\
	-Wformat-signedness -Wformat=2 -Winline  -Wlogical-op 		\
	-Wmissing-declarations  -Wnon-virtual-dtor -Wopenmp-simd	\
	-Woverloaded-virtual -Wpacked -Wpointer-arith 				\
	-Wredundant-decls -Wshadow -Wsign-conversion -Wsign-promo	\
	-Wstack-usage=8192  -Wstrict-null-sentinel 					\
	-Wstrict-overflow=2 -Wsuggest-attribute=noreturn 			\
	-Wsuggest-final-methods -Wsuggest-final-types  				\
	-Wsuggest-override -Wswitch-default -Wswitch-enum 			\
	-Wsync-nand -Wundef  -Wunreachable-code -Wunused 			\
	-Wuseless-cast -Wvariadic-macros -Wno-literal-suffix 		\
	-Wno-missing-field-initializers -Wno-narrowing				\
	-Wno-old-style-cast -Wno-varargs -fcheck-new 				\
	-fsized-deallocation  -fstack-protector 					\
	-fstrict-overflow   -flto-odr-type-merging 					\
	-fno-omit-frame-pointer -fPIE -fsanitize=address  			\
	-fsanitize=bool -fsanitize=bounds -fsanitize=enum  			\
	-fsanitize=float-cast-overflow 								\
	-fsanitize=float-divide-by-zero 							\
	-fsanitize=integer-divide-by-zero -fsanitize=leak 			\
	-fsanitize=nonnull-attribute -fsanitize=null 				\
	-fsanitize=object-size -fsanitize=return 					\
	-fsanitize=returns-nonnull-attribute -fsanitize=shift 		\
	-fsanitize=signed-integer-overflow -fsanitize=undefined 	\
	-fsanitize=unreachable -fsanitize=vla-bound 				\
	-fsanitize=vptr -lm -pie

else

	FLAGS =

endif

#==========================================================
# OBJECT FILES LIST
#==========================================================

OBJ = $(OBJ_DIR)/main.o   #\
	  $(OBJ_DIR)/vector.o \
	  $(OBJ_DIR)/array.o          		

#==========================================================
# FUNCTIONS
#==========================================================

MINIMAL_DEP = $(SRC_DIR)/$(1)/$(1).cpp $(INC_DIR)/$(1)/$(1).hpp

#==========================================================
# TARGETS
#==========================================================

all: dir test_exec

#----------------------------------------------------------

test_exec: $(OBJ)
	$(CXX) $(OBJ) -o $(@)


##---------------------------------------------------------

$(OBJ_DIR)/main.o:    				$(SRC_DIR)/main/main.cpp 								\
									$(INC_DIR)/array/array.hpp								\
									$(INC_DIR)/vector/vector.hpp
	$(CXX) 							$(<) -c -o $(@) $(DEBUG_FLAGS) $(CXXFLAGS) 

#----------------------------------------------------------

# $(OBJ_DIR)/vector.o:				$(call MINIMAL_DEP,vector)
# 	$(CXX) 							$(<) -c -o $(@) $(DEBUG_FLAGS) $(CXXFLAGS)

# #----------------------------------------------------------

# $(OBJ_DIR)/array.o:					$(call MINIMAL_DEP,array)
# 	$(CXX) 							$(<) -c -o $(@) $(DEBUG_FLAGS) $(CXXFLAGS)

#==========================================================
# .PHONY TARGETS
#==========================================================

.PHONY: dir clean

dir: obj
	@ mkdir -p obj

clean:
	- rm $(OBJ_DIR)/*.o 
	- rm test_exec

#==========================================================
