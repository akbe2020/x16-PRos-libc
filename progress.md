# C99 libc compliance tracker

### Useful resources:

- [cpp reference headers](https://en.cppreference.com/w/c/header)
- [musl libc](https://git.musl-libc.org/cgit/musl/tree/)
- [newlib libc](https://sourceware.org/git/?p=newlib-cygwin.git;a=tree)

## Legend

- ✅ Everything implemented
- ⚠️ **(n/m)** Not all has been implemented
- ➖ Header does not contain that type
- 🚫 I did not have that even opened (likely)

| Header         | Functions       | Macros/types |
|----------------|-----------------|--------------|
| `<assert.h>`   | 🚫              | 🚫           |
| `<complex.h>`  | 🚫              | 🚫           |
| `<ctype.h>`    | ✅               | ➖            |
| `<errno.h>`    | 🚫              | 🚫           |
| `<fenv.h>`     | 🚫              | 🚫           |
| `<float.h>`    | ➖               | ✅            |
| `<inttypes.h>` | ⚠️ **(2/6)**    | ⚠️           |
| `<iso646.h>`   | ➖               | ✅            |
| `<limits.h>`   | ➖               | ✅            |
| `<locale.h>`   | 🚫              | 🚫           |
| `<math.h>`     | ⚠️ **(72/171)** | ⚠️           |
| `<setjmp.h>`   | 🚫              | 🚫           |
| `<signal.h>`   | 🚫              | 🚫           |
| `<stdarg.h>`   | ✅               | ➖            |
| `<stdbool.h>`  | ➖               | ✅            |
| `<stddef.h>`   | ➖               | ✅            |
| `<stdint.h>`   | ➖               | ✅            |
| `<stdio.h>`    | ⚠️ **(12/46)**  | ✅            |
| `<stdlib.h>`   | ⚠️ **(9/36)**   | ✅            |
| `<string.h>`   | ⚠️ **(21/22)**  | ➖            |
| `<time.h>`     | 🚫              | 🚫           |
| `<wchar.h>`    | 🚫              | 🚫           |
| `<wctype.h>`   | 🚫              | 🚫           |
