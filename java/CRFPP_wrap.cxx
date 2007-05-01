/* ----------------------------------------------------------------------------
 * This file was automatically generated by SWIG (http://www.swig.org).
 * Version 1.3.31
 * 
 * This file is not intended to be easily readable and contains a number of 
 * coding conventions designed to improve portability and efficiency. Do not make
 * changes to this file unless you know what you are doing--modify the SWIG 
 * interface file instead. 
 * ----------------------------------------------------------------------------- */


#ifdef __cplusplus
template<class T> class SwigValueWrapper {
    T *tt;
public:
    SwigValueWrapper() : tt(0) { }
    SwigValueWrapper(const SwigValueWrapper<T>& rhs) : tt(new T(*rhs.tt)) { }
    SwigValueWrapper(const T& t) : tt(new T(t)) { }
    ~SwigValueWrapper() { delete tt; } 
    SwigValueWrapper& operator=(const T& t) { delete tt; tt = new T(t); return *this; }
    operator T&() const { return *tt; }
    T *operator&() { return tt; }
private:
    SwigValueWrapper& operator=(const SwigValueWrapper<T>& rhs);
};
#endif

/* -----------------------------------------------------------------------------
 *  This section contains generic SWIG labels for method/variable
 *  declarations/attributes, and other compiler dependent labels.
 * ----------------------------------------------------------------------------- */

/* template workaround for compilers that cannot correctly implement the C++ standard */
#ifndef SWIGTEMPLATEDISAMBIGUATOR
# if defined(__SUNPRO_CC)
#   if (__SUNPRO_CC <= 0x560)
#     define SWIGTEMPLATEDISAMBIGUATOR template
#   else
#     define SWIGTEMPLATEDISAMBIGUATOR 
#   endif
# else
#   define SWIGTEMPLATEDISAMBIGUATOR 
# endif
#endif

/* inline attribute */
#ifndef SWIGINLINE
# if defined(__cplusplus) || (defined(__GNUC__) && !defined(__STRICT_ANSI__))
#   define SWIGINLINE inline
# else
#   define SWIGINLINE
# endif
#endif

/* attribute recognised by some compilers to avoid 'unused' warnings */
#ifndef SWIGUNUSED
# if defined(__GNUC__)
#   if !(defined(__cplusplus)) || (__GNUC__ > 3 || (__GNUC__ == 3 && __GNUC_MINOR__ >= 4))
#     define SWIGUNUSED __attribute__ ((__unused__)) 
#   else
#     define SWIGUNUSED
#   endif
# elif defined(__ICC)
#   define SWIGUNUSED __attribute__ ((__unused__)) 
# else
#   define SWIGUNUSED 
# endif
#endif

#ifndef SWIGUNUSEDPARM
# ifdef __cplusplus
#   define SWIGUNUSEDPARM(p)
# else
#   define SWIGUNUSEDPARM(p) p SWIGUNUSED 
# endif
#endif

/* internal SWIG method */
#ifndef SWIGINTERN
# define SWIGINTERN static SWIGUNUSED
#endif

/* internal inline SWIG method */
#ifndef SWIGINTERNINLINE
# define SWIGINTERNINLINE SWIGINTERN SWIGINLINE
#endif

/* exporting methods */
#if (__GNUC__ >= 4) || (__GNUC__ == 3 && __GNUC_MINOR__ >= 4)
#  ifndef GCC_HASCLASSVISIBILITY
#    define GCC_HASCLASSVISIBILITY
#  endif
#endif

#ifndef SWIGEXPORT
# if defined(_WIN32) || defined(__WIN32__) || defined(__CYGWIN__)
#   if defined(STATIC_LINKED)
#     define SWIGEXPORT
#   else
#     define SWIGEXPORT __declspec(dllexport)
#   endif
# else
#   if defined(__GNUC__) && defined(GCC_HASCLASSVISIBILITY)
#     define SWIGEXPORT __attribute__ ((visibility("default")))
#   else
#     define SWIGEXPORT
#   endif
# endif
#endif

/* calling conventions for Windows */
#ifndef SWIGSTDCALL
# if defined(_WIN32) || defined(__WIN32__) || defined(__CYGWIN__)
#   define SWIGSTDCALL __stdcall
# else
#   define SWIGSTDCALL
# endif 
#endif

/* Deal with Microsoft's attempt at deprecating C standard runtime functions */
#if !defined(SWIG_NO_CRT_SECURE_NO_DEPRECATE) && defined(_MSC_VER) && !defined(_CRT_SECURE_NO_DEPRECATE)
# define _CRT_SECURE_NO_DEPRECATE
#endif


/* Fix for jlong on some versions of gcc on Windows */
#if defined(__GNUC__) && !defined(__INTELC__)
  typedef long long __int64;
#endif

/* Fix for jlong on 64-bit x86 Solaris */
#if defined(__x86_64)
# ifdef _LP64
#   undef _LP64
# endif
#endif

#include <jni.h>
#include <stdlib.h>
#include <string.h>


