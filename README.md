# libcafe

Library for writing Wii U homebrew applications.

## Building

Make sure to either clone the repository recursively, or initialize and update the submodules after cloning. Then, either run "make" to build the library, or "make install" to also install it to your devkitpro directory.

## Usage

Code should start from the standard "main" function. From there, you may access any of the supported dynamic library functions. You can also initialize the stdio filesystem driver with "FSDrvInit", and clean it up later with "FSDrvShutdown".

## License

See LICENSE.txt