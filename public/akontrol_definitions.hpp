#pragma once

#ifndef GCC_COMPILER
#if (defined(__GNUC__) || defined(__GNUG__)) && not defined(__clang__)
#define GCC_COMPILER 1
#else
#define GCC_COMPILER 0
#endif
#endif