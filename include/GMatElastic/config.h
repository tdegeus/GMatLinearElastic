/*

(c - MIT) T.W.J. de Geus (Tom) | www.geus.me | github.com/tdegeus/GMatElastic

*/

#ifndef GMATELASTIC_H
#define GMATELASTIC_H

#ifdef GMATELASTIC_ENABLE_ASSERT

    #define GMATELASTIC_ASSERT(expr) GMATELASTIC_ASSERT_IMPL(expr, __FILE__, __LINE__)
    #define GMATELASTIC_ASSERT_IMPL(expr, file, line) \
        if (!(expr)) { \
            throw std::runtime_error( \
                std::string(file) + ':' + std::to_string(line) + \
                ": assertion failed (" #expr ") \n\t"); \
        }

#else

    #define GMATELASTIC_ASSERT(expr)

#endif

#define GMATELASTIC_VERSION_MAJOR 0
#define GMATELASTIC_VERSION_MINOR 2
#define GMATELASTIC_VERSION_PATCH 1

#define GMATELASTIC_VERSION_AT_LEAST(x, y, z) \
    (GMATELASTIC_VERSION_MAJOR > x || (GMATELASTI_VERSION_MAJOR >= x && \
    (GMATELASTIC_VERSION_MINOR > y || (GMATELASTI_VERSION_MINOR >= y && \
                                       GMATELASTI_VERSION_PATCH >= z))))

#define GMATELASTIC_VERSION(x, y, z) \
    (GMATELASTIC_VERSION_MAJOR == x && \
     GMATELASTIC_VERSION_MINOR == y && \
     GMATELASTIC_VERSION_PATCH == z)

#endif
