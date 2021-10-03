CC=clang++
WARN=-Werror
CFLAGS=-I
ISPCFLAGS=--target avx2-i32x8
DEPS = blurImage.hpp

%.o: %.cpp $(DEPS)
	$(CC) $(CFLAGS) $(WARN) -c -o $@ $< 
%.o: %.ispc
	ispc $(ISPCFLAGS) $< -o $@

blurImage: blurImage.o greyScaleISPC.o blurImageISPC.o
	$(CC) $(CLAFGS) $(WARN) greyScaleISPC.o blurImageISPC.o blurImage.o -o blurImage.out

.PHONY: IR %.ll

%.ll: %.ispc
	ispc $(ISPCFLAGS) --emit-llvm-text $< -o $@

IR: greyScaleISPC.ll blurImageISPC.ll
