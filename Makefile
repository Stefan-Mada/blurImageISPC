CC=clang++
WARN=-Werror
CFLAGS=-I
ISPCFLAGS=--target avx2-i32x8
DEPS = blurImage.hpp

all: blurImage IR BC

%.o: %.cpp $(DEPS)
	$(CC) $(CFLAGS) $(WARN) -c -o $@ $< 
%.o: %.ispc
	ispc $(ISPCFLAGS) $< -o $@

blurImage: blurImage.o greyScaleISPC.o blurImageISPC.o blurImageCpp.o greyScaleCpp.o
	$(CC) $(CLAFGS) $(WARN) greyScaleISPC.o blurImageISPC.o blurImage.o blurImageCpp.o greyScaleCpp.o -o blurImage.out

.PHONY: IR %.ll BC %.bc

%.ll: %.ispc
	ispc $(ISPCFLAGS) --emit-llvm-text $< -o $@

%.ll: %.cpp
	$(CC) $(CFLAGS) $(WARN) -S -emit-llvm $< -o $@

IR: greyScaleISPC.ll blurImageISPC.ll greyScaleCpp.ll blurImageCpp.ll

%.bc: %.ispc
	ispc $(ISPCFLAGS) --emit-llvm $< -o $@
BC: greyScaleISPC.bc blurImageISPC.bc 
