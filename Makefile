
all: flatbuf_test

sample_generated.h:
	flatc --version
	flatc --cpp --grpc sample.fbs

flatbuf_test: sample_generated.h
	g++ -std=c++1y -Wl,-no-as-needed $(INCS) test.cpp -o $@

.PHONY: clean
clean:
	rm flatbuf_test

