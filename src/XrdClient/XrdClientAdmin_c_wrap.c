/* ----------------------------------------------------------------------------
 * This file was automatically generated by SWIG (http://www.swig.org).
 * Version 1.3.22
 * 
 * This file is not intended to be easily readable and contains a number of 
 * coding conventions designed to improve portability and efficiency. Do not make
 * changes to this file unless you know what you are doing--modify the SWIG 
 * interface file instead. 
 * ----------------------------------------------------------------------------- */

/*************************************************************** -*- c -*-
 * perl5/precommon.swg
 *
 * Rename all exported symbols from common.swg, to avoid symbol
 * clashes if multiple interpreters are included
 *
 ************************************************************************/

#define SWIG_TypeRegister    SWIG_Perl_TypeRegister
#define SWIG_TypeCheck       SWIG_Perl_TypeCheck
#define SWIG_TypeCast        SWIG_Perl_TypeCast
#define SWIG_TypeDynamicCast SWIG_Perl_TypeDynamicCast
#define SWIG_TypeName        SWIG_Perl_TypeName
#define SWIG_TypePrettyName  SWIG_Perl_TypePrettyName
#define SWIG_TypeQuery       SWIG_Perl_TypeQuery
#define SWIG_TypeClientData  SWIG_Perl_TypeClientData
#define SWIG_PackData        SWIG_Perl_PackData 
#define SWIG_UnpackData      SWIG_Perl_UnpackData 


/***********************************************************************
 * common.swg
 *
 *     This file contains generic SWIG runtime support for pointer
 *     type checking as well as a few commonly used macros to control
 *     external linkage.
 *
 * Author : David Beazley (beazley@cs.uchicago.edu)
 *
 * Copyright (c) 1999-2000, The University of Chicago
 * 
 * This file may be freely redistributed without license or fee provided
 * this copyright message remains intact.
 ************************************************************************/

#include <string.h>

#if defined(_WIN32) || defined(__WIN32__) || defined(__CYGWIN__)
#  if defined(_MSC_VER) || defined(__GNUC__)
#    if defined(STATIC_LINKED)
#      define SWIGEXPORT(a) a
#      define SWIGIMPORT(a) extern a
#    else
#      define SWIGEXPORT(a) __declspec(dllexport) a
#      define SWIGIMPORT(a) extern a
#    endif
#  else
#    if defined(__BORLANDC__)
#      define SWIGEXPORT(a) a _export
#      define SWIGIMPORT(a) a _export
#    else
#      define SWIGEXPORT(a) a
#      define SWIGIMPORT(a) a
#    endif
#  endif
#else
#  define SWIGEXPORT(a) a
#  define SWIGIMPORT(a) a
#endif

#ifdef SWIG_GLOBAL
#  define SWIGRUNTIME(a) SWIGEXPORT(a)
#else
#  define SWIGRUNTIME(a) static a
#endif

