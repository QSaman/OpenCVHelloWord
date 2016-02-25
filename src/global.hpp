#include <cmath>

#define ENABLE_DEBUGGING
#ifdef ENABLE_DEBUGGING
#include <iostream>

#define print(x) std::cout << #x << ": " << x
#define println(x) print(x) << std::endl
#else
#define print(x)
#define println(x)
#endif

#define pow2(x) ((x) * (x))

#ifdef M_PI
#define pi M_PI
#else
#define pi std::acos(-1.0)
#endif

#define GaussianSize 33

#ifdef ReleaseMode
#define CustomGaussianSize 33
#else
#define CustomGaussianSize 17
#endif

#define GaussianSigma 70.0

#ifndef INFINITY
#define INFINITY 1e9
#endif
