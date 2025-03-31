tutorial%: tutorial%.cc
	g++ -I/home/jose/Documentos/pythia8313/include $@.cc -o $@ -lpythia8 -L /home/jose/Documentos/pythia8313/lib/

tutorial3: tutorial3.cc
	g++ -I/home/jose/Documentos/pythia8313/include `root-config -- cflags` $@.cc -o $@ -lpythia8 -L /home/jose/Documentos/pythia8313/lib/ `root-config --glibs`
