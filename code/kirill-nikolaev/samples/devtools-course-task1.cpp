// Copyright 2013 K.Nikolaev
#include <NumConverter.h>
#include <cstdio>

int main(int argc, char* argv[]) {
    printf("This is a number converter application\n");
    NumConverter a(hex, "1f");
    printf("%s in hex\n", a.GetValue().c_str());
    printf("Is %s in oct\n", a.ToOctal().c_str());
    printf("Is %s in dec\n", a.ToDecimal().c_str());
    printf("Is %s in bin\n", a.ToBinary().c_str());
    NumConverter b(oct, "17");
    printf("%s in oct\n", b.GetValue().c_str());
    printf("Is %s in hex\n", b.ToHex().c_str());
    printf("Is %s in dec\n", b.ToDecimal().c_str());
    printf("Is %s in bin\n", b.ToBinary().c_str());
    NumConverter c(dec, "199");
    printf("%s in dec\n", c.GetValue().c_str());
    printf("Is %s in hex\n", c.ToHex().c_str());
    printf("Is %s in oct\n", c.ToOctal().c_str());
    printf("Is %s in bin\n", c.ToBinary().c_str());
    NumConverter d(bin, "11101011");
    printf("%s in bin\n", d.GetValue().c_str());
    printf("Is %s in hex\n", d.ToHex().c_str());
    printf("Is %s in oct\n", d.ToOctal().c_str());
    printf("Is %s in dec\n", d.ToDecimal().c_str());
    NumConverter e(hex, "fffffff0");
    printf("%s in hex\n", e.GetValue().c_str());
    printf("Is %s in oct\n", e.ToOctal().c_str());
    printf("Is %s in dec\n", e.ToDecimal().c_str());
    printf("Is %s in bin\n", e.ToBinary().c_str());

    return 0;
}