#ifdef __cplusplus
extern "C" {
#endif

typedef void *(*swig_converter_func)(void *);
typedef struct swig_type_info *(*swig_dycast_func)(void **);

typedef struct swig_type_info {
  const char             *name;
  swig_converter_func     converter;
  const char             *str;
  void                   *clientdata;
  swig_dycast_func        dcast;
  struct swig_type_info  *next;
  struct swig_type_info  *prev;
} swig_type_info;

#ifdef SWIG_NOINCLUDE

SWIGIMPORT(swig_type_info *) SWIG_TypeRegister(swig_type_info *);
SWIGIMPORT(swig_type_info *) SWIG_TypeCheck(char *c, swig_type_info *);
SWIGIMPORT(void *)           SWIG_TypeCast(swig_type_info *, void *);
SWIGIMPORT(swig_type_info *) SWIG_TypeDynamicCast(swig_type_info *, void **);
SWIGIMPORT(const char *)     SWIG_TypeName(const swig_type_info *);
SWIGIMPORT(const char *)     SWIG_TypePrettyName(const swig_type_info *);
SWIGIMPORT(swig_type_info *) SWIG_TypeQuery(const char *);
SWIGIMPORT(void)             SWIG_TypeClientData(swig_type_info *, void *);
SWIGIMPORT(char *)           SWIG_PackData(char *, void *, int);
SWIGIMPORT(char *)           SWIG_UnpackData(char *, void *, int);

#else

static swig_type_info *swig_type_list = 0;
static swig_type_info **swig_type_list_handle = &swig_type_list;

/* Register a type mapping with the type-checking */
SWIGRUNTIME(swig_type_info *)
SWIG_TypeRegister(swig_type_info *ti) {
  swig_type_info *tc, *head, *ret, *next;
  /* Check to see if this type has already been registered */
  tc = *swig_type_list_handle;
  while (tc) {
    if (strcmp(tc->name, ti->name) == 0) {
      /* Already exists in the table.  Just add additional types to the list */
      if (tc->clientdata) ti->clientdata = tc->clientdata;
      head = tc;
      next = tc->next;
      goto l1;
    }
    tc = tc->prev;
  }
  head = ti;
  next = 0;

  /* Place in list */
  ti->prev = *swig_type_list_handle;
  *swig_type_list_handle = ti;

  /* Build linked lists */
  l1:
  ret = head;
  tc = ti + 1;
  /* Patch up the rest of the links */
  while (tc->name) {
    head->next = tc;
    tc->prev = head;
    head = tc;
    tc++;
  }
  if (next) next->prev = head;
  head->next = next;
  return ret;
}

/* Check the typename */
SWIGRUNTIME(swig_type_info *) 
SWIG_TypeCheck(char *c, swig_type_info *ty) {
  swig_type_info *s;
  if (!ty) return 0;        /* Void pointer */
  s = ty->next;             /* First element always just a name */
  do {
    if (strcmp(s->name,c) == 0) {
      if (s == ty->next) return s;
      /* Move s to the top of the linked list */
      s->prev->next = s->next;
      if (s->next) {
        s->next->prev = s->prev;
      }
      /* Insert s as second element in the list */
      s->next = ty->next;
      if (ty->next) ty->next->prev = s;
      ty->next = s;
      s->prev = ty;
      return s;
    }
    s = s->next;
  } while (s && (s != ty->next));
  return 0;
}

/* Cast a pointer up an inheritance hierarchy */
SWIGRUNTIME(void *) 
SWIG_TypeCast(swig_type_info *ty, void *ptr) {
  if ((!ty) || (!ty->converter)) return ptr;
  return (*ty->converter)(ptr);
}

/* Dynamic pointer casting. Down an inheritance hierarchy */
SWIGRUNTIME(swig_type_info *) 
SWIG_TypeDynamicCast(swig_type_info *ty, void **ptr) {
  swig_type_info *lastty = ty;
  if (!ty || !ty->dcast) return ty;
  while (ty && (ty->dcast)) {
    ty = (*ty->dcast)(ptr);
    if (ty) lastty = ty;
  }
  return lastty;
}

/* Return the name associated with this type */
SWIGRUNTIME(const char *)
SWIG_TypeName(const swig_type_info *ty) {
  return ty->name;
}

/* Return the pretty name associated with this type,
   that is an unmangled type name in a form presentable to the user.
*/
SWIGRUNTIME(const char *)
SWIG_TypePrettyName(const swig_type_info *type) {
  /* The "str" field contains the equivalent pretty names of the
     type, separated by vertical-bar characters.  We choose
     to print the last name, as it is often (?) the most
     specific. */
  if (type->str != NULL) {
    const char *last_name = type->str;
    const char *s;
    for (s = type->str; *s; s++)
      if (*s == '|') last_name = s+1;
    return last_name;
  }
  else
    return type->name;
}

/* 
   Compare two type names skipping the space characters, therefore
   "char*" == "char *" and "Class<int>" == "Class<int >", etc.

   Return 0 when the two name types are equivalent, as in
   strncmp, but skipping ' '.
*/
static int
SWIG_TypeNameComp(const char *f1, const char *l1,
		  const char *f2, const char *l2) {
  for (;(f1 != l1) && (f2 != l2); ++f1, ++f2) {
    while ((*f1 == ' ') && (f1 != l1)) ++f1;
    while ((*f2 == ' ') && (f2 != l2)) ++f2;
    if (*f1 != *f2) return *f1 - *f2;
  }
  return (l1 - f1) - (l2 - f2);
}

/*
  Check type equivalence in a name list like <name1>|<name2>|...
*/
static int
SWIG_TypeEquiv(const char *nb, const char *tb) {
  int equiv = 0;
  const char* te = tb + strlen(tb);
  const char* ne = nb;
  while (!equiv && *ne) {
    for (nb = ne; *ne; ++ne) {
      if (*ne == '|') break;
    }
    equiv = SWIG_TypeNameComp(nb, ne, tb, te) == 0;
    if (*ne) ++ne;
  }
  return equiv;
}
  

/* Search for a swig_type_info structure */
SWIGRUNTIME(swig_type_info *)
SWIG_TypeQuery(const char *name) {
  swig_type_info *ty = *swig_type_list_handle;
  while (ty) {
    if (ty->str && (SWIG_TypeEquiv(ty->str,name))) return ty;
    if (ty->name && (strcmp(name,ty->name) == 0)) return ty;
    ty = ty->prev;
  }
  return 0;
}

/* Set the clientdata field for a type */
SWIGRUNTIME(void)
SWIG_TypeClientData(swig_type_info *ti, void *clientdata) {
  swig_type_info *tc, *equiv;
  if (ti->clientdata == clientdata) return;
  ti->clientdata = clientdata;
  equiv = ti->next;
  while (equiv) {
    if (!equiv->converter) {
      tc = *swig_type_list_handle;
      while (tc) {
        if ((strcmp(tc->name, equiv->name) == 0))
          SWIG_TypeClientData(tc,clientdata);
        tc = tc->prev;
      }
    }
    equiv = equiv->next;
  }
}

/* Pack binary data into a string */
SWIGRUNTIME(char *)
SWIG_PackData(char *c, void *ptr, int sz) {
  static char hex[17] = "0123456789abcdef";
  unsigned char *u = (unsigned char *) ptr;
  const unsigned char *eu =  u + sz;
  register unsigned char uu;
  for (; u != eu; ++u) {
    uu = *u;
    *(c++) = hex[(uu & 0xf0) >> 4];
    *(c++) = hex[uu & 0xf];
  }
  return c;
}

/* Unpack binary data from a string */
SWIGRUNTIME(char *)
SWIG_UnpackData(char *c, void *ptr, int sz) {
  register unsigned char uu = 0;
  register int d;
  unsigned char *u = (unsigned char *) ptr;
  const unsigned char *eu =  u + sz;
  for (; u != eu; ++u) {
    d = *(c++);
    if ((d >= '0') && (d <= '9'))
      uu = ((d - '0') << 4);
    else if ((d >= 'a') && (d <= 'f'))
      uu = ((d - ('a'-10)) << 4);
    d = *(c++);
    if ((d >= '0') && (d <= '9'))
      uu |= (d - '0');
    else if ((d >= 'a') && (d <= 'f'))
      uu |= (d - ('a'-10));
    *u = uu;
  }
  return c;
}

#endif

#ifdef __cplusplus
}
#endif

