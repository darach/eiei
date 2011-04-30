all:
	mkdir -p lib
	make -C c_src all
	mv c_src/libeiei.so lib

clean:
	make -C c_src clean
	rm -f c_src/libeiei.so
	rm -rf lib
