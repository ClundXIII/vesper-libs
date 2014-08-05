#Makefile to:
# compile libraries
# install the libs (for development)
# generate packages for Distributions

#make everything:
all: compile-all devinst-all pkg-all

#prepare, create folder for the libs and install needed packages
prepare: pre-dev-inst install-dependencies

#compile all the libraries:
compile-all:
	bash compile_all.sh

devinst-all:
	bash devinst.sh -a

pkg-all:
	bash pkg.sh -a

#exeute this once before development:
pre-dev-inst:
	sudo mkdir -p /opt/lib/vesper
	sudo echo "/opt/lib/vesper" > /etc/ld.so.conf.d/vesper.conf
	bash prepare_cmake.sh

install-dependencies:
	bash install_dependencies.sh