/* ---------------------------------------------------------------------- -*- c -*-
 * perl5.swg
 *
 * Perl5 runtime library
 * $Header$
 * ----------------------------------------------------------------------------- */

#define SWIGPERL
#define SWIGPERL5
#ifdef __cplusplus
/* Needed on some windows machines---since MS plays funny games with the header files under C++ */
#include <math.h>
#include <stdlib.h>
extern "C" {
#endif
#include "EXTERN.h"
#include "perl.h"
#include "XSUB.h"

/* Get rid of free and malloc defined by perl */
#undef free
#undef malloc

#ifndef pTHX_
#define pTHX_
#endif

#include <string.h>
#ifdef __cplusplus
}
#endif

/* Macro to call an XS function */

#ifdef PERL_OBJECT 
#  define SWIG_CALLXS(_name) _name(cv,pPerl) 
#else 
#  ifndef MULTIPLICITY 
#    define SWIG_CALLXS(_name) _name(cv) 
#  else 
#    define SWIG_CALLXS(_name) _name(PERL_GET_THX, cv) 
#  endif 
#endif 

/* Contract support */

#define SWIG_contract_assert(expr,msg) if (!(expr)) { SWIG_croak(msg); } else

/* Note: SwigMagicFuncHack is a typedef used to get the C++ compiler to just shut up already */

#ifdef PERL_OBJECT
#define MAGIC_PPERL  CPerlObj *pPerl = (CPerlObj *) this;
typedef int (CPerlObj::*SwigMagicFunc)(SV *, MAGIC *);

#ifdef __cplusplus
extern "C" {
#endif
typedef int (CPerlObj::*SwigMagicFuncHack)(SV *, MAGIC *);
#ifdef __cplusplus
}
#endif

#define SWIG_MAGIC(a,b) (SV *a, MAGIC *b)
#define SWIGCLASS_STATIC
#else
#define MAGIC_PPERL
#define SWIGCLASS_STATIC static
#ifndef MULTIPLICITY
#define SWIG_MAGIC(a,b) (SV *a, MAGIC *b)
typedef int (*SwigMagicFunc)(SV *, MAGIC *);

#ifdef __cplusplus
extern "C" {
#endif
typedef int (*SwigMagicFuncHack)(SV *, MAGIC *);
#ifdef __cplusplus
}
#endif


#else
#define SWIG_MAGIC(a,b) (struct interpreter *interp, SV *a, MAGIC *b)
typedef int (*SwigMagicFunc)(struct interpreter *, SV *, MAGIC *);
#ifdef __cplusplus
extern "C" {
#endif
typedef int (*SwigMagicFuncHack)(struct interpreter *, SV *, MAGIC *);
#ifdef __cplusplus
}
#endif

#endif
#endif

#if defined(WIN32) && defined(PERL_OBJECT) && !defined(PerlIO_exportFILE)
#define PerlIO_exportFILE(fh,fl) (FILE*)(fh)
#endif

/* Modifications for newer Perl 5.005 releases */

#if !defined(PERL_REVISION) || ((PERL_REVISION >= 5) && ((PERL_VERSION < 5) || ((PERL_VERSION == 5) && (PERL_SUBVERSION < 50))))
#  ifndef PL_sv_yes
#    define PL_sv_yes sv_yes
#  endif
#  ifndef PL_sv_undef
#    define PL_sv_undef sv_undef
#  endif
#  ifndef PL_na
#    define PL_na na
#  endif
#endif

#include <stdlib.h>

