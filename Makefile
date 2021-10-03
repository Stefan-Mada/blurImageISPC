CC=clang++
WARN=-Werror
CFLAGS=-I
ISPCFLAGS=--target avx2-i32x8
DEPS = blurImage.hpp

%.o: %.cpp $(DEPS)
	$(CC) $(CFLAGS) $(WARN) -c -o $@ $< 
%.o: %.ispc
	ispc $(ISPCFLAGS) $< -o $@

blurImage: blurImage.o greyScaleISPC.o blurImageISPC.o blurImageCpp.o greyScaleCpp.o
	$(CC) $(CLAFGS) $(WARN) greyScaleISPC.o blurImageISPC.o blurImage.o blurImageCpp.o greyScaleCpp.o -o blurImage.out

.PHONY: IR %.ll

%.ll: %.ispc
	ispc $(ISPCFLAGS) --emit-llvm-text $< -o $@

%.ll: %.cpp
	$(CC) $(CLAGS) $(WARN) -S -emit-llvm $< -o $@

IR: greyScaleISPC.ll blurImageISPC.ll greyScaleCpp.ll blurImageCpp.ll
