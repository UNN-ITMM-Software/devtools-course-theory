// #if defined(__GNUC__) || defined(__clang__)
//     #pragma GCC diagnostic push

    #pragma GCC diagnostic ignored "-Wundef"
    #pragma GCC diagnostic ignored "-Wpadded"
    #pragma GCC diagnostic ignored "-Wmissing-noreturn"
// #endif

// #if defined(__clang__)
    #pragma clang diagnostic ignored "-Wweak-vtables"
    #pragma clang diagnostic ignored "-Wglobal-constructors"
    #pragma clang diagnostic ignored "-Wused-but-marked-unused"
    #pragma clang diagnostic ignored "-Wshift-sign-overflow"
    #pragma clang diagnostic ignored "-Wc++98-compat-pedantic"
// #endif

// #if defined(__GNUC__) || defined(__clang__)
//     #pragma GCC diagnostic pop
// #endif