#ifdef __cplusplus
extern "C" {
#endif

#define SWIG_OWNER 1
#define SWIG_SHADOW 2

/* Common SWIG API */

#ifdef PERL_OBJECT
#  define SWIG_ConvertPtr(obj, pp, type, flags) \
     SWIG_Perl_ConvertPtr(pPerl, obj, pp, type, flags)
#  define SWIG_NewPointerObj(p, type, flags) \
     SWIG_Perl_NewPointerObj(pPerl, p, type, flags)
#  define SWIG_MakePackedObj(sv, p, s, type)	\
     SWIG_Perl_MakePackedObj(pPerl, sv, p, s, type)
#  define SWIG_ConvertPacked(obj, p, s, type, flags) \
     SWIG_Perl_ConvertPacked(pPerl, obj, p, s, type, flags)

#else
#  define SWIG_ConvertPtr(obj, pp, type, flags) \
     SWIG_Perl_ConvertPtr(obj, pp, type, flags)
#  define SWIG_NewPointerObj(p, type, flags) \
     SWIG_Perl_NewPointerObj(p, type, flags)
#  define SWIG_MakePackedObj(sv, p, s, type)	\
     SWIG_Perl_MakePackedObj(sv, p, s, type )
#  define SWIG_ConvertPacked(obj, p, s, type, flags) \
     SWIG_Perl_ConvertPacked(obj, p, s, type, flags)
#endif

/* Perl-specific API */
#ifdef PERL_OBJECT
#  define SWIG_MakePtr(sv, ptr, type, flags) \
     SWIG_Perl_MakePtr(pPerl, sv, ptr, type, flags)
#  define SWIG_TypeCheckRV(rv, ty) \
     SWIG_Perl_TypeCheckRV(pPerl, rv, ty)
#  define SWIG_SetError(str) \
     SWIG_Perl_SetError(pPerl, str)
#else
#  define SWIG_MakePtr(sv, ptr, type, flags) \
     SWIG_Perl_MakePtr(sv, ptr, type, flags)
#  define SWIG_TypeCheckRV(rv, ty) \
     SWIG_Perl_TypeCheckRV(rv, ty)
#  define SWIG_SetError(str) \
     SWIG_Perl_SetError(str)
#  define SWIG_SetErrorSV(str) \
     SWIG_Perl_SetErrorSV(str)
#endif

#define SWIG_SetErrorf SWIG_Perl_SetErrorf


#ifdef PERL_OBJECT
#  define SWIG_MAYBE_PERL_OBJECT CPerlObj *pPerl,
#else
#  define SWIG_MAYBE_PERL_OBJECT
#endif

#ifdef SWIG_NOINCLUDE

SWIGIMPORT(int)               SWIG_Perl_ConvertPtr(SWIG_MAYBE_PERL_OBJECT SV *, void **, swig_type_info *, int flags);
SWIGIMPORT(void)              SWIG_Perl_MakePtr(SWIG_MAYBE_PERL_OBJECT SV *, void *, swig_type_info *, int flags);
SWIGIMPORT(SV *)              SWIG_Perl_NewPointerObj(SWIG_MAYBE_PERL_OBJECT void *, swig_type_info *, int flags);
SWIGIMPORT(void)              SWIG_Perl_MakePackedObj(SWIG_MAYBE_PERL_OBJECT SV *, void *, int, swig_type_info *);
SWIGIMPORT(int)               SWIG_Perl_ConvertPacked(SWIG_MAYBE_PERL_OBJECT SV *, void *, int, swig_type_info *, int flags);
SWIGIMPORT(swig_type_info *)  SWIG_Perl_TypeCheckRV(SWIG_MAYBE_PERL_OBJECT SV *rv, swig_type_info *ty);
SWIGIMPORT(SV *)              SWIG_Perl_SetError(SWIG_MAYBE_PERL_OBJECT char *);

#else

SWIGRUNTIME(swig_type_info *)
SWIG_Perl_TypeCheckRV(SWIG_MAYBE_PERL_OBJECT SV *rv, swig_type_info *ty) {
  swig_type_info *s;
  if (!ty) return 0;        /* Void pointer */
  s = ty->next;             /* First element always just a name */
  do {
    if (sv_derived_from(rv, (char *) s->name)) {
      if (s == ty->next) return s;
      /* Move s to the top of the linked list */
      s->prev->next = s->next;
      if (s->next) {
        s->next->prev = s->prev;
      }
      /* Insert s as second element in the list */
      s->next = ty->next;
      if (ty->next) ty->next->prev = s;
      ty->next = s;
      s->prev = ty;
      return s;
    }
    s = s->next;
  } while (s && (s != ty->next));
  return 0;
}

/* Function for getting a pointer value */

SWIGRUNTIME(int) 
SWIG_Perl_ConvertPtr(SWIG_MAYBE_PERL_OBJECT SV *sv, void **ptr, swig_type_info *_t, int flags) {
  swig_type_info *tc;
  void *voidptr = (void *)0;

  /* If magical, apply more magic */
  if (SvGMAGICAL(sv))
    mg_get(sv);

  /* Check to see if this is an object */
  if (sv_isobject(sv)) {
    SV *tsv = (SV*) SvRV(sv);
    IV tmp = 0;
    if ((SvTYPE(tsv) == SVt_PVHV)) {
      MAGIC *mg;
      if (SvMAGICAL(tsv)) {
        mg = mg_find(tsv,'P');
        if (mg) {
          SV *rsv = mg->mg_obj;
          if (sv_isobject(rsv)) {
            tmp = SvIV((SV*)SvRV(rsv));
          }
        }
      } else {
        return -1;
      }
    } else {
      tmp = SvIV((SV*)SvRV(sv));
    }
    voidptr = (void *)tmp;
    if (!_t) {
      *(ptr) = voidptr;
      return 0;
    }
  } else if (! SvOK(sv)) {            /* Check for undef */
    *(ptr) = (void *) 0;
    return 0;
  } else if (SvTYPE(sv) == SVt_RV) {  /* Check for NULL pointer */
    *(ptr) = (void *) 0;
    if (!SvROK(sv))
      return 0;
    else
      return -1;
  } else {                            /* Don't know what it is */
    *(ptr) = (void *) 0;
    return -1;
  }
  if (_t) {
    /* Now see if the types match */
    tc = SWIG_TypeCheckRV(sv,_t);
    if (!tc) {
      *ptr = voidptr;
      return -1;
    }
    *ptr = SWIG_TypeCast(tc,voidptr);
    return 0;
  }
  *ptr = voidptr;
  return 0;
}

SWIGRUNTIME(void)
SWIG_Perl_MakePtr(SWIG_MAYBE_PERL_OBJECT SV *sv, void *ptr, swig_type_info *t, int flags) {
  if (ptr && (flags & SWIG_SHADOW)) {
    SV *self;
    SV *obj=newSV(0);
    HV *hash=newHV();
    HV *stash;
    sv_setref_pv(obj, (char *) t->name, ptr);
    stash=SvSTASH(SvRV(obj));
    if (flags & SWIG_OWNER) {
      HV *hv;
      GV *gv=*(GV**)hv_fetch(stash, "OWNER", 5, TRUE);
      if (!isGV(gv))
        gv_init(gv, stash, "OWNER", 5, FALSE);
      hv=GvHVn(gv);
      hv_store_ent(hv, obj, newSViv(1), 0);
    }
    sv_magic((SV *)hash, (SV *)obj, 'P', Nullch, 0);
    SvREFCNT_dec(obj);
    self=newRV_noinc((SV *)hash);
    sv_setsv(sv, self);
    SvREFCNT_dec((SV *)self);
    sv_bless(sv, stash);
  }
  else {
    sv_setref_pv(sv, (char *) t->name, ptr);
  }
}

SWIGRUNTIME(SV *)
SWIG_Perl_NewPointerObj(SWIG_MAYBE_PERL_OBJECT void *ptr, swig_type_info *t, int flags) {
  SV *result = sv_newmortal();
  SWIG_MakePtr(result, ptr, t, flags);
  return result;
}

SWIGRUNTIME(void)
  SWIG_Perl_MakePackedObj(SWIG_MAYBE_PERL_OBJECT SV *sv, void *ptr, int sz, swig_type_info *type) {
  char result[1024];
  char *r = result;
  if ((2*sz + 1 + strlen(type->name)) > 1000) return;
  *(r++) = '_';
  r = SWIG_PackData(r,ptr,sz);
  strcpy(r,type->name);
  sv_setpv(sv, result);
}

/* Convert a packed value value */
SWIGRUNTIME(int)
SWIG_Perl_ConvertPacked(SWIG_MAYBE_PERL_OBJECT SV *obj, void *ptr, int sz, swig_type_info *ty, int flags) {
  swig_type_info *tc;
  char  *c = 0;

  if ((!obj) || (!SvOK(obj))) return -1;
  c = SvPV(obj, PL_na);
  /* Pointer values must start with leading underscore */
  if (*c != '_') return -1;
  c++;
  c = SWIG_UnpackData(c,ptr,sz);
  if (ty) {
    tc = SWIG_TypeCheck(c,ty);
    if (!tc) return -1;
  }
  return 0;
}

SWIGRUNTIME(void)
SWIG_Perl_SetError(SWIG_MAYBE_PERL_OBJECT const char *error) {
  if (error) sv_setpv(perl_get_sv("@", TRUE), error);
}

SWIGRUNTIME(void)
SWIG_Perl_SetErrorSV(SWIG_MAYBE_PERL_OBJECT SV *error) {
  if (error) sv_setsv(perl_get_sv("@", TRUE), error);
}

SWIGRUNTIME(void)
SWIG_Perl_SetErrorf(const char *fmt, ...) {
  va_list args;
  va_start(args, fmt);
  sv_vsetpvfn(perl_get_sv("@", TRUE), fmt, strlen(fmt), &args, Null(SV**), 0, Null(bool*));
  va_end(args);
}

#endif

/* Macros for low-level exception handling */
#define SWIG_fail       goto fail
#define SWIG_croak(x)   { SWIG_SetError(x); goto fail; }
#define SWIG_croakSV(x) { SWIG_SetErrorSV(x); goto fail; }
/* most preprocessors do not support vararg macros :-( */
/* #define SWIG_croakf(x...) { SWIG_SetErrorf(x); goto fail; } */


typedef XS(SwigPerlWrapper);
typedef SwigPerlWrapper *SwigPerlWrapperPtr;

/* Structure for command table */
typedef struct {
  const char         *name;
  SwigPerlWrapperPtr  wrapper;
} swig_command_info;

/* Information for constant table */

#define SWIG_INT     1
#define SWIG_FLOAT   2
#define SWIG_STRING  3
#define SWIG_POINTER 4
#define SWIG_BINARY  5

/* Constant information structure */
typedef struct swig_constant_info {
    int              type;
    const char      *name;
    long             lvalue;
    double           dvalue;
    void            *pvalue;
    swig_type_info **ptype;
} swig_constant_info;

#ifdef __cplusplus
}
#endif

