#define BSNES_VERSION "0.020"
#define BSNES_TITLE   "bsnes v" BSNES_VERSION

#define MEMCORE bMemBus
#define CPUCORE sCPU
#define SMPCORE sSMP
#define DSPCORE bDSP
#define PPUCORE bPPU

//#define FAVOR_ACCURACY
#define FAVOR_SPEED

//game genie + pro action replay code support (~1-3% speed hit)
#define CHEAT_SYSTEM

//snes core polymorphism
//(allow runtime cpu/smp/dsp/ppu/bus selection, ~10% speed hit)
//#define POLYMORPHISM

#include "lib/libbase.h"

#if defined(PROCESSOR_X86)
  #define ARCH_LSB
  #include "lib/libco_x86.h"
#elif defined(PROCESSOR_X86_64)
  #define ARCH_LSB
  #include "lib/libco_x86_64.h"
#elif defined(PROCESSOR_G5)
  #define ARCH_MSB
#else
  #error "unsupported processor"
#endif

#include "lib/libinterp.h"
#include "lib/libsort.h"
#include "lib/libarray.h"
#include "lib/libvector.h"
#include "lib/libfile.h"
#include "lib/libstring.h"
#include "lib/libconfig.h"

//platform-specific global functions
void alert(char*, ...);
void dprintf(char*, ...);
void dprintf(uint, char*, ...);

namespace source {
  enum {
    none = 0,
    debug,
    cpu,
    ppu,
    smp,
    dsp,
    bus,
  };
};

//various class interfaces
#include "interface.h"
