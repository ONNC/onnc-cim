BASE_PATH=$(abspath $(shell cd ..; pwd))
INCLUDE_PATH=$(BASE_PATH)/include
RT_BUILD_PATH=$(BASE_PATH)/onnc-runtime
RT_LIB=$(RT_BUILD_PATH)/install/lib/libonnc-rt.a
RT_INCLUDE_PATH=$(RT_BUILD_PATH)/install/include/onnc/Runtime
ONNC_PATH=$(BASE_PATH)/../../../onnc

CXX_FLAGS=-std=c++17 -I$(INCLUDE_PATH) -D FASTMODEL
SIM_DIR=$(INCLUDE_PATH)/fastsim

EVENT_HH=$(wildcard $(INCLUDE_PATH)/sim-module/*.hh) $(INCLUDE_PATH)/fastsim/register-fast_model.h $(INCLUDE_PATH)/fastsim/fast_model.hh
EVENT_CC=$(BASE_PATH)/fastsim/fast_model.cc

all: fastsim-reg_programming.a fastsim-struct_defined.a

fastsim-reg_programming.a: $(EVENT_HH) $(EVENT_CC)
	mkdir -p $(RT_BUILD_PATH)
	cd $(RT_BUILD_PATH) && cmake -DCMAKE_INSTALL_PREFIX=$(RT_BUILD_PATH)/install -DONNC_RT_ONLY=1 $(ONNC_PATH)
	$(MAKE) -C $(RT_BUILD_PATH) install
	cp $(RT_LIB) fastsim-reg_programming.a
	if [ "$(SIM_DIR)" !=  "$(INCLUDE_PATH)/fastsim" ]; then \
		cp $(SIM_DIR)/fastmodel-define.h $(INCLUDE_PATH)/fastsim/fastmodel-define.h; \
	else \
		echo "##### Warning: SIM_DIR is not specified. Default fastmodel-define.h is used. #####"; \
		cp $(INCLUDE_PATH)/fastsim/fastmodel-define-default.h $(INCLUDE_PATH)/fastsim/fastmodel-define.h; \
	fi
	g++ fast_model.cc -c $(CXX_FLAGS) -I $(RT_INCLUDE_PATH)
	ar rcs fastsim-reg_programming.a fast_model.o

fastsim-struct_defined.a: $(INCLUDE_PATH)/fastsim/operator.hh operator.cc $(ONNC_PATH)
	mkdir -p $(RT_BUILD_PATH)
	cd $(RT_BUILD_PATH) && cmake -DCMAKE_INSTALL_PREFIX=$(RT_BUILD_PATH)/install -DONNC_RT_ONLY=1 $(ONNC_PATH)
	$(MAKE) -C $(RT_BUILD_PATH) install
	g++ operator.cc -c $(CXX_FLAGS) -I $(RT_INCLUDE_PATH)
	ar rcs fastsim-struct_defined.a operator.o

struct_defined_test: main.cc fastsim-struct_defined.a
	g++ main.cc -c $(CXX_FLAGS)
	g++ -o struct_defined_test main.o fastsim-struct_defined.a $(RT_LIB) $(CXX_FLAGS)

run-test: struct_defined_test
	./struct_defined_test

clean:
	rm -f *.o *.a struct_defined_test
