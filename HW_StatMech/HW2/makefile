CXX           := g++
CXXFLAGS      := -m64 -O3 -std=c++11
# UNI10CXXFLAGS := -DUNI_CPU -DUNI_LAPACK
# UNI10_ROOT    := /usr/local/uni10
# ROOTS := /usr/local/uni10

# The name of binary object.
EXU := Generalized_diceS.cpp

# Set Uni10 environment
# COMMON_FLAGS_INCS += $(foreach root,$(ROOTS),-I$(root)/include)
# COMMON_FLAGS_LIBS += $(foreach root,$(ROOTS),-L$(root)/lib)
# CXXFLAGS += $(UNI10CXXFLAGS)
# UNI10LDLIBRARY := -luni10

all: job.exe 

job.exe: $(EXU)
	$(CXX) $(COMMON_FLAGS_INCS) $(COMMON_FLAGS_LIBS) $(CXXFLAGS) $^ -o $@ 

clean:
	rm -rf job.exe