/* Support for throwing Java exceptions */
typedef enum {
  SWIG_JavaOutOfMemoryError = 1, 
  SWIG_JavaIOException, 
  SWIG_JavaRuntimeException, 
  SWIG_JavaIndexOutOfBoundsException,
  SWIG_JavaArithmeticException,
  SWIG_JavaIllegalArgumentException,
  SWIG_JavaNullPointerException,
  SWIG_JavaDirectorPureVirtual,
  SWIG_JavaUnknownError
} SWIG_JavaExceptionCodes;

typedef struct {
  SWIG_JavaExceptionCodes code;
  const char *java_exception;
} SWIG_JavaExceptions_t;


static void SWIGUNUSED SWIG_JavaThrowException(JNIEnv *jenv, SWIG_JavaExceptionCodes code, const char *msg) {
  jclass excep;
  static const SWIG_JavaExceptions_t java_exceptions[] = {
    { SWIG_JavaOutOfMemoryError, "java/lang/OutOfMemoryError" },
    { SWIG_JavaIOException, "java/io/IOException" },
    { SWIG_JavaRuntimeException, "java/lang/RuntimeException" },
    { SWIG_JavaIndexOutOfBoundsException, "java/lang/IndexOutOfBoundsException" },
    { SWIG_JavaArithmeticException, "java/lang/ArithmeticException" },
    { SWIG_JavaIllegalArgumentException, "java/lang/IllegalArgumentException" },
    { SWIG_JavaNullPointerException, "java/lang/NullPointerException" },
    { SWIG_JavaDirectorPureVirtual, "java/lang/RuntimeException" },
    { SWIG_JavaUnknownError,  "java/lang/UnknownError" },
    { (SWIG_JavaExceptionCodes)0,  "java/lang/UnknownError" } };
  const SWIG_JavaExceptions_t *except_ptr = java_exceptions;

  while (except_ptr->code != code && except_ptr->code)
    except_ptr++;

  jenv->ExceptionClear();
  excep = jenv->FindClass(except_ptr->java_exception);
  if (excep)
    jenv->ThrowNew(excep, msg);
}


/* Contract support */

#define SWIG_contract_assert(nullreturn, expr, msg) if (!(expr)) {SWIG_JavaThrowException(jenv, SWIG_JavaIllegalArgumentException, msg); return nullreturn; } else

/*  Errors in SWIG */
#define  SWIG_UnknownError    	   -1 
#define  SWIG_IOError        	   -2 
#define  SWIG_RuntimeError   	   -3 
#define  SWIG_IndexError     	   -4 
#define  SWIG_TypeError      	   -5 
#define  SWIG_DivisionByZero 	   -6 
#define  SWIG_OverflowError  	   -7 
#define  SWIG_SyntaxError    	   -8 
#define  SWIG_ValueError     	   -9 
#define  SWIG_SystemError    	   -10
#define  SWIG_AttributeError 	   -11
#define  SWIG_MemoryError    	   -12 
#define  SWIG_NullReferenceError   -13




SWIGINTERN void SWIG_JavaException(JNIEnv *jenv, int code, const char *msg) {
  SWIG_JavaExceptionCodes exception_code = SWIG_JavaUnknownError;
  switch(code) {
  case SWIG_MemoryError:
    exception_code = SWIG_JavaOutOfMemoryError;
    break;
  case SWIG_IOError:
    exception_code = SWIG_JavaIOException;
    break;
  case SWIG_SystemError:
  case SWIG_RuntimeError:
    exception_code = SWIG_JavaRuntimeException;
    break;
  case SWIG_OverflowError:
  case SWIG_IndexError:
    exception_code = SWIG_JavaIndexOutOfBoundsException;
    break;
  case SWIG_DivisionByZero:
    exception_code = SWIG_JavaArithmeticException;
    break;
  case SWIG_SyntaxError:
  case SWIG_ValueError:
  case SWIG_TypeError:
    exception_code = SWIG_JavaIllegalArgumentException;
    break;
  case SWIG_UnknownError:
  default:
    exception_code = SWIG_JavaUnknownError;
    break;
  }
  SWIG_JavaThrowException(jenv, exception_code, msg);
}


#include <stdexcept>


#include "crfpp.h"



void delete_CRFPP_Tagger (CRFPP::Tagger *t) {
  delete t;
  t = 0;
}

CRFPP::Tagger* new_CRFPP_Tagger (const char *arg) {
  CRFPP::Tagger *tagger = CRFPP::createTagger(arg);
  if (! tagger) throw CRFPP::getTaggerError();
  return tagger;
}



