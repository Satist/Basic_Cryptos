
project(hy457_crypto C)

set(CMAKE_C_STANDARD 11)
add_executable(hy457_crypto hy457_crypto.h ceasar.c otp.c playfair.c affine.c test.c)
