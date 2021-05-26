/* Useful if you wish to make target-specific GCC changes. */
#undef TARGET_ASTRAEAOS
#define TARGET_ASTRAEAOS 1

#undef LINK_SPEC
#define LINK_SPEC "%{shared:-shared} %{static:-static} %{!shared: %{!static: %{rdynamic:-export-dynamic}}}"

/* Files that are linked before user code.
   The %s tells GCC to look for these files in the library directory. */
#undef STANDARD_STARTFILE_PREFIX
#define STANDARD_STARTFILE_PREFIX "/lib/"

/*
#undef STARTFILE_SPEC
#define STARTFILE_SPEC "crt1.o%s crti.o%s crtbegin.o%s"
*/

#undef STARTFILE_SPEC
#define STARTFILE_SPEC \
  "%{!shared: crt1.o%s} crti.o%s \
   %{!shared:crtbegin.o%s} %{shared:crtbeginS.o%s}"

/* Files that are linked after user code.
#undef ENDFILE_SPEC
#define ENDFILE_SPEC "crtend.o%s crtn.o%s"
*/

#undef ENDFILE_SPEC
#define ENDFILE_SPEC \
  "%{!shared:crtend.o%s} %{shared:crtend.o%s} crtn.o%s"

/* Using musl libc as the libc library*/
#undef OPTION_MUSL
#define OPTION_MUSL 1

/* Default arguments you want when running your
   i686-astraeaos-gcc/x86_64-astraeaos-gcc toolchain */
#undef LIB_SPEC
#define LIB_SPEC "-lc -lm" /* link against C standard library */

/* Additional predefined macros. */
#undef TARGET_OS_CPP_BUILTINS
#define TARGET_OS_CPP_BUILTINS()      \
  do {                                \
    builtin_define ("__astraeaos__");      \
    builtin_define ("__unix__");      \
    builtin_assert ("system=astraeaos");   \
    builtin_assert ("system=unix");   \
    builtin_assert ("system=posix");   \
  } while(0);
