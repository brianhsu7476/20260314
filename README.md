# 20260314

## Initialization

```$ git clone https://github.com/brianhsu7476/20260314```

If meet the error like:

```fatal error: openssl/evp.h: No such file or directory```

Just install openssl using the following command on Ubuntu:

```$ sudo apt-get install libssl-dev```

## Compile and Run

Use the following command to compile ```decode.cpp```. Remember to add the ```-lcrypto``` flag.

```$ g++ decode.cpp -lcrypto```

After compiling, you will get an executable file like ```a.out```. Just run it.

```$ ./a.out```

You need to enter two lines. The first line is for the key, and the second line is for the initial value of CBC. Ask me what to enter.