#ifdef __cplusplus
extern "C" {
#endif

SWIGEXPORT jboolean JNICALL Java_org_chasen_crfpp_CRFPPJNI_Tagger_1add(JNIEnv *jenv, jclass jcls, jlong jarg1, jobject jarg1_, jstring jarg2) {
  jboolean jresult = 0 ;
  CRFPP::Tagger *arg1 = (CRFPP::Tagger *) 0 ;
  char *arg2 = (char *) 0 ;
  bool result;
  
  (void)jenv;
  (void)jcls;
  (void)jarg1_;
  arg1 = *(CRFPP::Tagger **)&jarg1; 
  arg2 = 0;
  if (jarg2) {
    arg2 = (char *)jenv->GetStringUTFChars(jarg2, 0);
    if (!arg2) return 0;
  }
  {
    try {
      result = (bool)(arg1)->add((char const *)arg2); 
    }
    catch (char *e) {
      {
        SWIG_JavaException(jenv, SWIG_RuntimeError, e); return 0; 
      }; 
    }
    catch (const char *e) {
      {
        SWIG_JavaException(jenv, SWIG_RuntimeError, (char*)e); return 0; 
      }; 
    }
  }
  jresult = (jboolean)result; 
  if (arg2) jenv->ReleaseStringUTFChars(jarg2, (const char *)arg2);
  return jresult;
}


SWIGEXPORT jlong JNICALL Java_org_chasen_crfpp_CRFPPJNI_Tagger_1size(JNIEnv *jenv, jclass jcls, jlong jarg1, jobject jarg1_) {
  jlong jresult = 0 ;
  CRFPP::Tagger *arg1 = (CRFPP::Tagger *) 0 ;
  size_t result;
  
  (void)jenv;
  (void)jcls;
  (void)jarg1_;
  arg1 = *(CRFPP::Tagger **)&jarg1; 
  {
    try {
      result = ((CRFPP::Tagger const *)arg1)->size(); 
    }
    catch (char *e) {
      {
        SWIG_JavaException(jenv, SWIG_RuntimeError, e); return 0; 
      }; 
    }
    catch (const char *e) {
      {
        SWIG_JavaException(jenv, SWIG_RuntimeError, (char*)e); return 0; 
      }; 
    }
  }
  jresult = (jlong)result; 
  return jresult;
}


SWIGEXPORT jlong JNICALL Java_org_chasen_crfpp_CRFPPJNI_Tagger_1xsize(JNIEnv *jenv, jclass jcls, jlong jarg1, jobject jarg1_) {
  jlong jresult = 0 ;
  CRFPP::Tagger *arg1 = (CRFPP::Tagger *) 0 ;
  size_t result;
  
  (void)jenv;
  (void)jcls;
  (void)jarg1_;
  arg1 = *(CRFPP::Tagger **)&jarg1; 
  {
    try {
      result = ((CRFPP::Tagger const *)arg1)->xsize(); 
    }
    catch (char *e) {
      {
        SWIG_JavaException(jenv, SWIG_RuntimeError, e); return 0; 
      }; 
    }
    catch (const char *e) {
      {
        SWIG_JavaException(jenv, SWIG_RuntimeError, (char*)e); return 0; 
      }; 
    }
  }
  jresult = (jlong)result; 
  return jresult;
}


SWIGEXPORT jlong JNICALL Java_org_chasen_crfpp_CRFPPJNI_Tagger_1dsize(JNIEnv *jenv, jclass jcls, jlong jarg1, jobject jarg1_) {
  jlong jresult = 0 ;
  CRFPP::Tagger *arg1 = (CRFPP::Tagger *) 0 ;
  size_t result;
  
  (void)jenv;
  (void)jcls;
  (void)jarg1_;
  arg1 = *(CRFPP::Tagger **)&jarg1; 
  {
    try {
      result = ((CRFPP::Tagger const *)arg1)->dsize(); 
    }
    catch (char *e) {
      {
        SWIG_JavaException(jenv, SWIG_RuntimeError, e); return 0; 
      }; 
    }
    catch (const char *e) {
      {
        SWIG_JavaException(jenv, SWIG_RuntimeError, (char*)e); return 0; 
      }; 
    }
  }
  jresult = (jlong)result; 
  return jresult;
}


SWIGEXPORT jlong JNICALL Java_org_chasen_crfpp_CRFPPJNI_Tagger_1result(JNIEnv *jenv, jclass jcls, jlong jarg1, jobject jarg1_, jlong jarg2) {
  jlong jresult = 0 ;
  CRFPP::Tagger *arg1 = (CRFPP::Tagger *) 0 ;
  size_t arg2 ;
  size_t result;
  
  (void)jenv;
  (void)jcls;
  (void)jarg1_;
  arg1 = *(CRFPP::Tagger **)&jarg1; 
  arg2 = (size_t)jarg2; 
  {
    try {
      result = ((CRFPP::Tagger const *)arg1)->result(arg2); 
    }
    catch (char *e) {
      {
        SWIG_JavaException(jenv, SWIG_RuntimeError, e); return 0; 
      }; 
    }
    catch (const char *e) {
      {
        SWIG_JavaException(jenv, SWIG_RuntimeError, (char*)e); return 0; 
      }; 
    }
  }
  jresult = (jlong)result; 
  return jresult;
}


SWIGEXPORT jlong JNICALL Java_org_chasen_crfpp_CRFPPJNI_Tagger_1answer(JNIEnv *jenv, jclass jcls, jlong jarg1, jobject jarg1_, jlong jarg2) {
  jlong jresult = 0 ;
  CRFPP::Tagger *arg1 = (CRFPP::Tagger *) 0 ;
  size_t arg2 ;
  size_t result;
  
  (void)jenv;
  (void)jcls;
  (void)jarg1_;
  arg1 = *(CRFPP::Tagger **)&jarg1; 
  arg2 = (size_t)jarg2; 
  {
    try {
      result = ((CRFPP::Tagger const *)arg1)->answer(arg2); 
    }
    catch (char *e) {
      {
        SWIG_JavaException(jenv, SWIG_RuntimeError, e); return 0; 
      }; 
    }
    catch (const char *e) {
      {
        SWIG_JavaException(jenv, SWIG_RuntimeError, (char*)e); return 0; 
      }; 
    }
  }
  jresult = (jlong)result; 
  return jresult;
}


SWIGEXPORT jlong JNICALL Java_org_chasen_crfpp_CRFPPJNI_Tagger_1y(JNIEnv *jenv, jclass jcls, jlong jarg1, jobject jarg1_, jlong jarg2) {
  jlong jresult = 0 ;
  CRFPP::Tagger *arg1 = (CRFPP::Tagger *) 0 ;
  size_t arg2 ;
  size_t result;
  
  (void)jenv;
  (void)jcls;
  (void)jarg1_;
  arg1 = *(CRFPP::Tagger **)&jarg1; 
  arg2 = (size_t)jarg2; 
  {
    try {
      result = ((CRFPP::Tagger const *)arg1)->y(arg2); 
    }
    catch (char *e) {
      {
        SWIG_JavaException(jenv, SWIG_RuntimeError, e); return 0; 
      }; 
    }
    catch (const char *e) {
      {
        SWIG_JavaException(jenv, SWIG_RuntimeError, (char*)e); return 0; 
      }; 
    }
  }
  jresult = (jlong)result; 
  return jresult;
}


SWIGEXPORT jstring JNICALL Java_org_chasen_crfpp_CRFPPJNI_Tagger_1y2(JNIEnv *jenv, jclass jcls, jlong jarg1, jobject jarg1_, jlong jarg2) {
  jstring jresult = 0 ;
  CRFPP::Tagger *arg1 = (CRFPP::Tagger *) 0 ;
  size_t arg2 ;
  char *result = 0 ;
  
  (void)jenv;
  (void)jcls;
  (void)jarg1_;
  arg1 = *(CRFPP::Tagger **)&jarg1; 
  arg2 = (size_t)jarg2; 
  {
    try {
      result = (char *)((CRFPP::Tagger const *)arg1)->y2(arg2); 
    }
    catch (char *e) {
      {
        SWIG_JavaException(jenv, SWIG_RuntimeError, e); return 0; 
      }; 
    }
    catch (const char *e) {
      {
        SWIG_JavaException(jenv, SWIG_RuntimeError, (char*)e); return 0; 
      }; 
    }
  }
  if(result) jresult = jenv->NewStringUTF((const char *)result);
  return jresult;
}


SWIGEXPORT jstring JNICALL Java_org_chasen_crfpp_CRFPPJNI_Tagger_1yname(JNIEnv *jenv, jclass jcls, jlong jarg1, jobject jarg1_, jlong jarg2) {
  jstring jresult = 0 ;
  CRFPP::Tagger *arg1 = (CRFPP::Tagger *) 0 ;
  size_t arg2 ;
  char *result = 0 ;
  
  (void)jenv;
  (void)jcls;
  (void)jarg1_;
  arg1 = *(CRFPP::Tagger **)&jarg1; 
  arg2 = (size_t)jarg2; 
  {
    try {
      result = (char *)((CRFPP::Tagger const *)arg1)->yname(arg2); 
    }
    catch (char *e) {
      {
        SWIG_JavaException(jenv, SWIG_RuntimeError, e); return 0; 
      }; 
    }
    catch (const char *e) {
      {
        SWIG_JavaException(jenv, SWIG_RuntimeError, (char*)e); return 0; 
      }; 
    }
  }
  if(result) jresult = jenv->NewStringUTF((const char *)result);
  return jresult;
}


SWIGEXPORT jstring JNICALL Java_org_chasen_crfpp_CRFPPJNI_Tagger_1x(JNIEnv *jenv, jclass jcls, jlong jarg1, jobject jarg1_, jlong jarg2, jlong jarg3) {
  jstring jresult = 0 ;
  CRFPP::Tagger *arg1 = (CRFPP::Tagger *) 0 ;
  size_t arg2 ;
  size_t arg3 ;
  char *result = 0 ;
  
  (void)jenv;
  (void)jcls;
  (void)jarg1_;
  arg1 = *(CRFPP::Tagger **)&jarg1; 
  arg2 = (size_t)jarg2; 
  arg3 = (size_t)jarg3; 
  {
    try {
      result = (char *)((CRFPP::Tagger const *)arg1)->x(arg2,arg3); 
    }
    catch (char *e) {
      {
        SWIG_JavaException(jenv, SWIG_RuntimeError, e); return 0; 
      }; 
    }
    catch (const char *e) {
      {
        SWIG_JavaException(jenv, SWIG_RuntimeError, (char*)e); return 0; 
      }; 
    }
  }
  if(result) jresult = jenv->NewStringUTF((const char *)result);
  return jresult;
}


SWIGEXPORT jlong JNICALL Java_org_chasen_crfpp_CRFPPJNI_Tagger_1ysize(JNIEnv *jenv, jclass jcls, jlong jarg1, jobject jarg1_) {
  jlong jresult = 0 ;
  CRFPP::Tagger *arg1 = (CRFPP::Tagger *) 0 ;
  size_t result;
  
  (void)jenv;
  (void)jcls;
  (void)jarg1_;
  arg1 = *(CRFPP::Tagger **)&jarg1; 
  {
    try {
      result = ((CRFPP::Tagger const *)arg1)->ysize(); 
    }
    catch (char *e) {
      {
        SWIG_JavaException(jenv, SWIG_RuntimeError, e); return 0; 
      }; 
    }
    catch (const char *e) {
      {
        SWIG_JavaException(jenv, SWIG_RuntimeError, (char*)e); return 0; 
      }; 
    }
  }
  jresult = (jlong)result; 
  return jresult;
}


SWIGEXPORT jdouble JNICALL Java_org_chasen_crfpp_CRFPPJNI_Tagger_1prob_1_1SWIG_10(JNIEnv *jenv, jclass jcls, jlong jarg1, jobject jarg1_, jlong jarg2, jlong jarg3) {
  jdouble jresult = 0 ;
  CRFPP::Tagger *arg1 = (CRFPP::Tagger *) 0 ;
  size_t arg2 ;
  size_t arg3 ;
  double result;
  
  (void)jenv;
  (void)jcls;
  (void)jarg1_;
  arg1 = *(CRFPP::Tagger **)&jarg1; 
  arg2 = (size_t)jarg2; 
  arg3 = (size_t)jarg3; 
  {
    try {
      result = (double)((CRFPP::Tagger const *)arg1)->prob(arg2,arg3); 
    }
    catch (char *e) {
      {
        SWIG_JavaException(jenv, SWIG_RuntimeError, e); return 0; 
      }; 
    }
    catch (const char *e) {
      {
        SWIG_JavaException(jenv, SWIG_RuntimeError, (char*)e); return 0; 
      }; 
    }
  }
  jresult = (jdouble)result; 
  return jresult;
}


SWIGEXPORT jdouble JNICALL Java_org_chasen_crfpp_CRFPPJNI_Tagger_1prob_1_1SWIG_11(JNIEnv *jenv, jclass jcls, jlong jarg1, jobject jarg1_, jlong jarg2) {
  jdouble jresult = 0 ;
  CRFPP::Tagger *arg1 = (CRFPP::Tagger *) 0 ;
  size_t arg2 ;
  double result;
  
  (void)jenv;
  (void)jcls;
  (void)jarg1_;
  arg1 = *(CRFPP::Tagger **)&jarg1; 
  arg2 = (size_t)jarg2; 
  {
    try {
      result = (double)((CRFPP::Tagger const *)arg1)->prob(arg2); 
    }
    catch (char *e) {
      {
        SWIG_JavaException(jenv, SWIG_RuntimeError, e); return 0; 
      }; 
    }
    catch (const char *e) {
      {
        SWIG_JavaException(jenv, SWIG_RuntimeError, (char*)e); return 0; 
      }; 
    }
  }
  jresult = (jdouble)result; 
  return jresult;
}


SWIGEXPORT jdouble JNICALL Java_org_chasen_crfpp_CRFPPJNI_Tagger_1prob_1_1SWIG_12(JNIEnv *jenv, jclass jcls, jlong jarg1, jobject jarg1_) {
  jdouble jresult = 0 ;
  CRFPP::Tagger *arg1 = (CRFPP::Tagger *) 0 ;
  double result;
  
  (void)jenv;
  (void)jcls;
  (void)jarg1_;
  arg1 = *(CRFPP::Tagger **)&jarg1; 
  {
    try {
      result = (double)((CRFPP::Tagger const *)arg1)->prob(); 
    }
    catch (char *e) {
      {
        SWIG_JavaException(jenv, SWIG_RuntimeError, e); return 0; 
      }; 
    }
    catch (const char *e) {
      {
        SWIG_JavaException(jenv, SWIG_RuntimeError, (char*)e); return 0; 
      }; 
    }
  }
  jresult = (jdouble)result; 
  return jresult;
}


SWIGEXPORT jdouble JNICALL Java_org_chasen_crfpp_CRFPPJNI_Tagger_1alpha(JNIEnv *jenv, jclass jcls, jlong jarg1, jobject jarg1_, jlong jarg2, jlong jarg3) {
  jdouble jresult = 0 ;
  CRFPP::Tagger *arg1 = (CRFPP::Tagger *) 0 ;
  size_t arg2 ;
  size_t arg3 ;
  double result;
  
  (void)jenv;
  (void)jcls;
  (void)jarg1_;
  arg1 = *(CRFPP::Tagger **)&jarg1; 
  arg2 = (size_t)jarg2; 
  arg3 = (size_t)jarg3; 
  {
    try {
      result = (double)((CRFPP::Tagger const *)arg1)->alpha(arg2,arg3); 
    }
    catch (char *e) {
      {
        SWIG_JavaException(jenv, SWIG_RuntimeError, e); return 0; 
      }; 
    }
    catch (const char *e) {
      {
        SWIG_JavaException(jenv, SWIG_RuntimeError, (char*)e); return 0; 
      }; 
    }
  }
  jresult = (jdouble)result; 
  return jresult;
}


SWIGEXPORT jdouble JNICALL Java_org_chasen_crfpp_CRFPPJNI_Tagger_1beta(JNIEnv *jenv, jclass jcls, jlong jarg1, jobject jarg1_, jlong jarg2, jlong jarg3) {
  jdouble jresult = 0 ;
  CRFPP::Tagger *arg1 = (CRFPP::Tagger *) 0 ;
  size_t arg2 ;
  size_t arg3 ;
  double result;
  
  (void)jenv;
  (void)jcls;
  (void)jarg1_;
  arg1 = *(CRFPP::Tagger **)&jarg1; 
  arg2 = (size_t)jarg2; 
  arg3 = (size_t)jarg3; 
  {
    try {
      result = (double)((CRFPP::Tagger const *)arg1)->beta(arg2,arg3); 
    }
    catch (char *e) {
      {
        SWIG_JavaException(jenv, SWIG_RuntimeError, e); return 0; 
      }; 
    }
    catch (const char *e) {
      {
        SWIG_JavaException(jenv, SWIG_RuntimeError, (char*)e); return 0; 
      }; 
    }
  }
  jresult = (jdouble)result; 
  return jresult;
}


SWIGEXPORT jdouble JNICALL Java_org_chasen_crfpp_CRFPPJNI_Tagger_1emission_1cost(JNIEnv *jenv, jclass jcls, jlong jarg1, jobject jarg1_, jlong jarg2, jlong jarg3) {
  jdouble jresult = 0 ;
  CRFPP::Tagger *arg1 = (CRFPP::Tagger *) 0 ;
  size_t arg2 ;
  size_t arg3 ;
  double result;
  
  (void)jenv;
  (void)jcls;
  (void)jarg1_;
  arg1 = *(CRFPP::Tagger **)&jarg1; 
  arg2 = (size_t)jarg2; 
  arg3 = (size_t)jarg3; 
  {
    try {
      result = (double)((CRFPP::Tagger const *)arg1)->emission_cost(arg2,arg3); 
    }
    catch (char *e) {
      {
        SWIG_JavaException(jenv, SWIG_RuntimeError, e); return 0; 
      }; 
    }
    catch (const char *e) {
      {
        SWIG_JavaException(jenv, SWIG_RuntimeError, (char*)e); return 0; 
      }; 
    }
  }
  jresult = (jdouble)result; 
  return jresult;
}


SWIGEXPORT jdouble JNICALL Java_org_chasen_crfpp_CRFPPJNI_Tagger_1next_1transition_1cost(JNIEnv *jenv, jclass jcls, jlong jarg1, jobject jarg1_, jlong jarg2, jlong jarg3, jlong jarg4) {
  jdouble jresult = 0 ;
  CRFPP::Tagger *arg1 = (CRFPP::Tagger *) 0 ;
  size_t arg2 ;
  size_t arg3 ;
  size_t arg4 ;
  double result;
  
  (void)jenv;
  (void)jcls;
  (void)jarg1_;
  arg1 = *(CRFPP::Tagger **)&jarg1; 
  arg2 = (size_t)jarg2; 
  arg3 = (size_t)jarg3; 
  arg4 = (size_t)jarg4; 
  {
    try {
      result = (double)((CRFPP::Tagger const *)arg1)->next_transition_cost(arg2,arg3,arg4); 
    }
    catch (char *e) {
      {
        SWIG_JavaException(jenv, SWIG_RuntimeError, e); return 0; 
      }; 
    }
    catch (const char *e) {
      {
        SWIG_JavaException(jenv, SWIG_RuntimeError, (char*)e); return 0; 
      }; 
    }
  }
  jresult = (jdouble)result; 
  return jresult;
}


SWIGEXPORT jdouble JNICALL Java_org_chasen_crfpp_CRFPPJNI_Tagger_1prev_1transition_1cost(JNIEnv *jenv, jclass jcls, jlong jarg1, jobject jarg1_, jlong jarg2, jlong jarg3, jlong jarg4) {
  jdouble jresult = 0 ;
  CRFPP::Tagger *arg1 = (CRFPP::Tagger *) 0 ;
  size_t arg2 ;
  size_t arg3 ;
  size_t arg4 ;
  double result;
  
  (void)jenv;
  (void)jcls;
  (void)jarg1_;
  arg1 = *(CRFPP::Tagger **)&jarg1; 
  arg2 = (size_t)jarg2; 
  arg3 = (size_t)jarg3; 
  arg4 = (size_t)jarg4; 
  {
    try {
      result = (double)((CRFPP::Tagger const *)arg1)->prev_transition_cost(arg2,arg3,arg4); 
    }
    catch (char *e) {
      {
        SWIG_JavaException(jenv, SWIG_RuntimeError, e); return 0; 
      }; 
    }
    catch (const char *e) {
      {
        SWIG_JavaException(jenv, SWIG_RuntimeError, (char*)e); return 0; 
      }; 
    }
  }
  jresult = (jdouble)result; 
  return jresult;
}


SWIGEXPORT jdouble JNICALL Java_org_chasen_crfpp_CRFPPJNI_Tagger_1best_1cost(JNIEnv *jenv, jclass jcls, jlong jarg1, jobject jarg1_, jlong jarg2, jlong jarg3) {
  jdouble jresult = 0 ;
  CRFPP::Tagger *arg1 = (CRFPP::Tagger *) 0 ;
  size_t arg2 ;
  size_t arg3 ;
  double result;
  
  (void)jenv;
  (void)jcls;
  (void)jarg1_;
  arg1 = *(CRFPP::Tagger **)&jarg1; 
  arg2 = (size_t)jarg2; 
  arg3 = (size_t)jarg3; 
  {
    try {
      result = (double)((CRFPP::Tagger const *)arg1)->best_cost(arg2,arg3); 
    }
    catch (char *e) {
      {
        SWIG_JavaException(jenv, SWIG_RuntimeError, e); return 0; 
      }; 
    }
    catch (const char *e) {
      {
        SWIG_JavaException(jenv, SWIG_RuntimeError, (char*)e); return 0; 
      }; 
    }
  }
  jresult = (jdouble)result; 
  return jresult;
}


SWIGEXPORT jdouble JNICALL Java_org_chasen_crfpp_CRFPPJNI_Tagger_1Z(JNIEnv *jenv, jclass jcls, jlong jarg1, jobject jarg1_) {
  jdouble jresult = 0 ;
  CRFPP::Tagger *arg1 = (CRFPP::Tagger *) 0 ;
  double result;
  
  (void)jenv;
  (void)jcls;
  (void)jarg1_;
  arg1 = *(CRFPP::Tagger **)&jarg1; 
  {
    try {
      result = (double)((CRFPP::Tagger const *)arg1)->Z(); 
    }
    catch (char *e) {
      {
        SWIG_JavaException(jenv, SWIG_RuntimeError, e); return 0; 
      }; 
    }
    catch (const char *e) {
      {
        SWIG_JavaException(jenv, SWIG_RuntimeError, (char*)e); return 0; 
      }; 
    }
  }
  jresult = (jdouble)result; 
  return jresult;
}


SWIGEXPORT jboolean JNICALL Java_org_chasen_crfpp_CRFPPJNI_Tagger_1parse_1_1SWIG_10(JNIEnv *jenv, jclass jcls, jlong jarg1, jobject jarg1_) {
  jboolean jresult = 0 ;
  CRFPP::Tagger *arg1 = (CRFPP::Tagger *) 0 ;
  bool result;
  
  (void)jenv;
  (void)jcls;
  (void)jarg1_;
  arg1 = *(CRFPP::Tagger **)&jarg1; 
  {
    try {
      result = (bool)(arg1)->parse(); 
    }
    catch (char *e) {
      {
        SWIG_JavaException(jenv, SWIG_RuntimeError, e); return 0; 
      }; 
    }
    catch (const char *e) {
      {
        SWIG_JavaException(jenv, SWIG_RuntimeError, (char*)e); return 0; 
      }; 
    }
  }
  jresult = (jboolean)result; 
  return jresult;
}


SWIGEXPORT jboolean JNICALL Java_org_chasen_crfpp_CRFPPJNI_Tagger_1empty(JNIEnv *jenv, jclass jcls, jlong jarg1, jobject jarg1_) {
  jboolean jresult = 0 ;
  CRFPP::Tagger *arg1 = (CRFPP::Tagger *) 0 ;
  bool result;
  
  (void)jenv;
  (void)jcls;
  (void)jarg1_;
  arg1 = *(CRFPP::Tagger **)&jarg1; 
  {
    try {
      result = (bool)((CRFPP::Tagger const *)arg1)->empty(); 
    }
    catch (char *e) {
      {
        SWIG_JavaException(jenv, SWIG_RuntimeError, e); return 0; 
      }; 
    }
    catch (const char *e) {
      {
        SWIG_JavaException(jenv, SWIG_RuntimeError, (char*)e); return 0; 
      }; 
    }
  }
  jresult = (jboolean)result; 
  return jresult;
}


SWIGEXPORT jboolean JNICALL Java_org_chasen_crfpp_CRFPPJNI_Tagger_1clear(JNIEnv *jenv, jclass jcls, jlong jarg1, jobject jarg1_) {
  jboolean jresult = 0 ;
  CRFPP::Tagger *arg1 = (CRFPP::Tagger *) 0 ;
  bool result;
  
  (void)jenv;
  (void)jcls;
  (void)jarg1_;
  arg1 = *(CRFPP::Tagger **)&jarg1; 
  {
    try {
      result = (bool)(arg1)->clear(); 
    }
    catch (char *e) {
      {
        SWIG_JavaException(jenv, SWIG_RuntimeError, e); return 0; 
      }; 
    }
    catch (const char *e) {
      {
        SWIG_JavaException(jenv, SWIG_RuntimeError, (char*)e); return 0; 
      }; 
    }
  }
  jresult = (jboolean)result; 
  return jresult;
}


SWIGEXPORT jboolean JNICALL Java_org_chasen_crfpp_CRFPPJNI_Tagger_1next(JNIEnv *jenv, jclass jcls, jlong jarg1, jobject jarg1_) {
  jboolean jresult = 0 ;
  CRFPP::Tagger *arg1 = (CRFPP::Tagger *) 0 ;
  bool result;
  
  (void)jenv;
  (void)jcls;
  (void)jarg1_;
  arg1 = *(CRFPP::Tagger **)&jarg1; 
  {
    try {
      result = (bool)(arg1)->next(); 
    }
    catch (char *e) {
      {
        SWIG_JavaException(jenv, SWIG_RuntimeError, e); return 0; 
      }; 
    }
    catch (const char *e) {
      {
        SWIG_JavaException(jenv, SWIG_RuntimeError, (char*)e); return 0; 
      }; 
    }
  }
  jresult = (jboolean)result; 
  return jresult;
}


SWIGEXPORT jstring JNICALL Java_org_chasen_crfpp_CRFPPJNI_Tagger_1parse_1_1SWIG_11(JNIEnv *jenv, jclass jcls, jlong jarg1, jobject jarg1_, jstring jarg2) {
  jstring jresult = 0 ;
  CRFPP::Tagger *arg1 = (CRFPP::Tagger *) 0 ;
  char *arg2 = (char *) 0 ;
  char *result = 0 ;
  
  (void)jenv;
  (void)jcls;
  (void)jarg1_;
  arg1 = *(CRFPP::Tagger **)&jarg1; 
  arg2 = 0;
  if (jarg2) {
    arg2 = (char *)jenv->GetStringUTFChars(jarg2, 0);
    if (!arg2) return 0;
  }
  {
    try {
      result = (char *)(arg1)->parse((char const *)arg2); 
    }
    catch (char *e) {
      {
        SWIG_JavaException(jenv, SWIG_RuntimeError, e); return 0; 
      }; 
    }
    catch (const char *e) {
      {
        SWIG_JavaException(jenv, SWIG_RuntimeError, (char*)e); return 0; 
      }; 
    }
  }
  if(result) jresult = jenv->NewStringUTF((const char *)result);
  if (arg2) jenv->ReleaseStringUTFChars(jarg2, (const char *)arg2);
  return jresult;
}


SWIGEXPORT jstring JNICALL Java_org_chasen_crfpp_CRFPPJNI_Tagger_1what(JNIEnv *jenv, jclass jcls, jlong jarg1, jobject jarg1_) {
  jstring jresult = 0 ;
  CRFPP::Tagger *arg1 = (CRFPP::Tagger *) 0 ;
  char *result = 0 ;
  
  (void)jenv;
  (void)jcls;
  (void)jarg1_;
  arg1 = *(CRFPP::Tagger **)&jarg1; 
  {
    try {
      result = (char *)(arg1)->what(); 
    }
    catch (char *e) {
      {
        SWIG_JavaException(jenv, SWIG_RuntimeError, e); return 0; 
      }; 
    }
    catch (const char *e) {
      {
        SWIG_JavaException(jenv, SWIG_RuntimeError, (char*)e); return 0; 
      }; 
    }
  }
  if(result) jresult = jenv->NewStringUTF((const char *)result);
  return jresult;
}


SWIGEXPORT void JNICALL Java_org_chasen_crfpp_CRFPPJNI_delete_1Tagger(JNIEnv *jenv, jclass jcls, jlong jarg1) {
  CRFPP::Tagger *arg1 = (CRFPP::Tagger *) 0 ;
  
  (void)jenv;
  (void)jcls;
  arg1 = *(CRFPP::Tagger **)&jarg1; 
  {
    try {
      delete arg1;
    }
    catch (char *e) {
      {
        SWIG_JavaException(jenv, SWIG_RuntimeError, e); return ; 
      }; 
    }
    catch (const char *e) {
      {
        SWIG_JavaException(jenv, SWIG_RuntimeError, (char*)e); return ; 
      }; 
    }
  }
}


SWIGEXPORT jlong JNICALL Java_org_chasen_crfpp_CRFPPJNI_new_1Tagger(JNIEnv *jenv, jclass jcls, jstring jarg1) {
  jlong jresult = 0 ;
  char *arg1 = (char *) 0 ;
  CRFPP::Tagger *result = 0 ;
  
  (void)jenv;
  (void)jcls;
  arg1 = 0;
  if (jarg1) {
    arg1 = (char *)jenv->GetStringUTFChars(jarg1, 0);
    if (!arg1) return 0;
  }
  {
    try {
      result = (CRFPP::Tagger *)new_CRFPP_Tagger((char const *)arg1); 
    }
    catch (char *e) {
      {
        SWIG_JavaException(jenv, SWIG_RuntimeError, e); return 0; 
      }; 
    }
    catch (const char *e) {
      {
        SWIG_JavaException(jenv, SWIG_RuntimeError, (char*)e); return 0; 
      }; 
    }
  }
  *(CRFPP::Tagger **)&jresult = result; 
  if (arg1) jenv->ReleaseStringUTFChars(jarg1, (const char *)arg1);
  return jresult;
}


SWIGEXPORT jstring JNICALL Java_org_chasen_crfpp_CRFPPJNI_VERSION_1get(JNIEnv *jenv, jclass jcls) {
  jstring jresult = 0 ;
  char *result = 0 ;
  
  (void)jenv;
  (void)jcls;
  result = (char *) "0.47";
  
  if(result) jresult = jenv->NewStringUTF((const char *)result);
  return jresult;
}


#ifdef __cplusplus
}
#endif

