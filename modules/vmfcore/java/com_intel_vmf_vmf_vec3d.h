/* DO NOT EDIT THIS FILE - it is machine generated */
#include <jni.h>
/* Header for class com_intel_vmf_vmf_vec3d */

#ifndef _Included_com_intel_vmf_vmf_vec3d
#define _Included_com_intel_vmf_vmf_vec3d
#ifdef __cplusplus
extern "C" {
#endif
/*
 * Class:     com_intel_vmf_vmf_vec3d
 * Method:    n_vmf_vec3d
 * Signature: ()J
 */
JNIEXPORT jlong JNICALL Java_com_intel_vmf_vmf_1vec3d_n_1vmf_1vec3d__
  (JNIEnv *, jclass);

/*
 * Class:     com_intel_vmf_vmf_vec3d
 * Method:    n_vmf_vec3d
 * Signature: (DDD)J
 */
JNIEXPORT jlong JNICALL Java_com_intel_vmf_vmf_1vec3d_n_1vmf_1vec3d__DDD
  (JNIEnv *, jclass, jdouble, jdouble, jdouble);

/*
 * Class:     com_intel_vmf_vmf_vec3d
 * Method:    n_setTo
 * Signature: (JJ)V
 */
JNIEXPORT void JNICALL Java_com_intel_vmf_vmf_1vec3d_n_1setTo
  (JNIEnv *, jclass, jlong, jlong);

/*
 * Class:     com_intel_vmf_vmf_vec3d
 * Method:    n_get
 * Signature: (J)[D
 */
JNIEXPORT jdoubleArray JNICALL Java_com_intel_vmf_vmf_1vec3d_n_1get
  (JNIEnv *, jclass, jlong);

/*
 * Class:     com_intel_vmf_vmf_vec3d
 * Method:    n_delete
 * Signature: (J)V
 */
JNIEXPORT void JNICALL Java_com_intel_vmf_vmf_1vec3d_n_1delete
  (JNIEnv *, jclass, jlong);

#ifdef __cplusplus
}
#endif
#endif