/* Structure for variable table */
typedef struct {
  const char   *name;
  SwigMagicFunc   set;
  SwigMagicFunc   get;
  swig_type_info  **type;
} swig_variable_info;

/* Magic variable code */
#ifndef PERL_OBJECT
#define swig_create_magic(s,a,b,c) _swig_create_magic(s,a,b,c)
  #ifndef MULTIPLICITY
     static void _swig_create_magic(SV *sv, char *name, int (*set)(SV *, MAGIC *), int (*get)(SV *,MAGIC *)) {
  #else
     static void _swig_create_magic(SV *sv, char *name, int (*set)(struct interpreter*, SV *, MAGIC *), int (*get)(struct interpreter*, SV *,MAGIC *)) {
  #endif
#else
#  define swig_create_magic(s,a,b,c) _swig_create_magic(pPerl,s,a,b,c)
static void _swig_create_magic(CPerlObj *pPerl, SV *sv, const char *name, int (CPerlObj::*set)(SV *, MAGIC *), int (CPerlObj::*get)(SV *, MAGIC *)) {
#endif
  MAGIC *mg;
  sv_magic(sv,sv,'U',(char *) name,strlen(name));
  mg = mg_find(sv,'U');
  mg->mg_virtual = (MGVTBL *) malloc(sizeof(MGVTBL));
  mg->mg_virtual->svt_get = (SwigMagicFuncHack) get;
  mg->mg_virtual->svt_set = (SwigMagicFuncHack) set;
  mg->mg_virtual->svt_len = 0;
  mg->mg_virtual->svt_clear = 0;
  mg->mg_virtual->svt_free = 0;
}






#ifdef do_open
  #undef do_open
#endif
#ifdef do_close
  #undef do_close
#endif
#ifdef scalar
  #undef scalar
#endif
#ifdef list
  #undef list
#endif
#ifdef apply
  #undef apply
#endif
#ifdef convert
  #undef convert
#endif
#ifdef Error
  #undef Error
#endif
#ifdef form
  #undef form
#endif
#ifdef vform
  #undef vform
#endif
#ifdef LABEL
  #undef LABEL
#endif
#ifdef METHOD
  #undef METHOD
#endif
#ifdef Move
  #undef Move
#endif
#ifdef yylex
  #undef yylex
#endif
#ifdef yyparse
  #undef yyparse
#endif
#ifdef yyerror
  #undef yyerror
#endif
#ifdef invert
  #undef invert
#endif
#ifdef ref
  #undef ref
#endif
#ifdef ENTER
  #undef ENTER
#endif


/* -------- TYPES TABLE (BEGIN) -------- */

#define  SWIGTYPE_p_unsigned_char swig_types[0] 
static swig_type_info *swig_types[2];

/* -------- TYPES TABLE (END) -------- */

#define SWIG_init    boot_XrdClientAdmin

#define SWIG_name   "XrdClientAdminc::boot_XrdClientAdmin"
#define SWIG_prefix "XrdClientAdminc::"

#ifdef __cplusplus
extern "C"
#endif
#ifndef PERL_OBJECT
#ifndef MULTIPLICITY
SWIGEXPORT(void) SWIG_init (CV* cv);
#else
SWIGEXPORT(void) SWIG_init (pTHXo_ CV* cv);
#endif
#else
SWIGEXPORT(void) SWIG_init (CV *cv, CPerlObj *);
#endif


#include "XrdClientAdmin_c.hh"

#ifdef PERL_OBJECT
#define MAGIC_CLASS _wrap_XrdClientAdmin_var::
class _wrap_XrdClientAdmin_var : public CPerlObj {
public:
#else
#define MAGIC_CLASS
#endif
SWIGCLASS_STATIC int swig_magic_readonly(pTHX_ SV *sv, MAGIC *mg) {
    MAGIC_PPERL
    sv = sv; mg = mg;
    croak("Value is read-only.");
    return 0;
}


#ifdef PERL_OBJECT
};
#endif

#ifdef __cplusplus
extern "C" {
#endif
XS(_wrap_XrdCA_Initialize) {
    {
        char *arg1 ;
        bool result;
        int argvi = 0;
        dXSARGS;
        
        if ((items < 1) || (items > 1)) {
            SWIG_croak("Usage: XrdCA_Initialize(url);");
        }
        if (!SvOK((SV*) ST(0))) arg1 = 0;
        else arg1 = (char *) SvPV(ST(0), PL_na);
        result = (bool)XrdCA_Initialize((char const *)arg1);
        
        ST(argvi) = sv_newmortal();
        sv_setiv(ST(argvi++), (IV) result);
        XSRETURN(argvi);
        fail:
        ;
    }
    croak(Nullch);
}


XS(_wrap_XrdCA_Terminate) {
    {
        bool result;
        int argvi = 0;
        dXSARGS;
        
        if ((items < 0) || (items > 0)) {
            SWIG_croak("Usage: XrdCA_Terminate();");
        }
        result = (bool)XrdCA_Terminate();
        
        ST(argvi) = sv_newmortal();
        sv_setiv(ST(argvi++), (IV) result);
        XSRETURN(argvi);
        fail:
        ;
    }
    croak(Nullch);
}


XS(_wrap_XrdCA_SysStatX) {
    {
        char *arg1 ;
        unsigned char *arg2 = (unsigned char *) 0 ;
        int arg3 ;
        bool result;
        int argvi = 0;
        dXSARGS;
        
        if ((items < 3) || (items > 3)) {
            SWIG_croak("Usage: XrdCA_SysStatX(paths_list,binInfo,numPath);");
        }
        if (!SvOK((SV*) ST(0))) arg1 = 0;
        else arg1 = (char *) SvPV(ST(0), PL_na);
        {
            if (SWIG_ConvertPtr(ST(1), (void **) &arg2, SWIGTYPE_p_unsigned_char,0) < 0) {
                SWIG_croak("Type error in argument 2 of XrdCA_SysStatX. Expected _p_unsigned_char");
            }
        }
        arg3 = (int) SvIV(ST(2));
        result = (bool)XrdCA_SysStatX((char const *)arg1,arg2,arg3);
        
        ST(argvi) = sv_newmortal();
        sv_setiv(ST(argvi++), (IV) result);
        XSRETURN(argvi);
        fail:
        ;
    }
    croak(Nullch);
}


XS(_wrap_XrdCA_ExistFiles) {
    {
        char *arg1 ;
        char *result;
        int argvi = 0;
        dXSARGS;
        
        if ((items < 1) || (items > 1)) {
            SWIG_croak("Usage: XrdCA_ExistFiles(filepaths);");
        }
        if (!SvOK((SV*) ST(0))) arg1 = 0;
        else arg1 = (char *) SvPV(ST(0), PL_na);
        result = (char *)XrdCA_ExistFiles((char const *)arg1);
        
        ST(argvi) = sv_newmortal();
        if (result) {
            sv_setpv((SV*)ST(argvi++), (char *) result);
        } else {
            sv_setsv((SV*)ST(argvi++), &PL_sv_undef);
        }
        XSRETURN(argvi);
        fail:
        ;
    }
    croak(Nullch);
}


XS(_wrap_XrdCA_ExistDirs) {
    {
        char *arg1 ;
        char *result;
        int argvi = 0;
        dXSARGS;
        
        if ((items < 1) || (items > 1)) {
            SWIG_croak("Usage: XrdCA_ExistDirs(filepaths);");
        }
        if (!SvOK((SV*) ST(0))) arg1 = 0;
        else arg1 = (char *) SvPV(ST(0), PL_na);
        result = (char *)XrdCA_ExistDirs((char const *)arg1);
        
        ST(argvi) = sv_newmortal();
        if (result) {
            sv_setpv((SV*)ST(argvi++), (char *) result);
        } else {
            sv_setsv((SV*)ST(argvi++), &PL_sv_undef);
        }
        XSRETURN(argvi);
        fail:
        ;
    }
    croak(Nullch);
}


XS(_wrap_XrdCA_IsFileOnline) {
    {
        char *arg1 ;
        char *result;
        int argvi = 0;
        dXSARGS;
        
        if ((items < 1) || (items > 1)) {
            SWIG_croak("Usage: XrdCA_IsFileOnline(filepaths);");
        }
        if (!SvOK((SV*) ST(0))) arg1 = 0;
        else arg1 = (char *) SvPV(ST(0), PL_na);
        result = (char *)XrdCA_IsFileOnline((char const *)arg1);
        
        ST(argvi) = sv_newmortal();
        if (result) {
            sv_setpv((SV*)ST(argvi++), (char *) result);
        } else {
            sv_setsv((SV*)ST(argvi++), &PL_sv_undef);
        }
        XSRETURN(argvi);
        fail:
        ;
    }
    croak(Nullch);
}


XS(_wrap_XrdCA_Mv) {
    {
        char *arg1 ;
        char *arg2 ;
        bool result;
        int argvi = 0;
        dXSARGS;
        
        if ((items < 2) || (items > 2)) {
            SWIG_croak("Usage: XrdCA_Mv(fileDest,fileSrc);");
        }
        if (!SvOK((SV*) ST(0))) arg1 = 0;
        else arg1 = (char *) SvPV(ST(0), PL_na);
        if (!SvOK((SV*) ST(1))) arg2 = 0;
        else arg2 = (char *) SvPV(ST(1), PL_na);
        result = (bool)XrdCA_Mv((char const *)arg1,(char const *)arg2);
        
        ST(argvi) = sv_newmortal();
        sv_setiv(ST(argvi++), (IV) result);
        XSRETURN(argvi);
        fail:
        ;
    }
    croak(Nullch);
}


XS(_wrap_XrdCA_Mkdir) {
    {
        char *arg1 ;
        int arg2 ;
        int arg3 ;
        int arg4 ;
        bool result;
        int argvi = 0;
        dXSARGS;
        
        if ((items < 4) || (items > 4)) {
            SWIG_croak("Usage: XrdCA_Mkdir(dir,user,group,other);");
        }
        if (!SvOK((SV*) ST(0))) arg1 = 0;
        else arg1 = (char *) SvPV(ST(0), PL_na);
        arg2 = (int) SvIV(ST(1));
        arg3 = (int) SvIV(ST(2));
        arg4 = (int) SvIV(ST(3));
        result = (bool)XrdCA_Mkdir((char const *)arg1,arg2,arg3,arg4);
        
        ST(argvi) = sv_newmortal();
        sv_setiv(ST(argvi++), (IV) result);
        XSRETURN(argvi);
        fail:
        ;
    }
    croak(Nullch);
}


XS(_wrap_XrdCA_Chmod) {
    {
        char *arg1 ;
        int arg2 ;
        int arg3 ;
        int arg4 ;
        bool result;
        int argvi = 0;
        dXSARGS;
        
        if ((items < 4) || (items > 4)) {
            SWIG_croak("Usage: XrdCA_Chmod(file,user,group,other);");
        }
        if (!SvOK((SV*) ST(0))) arg1 = 0;
        else arg1 = (char *) SvPV(ST(0), PL_na);
        arg2 = (int) SvIV(ST(1));
        arg3 = (int) SvIV(ST(2));
        arg4 = (int) SvIV(ST(3));
        result = (bool)XrdCA_Chmod((char const *)arg1,arg2,arg3,arg4);
        
        ST(argvi) = sv_newmortal();
        sv_setiv(ST(argvi++), (IV) result);
        XSRETURN(argvi);
        fail:
        ;
    }
    croak(Nullch);
}


XS(_wrap_XrdCA_Rm) {
    {
        char *arg1 ;
        bool result;
        int argvi = 0;
        dXSARGS;
        
        if ((items < 1) || (items > 1)) {
            SWIG_croak("Usage: XrdCA_Rm(file);");
        }
        if (!SvOK((SV*) ST(0))) arg1 = 0;
        else arg1 = (char *) SvPV(ST(0), PL_na);
        result = (bool)XrdCA_Rm((char const *)arg1);
        
        ST(argvi) = sv_newmortal();
        sv_setiv(ST(argvi++), (IV) result);
        XSRETURN(argvi);
        fail:
        ;
    }
    croak(Nullch);
}


XS(_wrap_XrdCA_Rmdir) {
    {
        char *arg1 ;
        bool result;
        int argvi = 0;
        dXSARGS;
        
        if ((items < 1) || (items > 1)) {
            SWIG_croak("Usage: XrdCA_Rmdir(path);");
        }
        if (!SvOK((SV*) ST(0))) arg1 = 0;
        else arg1 = (char *) SvPV(ST(0), PL_na);
        result = (bool)XrdCA_Rmdir((char const *)arg1);
        
        ST(argvi) = sv_newmortal();
        sv_setiv(ST(argvi++), (IV) result);
        XSRETURN(argvi);
        fail:
        ;
    }
    croak(Nullch);
}


XS(_wrap_XrdCA_Prepare) {
    {
        char *arg1 ;
        unsigned char arg2 ;
        unsigned char arg3 ;
        bool result;
        int argvi = 0;
        dXSARGS;
        
        if ((items < 3) || (items > 3)) {
            SWIG_croak("Usage: XrdCA_Prepare(filepaths,opts,prty);");
        }
        if (!SvOK((SV*) ST(0))) arg1 = 0;
        else arg1 = (char *) SvPV(ST(0), PL_na);
        arg2 = (unsigned char) SvUV(ST(1));
        arg3 = (unsigned char) SvUV(ST(2));
        result = (bool)XrdCA_Prepare((char const *)arg1,arg2,arg3);
        
        ST(argvi) = sv_newmortal();
        sv_setiv(ST(argvi++), (IV) result);
        XSRETURN(argvi);
        fail:
        ;
    }
    croak(Nullch);
}


XS(_wrap_XrdCA_DirList) {
    {
        char *arg1 ;
        char *result;
        int argvi = 0;
        dXSARGS;
        
        if ((items < 1) || (items > 1)) {
            SWIG_croak("Usage: XrdCA_DirList(dir);");
        }
        if (!SvOK((SV*) ST(0))) arg1 = 0;
        else arg1 = (char *) SvPV(ST(0), PL_na);
        result = (char *)XrdCA_DirList((char const *)arg1);
        
        ST(argvi) = sv_newmortal();
        if (result) {
            sv_setpv((SV*)ST(argvi++), (char *) result);
        } else {
            sv_setsv((SV*)ST(argvi++), &PL_sv_undef);
        }
        XSRETURN(argvi);
        fail:
        ;
    }
    croak(Nullch);
}



/* -------- TYPE CONVERSION AND EQUIVALENCE RULES (BEGIN) -------- */

static swig_type_info _swigt__p_unsigned_char[] = {{"_p_unsigned_char", 0, "unsigned char *", 0, 0, 0, 0},{"_p_unsigned_char", 0, 0, 0, 0, 0, 0},{0, 0, 0, 0, 0, 0, 0}};

static swig_type_info *swig_types_initial[] = {
_swigt__p_unsigned_char, 
0
};


/* -------- TYPE CONVERSION AND EQUIVALENCE RULES (END) -------- */

static swig_constant_info swig_constants[] = {
{0,0,0,0,0,0}
};
#ifdef __cplusplus
}
#endif
static swig_variable_info swig_variables[] = {
{0,0,0,0}
};
static swig_command_info swig_commands[] = {
{"XrdClientAdminc::XrdCA_Initialize", _wrap_XrdCA_Initialize},
{"XrdClientAdminc::XrdCA_Terminate", _wrap_XrdCA_Terminate},
{"XrdClientAdminc::XrdCA_SysStatX", _wrap_XrdCA_SysStatX},
{"XrdClientAdminc::XrdCA_ExistFiles", _wrap_XrdCA_ExistFiles},
{"XrdClientAdminc::XrdCA_ExistDirs", _wrap_XrdCA_ExistDirs},
{"XrdClientAdminc::XrdCA_IsFileOnline", _wrap_XrdCA_IsFileOnline},
{"XrdClientAdminc::XrdCA_Mv", _wrap_XrdCA_Mv},
{"XrdClientAdminc::XrdCA_Mkdir", _wrap_XrdCA_Mkdir},
{"XrdClientAdminc::XrdCA_Chmod", _wrap_XrdCA_Chmod},
{"XrdClientAdminc::XrdCA_Rm", _wrap_XrdCA_Rm},
{"XrdClientAdminc::XrdCA_Rmdir", _wrap_XrdCA_Rmdir},
{"XrdClientAdminc::XrdCA_Prepare", _wrap_XrdCA_Prepare},
{"XrdClientAdminc::XrdCA_DirList", _wrap_XrdCA_DirList},
{0,0}
};

#ifdef __cplusplus
extern "C"
#endif

XS(SWIG_init) {
    dXSARGS;
    int i;
    static int _init = 0;
    if (!_init) {
        for (i = 0; swig_types_initial[i]; i++) {
            swig_types[i] = SWIG_TypeRegister(swig_types_initial[i]);
        }	
        _init = 1;
    }
    
    /* Install commands */
    for (i = 0; swig_commands[i].name; i++) {
        newXS((char*) swig_commands[i].name,swig_commands[i].wrapper, (char*)__FILE__);
    }
    
    /* Install variables */
    for (i = 0; swig_variables[i].name; i++) {
        SV *sv;
        sv = perl_get_sv((char*) swig_variables[i].name, TRUE | 0x2);
        if (swig_variables[i].type) {
            SWIG_MakePtr(sv,(void *)1, *swig_variables[i].type,0);
        } else {
            sv_setiv(sv,(IV) 0);
        }
        swig_create_magic(sv, (char *) swig_variables[i].name, swig_variables[i].set, swig_variables[i].get); 
    }
    
    /* Install constant */
    for (i = 0; swig_constants[i].type; i++) {
        SV *sv;
        sv = perl_get_sv((char*)swig_constants[i].name, TRUE | 0x2);
        switch(swig_constants[i].type) {
            case SWIG_INT:
            sv_setiv(sv, (IV) swig_constants[i].lvalue);
            break;
            case SWIG_FLOAT:
            sv_setnv(sv, (double) swig_constants[i].dvalue);
            break;
            case SWIG_STRING:
            sv_setpv(sv, (char *) swig_constants[i].pvalue);
            break;
            case SWIG_POINTER:
            SWIG_MakePtr(sv, swig_constants[i].pvalue, *(swig_constants[i].ptype),0);
            break;
            case SWIG_BINARY:
            SWIG_MakePackedObj(sv, swig_constants[i].pvalue, swig_constants[i].lvalue, *(swig_constants[i].ptype));
            break;
            default:
            break;
        }
        SvREADONLY_on(sv);
    }
    
    ST(0) = &PL_sv_yes;
    XSRETURN(1);
}

